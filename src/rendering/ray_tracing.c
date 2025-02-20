/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:40:28 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/20 16:18:35 by ipuig-pa         ###   ########.fr       */
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
	t_hit	*hit;

	hit = NULL;
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			cast_ray(&ray, i, j, env->scene);
			find_hit(hit, &ray, env->scene);
			//how to distinguish if it hits the light
			if (hit)
				shading(hit, &ray, env->scene);
			mypixelput(env, j, i, ray->color); //how to handle if it hits nothing, we have to put the background?
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

	half_viewport_w = tan(scene->cam->fov / 2);
	px_space = 2 * half_viewport_w / WINDOW_WIDTH;
	half_viewport_h = WINDOW_HEIGHT * half_viewport_h / WINDOW_WIDTH;
	ray->p = scene->cam->p_cam; //do a hard_copy or like this is ok? (should be ok, because he camera are not supposed to be changed)
	ray->v.x = scene->cam->p_cam.x - half_viewport_w + (j + 0.5) * px_space;
	ray->v.y = scene->cam->p_cam.y + half_viewport_h - (i + 0.5) * px_space;
	ray->v.z = 1;
	ray->color = FILTER; //or take it from the scene file if we are introducing a filter??
	ray->end = false;
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
		calc_intesect(hit, ray, scene, i);
		i++;
	}
}

//cast a ray from the hit point to the light source
//finds if it hits some object
//determine if the hit is before or after the light source
//change the ray color according (in light or shadow)
void	shading(t_hit *hit, t_ray *ray, t_scene *scene)
{
	float		light_dist;
	t_hit		sh_hit;

	ray->p = hit->p; //do a hard_copy or like this is ok?
	ray->v.x = scene->light->p_light.x - hit->p.x;
	ray->v.y = scene->light->p_light.y - hit->p.y;
	ray->v.z = scene->light->p_light.z - hit->p.z;
	light_dist = dist(scene->light->p_light, hit->p);
	//dont know if the initial color of the ray has to be multiplied or added?!?!?
	ray->color = ray->color + scene->obj[hit->obj_id].color * scene->amblight->color * scene->amblight->ratio; //adding ambient light
	sh_hit = NULL;
	find_hit(sh_hit, ray, scene);
	if (!sh_hit || sh_hit->dist > light_dist)//it is directly illuminated by light
		ray->color = ray->color + scene->obj[hit->obj_id].color * scene->light->color * scene->light->ratio * dot_product(ray->v, hit->normal);
}
