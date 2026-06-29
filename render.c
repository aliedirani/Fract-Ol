#include "fractol.h"

t_complex	map_pixel_to_complex(int x, int y, t_fractol *f)
{
	t_complex	point;
	double		range_re;
	double		range_im;

	range_re = f->max_re - f->min_re;
	range_im = f->max_im - f->min_im;
	point.real = f->min_re + ((double)x * range_re / (WIDTH - 1));
	point.imag = f->min_im + ((double)y * range_im / (HEIGHT - 1));
	return (point);
}

static int	get_iterations(t_fractol *f, t_complex point)
{
	if (f->type == MANDELBROT)
		return (calculate_mandelbrot(point, f->max_iter));
	if (f->type == JULIA)
		return (calculate_julia(point, f->julia_c, f->max_iter));
	if (f->type == BURNING_SHIP)
		return (calculate_burning_ship(point, f->max_iter));
	return (calculate_tricorn(point, f->max_iter));
}

void	render_fractal(t_fractol *f)
{
	int			x;
	int			y;
	t_complex	point;
	int			iterations;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			point = map_pixel_to_complex(x, y, f);
			iterations = get_iterations(f, point);
			mlx_put_pixel(f->img, x, y,
				get_color_scheme(iterations, f->max_iter, f->color_scheme));
			x++;
		}
		y++;
	}
}
