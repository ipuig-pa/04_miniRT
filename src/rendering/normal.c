/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:42:44 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/21 11:54:09 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	normal_sph(t_hit *hit, t_sph *sph)
{
	hit->normal.x = (hit->p.x - sph->c.x) / (sph->d / 2.0);
	hit->normal.y = (hit->p.y - sph->c.y) / (sph->d / 2.0);
	hit->normal.z = (hit->p.z - sph->c.z) / (sph->d / 2.0);
}

static void	normal_pl(t_hit *hit, t_pl *pl)
{
	(void) pl;
	(void) hit;
}

static void	normal_cyl(t_hit *hit, t_cyl *cyl)
{
	(void) cyl;
	(void) hit;
}

void	find_normal(t_hit *hit, t_scene *scene)
{
	if (scene->obj[hit->obj_id].type == SPH)
		normal_sph(hit, &scene->obj[hit->obj_id].param.sph);
	else if (scene->obj[hit->obj_id].type == PL)
		normal_pl(hit, &scene->obj[hit->obj_id].param.pl);
	else if (scene->obj[hit->obj_id].type == CYL)
		normal_cyl(hit, &scene->obj[hit->obj_id].param.cyl);
}
