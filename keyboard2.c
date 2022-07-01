#include "includes/fractol.h"

void	keyboard_move_right(t_fractal *fractal)
{
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	fractal->min.re += OFFSET * fractal->factor.re;
	fractal->max.re += OFFSET * fractal->factor.re;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	keyboard_move_left(t_fractal *fractal)
{
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	fractal->min.re -= OFFSET * fractal->factor.re;
	fractal->max.re -= OFFSET * fractal->factor.re;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	keyboard_move_up(t_fractal *fractal)
{
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	fractal->min.im += OFFSET * fractal->factor.im;
	fractal->max.im += OFFSET * fractal->factor.im;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	keyboard_move_down(t_fractal *fractal)
{
	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	fractal->min.im -= OFFSET * fractal->factor.im;
	fractal->max.im -= OFFSET * fractal->factor.im;
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}
