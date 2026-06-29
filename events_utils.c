#include "fractol.h"

void	shift_view(t_fractol *f, double shift_re, double shift_im)
{
	f->min_re += shift_re;
	f->max_re += shift_re;
	f->min_im += shift_im;
	f->max_im += shift_im;
}

void	zoom_at_point(t_fractol *f, int x, int y, double factor)
{
	t_complex	mouse;

	if (factor <= 0.0)
		return ;
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	mouse = map_pixel_to_complex(x, y, f);
	f->min_re = mouse.real + (f->min_re - mouse.real) * factor;
	f->max_re = mouse.real + (f->max_re - mouse.real) * factor;
	f->min_im = mouse.imag + (f->min_im - mouse.imag) * factor;
	f->max_im = mouse.imag + (f->max_im - mouse.imag) * factor;
	f->zoom /= factor;
}

bool	handle_move_keys(mlx_key_data_t keydata, t_fractol *f)
{
	double	shift_re;
	double	shift_im;

	shift_re = (f->max_re - f->min_re) * PAN_RATIO;
	shift_im = (f->max_im - f->min_im) * PAN_RATIO;
	if (keydata.key == MLX_KEY_LEFT)
		return (shift_view(f, -shift_re, 0.0), true);
	if (keydata.key == MLX_KEY_RIGHT)
		return (shift_view(f, shift_re, 0.0), true);
	if (keydata.key == MLX_KEY_UP)
		return (shift_view(f, 0.0, -shift_im), true);
	if (keydata.key == MLX_KEY_DOWN)
		return (shift_view(f, 0.0, shift_im), true);
	return (false);
}

bool	handle_action_keys(mlx_key_data_t keydata, t_fractol *f)
{
	if (keydata.key == MLX_KEY_EQUAL || keydata.key == MLX_KEY_KP_ADD)
		return (increase_iterations(f), true);
	if (keydata.key == MLX_KEY_MINUS || keydata.key == MLX_KEY_KP_SUBTRACT)
		return (decrease_iterations(f), true);
	if (keydata.key == MLX_KEY_C)
		return (change_color_scheme(f), true);
	if (keydata.key == MLX_KEY_R)
		return (reset_view(f), true);
	if (keydata.key == MLX_KEY_A)
		return (toggle_autoplay(f), true);
	return (false);
}
