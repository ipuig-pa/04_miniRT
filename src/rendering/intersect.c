/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:55:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/19 19:27:48 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	intersect_sph(t_hit *hit, t_ray *ray, t_scene *scene, int i)
{
	float		root;
	float		sol1;
	float		sol2;
	t_vector	v2;

	v2.x = scene->cam->p.x - ray->p.x;
	v2.y = scene->cam->p.y - ray->p.y;
	v2.z = scene->cam->p.z - ray->p.z;
	root = (power((-2 * dot_product(ray->v,v2)), 2)) - 4 * dot_product(ray->v, ray->v) * (dot_product(v2,v2) * scene->obj[i]->d/2 * scene->obj[i]->d/2)//be sure of how the product is calculated, and see if we can use the same functions for both points and vectors (4d vector)
	if (root >= 0)
	{
		sol1 = //calculations using root and the functions of linalg;
		if (root > 0)
			sol2 = //calculations using root and the functions of linalg;;
		if (root == 0 || sol1 < sol2)
			update_hit(sol1, hit, scene, i);
		else
			update_hit(sol2, hit, scene, i);
	}
	else if (root < 0)
		return ();
}

static void	intersect_pl(t_hit *hit, t_ray *ray, t_scene *scene, int i)
{
	
}

static void	intersect_cyl(t_hit *hit, t_ray *ray, t_scene *scene, int i)
{
	
}

void	calc_intersect(t_hit *hit, t_ray *ray, t_scene *scene, int i)
{
	if (obj->type == SPH)
		intersect_sph(hit, ray, scene, i);
	else if (obj->type == PL)
		intersect_pl(hit, ray, scene, i);
	else if (obj->type == CYL)
		intersect_cyl(hit, ray, scene, i);
}

void	update_hit(t_point p, t_hit *hit, t_scene *scene, int i) //I think that we are going to pass distance (t or d in the equation) instead of point, so the one we should calculate is the point
{
	float	dist;

	dist = calc_dist(scene->cam->p, p);
	if (!hit || hit->dist > dist)
	{
		hit->p = p;
		hit->obj_id = i;
		hit->dist = dist;
	}
}
