# include "fractol.h"
# include <stdio.h>



int		mandelbrot(t_frac *data)
{
	double x_temp;
	//	data->c_r = (data->x/data->zoom) - 2.05;
	//	data->c_i = (data->y/data->zoom) - 1.3;

	//	printf("y = %d\n",data->y);
	//	printf("x = %d\n",data->x);
	//	printf("x/300 = %.2f\n",(data->x/300));
	//	printf("x/300 = %.2f\n",data->x/300 - 1.3 );
	//	printf("c_r = %.2f\n",data->c_r);
	//	printf("c_i = %.2f\n",data->c_i);
	data->c_i = (data->y/data->zoom) + data->c_c_i;
	data->c_r = (data->x/data->zoom) + data->c_c_r;
	data->z_x = 0;
	data->z_y = 0;
	data->i = 0;
	//	printf("toto\n");
	while (data->z_x * data->z_x + data->z_y * data->z_y < 4 && data->i < data->i_max)
	{
		x_temp = data->z_x;
		data->z_x = data->z_x * data->z_x - data->z_y * data->z_y + data->c_r;
		data->z_y = 2 * x_temp * data->z_y + data->c_i;
		data->i++;
	}
	//	printf("data->z_x = %.1f \n",data->z_x);
	//	printf("data->z_y = %.1f \n",data->z_y);
	//	printf("data->i = %d \n",data->i);
	if (data->i == data->i_max)
		return (0x000000);
	else
		return (data->color * data->i + data->color_c);
}


void	browse_image(t_frac *data)
{
	int p;

	data->x = 0;
	while (data->x < data->x_max)
	{
		data->y = 0;
		while (data->y < data->y_max)
		{
			p = data->x + data->y * WIDTH;
			//			printf("p = %d\n",p);
			//			printf("couleur = %d \n",mandelbrot(data));
			data->addr[p] = mandelbrot(data);
			//			data->addr[p] = 0xFFFFFF;
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	ft_bzero(data->addr, WIDTH + WIDTH * WIDTH);
}


void	set_data(t_frac *data)
{
	data->zoom = 300;
	data->c_c_i = -0.909;
	data->c_c_r = -0.275;
	data->x_max = WIDTH;
	data->y_max = WIDTH;
	data->color_c = 10;
	data->x = 0;
	data->y = 0;
	data->i = 0;
	data->i_max = 50 ;
	data->color = 265;
}


void	start_graph(t_frac *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, WIDTH, "fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, WIDTH);
	data->addr = (int *)mlx_get_data_addr(data->img, &(data->bpp), &(data->sl), &(data->endian));
}

int		main(int ac, char **av)
{
	t_frac *data;

	if (!(data = (t_frac *)malloc(sizeof(t_frac))))
		return (-1);
	start_graph(data);
	set_data(data);
	browse_image(data);
	mlx_hook(data->win, 2, 0, deal_key_c_move, data);
	mlx_mouse_hook(data->win, ft_mouse, data);
//	mlx_hook(data->win, 4,0, ft_mouse2, data);
	mlx_loop(data->mlx);
	return (0);
}
