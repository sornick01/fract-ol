#include "includes/fractol.h"

void	mouse_zoom_in(t_fractal *fractal, int x, int y)
{
	t_complex	mouse;
	double		zoom;

	zoom = 0.9;
	mouse.re = (double)x / (WIN_WIDTH / (fractal->max.re - fractal->min.re))
		+ fractal->min.re;
	mouse.im = (double)y / (WIN_HEIGHT / (fractal->max.im - fractal->min.im))
		* -1 + fractal->max.im;
	fractal->max.re = mouse.re + (zoom * (fractal->max.re - mouse.re));
	fractal->min.re = mouse.re + (zoom * (fractal->min.re - mouse.re));
	fractal->max.im = mouse.im + (zoom * (fractal->max.im - mouse.im));
	fractal->min.im = mouse.im + (zoom * (fractal->min.im - mouse.im));
	mlx_clear_window(fractal->window.mlx, fractal->window.win);
	draw_fractal(fractal);
}

void	mouse_zoom_out(t_fractal *fractal)
{
	if (fractal->min.re >= -4.0 && fractal->max.re <= 4.0
		&& fractal->min.im >= -4.0 && fractal->max.im <= 4.0)
	{
		fractal->max.re += OFFSET * fractal->factor.re;
		fractal->min.re -= OFFSET * fractal->factor.re;
		fractal->max.im += OFFSET * fractal->factor.im;
		fractal->min.im -= OFFSET * fractal->factor.im;
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		draw_fractal(fractal);
	}
}
