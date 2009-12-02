/***********************************************************************
**
**  REBOL 3.0 "Invasion"
**  Copyright 2009 REBOL Technologies
**  All rights reserved.
**
************************************************************************
**
**  Title: REBOL Interface Library
**  Build: A96
**  Date:  2-Dec-2009/15:36:34-8:00
**  File:  rebol-lib.h
**
**  AUTO-GENERATED FILE - Do not modify. (From: make-headers.r)
**
***********************************************************************/

extern REBOL_API void Reb_Version(REBYTE vers[]); // a-lib.c
extern REBOL_API REBINT Reb_Init(REBARGS *rargs, REBOL_HOST_LIB *lib); // a-lib.c
extern REBOL_API REBINT Reb_Start(REBINT reserved); // a-lib.c
extern REBOL_API void Reb_Reset(); // a-lib.c
extern REBOL_API void Reb_Escape(REBINT reserved); // a-lib.c
extern REBOL_API REBFLG Reb_Do_String(REBYTE *text); // a-lib.c
extern REBOL_API REBINT Reb_Do_Binary(REBYTE *bin, REBINT length, REBCNT flags, REBCNT key); // a-lib.c
extern REBOL_API void Reb_Print(REBYTE *fmt, ...); // a-lib.c
extern REBOL_API void Reb_Print_TOS(REBCNT flags, REBYTE *marker); // a-lib.c
extern REBOL_API REBINT Reb_Event(REBEVT *evt); // a-lib.c
