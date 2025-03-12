/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:20:35 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:44:59 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	set_color(float r, float g, float b, float a)
{
	t_color	col;

	col.s_comp.r = r;
	col.s_comp.g = g;
	col.s_comp.b = b;
	col.s_comp.a = a;
	return (col);
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

