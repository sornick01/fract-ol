#include "includes/fractol.h"

int	close_hook(t_fractal *fractal)
{
	success_exit(fractal);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	if (keycode == MOUSE_SCROLL_UP || keycode == MOUSE_LEFT_BUTTON)
		mouse_zoom_in(fractal, x, y);
	if (keycode == MOUSE_SCROLL_DOWN || keycode == MOUSE_RIGHT_BUTTON)
		mouse_zoom_out(fractal);
	return (0);
}

int	mouse_motion_hook(int x, int y, t_fractal *fractal)
{
	if (fractal->fractal_type == JULIA && fractal->is_julia_motion == ON
		&& (x >= 0 && x <= WIN_WIDTH) && (y >= 0 && y <= WIN_HEIGHT))
	{
		fractal->c.re = 5 * ((double)(x - WIN_WIDTH / 2) / WIN_WIDTH);
		fractal->c.im = 5 * ((double)(y - WIN_HEIGHT / 2) / WIN_HEIGHT);
		mlx_clear_window(fractal->window.mlx, fractal->window.win);
		draw_fractal(fractal);
	}
	return (0);
}

int	keyboard_hook(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		keyboard_move_up(fractal);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		keyboard_move_left(fractal);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		keyboard_move_down(fractal);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		keyboard_move_right(fractal);
	else if (keycode == KEY_Q)
		keyboard_less_iterations(fractal);
	else if (keycode == KEY_CTRL && fractal->fractal_type == JULIA)
		keyboard_julia_motion(fractal);
	else if (keycode == KEY_E)
		keyboard_more_iterations(fractal);
	else if (keycode == KEY_ONE || keycode == KEY_TWO || keycode == KEY_THREE)
		keyboard_change_colorset(keycode, fractal);
	else if (keycode == KEY_ESC)
		success_exit(fractal);
	return (0);
}
