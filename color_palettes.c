#include "fractol.h"

static uint32_t	rgba(int r, int g, int b, int a)
{
	return (((uint32_t)r << 24) | ((uint32_t)g << 16)
		| ((uint32_t)b << 8) | (uint32_t)a);
}

uint32_t	palette_rainbow(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(9.0 * (1.0 - t) * t * t * t * 255.0);
	g = (int)(15.0 * (1.0 - t) * (1.0 - t) * t * t * 255.0);
	b = (int)(8.5 * (1.0 - t) * (1.0 - t) * (1.0 - t) * t * 255.0);
	return (rgba(r, g, b, 255));
}

uint32_t	palette_electric(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)((sin(6.0 * t) * 0.5 + 0.5) * 90.0);
	g = (int)((sin(8.0 * t + 1.0) * 0.5 + 0.5) * 200.0);
	b = (int)((sin(10.0 * t + 2.0) * 0.5 + 0.5) * 255.0);
	return (rgba(r, g, b, 255));
}

uint32_t	palette_fire(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255.0 * pow(t, 0.4));
	g = (int)(180.0 * pow(t, 1.2));
	b = (int)(80.0 * pow(t, 2.0));
	return (rgba(r, g, b, 255));
}

uint32_t	palette_gray(double t)
{
	int	shade;

	shade = (int)(t * 255.0);
	return (rgba(shade, shade, shade, 255));
}
