/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linalg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:57:25 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/25 18:05:52 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	dot_prod(t_vector v1, t_vector v2)
{
	float	res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}

t_vector	cross_prod(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.y * v2.z - v1.z * v2.y;
	res.y = v1.z * v2.x - v1.x * v2.z;
	res.z = v1.x * v2.y - v1.y * v2.x;
	return (res);
}

t_vector	scalar_mult(t_vector v, float s)
{
	t_vector	res;

	res.x = v.x * s;
	res.y = v.y * s;
	res.z = v.z * s;
	return (res);
}

float	dist(t_point p1, t_point p2)
{
	return (sqrtf(powf((p1.x - p2.x), 2) + powf((p1.y - p2.y), 2) + powf((p1.z - p2.z), 2)));
}

t_vector	invert_v(t_vector v)
{
	t_vector	inv_v;

	inv_v.x = -v.x;
	inv_v.y = -v.y;
	inv_v.z = -v.z;
	return (inv_v);
}

float	v_modulus(t_vector v)
{
	return(sqrtf(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2)));
}

t_vector	point_subt(t_point p2, t_point p1)
{
	t_vector	v;

	v.x = p2.x - p1.x;
	v.y = p2.y - p1.y;
	v.z = p2.z - p1.z;
	return (v);
}

t_point	pv_add(t_point p, t_vector v)
{
	t_point	res;

	res.x = p.x + v.x;
	res.y = p.y + v.y;
	res.z = p.z + v.z;
	return (res);
}

t_vector v_subt(t_vector v2, t_vector v1)
{
	t_vector	res;

	res.x = v2.x - v1.x;
	res.y = v2.y - v1.y;
	res.z = v2.z - v1.z;
	return (res);
}

t_vector v_add(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vector	unit_v(t_vector v)
{
	float		mod;
	t_vector	u_v;

	mod = v_modulus(v);
	u_v.x = v.x / mod;
	u_v.y = v.y / mod;
	u_v.z = v.z / mod;
	return (u_v);
}
