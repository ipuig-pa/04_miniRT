/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:42:44 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 10:50:55 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	normal_sph(t_hit *hit, t_sph *sph, t_scene *scene)
{
	hit->normal = scalar_div(v_subt(hit->p, sph->c), sph->r);
	if (scene->obj[hit->obj_id].m.exist == true)
	{
		hit->normal = v_transform(hit->normal, scene->obj[hit->obj_id].m, 'v');
		hit->normal = unit_v(hit->normal); //make unit vector after transformatio!?!?
	}
}

static void	normal_pl(t_hit *hit, t_pl *pl, t_scene *scene)
{
	//can have 2 normals. Check the one in the direction we are interested (in the direction towards the camera once transformed if needed)
	hit->normal = pl->n; // if it is already unit vector, which should be for intersect costheta, no need to devide for modulus
	if (scene->obj[hit->obj_id].m.exist == true)
	{
		hit->normal = v_transform(hit->normal, scene->obj[hit->obj_id].m, 'v');
		hit->normal = unit_v(hit->normal);  //make unit vector after transformation??!?
	}
	if (dot_prod(v_subt(scene->cam.p, hit->real_p), hit->normal) < 0)
		hit->normal = invert_v(hit->normal); //make unit vector??!?
}

static void	normal_cyl(t_hit *hit, t_cyl *cyl, t_scene *scene)
{
	t_vector	bp;
	t_vector	tan;

	bp = v_subt(hit->p, cyl->b);
	tan = cross_prod(bp, cyl->a);
	hit->normal = unit_v(cross_prod(cyl->a, tan));
	if (scene->obj[hit->obj_id].m.exist == true)
	{
		hit->normal = v_transform(hit->normal, scene->obj[hit->obj_id].m, 'v');
		hit->normal = unit_v(hit->normal);  //make unit vector after transformation??!?
	}
}

static void	normal_cir(t_hit *hit, t_cir *cir, t_scene *scene)
{
	hit->normal = cir->n;
	if (scene->obj[hit->obj_id].m.exist == true)
	{
		hit->normal = v_transform(hit->normal, scene->obj[hit->obj_id].m, 'v');
		hit->normal = unit_v(hit->normal);  //make unit vector after transformation??!?
	}
	if (dot_prod(v_subt(scene->cam.p, hit->real_p), hit->normal) < 0)
		hit->normal = invert_v(cir->n);
}

void	find_normal(t_hit *hit, t_scene *scene)
{
	if (scene->obj[hit->obj_id].type == SPH)
		normal_sph(hit, &scene->obj[hit->obj_id].param.sph, scene);
	else if (scene->obj[hit->obj_id].type == PL)
		normal_pl(hit, &scene->obj[hit->obj_id].param.pl, scene);
	else if (scene->obj[hit->obj_id].type == CYL)
		normal_cyl(hit, &scene->obj[hit->obj_id].param.cyl, scene);
	else if (scene->obj[hit->obj_id].type == CIR)
		normal_cir(hit, &scene->obj[hit->obj_id].param.cir, scene);
}
