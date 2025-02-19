/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:40:28 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/19 17:45:45 by ipuig-pa         ###   ########.fr       */
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
	t_point	*p;

	p = NULL;
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			p = cast_ray(&ray, i, j, env->scene);
			while (p && ray->end == false)
				p = find_hit(&ray, env->scene);
			if (ray->end == true)
				ray.color = ray.color * scene->light->color * scene->light->br_ratio;//*ratio???? what does ratio mean in each case?
			else
				ray.color = ray.color * scene->amblight->color * scene->amblight->ratio; //*ratio???? what does ratio mean in each case?
			mypixelput(env, j, i, ray->color);
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
t_point	*cast_ray(t_ray *ray, int i, int j, t_scene *scene)
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
	return (ray->p);
}

//return the point of the first intersect of the ray
//recalculates ray direction (p and v) according to material properties
t_point	*find_hit(t_ray *ray, t_scene scene)
{
	int		i;
	t_hit	*hit;

	i = 0;
	hit = NULL;
	//allocate for a maximum of 2 times for each object?
	//what about planes exactly coincident with the ray? (line contained in a plane)
	while (i < scene->obj_num)//optimize somehow to not iterate through ALL the objects
	{
		calc_intesect(hit, ray, scene, i);
		i++;
	}
	recalc_ray???
	return (hit);
}
