/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:40:28 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/19 15:32:09 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
//anything related with the tracing of the rays and render of the image

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
			p = cast_ray(&ray, env->scene);
			while (p == scene->light->p || p > scene_bounds (no p, as the equation will not have any solution)) //how to make point comparisons!?!? Can we overload operators in C? Create function to compare points??
			//we can include a bool in ray to see if it has reached its end (light source) and check if ray->end == true || !p (as a pointer))
				p = intersect(&ray, scene);
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
//calculate the vector according to camera point and the pixel point in viewport
//init to white as the base color of the ray
//return the point of origin
t_point	*cast_ray(t_ray *ray, t_scene scene)
{
	ray->p = //convert screen coord to world coord
	ray->v = //get vector according to camera point and p in real world coord
	ray->color = FILTER;
	ray->end = false;
	return (ray->p);
}

//return the point of the first intersect of the ray
//recalculates ray direction (p and v) according to material properties
t_point	*intersect(t_ray *ray, t_scene scene)
{
	//how to find the first intersection? Iterate through all objects???? somehow order the objects in a linked list according to their distance of the nearest point to the camera point???
	if (no sol)
		return (NULL)
}

//TO DO:
//objects as a linked list according to their proximity to camera?? OR not, beause when it hits one, we have to change again the order? OR subdivide the space?
//render parts 
//understand matrices