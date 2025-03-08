/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:08:15 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 15:56:33 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//⬆️⬇️ => pitch; ⬅️➡️ => yaw(rotate along vp.up axis)
//vector axis: the vectors of up, front and right of viewport
//rotate(): create 4x4 matrix based on GIVEN rad and axis
//change vp.up/right/front; vp.o UNCHANGED!
void	move_cam(t_env *env, t_scene *scene, int key)
{
	if (key == W)
		cam_translate(env, &scene->cam, scalar_mult(scene->vp.up, TRANSL));
	else if (key == A)
		cam_translate(env, &scene->cam, scalar_mult(scene->vp.right, -TRANSL));
	else if (key == S)
		cam_translate(env, &scene->cam, scalar_mult(scene->vp.up, -TRANSL));
	else if (key == D)
		cam_translate(env, &scene->cam, scalar_mult(scene->vp.right, TRANSL));
	else if (key == Q)
		cam_translate(env, &scene->cam, scalar_mult(scene->vp.front, TRANSL));
	else if (key == E)
		cam_translate(env, &scene->cam, scalar_mult(scene->vp.front, -TRANSL));
}

void	rotate_cam(t_env *env, int key)
{
	float	rad;

	rad = to_rad(ROT);
	if (key == LEFT)
		cam_rotate(env, &env->scene->cam, rad, env->scene->vp.up);
	else if (key == RIGHT)
		cam_rotate(env, &env->scene->cam, -rad, env->scene->vp.up);
	else if (key == DOWN)
		cam_rotate(env, &env->scene->cam, -rad, env->scene->vp.right);
	else if (key == UP)
		cam_rotate(env, &env->scene->cam, rad, env->scene->vp.right);
	else if (key == S_LEFT)
		vp_rotate(env, -rad, env->scene->vp.front);
	else if (key == S_RIGHT)
		vp_rotate(env, rad, env->scene->vp.front);
}
