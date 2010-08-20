/***********************************************************************
**
**  REBOL 3.0 "Invasion"
**  Copyright 2010 REBOL Technologies
**  All rights reserved.
**
************************************************************************
**
**  Title: REBOL Interface Library
**  Build: A102
**  Date:  13-Aug-2010/15:36:26-7:00
**  File:  rebol-lib.h
**
**  AUTO-GENERATED FILE - Do not modify. (From: make-headers.r)
**
***********************************************************************/


extern REBOL_API void Reb_Version(REBYTE vers[]); // a-lib.c
extern REBOL_API REBINT Reb_Init(REBARGS *rargs, REBOL_HOST_LIB *lib); // a-lib.c
extern REBOL_API REBINT Reb_Start(REBINT reserved); // a-lib.c
extern REBOL_API void Reb_Reset(); // a-lib.c
extern REBOL_API void *Reb_Extend(REBYTE *source, RXICAL call); // a-lib.c
extern REBOL_API void Reb_Escape(REBINT reserved); // a-lib.c
extern REBOL_API REBFLG Reb_Do_String(REBYTE *text); // a-lib.c
extern REBOL_API REBINT Reb_Do_Binary(REBYTE *bin, REBINT length, REBCNT flags, REBCNT key); // a-lib.c
extern REBOL_API void Reb_Print(REBYTE *fmt, ...); // a-lib.c
extern REBOL_API void Reb_Print_TOS(REBCNT flags, REBYTE *marker); // a-lib.c
extern REBOL_API REBINT Reb_Event(REBEVT *evt); // a-lib.c
extern REBOL_API void *Reb_Get_Series(REBSER *ser, REBINT what); // a-lib.c
extern REBOL_API void Reb_Do_Commands(REBSER *blk, void *data); // a-lib.c
extern REBOL_API REBINT Reb_Dialect(REBINT dialect, REBSER *block, REBCNT *index, REBSER **arglist); // a-lib2.c
extern REBOL_API void Reb_Set_Var(void *var, void *value); // a-lib2.c
extern REBOL_API REBINT Reb_Map_Words(REBYTE **names, REBCNT *symbols); // a-lib2.c
extern REBOL_API REBINT Reb_Find_Word(REBCNT sym, REBCNT *symbols, REBINT limit); // a-lib2.c
