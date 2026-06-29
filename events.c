#include "fractol.h"

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_fractol	*f;
	bool		needs_render;

	f = (t_fractol *)param;
	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(f->mlx);
	needs_render = handle_move_keys(keydata, f);
	if (!needs_render)
		needs_render = handle_action_keys(keydata, f);
	if (needs_render)
		render_fractal(f);
	if (keydata.key == MLX_KEY_H)
		print_controls();
	if (keydata.key == MLX_KEY_I || keydata.key == MLX_KEY_H)
		print_info(f);
}

void	scroll_handler(double xdelta, double ydelta, void *param)
{
	t_fractol	*f;
	int32_t		mouse_x;
	int32_t		mouse_y;

	(void)xdelta;
	f = (t_fractol *)param;
	if (ydelta == 0.0)
		return ;
	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	if (ydelta > 0.0)
		zoom_at_point(f, mouse_x, mouse_y, ZOOM_IN_FACTOR);
	else
		zoom_at_point(f, mouse_x, mouse_y, ZOOM_OUT_FACTOR);
	render_fractal(f);
}

void	close_handler(void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	mlx_close_window(f->mlx);
}

void	setup_hooks(t_fractol *f)
{
	mlx_key_hook(f->mlx, &key_handler, f);
	mlx_scroll_hook(f->mlx, &scroll_handler, f);
	mlx_close_hook(f->mlx, &close_handler, f);
}
