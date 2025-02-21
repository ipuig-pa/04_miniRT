/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linalg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:57:25 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/21 12:09:24 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	dot_product(const t_vector *v1, const t_vector *v2)
{
	float	res;

	res = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	return (res);
}

float	scalar_mult(const t_vector *v, int s)
{
	float	res;

	res = v->x * s + v->y * s + v->z * s;
	return (res);
}

float	dist(const t_point *p1, const t_point *p2)
{
	return (sqrtf(powf((p1->x - p2->x), 2) + powf((p1->y - p2->y), 2) + powf((p1->z - p2->z), 2)));
}

t_vector	invert_v(t_vector *v)
{
	t_vector	inv_v;

	inv_v.x = -v->x;
	inv_v.y = -v->y;
	inv_v.z = -v->z;
	return (inv_v);
}

float	v_modulus(const t_vector *v)
{
	return(sqrtf(powf(v->x, 2) + powf(v->y, 2) + powf(v->z, 2)));
}
