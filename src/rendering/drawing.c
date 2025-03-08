/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:18:18 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 12:27:25 by ipuig-pa         ###   ########.fr       */
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

t_color	set_color(float r, float g, float b, float a)
{
	t_color	col;

	col.s_comp.r = r;
	col.s_comp.g = g;
	col.s_comp.b = b;
	col.s_comp.a = a;
	return (col);
}
