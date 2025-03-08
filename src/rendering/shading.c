/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:02:04 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 13:30:47 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	phong(t_hit *hit, t_ray *ray, t_scene *scene, float cos_theta)
{
	t_color		amb;
	t_color		diff;
	t_color		spec;
	float		cos_theta2;

	diff = BLACK;
	spec = BLACK;
	amb = col_prod(scene->obj[hit->obj_id].color, col_sc_prod(col_prod(scene->obj[hit->obj_id].color, scene->amblight.color), scene->amblight.ratio));
	if (cos_theta > 0)
	{
		diff = col_prod(scene->obj[hit->obj_id].color,(col_sc_prod(scene->light.color, scene->light.ratio * cos_theta)));
		//cos_theta2 = dot_prod(unit_v(v_reflect(unit_v(invert_v(ray->d)), unit_v(hit->normal))), unit_v(v_subt(scene->cam.p, ray->o)));
		cos_theta2 = dot_prod(unit_v(v_reflect(invert_v(ray->d), hit->normal)), unit_v(v_subt(scene->cam.p, ray->o)));
		if (cos_theta2 > 0)
			spec = col_sc_prod(scene->light.color, scene->light.ratio * scene->obj[hit->obj_id].mat.k_s * powf(cos_theta2, scene->obj[hit->obj_id].mat.n_s));
	}
	ray->color = col_add(spec, col_add (diff, amb));
	if (hit->obj_id == scene->select_obj)
		ray->color = col_add(ray->color, col_sc_prod(WHITE, 0.2)); //highlight the selected object: use YELLOW instead?!?!
	(void) cos_theta2; //for testing purpose. DELETE!s
}

//cast a ray from the light source to the hit point
//finds if it hits some object
//determine if the hit is before or after the light source
//change the ray color according (in light or shadow)
void	shading(t_hit *hit, t_ray *ray, t_scene *scene)
{
	t_hit		sh_hit;
	float		cos_theta;

	cos_theta = 0;
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
		cos_theta = dot_prod(ray->d, hit->normal);
	}
	phong(hit, ray, scene, cos_theta);
}

// void	shading(t_hit *hit, t_ray *ray, t_scene *scene)
// {
// 	float		hit_light_d;
// 	t_hit		sh_hit;
// 	float		cos_theta;

// 	if (scene->obj[hit->obj_id].m.exist == true)
// 		hit->real_p = p_transform(hit->p, scene->obj[hit->obj_id].m);
// 	else
// 		hit->real_p = hit->p;
// 	ray->o = hit->real_p;
// 	ray->d = v_subt(scene->light.p, ray->o);
// 	hit_light_d = v_modulus(ray->d);
// 	ray->d = scalar_div(ray->d, hit_light_d);
// 	ray->color = col_prod(ray->color, col_sc_prod(col_prod(scene->obj[hit->obj_id].color, scene->amblight.color), scene->amblight.ratio)); //adding ambient light
// 	sh_hit.occur = false;
// 	find_hit(&sh_hit, *ray, scene, hit->obj_id);
// 	if (sh_hit.occur == false || sh_hit.dist > hit_light_d)//there is no other object intersecting the path from hit object to light
// 	{
// 		find_normal(hit, scene);
// 		cos_theta = dot_prod(ray->d, hit->normal);
// 		if (cos_theta > 0)
// 			ray->color = col_add(ray->color, col_prod(scene->obj[hit->obj_id].color,(col_sc_prod(scene->light.color, scene->light.ratio * cos_theta))));
// 	}
// }

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
