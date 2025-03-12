/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:30:00 by ewu               #+#    #+#             */
/*   Updated: 2025/03/12 20:54:18 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_camera(t_camera *camera, char **tokens, int i)
{
	float	degree;

	if (check_para_num(tokens, 'c') == -1)
		return (-1);
	camera->p = parse_vector(tokens[1], 'p');
	if (camera->p.w == -1.0f)
		return (-1);
	camera->v = norm_vector(parse_vector(tokens[2], 'v'));
	if (camera->v.w == -1.0f)
		return (-1);
	if (check_norm_range(camera->v) == -1)
		return (p_err("Error:\nCamera orientation vector \
			out of range! Must be within [-1,1]. Exit!"), -1);
	degree = ft_atofloat(tokens[3]);
	if (degree <= 0.0f || degree > 180.0f)
		return (p_err("Error:\nInvalid degree of FOV! \
			Must be within [0-180]. Exit!"), -1);
	camera->fov = degree * (M_PI / 180.0f);
	return (i);
}
