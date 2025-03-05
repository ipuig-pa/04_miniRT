/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:40:28 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/05 18:53:22 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//anything related with the tracing of the rays and render of the image
#include "minirt.h"

static void	do_some_trans(t_env *env) // just for testing purposes, delete from here
{
	t_vector	t_vect;

	t_vect = v_create(2.0, 0.0, 0.0, 0);
	// o_rotate(&env->scene->obj[5], 0.7, env->scene->vp.up);
	//o_scale(&env->scene->obj[5], 2, 2, 2);
	// // env->scene->obj[0].m = m_multiply(m_multiply(translate(env->scene->obj[7].param.sph.c),scale(3, 3, 3)),translate(invert_v(env->scene->obj[7].param.sph.c)));
	// // env->scene->obj[5].m = translate(t_vect);
	// // env->scene->obj[6].m = translate(t_vect);
	// // env->scene->obj[7].m = translate(t_vect);
	// //env->scene->obj[5].m = rotate(-0.7, env->scene->vp.front);
	// //env->scene->obj[5].m = rotate(-0.1, env->scene->vp.up);
	// //env->scene->obj[6].m = rotate(-0.1, env->scene->vp.up);
	// //env->scene->obj[7].m = rotate(-0.1, env->scene->vp.up);
	// // env->scene->obj[5].m = m_multiply(m_multiply(translate(env->scene->obj[5].param.cyl.b),rotate(-2, env->scene->vp.up)),translate(invert_v(env->scene->obj[5].param.cyl.b)));
	// // env->scene->obj[6].m = m_multiply(m_multiply(translate(env->scene->obj[5].param.cyl.b),rotate(-2, env->scene->vp.up)),translate(invert_v(env->scene->obj[5].param.cyl.b)));
	// // env->scene->obj[7].m = m_multiply(m_multiply(translate(env->scene->obj[5].param.cyl.b),rotate(-2, env->scene->vp.up)),translate(invert_v(env->scene->obj[5].param.cyl.b)));
	// env->scene->obj[5].m = m_multiply(m_multiply(translate(env->scene->obj[5].param.cyl.c),scale(2,2,2)),translate(invert_v(env->scene->obj[5].param.cyl.c)));
	// // env->scene->obj[6].m = m_multiply(m_multiply(translate(env->scene->obj[6].param.cir.c),scale(2,2,2)),translate(v_add(invert_v(env->scene->obj[6].param.cir.c),scalar_mult(env->scene->obj[5].param.cyl.a, env->scene->obj[5].param.cyl.h))));
	// // env->scene->obj[7].m = m_multiply(m_multiply(translate(env->scene->obj[7].param.cir.c),scale(2,2,2)),translate(v_add(invert_v(env->scene->obj[7].param.cir.c),scalar_mult(env->scene->obj[5].param.cyl.a, -env->scene->obj[5].param.cyl.h))));
	// //env->scene->obj[4].m = rotate(0.7, env->scene->vp.up);
	// //env->scene->obj[4].m = m_multiply(m_multiply(translate(env->scene->obj[4].param.pl.p),rotate(0.7, env->scene->vp.up)),translate(invert_v(env->scene->obj[4].param.pl.p)));
	// //env->scene->obj[4].m = translate(t_vect);
	(void) env;
	(void) t_vect;
}

//choose if float or double, to have different function prototype in math library function

void	ray_tracer(t_env *env)
{
	int		i;
	int		j;
	t_ray	ray;
	t_hit	hit;

	create_viewport(env->scene); //maybe call it after parsing and not here?
	do_some_trans(env); // just for testing purposes, delete from here
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			hit.occur = false;
			cast_ray(&ray, i, j, env->scene);
			find_hit(&hit, ray, env->scene, -1);
			//how to distinguish if it hits the light
			if (hit.occur == true)
			{
				shading(&hit, &ray, env->scene);
				my_pixel_put(env, j, i, convert_rgba(&ray.color)); //how to handle if it hits nothing, we have to put the background?
			}
			j++;
		}
		i++;
	}
}

//init the ray parameters
//give real world coordinates of its origin (camera)
//uses a vp at dist 1 from camera, size acc. to FOV
//calculate the vector acc. to camera position and pixel in vp
//init to filter color (white by def) as the base color of the ray
//return the point of origin
void	cast_ray(t_ray *ray, int i, int j, t_scene *scene)
{
	t_vector	vp_px;

	ray->o = scene->cam.p;
	vp_px = v_add(scene->vp.o, scalar_mult(scene->vp.right, (j + 0.5) * scene->vp.px_space));
	vp_px = v_add(vp_px, scalar_mult(scene->vp.up, -(i + 0.5) * scene->vp.px_space));
	ray->d = v_subt(vp_px, scene->cam.p);
	ray->d = unit_v(ray->d);
	ray->color = FILTER; //or take it from the scene file if we are introducing a filter??
	// ray->end = false;
}

void	create_viewport(t_scene *scene)
{
	t_vector	world_vert;
	float		half_vp_w;
	float		half_vp_h;

	world_vert = v_create(0.0, 1.0, 0.0, 0.0);
	scene->vp.right = unit_v(cross_prod(scene->cam.v, world_vert));
	scene->vp.up = unit_v(cross_prod(scene->vp.right, scene->cam.v));
	scene->vp.front = unit_v(scene->cam.v);
	half_vp_w = tanf(scene->cam.fov / 2.0);
	half_vp_h = WINDOW_HEIGHT * half_vp_w / WINDOW_WIDTH;
	scene->vp.px_space = 2.0 * half_vp_w / WINDOW_WIDTH;
	scene->vp.o = v_add(scene->cam.p, scene->vp.front);
	scene->vp.o = v_add(scene->vp.o, scalar_mult(scene->vp.right, -half_vp_w));
	scene->vp.o = v_add(scene->vp.o, scalar_mult(scene->vp.up, half_vp_h));
}
