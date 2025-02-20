/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:55:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/20 15:53:19 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//calculates intersect point between ray and sphere
//gives the lowest (if the 2 possible solutions)
static void	intersect_sph(t_hit *hit, t_ray *ray, t_scene *scene, int i)
{
	float		root;
	float		a;
	float		h;
	float		c;
	t_vector	v2;

	v2.x = scene->obj[i].p.x - scene->cam->p.x;
	v2.y = scene->obj[i].p.y - scene->cam->p.y;
	v2.z = scene->obj[i].p.z - scene->cam->p.z;
	a = dot_product(ray->v, ray->v);
	h = dot_product(ray->v, v2);
	c = dot_product(v2, v2) - powf(scene->obj[i]->d / 2.0, 2); //maybe it will be easier if the value stored is the radius instead of the diameter
	root = powf(h, 2) - a * c;
	if (root >= 0)
		update_hit(((h - sqrtf(root)) / a), hit, invert_v(v2), i);
	else if (root < 0)
		return ();
}

static void	intersect_pl(t_hit *hit, t_ray *ray, t_scene *scene, int i)
{
	
}

static void	intersect_cyl(t_hit *hit, t_ray *ray, t_scene *scene, int i)
{
	
}

void	calc_intersect(t_hit *hit, t_ray *ray, t_scene *scene, int i) //or put this chunk of code inside the find_hit function
{
	if (obj->type == SPH)
		intersect_sph(hit, ray, scene, i);
	else if (obj->type == PL)
		intersect_pl(hit, ray, scene, i);
	else if (obj->type == CYL)
		intersect_cyl(hit, ray, scene, i);
}

void	update_hit(float d, t_hit *hit, t_vector normal, int i)
{
	if (!hit || hit->dist > d)
	{
		hit->p.x = ray->p.x + ray->v.x * d;
		hit->p.y = ray->p.y + ray->v.y * d;
		hit->p.z = ray->p.z + ray->v.z * d;
		hit->obj_id = i;
		hit->dist = d;
		hit->normal = normal;
	}
}
