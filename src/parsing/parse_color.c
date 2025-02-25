/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:37:07 by ewu               #+#    #+#             */
/*   Updated: 2025/02/25 12:26:55 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//tomatch the ret type, add a helper ft to ret err_color()
//to indicate that errors in parse_color()
t_color	err_color(void)
{
	return ((t_color){0, 0, 0, 0});
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

// parse color with t_color struct
// UPDATE: convert to [0.0f-1.0f]
// convert_rgba(t_color *color) (in drawing.c) is called later
t_color	parse_color(char *token)
{
	t_color	color;
	char	**clr;

	clr = gc_split(token, ',');
	if (!clr || !clr[0] || !clr[1] || !clr[2] || !clr[3] || para_nbr(clr) != 4)
	{
		p_err("Invalid parameter number for color or malloc failed!");
		free_double_pointer(clr);
		return (err_color());
	}
	color.s_comp.a = ft_atofloat(clr[3]) / 255.0f;
	color.s_comp.r = ft_atofloat(clr[0]) / 255.0f;
	color.s_comp.g = ft_atofloat(clr[1]) / 255.0f;
	color.s_comp.b = ft_atofloat(clr[2]) / 255.0f;
	free_double_pointer(clr);
	if (!valid_color_val(color))
	{
		p_err("Invalid color value!");
		return (err_color());
	}
	return (color);
}
