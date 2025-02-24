/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:13:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/23 15:13:11 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920
# define ASPECT_RATIO //or use one depending on the other????

typedef struct s_scene t_scene;

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
	char	*rt_scene_file;
	void	*mlx;
	void	*mlx_window;
	t_data	img;
	t_scene	*scene;
}			t_env;

void	init_env(t_env *env);
void	finish_env(t_env *env, int return_val, char *str);

#endif