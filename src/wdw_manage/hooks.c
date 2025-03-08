/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:25:56 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 12:34:32 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	rerender(t_env *env)
{
	create_viewport(env->scene);
	ray_tracer(env);
	mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
}

// call AFTER ini_env()
// mlx_hook format: mlx_hook(wdw, event, mask, function, param);
// 2rd para: X11 event code for hook activity, 3rd: X11 mask for specific event
void	set_hooks(t_env *env)
{
	mlx_hook(env->mlx_window, 2, 1L << 0, key_action, env);
	mlx_hook(env->mlx_window, 4, 1L << 2, mouse_scroll, env);
	mlx_hook(env->mlx_window, 6, 1L << 6, mouse_move, env);
}

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
		save_picture();
	else if (key == W || key == A || key == S || key == D)
		move_cam(env, key);
	else if (key == LEFT || key == RIGHT || key == DOWN || key == UP)
		rotate_cam(env, key);
	rerender(env);
	return (0); // check where exactly do I have to retrun and where!?
}

// scroll the wheel to zoom in(UP)/out(DOWN)
// edge case(0 && PI) check; +-3 is randomly set
//if its edge case, return(0) and nothing will be implemented
int	mouse_scroll(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (button == SCROLL_UP)
	{
		if (env->scene->cam.fov <= 0)
			return (0);
		env->scene->cam.fov -= 3;
	}
	else if (button == SCROLL_DOWN)
	{
		if (env->scene->cam.fov >= M_PI)
			return (0);
		env->scene->cam.fov += 3;
	}
	rerender(env); // think if there is a more efficient way different than rerender!?
	return (0);
}
