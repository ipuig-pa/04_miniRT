/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:44:08 by ewu               #+#    #+#             */
/*   Updated: 2025/03/13 10:20:40 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cam_translate(t_scene *scene, t_camera *cam, t_vector tv)
{
	cam->p = v_add(cam->p, tv);
	scene->vp.o = v_add(scene->vp.o, tv);
}

void	cam_rotate(t_scene *scene, t_camera *cam, float r, t_vector a)
{
	t_matrix4	rot;
	t_vector	cam_to_vp;

	rot = rotate(r, a);
	cam->v = v_transform(cam->v, rot, 'v');
	scene->vp.right = unit_v(v_transform(scene->vp.right, rot, 'v'));
	scene->vp.up = unit_v(v_transform(scene->vp.up, rot, 'v'));
	scene->vp.front = unit_v(v_transform(scene->vp.front, rot, 'v'));
	cam_to_vp = v_subt(scene->vp.o, cam->p);
	cam_to_vp = v_transform(cam_to_vp, rot, 'v');
	scene->vp.o = v_add(cam->p, cam_to_vp);
}

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
			'p');
}
