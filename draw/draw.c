#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	draw_fractal(t_fractal *fractal)
{
	if (fractal->fractal_type == MANDELBROT)
		mandelbrot(fractal);
	mlx_put_image_to_window(fractal->window.mlx, fractal->window.win,
		fractal->image.img, 0, 0);
	display_control_tips(fractal);
	return (0);
}