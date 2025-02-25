/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:40:28 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/25 19:16:24 by ipuig-pa         ###   ########.fr       */
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

	create_viewport(env->scene); //maybe call it after parsing and not here?
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
//uses a vp at dist 1 from camera, size acc. to FOV
//calculate the vector acc. to camera position and pixel in vp
//init to filter color (white by def) as the base color of the ray
//return the point of origin
void	cast_ray(t_ray *ray, int i, int j, t_scene *scene)
{
	t_point	vp_px;

	ray->o = scene->cam->p;
	vp_px = pv_add(scene->vp.o, scalar_mult(scene->vp.right, (j + 0.5) * scene->vp.px_space));
	vp_px = pv_add(vp_px, scalar_mult(scene->vp.up, -(i + 0.5) * scene->vp.px_space));
	ray->d.x = vp_px.x - scene->cam->p.x;
	ray->d.y = vp_px.y - scene->cam->p.y;
	ray->d.z = vp_px.z - scene->cam->p.z;
	ray->d = unit_v(ray->d);
	ray->color = FILTER; //or take it from the scene file if we are introducing a filter??
	// ray->end = false;
}

void	create_viewport(t_scene *scene)
{
	t_vector	world_vert;
	float		half_vp_w;
	float		half_vp_h;

	world_vert.x = 0;
	world_vert.y = 1;
	world_vert.z = 0;
	scene->vp.right = unit_v(cross_prod(scene->cam->v, world_vert));
	scene->vp.up = unit_v(cross_prod(scene->vp.right, scene->cam->v));
	printf("right.x: %f, .y: %f, .z: %f\nup.x: %f, .y: %f, .z: %f\n", scene->vp.right.x, scene->vp.right.y, scene->vp.right.z, scene->vp.up.x, scene->vp.up.y, scene->vp.up.z);
	scene->vp.front = scene->cam->v;
	half_vp_w = tanf(scene->cam->fov / 2.0);
	half_vp_h = WINDOW_HEIGHT * half_vp_w / WINDOW_WIDTH;
	printf("%f, %f\n", half_vp_w, half_vp_h);
	scene->vp.px_space = 2.0 * half_vp_w / WINDOW_WIDTH;
	scene->vp.o = pv_add(scene->cam->p, scene->vp.front);
	printf("o.x: %f, .y: %f, .z: %f\n", scene->vp.o.x, scene->vp.o.y, scene->vp.o.z);
	scene->vp.o = pv_add(scene->vp.o, scalar_mult(scene->vp.right, -half_vp_w));
	printf("o.x: %f, .y: %f, .z: %f\n", scene->vp.o.x, scene->vp.o.y, scene->vp.o.z);
	scene->vp.o = pv_add(scene->vp.o, scalar_mult(scene->vp.up, half_vp_h));
	printf("o.x: %f, .y: %f, .z: %f\n", scene->vp.o.x, scene->vp.o.y, scene->vp.o.z);
}
