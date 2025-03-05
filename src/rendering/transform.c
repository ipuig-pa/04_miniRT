/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:15:19 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/05 17:38:03 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	r_transform(t_ray r, t_matrix4 m)
{
	t_ray	res_r;

	res_r.o = p_transform(r.o, m);
	res_r.d = v_transform(r.d, m);
	res_r.color = r.color;
	return (res_r);
}

t_vector	p_transform(t_vector p, t_matrix4 m)
{
	t_vector	res_p;

	res_p.x = m.m[0][0] * p.x + m.m[0][1] * p.y \
			+ m.m[0][2] * p.z + m.m[0][3] * p.w;
	res_p.y = m.m[1][0] * p.x + m.m[1][1] * p.y \
			+ m.m[1][2] * p.z + m.m[1][3] * p.w;
	res_p.z = m.m[2][0] * p.x + m.m[2][1] * p.y \
			+ m.m[2][2] * p.z + m.m[2][3] * p.w;
	res_p.w = 1;
	return (res_p);
}

t_vector	v_transform(t_vector v, t_matrix4 m)
{
	t_vector	res_v;

	res_v.x = m.m[0][0] * v.x + m.m[0][1] * v.y \
			+ m.m[0][2] * v.z + m.m[0][3] * v.w;
	res_v.y = m.m[1][0] * v.x + m.m[1][1] * v.y \
			+ m.m[1][2] * v.z + m.m[1][3] * v.w;
	res_v.z = m.m[2][0] * v.x + m.m[2][1] * v.y \
			+ m.m[2][2] * v.z + m.m[2][3] * v.w;
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
	return (m);
}

void	o_translate(t_obj *obj, t_vector t)
{
	obj->m = m_multiply(translate(t), obj->m);
	obj->m.exist = true;
}

void	o_rotate(t_obj *obj, float r, t_vector a)
{
	t_vector	ref;

	ref = v_create(0, 0, 0, 0);
	if (obj->type == SPH)
		ref = obj->param.sph.c;
	else if (obj->type == PL)
		ref = obj->param.pl.p;
	else if (obj->type == CYL)
	{
		ref = obj->param.cyl.c;
		obj[1].m = m_multiply(m_multiply(m_multiply(translate(ref),rotate(r,a)),translate(invert_v(ref))), obj->m);
		obj[1].m.exist = true;
		obj[2].m = m_multiply(m_multiply(m_multiply(translate(ref),rotate(r,a)),translate(invert_v(ref))), obj->m);
		obj[2].m.exist = true;
	}
	else if (obj->type == CIR)
		ref = obj->param.cir.c;
	obj->m = m_multiply(m_multiply(m_multiply(translate(ref),rotate(r,a)),translate(invert_v(ref))), obj->m);
	obj->m.exist = true;
}

void	o_scale(t_obj *obj, float sx, float sy, float sz)
{
	t_vector	ref;
	t_vector	s;
	t_vector	h;

	ref = v_create(0, 0, 0, 0);
	if (obj->type == SPH)
		ref = obj->param.sph.c;
	else if (obj->type == PL)
		ref = obj->param.pl.p;
	else if (obj->type == CYL)
	{
		ref = obj->param.cyl.c;
		s = v_create(sx, sy, sz, 1);
		h = scalar_mult(obj->param.cyl.a, obj->param.cyl.h / 2);
		obj[1].m = m_multiply(m_multiply(m_multiply(\
					translate(v_subt(obj->param.cyl.c, element_mult(h, s))), \
					scale(sx, sy, sz)), \
					translate(invert_v(obj[1].param.cir.c))), \
					obj->m);
		obj[1].m.exist = true;
		obj[2].m = m_multiply(m_multiply(m_multiply(\
			translate(v_add(obj->param.cyl.c, element_mult(h, s))), \
			scale(sx, sy, sz)), \
			translate(invert_v(obj[2].param.cir.c))), \
			obj->m);
		obj[2].m.exist = true;
	}
	else if (obj->type == CIR)
		ref = obj->param.cir.c;
	obj->m = m_multiply(m_multiply(m_multiply(translate(ref),scale(sx, sy, sz)),translate(invert_v(ref))), obj->m);
	obj->m.exist = true;
}
