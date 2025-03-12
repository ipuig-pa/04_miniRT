/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:37:03 by ewu               #+#    #+#             */
/*   Updated: 2025/03/12 10:37:57 by ewu              ###   ########.fr       */
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
int	parse_light(t_light *light, char **tokens, int i)
{
	if (check_para_num(tokens, 'l') == -1)
		return (-1);
	light->p = parse_vector(tokens[1], 'p');
	if (light->p.w == -1.0f)
		return (-1);
	light->ratio = ft_atofloat(tokens[2]);
	if (light->ratio < 0.0f || light->ratio > 1.0f)
		return (p_err("Error:\nInvalid value for brightness ratio! Exit!"), -1);
	light->color = parse_color(tokens[3]);
	if (is_err_color(light->color))
		return (-1);
	return (i);
}
