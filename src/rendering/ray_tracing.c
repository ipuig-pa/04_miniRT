/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:40:28 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/11 13:03:57 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//anything related with the tracing of the rays and render of the image
#include "minirt.h"

void	ray_tracer(t_env *env)
{
	int		i;
	int		j;
	t_ray	ray;
	t_hit	hit;

	handle_resolution(env);
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			cast_ray(&ray, i, j, env->scene);
			find_hit(&hit, ray, env->scene, -1); //how to distinguish if it hits the light?
			if (hit.occur == true)
			{
				shading(&hit, &ray, env->scene);
				my_pixel_put(env, j, i, convert_rgba(&ray.color)); //how to handle if it hits nothing, we have to put the background?
			}
			else
				my_pixel_put(env, j, i, 0x00000000);
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
	vp_px = v_add(scene->vp.o, scalar_mult(scene->vp.right, (j + 0.5) * scene->vp.px_space));
	vp_px = v_add(vp_px, scalar_mult(scene->vp.up, -(i + 0.5) * scene->vp.px_space));
	ray->d = v_subt(vp_px, scene->cam.p);
	ray->d = unit_v(ray->d);
	ray->color = FILTER; //or take it from the scene file if we are introducing a filter??
	// ray->end = false;
}

void	handle_resolution(t_env	*env)
{
	env->res.x_step = WINDOW_WIDTH / (WINDOW_WIDTH * env->res.res / 100);
	env->res.y_step = WINDOW_HEIGHT / (WINDOW_HEIGHT * env->res.res / 100);
}
