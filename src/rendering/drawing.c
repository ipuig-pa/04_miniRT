/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:18:18 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:51:16 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	while (y < f_y && y < WDW_HEIGHT)
	{
		x = i_x;
		while (x < f_x && x < WDW_WIDTH)
		{
			if (x < 0 || x >= WDW_WIDTH || y < 0 || y >= WDW_HEIGHT)
				finish_env(env, 1, "Points out of bounds");
			offset = (y * env->img.line_length + \
					x * (env->img.bits_per_pixel / 8));
			pixel = env->img.addr + offset;
			*(unsigned int *)pixel = color;
			x++;
		}
		y++;
	}
}
