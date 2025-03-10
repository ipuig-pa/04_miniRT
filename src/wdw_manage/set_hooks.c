/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:25:56 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/10 15:36:37 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// call AFTER ini_env()
// mlx_hook format: mlx_hook(wdw, event, mask, function, param);
// 2rd para: X11 event code for hook activity, 3rd: X11 mask for specific event
void	set_hooks(t_env *env)
{
	mlx_hook(env->mlx_window, 2, 1L << 0, key_action, env);
	mlx_hook(env->mlx_window, 4, 1L << 2, mouse_button, env);
	mlx_hook(env->mlx_window, 17, 0, close_window, env);
	// mlx_hook(env->mlx_window, 6, 1L << 6, mouse_move, env);
}

int	close_window(t_env *env)
{
	finish_env(env, 0, "Exit with mouse click!");
	return (0);
}

/**
 * WASD =>Front-Left-Bck-Left
 * Yaw (left/right) → Rotate around up axis.
 * Pitch (up/down) → Rotate around right axis
 */
int	key_action(int key, t_env *env)
{
	if (key == ESC)
		finish_env(env, 0, "Exit with keyboard ESC!");
	else if (key == SPACE)
		hiq_rerender(env);
	else if (key == L)
		select_light(env);
	else if (key == W || key == A || key == S || key == D || key == Q
		|| key == E)
		move_elem(key, env);
	else if (key == LEFT || key == RIGHT || key == DOWN || key == UP
		|| key == S_LEFT || key == S_RIGHT)
		rotate_elem(key, env);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		scale_elem(key, env);
	else if (key == KEY_REVERT)
		revert_scene(env);
	return (0); // check where exactly do I have to retrun and where!?
}

int	mouse_button(int button, int x, int y, t_env *env)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		scale_elem(button, env);
	else if (button == CLICK_SELECT && y >= 0)
		select_obj(x, y, env);
	return (0);
}

/*
void	mouse_click(int x, int y, t_env *env)
{
	t_ray	ray;
	t_hit	hit;

	cast_ray(&ray, y, x, env->scene);
	find_hit(&hit, ray, env->scene, -1);
	if (hit.occur == true)
	{
		if (env->scene->obj[hit.obj_id].type == CIR)
		{
			while (env->scene->obj[hit.obj_id].type != CYL)
				hit.obj_id--;
		}
		if (env->scene->select_obj == hit.obj_id)
			env->scene->select_obj = -1;
		else
		{
			env->scene->select_obj = hit.obj_id;
			env->scene->select_light = false;
		}
		loq_rerender(env, false);
	}
	else
		env->scene->select_obj = -1;
}*/

/*
void	mouse_scroll(int button, t_env *env)
{
	float	rad;

	rad = to_rad(ZOOM);
	if (button == SCROLL_UP)
	{
		if ((env->scene->cam.fov - rad) <= 0)
			return ;
		env->scene->cam.fov -= rad;
	}
	else if (button == SCROLL_DOWN)
	{
		if ((env->scene->cam.fov + rad) >= M_PI)
			return ;
		env->scene->cam.fov += rad;
	}
	loq_rerender(env, true);
}*/

/*
int	mouse_move(int x, int y, t_env *env)
{
	static int	prev_x = WINDOW_WIDTH / 2;
	static int	prev_y = WINDOW_HEIGHT / 2;
	float		dx;
	float		dy;

	if (env->scene->select_obj >= 0)
	{
		dx = x - prev_x;
		dy = y - prev_y;
		prev_x = x;
		prev_y = y;
		rotate_obj(&env->scene->obj[env->scene->select_obj], dx, dy,
			env->scene->vp);
		loq_rerender(env, false);
	}
	return (0);//else doing, just return
}*/

/*
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
		rotate_cam(key, env);
	else if (key == OBJ_B || key == OBJ_D || key == OBJ_F || key == OBJ_L \
			|| key == OBJ_R || key == OBJ_UP)
		move_obj(key, env);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		scale_obj(key, env);
	return (0); // check where exactly do I have to retrun and where!?
}*/