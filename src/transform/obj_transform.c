/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:15:19 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 11:37:02 by ipuig-pa         ###   ########.fr       */
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
	t_matrix4	sc_m;

	ref = v_create(0, 0, 0, 0);
	if (obj->type == SPH)
		ref = obj->param.sph.c;
	else if (obj->type == CYL)
		ref = obj->param.cyl.c;
	else if (obj->type == CIR)
		ref = obj->param.cir.c;
	else
		return ;
	ref = v_transform(ref, obj->m, 'v');
	sc_m = scale(sx, sy, sz);
	obj->m = m_multiply(\
				m_multiply(\
					m_multiply(\
						translate(ref), sc_m), \
					translate(invert_v(ref))), \
				obj->m);
	obj->inv_m = m_invert(obj->m);
	if (obj->type == CYL)
		scale_caps(obj, sc_m);
}
