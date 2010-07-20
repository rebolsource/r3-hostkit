/***********************************************************************
**
**  REBOL 3.0 "Invasion"
**  Copyright 2010 REBOL Technologies
**  All rights reserved.
**
************************************************************************
**
**  Title: Graphics Compositing
**  Date:  5-July-2010
**  File:  host-graphics.c
**  Author: Carl (and soon Cyphre)
**  Purpose: Interface from graphics commands to AGG library.
**  Tools: make-host-ext.r
**
************************************************************************
**
**  NOTE to PROGRAMMERS:
**
**    1. Keep code clear and simple.
**    2. Document unusual code, reasoning, or gotchas.
**    3. Use same style for code, vars, indent(4), comments, etc.
**    4. Keep in mind Linux, OS X, BSD, big/little endian CPUs.
**    5. Test everything, then test it again.
**
***********************************************************************/

#include <windows.h>

#include "reb-host.h"
#include "host-lib.h" 
#include "rebol-lib.h"
#include "agg-draw.h"
#include "host-ext-graphics.h"
#include "host-ext-draw.h"

// REBOL Sources:
#include "../host-ext-graphics.c"
#include "../host-ext-draw.c"

//***** Externs *****

extern REBINT Show_Gob(REBGOB *gob);


/***********************************************************************
**
*/	REBINT Draw_Gob(void *graphics, REBSER *block, REBSER *args)
/*
**		Temporary trampoline. Move to compositor!
**
***********************************************************************/
{
	Reb_Do_Commands(block, graphics);
	return 0;
}


/***********************************************************************
**
*/	RXIEXT int RXD_Graphics(int cmd, RXIFRM *frm, void *data)
/*
**		Graphics command extension dispatcher.
**
***********************************************************************/
{
	switch (cmd) {

	case CMD_SHOW:
		Show_Gob((REBGOB*)RXA_SERIES(frm, 1));
		break;

	case CMD_INIT_GRAPHICS:
		Gob_Root = (REBGOB*)RXA_SERIES(frm, 1); // system/view/screen-gob
		Gob_Root->size.x = (REBD32)GetSystemMetrics(SM_CXSCREEN);
		Gob_Root->size.y = (REBD32)GetSystemMetrics(SM_CYSCREEN);
		break;

	default:
		return RXR_NO_COMMAND;
	}
    return RXR_UNSET;
}


/***********************************************************************
**
*/	RXIEXT int RXD_Draw(int cmd, RXIFRM *frm, void *data)
/*
**		DARW command dispatcher.
**
***********************************************************************/
{
	switch (cmd) {

	case CMD_BOX:
		agg_box(data, RXA_PAIR(frm, 1), RXA_PAIR(frm, 2), 0);
		break;

	case CMD_CIRCLE:
		agg_circle(data, RXA_PAIR(frm, 1), RXA_PAIR(frm, 2));
		break;

	case CMD_LINES:
		{
			RXIARG val;
			REBCNT type;
			REBCNT n;
			REBSER blk = RXA_SERIES(frm, 1);

			for (n = 0; type = RXI_GET_VALUE(blk, n, &val); n++) {
				if (type == RXT_PAIR) {
					if (n > 0)
						agg_add_vertex(data, val.pair);
					else
						agg_begin_poly(data, val.pair);
				}
			}
		}
		break;

	case CMD_PEN:
		agg_pen(data, RXA_TUPLE(frm, 1)+1, 0);
		break;

	case CMD_FILL_PEN:
		agg_fill_pen(data, RXA_TUPLE(frm, 1)+1);
		break;

	default:
		return RXR_NO_COMMAND;
	}

    return RXR_UNSET;
}


/***********************************************************************
**
*/	void Init_Graphics(void)
/*
**	Initialize special variables of the graphics subsystem.
**
***********************************************************************/
{
	RXI = Reb_Extend((REBYTE *)(&RX_graphics[0]), &RXD_Graphics);
	Reb_Extend((REBYTE *)(&RX_draw[0]), &RXD_Draw);
}



#ifdef OLD__FUNCS_NEED_CONVERSION

