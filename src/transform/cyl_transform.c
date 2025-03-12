/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:15:59 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:36:13 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	scale_caps(t_obj *obj, t_matrix4 sc_m)
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
							translate(ref_back), sc_m), \
						translate(invert_v(ref))), \
					obj[i].m);
		obj[i].inv_m = m_invert(obj[i].m);
		i++;
	}
}

void	cyl_h_scale(t_obj *obj, float s)
{
	t_vector	reloc;

	reloc = scalar_mult(obj->param.cyl.a, ((1 - s) * obj->param.cyl.h) / 2);
	obj->param.cyl.h = s * obj->param.cyl.h;
	obj->param.cyl.b = v_add(obj->param.cyl.b, reloc);
	obj[1].param.cir.c = v_add(obj[1].param.cir.c, reloc);
	obj[2].param.cir.c = v_subt(obj[2].param.cir.c, reloc);
}

void	cyl_w_scale(t_obj *obj, float s)
{
	obj->param.cyl.r = s * obj->param.cyl.r;
	obj[1].param.cir.r = obj->param.cyl.r;
	obj[2].param.cir.r = obj->param.cyl.r;
}
