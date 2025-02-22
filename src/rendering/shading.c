/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:02:04 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/22 16:41:07 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//cast a ray from the light source to the hit point
//finds if it hits some object
//determine if the hit is before or after the light source
//change the ray color according (in light or shadow)
void	shading(t_hit *hit, t_ray *ray, t_scene *scene)
{
	float		hit_light_d;
	t_hit		sh_hit;
	float		cos_theta;

	ray->p = hit->p; //do a hard_copy or like this is ok?
	hit_light_d = dist(&scene->light->p, &hit->p);
	ray->v.x = (scene->light->p.x - hit->p.x) / hit_light_d; //unitary vector
	ray->v.y = (scene->light->p.y - hit->p.y) / hit_light_d;
	ray->v.z = (scene->light->p.z - hit->p.z) / hit_light_d;
	ray->color = col_prod(ray->color, col_sc_prod(col_prod(scene->obj[hit->obj_id].color, scene->amblight->color), scene->amblight->ratio)); //adding ambient light
	sh_hit.occur = false;
	find_hit(&sh_hit, ray, scene, hit->obj_id);
	//if hit then do whatever needed for shadows
	if (sh_hit.occur == false || sh_hit.dist > hit_light_d)//there is no other object intersecting the path from hit object to light
	{
		find_normal(hit, scene);
		cos_theta = dot_product(&ray->v, &hit->normal);
		if (cos_theta > 0)
			ray->color = col_add(ray->color, col_prod(scene->obj[hit->obj_id].color,(col_sc_prod(scene->light->color, scene->light->ratio * cos_theta))));
	}
	// else
	// {
	// 	ray->color = col_sc_prod(ray->color, 0.0);//Not working!
	// }
}
// t_color	facing_ratio

// t_color	diffuse_comp(t_hit *hit, t_scene *scene, float cos_theta) //or move everything related to cos_theta inside
// {
// 	t_color	diffuse_col;

// 	diffuse_col = col_sc_prod(col_prod(scene->obj[hit->obj_id].color,col_sc_prod(scene->light->color, scene->light->ratio)), cos_theta);
// 	return (diffuse_col);
// }

// t_color	specular()
// {
// 	t_color	spec_col;

// 	spec_col = scene->light->color * 
// }
