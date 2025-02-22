/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:55:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/22 18:30:54 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//calculates intersect point between ray and sphere
//gives the lowest (if the 2 possible solutions)
static void	intersect_sph(t_hit *hit, t_ray *ray, t_sph *sph, int i)
{
	float		root;
	float		a;
	float		h;
	float		c;
	t_vector	v2;

	v2 = point_subt(&sph->c, &ray->p);
	a = dot_product(&ray->v, &ray->v);
	h = dot_product(&ray->v, &v2);
	c = dot_product(&v2, &v2) - powf(sph->d / 2.0, 2); //maybe it will be easier if the value stored is the radius instead of the diameter
	root = powf(h, 2) - a * c;
	if (root >= 0)
	{
		if (((h - sqrtf(root)) / a) > 0)
			update_hit(((h - sqrtf(root)) / a), hit, ray, i);
		else if (root > 0 && (((h + sqrtf(root)) / a) > 0))
			update_hit(((h + sqrtf(root)) / a), hit, ray, i);
	}
}

static void	intersect_pl(t_hit *hit, t_ray *ray, t_pl *pl, int i)
{
	float		cos_theta;
	t_vector	v2;
	float		d;

	cos_theta = dot_product(&pl->v, &ray->v);
	v2 = point_subt(&pl->p, &ray->p);
	if (cos_theta == 0)
	{
		return ; // do it either if they are coincident or parallel with no intersection??
		// if (dot_product(pl->v,v2) == 0) //they are coincident
		// {
		// 	d = distance from the camera to that point of the ;
		// 	update_hit(d, hit, ray, i);
		// }
		// else //they are parallel (no intersection)
		// 	return ();
	}
	d = dot_product(&pl->v, &v2) / dot_product(&pl->v, &ray->v);
	if (d > 0)
		update_hit(d, hit, ray, i);
}

static void	intersect_cyl(t_hit *hit, t_ray *ray, t_cyl *cyl, int i)
{
	(void) hit;
	(void) ray;
	(void) cyl;
	(void) i;
}

void	calc_intersect(t_hit *hit, t_ray *ray, t_scene *scene, int i) //or put this chunk of code inside the find_hit function
{
	if (scene->obj[i].type == SPH)
		intersect_sph(hit, ray, &scene->obj[i].param.sph, i);
	else if (scene->obj[i].type == PL)
		intersect_pl(hit, ray, &scene->obj[i].param.pl, i);
	else if (scene->obj[i].type == CYL)
		intersect_cyl(hit, ray, &scene->obj[i].param.cyl, i);
}

//return the point of the first intersect of the ray
//recalculates ray direction (p and v) according to material properties
void	find_hit(t_hit	*hit, t_ray *ray, t_scene *scene, int h) //allocate the hit if needed
{
	int		i;

	i = 0;
	//allocate for a maximum of 2 times for each object?
	//what about planes exactly coincident with the ray? (line contained in a plane)
	while (i < scene->obj_num)//optimize somehow to not iterate through ALL the objects
	{
		if (i != h)
			calc_intersect(hit, ray, scene, i);
		i++;
	}
}

void	update_hit(float d, t_hit *hit, t_ray *ray, int i)
{
	if (hit->occur == false || hit->dist > d)
	{
		hit->p.x = ray->p.x + ray->v.x * d;
		hit->p.y = ray->p.y + ray->v.y * d;
		hit->p.z = ray->p.z + ray->v.z * d;
		hit->obj_id = i;
		hit->dist = d * v_modulus(&ray->v);
		hit->occur = true;
	}
}
