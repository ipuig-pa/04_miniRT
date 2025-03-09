/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:23:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/09 12:56:25 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	select_light(t_env *env)
{
	if (env->scene->select_light == true)
	{
		env->scene->select_light = false;
		env->scene->light.color = env->scene->light.store_col;
	}
	else
	{
		env->scene->select_light = true;
		env->scene->select_obj = -1;
		env->scene->light.store_col = env->scene->light.color;
		env->scene->light.color = BLUE; //change relative to the current color, and not absolute change
	}
	loq_rerender(env, false);
}

void	move_light(int key, t_env *env)
{
	t_light	*light;

	if (env->scene->select_light == true)
	{
		light = &env->scene->light;
		if (key == W)
			light_translate(light, scalar_mult(env->scene->vp.up, TRANSL));
		else if (key == A)
			light_translate(light, scalar_mult(env->scene->vp.right, -TRANSL));
		else if (key == S)
			light_translate(light, scalar_mult(env->scene->vp.up, -TRANSL));
		else if (key == D)
			light_translate(light, scalar_mult(env->scene->vp.right, TRANSL));
		else if (key == Q)
			light_translate(light, scalar_mult(env->scene->vp.front, TRANSL));
		else if (key == E)
			light_translate(light, scalar_mult(env->scene->vp.front, -TRANSL));
		loq_rerender(env, false);
	}
}

void	scale_light(int key, t_env *env)
{
	t_light	*light;

	if (env->scene->select_light == true)
	{
		light = &env->scene->light;
		if (key == KEY_PLUS || key == SCROLL_UP)
			light_scale(light, ILLUM);
		else if (key == KEY_MINUS || key == SCROLL_DOWN)
			light_scale(light, 1.0 / ILLUM);
		loq_rerender(env, false);
	}
}