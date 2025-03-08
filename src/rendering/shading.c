/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:02:04 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 18:11:16 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_selected(int hit, int sel, t_ray *ray, const t_scene *scene)
{
	if (scene->obj[hit].type == CIR)
	{
		while (scene->obj[hit].type != CYL)
			hit--;
	}
	if (hit == sel)
		ray->color = col_add(ray->color, col_sc_prod(WHITE, 0.2));
}

//cast a ray from the light source to the hit point
//finds if it hits some object
//determine if the hit is before or after the light source
//change the ray color according (in light or shadow)
void	shading(t_hit *hit, t_ray *ray, t_scene *scene)
{
	t_hit		sh_hit;
	float		cos;

	cos = 0;
	if (scene->obj[hit->obj_id].m.exist == true)
		hit->real_p = v_transform(hit->p, scene->obj[hit->obj_id].m, 'p');
	else
		hit->real_p = hit->p;
	ray->o = hit->real_p;
	ray->d = v_subt(scene->light.p, ray->o);
	hit->light_dist = v_modulus(ray->d);
	ray->d = scalar_div(ray->d, hit->light_dist); //make unitary
	find_hit(&sh_hit, *ray, scene, hit->obj_id);
	if (sh_hit.occur == false || sh_hit.dist > hit->light_dist)//there is no other object intersecting the path from hit object to light
	{
		find_normal(hit, scene);
		cos = dot_prod(ray->d, hit->normal);
	}
	phong(hit, ray, scene, cos);
	check_selected(hit->obj_id, scene->select_obj, ray, scene);
}
