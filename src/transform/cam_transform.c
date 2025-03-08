/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:44:08 by ewu               #+#    #+#             */
/*   Updated: 2025/03/08 19:01:32 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	vp_rotate(t_env *env, float r, t_vector a)
{
	t_vector	ref;

	ref = env->scene->cam.p;
	env->scene->vp.right = v_transform(env->scene->vp.right, rotate(r, a), 'v');
	env->scene->vp.up = v_transform(env->scene->vp.up, rotate(r, a), 'v');
	env->scene->vp.o = \
		v_transform(\
			env->scene->vp.o, \
			m_multiply(\
				m_multiply(\
					translate(ref), \
					rotate(r, a)), \
				translate(invert_v(ref))), \
			'v');
	loq_rerender(env, false);
}

void	cam_rotate(t_env *env, t_camera *cam, float r, t_vector a)
{
	t_vector	ref;

	ref = cam->p;
	cam->v = \
		v_transform(\
			cam->v, \
			m_multiply(\
				m_multiply(\
					translate(ref), \
					rotate(r, a)), \
				translate(invert_v(ref))), \
			'v');
	loq_rerender(env, true);
}

// float: the sensitivity/speed of move
//change vp.o; vp-.up/right/front UNCHANGED!
void	cam_translate(t_env *env, t_camera *cam, t_vector tv)
{
	cam->p = v_transform(cam->p, translate(tv), 'p');
	loq_rerender(env, true);
}
