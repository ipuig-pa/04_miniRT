/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_transforms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:15:19 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 10:20:22 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	o_translate(t_obj *obj, t_vector t)
{
	obj->m = m_multiply(translate(t), obj->m);
	obj->inv_m = m_invert(obj->m);
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
	obj->inv_m = m_invert(obj->m);
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
	obj->inv_m = m_invert(obj->m);
	obj->m.exist = true;
}
