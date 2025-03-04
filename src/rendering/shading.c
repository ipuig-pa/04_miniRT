/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:02:04 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/04 13:23:10 by ipuig-pa         ###   ########.fr       */
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

	if (scene->obj[hit->obj_id].m.exist == true)
		hit->real_p = p_transform(hit->p, scene->obj[hit->obj_id].m);
	else
		hit->real_p = hit->p;
	ray->o = hit->real_p;
	ray->d = v_subt(scene->light.p, ray->o);
	hit_light_d = v_modulus(ray->d);
	ray->d = scalar_div(ray->d, hit_light_d);
	ray->color = col_prod(ray->color, col_sc_prod(col_prod(scene->obj[hit->obj_id].color, scene->amblight.color), scene->amblight.ratio)); //adding ambient light
	sh_hit.occur = false;
	find_hit(&sh_hit, *ray, scene, hit->obj_id);
	if (sh_hit.occur == false || sh_hit.dist > hit_light_d)//there is no other object intersecting the path from hit object to light
	{
		find_normal(hit, scene);
		cos_theta = dot_prod(ray->d, hit->normal);
		if (cos_theta > 0)
			ray->color = col_add(ray->color, col_prod(scene->obj[hit->obj_id].color,(col_sc_prod(scene->light.color, scene->light.ratio * cos_theta))));
	}
	//if hit then do whatever needed for shadows
	// else
	// {
	// 	if (hit->obj_id == 4)
	// 		printf("HIT	x:%f, y:%f, z:%f, w:%f\nSHA	x:%f, y:%f, z:%f, w:%f\nLIG	x:%f, y:%f, z:%f, w:%f\n\n", hit->p.x, hit->p.y, hit->p.z, hit->p.w, sh_hit.p.x, sh_hit.p.y, sh_hit.p.z, sh_hit.p.w, scene->light.p.x, scene->light.p.y, scene->light.p.z, scene->light.p.w);
	// 	ray->color = scene->obj[sh_hit.obj_id].color; // just to check which object is making the shadow we see
	// 	//ray->color = col_sc_prod(ray->color, 0.0);//Not working!
	// }
}
// t_color	facing_ratio

// t_color	diffuse_comp(t_hit *hit, t_scene *scene, float cos_theta) //or move everything related to cos_theta inside
// {
// 	t_color	diffuse_col;

// 	diffuse_col = col_sc_prod(col_prod(scene->obj[hit->obj_id].color,col_sc_prod(scene->light.color, scene->light.ratio)), cos_theta);
// 	return (diffuse_col);
// }

// t_color	specular()
// {
// 	t_color	spec_col;

// 	spec_col = scene->light.color * 
// }
