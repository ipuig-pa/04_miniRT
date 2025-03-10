/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:15:19 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/10 15:22:02 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	r_transform(t_ray r, t_matrix4 m)
{
	t_ray	res_r;

	res_r.o = v_transform(r.o, m, 'p');
	res_r.d = v_transform(r.d, m, 'v');
	res_r.color = r.color;
	return (res_r);
}

t_vector	v_transform(t_vector v, t_matrix4 m, char key)
{
	t_vector	res_v;

	res_v.x = m.m[0][0] * v.x + m.m[0][1] * v.y \
			+ m.m[0][2] * v.z + m.m[0][3] * v.w;
	res_v.y = m.m[1][0] * v.x + m.m[1][1] * v.y \
			+ m.m[1][2] * v.z + m.m[1][3] * v.w;
	res_v.z = m.m[2][0] * v.x + m.m[2][1] * v.y \
			+ m.m[2][2] * v.z + m.m[2][3] * v.w;
	if (key == 'p')
		res_v.w = 1;
	else if (key == 'v')
		res_v.w = 0;
	return (res_v);
}

t_matrix4	translate(t_vector t)
{
	t_matrix4	m;

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

//to rotate uisng a specific point as pivot, combine to the origin of coordinates, with translation back and forth.
t_matrix4	rotate(float r, t_vector a) //rotate r rad (angle) about an axis defined by the vector a (should be the vectors of up, front and right of viewport!!!)
{
	t_matrix4	m;

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
	// if (obj->m.exist == false)
	// 	obj.m = m;
	// else
	// 	obj.m = m_multiply(obj.m * m); // in case we pass as parameter the object we want to modify (if this is not used for camera rotations, etc??? Then camera rotations should be handled differently, directly affecting the vector? or applying the same matrix to all the obejcts in a while loop???)
	return (m);
}

//combine to translation to the origin of coordinates and back to original position.
t_matrix4	scale(float sx, float sy, float sz)
{
	t_matrix4	m;

	m.m[0][0] = sx;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[0][3] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = sy;
	m.m[1][2] = 0;
	m.m[1][3] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = sz;
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	m.exist = true;
	return (m);
}
