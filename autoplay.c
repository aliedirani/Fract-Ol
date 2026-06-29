#include "fractol.h"

static unsigned int	next_auto_seed(t_fractol *f)
{
	f->auto_seed = f->auto_seed * 1103515245 + 12345;
	return (f->auto_seed);
}

void	toggle_autoplay(t_fractol *f)
{
	char	*state;

	f->autoplay = !f->autoplay;
	f->auto_last_update = mlx_get_time();
	if (f->autoplay)
		state = "on";
	else
		state = "off";
	printf("Autoplay: %s\n", state);
}

void	autoplay_loop(void *param)
{
	t_fractol	*f;
	int			x;
	int			y;

	f = (t_fractol *)param;
	if (!f->autoplay || mlx_get_time() - f->auto_last_update < 0.08)
		return ;
	f->auto_last_update = mlx_get_time();
	x = (int)(next_auto_seed(f) % WIDTH);
	y = (int)(next_auto_seed(f) % HEIGHT);
	if (f->auto_zoom_in)
		zoom_at_point(f, x, y, ZOOM_IN_FACTOR);
	else
		zoom_at_point(f, x, y, ZOOM_OUT_FACTOR);
	if ((next_auto_seed(f) % 8) == 0)
		change_color_scheme(f);
	if ((next_auto_seed(f) % 20) == 0)
		f->auto_zoom_in = !f->auto_zoom_in;
	render_fractal(f);
}

void	setup_loop_hooks(t_fractol *f)
{
	mlx_loop_hook(f->mlx, &autoplay_loop, f);
}
