/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:21:43 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:44:54 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_white(t_color col)
{
	float	threshold;

	threshold = 0.8;
	if (col.s_comp.r > threshold && col.s_comp.g > threshold && \
		col.s_comp.b > threshold)
		return (true);
	return (false);
}

t_color	complementary(t_color col)
{
	t_color	comp;

	comp.s_comp.r = 1.0 - col.s_comp.r;
	comp.s_comp.g = 1.0 - col.s_comp.g;
	comp.s_comp.b = 1.0 - col.s_comp.b;
	comp.s_comp.a = col.s_comp.a;
	return (comp);
}

int	convert_rgba(t_color *color)
{
	clamp_col(color);
	return (((int)(color->s_comp.a * 255.0f) << 24) | \
			((int)(color->s_comp.r * 255.0f) << 16) | \
			((int)(color->s_comp.g * 255.0f) << 8) | \
			((int)(color->s_comp.b * 255.0f)));
}
