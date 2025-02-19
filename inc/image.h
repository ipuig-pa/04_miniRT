/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:13:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/19 11:24:06 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "scene.h"

# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920
# define ASPECT_RATIO //or use one depending on the other????

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

#endif