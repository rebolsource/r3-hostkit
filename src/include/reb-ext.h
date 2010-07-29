/***********************************************************************
**
**  REBOL 3.0 "Invasion"
**  Copyright 2010 REBOL Technologies
**  All rights reserved.
**
************************************************************************
**
**  Title: Extensions Include File
**  Build: A100
**  Date:  17-Jul-2010/14:47:24-7:00
**  File:  reb-ext.h
**
***********************************************************************/

#include "reb-defs.h"
#include "ext-types.h"

// Value structure (for passing args to and from):
typedef union rxi_arg_val {
	void *addr;
	i64    int64;
	double dec64;
	REBXYF pair;
	REBYTE bytes[8];
	struct {
		i32 int32a;
		i32 int32b;
	};
	struct {
		REBD32 dec32a;
		REBD32 dec32b;
	};
	struct {
		void *series;
		u32 index;
	};
	struct {
		void *image;
		int width:16;
		int height:16;
	};
} RXIARG;

// Command function call frame:
typedef struct rxi_cmd_frame {
	RXIARG args[8];	// arg values (64 bits each)
} RXIFRM;

typedef int (*RXICAL)(int cmd, RXIFRM *args, void *data);

// Access macros:
#define RXA_ARG(f,n)	((f)->args[n])
#define RXA_COUNT(f)	(RXA_ARG(f,0).bytes[0])
#define RXA_TYPE(f,n)	(RXA_ARG(f,0).bytes[n])
#define RXA_REF(f,n)	(RXA_ARG(f,n).int32a)

#define RXA_INT64(f,n)	(RXA_ARG(f,n).int64)
#define RXA_DEC64(f,n)	(RXA_ARG(f,n).dec64)
#define RXA_LOGIC(f,n)	(RXA_ARG(f,n).int32a)
#define RXA_CHAR(f,n)	(RXA_ARG(f,n).int32a)
#define RXA_TIME(f,n)	(RXA_ARG(f,n).int64)
#define RXA_DATE(f,n)	(RXA_ARG(f,n).int32a)
#define RXA_WORD(f,n)	(RXA_ARG(f,n).int32a)
#define RXA_PAIR(f,n)	(RXA_ARG(f,n).pair)
#define RXA_TUPLE(f,n)	(RXA_ARG(f,n).bytes)
#define RXA_SERIES(f,n)	(RXA_ARG(f,n).series)
#define RXA_INDEX(f,n)	(RXA_ARG(f,n).index)
#define RXA_OBJECT(f,n)	(RXA_ARG(f,n).addr)
#define RXA_MODULE(f,n)	(RXA_ARG(f,n).addr)
#define RXA_HANDLE(f,n)	(RXA_ARG(f,n).addr)
#define RXA_IMAGE(f,n)	(RXA_ARG(f,n).image)
#define RXA_IMAGE_BITS(f,n)	  ((REBYTE *)RXI_SERIES_INFO((RXA_ARG(f,n).image), RXI_SER_DATA))
#define RXA_IMAGE_WIDTH(f,n)  (RXA_ARG(f,n).width)
#define RXA_IMAGE_HEIGHT(f,n) (RXA_ARG(f,n).height)


// Command function return values:
enum rxi_return {
	RXR_UNSET,
	RXR_NONE,
	RXR_TRUE,
	RXR_FALSE,

	RXR_VALUE,
	RXR_BLOCK,
	RXR_ERROR,
	RXR_BAD_ARGS,
	RXR_NO_COMMAND,
};

// Used with RXI_SERIES_INFO:
enum {
	RXI_SER_TAIL,	// series tail index (length of data)
	RXI_SER_DATA,	// pointer to data
	RXI_SER_SIZE,	// size of series (in units)
	RXI_SER_WIDE,	// width of series (in bytes)
	RXI_SER_LEFT,	// units free in series (past tail)
};

// Include the library interface:
#include "reb-ext-lib.h"
