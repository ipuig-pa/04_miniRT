/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:52:45 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/11 17:44:17 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "linalg.h"
# include "color.h"
# include <stdbool.h>

typedef struct s_ray
{
	t_vector	o; //origin point. these will keep changing as the ray is reflected, refracted or absorbed
	t_vector	d; //direction (unitary vector)
	t_color		color; //in hex
	// bool		end; //?? neeeded?
}			t_ray;

typedef struct s_hit
{
	t_vector	p;
	t_vector	real_p;
	int			obj_id; //then, they have to be in an array, not a linked list
	float		dist; //distance from the camera to the point of intersection
	float		light_dist; //distance from the hit point to the light
	bool		occur;
	t_vector	normal;
}			t_hit;

void	ray_tracer(t_env *env);
void	cast_ray(t_ray *ray, int i, int j, t_scene *scene);
void	find_hit(t_hit	*hit, t_ray ray, t_scene *scene, int h);
void	shading(t_hit *hit, t_ray *ray, t_scene *scene);
void	phong(t_hit *hit, t_ray *ray, t_scene *scene, float cos);
void	calc_intersect(t_ray ray, t_hit *hit, t_scene *scene, int i);
void	update_hit(float t, t_hit *hit, t_ray ray, int i);
void	find_normal(t_hit *hit, t_scene *scene);
void	handle_resolution(t_env	*env);
void	check_enclosed_light(t_scene *scene);

#endif