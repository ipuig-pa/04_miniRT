/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:25:56 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 13:05:34 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	hiq_rerender(t_env *env)
{
	env->res.res = 100;
	ray_tracer(env);
	mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
}

static void	loq_rerender(t_env *env)
{
	create_viewport(env->scene);
	env->res.res = 10;
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
		return (hiq_rerender(env), 0);
	else if (key == W || key == A || key == S || key == D \
			|| key == Q || key == E)
		move_cam(env->scene, key);
	else if (key == LEFT || key == RIGHT || key == DOWN || key == UP)
		rotate_cam(env->scene, key);
	else
		return (0);
	loq_rerender(env);
	return (0); // check where exactly do I have to retrun and where!?
}

// scroll the wheel to zoom in(UP)/out(DOWN)
// edge case(0 && PI) check; +-3 is randomly set
//if its edge case, return(0) and nothing will be implemented
int	mouse_scroll(int button, int xdelta, int ydelta, t_env *env)
{
	float	rad;

	(void)xdelta;
	(void)ydelta;
	rad = to_rad(ZOOM);
	if (button == SCROLL_UP)
	{
		if ((env->scene->cam.fov - rad) <= 0)
			return (0);
		env->scene->cam.fov -= rad;
	}
	else if (button == SCROLL_DOWN)
	{
		if ((env->scene->cam.fov + rad) >= M_PI)
			return (0);
		env->scene->cam.fov += rad;
	}
	else
		return (0);
	loq_rerender(env);
	return (0);
}

//MOUSE MOVE AND MOUSE CLICK + KEYS + / - and something else for rotation of objects!?!?

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
