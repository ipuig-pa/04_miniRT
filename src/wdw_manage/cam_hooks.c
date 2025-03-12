/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:08:15 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:28:52 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_cam(int key, t_env *env)
{
	t_camera	*cam;

	cam = &env->scene->cam;
	if (key == W)
		cam_translate(env->scene, cam, \
			scalar_mult(env->scene->vp.up, TRANSL));
	else if (key == A)
		cam_translate(env->scene, cam, \
			scalar_mult(env->scene->vp.right, -TRANSL));
	else if (key == S)
		cam_translate(env->scene, cam, \
			scalar_mult(env->scene->vp.up, -TRANSL));
	else if (key == D)
		cam_translate(env->scene, cam, \
			scalar_mult(env->scene->vp.right, TRANSL));
	else if (key == Q)
		cam_translate(env->scene, cam, \
			scalar_mult(env->scene->vp.front, TRANSL));
	else if (key == E)
		cam_translate(env->scene, cam, \
			scalar_mult(env->scene->vp.front, -TRANSL));
	loq_rerender(env, false);
}

void	rotate_cam(int key, t_env *env)
{
	float	rad;

	rad = to_rad(ROT);
	if (key == LEFT)
		cam_rotate(env->scene, &env->scene->cam, rad, env->scene->vp.up);
	else if (key == RIGHT)
		cam_rotate(env->scene, &env->scene->cam, -rad, env->scene->vp.up);
	else if (key == DOWN)
		cam_rotate(env->scene, &env->scene->cam, -rad, env->scene->vp.right);
	else if (key == UP)
		cam_rotate(env->scene, &env->scene->cam, rad, env->scene->vp.right);
	else if (key == S_LEFT)
		vp_rotate(env->scene, rad, env->scene->vp.front);
	else if (key == S_RIGHT)
		vp_rotate(env->scene, -rad, env->scene->vp.front);
	loq_rerender(env, false);
}

void	zoom(int key, t_env *env)
{
	float	rad;

	rad = to_rad(ZOOM);
	if (key == SCROLL_UP)
	{
		if ((env->scene->cam.fov - rad) <= 0)
			return ;
		env->scene->cam.fov -= rad;
	}
	else if (key == SCROLL_DOWN)
	{
		if ((env->scene->cam.fov + rad) >= M_PI)
			return ;
		env->scene->cam.fov += rad;
	}
	loq_rerender(env, true);
}
