/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:15:19 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/26 17:16:42 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	m_transform(t_ray r, t_matrix m)
{
	t_ray	res_r;

	res_r.o.x = m.m[0][0] * r.o.x + m.m[0][1] * r.o.y + m.m[0][2] * r.o.z + m.m[0][3] * r.o.w;
	res_r.o.y = m.m[1][0] * r.o.x + m.m[1][1] * r.o.y + m.m[1][2] * r.o.z + m.m[1][3] * r.o.w;
	res_r.o.z = m.m[2][0] * r.o.x + m.m[2][1] * r.o.y + m.m[2][2] * r.o.z + m.m[2][3] * r.o.w;
	res_r.o.w = m.m[3][0] * r.o.x + m.m[3][1] * r.o.y + m.m[3][2] * r.o.z + m.m[3][3] * r.o.w;
	res_r.d.x = m.m[0][0] * r.d.x + m.m[0][1] * r.d.y + m.m[0][2] * r.d.z + m.m[0][3] * r.d.w;
	res_r.d.y = m.m[1][0] * r.d.x + m.m[1][1] * r.d.y + m.m[1][2] * r.d.z + m.m[1][3] * r.d.w;
	res_r.d.z = m.m[2][0] * r.d.x + m.m[2][1] * r.d.y + m.m[2][2] * r.d.z + m.m[2][3] * r.d.w;
	res_r.d.w = m.m[3][0] * r.o.x + m.m[3][1] * r.o.y + m.m[3][2] * r.o.z + m.m[3][3] * r.o.w;
	res_r.color = r.color;
	return (res_r);
}

t_matrix	rotate(float r, t_vector a) //rotate r rad (angle) about an axis defined by the vector a (should be the vectors of up, front and right of viewport!!!)
{
	t_matrix	m;

	m.m[0][0] = a.x * a.x * (1 - cosf(r)) + cosf(r);
	m.m[0][1] = a.y * a.x * (1 - cosf(r)) - a.z * sinf(r);
	m.m[0][2] = a.z * a.x * (1 - cosf(r)) + a.y * sinf(r);
	m.m[0][3] = 0;
	m.m[1][0] = a.x * a.y * (1 - cosf(r)) + a.z * sinf(r);
	m.m[1][1] = a.y * a.y * (1 - cosf(r)) + cosf(r);
	m.m[1][2] = a.z * a.y * (1 - cosf(r)) - a.x * sinf(r);
	m.m[1][3] = 0;
	m.m[2][0] = a.x * a.z * (1 - cosf(r)) - a.y * sinf(r);
	m.m[2][1] = a.y * a.z * (1 - cosf(r)) + a.x * sinf(r);
	m.m[2][2] = a.z * a.z * (1 - cosf(r)) + cosf(r);
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	m.exist = true;
	return (m);
}

t_matrix	translate(t_vector t)
{
	t_matrix	m;

	m.m[0][0] = 1;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[0][3] = t.x;
	m.m[1][0] = 0;
	m.m[1][1] = 1;
	m.m[1][2] = 0;
	m.m[1][3] = t.y;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = 1;
	m.m[2][3] = t.z;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	m.exist = true;
	return (m);
}

t_matrix	scale(float s)
{
	t_matrix	m;

	m.m[0][0] = s;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[0][3] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = s;
	m.m[1][2] = 0;
	m.m[1][3] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = s;
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	m.exist = true;
	return (m);
}
