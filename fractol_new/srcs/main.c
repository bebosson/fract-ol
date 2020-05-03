# include "fractol.h"

# define WIN 600
# define E_KEY_PRESS (1l << 0)
# define E_KEY_RELEASE (1L << 1)
# define E_MOUSE_PRESS (1L << 2)
# define E_MOUSE_RELEASE (1L << 3)
# define E_CLOSE = (1L << 17)
//memset env
//init mlx
//open window
//send loop

void	draw(t_env *env)
{
	int		color;
	int		i;
	int		j;
	
	j = 0;
	color = 0x00FFFFFF;
	while (j < WIN * 4)
	{
		i = 0;
		while (i < WIN * 4)
		{
			*(int*)&env->mlx.img_data[i + j * WIN] = color;
			i += 4;
		}
		j += 4;
	}
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.win_ptr, env->mlx.img_ptr, 0, 0);
}

int	key_press(int key, void *param)
{
	(void)param;
	printf("%d\n", key);
	return (0);
}

void		mlx_hooks(t_env *env)
{
//	void			*win;

//	win = env->mlx.win_ptr;
//	mlx_hook(win, 2, E_KEY_PRESS, (int(*)(void))key_press, env);
//	mlx_hook(win, 3, E_KEY_RELEASE, (int(*)(void))key_release, env);
//	mlx_hook(win, 4, E_MOUSE_PRESS, (int(*)(void))mouse_press, env);
//	mlx_hook(win, 5, E_MOUSE_RELEASE, (int(*)(void))mouse_release, env);
//	mlx_hook(win, 6, E_MOUSE_POSITION, (int(*)(void))mouse_position, env);
//	mlx_hook(win, 17, E_CLOSE, (int(*)(void))exit, (void*)0);
//	mlx_loop_hook(env->mlx.mlx_ptr, (int(*)(void))render, (void*)env);
	mlx_loop(env->mlx.mlx_ptr);
}


void	init_mlx(t_env *env)
{
	int p;

	env->mlx.mlx_ptr = mlx_init();
	env->mlx.win_ptr = mlx_new_window(env->mlx.mlx_ptr, WIN, WIN, "fractol");
	env->mlx.img_ptr = mlx_new_image(env->mlx.mlx_ptr, WIN, WIN);
	env->mlx.img_data = mlx_get_data_addr(env->mlx.img_ptr, &p, &p, &p);
}


int main(int ac, char **av)
{
	t_env env;
	
	(void)ac;
	(void)av;
	ft_memset(&env, 0, sizeof(env));
	init_mlx(&env);
	draw(&env);
	mlx_hooks(&env);
}
