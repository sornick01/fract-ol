#include "includes/fractol.h"

static int	set_colorset_galactic(int iteration, int max_iteration)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	if (iteration >= max_iteration)
	{
		red = 30;
		green = 0;
		blue = 0;
	}
	else
	{	
		t = (double)iteration / (double)(1 + max_iteration);
		red = (int)(9 * (1 - t) * pow(t, 3) * 255);
		green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	}
	return (((red & 0xFF) << 16) + ((green & 0xFF) << 8) + (blue & 0xFF));
}

static int	set_colorset_red(int iteration, int max_iteration)
{
	int		red;
	int		green;
	int		blue;

	if (iteration >= max_iteration)
	{
		red = 141;
		green = 26;
		blue = 187;
	}
	else
	{
		red = (iteration * 12) % 255;
		green = (iteration * 0) % 255;
		blue = (iteration * 6) % 255;
	}
	return (((red & 0xFF) << 16) + ((green & 0xFF) << 8) + (blue & 0xFF));
}

static int	set_colorset_psycho(int iteration, int max_iteration)
{
	int		red;
	int		green;
	int		blue;

	if (iteration >= max_iteration)
	{
		red = 20;
		green = 0;
		blue = 80;
	}
	else
	{
		red = (iteration * 128) % 255;
		green = (iteration * 255) % 255;
		blue = (iteration * 64) % 255;
	}
	return (((red & 0xFF) << 16) + ((green & 0xFF) << 8) + (blue & 0xFF));
}

int	get_color(t_fractal *fractal, int iteration, int max_iteration)
{
	int	color;

	color = 0;
	if (fractal->colorset == COLORSET_GALACTIC)
		color = set_colorset_galactic(iteration, max_iteration);
	else if (fractal->colorset == COLORSET_RED)
		color = set_colorset_red(iteration, max_iteration);
	else if (fractal->colorset == COLORSET_PSYCHO)
		color = set_colorset_psycho(iteration, max_iteration);
	return (color);
}
