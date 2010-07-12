/***********************************************************************
**
**  REBOL Invasion 3.0
**  Copyright 2007 REBOL Technologies. All rights reserved.
**
************************************************************************
**
**  reb-value.h - REBOL Values for External Usage
**
**  $Id: reb-value.h,v 1.5 2009/12/02 01:38:02 carl Exp $
**
**	Important: Compile with 4 byte alignment on structures.
**
***********************************************************************/

struct rebol_value;
typedef struct rebol_value REBVAL;

typedef struct rebol_tuple {
	REBYTE tuple[12];
} REBTUP;

typedef struct rebol_series_index
{
	REBSER	*series;
	REBCNT	index;
} REBSRI;

typedef struct rebol_word {
	REBCNT	sym;		// Index of the word's symbol
	REBINT	index;		// Index of the word in the frame
	union {
		REBSER	*frame;	// Frame in which the word is defined
		REBCNT	typeset;// Typeset number
	} c;
} REBWRD;

struct rebol_value {
	REBINT flags;
	union REBOL_Val_Data {
		REBI64	integer;
		REBINT	int32;
		REBDEC	decimal;
		REBPAR	pair;
		REBTUP	tuple;
		REBGOB	*gob;
		REBWRD	word;
		REBSRI	series;
	} data;
};

#define VAL_TYPE(v)			((REBYTE)((v)->flags))	// get only the type, not flags

#define VAL_INT32(v)		(REBINT)((v)->data.integer)
#define VAL_INT64(v)		((v)->data.integer)
#define VAL_DECIMAL(v)		((v)->data.decimal)
#define VAL_LOGIC(v)		((v)->data.int32)
#define	VAL_TUPLE(v)		((v)->data.tuple.tuple+1)
#define	VAL_TUPLE_LEN(v)	((v)->data.tuple.tuple[0])
#define	VAL_PAIR(v)			((v)->data.pair)
#define VAL_WORD(v)			((v)->data.word.index)
#define VAL_WORD_SYM(v)		((v)->data.word.sym)

#define VAL_SERIES(v)		((v)->data.series.series)
#define	VAL_STRING(v)		STR_HEAD(VAL_SERIES(v))

#define	VAL_IMAGE_SIZE(v)	(IMG_SIZE(VAL_SERIES(v)))
#define	VAL_IMAGE_WIDE(v)	(IMG_WIDE(VAL_SERIES(v)))
#define	VAL_IMAGE_HIGH(v)	(IMG_HIGH(VAL_SERIES(v)))
#define	VAL_IMAGE_DATA(v)   (IMG_DATA(VAL_SERIES(v)))

