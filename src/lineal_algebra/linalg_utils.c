/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linalg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:17:08 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/20 15:53:05 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linalg.h"

float	dot_product(t_vector *v1, t_vector *v2)
{
	float	res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}

float	scalar_mult(t_vector *v, int s)
{
	float	res;

	res = v.x * s + v.y * s + v.z * s;
	return (res);
}

float	dist(t_point p1, t_point p2)
{
	return (sqrtf(powf((p1.x - p2.x),2) + powf((p1.y - p2.y),2) + powf((p1.z - p2.z),2)));
}

t_vector	invert_v(t_vector v)
{
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
}
