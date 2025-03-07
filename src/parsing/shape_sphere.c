/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:25:32 by ewu               #+#    #+#             */
/*   Updated: 2025/03/07 16:14:24 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//sp 0,0,0 20 255,0,0
void	parse_sphere(t_obj *obj, char **tokens)
{
	if (check_para_num(tokens, 's') == -1)
		return (gc_clean());
	obj->type = SPH;
	obj->color = parse_color(tokens[3]);
	obj->param.sph.c = parse_vector(tokens[1], 'p');
	obj->param.sph.r = ft_atofloat(tokens[2]) / 2.0f;
	if (obj->param.sph.r < 0.0f)
		return (p_err("Diameter cannot be negative!"), gc_clean());
	obj->m = identity();
	parse_material(obj, tokens[4]);
	get_material(obj);
}

/**
 * typedef struct s_sph
{
	t_point	c; //coordinates of the sphere center
	float	r; //sphere diameter (maybe it would be more useful to store the radius r instead of diameter d)
}			t_sph;
 */