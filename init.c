#include "fractol.h"

void	init_fractol(t_fractol *f, t_fractal_type type)
{
	f->type = type;
	f->zoom = 1.0;
	f->max_iter = DEFAULT_ITERATIONS;
	f->color_scheme = 0;
	f->autoplay = false;
	f->auto_zoom_in = true;
	f->auto_last_update = 0.0;
	f->auto_seed = (unsigned int)(type + 1) * 12345;
}

void	init_mandelbrot(t_fractol *f)
{
	init_fractol(f, MANDELBROT);
	f->min_re = -2.0;
	f->max_re = 1.0;
	f->min_im = -1.5;
	f->max_im = 1.5;
}

void	init_julia(t_fractol *f, double c_re, double c_im)
{
	init_fractol(f, JULIA);
	f->julia_c.real = c_re;
	f->julia_c.imag = c_im;
	f->min_re = -2.0;
	f->max_re = 2.0;
	f->min_im = -2.0;
	f->max_im = 2.0;
}

void	init_burning_ship(t_fractol *f)
{
	init_fractol(f, BURNING_SHIP);
	f->min_re = -2.2;
	f->max_re = 1.2;
	f->min_im = -2.2;
	f->max_im = 1.2;
}

void	init_tricorn(t_fractol *f)
{
	init_fractol(f, TRICORN);
	f->min_re = -2.2;
	f->max_re = 2.2;
	f->min_im = -2.0;
	f->max_im = 2.0;
}
