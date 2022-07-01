#include "./includes/fractol.h"

void	fractal_null_init(t_fractal *fractal)
{
	fractal->window.mlx = NULL;
	fractal->window.win = NULL;
	fractal->image.img = NULL;
	fractal->image.addr = NULL;
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	fractal_null_init(&fractal);
	init_application_from_args(&fractal, argc, argv);
	fractal.window = create_window(WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (!fractal.window.mlx || !fractal.window.win)
		fail_exit(&fractal, INIT_WINDOW_ERROR);
	fractal.image = create_image(&fractal);
	if (!fractal.image.img || !fractal.image.addr)
		fail_exit(&fractal, INIT_IMAGE_ERROR);
	set_defaults(&fractal);
	draw_fractal(&fractal);
	mlx_hook(fractal.window.win, 6, 6, mouse_motion_hook, &fractal);
	mlx_hook(fractal.window.win, 4, 0, mouse_hook, &fractal);
	mlx_hook(fractal.window.win, 2, 5, keyboard_hook, &fractal);
	mlx_hook(fractal.window.win, 17, 0, close_hook, &fractal);
	mlx_loop(fractal.window.mlx);
	success_exit(&fractal);
	return (0);
}