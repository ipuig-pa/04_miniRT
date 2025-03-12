/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linalg_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:57:25 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:48:03 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	return (sqrtf(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2)));
}
