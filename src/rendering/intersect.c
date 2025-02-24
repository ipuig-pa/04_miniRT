/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:55:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/24 15:56:55 by ipuig-pa         ###   ########.fr       */
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

	v2 = point_subt(sph->c, ray->o);
	a = dot_prod(ray->d, ray->d);
	h = dot_prod(ray->d, v2);
	c = dot_prod(v2, v2) - powf(sph->r, 2); //maybe it will be easier if the value stored is the radius instead of the diameter
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

	cos_theta = dot_prod(pl->n, ray->d);
	v2 = point_subt(pl->p, ray->o);
	if (cos_theta == 0)
	{
		return ; // do it either if they are coincident or parallel with no intersection??
		// if (dot_prod(pl->n,v2) == 0) //they are coincident
		// {
		// 	d = distance from the camera to that point of the ;
		// 	update_hit(d, hit, ray, i);
		// }
		// else //they are parallel (no intersection)
		// 	return ();
	}
	d = dot_prod(pl->n, v2) / cos_theta;
	if (d > 0)
		update_hit(d, hit, ray, i);
}

static void	intersect_cyl(t_hit *hit, t_ray *ray, t_cyl *cyl, int i)
{
	t_vector	v2;
	t_vector	dxa;
	float		root;
	float		d;
	float		t;

	if (dot_prod(cyl->a, ray->d) != 0)//get the point of intersection and check if it is within the height of the cylinder
	{
		v2 = point_subt(cyl->b, ray->o);
		dxa = cross_prod(ray->d, cyl->a);
		root = (dot_prod(dxa, dxa)) * powf(cyl->r, 2) - powf(dot_prod(v2, dxa), 2);
		d = (dot_prod(dxa, cross_prod(v2, cyl->a)) - sqrtf(root)) / dot_prod(dxa, dxa);
		
		t = dot_prod(cyl->a, v_subt(scalar_mult(ray->d, d), v2));
		if (d < 0 || t > cyl->h || t < 0)
		{
			d = (dot_prod(dxa, cross_prod(v2, cyl->a)) + (sqrtf(root)) / dot_prod(dxa, dxa));
			t = dot_prod(cyl->a, v_subt(scalar_mult(ray->d, d), v2));
		}
		if (t >= 0 && t <= cyl->h)
			update_hit(d, hit, ray, i);
	}
}

static void	intersect_cir(t_hit *hit, t_ray *ray, t_cir *cir, int i)
{
	t_vector	v2;
	float		d;
	t_vector	pc;

	v2 = point_subt(cir->c, ray->o);
	d = dot_prod(cir->n, v2) / dot_prod(cir->n, ray->d);
	pc = point_subt(pv_add(ray->o, scalar_mult(ray->d, d)), cir->c);
	if (dot_prod(pc, pc) < powf(cir->r, 2))
		update_hit(d, hit, ray, i);
}

void	calc_intersect(t_hit *hit, t_ray *ray, t_scene *scene, int i) //or put this chunk of code inside the find_hit function
{
	if (scene->obj[i].type == SPH)
		intersect_sph(hit, ray, &scene->obj[i].param.sph, i);
	else if (scene->obj[i].type == PL)
		intersect_pl(hit, ray, &scene->obj[i].param.pl, i);
	else if (scene->obj[i].type == CYL)
		intersect_cyl(hit, ray, &scene->obj[i].param.cyl, i);
	else if (scene->obj[i].type == CIR)
		intersect_cir(hit, ray, &scene->obj[i].param.cir, i);
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
		hit->p.x = ray->o.x + ray->d.x * d;
		hit->p.y = ray->o.y + ray->d.y * d;
		hit->p.z = ray->o.z + ray->d.z * d;
		hit->obj_id = i;
		hit->dist = d * v_modulus(ray->d);
		hit->occur = true;
	}
}
