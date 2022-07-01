/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:17:50 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/30 13:40:24 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

static int	iterate_julia(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	double		temp;
	int			iteration;

	iteration = 1;
	z.re = x * fractal->factor.re + fractal->min.re;
	z.im = y * fractal->factor.im + fractal->min.im;
	while (z.re * z.re + z.im * z.im <= 4.0
		&& iteration <= fractal->max_iteration)
	{
		temp = z.re;
		z.re = z.re * z.re - z.im * z.im + fractal->c.re;
		z.im = 2.0 * temp * z.im + fractal->c.im;
		iteration++;
	}
	return (iteration);
}

static void	julia_part(t_fractal *fractal)
{
	int	x;
	int	y;
	int	color;
	int	iteration;

	y = fractal->min_pthread_bound;
	while (y < fractal->max_pthread_bound)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			iteration = iterate_julia(fractal, x, y);
			color = get_color(fractal, iteration, fractal->max_iteration);
			my_mlx_pixel_put(&fractal->image, x, WIN_HEIGHT - y - 1, color);
			x++;
		}
		y++;
	}
}

void	julia(t_fractal *fractal)
{
	int			i;
	pthread_t	threads[THREADS];
	t_fractal	fractals[THREADS];

	fractal->factor.re = (fractal->max.re - fractal->min.re) / WIN_WIDTH;
	fractal->factor.im = (fractal->max.im - fractal->min.im) / WIN_HEIGHT;
	i = 0;
	while (i < THREADS)
	{
		fractals[i] = *fractal;
		fractals[i].min_pthread_bound = i * (WIN_HEIGHT / THREADS);
		fractals[i].max_pthread_bound = (i + 1) * (WIN_HEIGHT / THREADS);
		pthread_create(&threads[i], NULL,
			(void *(*)(void *))julia_part, (void *)&fractals[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
}
