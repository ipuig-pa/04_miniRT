/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:28:16 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 12:28:51 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	select_param(int key, t_env *env)
{
	if (env->scene->select_obj != -1 && \
		env->scene->obj[env->scene->select_obj].type == CYL)
	{
		if (key == WIDTH)
		{
			if (!env->scene->select_width)
			{
				env->scene->select_width = true;
				env->scene->select_height = false;
			}
			else
				env->scene->select_width = false;
		}
		if (key == HEIGHT)
		{
			if (!env->scene->select_height)
			{
				env->scene->select_height = true;
				env->scene->select_width = false;
			}
			else
				env->scene->select_height = false;
		}
	}
	loq_rerender(env, false);
}

void	scale_cyl(int key, t_env *env)
{
	t_obj	*obj;

	if (env->scene->select_obj != -1)
	{
		obj = &env->scene->obj[env->scene->select_obj];
		if (obj->type == CYL && env->scene->select_height)
		{
			if (key == KEY_PLUS)
				cyl_h_scale(obj, SCALE);
			else if (key == KEY_MINUS)
				cyl_h_scale(obj, 1.0 / SCALE);
		}
		else if (obj->type == CYL && env->scene->select_width)
		{
			if (key == KEY_PLUS)
				cyl_w_scale(obj, SCALE);
			else if (key == KEY_MINUS)
				cyl_w_scale(obj, 1.0 / SCALE);
		}
	}
}