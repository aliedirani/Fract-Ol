#include "fractol.h"

void	cleanup_fractol(t_fractol *f)
{
	if (f->mlx && f->img)
		mlx_delete_image(f->mlx, f->img);
	if (f->mlx)
		mlx_terminate(f->mlx);
	f->img = NULL;
	f->mlx = NULL;
}

void	error_exit(char *message, t_fractol *f)
{
	fprintf(stderr, "Error: %s\n", message);
	cleanup_fractol(f);
	exit(EXIT_FAILURE);
}
