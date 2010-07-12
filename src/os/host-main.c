/***********************************************************************
**
**  REBOL 3.0 "Invasion"
**  Copyright 2009 REBOL Technologies
**  All rights reserved.
**
************************************************************************
**
**	Name: host-main.c
**	What: Host environment main entry point
**	Note: OS independent
**  Author: Carl Sassenrath
**  Purpose:
**		Provides the outer environment that calls the REBOL lib.
**		This module is more or less just an example and includes
**		a very simple console prompt.
**
************************************************************************
**
**  WARNING to PROGRAMMERS:
**
**		This open source code is strictly managed to maintain
**		source consistency according to our standards, not yours.
**
**		1. Keep code clear and simple.
**		2. Document odd code, your reasoning, or gotchas.
**		3. Use our source style for code, indentation, comments, etc.
**		4. It must work on Win32, Linux, OS X, BSD, big/little endian.
**		5. Test your code really well before submitting it.
**
***********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define OS_LIB_TABLE		// include the host-lib dispatch table

#include "reb-host.h"		// standard host include files
#include "host-lib.h"		// OS host library (dispatch table)
#include "rebol-lib.h"		// REBOL library (function prototypes)

#include "host-init.c"

/**********************************************************************/

#define PROMPT_STR ">> "
#define RESULT_STR "== "

REBARGS Main_Args;

#ifdef TO_WIN32
HINSTANCE App_Instance = 0;
#endif

#ifndef CORE_ONLY
extern void Init_Windows(void);
extern void Init_Graphics(void);
#endif

// Host bare-bones stdio functs:
void Open_StdIO(void);
void Put_Str(char *buf);
REBYTE *Get_Str();

void Host_Crash(REBYTE *reason) {
	OS_Crash("REBOL host failure", reason);
}


/***********************************************************************
**
**  Example Embedded Extension
**  See: http://www.rebol.com/r3/docs/concepts/extensions-embedded.html
**
***********************************************************************/

#ifdef EMBEDDED_EXTENSION

char *RX_Spec =
    "REBOL [\n"
        "Title: {Hosted extension}\n"
		"Name: hosted\n"
        "Type: extension\n"
        "Exports: [add3 mul3]\n"
    "]\n"
    "add3: command [a b c]\n"
    "mul3: command [a b c]\n"
;

RXIEXT int RX_Call(int cmd, RXIFRM *frm) {
	if (cmd == 1) {
		RXA_INT64(frm, 1) = RXA_INT64(frm, 1) + RXA_INT64(frm, 2) + RXA_INT64(frm, 3);
	} else {
		RXA_INT64(frm, 1) = RXA_INT64(frm, 1) * RXA_INT64(frm, 2) * RXA_INT64(frm, 3);
	}
    return RXR_VALUE;
}

#endif


/***********************************************************************
**
**  MAIN ENTRY POINT
**
**	Win32 args:
**		inst:  current instance of the application (app handle)
**		prior: always NULL (use a mutex for single inst of app)
**		cmd:   command line string (or use GetCommandLine)
**	    show:  how app window is to be shown (e.g. maximize, minimize, etc.)
**
**	Win32 return:
**		If the function succeeds, terminating when it receives a WM_QUIT
**		message, it should return the exit value contained in that
**		message's wParam parameter. If the function terminates before
**		entering the message loop, it should return zero.
**
**  Posix args: as you would expect in C.
**  Posix return: ditto.
**
***********************************************************************/

#ifdef TO_WIN32
int WINAPI WinMain(HINSTANCE inst, HINSTANCE prior, LPSTR cmd, int show)
#else
int main(int argc, char **argv)
#endif
{
	REBYTE vers[8];
	REBYTE *line;
	REBINT n;

#ifdef TO_WIN32  // In Win32 get args manually:
	int argc;
	REBCHR **argv;
	// Fetch the win32 unicoded program arguments:
	argv = CommandLineToArgvW(GetCommandLineW(), &argc);
	App_Instance = inst;
#endif

	Host_Lib = &Host_Lib_Init;

	Parse_Args(argc, argv, &Main_Args);

	vers[0] = 5; // len
	Reb_Version(&vers[0]);

	Open_StdIO();  // also sets up interrupt handler

	// Initialize the REBOL library:
	if (!Host_Lib) Host_Crash("Missing host lib");
	n = Reb_Init(&Main_Args, Host_Lib);
	if (n == 1) Host_Crash("REBOL DLL wrong size");
	if (n == 2) Host_Crash("REBOL DLL wrong version/checksum");

#ifndef CORE_ONLY
	Init_Windows();
	Init_Graphics();
#endif

#ifdef EMBEDDED_EXTENSION
	Reb_Extend(&RX_Spec[0], &RX_Call);
#endif

	// Initialize host bundled source code:
	Reb_Do_Binary((REBYTE *)(&Reb_Init_Code[0]), REB_INIT_SIZE, 0, 0);

	// Run REBOL's mezzanine bootstrap:
	n = (Main_Args.options & RO_NO_BOOT) ? TRUE : Reb_Start(0); // TRUE on halt

	// Console line input loop (just an example, can be improved):
	if (
		!Main_Args.script // no script was provided
		|| n              // script was halted
		|| Main_Args.options & RO_HALT  // --halt option
	){
		while (TRUE) {
			Put_Str(PROMPT_STR);
			if ((line = Get_Str())) {
				Reb_Do_String(line);
				Reb_Print_TOS(0, RESULT_STR);
				OS_Free(line);
			}
			else break; // EOS
		}
	}

	OS_Call_Device(RDI_STDIO, RDC_CLOSE);

	return 0;
}
