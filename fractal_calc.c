#include "fractol.h"

static bool	in_cardioid_or_bulb(t_complex c)
{
	double	q;

	q = (c.real - 0.25) * (c.real - 0.25) + (c.imag * c.imag);
	if (q * (q + (c.real - 0.25)) <= 0.25 * c.imag * c.imag)
		return (true);
	if ((c.real + 1.0) * (c.real + 1.0) + c.imag * c.imag <= 0.0625)
		return (true);
	return (false);
}

int	calculate_mandelbrot(t_complex c, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	if (in_cardioid_or_bulb(c))
		return (max_iter);
	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (i < max_iter && ((zr * zr) + (zi * zi)) <= 4.0)
	{
		tmp = (zr * zr) - (zi * zi) + c.real;
		zi = (2.0 * zr * zi) + c.imag;
		zr = tmp;
		i++;
	}
	return (i);
}

int	calculate_julia(t_complex z, t_complex c, int max_iter)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < max_iter && ((z.real * z.real) + (z.imag * z.imag)) <= 4.0)
	{
		tmp = (z.real * z.real) - (z.imag * z.imag) + c.real;
		z.imag = (2.0 * z.real * z.imag) + c.imag;
		z.real = tmp;
		i++;
	}
	return (i);
}

int	calculate_burning_ship(t_complex c, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (i < max_iter && ((zr * zr) + (zi * zi)) <= 4.0)
	{
		zr = fabs(zr);
		zi = fabs(zi);
		tmp = (zr * zr) - (zi * zi) + c.real;
		zi = (2.0 * zr * zi) + c.imag;
		zr = tmp;
		i++;
	}
	return (i);
}

int	calculate_tricorn(t_complex c, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (i < max_iter && ((zr * zr) + (zi * zi)) <= 4.0)
	{
		tmp = (zr * zr) - (zi * zi) + c.real;
		zi = (-2.0 * zr * zi) + c.imag;
		zr = tmp;
		i++;
	}
	return (i);
}
