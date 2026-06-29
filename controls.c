#include "fractol.h"

void	increase_iterations(t_fractol *f)
{
	f->max_iter += ITERATION_STEP;
}

void	decrease_iterations(t_fractol *f)
{
	if (f->max_iter > MIN_ITERATIONS)
		f->max_iter -= ITERATION_STEP;
}

void	reset_view(t_fractol *f)
{
	if (f->type == MANDELBROT)
		init_mandelbrot(f);
	else if (f->type == JULIA)
		init_julia(f, f->julia_c.real, f->julia_c.imag);
	else if (f->type == BURNING_SHIP)
		init_burning_ship(f);
	else if (f->type == TRICORN)
		init_tricorn(f);
}

void	change_color_scheme(t_fractol *f)
{
	f->color_scheme = (f->color_scheme + 1) % 4;
}
