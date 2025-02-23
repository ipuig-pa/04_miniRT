/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:37:07 by ewu               #+#    #+#             */
/*   Updated: 2025/02/23 12:33:02 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	para_nbr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

/*check valid range of value*/
bool	valid_color_val(t_color *clr)
{
	if (clr->s_comp.a >= 0 && clr->s_comp.a <= 255 && clr->s_comp.r >= 0
		&& clr->s_comp.r <= 255 && clr->s_comp.g >= 0 && clr->s_comp.g <= 255
		&& clr->s_comp.b >= 0 && clr->s_comp.b <= 255)
		return (true);
	return (false);
}

// parse color with t_color struct
// color formatted as: 255,255,255,255
t_color	*parse_color(char *token)
{
	t_color	*color;
	char	**clr;

	clr = gc_split(token, ',');
	if (!clr || !clr[0] || !clr[1] || !clr[2] || !clr[3] || para_nbr(clr) != 4)
		return (p_err("Invalid parameter number or malloc failed!"),
			free_double_pointer(clr), NULL);
	color->s_comp.r = ft_atofloat(clr[0]);
	color->s_comp.g = ft_atofloat(clr[1]);
	color->s_comp.b = ft_atofloat(clr[2]);
	color->s_comp.a = ft_atofloat(clr[3]);
	free_double_pointer(clr);
	if (!valid_color_val(color))
		return (p_err("Invalid color value!"), free(color), NULL);
	return (color);
}
