#include "includes/fractol.h"

t_window	create_window(int width, int height, char *title)
{
	t_window	window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, width, height, title);
	return (window);
}