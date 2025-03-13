/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:37:03 by ewu               #+#    #+#             */
/*   Updated: 2025/03/13 11:01:35 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_light(t_light *light, char **tokens, int i)
{
	if (check_para_num(tokens, 'l') == -1)
		return (-1);
	light->p = parse_vector(tokens[1], 'p');
	if (light->p.w == -1.0f)
		return (-1);
	light->ratio = ft_atofloat(tokens[2]);
	if (light->ratio < 0.0f || light->ratio > 1.0f)
		return (p_err("Error:\nInvalid value for brightness ratio! \
Must be within [0.0-1.0]. Exit!"), -1);
	light->color = parse_color(tokens[3]);
	if (is_err_color(light->color))
		return (-1);
	return (i);
}
