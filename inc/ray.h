/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:52:45 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/20 15:44:57 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "linalg.h"

typedef struct s_ray
{
	t_point		p; //these will keep changing as the ray is reflected, refracted or absorbed
	t_vector	v;
	int			color; //in hex
	bool		end; //?? neeeded?
}			t_ray;

typedef struct s_hit
{
	t_point		p;
	int			obj_id; //then, they have to be in an array, not a linked list
	float		dist; //distance from the camera to the point of intersection
	t_vector	normal;
}			t_hit;

#endif