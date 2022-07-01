#include <stdio.h>
#include "./includes/fractol.h"
#include <mlx.h>

#define KEY_ESC 65307

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		return (0);
	}
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 100, 100, "Hello world!");
	mlx_hook(vars.win, 4, 5, close, &vars);
	mlx_loop(vars.mlx);
}