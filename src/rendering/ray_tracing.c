/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:40:28 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/24 13:03:13 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//anything related with the tracing of the rays and render of the image
#include "minirt.h"

//choose if float or double, to have different function prototype in math library function

void	ray_tracer(t_env *env)
{
	int		i;
	int		j;
	t_ray	ray;
	t_hit	hit;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			hit.occur = false;
			cast_ray(&ray, i, j, env->scene);
			find_hit(&hit, &ray, env->scene, -1);
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
//uses a viewport at dist 1 from camera, size acc. to FOV
//calculate the vector acc. to camera position and pixel in viewport
//init to filter color (white by def) as the base color of the ray
//return the point of origin
void	cast_ray(t_ray *ray, int i, int j, t_scene *scene)
{
	float	px_space;
	float	half_viewport_w;
	float	half_viewport_h;
	float	v_modul;

	half_viewport_w = tanf(scene->cam->fov / 2.0);
	px_space = 2.0 * half_viewport_w / WINDOW_WIDTH;
	half_viewport_h = WINDOW_HEIGHT * half_viewport_w / WINDOW_WIDTH;
	ray->o = scene->cam->p; //do a hard_copy or like this is ok? (should be ok, because he camera are not supposed to be changed)
	ray->d.x = scene->cam->p.x - half_viewport_w + (j + 0.5) * px_space;
	ray->d.y = scene->cam->p.y + half_viewport_h - (i + 0.5) * px_space;
	ray->d.z = 1.0;
	v_modul = v_modulus(ray->d);
	ray->d.x = ray->d.x / v_modul;
	ray->d.y = ray->d.y / v_modul;
	ray->d.z = ray->d.z / v_modul;
	ray->color = FILTER; //or take it from the scene file if we are introducing a filter??
	// ray->end = false;
}
