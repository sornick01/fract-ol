#include "includes/fractol.h"

void	keyboard_julia_motion(t_fractal *fractal)
{
	if (fractal->is_julia_motion == OFF)
		fractal->is_julia_motion = ON;
	else if (fractal->is_julia_motion == ON)
		fractal->is_julia_motion = OFF;
}

void	keyboard_less_iterations(t_fractal *fractal)
{
	if (fractal->max_iteration - ITERATIONS_CHANGE >= ITERATIONS_MIN)
	{
		fractal->max_iteration -= ITERATIONS_CHANGE;
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		draw_fractal(fractal);
	}
}

void	keyboard_more_iterations(t_fractal *fractal)
{
	if (fractal->max_iteration + ITERATIONS_CHANGE <= ITERATIONS_MAX)
	{
		fractal->max_iteration += ITERATIONS_CHANGE;
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		draw_fractal(fractal);
	}
}

void	keyboard_change_colorset(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_ONE)
	{
		fractal->colorset = COLORSET_GALACTIC;
		draw_fractal(fractal);
	}
	else if (keycode == KEY_TWO)
	{
		fractal->colorset = COLORSET_RED;
		draw_fractal(fractal);
	}
	else if (keycode == KEY_THREE)
	{
		fractal->colorset = COLORSET_PSYCHO;
		draw_fractal(fractal);
	}
}
