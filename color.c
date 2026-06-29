#include "fractol.h"

static uint32_t	rgba(int r, int g, int b, int a)
{
	return (((uint32_t)r << 24) | ((uint32_t)g << 16)
		| ((uint32_t)b << 8) | (uint32_t)a);
}

uint32_t	get_color(int iterations, int max_iter)
{
	return (get_color_scheme(iterations, max_iter, 0));
}

uint32_t	get_color_scheme(int iterations, int max_iter, int scheme)
{
	double	t;

	if (iterations >= max_iter)
		return (rgba(0, 0, 0, 255));
	t = (double)iterations / (double)max_iter;
	if (scheme == 1)
		return (palette_electric(t));
	if (scheme == 2)
		return (palette_fire(t));
	if (scheme == 3)
		return (palette_gray(t));
	return (palette_rainbow(t));
}
