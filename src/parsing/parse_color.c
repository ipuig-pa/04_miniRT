/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:37:07 by ewu               #+#    #+#             */
/*   Updated: 2025/03/12 20:55:23 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	err_color(void)
{
	t_color	err_color;

	err_color.s_comp.r = -1.0f;
	err_color.s_comp.g = -1.0f;
	err_color.s_comp.b = -1.0f;
	err_color.s_comp.a = -1.0f;
	return (err_color);
}

bool	is_err_color(t_color clr)
{
	return (clr.s_comp.a == -1.0f && \
		clr.s_comp.a == -1.0f && \
		clr.s_comp.a == -1.0f && \
		clr.s_comp.a == -1.0f);
}

/*check valid range of value*/
bool	valid_color_val(t_color clr)
{
	if (clr.s_comp.a >= 0.0f && clr.s_comp.a <= 1.0f && clr.s_comp.r >= 0.0f
		&& clr.s_comp.r <= 1.0f && clr.s_comp.g >= 0.0f && clr.s_comp.g <= 1.0f
		&& clr.s_comp.b >= 0.0f && clr.s_comp.b <= 1.0f)
		return (true);
	return (false);
}

t_color	parse_color(char *token)
{
	t_color	color;
	char	**clr;

	clr = gc_split(token, ',');
	if (para_nbr(clr) != 3 && para_nbr(clr) != 4)
		return (p_err("Error:\nInvalid parameter number for color or \
			malloc failed! Exit!"), err_color());
	if (!clr)
		return (p_err("Error:\nMalloc failed! Exit!"), err_color());
	if (!clr[0] || !clr[1] || !clr[2] || (para_nbr(clr) == 4 && !clr[3]))
		return (free_double_pointer(clr), err_color());
	color.s_comp.a = 0.0f;
	if (para_nbr(clr) == 4)
		color.s_comp.a = ft_atofloat(clr[3]) / 255.0f;
	color.s_comp.r = ft_atofloat(clr[0]) / 255.0f;
	color.s_comp.g = ft_atofloat(clr[1]) / 255.0f;
	color.s_comp.b = ft_atofloat(clr[2]) / 255.0f;
	free_double_pointer(clr);
	if (!valid_color_val(color))
	{
		p_err("Error:\nInvalid color value! Must be within [0-255]! Exit!");
		return (err_color());
	}
	return (color);
}
