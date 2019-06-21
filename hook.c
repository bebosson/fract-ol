#include "fractol.h"

int		deal_key_c_move(int key, t_frac *data)
{
	if (key == 125)
		data->c_c_i += 0.01;
	if (key == 126)
		data->c_c_i -= 0.01;
	if (key == 123)
		data->c_c_r += 0.01;
	if (key == 124)
		data->c_c_r -= 0.01;
	printf("-------------------\n");
	printf("c_i = %.2f \n",data->c_c_i);
	printf("c_r = %.2f \n",data->c_c_r);

	browse_image(data);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		ft_mouse2(int x, int y, t_frac *data)
{
	printf("%d x %d\n",x,y);
	return (0);
}

int		ft_mouse(void *win, int x, int y, t_frac *data)
{
	printf("%d x %d\n",x,y);
	return (0);
}
/*
int		deal_key_c_move(int key, t_frac *data)
{
	if (key == 126)
		data->color_c *= 10;
	if (key == 125)
	{
		data->color_c /= 10;
		data->color_c++;
	}
//	if (key == 123)
//		data->c_c_r += 0.01;
//	if (key == 124)
//		data->c_c_r -= 0.01;
	printf("-------------------\n");
	printf("color_c = %d \n",data->color_c);
//	printf("c_r = %.2f \n",data->c_c_r);

	browse_image(data);
	return (0);
}
*/
