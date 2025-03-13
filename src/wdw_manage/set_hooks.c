/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:25:56 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/13 11:04:55 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_hooks(t_env *env)
{
	mlx_hook(env->mlx_window, 2, 1L << 0, key_action, env);
	mlx_hook(env->mlx_window, 4, 1L << 2, mouse_button, env);
	mlx_hook(env->mlx_window, 17, 0, close_window, env);
}

int	close_window(t_env *env)
{
	finish_env(env, 0, RE"Exit with mouse click!");
	return (0);
}

int	key_action(int key, t_env *env)
{
	if (key == ESC)
		return (finish_env(env, 0, RE"Exit with keyboard ESC!"), 0);
	else if (key == SPACE)
		hiq_rerender(env);
	else if (key == L)
		select_light(env);
	else if (key == WIDTH || key == HEIGHT)
		select_param(key, env);
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
	return (0);
}

int	mouse_button(int button, int x, int y, t_env *env)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		scale_elem(button, env);
	else if (button == CLICK_SELECT && y >= 0)
		select_obj(x, y, env);
	return (0);
}
