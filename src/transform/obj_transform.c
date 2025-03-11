/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:15:19 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/11 12:07:19 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	o_translate(t_obj *obj, t_vector t)
{
	t_matrix4	t_m;

	t_m = translate(t);
	obj->m = m_multiply(t_m, obj->m);
	obj->inv_m = m_invert(obj->m);
	if (obj->type == CYL)
		transform_caps(obj, t_m);
}

void	o_rotate(t_obj *obj, float r, t_vector a)
{
	t_vector	ref;
	t_matrix4	rot_m;

	ref = v_create(0, 0, 0, 0);
	if (obj->type == SPH)
		ref = obj->param.sph.c;
	else if (obj->type == PL)
		ref = obj->param.pl.p;
	else if (obj->type == CYL)
		ref = obj->param.cyl.c;
	else if (obj->type == CIR)
		ref = obj->param.cir.c;
	ref = v_transform(ref, obj->m, 'v');
	rot_m = m_multiply(\
				m_multiply(\
					translate(ref), rotate(r, a)), \
				translate(invert_v(ref)));
	obj->m = m_multiply(rot_m, obj->m);
	obj->inv_m = m_invert(obj->m);
	if (obj->type == CYL)
		transform_caps(obj, rot_m);
}

void	o_scale(t_obj *obj, float sx, float sy, float sz)
{
	t_vector	ref;
	t_vector	s;
	t_matrix4	sc_m;

	ref = v_create(0, 0, 0, 0);
	if (obj->type == SPH)
		ref = obj->param.sph.c;
	else if (obj->type == PL)
		ref = obj->param.pl.p;
	else if (obj->type == CYL)
		ref = obj->param.cyl.c;
	else if (obj->type == CIR)
		ref = obj->param.cir.c;
	ref = v_transform(ref, obj->m, 'v');
	sc_m = m_multiply(\
			m_multiply(\
				translate(ref), scale(sx, sy, sz)), \
			translate(invert_v(ref)));
	obj->m = m_multiply(sc_m, obj->m);
	obj->inv_m = m_invert(obj->m);
	if (obj->type == CYL)
	{
		s = v_create(sx, sy, sz, 1);
		scale_caps(obj, s);
	}
}

void	transform_caps(t_obj *obj, t_matrix4 m)
{
	int	i;

	i = 1;
	while (i <= 2)
	{
		obj[i].m = m_multiply(m, obj[i].m);
		obj[i].inv_m = m_invert(obj[i].m);
		i++;
	}
}

void	scale_caps(t_obj *obj, t_vector s)
{
	t_vector	ref;
	t_vector	ref_back;
	int			i;

	i = 1;
	while (i <= 2)
	{
		ref = obj[i].param.cir.c;
		ref = v_transform(ref, obj[i].m, 'v');
		if (i == 1)
			ref_back = obj->param.cyl.b;
		else
			ref_back = v_add(obj->param.cyl.b, \
							scalar_mult(obj->param.cyl.a, obj->param.cyl.h));
		ref_back = v_transform(ref_back, obj->m, 'v');
		obj[i].m = m_multiply(\
					m_multiply(\
						m_multiply(\
							translate(ref_back), \
							scale(s.x, s.y, s.z)), \
						translate(invert_v(ref))), \
					obj[i].m);
		obj[i].inv_m = m_invert(obj[i].m);
		i++;
	}
}
