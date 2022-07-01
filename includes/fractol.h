#ifndef FRACTOL_H
# define FRACTOL_H

# include "defines.h"
# include <math.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct	s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractal
{
	t_window		window;
	t_image			image;
	t_complex		c;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	int				colorset;
	int				fractal_type;
	int				max_iteration;
	int				is_julia_motion;
	int				min_pthread_bound;
	int				max_pthread_bound;
}	t_fractal;

void	mandelbrot(t_fractal *fractal);

#endif