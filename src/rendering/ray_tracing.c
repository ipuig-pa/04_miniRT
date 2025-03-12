/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:40:28 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:50:52 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ray_tracer(t_env *env)
{
	int		i;
	int		j;
	t_ray	ray;
	t_hit	hit;

	check_enclosed_light(env->scene);
	handle_resolution(env);
	i = 0;
	while (i < WDW_HEIGHT)
	{
		j = 0;
		while (j < WDW_WIDTH)
		{
			cast_ray(&ray, i, j, env->scene);
			find_hit(&hit, ray, env->scene, -1);
			if (hit.occur == true)
				shading(&hit, &ray, env->scene);
			else
				ray.color = set_color(0, 0, 0, 0);
			my_pixel_put(env, j, i, convert_rgba(&ray.color));
			j += env->res.x_step;
		}
		i += env->res.y_step;
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
	vp_px = v_add(\
				scene->vp.o, \
				scalar_mult(scene->vp.right, (j + 0.5) * scene->vp.px_space));
	vp_px = v_add(\
				vp_px, \
				scalar_mult(scene->vp.up, -(i + 0.5) * scene->vp.px_space));
	ray->d = v_subt(vp_px, scene->cam.p);
	ray->d = unit_v(ray->d);
	ray->color = set_color(1, 1, 1, 0);
}

//return the point of the first intersect of the ray
//recalculates ray direction (p and v) according to material properties
//h identifies the object to be excluded from the shadow checking
void	find_hit(t_hit	*hit, t_ray ray, t_scene *scene, int h)
{
	int		i;

	i = 0;
	hit->occur = false;
	while (i < scene->obj_num)
	{
		if (i != h)
		{
			if (scene->obj[i].m.exist == true)
				calc_intersect(r_transform(ray, scene->obj[i].inv_m), \
				hit, scene, i);
			else
				calc_intersect(ray, hit, scene, i);
		}
		i++;
	}
}

void	update_hit(float t, t_hit *hit, t_ray ray, int i)
{
	if (hit->occur == false || hit->dist > t)
	{
		hit->p = v_add(ray.o, scalar_mult(ray.d, t));
		hit->obj_id = i;
		hit->dist = t;
		hit->occur = true;
	}
}

void	handle_resolution(t_env	*env)
{
	env->res.x_step = WDW_WIDTH / (WDW_WIDTH * env->res.res / 100);
	env->res.y_step = WDW_HEIGHT / (WDW_HEIGHT * env->res.res / 100);
}
