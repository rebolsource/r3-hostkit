/***********************************************************************
**
**  REBOL 3.0 "Invasion"
**  Copyright 2010 REBOL Technologies
**  All rights reserved.
**
************************************************************************
**
**  Title: REBOL Graphics - DRAW commands
**  Build: A106
**  Date:  8-Sep-2010
**  File:  host-ext-draw
**
**  AUTO-GENERATED FILE - Do not modify. (From: make-host-ext.r)
**
***********************************************************************/

enum draw_commands {
	CMD_DRAW_INIT_WORDS,
	CMD_DRAW_ANTI_ALIAS,
	CMD_DRAW_ARC,
	CMD_DRAW_ARROW,
	CMD_DRAW_BOX,
	CMD_DRAW_CIRCLE,
	CMD_DRAW_CURVE,
	CMD_DRAW_CLIP,
	CMD_DRAW_ELLIPSE,
	CMD_DRAW_FILL_PEN,
	CMD_DRAW_FILL_RULE,
	CMD_DRAW_GAMMA,
	CMD_DRAW_GRAD_PEN,
	CMD_DRAW_IMAGE,
	CMD_DRAW_IMAGE_FILTER,
	CMD_DRAW_IMAGE_OPTIONS,
	CMD_DRAW_IMAGE_PATTERN,
	CMD_DRAW_LINE,
	CMD_DRAW_LINE_CAP,
	CMD_DRAW_LINE_JOIN,
	CMD_DRAW_LINE_PATTERN,
	CMD_DRAW_LINE_WIDTH,
	CMD_DRAW_INVERT_MATRIX,
	CMD_DRAW_MATRIX,
	CMD_DRAW_PEN,
	CMD_DRAW_POLYGON,
	CMD_DRAW_PUSH,
	CMD_DRAW_RESET_MATRIX,
	CMD_DRAW_ROTATE,
	CMD_DRAW_SCALE,
	CMD_DRAW_SHAPE,
	CMD_DRAW_SKEW,
	CMD_DRAW_SPLINE,
	CMD_DRAW_TEXT,
	CMD_DRAW_TRANSFORM,
	CMD_DRAW_TRANSLATE,
	CMD_DRAW_TRIANGLE,
};

enum draw_words {
	W_DRAW_0,
	W_DRAW_EVEN_ODD,
	W_DRAW_NON_ZERO,
	W_DRAW_CONIC,
	W_DRAW_CUBIC,
	W_DRAW_DIAGONAL,
	W_DRAW_DIAMOND,
	W_DRAW_LINEAR,
	W_DRAW_RADIAL,
	W_DRAW_NORMAL,
	W_DRAW_REPEAT,
	W_DRAW_REFLECT,
	W_DRAW_BUTT,
	W_DRAW_SQUARE,
	W_DRAW_ROUNDED,
	W_DRAW_MITER,
	W_DRAW_MITER_BEVEL,
	W_DRAW_ROUND,
	W_DRAW_BEVEL,
	W_DRAW_VARIABLE,
	W_DRAW_FIXED,
	W_DRAW_OPENED,
	W_DRAW_CLOSED,
	W_DRAW_NO_BORDER,
	W_DRAW_BORDER,
	W_DRAW_NEAREST,
	W_DRAW_BILINEAR,
	W_DRAW_BICUBIC,
	W_DRAW_GAUSSIAN,
	W_DRAW_RESIZE,
	W_DRAW_RESAMPLE,
	W_DRAW_RASTER,
	W_DRAW_VECTORIAL,
};

