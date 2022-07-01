#include "includes/fractol.h"

void	success_exit(t_fractal *fractal)
{
	mlx_destroy_image(fractal->window.mlx, fractal->image.img);
	mlx_destroy_window(fractal->window.mlx, fractal->window.win);
	exit(EXIT_SUCCESS);
}

void	fail_exit(t_fractal *fractal, char *message)
{
	if ((fractal->window.mlx || fractal->window.win)
		&& (fractal->image.img || fractal->image.addr))
		mlx_destroy_image(fractal->window.mlx, fractal->image.img);
	if (fractal->window.mlx || fractal->window.win)
		mlx_destroy_window(fractal->window.mlx, fractal->window.win);
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}