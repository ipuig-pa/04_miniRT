/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:52:45 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/20 18:08:08 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "linalg.h"
# include "stdbool.h"

typedef struct s_ray
{
	t_point		p; //these will keep changing as the ray is reflected, refracted or absorbed
	t_vector	v;
	int			color; //in hex
	// bool		end; //?? neeeded?
}			t_ray;

typedef struct s_hit
{
	t_point		p;
	int			obj_id; //then, they have to be in an array, not a linked list
	float		dist; //distance from the camera to the point of intersection
	bool		occur;
	t_vector	normal;
}			t_hit;

void	ray_tracer(t_env *env);
void	cast_ray(t_ray *ray, int i, int j, t_scene *scene);
void	find_hit(t_hit	*hit, t_ray *ray, t_scene *scene);
void	shading(t_hit *hit, t_ray *ray, t_scene *scene);
void	calc_intersect(t_hit *hit, t_ray *ray, t_scene *scene, int i);
void	update_hit(float d, t_hit *hit, t_ray *ray, t_vector normal, int i);

#endif