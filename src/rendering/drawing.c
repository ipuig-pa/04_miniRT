/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:18:18 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/19 11:22:04 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_pixel_put(t_env *env, int x, int y, int color)
{
	int		offset;
	char	*pixel;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		finish_env(env, 1, "Points out of bounds");
	offset = (y * env->img.line_length + x * (env->img.bits_per_pixel / 8));
	pixel = env->img.addr + offset;
	*(unsigned int *)pixel = color;
}