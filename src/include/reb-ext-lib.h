/***********************************************************************
**
**  REBOL 3.0 "Invasion"
**  Copyright 2010 REBOL Technologies
**  All rights reserved.
**
************************************************************************
**
**  Title: REBOL Extension API
**  Build: A100
**  Date:  12-Jul-2010/13:17:34-7:00
**  File:  reb-ext-lib.r
**
**  AUTO-GENERATED FILE - Do not modify. (From: make-ext-lib.r)
**
***********************************************************************/

#define RXI_VERSION 1

typedef struct rebol_ext_api {
	int version;
	void *(*make_block)(u32 size);
	void *(*make_string)(u32 size, int uni);
	u32 *(*map_words)(REBSER *ser);
	u32 (*find_word)(u32 *words, u32 word);
	int (*series_info)(REBSER *ser, REBCNT what);
	int (*get_char)(REBSER *ser, u32 index);
	u32 (*set_char)(REBSER *ser, u32 index, u32 chr);
	int (*get_value)(REBSER *ser, u32 index, RXIARG *val);
	int (*set_value)(REBSER *ser, u32 index, RXIARG val, int type);
	int (*get_string)(REBSER *ser, u32 index, void **str);
} RXILIB;

//** Included by extension ********************************************

#ifndef RXI_API

#ifdef TO_WIN32
#define RXIEXT __declspec(dllexport)
#else
#define RXIEXT extern
#endif

RXIEXT const char *RX_Init(int opts, RXILIB *lib);
RXIEXT int RX_Quit(int opts);
RXIEXT int RX_Call(int cmd, RXIFRM *frm, void *data);

RXILIB *RXI;  // Passed to the Init() function

// Use these macros to access the API library functions:

#define RXI_MAKE_BLOCK(a)           RXI->make_block(a)
#define RXI_MAKE_STRING(a,b)        RXI->make_string(a,b)
#define RXI_MAP_WORDS(a)            RXI->map_words(a)
#define RXI_FIND_WORD(a,b)          RXI->find_word(a,b)
#define RXI_SERIES_INFO(a,b)        RXI->series_info(a,b)
#define RXI_GET_CHAR(a,b)           RXI->get_char(a,b)
#define RXI_SET_CHAR(a,b,c)         RXI->set_char(a,b,c)
#define RXI_GET_VALUE(a,b,c)        RXI->get_value(a,b,c)
#define RXI_SET_VALUE(a,b,c,d)      RXI->set_value(a,b,c,d)
#define RXI_GET_STRING(a,b,c)       RXI->get_string(a,b,c)

#else

//** Included by REBOL ************************************************

extern void *RXI_make_block(u32 size);
extern void *RXI_make_string(u32 size, int uni);
extern u32 *RXI_map_words(REBSER *ser);
extern u32 RXI_find_word(u32 *words, u32 word);
extern int RXI_series_info(REBSER *ser, REBCNT what);
extern int RXI_get_char(REBSER *ser, u32 index);
extern u32 RXI_set_char(REBSER *ser, u32 index, u32 chr);
extern int RXI_get_value(REBSER *ser, u32 index, RXIARG *val);
extern int RXI_set_value(REBSER *ser, u32 index, RXIARG val, int type);
extern int RXI_get_string(REBSER *ser, u32 index, void **str);

RXILIB Ext_Lib = {
	RXI_VERSION,
	RXI_make_block,
	RXI_make_string,
	RXI_map_words,
	RXI_find_word,
	RXI_series_info,
	RXI_get_char,
	RXI_set_char,
	RXI_get_value,
	RXI_set_value,
	RXI_get_string,
};

#endif
