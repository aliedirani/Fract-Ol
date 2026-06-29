#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800
# define DEFAULT_ITERATIONS 80
# define MIN_ITERATIONS 20
# define ITERATION_STEP 10
# define ZOOM_IN_FACTOR 0.90
# define ZOOM_OUT_FACTOR 1.10
# define PAN_RATIO 0.10

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP,
	TRICORN
}	t_fractal_type;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_fractol
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_fractal_type	type;
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			zoom;
	t_complex		julia_c;
	int				max_iter;
	int				color_scheme;
	bool			autoplay;
	bool			auto_zoom_in;
	double			auto_last_update;
	unsigned int	auto_seed;
}	t_fractol;

void		init_fractol(t_fractol *f, t_fractal_type type);
void		init_mandelbrot(t_fractol *f);
void		init_julia(t_fractol *f, double c_re, double c_im);
void		init_burning_ship(t_fractol *f);
void		init_tricorn(t_fractol *f);

void		render_fractal(t_fractol *f);
int			calculate_mandelbrot(t_complex c, int max_iter);
int			calculate_julia(t_complex z, t_complex c, int max_iter);
int			calculate_burning_ship(t_complex c, int max_iter);
int			calculate_tricorn(t_complex c, int max_iter);
uint32_t	get_color(int iterations, int max_iter);
uint32_t	get_color_scheme(int iterations, int max_iter, int scheme);
uint32_t	palette_rainbow(double t);
uint32_t	palette_electric(double t);
uint32_t	palette_fire(double t);
uint32_t	palette_gray(double t);

void		setup_hooks(t_fractol *f);
void		setup_loop_hooks(t_fractol *f);
void		key_handler(mlx_key_data_t keydata, void *param);
void		scroll_handler(double xdelta, double ydelta, void *param);
void		close_handler(void *param);
bool		handle_move_keys(mlx_key_data_t keydata, t_fractol *f);
bool		handle_action_keys(mlx_key_data_t keydata, t_fractol *f);
void		autoplay_loop(void *param);
void		toggle_autoplay(t_fractol *f);

t_complex	map_pixel_to_complex(int x, int y, t_fractol *f);
void		zoom_at_point(t_fractol *f, int x, int y, double factor);
void		shift_view(t_fractol *f, double shift_re, double shift_im);
double		ft_atof(const char *str, bool *ok);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isdigit(int c);
void		cleanup_fractol(t_fractol *f);
void		error_exit(char *message, t_fractol *f);

bool		parse_arguments(int ac, char **av, t_fractol *f);
void		print_usage(void);
void		print_controls(void);
void		print_julia_examples(void);
void		print_info(t_fractol *f);
void		print_banner(void);

void		increase_iterations(t_fractol *f);
void		decrease_iterations(t_fractol *f);
void		reset_view(t_fractol *f);
void		change_color_scheme(t_fractol *f);

#endif