/***********************************************************************
**
*/	HCURSOR Image_To_Cursor(REBSER *image)
/*
**      Converts REBOL image! to Windows CURSOR
**
***********************************************************************/
{
	int xHotspot = 0;
	int yHotspot = 0;
	
	HICON result = NULL;
	HBITMAP hSourceBitmap;
	BITMAPINFO  BitmapInfo;
	ICONINFO iconinfo;

    //Get the system display DC
    HDC hDC = GetDC(NULL);

	//Create DIB
	unsigned char* ppvBits;
	int bmlen = IMG_WIDE(image) * IMG_HIGH(image) * 4;
	int i;

	BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	BitmapInfo.bmiHeader.biWidth = IMG_WIDE(image);
	BitmapInfo.bmiHeader.biHeight = -(signed)IMG_HIGH(image);
	BitmapInfo.bmiHeader.biPlanes = 1;
	BitmapInfo.bmiHeader.biBitCount = 32;
	BitmapInfo.bmiHeader.biCompression = BI_RGB;
	BitmapInfo.bmiHeader.biSizeImage = 0;
	BitmapInfo.bmiHeader.biXPelsPerMeter = 0;
	BitmapInfo.bmiHeader.biYPelsPerMeter = 0;
	BitmapInfo.bmiHeader.biClrUsed = 0;
	BitmapInfo.bmiHeader.biClrImportant = 0;

	hSourceBitmap = CreateDIBSection(hDC, &BitmapInfo, DIB_RGB_COLORS, &ppvBits, NULL, 0);

	//Release the system display DC
    ReleaseDC(NULL, hDC);

	//Copy the image content to DIB
	COPY_MEM(ppvBits,IMG_DATA(image), bmlen);

	//Invert alphachannel from the REBOL format
	for (i = 3;i < bmlen;i+=4){
		ppvBits[i] ^= 0xff;
	}

	//Create the cursor using the masks and the hotspot values provided
	iconinfo.fIcon		= FALSE;
	iconinfo.xHotspot	= xHotspot;
	iconinfo.yHotspot	= yHotspot;
	iconinfo.hbmMask	= hSourceBitmap;
	iconinfo.hbmColor	= hSourceBitmap;

	result = CreateIconIndirect(&iconinfo);

	DeleteObject(hSourceBitmap);

	return result;
}


/***********************************************************************
**
*/  void OS_GUI_Metrics(REBOL_OS_METRICS *met)
/*
**      Provide info about the hosting GUI.
**
***********************************************************************/
{
	RECT rect;

	met->screen_size.x  = GetSystemMetrics(SM_CXSCREEN);
	met->screen_size.y  = GetSystemMetrics(SM_CYSCREEN);
	met->title_size.x   = 0;
	met->title_size.y   = GetSystemMetrics(SM_CYCAPTION);
	met->border_size.x  = GetSystemMetrics(SM_CXSIZEFRAME);
	met->border_size.y  = GetSystemMetrics(SM_CYSIZEFRAME);
	met->border_fixed.x = GetSystemMetrics(SM_CXFIXEDFRAME);
	met->border_fixed.y = GetSystemMetrics(SM_CYFIXEDFRAME);
	if (SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0)) {
		met->work_origin.x = rect.left;
		met->work_origin.y = rect.top;
		met->work_size.x = rect.right;
		met->work_size.y = rect.bottom;
	}
 
	Metrics = *met;
}


/***********************************************************************
**
*/  REBINT OS_Size_Text(REBGOB *gob, REBPAR *size)
/*
**      Return the area size of the text.
**
***********************************************************************/
{
//	return rt_size_text(Rich_Text, gob, size);
	return 0;
}


/***********************************************************************
**
*/  REBINT OS_Offset_To_Caret(REBGOB *gob, REBPAR xy, REBINT *element, REBINT *position)
/*
**      Return the element and position for a given offset pair.
**
***********************************************************************/
{
//	return rt_offset_to_caret(Rich_Text, gob, &xy, element, position);
	return 0;
}


/***********************************************************************
**
*/  REBINT OS_Caret_To_Offset(REBGOB *gob, REBPAR *xy, REBINT element, REBINT position)
/*
**      Return the offset pair for a given element and position.
**
***********************************************************************/
{
//	return rt_caret_to_offset(Rich_Text, gob, xy, element, position);
	return 0;
}


/***********************************************************************
**
*/  REBINT OS_Gob_To_Image(REBSER *image, REBGOB *gob)
/*
**      Render gob into an image.
**		Clip to keep render inside the image provided.
**
***********************************************************************/
{
	return Gob_To_Image(image, gob);
}


/***********************************************************************
**
*/  REBINT OS_Draw_Image(REBSER *image, REBSER *block)
/*
**      Render DRAW dialect into an image.
**		Clip to keep render inside the image provided.
**
***********************************************************************/
{
	return Draw_Image(image, block);
}


/***********************************************************************
**
*/  REBINT OS_Effect_Image(REBSER *image, REBSER *block)
/*
**      Render EFFECT dialect into an image.
**		Clip to keep render inside the image provided.
**
***********************************************************************/
{
//	return Effect_Image(image, block);
	return 0;
}


/***********************************************************************
**
*/  void OS_Cursor_Image(REBINT n, REBSER *image)
/*
***********************************************************************/
{
	if (Custom_Cursor) {
		//Destroy cursor object only if it is a custom image
		DestroyCursor(Cursor);
		Custom_Cursor = FALSE;
	}

	if (n > 0)
		Cursor = LoadCursor(NULL, (LPCTSTR)n);
	else if (image) {
		Cursor = Image_To_Cursor(image);
		Custom_Cursor = TRUE;
	} else
		Cursor = NULL;

	SetCursor(Cursor);
}

#endif

