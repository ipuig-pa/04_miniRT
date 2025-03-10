/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:18:18 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/10 13:25:30 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//maybe change the file name to color utils if we change mypixelput into another file

void	my_pixel_put(t_env *env, int x, int y, int color)
{
	int		offset;
	char	*pixel;
	int		f_x;
	int		f_y;
	int		i_x;

	i_x = x;
	f_x = x + env->res.x_step;
	f_y = y + env->res.y_step;
	while (y < f_y && y < WINDOW_HEIGHT)
	{
		x = i_x;
		while (x < f_x && x < WINDOW_WIDTH)
		{
			if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
				finish_env(env, 1, "Points out of bounds");
			offset = (y * env->img.line_length + x * (env->img.bits_per_pixel / 8));
			pixel = env->img.addr + offset;
			*(unsigned int *)pixel = color;
			x++;
		}
		y++;
	}
}

