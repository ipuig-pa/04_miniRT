/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:55:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/05 15:55:56 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//calculates intersect point between ray and sphere
//gives the lowest (if the 2 possible solutions)
static float	intersect_sph(t_ray ray, t_sph *sph)
{
	float		root;
	float		a;
	float		h;
	float		c;
	t_vector	v2;

	v2 = v_subt(sph->c, ray.o);
	a = dot_prod(ray.d, ray.d);
	h = dot_prod(ray.d, v2);
	c = dot_prod(v2, v2) - powf(sph->r, 2); //maybe it will be easier if the value stored is the radius instead of the diameter
	root = powf(h, 2) - a * c;
	if (root >= 0)
	{
		if (((h - sqrtf(root)) / a) > 0)
			return ((h - sqrtf(root)) / a);
		else if (root > 0 && (((h + sqrtf(root)) / a) > 0))
			return ((h + sqrtf(root)) / a);
	}
	return (-1);
}

static float	intersect_pl(t_ray ray, t_pl *pl)
{
	float		cos_theta;
	t_vector	v2;
	float		d;

	cos_theta = dot_prod(pl->n, ray.d);
	v2 = v_subt(pl->p, ray.o);
	if (cos_theta == 0)
	{
		return (-1); // do it either if they are coincident or parallel with no intersection??
		// if (dot_prod(pl->n,v2) == 0) //they are coincident
		// {
		// 	d = distance from the camera to that point of the ;
		// 	update_hit(d, hit, ray, i);
		// }
		// else //they are parallel (no intersection)
		// 	return ();
	}
	d = dot_prod(pl->n, v2) / cos_theta;
	return (d);
}

static float	intersect_cyl(t_ray ray, t_cyl *cyl)
{
	t_vector	v2;
	t_vector	dxa;
	float		root;
	float		d;
	float		t;

	if (dot_prod(cyl->a, ray.d) != 0)//get the point of intersection and check if it is within the height of the cylinder
	{
		v2 = v_subt(cyl->b, ray.o);
		dxa = cross_prod(ray.d, cyl->a);
		root = (dot_prod(dxa, dxa)) * powf(cyl->r, 2) - powf(dot_prod(v2, dxa), 2);
		d = (dot_prod(dxa, cross_prod(v2, cyl->a)) - sqrtf(root)) / dot_prod(dxa, dxa);
		t = dot_prod(cyl->a, v_subt(scalar_mult(ray.d, d), v2));
		if (d < 0 || t > cyl->h || t < 0)
		{
			d = (dot_prod(dxa, cross_prod(v2, cyl->a)) + sqrtf(root)) / dot_prod(dxa, dxa);
			t = dot_prod(cyl->a, v_subt(scalar_mult(ray.d, d), v2));
		}
		if (t >= 0 && t <= cyl->h)
			return (d);
	}
	return (-1);
}

static float	intersect_cir(t_ray ray, t_cir *cir)
{
	t_vector	v2;
	float		d;
	t_vector	pc;

	v2 = v_subt(cir->c, ray.o);
	d = dot_prod(cir->n, v2) / dot_prod(cir->n, ray.d);
	pc = v_subt(v_add(ray.o, scalar_mult(ray.d, d)), cir->c);
	if (dot_prod(pc, pc) < powf(cir->r, 2))
		return (d);
	return (-1);
}

void	calc_intersect(t_ray ray, t_hit *hit, t_scene *scene, int i) //or put this chunk of code inside the find_hit function
{
	float	t;

	t = -1;
	if (scene->obj[i].type == SPH)
		t = intersect_sph(ray, &scene->obj[i].param.sph);
	else if (scene->obj[i].type == PL)
		t = intersect_pl(ray, &scene->obj[i].param.pl);
	else if (scene->obj[i].type == CYL)
		t = intersect_cyl(ray, &scene->obj[i].param.cyl);
	else if (scene->obj[i].type == CIR)
		t = intersect_cir(ray, &scene->obj[i].param.cir);
	if (t > 0) // d -1 is returned when no hit occur
		update_hit(t, hit, ray, i);
}

//return the point of the first intersect of the ray
//recalculates ray direction (p and v) according to material properties
//h identifies the object to be excluded from the shadow checking
void	find_hit(t_hit	*hit, t_ray ray, t_scene *scene, int h) //allocate the hit if needed
{
	int		i;
	//t_ray	t_ray;

	i = 0;
	//what about planes exactly coincident with the ray? (line contained in a plane)
	while (i < scene->obj_num)//optimize somehow to not iterate through ALL the objects??
	{
		if (i != h)
		{
			if (scene->obj[i].m.exist == true)
			{
				// t_ray = r_transform(ray, m_invert(scene->obj[i].m));
				// printf("i:		%i\nT_RAY POS	x:%f, y:%f, z:%f, w:%f\nT_RAY DIR	x:%f, y:%f, z:%f, w:%f\n\n", i, t_ray.o.x, t_ray.o.y, t_ray.o.z, t_ray.o.w, t_ray.d.x, t_ray.d.y, t_ray.d.z, t_ray.d.w);
				calc_intersect(r_transform(ray, m_invert(scene->obj[i].m)), hit, scene, i);
			}
			else
				calc_intersect(ray, hit, scene, i); //pass transformed ray always if we change to obj space always???? (multiplied by the t_m of the object, if there was any transformation)
		}
		i++;
	}
}

//If reflexion is included, we want to keep track of all the hits (not just the most poximal one). Then, caluclate the normal in situ (do not apply that much matrix transformations)
void	update_hit(float t, t_hit *hit, t_ray ray, int i)
{
	if (hit->occur == false || hit->dist > t)
	{
		hit->p = v_add(ray.o, scalar_mult(ray.d, t));
		hit->obj_id = i;
		// hit->dist = t * v_modulus(ray.d);
		hit->dist = t;
		hit->occur = true;
	}
}
