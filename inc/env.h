/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:13:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:51:27 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define WDW_HEIGHT 1080
# define WDW_WIDTH 1920

//forward declaration
struct	s_scene;

typedef struct s_resol
{
	int	res;
	int	x_step;
	int	y_step;
}			t_resol;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_env
{
	char			*rt_scene_file;
	void			*mlx;
	void			*mlx_window;
	t_data			img;
	struct s_scene	*scene;
	t_resol			res;
}			t_env;

void	init_env(t_env *env);
void	finish_env(t_env *env, int return_val, char *str);

#endif