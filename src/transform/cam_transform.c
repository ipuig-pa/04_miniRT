/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:44:08 by ewu               #+#    #+#             */
/*   Updated: 2025/03/09 12:29:57 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	vp_rotate(t_scene *scene, float r, t_vector a)
{
	t_vector	ref;

	ref = scene->cam.p;
	scene->vp.right = v_transform(scene->vp.right, rotate(r, a), 'v');
	scene->vp.up = v_transform(scene->vp.up, rotate(r, a), 'v');
	scene->vp.o = \
		v_transform(\
			scene->vp.o, \
			m_multiply(\
				m_multiply(\
					translate(ref), \
					rotate(r, a)), \
				translate(invert_v(ref))), \
			'v');
}

void	cam_rotate(t_camera *cam, float r, t_vector a)
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
}

// float: the sensitivity/speed of move
//change vp.o; vp-.up/right/front UNCHANGED!
void	cam_translate(t_camera *cam, t_vector tv)
{
	cam->p = v_transform(cam->p, translate(tv), 'p');
}
