#include "agg_compo.h"
#include "agg_truetype_text.h"


extern "C" void Reb_Print(char *fmt, ...);//output just for testing
extern "C" void *RL_Series(REBSER *ser, REBINT what);

namespace agg
{
	extern "C" void* Create_RichText()
	{
		return (void*)new rich_text(GetDC( NULL ));
	}

	extern "C" void Destroy_RichText(void* rt)
	{
	   delete (rich_text*)rt;
	}

	extern "C" void rt_anti_alias(void* rt, REBINT mode)
	{
		((rich_text*)rt)->rt_text_mode(mode);
	}

	extern "C" void rt_bold(void* rt, REBINT state)
	{
		font* font = ((rich_text*)rt)->rt_get_font();
		font->bold = state;
		((rich_text*)rt)->rt_push();
	}

	extern "C" void rt_caret(void* rt, REBXYF* caret, REBXYF* highlightStart, REBXYF highlightEnd)
	{
		if (highlightStart) ((rich_text*)rt)->rt_set_hinfo(*highlightStart,highlightEnd);
		if (caret) ((rich_text*)rt)->rt_set_caret(*caret);
	}

	extern "C" void rt_center(void* rt)
	{
		para* par = ((rich_text*)rt)->rt_get_para();
		par->align = W_TEXT_CENTER;
		((rich_text*)rt)->rt_set_para(par);
		((rich_text*)rt)->rt_push();
	}

	extern "C" void rt_color(void* rt, REBYTE* color)
	{
		font* font = ((rich_text*)rt)->rt_get_font();
		font->color[0] = color[0];
		font->color[1] = color[1];
		font->color[2] = color[2];
		font->color[3] = color[3];
		((rich_text*)rt)->rt_push();
		((rich_text*)rt)->rt_color_change();
	}

	extern "C" void rt_drop(void* rt, REBINT number)
	{
		((rich_text*)rt)->rt_drop(number);
	}

	extern "C" void rt_font(void* rt, font* font)
	{
		((rich_text*)rt)->rt_set_font(font);
		((rich_text*)rt)->rt_push();
	}

	extern "C" void rt_font_size(void* rt, REBINT size)
	{
		font* font = ((rich_text*)rt)->rt_get_font();
		font->size = size;
		((rich_text*)rt)->rt_push();
	}

	extern "C" void* rt_get_font(void* rt)
	{
		return (void*)((rich_text*)rt)->rt_get_font();
	}


	extern "C" void* rt_get_para(void* rt)
	{
		return (void*)((rich_text*)rt)->rt_get_para();
	}

	extern "C" void rt_italic(void* rt, REBINT state)
	{
		font* font = ((rich_text*)rt)->rt_get_font();
		font->italic = state;
		((rich_text*)rt)->rt_push();
	}

	extern "C" void rt_left(void* rt)
	{
		para* par = ((rich_text*)rt)->rt_get_para();
		par->align = W_TEXT_LEFT;
		((rich_text*)rt)->rt_set_para(par);
		((rich_text*)rt)->rt_push();
	}

	extern "C" void rt_newline(void* rt, REBINT index)
	{
		((rich_text*)rt)->rt_set_text((REBCHR*)"\n", TRUE);
		((rich_text*)rt)->rt_push(index);
	}

	extern "C" void rt_para(void* rt, para* para)
	{
		((rich_text*)rt)->rt_set_para(para);
		((rich_text*)rt)->rt_push();
	}

	extern "C" void rt_right(void* rt)
	{
		para* par = ((rich_text*)rt)->rt_get_para();
		par->align = W_TEXT_RIGHT;
		((rich_text*)rt)->rt_set_para(par);
		((rich_text*)rt)->rt_push();
	}

	extern "C" void rt_scroll(void* rt, REBXYF offset)
	{
		para* par = ((rich_text*)rt)->rt_get_para();
		par->scroll_x = offset.x;
		par->scroll_y = offset.y;
		((rich_text*)rt)->rt_set_para(par);
		((rich_text*)rt)->rt_push();
	}

