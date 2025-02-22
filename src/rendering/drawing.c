/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:18:18 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/22 12:35:47 by ipuig-pa         ###   ########.fr       */
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

void	clamp_col(t_color *color)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (color->rgba[i] > 1)
			color->rgba[i] = 1;
		else if (color->rgba[i] < 0)
			color->rgba[i] = 0;
		i++;
	}
}

int	convert_rgba(t_color *color)
{
	clamp_col(color);
	return ((int)(color->s_comp.a * 255.0f) << 24) | ((int)(color->s_comp.r * 255.0f) << 16) | ((int)(color->s_comp.g * 255.0f) << 8) | ((int)(color->s_comp.b * 255.0f));
}

t_color	col_prod(t_color c1, t_color c2)
{
	int		i;
	t_color	res_col;

	i = 0;
	while (i < 4)
	{
		res_col.rgba[i] = c1.rgba[i] * c2.rgba[i];
		i++;
	}
	clamp_col(&res_col);
	return (res_col);
}

t_color	col_sc_prod(t_color c, float s)
{
	int		i;
	t_color	res_col;

	i = 0;
	while (i < 4)
	{
		res_col.rgba[i] = s * c.rgba[i];
		i++;
	}
	clamp_col(&res_col);
	return (res_col);
}

t_color	col_add(t_color c1, t_color c2)
{
	int		i;
	t_color	res_col;

	i = 0;
	while (i < 4)
	{
		res_col.rgba[i] = c1.rgba[i] + c2.rgba[i];
		i++;
	}
	clamp_col(&res_col);
	return (res_col);
}
