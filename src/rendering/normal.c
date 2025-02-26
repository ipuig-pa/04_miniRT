/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:42:44 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/26 17:23:16 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	normal_sph(t_hit *hit, t_sph *sph)
{
	hit->normal.x = (hit->p.x - sph->c.x) / (sph->r);
	hit->normal.y = (hit->p.y - sph->c.y) / (sph->r);
	hit->normal.z = (hit->p.z - sph->c.z) / (sph->r);
}

static void	normal_pl(t_hit *hit, t_pl *pl, t_scene *scene)
{
	//can have 2 normals. Check the one in the direction towards light!!!
	hit->normal = pl->n; // if it is already unit vector, which should be for intersect costheta, no need to devide for modulus
	if (dot_prod(point_subt(scene->light->p, hit->p), hit->normal) < 0)
		hit->normal = invert_v(pl->n);
}

static void	normal_cyl(t_hit *hit, t_cyl *cyl)
{
	t_vector	bp;
	t_vector	tan;
	t_vector	n;

	bp = point_subt(hit->p, cyl->b);
	tan = cross_prod(bp, cyl->a);
	n = cross_prod(cyl->a, tan);
	hit->normal.x = n.x / v_modulus(n);
	hit->normal.y = n.y / v_modulus(n);
	hit->normal.z = n.z / v_modulus(n);
}

static void	normal_cir(t_hit *hit, t_cir *cir, t_scene *scene)
{
	hit->normal = cir->n;
	if (dot_prod(point_subt(scene->light->p, hit->p), hit->normal) < 0)
		hit->normal = invert_v(cir->n);
	(void) scene;
}

void	find_normal(t_hit *hit, t_scene *scene)
{
	if (scene->obj[hit->obj_id].type == SPH)
		normal_sph(hit, &scene->obj[hit->obj_id].param.sph);
	else if (scene->obj[hit->obj_id].type == PL)
		normal_pl(hit, &scene->obj[hit->obj_id].param.pl, scene);
	else if (scene->obj[hit->obj_id].type == CYL)
		normal_cyl(hit, &scene->obj[hit->obj_id].param.cyl);
	else if (scene->obj[hit->obj_id].type == CIR)
		normal_cir(hit, &scene->obj[hit->obj_id].param.cir, scene);
}
