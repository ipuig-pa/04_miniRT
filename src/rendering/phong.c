/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:06:09 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 18:12:17 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	calc_amb(t_color obj_col, const t_amblight *amblight, t_ray *ray)
{
	t_color	amb;

	amb = col_prod(\
			obj_col, \
			col_sc_prod(\
				col_prod(\
					obj_col, \
					amblight->color), \
				amblight->ratio));
	ray->color = amb;
}

static void	calc_diff(t_color obj_col, const t_light *l, float cos, t_ray *ray)
{
	t_color	diff;

	diff = col_prod(\
			obj_col, \
			(col_sc_prod(\
				l->color, \
				l->ratio * cos)));
	ray->color = col_add(diff, ray->color);
}

static void	calc_spec(const t_light *l, t_material mat, float cos2, t_ray *ray)
{
	t_color	spec;

	spec = col_sc_prod(\
			l->color, \
			l->ratio * mat.k_s * powf(cos2, mat.n_s));
	ray->color = col_add(spec, ray->color);
}

void	phong(t_hit *hit, t_ray *ray, t_scene *scene, float cos)
{
	float		cos2;

	calc_amb(scene->obj[hit->obj_id].color, &scene->amblight, ray);
	if (cos > 0)
	{
		calc_diff(scene->obj[hit->obj_id].color, &scene->light, cos, ray);
		cos2 = dot_prod(\
				unit_v(v_reflect(invert_v(ray->d), hit->normal)), \
				unit_v(v_subt(scene->cam.p, ray->o)));
		if (cos2 > 0)
			calc_spec(&scene->light, scene->obj[hit->obj_id].mat, cos2, ray);
	}
}
