/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:52:45 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:58:57 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "maths.h"
# include "color.h"
# include "scene.h"
# include <stdbool.h>

//forward declaration
struct	s_scene;

typedef struct s_ray
{
	t_vector	o;
	t_vector	d;
	t_color		color;
}			t_ray;

typedef struct s_hit
{
	t_vector	p;
	t_vector	real_p;
	int			obj_id;
	float		dist;
	float		light_dist;
	bool		occur;
	t_vector	normal;
}			t_hit;

void	ray_tracer(t_env *env);
void	cast_ray(t_ray *ray, int i, int j, struct s_scene *scene);
void	find_hit(t_hit	*hit, t_ray ray, struct s_scene *scene, int h);
void	shading(t_hit *hit, t_ray *ray, struct s_scene *scene);
void	phong(t_hit *hit, t_ray *ray, struct s_scene *scene, float cos);
void	calc_intersect(t_ray ray, t_hit *hit, struct s_scene *scene, int i);
void	update_hit(float t, t_hit *hit, t_ray ray, int i);
void	find_normal(t_hit *hit, struct s_scene *scene);
void	handle_resolution(t_env	*env);
void	check_enclosed_light(struct s_scene *scene);

#endif