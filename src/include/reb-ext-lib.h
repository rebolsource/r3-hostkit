/***********************************************************************
**
**  REBOL 3.0 "Invasion"
**  Copyright 2010 REBOL Technologies
**  All rights reserved.
**
************************************************************************
**
**  Title: REBOL Extension API
**  Build: A101
**  Date:  20-Jul-2010/16:01:51-7:00
**  File:  reb-ext-lib.r
**
**  AUTO-GENERATED FILE - Do not modify. (From: make-ext-lib.r)
**
***********************************************************************/

#define RXI_VERSION 1

typedef struct rebol_ext_api {
	int version;
	void *(*make_block)(u32 size);
	void *(*make_string)(u32 size, int unicode);
	int (*get_string)(REBSER *series, u32 index, void **str);
	u32 (*map_word)(REBYTE *string);
	u32 *(*map_words)(REBSER *series);
	REBYTE *(*word_string)(u32 word);
	u32 (*find_word)(u32 *words, u32 word);
	int (*series_info)(REBSER *series, REBCNT what);
	int (*get_char)(REBSER *series, u32 index);
	u32 (*set_char)(REBSER *series, u32 index, u32 chr);
	int (*get_value)(REBSER *series, u32 index, RXIARG *val);
	int (*set_value)(REBSER *series, u32 index, RXIARG val, int type);
	u32 *(*words_of_object)(REBSER *obj);
	int (*get_field)(REBSER *obj, u32 word, RXIARG *val);
	int (*set_field)(REBSER *obj, u32 word, RXIARG val, int type);
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
/*
**	void *RXI_make_block(u32 size)
**
**	Allocate a new block.
**
**	Returns:
**		A pointer to a block series.
**	Arguments:
**		size - the length of the block. The system will add one extra
**			for the end-of-block marker.
**	Notes:
**		Blocks are allocated with REBOL's internal memory manager.
**		Internal structures may change, so NO assumptions should be made!
**		Blocks are automatically garbage collected if there are
**		no references to them from REBOL code (C code does nothing.)
**		However, you can lock blocks to prevent deallocation. (?? default)
*/

#define RXI_MAKE_STRING(a,b)        RXI->make_string(a,b)
/*
**	void *RXI_make_string(u32 size, int unicode)
**
**	Allocate a new string.
**
**	Returns:
**		A pointer to a string series.
**	Arguments:
**		size - the length of the string. The system will add one extra
**			for a null terminator (not strictly required, but good for C.)
**		unicode - set FALSE for ASCII/Latin1 strings, set TRUE for Unicode.
**	Notes:
**		Strings can be REBYTE or REBCHR sized (depends on R3 config.)
**		Strings are allocated with REBOL's internal memory manager.
**		Internal structures may change, so NO assumptions should be made!
**		Strings are automatically garbage collected if there are
**		no references to them from REBOL code (C code does nothing.)
**		However, you can lock strings to prevent deallocation. (?? default)
*/

#define RXI_GET_STRING(a,b,c)       RXI->get_string(a,b,c)
/*
**	int RXI_get_string(REBSER *series, u32 index, void **str)
**
**	Obtain a pointer into a string (bytes or unicode).
**
**	Returns:
**		The length and type of string. When len > 0, string is unicode.
**		When len < 0, string is bytes.
**  Arguments:
**		series - string series pointer
**		index - index from beginning (zero-based)
**		str   - pointer to first character
**	Notes:
**		Strings are allowed to move in memory. Therefore, you will want
**		to make a copy of the string if needed.
*/

#define RXI_MAP_WORD(a)             RXI->map_word(a)
/*
**	u32 RXI_map_word(REBYTE *string)
**
**	Given a word as a string, return its word identifier.
**
**	Returns:
**		The word identifier that matches the string.
**	Arguments:
**		string - a valid word as a UTF-8 encoded string.
**	Note:
**		Word identifiers are persistent, and you can use them anytime.
**		If the word is new (not found in master symbol table)
**		it will be added and the new word identifier is returned.
*/

#define RXI_MAP_WORDS(a)            RXI->map_words(a)
/*
**	u32 *RXI_map_words(REBSER *series)
**
**	Given a block of word values, return an array of word ids.
**
**	Returns:
**		An array of word identifiers (integers), zero terminated. The index of
**		each id matches that of its word.
**	Arguments:
**		series - block of words as values (from REBOL blocks, not strings.)
**	Note:
**		Word identifiers are persistent, and you can use them anytime.
**		The array is allocated with OS_MAKE and you can OS_FREE it any time.
*/

#define RXI_WORD_STRING(a)          RXI->word_string(a)
/*
**	REBYTE *RXI_word_string(u32 word)
**
**	Return a string related to a given word identifier.
**
**	Returns:
**		A copy of the word string, null terminated.
**	Arguments:
**		word - a word identifier
**	Note:
**		The result is a null terminated copy of the name for your own use.
**		The string is always UTF-8 encoded (chars > 127 are encoded.)
**		In this API, word identifiers are always canonical. Therefore,
**		the returned string may have different spelling/casing than expected.
**		The string is allocated with OS_MAKE and you can OS_FREE it any time.
*/

#define RXI_FIND_WORD(a,b)          RXI->find_word(a,b)
/*
**	u32 RXI_find_word(u32 *words, u32 word)
**
**	Given an array of word ids, return the index of the given word.
**
**	Returns:
**		The index of the given word or zero. (??)
**	Arguments:
**		words - an array like that returned from MAP_WORDS
**		word - a word id
**	Note:
**		Zeroth word? remove this funct?
*/

#define RXI_SERIES_INFO(a,b)        RXI->series_info(a,b)
/*
**	int RXI_series_info(REBSER *series, REBCNT what)
**
**	Get series information.
**
**	Returns:
**		Returns information related to a series.
**	Arguments:
**		series - any series pointer (string or block)
**		what - indicates what information to return:
**			RXI_INFO_TAIL: the length of the series	
**			RXI_INFO_SIZE: total size of series (in elements)
**			RXI_INFO_WIDE: the width in bytes of each element
**			RXI_INFO_LEFT: number of unallocated elements available
*/

#define RXI_GET_CHAR(a,b)           RXI->get_char(a,b)
/*
**	int RXI_get_char(REBSER *series, u32 index)
**
**	Get a character from byte or unicode string.
**
**	Returns:
**		A Unicode character point from string. If index is
**		at or past the tail, a -1 is returned.
**	Arguments:
**		series - string series pointer
**		index - zero based index of character
**	Note:
**		This function works for byte and unicoded strings.
**		The maximum size of a Unicode char is determined by
**		R3 build options. The default is 16 bits.
*/

#define RXI_SET_CHAR(a,b,c)         RXI->set_char(a,b,c)
/*
**	u32 RXI_set_char(REBSER *series, u32 index, u32 chr)
**
**	Set a character into a byte or unicode string.
**
**	Returns:
**		The index passed as an argument.
**	Arguments:
**		series - string series pointer
**		index - where to store the character. If past the tail,
**			the string will be auto-expanded by one and the char
**			will be appended.
*/

#define RXI_GET_VALUE(a,b,c)        RXI->get_value(a,b,c)
/*
**	int RXI_get_value(REBSER *series, u32 index, RXIARG *val)
**
**	Get a value from a block.
**
**	Returns:
**		Datatype of value or zero if index is past tail.
**	Arguments:
**		series - block series pointer
**		index - word identifier (integer)
**		val  - gets set to the value of the field
*/

#define RXI_SET_VALUE(a,b,c,d)      RXI->set_value(a,b,c,d)
/*
**	int RXI_set_value(REBSER *series, u32 index, RXIARG val, int type)
**
**	Set a value in a block.
**
**	Returns:
**		TRUE if index past end and value was appended to tail of block.
**	Arguments:
**		series - block series pointer
**		index - word identifier (integer)
**		val  - new value for field
**		type - datatype of value
*/

#define RXI_WORDS_OF_OBJECT(a)      RXI->words_of_object(a)
/*
**	u32 *RXI_words_of_object(REBSER *obj)
**
**	Returns information about the object.
**
**	Returns:
**		Returns an array of words used as fields of the object.
**	Arguments:
**		obj  - object pointer (e.g. from RXA_OBJECT)
**	Note:
**		Returns a word array similar to MAP_WORDS().
**		The array is allocated with OS_MAKE and you can OS_FREE it any time.
*/

#define RXI_GET_FIELD(a,b,c)        RXI->get_field(a,b,c)
/*
**	int RXI_get_field(REBSER *obj, u32 word, RXIARG *val)
**
**	Get a field value (context variable) of an object.
**
**	Returns:
**		Datatype of value or zero if word is not found in the object.
**	Arguments:
**		obj  - object pointer (e.g. from RXA_OBJECT)
**		word - word identifier (integer)
**		val  - gets set to the value of the field
*/

#define RXI_SET_FIELD(a,b,c,d)      RXI->set_field(a,b,c,d)
/*
**	int RXI_set_field(REBSER *obj, u32 word, RXIARG val, int type)
**
**	Set a field (context variable) of an object.
**
**	Returns:
**		The type arg, or zero if word not found in object or if field is protected.
**	Arguments:
**		obj  - object pointer (e.g. from RXA_OBJECT)
**		word - word identifier (integer)
**		val  - new value for field
**		type - datatype of value
*/


#else

//** Included by REBOL ************************************************

extern void *RXI_make_block(u32 size);
extern void *RXI_make_string(u32 size, int unicode);
extern int RXI_get_string(REBSER *series, u32 index, void **str);
extern u32 RXI_map_word(REBYTE *string);
extern u32 *RXI_map_words(REBSER *series);
extern REBYTE *RXI_word_string(u32 word);
extern u32 RXI_find_word(u32 *words, u32 word);
extern int RXI_series_info(REBSER *series, REBCNT what);
extern int RXI_get_char(REBSER *series, u32 index);
extern u32 RXI_set_char(REBSER *series, u32 index, u32 chr);
extern int RXI_get_value(REBSER *series, u32 index, RXIARG *val);
extern int RXI_set_value(REBSER *series, u32 index, RXIARG val, int type);
extern u32 *RXI_words_of_object(REBSER *obj);
extern int RXI_get_field(REBSER *obj, u32 word, RXIARG *val);
extern int RXI_set_field(REBSER *obj, u32 word, RXIARG val, int type);

RXILIB Ext_Lib = {
	RXI_VERSION,
	RXI_make_block,
	RXI_make_string,
	RXI_get_string,
	RXI_map_word,
	RXI_map_words,
	RXI_word_string,
	RXI_find_word,
	RXI_series_info,
	RXI_get_char,
	RXI_set_char,
	RXI_get_value,
	RXI_set_value,
	RXI_words_of_object,
	RXI_get_field,
	RXI_set_field,
};

#endif
