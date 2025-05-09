/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linalg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:57:25 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:46:39 by ipuig-pa         ###   ########.fr       */
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
