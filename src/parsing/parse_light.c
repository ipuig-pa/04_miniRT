/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:37:03 by ewu               #+#    #+#             */
/*   Updated: 2025/02/27 11:46:10 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * typedef struct s_light
{
	t_point	p;
	float	ratio;//brightness level[0.0f-1.0f]
	t_color	color;
}		t_light;
formaye: L -40,0,30 0.7 255,255,255
 */
void	parse_light(t_light light, char **tokens)
{
	if (check_para_num(tokens, 'l') == -1)
		return (gc_clean());
	light.p = parse_point(tokens[1]);
	light.ratio = ft_atofloat(tokens[2]);
	if (light.ratio < 0.0f || light.ratio > 1.0f)
		return (p_err("Invalid value for brightness ratio!"), gc_clean());
	light.color = parse_color(tokens[3]);
}
