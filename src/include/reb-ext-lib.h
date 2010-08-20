/***********************************************************************
**
**  REBOL 3.0 "Invasion"
**  Copyright 2010 REBOL Technologies
**  All rights reserved.
**
************************************************************************
**
**  Title: REBOL Extension API
**  Build: A103
**  Date:  19-Aug-2010/20:35:21-7:00
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
	void *(*make_image)(u32 width, u32 height);
	void (*gc_protect)(REBSER *series, BOOL protect);
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
	int (*callback)(RXICBI *cbi);
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

#define RXI_MAKE_IMAGE(a,b)         RXI->make_image(a,b)
/*
**	void *RXI_make_image(u32 width, u32 height)
**
**	Allocate a new image of the given size.
**
**	Returns:
**		A pointer to an image series.
**	Arguments:
**		width - the width of the image in pixels
**		height - the height of the image in lines
**	Notes:
**		Images are allocated with REBOL's internal memory manager.
**		Image are automatically garbage collected if there are
**		no references to them from REBOL code (C code does nothing.)
*/

#define RXI_GC_PROTECT(a,b)         RXI->gc_protect(a,b)
/*
**	void RXI_gc_protect(REBSER *series, BOOL protect)
**
**	Protect memory from garbage collection.
**
**	Returns:
**		nothing
**	Arguments:
**		series - a series to protect (block, string, image, ...)
**		protect - TRUE to protect, FALSE to unprotect
**	Notes:
**		You should only use this function when absolutely necessary,
**		because it bypasses garbage collection for the specified series.
**		Meaning: if you protect a series, it will never be freed.
**		Also, you only need this function if you allocate several series
**		such as strings, blocks, images, etc. within the same command
**		and you don't store those references somewhere where the GC can
**		find them, such as in an existing block or object (variable).
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
**	Given a word as a string, return its global word identifier.
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
**		An array of global word identifiers (integers). The [0] value is the size.
**	Arguments:
**		series - block of words as values (from REBOL blocks, not strings.)
**	Note:
**		Word identifiers are persistent, and you can use them anytime.
**		The block can include any kind of word, including set-words, lit-words, etc.
**		If the input block contains non-words, they will be skipped.
**		The array is allocated with OS_MAKE and you can OS_FREE it any time.
*/

#define RXI_WORD_STRING(a)          RXI->word_string(a)
/*
**	REBYTE *RXI_word_string(u32 word)
**
**	Return a string related to a given global word identifier.
**
**	Returns:
**		A copy of the word string, null terminated.
**	Arguments:
**		word - a global word identifier
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
**		The index of the given word or zero.
**	Arguments:
**		words - a word array like that returned from MAP_WORDS (first element is size)
**		word - a word id
**	Note:
**		The first element of the word array is the length of the array.
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
**		what - indicates what information to return (see enum)
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
**		index - global word identifier (integer)
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
**		index - global word identifier (integer)
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
**		word - global word identifier (integer)
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
**		word - global word identifier (integer)
**		val  - new value for field
**		type - datatype of value
*/

#define RXI_CALLBACK(a)             RXI->callback(a)
/*
**	int RXI_callback(RXICBI *cbi)
**
**	Evaluate a REBOL callback function, either synchronous or asynchronous.
**
**	Returns:
**		Sync callback: type of the result; async callback: true if queued
**	Arguments:
**		cbi - callback information:
**			- special option flags
**			- object pointer (where function is located)
**			- function name as global word identifier (within above object)
**			- argument list passed to callback (see notes below)
**			- result value
**	Description:
**		The flag value will determine the type of callback. It can be either
**		synchronous, where the code will re-enter the interpreter environment
**		and call the specified function, or asynchronous where an EVT_CALLBACK
**		event is queued, and the callback will be evaluated later when events
**		are processed within the interpreter's environment.
**
**		For asynchronous callbacks, the cbi and the args array must be managed
**		because the data isn't processed until the callback event is
**		handled. Therefore, these cannot be allocated locally on
**		the C stack; they should be dynamic (or global if so desired.)
*/


#else

//** Included by REBOL ************************************************

extern void *RXI_make_block(u32 size);
extern void *RXI_make_string(u32 size, int unicode);
extern void *RXI_make_image(u32 width, u32 height);
extern void RXI_gc_protect(REBSER *series, BOOL protect);
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
extern int RXI_callback(RXICBI *cbi);

RXILIB Ext_Lib = {
	RXI_VERSION,
	RXI_make_block,
	RXI_make_string,
	RXI_make_image,
	RXI_gc_protect,
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
	RXI_callback,
};

#endif
