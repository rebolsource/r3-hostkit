/***********************************************************************
**
**  REBOL 3.0 "Invasion"
**  Copyright 2010 REBOL Technologies
**  All rights reserved.
**
************************************************************************
**
**  Title: Test for Embedded Extension Modules
**  Date:  18-Aug-2010
**  File:  host-ext-test.c
**  Author: Carl Sassenrath & Needa Volunteer
**  Purpose:
**      Provides test code for extensions that can be easily
**		built and run in the host-kit. Not part of release,
**		but can be used as an example.
**  See: http://www.rebol.com/r3/docs/concepts/extensions-embedded.html
**
************************************************************************
**
**  NOTE to PROGRAMMERS:
**
**    1. Keep code clear and simple.
**    2. Document unusual code, reasoning, or gotchas.
**    3. Use same style for code, vars, indent(4), comments, etc.
**    4. Keep in mind Linux, OS X, BSD, big/little endian CPUs.
**    5. Test everything, then test it again.
**
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reb-host.h"
#include "host-lib.h"
#include "rebol-lib.h"


char *RX_Spec =
	"REBOL [\n"
		"Title: {Test of Embedded Extension}\n"
		"Name: ext-test\n"
		"Type: extension\n"
		"Exports: [xtest]\n"
	"]\n"

	"xarg0:  command [{return zero}]\n"
	"xarg1:  command [{return first arg} arg]\n"
	"xarg2:  command [{return second arg} arg1 arg2]\n"
	"xword0: command [{return system word from internal string}]\n"
	"xword1: command [{return word from string} str [string!]]\n"
	"xobj1:  command [{return obj field value} obj [object!] field [word!]]\n"
	"calls:  command [{test sync callback} context [object!] word [word!]]\n"
	"calla:  command [{test async callback} context [object!] word [word!]]\n"

	"xtest: does [\n"
		"foreach blk [\n"
			"[xarg0]\n"
			"[xarg1 111]\n"
			"[xarg1 1.1]\n"
			"[xarg1 {test}]\n"
			"[xarg1 [1 2 3]]\n"
			"[xarg2 111 222]\n"
			"[xword0]\n"
			"[xword1 {system}]\n"
			"[xobj1 system 'version]\n"

			// We just use this context as example. Normally, it would be
			// your own object that has your special functions within it.
			"[calls system/contexts/exports 'negate]\n"
			"[calls system/contexts/exports 'sine]\n"
			"[calla system/contexts/exports 'print]\n"
		"][\n"
			"print [{test:} mold blk]\n"
			"prin {      } \n"
			"probe do blk\n"
		"]\n"
		"wait 0.1 ; let async events happen\n"
		"exit\n"
	"]\n"
	"print {^/type xtest^/^/}\n"
;


REBCNT Test_Sync_Callback(REBSER *obj, REBCNT word, RXIARG *result)
{
	RXICBI cbi;
	RXIARG args[4];
	REBCNT n;

	// These can be on the stack, because it's synchronous.
	CLEAR(&cbi, sizeof(cbi));
	CLEAR(&args[0], sizeof(args));
	cbi.obj = obj;
	cbi.word = word;
	cbi.args = args;

	// Pass a single integer arg to the callback function:
	RXI_COUNT(args) = 1;
	RXI_TYPE(args, 1) = RXT_INTEGER;

	args[1].int64 = 123;

	n = RXI_CALLBACK(&cbi);

	*result = cbi.result;
	return n;
}


REBCNT Test_Async_Callback(REBSER *obj, REBCNT word)
{
	RXICBI *cbi;
	RXIARG *args;
	REBCNT n;

	// These cannot be on the stack, because they are used
	// when the callback happens later.
	cbi = MAKE_NEW(*cbi);
	CLEAR(cbi, sizeof(cbi));
	args = MAKE_MEM(sizeof(RXIARG) * 4);
	CLEAR(args, sizeof(RXIARG) * 4);
	cbi->obj = obj;
	cbi->word = word;
	cbi->args = args;
	SET_FLAG(cbi->flags, RXC_ASYNC);

	// Pass a single integer arg to the callback function:
	RXI_COUNT(args) = 1;
	RXI_TYPE(args, 1) = RXT_INTEGER;

	args[1].int64 = 123;

	n = RXI_CALLBACK(cbi); // result is in cbi struct, if wanted

	return n;
}


RXIEXT int RX_Call(int cmd, RXIFRM *frm, void *data) {
	REBYTE *str;

	switch (cmd) {

	case 0:
		RXA_INT64(frm, 1) = 0;
		RXA_TYPE(frm, 1) = RXT_INTEGER;
		break;

	case 1:
		break; // same as arg

	case 2:
		RXA_INT64(frm, 1) = RXA_INT64(frm, 2);
		RXA_TYPE(frm, 1)  = RXA_TYPE(frm, 2);
		break;

	case 3:
		RXA_WORD(frm, 1) = RXI_MAP_WORD("system"); //?? is frame always long enough??
		RXA_TYPE(frm, 1) = RXT_WORD;
		break;

	case 4:
		RXI_GET_STRING(RXA_SERIES(frm, 1), 0, (void*)(&str)); // latin-1 only for test
		RXA_WORD(frm, 1) = RXI_MAP_WORD(str);
		RXA_TYPE(frm, 1) = RXT_WORD;
		break;

	case 5:
		RXA_TYPE(frm, 1) = RXI_GET_FIELD(RXA_OBJECT(frm, 1), RXA_WORD(frm, 2), &RXA_ARG(frm, 1));
		break;

	case 6:
		RXA_TYPE(frm, 1) = Test_Sync_Callback(RXA_OBJECT(frm, 1), RXA_WORD(frm, 2), &RXA_ARG(frm, 1));
		break;

	case 7:
		RXA_LOGIC(frm, 1) = Test_Async_Callback(RXA_OBJECT(frm, 1), RXA_WORD(frm, 2));
		RXA_TYPE(frm, 1) = RXT_LOGIC;
		break;

	default:
		return RXR_NO_COMMAND;
	}
    return RXR_VALUE;
}


void Init_Ext_Test(void)
{
	RXI = Reb_Extend(&RX_Spec[0], &RX_Call);
}