	extern "C" void rt_shadow(void* rt, REBXYF d, REBYTE* color, REBINT blur)
	{
		font* font = ((rich_text*)rt)->rt_get_font();

		font->shadow_x = d.x;
		font->shadow_y = d.y;
		font->shadow_blur = blur;

		memcpy(font->shadow_color, color, 4);

		((rich_text*)rt)->rt_push();
	}

    extern "C" void rt_set_font_styles(font* font, u32 word){
        switch (word){
            case W_TEXT_BOLD:
                font->bold = TRUE;
                break;
            case W_TEXT_ITALIC:
                font->italic = TRUE;
                break;
            case W_TEXT_UNDERLINE:
                font->underline = TRUE;
                break;
        }
    }

	extern "C" void rt_size_text(void* rt, REBGOB* gob, REBXYF* size)
	{
		REBINT result = 0;
		((rich_text*)rt)->rt_reset();
		((rich_text*)rt)->rt_set_clip(0,0, GOB_W(gob),GOB_H(gob));
		if (GOB_TYPE(gob) == GOBT_TEXT){
			result = Text_Gob(rt, (REBSER *)GOB_CONTENT(gob));
		} else if (GOB_TYPE(gob) == GOBT_STRING) {
			((rich_text*)rt)->rt_set_text((REBCHR*)GOB_STRING(gob), TRUE);
			((rich_text*)rt)->rt_push(1);
		} else {
			size->x = 0;
			size->y = 0;
			return;
		}

		if (result < 0) return;

		((rich_text*)rt)->rt_size_text(size);
	}

	extern "C" void rt_text(void* rt, REBCHR* text, REBINT index, REBCNT gc)
	{
		((rich_text*)rt)->rt_set_text((REBCHR*)text, gc);
		((rich_text*)rt)->rt_push(index);
	}

	extern "C" void rt_underline(void* rt, REBINT state)
	{
		font* font = ((rich_text*)rt)->rt_get_font();
		font->underline = state;
		((rich_text*)rt)->rt_push();
	}


















	extern "C" REBINT rt_offset_to_caret(void* rt, REBGOB *gob, REBXYF xy, REBINT *element, REBINT *position)
	{
		REBINT result = 0;
		((rich_text*)rt)->rt_reset();
		((rich_text*)rt)->rt_set_clip(0,0, GOB_W(gob),GOB_H(gob));
		if (GOB_TYPE(gob) == GOBT_TEXT){
			result = Text_Gob(rt, (REBSER *)GOB_CONTENT(gob));
		} else if (GOB_TYPE(gob) == GOBT_STRING) {
			((rich_text*)rt)->rt_set_text((REBCHR*)GOB_STRING(gob), TRUE);
			((rich_text*)rt)->rt_push(1);
		} else {
			*element = 0;
			*position = 0;
			return result;
		}

		if (result < 0) return result;

		((rich_text*)rt)->rt_offset_to_caret(xy, element, position);

		return result;
	}

	extern "C" REBINT rt_caret_to_offset(void* rt, REBGOB *gob, REBXYF* xy, REBINT element, REBINT position)
	{
		REBINT result = 0;
		((rich_text*)rt)->rt_reset();
		((rich_text*)rt)->rt_set_clip(0,0, GOB_W(gob),GOB_H(gob));
		if (GOB_TYPE(gob) == GOBT_TEXT){
			result = Text_Gob(rt, (REBSER *)GOB_CONTENT(gob));
		} else if (GOB_TYPE(gob) == GOBT_STRING) {
			((rich_text*)rt)->rt_set_text((REBCHR*)GOB_STRING(gob), TRUE);
			((rich_text*)rt)->rt_push(1);
		} else {
			xy->x = 0;
			xy->y = 0;
			return result;
		}

		if (result < 0) return result;

		((rich_text*)rt)->rt_caret_to_offset(xy, element, position);

		return result;
	}





}

