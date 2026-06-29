#include "fractol.h"

static bool	init_window(t_fractol *f)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, "Fract'ol", true);
	if (!f->mlx)
		return (false);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		return (false);
	if (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0)
		return (false);
	return (true);
}

bool	parse_arguments(int ac, char **av, t_fractol *f)
{
	bool	ok_re;
	bool	ok_im;
	double	re;
	double	im;

	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
		return (init_mandelbrot(f), true);
	if (ac == 2 && ft_strcmp(av[1], "burning_ship") == 0)
		return (init_burning_ship(f), true);
	if (ac == 2 && ft_strcmp(av[1], "tricorn") == 0)
		return (init_tricorn(f), true);
	if (ac != 4 || ft_strcmp(av[1], "julia") != 0)
		return (false);
	re = ft_atof(av[2], &ok_re);
	im = ft_atof(av[3], &ok_im);
	if (!ok_re || !ok_im)
		return (false);
	init_julia(f, re, im);
	return (true);
}

static void	run_fractol(t_fractol *f)
{
	print_controls();
	render_fractal(f);
	print_info(f);
	setup_hooks(f);
	setup_loop_hooks(f);
	mlx_loop(f->mlx);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	f.mlx = NULL;
	f.img = NULL;
	print_banner();
	if (!parse_arguments(ac, av, &f))
	{
		print_usage();
		print_julia_examples();
		return (EXIT_FAILURE);
	}
	if (!init_window(&f))
		error_exit("MLX42 initialization failed", &f);
	run_fractol(&f);
	cleanup_fractol(&f);
	return (EXIT_SUCCESS);
}
