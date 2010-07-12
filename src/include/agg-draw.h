//extern AGG-based DRAW functions

extern REBINT Draw_Image(REBSER *image, REBSER *block);
extern void agg_get_size(void* gr, REBPAR* p);

extern void agg_add_vertex (void* gr, REBDEC x,  REBDEC y);
extern void agg_anti_alias(void* gr, REBINT mode);
extern void agg_arc(void* gr, REBPAR* c, REBPAR* r, REBDEC ang1, REBDEC ang2, REBINT closed);
extern void agg_arrow(void* gr, REBCHR* c, REBPAR* ht);
extern void agg_begin_poly (void* gr, REBDEC x,  REBDEC y);
extern void agg_box(void* gr, REBPAR* p1, REBPAR* p2, REBDEC r);
extern void agg_circle(void* gr, REBPAR* p1, REBDEC rx, REBDEC ry);
extern void agg_clip(void* gr, REBPAR* p1, REBPAR* p2);
extern void agg_curve3(void* gr, REBPAR* p1, REBPAR* p2, REBPAR* p3);
extern void agg_curve4(void* gr, REBPAR* p1, REBPAR* p2, REBPAR* p3, REBPAR* p4);
extern void agg_effect (void* gr, REBPAR* p1, REBPAR* p2, REBSER* block);
extern void agg_end_spline (void* gr, REBINT step, REBINT closed);
extern void agg_end_poly (void* gr);
extern void agg_ellipse(void* gr, REBPAR* p1, REBPAR* p2);
extern void agg_fill_image_pen(void* gr, REBSER* img);
extern void agg_fill_pen(void* gr, REBYTE* color);
extern void agg_fill_rule(void* gr, REBINT mode);
extern void agg_gamma(void* gr, REBDEC gamma);
extern void agg_gradient_pen(void* gr, REBINT gradtype, REBPAR* oft, REBDEC begin, REBDEC end, REBDEC ang, REBDEC scX,REBDEC scY, unsigned char *colors, REBDEC* offsets, REBINT mode);
extern void agg_invert_matrix(void* gr);
extern void agg_image(void* gr, REBSER* img, REBPAR* offset, REBYTE* key, REBINT border);
extern void agg_image_filter(void* gr, REBINT type, REBINT mode, REBDEC blur);
extern void agg_image_perspective(void* gr, REBSER* img, REBPAR* p1, REBYTE* key, REBINT border, REBINT pattern, REBINT ox, REBINT oy, REBINT pw, REBINT ph, REBPAR* p2,REBPAR* p3,REBPAR* p4, REBCNT args);
extern void agg_line(void* gr, REBPAR* p1, REBPAR* p2);
extern void agg_line_cap(void* gr, REBINT mode);
extern void agg_line_join(void* gr, REBINT mode);
extern void agg_line_pattern(void* gr, REBYTE* col, REBDEC* patterns);
extern void agg_line_width(void* gr, REBDEC width, REBINT mode);
extern void agg_matrix(void* gr, REBSER* mtx);
extern void agg_pen(void* gr, REBYTE* col, REBSER* img);
extern void agg_pop_matrix(void* gr);
extern void agg_push_matrix(void* gr);
extern void agg_reset_gradient_pen(void* gr);
extern void agg_reset_matrix(void* gr);
extern void agg_rotate(void* gr, REBDEC ang);
extern void agg_scale(void* gr, REBDEC scx, REBDEC scy);
extern void agg_skew(void* gr, REBDEC sx, REBDEC sy);
extern REBINT agg_text(void* gr, REBINT mode, REBPAR* p1, REBPAR* p2, REBSER* block);
extern void agg_transform(void* gr, REBDEC ang, REBPAR* ctr, REBDEC scx, REBDEC scy, REBPAR* oft);
extern void agg_translate(void* gr, REBPAR* p);
extern void agg_triangle(void* gr, REBPAR* p1, REBPAR* p2, REBPAR* p3, REBYTE* c1, REBYTE* c2, REBYTE* c3, REBDEC dilation);

//SHAPE functions
extern void agg_path_open(void* gr);
extern void agg_path_close(void* gr);

extern void agg_path_arc(void* gr, REBINT rel, REBPAR* p, REBDEC rx, REBDEC ry, REBDEC ang, REBINT sweep, REBINT large);
extern void agg_path_curv(void* gr, REBINT rel, REBPAR* p1, REBPAR* p2);
extern void agg_path_curve(void* gr, REBINT rel, REBPAR* p1, REBPAR* p2, REBPAR* p3);
extern void agg_path_hline(void* gr,REBINT rel, REBDEC x);
extern void agg_path_line(void* gr, REBINT rel, REBPAR* p);
extern void agg_path_vline(void* gr,REBINT rel, REBDEC y);
extern void agg_path_move(void* gr, REBINT rel, REBPAR* p);
extern void agg_path_qcurv(void* gr, REBINT rel, REBPAR* p);
extern void agg_path_qcurve(void* gr, REBINT rel, REBPAR* p1, REBPAR* p2);
