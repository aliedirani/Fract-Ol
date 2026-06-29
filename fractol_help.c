#include "fractol.h"

void	print_usage(void)
{
	printf("Usage:\n");
	printf("  ./fractol mandelbrot\n");
	printf("  ./fractol julia <real> <imaginary>\n");
	printf("  ./fractol burning_ship\n");
	printf("  ./fractol tricorn\n\n");
}

void	print_controls(void)
{
	printf("Controls:\n");
	printf("  Mouse wheel : Zoom at cursor\n");
	printf("  Arrow keys  : Move view\n");
	printf("  + / -       : Change iteration count\n");
	printf("  C           : Change color scheme\n");
	printf("  R           : Reset current fractal\n");
	printf("  A           : Toggle autoplay mode\n");
	printf("  H           : Print controls\n");
	printf("  I           : Print current state\n");
	printf("  ESC         : Close the window\n\n");
}

void	print_julia_examples(void)
{
	printf("Julia examples:\n");
	printf("  ./fractol julia -0.4 0.6\n");
	printf("  ./fractol julia 0.285 0.01\n");
	printf("  ./fractol julia -0.70176 -0.3842\n");
	printf("  ./fractol julia -0.835 -0.2321\n\n");
}

void	print_info(t_fractol *f)
{
	const char	*name;
	const char	*autoplay;

	name = "Tricorn";
	if (f->type == MANDELBROT)
		name = "Mandelbrot";
	else if (f->type == JULIA)
		name = "Julia";
	else if (f->type == BURNING_SHIP)
		name = "Burning Ship";
	if (f->autoplay)
		autoplay = "on";
	else
		autoplay = "off";
	printf("Fractal: %s | zoom: %.2fx | iterations: %d | palette: %d\n",
		name, f->zoom, f->max_iter, f->color_scheme + 1);
	printf("Autoplay: %s\n", autoplay);
	if (f->type == JULIA)
		printf("Julia constant: %.6f + %.6fi\n",
			f->julia_c.real, f->julia_c.imag);
}

void	print_banner(void)
{
	printf("========================================\n");
	printf("              FRACT'OL\n");
	printf("========================================\n");
}
