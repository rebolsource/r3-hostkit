/***********************************************************************
**
**  REBOL 3.0 Extensions 1.0
**
***********************************************************************/

// Supported datatypes (isolated - relative to extensions, not kernel)
enum rebol_ext_types
{
    RXT_END = 0,			// 0
    RXT_UNSET,				// 1
    RXT_NONE,				// 2
    RXT_HANDLE,				// 3
    RXT_LOGIC = 4,			// 4
    RXT_INTEGER,			// 5
    RXT_DECIMAL,			// 6
    RXT_PERCENT,			// 7
    RXT_CHAR = 10,			// 8
    RXT_PAIR,				// 9
    RXT_TUPLE,				// 10
    RXT_TIME,				// 11
    RXT_DATE,				// 12
    RXT_WORD = 16,			// 13
    RXT_SET_WORD,			// 14
    RXT_GET_WORD,			// 15
    RXT_LIT_WORD,			// 16
    RXT_REFINEMENT,			// 17
	RXT_GOB = 23,
    RXT_STRING = 24,		// 18
    RXT_FILE,				// 19
    RXT_EMAIL,				// 20
    RXT_URL,				// 21
    RXT_TAG,				// 22
    RXT_ISSUE,				// 23
    RXT_BLOCK = 32,			// 24
    RXT_PAREN,				// 25
    RXT_PATH,				// 26
    RXT_SET_PATH,			// 27
    RXT_GET_PATH,			// 28
    RXT_LIT_PATH,			// 29
    RXT_BINARY = 40,		// 30
    RXT_BITSET,				// 31
    RXT_IMAGE,				// 32
    RXT_VECTOR,				// 33
    RXT_MAX
};

// Value structure (for passing args to and from):
typedef union rxi_arg_val {
	i64 int64;
	double dec64;
	REBYTE bytes[8];
	struct {
		i32 int32a;
		i32 int32b;
	};
	struct {
		u32 index;
		void *series;
	};
	REBPAR pair;
	void *handle;
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
#define RXA_PAIR_X(f,n)	(RXA_ARG(f,n).int32a)
#define RXA_PAIR_Y(f,n)	(RXA_ARG(f,n).int32b)
#define RXA_TUPLE(f,n)	(RXA_ARG(f,n).bytes)
#define RXA_SERIES(f,n)	(RXA_ARG(f,n).series)
#define RXA_INDEX(f,n)	(RXA_ARG(f,n).index)
#define RXA_HANDLE(f,n)	(RXA_ARG(f,n).handle)


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

enum {
	RXI_INFO_TAIL,	// series tail index
	RXI_INFO_SIZE,	// size of series (in units)
	RXI_INFO_WIDE,	// width of series (in bytes)
	RXI_INFO_LEFT,	// units free in series (past tail)
};

// Include the library interface:
#include "reb-ext-lib.h"
