/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:13:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 14:53:08 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920
# define ASPECT_RATIO //or use one depending on the other????

typedef struct s_scene t_scene;

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
	// double	delta_x;
	// double	delta_y;
	// int		mouse_select; these 3 var is for mouse scorolling event (CAN WE DELETE THEM FROM HERE????)
}			t_data;

typedef struct s_env
{
	char	*rt_scene_file; //is it used or we can erase it?!?!
	void	*mlx;
	void	*mlx_window;
	t_data	img;
	t_scene	*scene;
	t_resol	res;
}			t_env;

void	init_env(t_env *env);
void	finish_env(t_env *env, int return_val, char *str);

#endif