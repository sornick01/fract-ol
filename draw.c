#include "includes/fractol.h"

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
	else if (fractal->fractal_type == BURNINGSHIP)
		burningship(fractal);
	else if (fractal->fractal_type == JULIA)
		julia(fractal);
	mlx_put_image_to_window(fractal->window.mlx, fractal->window.win,
		fractal->image.img, 0, 0);
	display_control_tips(fractal);
	return (0);
}

void	display_application_tips(void)
{
	ft_putendl_fd("Correct format: ./fractol \"Fractal set\"", 1);
	ft_putendl_fd("Available fractal sets:", 1);
	ft_putendl_fd("1) Mandelbrot", 1);
	ft_putendl_fd("2) Julia", 1);
	ft_putendl_fd("3) Burningship", 1);
	ft_putendl_fd("4) Tricorn\n", 1);
}

void	display_control_tips(t_fractal *fractal)
{
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 10, WHITE,
		"Move - WASD/arrows");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 40, WHITE,
		"Zoom in - scroll up");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 60, WHITE,
		"(mouse left buton)");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 90, WHITE,
		"Zoom out - scroll down");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 110, WHITE,
		"(mouse right buton)");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 140, WHITE,
		"Depth down/up - Q/E");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 170, WHITE,
		"Julia animation - CTRL");
	mlx_string_put(fractal->window.mlx, fractal->window.win, 10, 200, WHITE,
		"Color palletes - 1/2/3");
}