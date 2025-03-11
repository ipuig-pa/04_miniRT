/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:04:19 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/11 10:27:54 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_elem(int key, t_env *env)
{
	if (env->scene->select_obj >= 0)
		move_obj(key, env);
	else if (env->scene->select_light == true)
		move_light(key, env);
	else
		move_cam(key, env);
}

void	rotate_elem(int key, t_env *env)
{
	if (env->scene->select_obj >= 0)
		rotate_obj(key, env);
	else if (env->scene->select_light == true)
		return ;
	else
		rotate_cam(key, env);
}

void	scale_elem(int key, t_env *env)
{
	if (env->scene->select_obj >= 0)
		scale_obj(key, env);
	else if (env->scene->select_light == true)
		scale_light(key, env);
	else
		zoom(key, env);
}