#ifdef INCLUDE_EXT_DATA
const unsigned char RX_draw[] = {
	82, 69, 66, 79, 76, 32, 91, 10, 84, 105, 
	116, 108, 101, 58, 32, 34, 82, 69, 66, 79, 
	76, 32, 71, 114, 97, 112, 104, 105, 99, 115, 
	32, 45, 32, 68, 82, 65, 87, 32, 99, 111, 
	109, 109, 97, 110, 100, 115, 34, 32, 10, 78, 
	97, 109, 101, 58, 32, 100, 114, 97, 119, 32, 
	10, 84, 121, 112, 101, 58, 32, 101, 120, 116, 
	101, 110, 115, 105, 111, 110, 32, 10, 69, 120, 
	112, 111, 114, 116, 115, 58, 32, 110, 111, 110, 
	101, 10, 93, 32, 10, 119, 111, 114, 100, 115, 
	58, 32, 91, 10, 101, 118, 101, 110, 45, 111, 
	100, 100, 32, 10, 110, 111, 110, 45, 122, 101, 
	114, 111, 32, 10, 99, 111, 110, 105, 99, 32, 
	10, 99, 117, 98, 105, 99, 32, 10, 100, 105, 
	97, 103, 111, 110, 97, 108, 32, 10, 100, 105, 
	97, 109, 111, 110, 100, 32, 10, 108, 105, 110, 
	101, 97, 114, 32, 10, 114, 97, 100, 105, 97, 
	108, 32, 10, 110, 111, 114, 109, 97, 108, 32, 
	10, 114, 101, 112, 101, 97, 116, 32, 10, 114, 
	101, 102, 108, 101, 99, 116, 32, 10, 98, 117, 
	116, 116, 32, 10, 115, 113, 117, 97, 114, 101, 
	32, 10, 114, 111, 117, 110, 100, 101, 100, 32, 
	10, 109, 105, 116, 101, 114, 32, 10, 109, 105, 
	116, 101, 114, 45, 98, 101, 118, 101, 108, 32, 
	10, 114, 111, 117, 110, 100, 32, 10, 98, 101, 
	118, 101, 108, 32, 10, 118, 97, 114, 105, 97, 
	98, 108, 101, 32, 10, 102, 105, 120, 101, 100, 
	32, 10, 111, 112, 101, 110, 101, 100, 32, 10, 
	99, 108, 111, 115, 101, 100, 32, 10, 110, 111, 
	45, 98, 111, 114, 100, 101, 114, 32, 10, 98, 
	111, 114, 100, 101, 114, 32, 10, 110, 101, 97, 
	114, 101, 115, 116, 32, 10, 98, 105, 108, 105, 
	110, 101, 97, 114, 32, 10, 98, 105, 99, 117, 
	98, 105, 99, 32, 10, 103, 97, 117, 115, 115, 
	105, 97, 110, 32, 10, 114, 101, 115, 105, 122, 
	101, 32, 10, 114, 101, 115, 97, 109, 112, 108, 
	101, 32, 10, 114, 97, 115, 116, 101, 114, 32, 
	10, 118, 101, 99, 116, 111, 114, 105, 97, 108, 
	10, 93, 32, 10, 105, 110, 105, 116, 45, 119, 
	111, 114, 100, 115, 58, 32, 99, 111, 109, 109, 
	97, 110, 100, 32, 91, 10, 119, 111, 114, 100, 
	115, 32, 91, 98, 108, 111, 99, 107, 33, 93, 
	10, 93, 32, 10, 105, 110, 105, 116, 45, 119, 
	111, 114, 100, 115, 32, 119, 111, 114, 100, 115, 
	32, 10, 97, 110, 116, 105, 45, 97, 108, 105, 
	97, 115, 58, 32, 99, 111, 109, 109, 97, 110, 
	100, 32, 91, 10, 34, 84, 117, 114, 110, 115, 
	32, 97, 110, 116, 105, 45, 97, 108, 105, 97, 
	115, 105, 110, 103, 32, 111, 110, 32, 111, 114, 
	32, 111, 102, 102, 46, 34, 32, 10, 115, 116, 
	97, 116, 101, 32, 91, 108, 111, 103, 105, 99, 
	33, 93, 10, 93, 32, 10, 97, 114, 99, 58, 
	32, 99, 111, 109, 109, 97, 110, 100, 32, 91, 
	10, 34, 68, 114, 97, 119, 115, 32, 97, 32, 
	112, 97, 114, 116, 105, 97, 108, 32, 115, 101, 
	99, 116, 105, 111, 110, 32, 111, 102, 32, 97, 
	110, 32, 101, 108, 108, 105, 112, 115, 101, 32, 
	111, 114, 32, 99, 105, 114, 99, 108, 101, 46, 
	34, 32, 10, 99, 101, 110, 116, 101, 114, 32, 
	91, 112, 97, 105, 114, 33, 93, 32, 34, 84, 
	104, 101, 32, 99, 101, 110, 116, 101, 114, 32, 
	111, 102, 32, 116, 104, 101, 32, 99, 105, 114, 
	99, 108, 101, 34, 32, 10, 114, 97, 100, 105, 
	117, 115, 32, 91, 112, 97, 105, 114, 33, 93, 
	32, 34, 84, 104, 101, 32, 114, 97, 100, 105, 
	117, 115, 32, 111, 102, 32, 116, 104, 101, 32, 
	99, 105, 114, 99, 108, 101, 34, 32, 10, 97, 
	110, 103, 108, 101, 45, 98, 101, 103, 105, 110, 
	32, 91, 110, 117, 109, 98, 101, 114, 33, 93, 
	32, 34, 84, 104, 101, 32, 97, 110, 103, 108, 
	101, 32, 119, 104, 101, 114, 101, 32, 116, 104, 
	101, 32, 97, 114, 99, 32, 98, 101, 103, 105, 
	110, 115, 44, 32, 105, 110, 32, 100, 101, 103, 
	114, 101, 101, 115, 34, 32, 10, 97, 110, 103, 
	108, 101, 45, 108, 101, 110, 103, 116, 104, 32, 
	91, 110, 117, 109, 98, 101, 114, 33, 93, 32, 
	34, 84, 104, 101, 32, 108, 101, 110, 103, 116, 
	104, 32, 111, 102, 32, 116, 104, 101, 32, 97, 
	114, 99, 32, 105, 110, 32, 100, 101, 103, 114, 
	101, 101, 115, 34, 32, 10, 39, 97, 114, 99, 
	45, 101, 110, 100, 105, 110, 103, 32, 91, 119, 
	111, 114, 100, 33, 93, 32, 34, 76, 101, 97, 
	118, 101, 32, 116, 104, 101, 32, 97, 114, 99, 
	58, 32, 79, 80, 69, 78, 69, 68, 32, 111, 
	114, 32, 67, 76, 79, 83, 69, 68, 34, 10, 
	93, 32, 10, 97, 114, 114, 111, 119, 58, 32, 
	99, 111, 109, 109, 97, 110, 100, 32, 91, 10, 
	34, 83, 101, 116, 115, 32, 116, 104, 101, 32, 
	97, 114, 114, 111, 119, 32, 109, 111, 100, 101, 
	46, 34, 32, 10, 109, 111, 100, 101, 32, 91, 
	112, 97, 105, 114, 33, 93, 32, 123, 80, 111, 
	115, 115, 105, 98, 108, 101, 32, 110, 117, 109, 
	98, 101, 114, 115, 32, 102, 111, 114, 32, 99, 
	111, 109, 98, 105, 110, 97, 116, 105, 111, 110, 
	46, 32, 48, 32, 102, 111, 114, 32, 110, 111, 
	110, 101, 44, 32, 49, 32, 102, 111, 114, 32, 
	104, 101, 97, 100, 44, 32, 50, 32, 102, 111, 
	114, 32, 116, 97, 105, 108, 125, 32, 10, 99, 
	111, 108, 111, 114, 32, 91, 116, 117, 112, 108, 
	101, 33, 32, 110, 111, 110, 101, 33, 93, 32, 
	123, 67, 111, 108, 111, 114, 32, 111, 102, 32, 
	116, 104, 101, 32, 104, 101, 97, 100, 47, 116, 
	97, 105, 108, 32, 111, 102, 32, 116, 104, 101, 
	32, 97, 114, 114, 111, 119, 46, 32, 78, 79, 
	78, 69, 32, 109, 101, 97, 110, 115, 32, 117, 
	115, 101, 32, 80, 69, 78, 32, 99, 111, 108, 
	111, 114, 125, 10, 93, 32, 10, 98, 111, 120, 
	58, 32, 99, 111, 109, 109, 97, 110, 100, 32, 
	91, 10, 34, 68, 114, 97, 119, 115, 32, 97, 
	32, 114, 101, 99, 116, 97, 110, 103, 117, 108, 
	97, 114, 32, 98, 111, 120, 46, 34, 32, 10, 
	111, 114, 105, 103, 105, 110, 32, 91, 112, 97, 
	105, 114, 33, 93, 32, 34, 67, 111, 114, 110, 
	101, 114, 32, 111, 102, 32, 98, 111, 120, 34, 
	32, 10, 101, 110, 100, 32, 91, 112, 97, 105, 
	114, 33, 93, 32, 34, 69, 110, 100, 32, 111, 
	102, 32, 98, 111, 120, 34, 32, 10, 99, 111, 
	114, 110, 101, 114, 45, 114, 97, 100, 105, 117, 
	115, 32, 91, 110, 117, 109, 98, 101, 114, 33, 
	93, 32, 34, 82, 111, 117, 110, 100, 115, 32, 
	99, 111, 114, 110, 101, 114, 115, 34, 10, 93, 
	32, 10, 99, 105, 114, 99, 108, 101, 58, 32, 
	99, 111, 109, 109, 97, 110, 100, 32, 91, 10, 
	34, 68, 114, 97, 119, 115, 32, 97, 32, 99, 
	105, 114, 99, 108, 101, 32, 111, 114, 32, 101, 
	108, 108, 105, 112, 115, 101, 46, 34, 32, 10, 
	99, 101, 110, 116, 101, 114, 32, 91, 112, 97, 
	105, 114, 33, 93, 32, 10, 114, 97, 100, 105, 
	117, 115, 32, 91, 112, 97, 105, 114, 33, 93, 
	10, 93, 32, 10, 99, 117, 114, 118, 101, 58, 
	32, 99, 111, 109, 109, 97, 110, 100, 32, 91, 
	10, 34, 68, 114, 97, 119, 115, 32, 97, 32, 
	115, 109, 111, 111, 116, 104, 32, 66, 195, 169, 
	122, 105, 101, 114, 32, 99, 117, 114, 118, 101, 
	46, 40, 117, 115, 105, 110, 103, 32, 51, 32, 
	111, 114, 32, 52, 32, 112, 111, 105, 110, 116, 
	115, 41, 34, 32, 10, 112, 111, 105, 110, 116, 
	45, 49, 32, 91, 112, 97, 105, 114, 33, 93, 
	32, 34, 69, 110, 100, 32, 112, 111, 105, 110, 
	116, 32, 65, 34, 32, 10, 112, 111, 105, 110, 
	116, 45, 50, 32, 91, 112, 97, 105, 114, 33, 
	93, 32, 34, 67, 111, 110, 116, 114, 111, 108, 
	32, 112, 111, 105, 110, 116, 32, 65, 34, 32, 
	10, 112, 111, 105, 110, 116, 45, 51, 32, 91, 
	112, 97, 105, 114, 33, 93, 32, 34, 69, 110, 
	100, 32, 112, 111, 105, 110, 116, 32, 66, 44, 
	32, 111, 114, 32, 99, 111, 110, 116, 114, 111, 
	108, 32, 112, 111, 105, 110, 116, 32, 66, 34, 
	32, 10, 112, 111, 105, 110, 116, 45, 52, 32, 
	91, 112, 97, 105, 114, 33, 32, 110, 111, 110, 
	101, 33, 93, 32, 34, 69, 110, 100, 32, 112, 
	111, 105, 110, 116, 32, 66, 34, 10, 93, 32, 
	10, 99, 108, 105, 112, 58, 32, 99, 111, 109, 
	109, 97, 110, 100, 32, 91, 10, 34, 83, 112, 
	101, 99, 105, 102, 105, 101, 115, 32, 97, 32, 
	99, 108, 105, 112, 112, 105, 110, 103, 32, 114, 
	101, 103, 105, 111, 110, 46, 34, 32, 10, 111, 
	114, 105, 103, 105, 110, 32, 91, 112, 97, 105, 
	114, 33, 93, 32, 34, 67, 111, 114, 110, 101, 
	114, 32, 111, 102, 32, 98, 111, 120, 34, 32, 
	10, 101, 110, 100, 32, 91, 112, 97, 105, 114, 
	33, 93, 32, 34, 69, 110, 100, 32, 111, 102, 
	32, 98, 111, 120, 34, 10, 93, 32, 10, 101, 
	108, 108, 105, 112, 115, 101, 58, 32, 99, 111, 
	109, 109, 97, 110, 100, 32, 91, 10, 34, 68, 
	114, 97, 119, 115, 32, 97, 110, 32, 101, 108, 
	108, 105, 112, 115, 101, 46, 34, 32, 10, 111, 
	114, 105, 103, 105, 110, 32, 91, 112, 97, 105, 
	114, 33, 93, 32, 34, 84, 104, 101, 32, 117, 
	112, 112, 101, 114, 45, 108, 101, 102, 116, 45, 
	112, 111, 105, 110, 116, 32, 111, 102, 32, 116, 
	104, 101, 32, 101, 108, 108, 105, 112, 115, 101, 
	32, 98, 111, 117, 110, 100, 105, 110, 103, 32, 
	98, 111, 120, 34, 32, 10, 100, 105, 97, 109, 
	101, 116, 101, 114, 32, 91, 112, 97, 105, 114, 
	33, 93, 10, 93, 32, 10, 102, 105, 108, 108, 
	45, 112, 101, 110, 58, 32, 99, 111, 109, 109, 
	97, 110, 100, 32, 91, 10, 34, 83, 101, 116, 
	115, 32, 116, 104, 101, 32, 97, 114, 101, 97, 
	32, 102, 105, 108, 108, 32, 112, 101, 110, 32, 
	99, 111, 108, 111, 114, 46, 34, 32, 10, 99, 
	111, 108, 111, 114, 32, 91, 116, 117, 112, 108, 
	101, 33, 32, 105, 109, 97, 103, 101, 33, 32, 
	108, 111, 103, 105, 99, 33, 93, 32, 34, 83, 
	101, 116, 32, 116, 111, 32, 79, 70, 70, 32, 
	116, 111, 32, 100, 105, 115, 97, 98, 108, 101, 
	32, 102, 105, 108, 108, 32, 112, 101, 110, 34, 
	10, 93, 32, 10, 102, 105, 108, 108, 45, 114, 
	117, 108, 101, 58, 32, 99, 111, 109, 109, 97, 
	110, 100, 32, 91, 10, 123, 68, 101, 116, 101, 
	114, 109, 105, 110, 101, 115, 32, 116, 104, 101, 
	32, 97, 108, 103, 111, 114, 105, 116, 104, 109, 
	32, 117, 115, 101, 100, 32, 116, 111, 32, 100, 
	101, 116, 101, 114, 109, 105, 110, 101, 32, 119, 
	104, 97, 116, 32, 97, 114, 101, 97, 32, 116, 
	111, 32, 102, 105, 108, 108, 46, 125, 32, 10, 
	39, 109, 111, 100, 101, 32, 91, 119, 111, 114, 
	100, 33, 93, 32, 34, 82, 117, 108, 101, 32, 
	116, 121, 112, 101, 58, 32, 69, 86, 69, 78, 
	45, 79, 68, 68, 32, 111, 114, 32, 78, 79, 
	78, 45, 90, 69, 82, 79, 34, 10, 93, 32, 
	10, 103, 97, 109, 109, 97, 58, 32, 99, 111, 
	109, 109, 97, 110, 100, 32, 91, 10, 34, 83, 
	101, 116, 115, 32, 116, 104, 101, 32, 103, 97, 
	109, 109, 97, 32, 99, 111, 114, 114, 101, 99, 
	116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 
	46, 34, 32, 10, 103, 97, 109, 109, 97, 45, 
	118, 97, 108, 117, 101, 32, 91, 110, 117, 109, 
	98, 101, 114, 33, 93, 10, 93, 32, 10, 103, 
	114, 97, 100, 45, 112, 101, 110, 58, 32, 99, 
	111, 109, 109, 97, 110, 100, 32, 91, 10, 123, 
	83, 101, 116, 115, 32, 116, 104, 101, 32, 99, 
	111, 108, 111, 114, 32, 103, 114, 97, 100, 105, 
	101, 110, 116, 32, 102, 111, 114, 32, 97, 114, 
	101, 97, 32, 102, 105, 108, 108, 105, 110, 103, 
	46, 32, 84, 111, 32, 100, 105, 115, 97, 98, 
	108, 101, 32, 105, 116, 32, 115, 101, 116, 32, 
	116, 104, 101, 32, 99, 111, 108, 111, 114, 32, 
	98, 108, 111, 99, 107, 32, 116, 111, 32, 78, 
	79, 78, 69, 46, 125, 32, 10, 39, 116, 121, 
	112, 101, 32, 91, 119, 111, 114, 100, 33, 93, 
	32, 123, 84, 104, 101, 32, 103, 114, 97, 100, 
	105, 101, 110, 116, 32, 116, 121, 112, 101, 58, 
	32, 82, 65, 68, 73, 65, 76, 32, 67, 79, 
	78, 73, 67, 32, 68, 73, 65, 77, 79, 78, 
	68, 32, 76, 73, 78, 69, 65, 82, 32, 68, 
	73, 65, 71, 79, 78, 65, 76, 32, 67, 85, 
	66, 73, 67, 125, 32, 10, 39, 109, 111, 100, 
	101, 32, 91, 119, 111, 114, 100, 33, 93, 32, 
	34, 84, 104, 101, 32, 103, 114, 97, 100, 105, 
	101, 110, 116, 32, 114, 101, 110, 100, 101, 114, 
	105, 110, 103, 32, 109, 111, 100, 101, 58, 32, 
	78, 79, 82, 77, 65, 76, 32, 82, 69, 80, 
	69, 65, 84, 32, 82, 69, 70, 76, 69, 67, 
	84, 34, 32, 10, 111, 102, 102, 115, 101, 116, 
	32, 91, 112, 97, 105, 114, 33, 93, 32, 34, 
	111, 102, 102, 115, 101, 116, 32, 102, 114, 111, 
	109, 32, 119, 104, 101, 114, 101, 32, 115, 104, 
	111, 117, 108, 100, 32, 116, 104, 101, 32, 103, 
	114, 97, 100, 105, 101, 110, 116, 32, 98, 101, 
	32, 114, 101, 110, 100, 101, 114, 101, 100, 34, 
	32, 10, 114, 97, 110, 103, 101, 32, 91, 112, 
	97, 105, 114, 33, 93, 32, 34, 98, 101, 103, 
	105, 110, 32, 97, 110, 100, 32, 101, 110, 100, 
	32, 111, 102, 32, 116, 104, 101, 32, 103, 114, 
	97, 100, 105, 101, 110, 116, 32, 114, 97, 110, 
	103, 101, 34, 32, 10, 97, 110, 103, 108, 101, 
	32, 91, 110, 117, 109, 98, 101, 114, 33, 93, 
	32, 34, 114, 111, 116, 97, 116, 105, 111, 110, 
	32, 111, 102, 32, 116, 104, 101, 32, 103, 114, 
	97, 100, 105, 101, 110, 116, 32, 105, 110, 32, 
	100, 101, 103, 114, 101, 101, 115, 34, 32, 10, 
	115, 99, 97, 108, 101, 32, 91, 112, 97, 105, 
	114, 33, 93, 32, 34, 88, 32, 97, 110, 100, 
	32, 89, 32, 115, 99, 97, 108, 101, 32, 102, 
	97, 99, 116, 111, 114, 34, 32, 10, 99, 111, 
	108, 111, 114, 115, 32, 91, 98, 108, 111, 99, 
	107, 33, 32, 110, 111, 110, 101, 33, 93, 32, 
	123, 98, 108, 111, 99, 107, 32, 99, 111, 110, 
	116, 97, 105, 110, 105, 110, 103, 32, 117, 112, 
	32, 116, 111, 32, 50, 53, 54, 32, 103, 114, 
	97, 100, 105, 101, 110, 116, 32, 99, 111, 108, 
	111, 114, 115, 32, 40, 111, 112, 116, 105, 111, 
	110, 97, 108, 108, 121, 32, 119, 105, 116, 104, 
	32, 99, 111, 108, 111, 114, 32, 111, 102, 102, 
	115, 101, 116, 115, 41, 125, 10, 93, 32, 10, 
	105, 109, 97, 103, 101, 58, 32, 99, 111, 109, 
	109, 97, 110, 100, 32, 91, 10, 123, 68, 114, 
	97, 119, 115, 32, 97, 110, 32, 105, 109, 97, 
	103, 101, 44, 32, 119, 105, 116, 104, 32, 111, 
	112, 116, 105, 111, 110, 97, 108, 32, 115, 99, 
	97, 108, 105, 110, 103, 44, 32, 98, 111, 114, 
	100, 101, 114, 115, 44, 32, 97, 110, 100, 32, 
	99, 111, 108, 111, 114, 32, 107, 101, 121, 105, 
	110, 103, 46, 125, 32, 10, 105, 109, 97, 103, 
	101, 32, 91, 105, 109, 97, 103, 101, 33, 93, 
	32, 10, 111, 102, 102, 115, 101, 116, 45, 112, 
	111, 105, 110, 116, 115, 32, 91, 112, 97, 105, 
	114, 33, 32, 98, 108, 111, 99, 107, 33, 93, 
	10, 93, 32, 10, 105, 109, 97, 103, 101, 45, 
	102, 105, 108, 116, 101, 114, 58, 32, 99, 111, 
	109, 109, 97, 110, 100, 32, 91, 10, 123, 83, 
	112, 101, 99, 105, 102, 105, 101, 115, 32, 116, 
	121, 112, 101, 32, 111, 102, 32, 97, 108, 103, 
	111, 114, 105, 116, 104, 109, 32, 117, 115, 101, 
	100, 32, 119, 104, 101, 110, 32, 97, 110, 32, 
	105, 109, 97, 103, 101, 32, 105, 115, 32, 115, 
	99, 97, 108, 101, 100, 46, 125, 32, 10, 39, 
	102, 105, 108, 116, 101, 114, 45, 116, 121, 112, 
	101, 32, 91, 119, 111, 114, 100, 33, 93, 32, 
	123, 115, 117, 112, 112, 111, 114, 116, 101, 100, 
	32, 102, 105, 108, 116, 101, 114, 115, 58, 32, 
	78, 69, 65, 82, 69, 83, 84, 44, 32, 66, 
	73, 76, 73, 78, 69, 65, 82, 44, 32, 66, 
	73, 67, 85, 66, 73, 67, 44, 32, 71, 65, 
	85, 83, 83, 73, 65, 78, 125, 32, 10, 39, 
	102, 105, 108, 116, 101, 114, 45, 109, 111, 100, 
	101, 32, 91, 119, 111, 114, 100, 33, 93, 32, 
	123, 79, 117, 116, 112, 117, 116, 32, 113, 117, 
	97, 108, 105, 116, 121, 58, 32, 82, 69, 83, 
	73, 90, 69, 40, 108, 111, 119, 44, 32, 102, 
	97, 115, 116, 101, 114, 41, 32, 111, 114, 32, 
	82, 69, 83, 65, 77, 80, 76, 69, 40, 104, 
	105, 103, 104, 44, 32, 115, 108, 111, 119, 101, 
	114, 41, 125, 32, 10, 98, 108, 117, 114, 32, 
	91, 110, 117, 109, 98, 101, 114, 33, 32, 110, 
	111, 110, 101, 33, 93, 32, 34, 85, 115, 101, 
	100, 32, 111, 110, 108, 121, 32, 105, 110, 32, 
	82, 69, 83, 65, 77, 80, 76, 69, 32, 109, 
	111, 100, 101, 34, 10, 93, 32, 10, 105, 109, 
	97, 103, 101, 45, 111, 112, 116, 105, 111, 110, 
	115, 58, 32, 99, 111, 109, 109, 97, 110, 100, 
	32, 91, 10, 34, 83, 101, 116, 115, 32, 111, 
	112, 116, 105, 111, 110, 115, 32, 114, 101, 108, 
	97, 116, 101, 100, 32, 116, 111, 32, 105, 109, 
	97, 103, 101, 32, 114, 101, 110, 100, 101, 114, 
	105, 110, 103, 46, 34, 32, 10, 107, 101, 121, 
	45, 99, 111, 108, 111, 114, 32, 91, 116, 117, 
	112, 108, 101, 33, 32, 110, 111, 110, 101, 33, 
	93, 32, 123, 67, 111, 108, 111, 114, 32, 116, 
	111, 32, 98, 101, 32, 114, 101, 110, 100, 101, 
	114, 101, 100, 32, 97, 115, 32, 116, 114, 97, 
	110, 115, 112, 97, 114, 101, 110, 116, 32, 111, 
	114, 32, 78, 79, 78, 69, 32, 116, 111, 32, 
	100, 105, 115, 97, 98, 108, 101, 32, 105, 116, 
	125, 32, 10, 39, 98, 111, 114, 100, 101, 114, 
	45, 102, 108, 97, 103, 32, 91, 119, 111, 114, 
	100, 33, 93, 32, 34, 99, 97, 110, 32, 98, 
	101, 32, 66, 79, 82, 68, 69, 82, 32, 111, 
	114, 32, 78, 79, 45, 66, 79, 82, 68, 69, 
	82, 34, 10, 93, 32, 10, 105, 109, 97, 103, 
	101, 45, 112, 97, 116, 116, 101, 114, 110, 58, 
	32, 99, 111, 109, 109, 97, 110, 100, 32, 91, 
	10, 34, 67, 111, 110, 102, 105, 103, 117, 114, 
	101, 32, 116, 104, 101, 32, 105, 109, 97, 103, 
	101, 32, 112, 97, 116, 116, 101, 114, 110, 32, 
	102, 105, 108, 108, 32, 115, 101, 116, 116, 105, 
	110, 103, 115, 46, 34, 32, 10, 39, 112, 97, 
	116, 116, 101, 114, 110, 45, 109, 111, 100, 101, 
	32, 91, 119, 111, 114, 100, 33, 93, 32, 34, 
	99, 97, 110, 32, 98, 101, 32, 78, 79, 82, 
	77, 65, 76, 44, 32, 82, 69, 80, 69, 65, 
	84, 32, 111, 114, 32, 82, 69, 70, 76, 69, 
	67, 84, 34, 32, 10, 112, 97, 116, 116, 101, 
	114, 110, 45, 111, 102, 102, 115, 101, 116, 32, 
	91, 112, 97, 105, 114, 33, 93, 32, 10, 112, 
	97, 116, 116, 101, 114, 110, 45, 115, 105, 122, 
	101, 32, 91, 112, 97, 105, 114, 33, 93, 32, 
	34, 115, 101, 116, 32, 116, 111, 32, 48, 120, 
	48, 32, 102, 111, 114, 32, 97, 117, 116, 111, 
	45, 115, 105, 122, 101, 34, 10, 93, 32, 10, 
	108, 105, 110, 101, 58, 32, 99, 111, 109, 109, 
	97, 110, 100, 32, 91, 10, 34, 68, 114, 97, 
	119, 115, 32, 40, 112, 111, 108, 121, 41, 108, 
	105, 110, 101, 32, 102, 114, 111, 109, 32, 97, 
	32, 110, 117, 109, 98, 101, 114, 32, 111, 102, 
	32, 112, 111, 105, 110, 116, 115, 46, 34, 32, 
	10, 108, 105, 110, 101, 115, 32, 91, 98, 108, 
	111, 99, 107, 33, 93, 32, 34, 66, 108, 111, 
	99, 107, 32, 111, 102, 32, 112, 97, 105, 114, 
	115, 34, 10, 93, 32, 10, 108, 105, 110, 101, 
	45, 99, 97, 112, 58, 32, 99, 111, 109, 109, 
	97, 110, 100, 32, 91, 10, 123, 83, 101, 116, 
	115, 32, 116, 104, 101, 32, 115, 116, 121, 108, 
	101, 32, 116, 104, 97, 116, 32, 119, 105, 108, 
	108, 32, 98, 101, 32, 117, 115, 101, 100, 32, 
	119, 104, 101, 110, 32, 100, 114, 97, 119, 105, 
	110, 103, 32, 116, 104, 101, 32, 101, 110, 100, 
	115, 32, 111, 102, 32, 108, 105, 110, 101, 115, 
	46, 125, 32, 10, 39, 116, 121, 112, 101, 32, 
	91, 119, 111, 114, 100, 33, 93, 32, 34, 67, 
	97, 112, 32, 116, 121, 112, 101, 58, 32, 66, 
	85, 84, 84, 44, 32, 83, 81, 85, 65, 82, 
	69, 32, 111, 114, 32, 82, 79, 85, 78, 68, 
	69, 68, 34, 10, 93, 32, 10, 108, 105, 110, 
	101, 45, 106, 111, 105, 110, 58, 32, 99, 111, 
	109, 109, 97, 110, 100, 32, 91, 10, 123, 83, 
	101, 116, 115, 32, 116, 104, 101, 32, 115, 116, 
	121, 108, 101, 32, 116, 104, 97, 116, 32, 119, 
	105, 108, 108, 32, 98, 101, 32, 117, 115, 101, 
	100, 32, 119, 104, 101, 114, 101, 32, 108, 105, 
	110, 101, 115, 32, 97, 114, 101, 32, 106, 111, 
	105, 110, 101, 100, 46, 125, 32, 10, 39, 116, 
	121, 112, 101, 32, 91, 119, 111, 114, 100, 33, 
	93, 32, 34, 74, 111, 105, 110, 32, 116, 121, 
	112, 101, 58, 32, 77, 73, 84, 69, 82, 44, 
	32, 77, 73, 84, 69, 82, 45, 66, 69, 86, 
	69, 76, 44, 32, 82, 79, 85, 78, 68, 44, 
	32, 111, 114, 32, 66, 69, 86, 69, 76, 34, 
	10, 93, 32, 10, 108, 105, 110, 101, 45, 112, 
	97, 116, 116, 101, 114, 110, 58, 32, 99, 111, 
	109, 109, 97, 110, 100, 32, 91, 10, 123, 83, 
	101, 116, 115, 32, 116, 104, 101, 32, 108, 105, 
	110, 101, 32, 112, 97, 116, 116, 101, 114, 110, 
	46, 32, 84, 111, 32, 100, 105, 115, 97, 98, 
	108, 101, 32, 105, 116, 32, 115, 101, 116, 32, 
	116, 104, 101, 32, 112, 97, 116, 116, 101, 114, 
	110, 32, 98, 108, 111, 99, 107, 32, 116, 111, 
	32, 78, 79, 78, 69, 46, 125, 32, 10, 99, 
	111, 108, 111, 114, 32, 91, 116, 117, 112, 108, 
	101, 33, 93, 32, 34, 68, 97, 115, 104, 32, 
	99, 111, 108, 111, 114, 34, 32, 10, 112, 97, 
	116, 116, 101, 114, 110, 32, 91, 98, 108, 111, 
	99, 107, 33, 32, 110, 111, 110, 101, 33, 93, 
	32, 34, 66, 108, 111, 99, 107, 32, 111, 102, 
	32, 100, 97, 115, 104, 45, 115, 105, 122, 101, 
	47, 115, 116, 114, 111, 107, 101, 45, 115, 105, 
	122, 101, 32, 110, 117, 109, 98, 101, 114, 32, 
	112, 97, 105, 114, 115, 34, 10, 93, 32, 10, 
	108, 105, 110, 101, 45, 119, 105, 100, 116, 104, 
	58, 32, 99, 111, 109, 109, 97, 110, 100, 32, 
	91, 10, 34, 83, 101, 116, 115, 32, 116, 104, 
	101, 32, 108, 105, 110, 101, 32, 119, 105, 100, 
	116, 104, 46, 34, 32, 10, 119, 105, 100, 116, 
	104, 32, 91, 110, 117, 109, 98, 101, 114, 33, 
	93, 32, 123, 90, 101, 114, 111, 44, 32, 111, 
	114, 32, 110, 101, 103, 97, 116, 105, 118, 101, 
	32, 118, 97, 108, 117, 101, 115, 44, 32, 112, 
	114, 111, 100, 117, 99, 101, 32, 97, 32, 108, 
	105, 110, 101, 45, 119, 105, 100, 116, 104, 32, 
	111, 102, 32, 49, 46, 125, 32, 10, 39, 109, 
	111, 100, 101, 32, 91, 119, 111, 114, 100, 33, 
	93, 32, 34, 76, 105, 110, 101, 32, 119, 105, 
	100, 116, 104, 32, 109, 111, 100, 101, 32, 100, 
	117, 114, 105, 110, 103, 32, 115, 99, 97, 108, 
	105, 110, 103, 58, 32, 70, 73, 88, 69, 68, 
	32, 111, 114, 32, 86, 65, 82, 73, 65, 66, 
	76, 69, 34, 10, 93, 32, 10, 105, 110, 118, 
	101, 114, 116, 45, 109, 97, 116, 114, 105, 120, 
	58, 32, 99, 111, 109, 109, 97, 110, 100, 32, 
	91, 10, 123, 65, 112, 112, 108, 105, 101, 115, 
	32, 97, 110, 32, 97, 108, 103, 101, 98, 114, 
	97, 105, 99, 32, 109, 97, 116, 114, 105, 120, 
	32, 105, 110, 118, 101, 114, 115, 105, 111, 110, 
	32, 111, 112, 101, 114, 97, 116, 105, 111, 110, 
	32, 111, 110, 32, 116, 104, 101, 32, 99, 117, 
	114, 114, 101, 110, 116, 32, 116, 114, 97, 110, 
	115, 102, 111, 114, 109, 97, 116, 105, 111, 110, 
	32, 109, 97, 116, 114, 105, 120, 46, 125, 10, 
	93, 32, 10, 109, 97, 116, 114, 105, 120, 58, 
	32, 99, 111, 109, 109, 97, 110, 100, 32, 91, 
	10, 123, 80, 114, 101, 109, 117, 108, 116, 105, 
	112, 108, 105, 101, 115, 32, 116, 104, 101, 32, 
	99, 117, 114, 114, 101, 110, 116, 32, 116, 114, 
	97, 110, 115, 102, 111, 114, 109, 97, 116, 105, 
	111, 110, 32, 109, 97, 116, 114, 105, 120, 32, 
	119, 105, 116, 104, 32, 116, 104, 101, 32, 103, 
	105, 118, 101, 110, 32, 98, 108, 111, 99, 107, 
	46, 125, 32, 10, 109, 97, 116, 114, 105, 120, 
	45, 115, 101, 116, 117, 112, 32, 91, 98, 108, 
	111, 99, 107, 33, 93, 32, 34, 99, 111, 110, 
	116, 101, 110, 116, 32, 109, 117, 115, 116, 32, 
	98, 101, 32, 54, 32, 110, 117, 109, 98, 101, 
	114, 115, 34, 10, 93, 32, 10, 112, 101, 110, 
	58, 32, 99, 111, 109, 109, 97, 110, 100, 32, 
	91, 10, 34, 83, 101, 116, 115, 32, 116, 104, 
	101, 32, 108, 105, 110, 101, 32, 112, 101, 110, 
	32, 99, 111, 108, 111, 114, 46, 34, 32, 10, 
	99, 111, 108, 111, 114, 32, 91, 116, 117, 112, 
	108, 101, 33, 32, 105, 109, 97, 103, 101, 33, 
	32, 108, 111, 103, 105, 99, 33, 93, 32, 34, 
	83, 101, 116, 32, 116, 111, 32, 79, 70, 70, 
	32, 116, 111, 32, 100, 105, 115, 97, 98, 108, 
	101, 32, 112, 101, 110, 34, 10, 93, 32, 10, 
	112, 111, 108, 121, 103, 111, 110, 58, 32, 99, 
	111, 109, 109, 97, 110, 100, 32, 91, 10, 123, 
	68, 114, 97, 119, 115, 32, 97, 32, 99, 108, 
	111, 115, 101, 100, 32, 97, 114, 101, 97, 32, 
	111, 102, 32, 108, 105, 110, 101, 32, 115, 101, 
	103, 109, 101, 110, 116, 115, 46, 32, 70, 105, 
	114, 115, 116, 32, 97, 110, 100, 32, 108, 97, 
	115, 116, 32, 112, 111, 105, 110, 116, 115, 32, 
	97, 114, 101, 32, 99, 111, 110, 110, 101, 99, 
	116, 101, 100, 46, 125, 32, 10, 118, 101, 114, 
	116, 105, 99, 101, 115, 32, 91, 98, 108, 111, 
	99, 107, 33, 93, 32, 34, 66, 108, 111, 99, 
	107, 32, 111, 102, 32, 112, 97, 105, 114, 115, 
	34, 10, 93, 32, 10, 112, 117, 115, 104, 58, 
	32, 99, 111, 109, 109, 97, 110, 100, 32, 91, 
	10, 34, 83, 116, 111, 114, 101, 115, 32, 116, 
	104, 101, 32, 99, 117, 114, 114, 101, 110, 116, 
	32, 97, 116, 116, 114, 105, 98, 117, 116, 101, 
	32, 115, 101, 116, 117, 112, 32, 105, 110, 32, 
	115, 116, 97, 99, 107, 46, 34, 32, 10, 100, 
	114, 97, 119, 45, 98, 108, 111, 99, 107, 32, 
	91, 98, 108, 111, 99, 107, 33, 93, 10, 93, 
	32, 10, 114, 101, 115, 101, 116, 45, 109, 97, 
	116, 114, 105, 120, 58, 32, 99, 111, 109, 109, 
	97, 110, 100, 32, 91, 10, 123, 82, 101, 115, 
	101, 116, 115, 32, 116, 104, 101, 32, 99, 117, 
	114, 114, 101, 110, 116, 32, 116, 114, 97, 110, 
	115, 102, 111, 114, 109, 97, 116, 105, 111, 110, 
	32, 109, 97, 116, 114, 105, 120, 32, 116, 111, 
	32, 105, 116, 115, 32, 100, 101, 102, 97, 117, 
	108, 116, 32, 118, 97, 108, 117, 101, 115, 46, 
	125, 10, 93, 32, 10, 114, 111, 116, 97, 116, 
	101, 58, 32, 99, 111, 109, 109, 97, 110, 100, 
	32, 91, 10, 123, 83, 101, 116, 115, 32, 116, 
	104, 101, 32, 99, 108, 111, 99, 107, 119, 105, 
	115, 101, 32, 114, 111, 116, 97, 116, 105, 111, 
	110, 32, 105, 110, 32, 99, 117, 114, 114, 101, 
	110, 116, 32, 116, 114, 97, 110, 115, 102, 111, 
	114, 109, 97, 116, 105, 111, 110, 32, 109, 97, 
	116, 114, 105, 120, 46, 125, 32, 10, 97, 110, 
	103, 108, 101, 32, 91, 110, 117, 109, 98, 101, 
	114, 33, 93, 32, 34, 105, 110, 32, 100, 101, 
	103, 114, 101, 101, 115, 34, 10, 93, 32, 10, 
	115, 99, 97, 108, 101, 58, 32, 99, 111, 109, 
	109, 97, 110, 100, 32, 91, 10, 123, 83, 101, 
	116, 115, 32, 116, 104, 101, 32, 115, 99, 97, 
	108, 105, 110, 103, 32, 102, 97, 99, 116, 111, 
	114, 32, 105, 110, 32, 99, 117, 114, 114, 101, 
	110, 116, 32, 116, 114, 97, 110, 115, 102, 111, 
	114, 109, 97, 116, 105, 111, 110, 32, 109, 97, 
	116, 114, 105, 120, 46, 125, 32, 10, 102, 97, 
	99, 116, 111, 114, 32, 91, 112, 97, 105, 114, 
	33, 93, 10, 93, 32, 10, 115, 104, 97, 112, 
	101, 58, 32, 99, 111, 109, 109, 97, 110, 100, 
	32, 91, 10, 34, 68, 114, 97, 119, 115, 32, 
	115, 104, 97, 112, 101, 115, 32, 117, 115, 105, 
	110, 103, 32, 116, 104, 101, 32, 83, 72, 65, 
	80, 69, 32, 115, 117, 98, 45, 100, 105, 97, 
	108, 101, 99, 116, 46, 34, 32, 10, 99, 111, 
	109, 109, 97, 110, 100, 115, 32, 91, 98, 108, 
	111, 99, 107, 33, 93, 32, 34, 66, 108, 111, 
	99, 107, 32, 111, 102, 32, 83, 72, 65, 80, 
	69, 32, 115, 117, 98, 45, 99, 111, 109, 109, 
	97, 110, 100, 115, 34, 10, 93, 32, 10, 115, 
	107, 101, 119, 58, 32, 99, 111, 109, 109, 97, 
	110, 100, 32, 91, 10, 123, 83, 101, 116, 115, 
	32, 97, 32, 99, 111, 111, 114, 100, 105, 110, 
	97, 116, 101, 32, 115, 121, 115, 116, 101, 109, 
	32, 115, 107, 101, 119, 101, 100, 32, 102, 114, 
	111, 109, 32, 116, 104, 101, 32, 111, 114, 105, 
	103, 105, 110, 97, 108, 32, 98, 121, 32, 116, 
	104, 101, 32, 103, 105, 118, 101, 110, 32, 110, 
	117, 109, 98, 101, 114, 32, 111, 102, 32, 100, 
	101, 103, 114, 101, 101, 115, 32, 105, 110, 32, 
	115, 112, 101, 99, 105, 102, 105, 101, 100, 32, 
	97, 120, 105, 115, 46, 125, 32, 10, 97, 110, 
	103, 108, 101, 32, 91, 112, 97, 105, 114, 33, 
	93, 32, 123, 80, 111, 115, 105, 116, 105, 118, 
	101, 32, 110, 117, 109, 98, 101, 114, 115, 32, 
	115, 107, 101, 119, 32, 116, 111, 32, 116, 104, 
	101, 32, 114, 105, 103, 104, 116, 59, 32, 110, 
	101, 103, 97, 116, 105, 118, 101, 32, 110, 117, 
	109, 98, 101, 114, 115, 32, 115, 107, 101, 119, 
	32, 116, 111, 32, 116, 104, 101, 32, 108, 101, 
	102, 116, 46, 125, 10, 93, 32, 10, 115, 112, 
	108, 105, 110, 101, 58, 32, 99, 111, 109, 109, 
	97, 110, 100, 32, 91, 10, 123, 68, 114, 97, 
	119, 115, 32, 97, 32, 99, 117, 114, 118, 101, 
	32, 116, 104, 114, 111, 117, 103, 104, 32, 97, 
	110, 121, 32, 110, 117, 109, 98, 101, 114, 32, 
	111, 102, 32, 112, 111, 105, 110, 116, 115, 46, 
	32, 84, 104, 101, 32, 115, 109, 111, 111, 116, 
	104, 110, 101, 115, 115, 32, 111, 102, 32, 116, 
	104, 101, 32, 99, 117, 114, 118, 101, 32, 119, 
	105, 108, 108, 32, 98, 101, 32, 100, 101, 116, 
	101, 114, 109, 105, 110, 101, 100, 32, 98, 121, 
	32, 116, 104, 101, 32, 115, 101, 103, 109, 101, 
	110, 116, 32, 102, 97, 99, 116, 111, 114, 46, 
	125, 32, 10, 112, 111, 105, 110, 116, 115, 32, 
	91, 98, 108, 111, 99, 107, 33, 93, 32, 34, 
	66, 108, 111, 99, 107, 32, 111, 102, 32, 112, 
	97, 105, 114, 115, 34, 32, 10, 115, 101, 103, 
	109, 101, 110, 116, 97, 116, 105, 111, 110, 32, 
	91, 105, 110, 116, 101, 103, 101, 114, 33, 93, 
	32, 10, 39, 115, 112, 108, 105, 110, 101, 45, 
	101, 110, 100, 105, 110, 103, 32, 91, 119, 111, 
	114, 100, 33, 93, 32, 34, 76, 101, 97, 118, 
	101, 32, 116, 104, 101, 32, 115, 112, 108, 105, 
	110, 101, 58, 32, 79, 80, 69, 78, 69, 68, 
	32, 111, 114, 32, 67, 76, 79, 83, 69, 68, 
	34, 10, 93, 32, 10, 116, 101, 120, 116, 58, 
	32, 99, 111, 109, 109, 97, 110, 100, 32, 91, 
	10, 34, 68, 114, 97, 119, 115, 32, 97, 32, 
	115, 116, 114, 105, 110, 103, 32, 111, 102, 32, 
	116, 101, 120, 116, 46, 34, 32, 10, 111, 102, 
	102, 115, 101, 116, 32, 91, 112, 97, 105, 114, 
	33, 93, 32, 34, 111, 102, 102, 115, 101, 116, 
	32, 102, 114, 111, 109, 32, 119, 104, 101, 114, 
	101, 32, 115, 104, 111, 117, 108, 100, 32, 116, 
	104, 101, 32, 116, 101, 120, 116, 32, 98, 101, 
	32, 114, 101, 110, 100, 101, 114, 101, 100, 34, 
	32, 10, 115, 105, 122, 101, 32, 91, 112, 97, 
	105, 114, 33, 93, 32, 34, 115, 105, 122, 101, 
	32, 111, 102, 32, 116, 104, 101, 32, 116, 101, 
	120, 116, 32, 97, 114, 101, 97, 34, 32, 10, 
	39, 114, 101, 110, 100, 101, 114, 45, 109, 111, 
	100, 101, 32, 91, 119, 111, 114, 100, 33, 93, 
	32, 34, 82, 65, 83, 84, 69, 82, 32, 111, 
	114, 32, 86, 69, 67, 84, 79, 82, 73, 65, 
	76, 34, 32, 10, 114, 105, 99, 104, 45, 116, 
	101, 120, 116, 45, 98, 108, 111, 99, 107, 32, 
	91, 98, 108, 111, 99, 107, 33, 93, 10, 93, 
	32, 10, 116, 114, 97, 110, 115, 102, 111, 114, 
	109, 58, 32, 99, 111, 109, 109, 97, 110, 100, 
	32, 91, 10, 123, 65, 112, 112, 108, 105, 101, 
	115, 32, 116, 114, 97, 110, 115, 102, 111, 114, 
	109, 97, 116, 105, 111, 110, 32, 115, 117, 99, 
	104, 32, 97, 115, 32, 116, 114, 97, 110, 115, 
	108, 97, 116, 105, 111, 110, 44, 32, 115, 99, 
	97, 108, 105, 110, 103, 44, 32, 97, 110, 100, 
	32, 114, 111, 116, 97, 116, 105, 111, 110, 46, 
	125, 32, 10, 97, 110, 103, 108, 101, 32, 91, 
	110, 117, 109, 98, 101, 114, 33, 93, 32, 10, 
	99, 101, 110, 116, 101, 114, 32, 91, 112, 97, 
	105, 114, 33, 93, 32, 10, 115, 99, 97, 108, 
	101, 32, 91, 112, 97, 105, 114, 33, 93, 32, 
	10, 116, 114, 97, 110, 115, 108, 97, 116, 105, 
	111, 110, 32, 91, 112, 97, 105, 114, 33, 93, 
	10, 93, 32, 10, 116, 114, 97, 110, 115, 108, 
	97, 116, 101, 58, 32, 99, 111, 109, 109, 97, 
	110, 100, 32, 91, 10, 123, 83, 101, 116, 115, 
	32, 116, 104, 101, 32, 116, 114, 97, 110, 115, 
	108, 97, 116, 105, 111, 110, 32, 105, 110, 32, 
	99, 117, 114, 114, 101, 110, 116, 32, 116, 114, 
	97, 110, 115, 102, 111, 114, 109, 97, 116, 105, 
	111, 110, 32, 109, 97, 116, 114, 105, 120, 46, 
	125, 32, 10, 111, 102, 102, 115, 101, 116, 32, 
	91, 112, 97, 105, 114, 33, 93, 10, 93, 32, 
	10, 116, 114, 105, 97, 110, 103, 108, 101, 58, 
	32, 99, 111, 109, 109, 97, 110, 100, 32, 91, 
	10, 123, 68, 114, 97, 119, 115, 32, 116, 114, 
	105, 97, 110, 103, 117, 108, 97, 114, 32, 112, 
	111, 108, 121, 103, 111, 110, 32, 119, 105, 116, 
	104, 32, 115, 104, 97, 100, 105, 110, 103, 32, 
	112, 97, 114, 97, 109, 101, 116, 101, 114, 115, 
	32, 40, 71, 111, 117, 114, 97, 117, 100, 32, 
	115, 104, 97, 100, 105, 110, 103, 41, 46, 32, 
	83, 101, 116, 32, 99, 111, 108, 111, 114, 115, 
	32, 116, 111, 32, 78, 79, 78, 69, 32, 116, 
	111, 32, 116, 117, 114, 110, 32, 111, 102, 32, 
	115, 104, 97, 100, 105, 110, 103, 46, 125, 32, 
	10, 118, 101, 114, 116, 101, 120, 45, 49, 32, 
	91, 112, 97, 105, 114, 33, 93, 32, 10, 118, 
	101, 114, 116, 101, 120, 45, 50, 32, 91, 112, 
	97, 105, 114, 33, 93, 32, 10, 118, 101, 114, 
	116, 101, 120, 45, 51, 32, 91, 112, 97, 105, 
	114, 33, 93, 32, 10, 99, 111, 108, 111, 114, 
	45, 49, 32, 91, 116, 117, 112, 108, 101, 33, 
	32, 110, 111, 110, 101, 33, 93, 32, 10, 99, 
	111, 108, 111, 114, 45, 50, 32, 91, 116, 117, 
	112, 108, 101, 33, 32, 110, 111, 110, 101, 33, 
	93, 32, 10, 99, 111, 108, 111, 114, 45, 51, 
	32, 91, 116, 117, 112, 108, 101, 33, 32, 110, 
	111, 110, 101, 33, 93, 32, 10, 100, 105, 108, 
	97, 116, 105, 111, 110, 32, 91, 110, 117, 109, 
	98, 101, 114, 33, 93, 32, 34, 85, 115, 101, 
	102, 117, 108, 32, 102, 111, 114, 32, 101, 108, 
	105, 109, 105, 110, 97, 116, 105, 110, 103, 32, 
	97, 110, 105, 116, 97, 108, 105, 97, 115, 101, 
	100, 32, 101, 100, 103, 101, 115, 34, 10, 93, 
	10, 0, 
};

#endif
