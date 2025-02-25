/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:25:32 by ewu               #+#    #+#             */
/*   Updated: 2025/02/25 15:36:41 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//sp 0,0,0 20 255,0,0
void	parse_sphere(t_obj *obj, char **tokens)
{
	if (check_para_num(tokens, 's') == -1)
		return ;
	obj->type = SPH;
	obj->color = parse_color(tokens[3]);
	obj->param.sph.c = parse_point(tokens[1]);
	obj->param.sph.r = ft_atofloat(tokens[2]) / 20.f;
	if (obj->param.sph.r < 0.0f)
	{
		p_err("Diameter cannot be negative!");
		return ;
	}
}

/**
 * typedef struct s_sph
{
	t_point	c; //coordinates of the sphere center
	float	r; //sphere diameter (maybe it would be more useful to store the radius r instead of diameter d)
}			t_sph;
 */