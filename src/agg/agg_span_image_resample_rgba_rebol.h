//----------------------------------------------------------------------------
// Anti-Grain Geometry - Version 2.3
// Copyright (C) 2002-2005 Maxim Shemanarev (http://www.antigrain.com)
//
// Permission to copy, use, modify, sell and distribute this software 
// is granted provided this copyright notice appears in all copies. 
// This software is provided "as is" without express or implied
// warranty, and with no claim as to its suitability for any purpose.
//
//----------------------------------------------------------------------------
// Contact: mcseem@antigrain.com
//          mcseemagg@yahoo.com
//          http://www.antigrain.com
//----------------------------------------------------------------------------

#ifndef AGG_SPAN_IMAGE_RESAMPLE_RGBA_INCLUDED
#define AGG_SPAN_IMAGE_RESAMPLE_RGBA_INCLUDED

#include "agg_color_rgba.h"
#include "agg_span_image_resample.h"

namespace agg
{

    //========================================span_image_resample_rgba_affine
    template<class ColorT,
             class Order, 
             class Allocator = span_allocator<ColorT>,
			 class Transformator = trans_perspective > 
    class span_image_resample_rgba_affine : 
    public span_image_resample_affine<ColorT, Allocator>
    {
    public:
        typedef ColorT color_type;
        typedef Order order_type;
        typedef Allocator alloc_type;
		typedef Transformator trans_type;
        typedef span_image_resample_affine<color_type, alloc_type> base_type;
        typedef typename base_type::interpolator_type interpolator_type;
        typedef typename color_type::value_type value_type;
        typedef typename color_type::long_type long_type;
        enum base_scale_e
        {
            base_shift      = color_type::base_shift,
            base_mask       = color_type::base_mask,
            downscale_shift = image_filter_shift
        };

        //--------------------------------------------------------------------
        span_image_resample_rgba_affine(alloc_type& alloc) : base_type(alloc) {}

        //--------------------------------------------------------------------
        span_image_resample_rgba_affine(alloc_type& alloc,
                                        const rendering_buffer& src, 
                                        const color_type& back_color,
                                        interpolator_type& inter,
                                        const image_filter_lut& filter) :
            base_type(alloc, src, back_color, inter, filter),
			m_trans_dst(m_trans_dst)
        {}

        //--------------------------------------------------------------------
        span_image_resample_rgba_affine(alloc_type& alloc,
                                        const rendering_buffer& src,
										const rendering_buffer& dst,
                                        interpolator_type& inter,
                                        const image_filter_lut& filter,
										trans_type& trans_dst) :
            base_type(alloc, src, dst, inter, filter),
			m_trans_dst(trans_dst)
        {}


        //--------------------------------------------------------------------
        color_type* generate(int x, int y, unsigned len)
        {
            base_type::interpolator().begin(x + base_type::filter_dx_dbl(), 
                                            y + base_type::filter_dy_dbl(), len);

            long_type fg[4];

            value_type back_r;
            value_type back_g;
            value_type back_b;
            value_type back_a;

			const rendering_buffer& bg_buffer = base_type::destination_image();

			const color_type* bg_color = &base_type::background_color();
			if (bg_color){
				back_r = base_type::background_color().r;
				back_g = base_type::background_color().g;
				back_b = base_type::background_color().b;
				back_a = base_type::background_color().a;
			}

            color_type* span = base_type::allocator().span();

            int diameter = base_type::filter().diameter();
            int filter_size = diameter << image_subpixel_shift;
            int radius_x = (diameter * base_type::m_rx) >> 1;
            int radius_y = (diameter * base_type::m_ry) >> 1;
            int maxx = base_type::source_image().width() - 1;
            int maxy = base_type::source_image().height() - 1;

            const int16* weight_array = base_type::filter().weight_array();

			dda2_line_interpolator li_x;
			dda2_line_interpolator li_y;
if (!bg_color){
            double tx = x;
            double ty = y;

            m_trans_dst.transform(&tx, &ty);
            int x1 = int(tx);
            int y1 = int(ty);

            tx = x + len;
            ty = y;
            m_trans_dst.transform(&tx, &ty);

            li_x = dda2_line_interpolator(x1, int(tx), len);
            li_y = dda2_line_interpolator(y1, int(ty), len);
}

            do
            {
				if (!bg_color){
					const value_type *bg_ptr = (const value_type*)bg_buffer.row(li_y.y()) + ((li_x.y()) << 2);
					++li_x;
					++li_y;
					back_r = bg_ptr[Order::R];
					back_g = bg_ptr[Order::G];
					back_b = bg_ptr[Order::B];
					back_a = 255 - bg_ptr[Order::A];
				}

                base_type::interpolator().coordinates(&x, &y);

                x += base_type::filter_dx_int() - radius_x;
                y += base_type::filter_dy_int() - radius_y;

                fg[0] = fg[1] = fg[2] = fg[3] = image_filter_size / 2;

                int y_lr = y >> image_subpixel_shift;
                int y_hr = ((image_subpixel_mask - (y & image_subpixel_mask)) * 
                                base_type::m_ry_inv) >> 
                                    image_subpixel_shift;
                int total_weight = 0;
                int x_lr_ini = x >> image_subpixel_shift;
                int x_hr_ini = ((image_subpixel_mask - (x & image_subpixel_mask)) * 
                                   base_type::m_rx_inv) >> 
                                       image_subpixel_shift;
                do
                {
                    int weight_y = weight_array[y_hr];
                    int x_lr = x_lr_ini;
                    int x_hr = x_hr_ini;
                    if(y_lr >= 0 && y_lr <= maxy)
                    {
                        const value_type* fg_ptr = (const value_type*)
                            base_type::source_image().row(y_lr) + (x_lr << 2);
                        do
                        {
                            int weight = (weight_y * weight_array[x_hr] + 
                                         image_filter_size / 2) >> 
                                         downscale_shift;

                            if(x_lr >= 0 && x_lr <= maxx)
                            {
                                fg[0] += fg_ptr[0] * weight;
                                fg[1] += fg_ptr[1] * weight;
                                fg[2] += fg_ptr[2] * weight;
                                fg[3] += fg_ptr[3] * weight;
                            }
                            else
                            {
                                fg[order_type::R] += back_r * weight;
                                fg[order_type::G] += back_g * weight;
                                fg[order_type::B] += back_b * weight;
                                fg[order_type::A] += back_a * weight;
                            }
                            total_weight += weight;
                            fg_ptr += 4;
                            x_hr   += base_type::m_rx_inv;
                            ++x_lr;
                        }
                        while(x_hr < filter_size);
                    }
                    else
                    {
                        do
                        {
                            int weight = (weight_y * weight_array[x_hr] + 
                                         image_filter_size / 2) >> 
                                         downscale_shift;

                            total_weight      += weight;
                            fg[order_type::R] += back_r * weight;
                            fg[order_type::G] += back_g * weight;
                            fg[order_type::B] += back_b * weight;
                            fg[order_type::A] += back_a * weight;
                            x_hr              += base_type::m_rx_inv;
                        }
                        while(x_hr < filter_size);
                    }
                    y_hr += base_type::m_ry_inv;
                    ++y_lr;
                }
                while(y_hr < filter_size);

                fg[0] /= total_weight;
                fg[1] /= total_weight;
                fg[2] /= total_weight;
                fg[3] /= total_weight;

                if(fg[0] < 0) fg[0] = 0;
                if(fg[1] < 0) fg[1] = 0;
                if(fg[2] < 0) fg[2] = 0;
                if(fg[3] < 0) fg[3] = 0;

			fg[order_type::A] = 255 - fg[order_type::A];

			//premultiply if needed
            if(fg[order_type::A] != ColorT::base_mask)
            {
                if(fg[order_type::A] == 0)
                {
                    fg[Order::R] = fg[Order::G] = fg[Order::B] = 0;
                } else {
					fg[Order::R] = value_type((fg[Order::R] * fg[order_type::A]) >> ColorT::base_shift);
					fg[Order::G] = value_type((fg[Order::G] * fg[order_type::A]) >> ColorT::base_shift);
					fg[Order::B] = value_type((fg[Order::B] * fg[order_type::A]) >> ColorT::base_shift);
				}
            }

                if(fg[order_type::A] > base_mask)         fg[order_type::A] = base_mask;
                if(fg[order_type::R] > fg[order_type::A]) fg[order_type::R] = fg[order_type::A];
                if(fg[order_type::G] > fg[order_type::A]) fg[order_type::G] = fg[order_type::A];
                if(fg[order_type::B] > fg[order_type::A]) fg[order_type::B] = fg[order_type::A];

                span->r = (value_type)fg[order_type::R];
                span->g = (value_type)fg[order_type::G];
                span->b = (value_type)fg[order_type::B];
                span->a = (value_type)fg[order_type::A];

                ++span;
                ++base_type::interpolator();
            } while(--len);
            return base_type::allocator().span();
        }
		private:
			trans_type m_trans_dst;
    };







