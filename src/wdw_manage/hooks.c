/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:25:56 by ipuig-pa          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/06 13:59:19 by ewu              ###   ########.fr       */
=======
/*   Updated: 2025/03/07 10:47:15 by ipuig-pa         ###   ########.fr       */
>>>>>>> b2081e0a12fdf63afd37be08a2637436ef53e6f2
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
int	key_action(int keysym, t_env *env)
{
	float	rad;

	rad = 15.0f * (M_PI / 180.0f);
	if (keysym == ESC)
		finish_env(env, 0, "Exit with keyboard ESC!\n");
	else if (keysym == SPACE)
		save_picture();
	else if (keysym == W)
		move_cam(&env->scene->vp, env->scene->vp.front, 0.2f);
	else if (keysym == A)
		move_cam(&env->scene->vp, env->scene->vp.right, -0.2f);
	else if (keysym == S)
		move_cam(&env->scene->vp, env->scene->vp.front, -0.2f);
	else if (keysym == D)
		move_cam(&env->scene->vp, env->scene->vp.right, 0.2f);
	else if (keysym == LEFT)
		rotate_cam(&env->scene->vp, -rad, env->scene->vp.up);
	else if (keysym == RIGHT)
		rotate_cam(&env->scene->vp, rad, env->scene->vp.up);
	else if (keysym == DOWN)
		rotate_cam(&env->scene->vp, -rad, env->scene->vp.right);
	else if (keysym == UP)
		rotate_cam(&env->scene->vp, rad, env->scene->vp.right);
	ray_tracer(env);
	return (0); // check where exactly do I have to retrun and where!?
}

// scroll the wheel to zoom in(UP)/out(DOWN)
// edge case(0 && PI) check; +-3 is randomly set
<<<<<<< HEAD
void	mouse_scroll(int button, float xdelta, float ydelta, t_env *env)
=======
int	mouse_scroll(int button, int x_delta, int y_delta, t_env *env)
>>>>>>> b2081e0a12fdf63afd37be08a2637436ef53e6f2
{
	(void)xdelta;
	(void)ydelta;
	if (button == SCROLL_UP)
	{
		if (env->scene->cam.fov <= 0)
			return (0); // check where exactly do I have to retrun and where!?
		env->scene->cam.fov -= 3;
	}
	else if (button == SCROLL_DOWN)
	{
		if (env->scene->cam.fov >= M_PI)
			return (0); // check where exactly do I have to retrun and where!?
		env->scene->cam.fov += 3;
	}
	ray_tracer(env);
	return (0); // check where exactly do I have to retrun and where!?
}

// should lock cursor at centre or not??
// move the mouse itself to rotate Cam(cursor regarded as the cam)
int	mouse_move(int xdelta, int ydelta, t_env *env)
{
	static int	origin_x = (float)WINDOW_WIDTH / 2;
	static int	origin_y = (float)WINDOW_HEIGHT / 2;

	//TO IMPLEMENT WHAT IS NEEDED!!!
	(void) origin_x;
	(void) origin_y;
	(void) xdelta;
	(void) ydelta;
	(void) env;
	return (0);
}
