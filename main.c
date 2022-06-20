#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	printf("%d, %d, %d\n", img.bits_per_pixel, img.line_length, img.endian);

	for (int x = -500; x < 500; x++)
	{
		for (int y = -500; y < +500; y++)
		{
			if ((x) * (x) + (y) * (y) <= 150 * 150)
				my_mlx_pixel_put(&img, 1920/2 + x, 1080/2 - y, 0x00FF0000);
		}
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 10, 10);

	mlx_loop(mlx);
}