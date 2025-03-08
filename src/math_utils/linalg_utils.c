/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linalg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:57:25 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 12:33:31 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	v_create(float x, float y, float z, float w)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}

t_vector	v_add(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	res.w = v1.w + v2.w;
	return (res);
}

t_vector	v_subt(t_vector v2, t_vector v1)
{
	t_vector	res;

	res.x = v2.x - v1.x;
	res.y = v2.y - v1.y;
	res.z = v2.z - v1.z;
	res.w = v2.w - v1.w;
	return (res);
}

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
	res.w = 0;
	return (res);
}

t_vector	scalar_mult(t_vector v, float s)
{
	t_vector	res;

	res.x = v.x * s;
	res.y = v.y * s;
	res.z = v.z * s;
	res.w = 0;
	return (res);
}

t_vector	element_mult(t_vector v, t_vector s)
{
	t_vector	res;

	res.x = v.x * s.x;
	res.y = v.y * s.y;
	res.z = v.z * s.z;
	res.w = 0;
	return (res);
}

t_vector	scalar_div(t_vector v, float s)
{
	t_vector	res;

	res.x = v.x / s;
	res.y = v.y / s;
	res.z = v.z / s;
	res.w = 0;
	return (res);
}

t_vector	invert_v(t_vector v)
{
	t_vector	inv_v;

	inv_v.x = -v.x;
	inv_v.y = -v.y;
	inv_v.z = -v.z;
	inv_v.w = 0;
	return (inv_v);
}

float	v_modulus(t_vector v)
{
	return(sqrtf(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2)));
}

t_vector	unit_v(t_vector v)
{
	float		mod;
	t_vector	u_v;

	mod = v_modulus(v);
	u_v.x = v.x / mod;
	u_v.y = v.y / mod;
	u_v.z = v.z / mod;
	u_v.w = 0;
	return (u_v);
}

t_vector	v_reflect(t_vector in, t_vector n)
{
	n = unit_v(n);
	in = unit_v(in);
	return (v_subt(in, scalar_mult(n, 2 * dot_prod(in, n))));
}
