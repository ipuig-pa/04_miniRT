/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:25:32 by ewu               #+#    #+#             */
/*   Updated: 2025/03/12 10:45:39 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//sp 0,0,0 20 255,0,0
int	parse_sphere(t_obj *obj, char **tokens, int i)
{
	if (check_para_num(tokens, 's') == -1)
		return (-1);
	obj->type = SPH;
	obj->color = parse_color(tokens[3]);
	if (is_err_color(obj->color))
		return (-1);
	obj->param.sph.c = parse_vector(tokens[1], 'p');
	if (obj->param.sph.c.w == -1.0f)
		return (-1);
	obj->param.sph.r = ft_atofloat(tokens[2]) / 2.0f;
	if (obj->param.sph.r < 0.0f)
		return (p_err("Error:\nDiameter cannot be negative! Exit!"), -1);
	obj->m = identity();
	parse_material(obj, tokens[4]);
	get_material(obj);
	return (i + 1);
}

/**
 * typedef struct s_sph
{
	t_point	c; //coordinates of the sphere center
	float	r; //sphere diameter (maybe it would be more useful to store the radius r instead of diameter d)
}			t_sph;
 */