    //==============================================span_image_resample_rgba
    template<class ColorT,
             class Order, 
             class Interpolator, 
             class Allocator = span_allocator<ColorT>,
			  class Transformator = trans_perspective >
    class span_image_resample_rgba : 
    public span_image_resample<ColorT, Interpolator, Allocator>
    {
    public:
        typedef ColorT color_type;
        typedef Order order_type;
        typedef Interpolator interpolator_type;
        typedef Allocator alloc_type;
		typedef Transformator trans_type;
        typedef span_image_resample<color_type, interpolator_type, alloc_type> base_type;
        typedef typename color_type::value_type value_type;
        typedef typename color_type::long_type long_type;
        enum base_scale_e
        {
            base_shift = color_type::base_shift,
            base_mask  = color_type::base_mask,
            downscale_shift = image_filter_shift
        };

        //--------------------------------------------------------------------
        span_image_resample_rgba(alloc_type& alloc) : 
            base_type(alloc)
        {}

        //--------------------------------------------------------------------
        span_image_resample_rgba(alloc_type& alloc,
                                 const rendering_buffer& src, 
                                 const color_type& back_color,
                                 interpolator_type& inter,
                                 const image_filter_lut& filter) :
            base_type(alloc, src, back_color, inter, filter),
			m_trans_dst(m_trans_dst)
        {}

		//--------------------------------------------------------------------
        span_image_resample_rgba(alloc_type& alloc,
                                 const rendering_buffer& src, 
								 const rendering_buffer& dst,
                                 interpolator_type& inter,
                                 const image_filter_lut& filter,
								 trans_type& trans_dst) :
			base_type(alloc, src, dst, inter, filter),
			m_trans_dst(trans_dst)
        {}


        //--------------------------------------------------------------------
        color_type* generate(int x, int y, unsigned len)
        {
            color_type* span = base_type::allocator().span();
            base_type::interpolator().begin(x + base_type::filter_dx_dbl(), 
                                            y + base_type::filter_dy_dbl(), len);
            long_type fg[4];

            value_type back_r;
            value_type back_g;
            value_type back_b;
            value_type back_a;

			const rendering_buffer& bg_buffer = base_type::destination_image();

			const color_type* bg_color = &base_type::background_color();
			if (bg_color){
				back_r = base_type::background_color().r;
				back_g = base_type::background_color().g;
				back_b = base_type::background_color().b;
				back_a = base_type::background_color().a;
			}

            int diameter = base_type::filter().diameter();
            int filter_size = diameter << image_subpixel_shift;

            const int16* weight_array = base_type::filter().weight_array();

			dda2_line_interpolator li_x;
			dda2_line_interpolator li_y;
if (!bg_color){
            double tx = x;
            double ty = y;

            m_trans_dst.transform(&tx, &ty);
            int x1 = int(tx);
            int y1 = int(ty);

            tx = x + len;
            ty = y;
            m_trans_dst.transform(&tx, &ty);

            li_x = dda2_line_interpolator(x1, int(tx), len);
            li_y = dda2_line_interpolator(y1, int(ty), len);
}

            do
            {
				if (!bg_color){
					const value_type *bg_ptr = (const value_type*)bg_buffer.row(li_y.y()) + ((li_x.y() << 2));
					++li_x;
					++li_y;
					back_r = bg_ptr[Order::R];
					back_g = bg_ptr[Order::G];
					back_b = bg_ptr[Order::B];
					back_a = 255 - bg_ptr[Order::A];
				}

                int rx;
                int ry;
                int rx_inv = image_subpixel_size;
                int ry_inv = image_subpixel_size;
                base_type::interpolator().coordinates(&x,  &y);
                base_type::interpolator().local_scale(&rx, &ry);

                rx = (rx * base_type::m_blur_x) >> image_subpixel_shift;
                ry = (ry * base_type::m_blur_y) >> image_subpixel_shift;

                if(rx < image_subpixel_size)
                {
                    rx = image_subpixel_size;
                }
                else
                {
                    if(rx > image_subpixel_size * base_type::m_scale_limit) 
                    {
                        rx = image_subpixel_size * base_type::m_scale_limit;
                    }
                    rx_inv = image_subpixel_size * image_subpixel_size / rx;
                }

                if(ry < image_subpixel_size)
                {
                    ry = image_subpixel_size;
                }
                else
                {
                    if(ry > image_subpixel_size * base_type::m_scale_limit) 
                    {
                        ry = image_subpixel_size * base_type::m_scale_limit;
                    }
                    ry_inv = image_subpixel_size * image_subpixel_size / ry;
                }

                int radius_x = (diameter * rx) >> 1;
                int radius_y = (diameter * ry) >> 1;
                int maxx = base_type::source_image().width() - 1;
                int maxy = base_type::source_image().height() - 1;

                x += base_type::filter_dx_int() - radius_x;
                y += base_type::filter_dy_int() - radius_y;

                fg[0] = fg[1] = fg[2] = fg[3] = image_filter_size / 2;

                int y_lr = y >> image_subpixel_shift;
                int y_hr = ((image_subpixel_mask - (y & image_subpixel_mask)) * 
                               ry_inv) >> 
                                   image_subpixel_shift;
                int total_weight = 0;
                int x_lr_ini = x >> image_subpixel_shift;
                int x_hr_ini = ((image_subpixel_mask - (x & image_subpixel_mask)) * 
                                   rx_inv) >> 
                                       image_subpixel_shift;

                do
                {
                    int weight_y = weight_array[y_hr];
                    int x_lr = x_lr_ini;
                    int x_hr = x_hr_ini;
                    if(y_lr >= 0 && y_lr <= maxy)
                    {
                        const value_type* fg_ptr = (const value_type*)
                            base_type::source_image().row(y_lr) + (x_lr << 2);
                        do
                        {
                            int weight = (weight_y * weight_array[x_hr] + 
                                         image_filter_size / 2) >> 
                                         downscale_shift;

                            if(x_lr >= 0 && x_lr <= maxx)
                            {
                                fg[0] += fg_ptr[0] * weight;
                                fg[1] += fg_ptr[1] * weight;
                                fg[2] += fg_ptr[2] * weight;
                                fg[3] += fg_ptr[3] * weight;
                            }
                            else
                            {
                                fg[order_type::R] += back_r * weight;
                                fg[order_type::G] += back_g * weight;
                                fg[order_type::B] += back_b * weight;
                                fg[order_type::A] += back_a * weight;
                            }
                            total_weight += weight;
                            fg_ptr += 4;
                            x_hr   += rx_inv;
                            ++x_lr;
                        }
                        while(x_hr < filter_size);
                    }
                    else
                    {
                        do
                        {
                            int weight = (weight_y * weight_array[x_hr] + 
                                         image_filter_size / 2) >> 
                                         downscale_shift;

                            total_weight      += weight;
                            fg[order_type::R] += back_r * weight;
                            fg[order_type::G] += back_g * weight;
                            fg[order_type::B] += back_b * weight;
                            fg[order_type::A] += back_a * weight;
                            x_hr              += rx_inv;
                        }
                        while(x_hr < filter_size);
                    }
                    y_hr += ry_inv;
                    ++y_lr;
                }
                while(y_hr < filter_size);

                fg[0] /= total_weight;
                fg[1] /= total_weight;
                fg[2] /= total_weight;
                fg[3] /= total_weight;

                if(fg[0] < 0) fg[0] = 0;
                if(fg[1] < 0) fg[1] = 0;
                if(fg[2] < 0) fg[2] = 0;
                if(fg[3] < 0) fg[3] = 0;

			fg[order_type::A] = 255 - fg[order_type::A];

			//premultiply if needed
            if(fg[order_type::A] != ColorT::base_mask)
            {
                if(fg[order_type::A] == 0)
                {
                    fg[Order::R] = fg[Order::G] = fg[Order::B] = 0;
                } else {
					fg[Order::R] = value_type((fg[Order::R] * fg[order_type::A]) >> ColorT::base_shift);
					fg[Order::G] = value_type((fg[Order::G] * fg[order_type::A]) >> ColorT::base_shift);
					fg[Order::B] = value_type((fg[Order::B] * fg[order_type::A]) >> ColorT::base_shift);
				}
            }

                if(fg[order_type::A] > base_mask)         fg[order_type::A] = base_mask;
                if(fg[order_type::R] > fg[order_type::R]) fg[order_type::R] = fg[order_type::R];
                if(fg[order_type::G] > fg[order_type::G]) fg[order_type::G] = fg[order_type::G];
                if(fg[order_type::B] > fg[order_type::B]) fg[order_type::B] = fg[order_type::B];

                span->r = (value_type)fg[order_type::R];
                span->g = (value_type)fg[order_type::G];
                span->b = (value_type)fg[order_type::B];
                span->a = (value_type)fg[order_type::A];

                ++span;
                ++base_type::interpolator();
            } while(--len);
            return base_type::allocator().span();
        }

		private:
			trans_type m_trans_dst;

    };

}


#endif
