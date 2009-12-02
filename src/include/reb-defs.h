/***********************************************************************
**
**  REBOL 3.0 "Invasion"
**  Copyright 2009 REBOL Technologies
**  All rights reserved.
**
************************************************************************
**
**  Title: Miscellaneous structures and definitions
**  Date:  1-Dec-2009
**  File:  reb_defs.h
**
**  Note: This file is used by internal and external C code. It
**  should not depend on many other header files prior to it.
**
***********************************************************************/

#ifndef FULL_DEFS
typedef void REBSER;
typedef void REBGOB;
#endif

// X/Y coordinate pair:
typedef struct rebol_pair {
	int x;
	int y;
} REBPAR;

// Standard date and time:
typedef struct rebol_dat {
	int year;
	int month;
	int day;
	int time;
	int nano;
	int zone;
} REBOL_DAT;  // not same as REBDAT

// OS metrics:
typedef struct rebol_met {
	int len; // # entries in this table
	REBPAR screen_size;
	REBPAR title_size;
	REBPAR border_size;
	REBPAR border_fixed;
	REBPAR work_origin;
	REBPAR work_size;
} REBOL_OS_METRICS;
