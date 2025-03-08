/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:20:44 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 15:57:21 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * WASD =>Front-Left-Bck-Left
 * Yaw (left/right) → Rotate around up axis.
 * Pitch (up/down) → Rotate around right axis
 */
int	key_action(int key, t_env *env)
{
	if (key == ESC)
		finish_env(env, 0, "Exit with keyboard ESC!\n");
	else if (key == SPACE)
		hiq_rerender(env);
	else if (key == W || key == A || key == S || key == D \
			|| key == Q || key == E)
		move_cam(env, env->scene, key);
	else if (key == LEFT || key == RIGHT || key == DOWN || key == UP \
			|| key == S_LEFT || key == S_RIGHT)
		rotate_cam(env, key);
	else if (key == OBJ_B || key == OBJ_D || key == OBJ_F || key == OBJ_L \
			|| key == OBJ_R || key == OBJ_UP)
		move_obj(env, key);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		scale_obj(env, key);
	return (0); // check where exactly do I have to retrun and where!?
}
