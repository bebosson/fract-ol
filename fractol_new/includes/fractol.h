/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:37:38 by bebosson          #+#    #+#             */
/*   Updated: 2020/04/25 18:12:39 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>

# include "libft.h"
# include "mlx.h"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*img_ptr;	
	void	*win_ptr;
	char	*img_data;
}				t_mlx;

typedef struct s_env
{
	t_mlx mlx;	

}				t_env;


#endif
