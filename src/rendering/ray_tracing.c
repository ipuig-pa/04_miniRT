/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:40:28 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/20 18:25:45 by ipuig-pa         ###   ########.fr       */
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
			find_hit(&hit, &ray, env->scene);
			//how to distinguish if it hits the light
			if (hit.occur == true)
				shading(&hit, &ray, env->scene);
			my_pixel_put(env, j, i, ray.color); //how to handle if it hits nothing, we have to put the background?
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

	half_viewport_w = tanf(scene->cam->fov / 2.0);
	px_space = 2.0 * half_viewport_w / WINDOW_WIDTH;
	half_viewport_h = WINDOW_HEIGHT * half_viewport_w / WINDOW_WIDTH;
	ray->p = scene->cam->p; //do a hard_copy or like this is ok? (should be ok, because he camera are not supposed to be changed)
	ray->v.x = scene->cam->p.x - half_viewport_w + (j + 0.5) * px_space;
	ray->v.y = scene->cam->p.y + half_viewport_h - (i + 0.5) * px_space;
	ray->v.z = 1.0;
	ray->color = FILTER; //or take it from the scene file if we are introducing a filter??
	// ray->end = false;
}

//return the point of the first intersect of the ray
//recalculates ray direction (p and v) according to material properties
void	find_hit(t_hit	*hit, t_ray *ray, t_scene *scene) //allocate the hit if needed
{
	int		i;

	i = 0;
	//allocate for a maximum of 2 times for each object?
	//what about planes exactly coincident with the ray? (line contained in a plane)
	while (i < scene->obj_num)//optimize somehow to not iterate through ALL the objects
	{
		calc_intersect(hit, ray, scene, i);
		i++;
	}
}

//cast a ray from the hit point to the light source
//finds if it hits some object
//determine if the hit is before or after the light source
//change the ray color according (in light or shadow)
void	shading(t_hit *hit, t_ray *ray, t_scene *scene)
{
	float	light_dist;
	t_hit	*sh_hit;

	ray->p = hit->p; //do a hard_copy or like this is ok?
	ray->v.x = scene->light->p.x - hit->p.x;
	ray->v.y = scene->light->p.y - hit->p.y;
	ray->v.z = scene->light->p.z - hit->p.z;
	light_dist = dist(&scene->light->p, &hit->p);
	//dont know if the initial color of the ray has to be multiplied or added?!?!?
	ray->color = ray->color + scene->obj[hit->obj_id].color * scene->amblight->color * scene->amblight->ratio; //adding ambient light
	sh_hit = NULL;
	find_hit(sh_hit, ray, scene);
	if (!sh_hit || sh_hit->dist > light_dist)//it is directly illuminated by light
		ray->color = ray->color + scene->obj[hit->obj_id].color * scene->light->color * scene->light->ratio * dot_product(&ray->v, &hit->normal);
}
