#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "mlx.h"
//# include "../../MinilibX/X11/mlx_int.h"
# define WIDTH 600


typedef struct s_frac
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	int			endian;
	int			sl;
	int			bpp;
	int			x_max;
	int			x;
	int			y_max;
	int			y;
	double		c_r;
	double		c_i;
	double		c_c_i;
	double		c_c_r;
	int			i;
	double		zoom;
	int			i_max;
	int			color;
	double		z_x;
	double		z_y;
	int			color_c;
}				t_frac;

int		ft_mouse2(int x, int y, t_frac *data);
int		ft_mouse(void *win, int x, int y, t_frac *data);
int		deal_key_c_move(int key, t_frac *data);
void	browse_image(t_frac *data);
#endif 
