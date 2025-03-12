/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:55:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:42:54 by ipuig-pa         ###   ########.fr       */
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
	c = dot_prod(v2, v2) - powf(sph->r, 2);
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
		return (-1);
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

	if (dot_prod(cyl->a, ray.d) != 0)
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

void	calc_intersect(t_ray ray, t_hit *hit, t_scene *scene, int i)
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
	if (t > 0)
		update_hit(t, hit, ray, i);
}
