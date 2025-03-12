/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:23:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:27:35 by ipuig-pa         ###   ########.fr       */
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
		if (!is_white(env->scene->light.color))
			env->scene->light.color = complementary(env->scene->light.color);
		else
			env->scene->light.color = set_color(0, 0, 1, 0);
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
			light_scale(&light->ratio, ILLUM);
		else if (key == KEY_MINUS || key == SCROLL_DOWN)
			light_scale(&light->ratio, 1.0 / ILLUM);
		loq_rerender(env, false);
	}
}

void	scale_amblight(int key, t_env *env)
{
	t_amblight	*light;

	light = &env->scene->amblight;
	if (key == KEY_PLUS)
		light_scale(&light->ratio, ILLUM);
	else if (key == KEY_MINUS)
		light_scale(&light->ratio, 1.0 / ILLUM);
	loq_rerender(env, false);
}
