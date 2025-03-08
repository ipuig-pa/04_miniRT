/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:25:56 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 11:01:22 by ipuig-pa         ###   ########.fr       */
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
int	key_action(int keysym, t_env *env)
{
	float	rad;

	rad = ROT * (M_PI / 180.0f);
	if (keysym == ESC)
		finish_env(env, 0, "Exit with keyboard ESC!\n");
	else if (keysym == SPACE)
		save_picture();
	else if (keysym == W)
		cam_translate(&env->scene->cam, scalar_mult(env->scene->vp.up, TRANSL));
	else if (keysym == A)
		cam_translate(&env->scene->cam, scalar_mult(env->scene->vp.right, -TRANSL));
	else if (keysym == S)
		cam_translate(&env->scene->cam, scalar_mult(env->scene->vp.up, -TRANSL));
	else if (keysym == D)
		cam_translate(&env->scene->cam, scalar_mult(env->scene->vp.right, TRANSL));
	else if (keysym == LEFT)
		cam_rotate(&env->scene->cam, rad, env->scene->vp.up);
	else if (keysym == RIGHT)
		cam_rotate(&env->scene->cam, -rad, env->scene->vp.up);
	else if (keysym == DOWN)
		cam_rotate(&env->scene->cam, -rad, env->scene->vp.right);
	else if (keysym == UP)
		cam_rotate(&env->scene->cam, rad, env->scene->vp.right);
	rerender(env);
	return (0); // check where exactly do I have to retrun and where!?
}

// scroll the wheel to zoom in(UP)/out(DOWN)
// edge case(0 && PI) check; +-3 is randomly set
//if its edge case, return(0) and nothing will be implemented
int	mouse_scroll(int button, int xdelta, int ydelta, t_env *env)
{
	(void)xdelta;
	(void)ydelta;
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
	ray_tracer(env);
	return (0);
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
