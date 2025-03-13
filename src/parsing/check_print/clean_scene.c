/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:04:39 by ewu               #+#    #+#             */
/*   Updated: 2025/03/13 11:02:23 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_scene(t_env *env)
{
	if (!env->scene)
		return ((void)p_err("Error:\nNo proper scene \
data found to rerender!"), gc_clean());
	if (env->scene->obj)
	{
		gc_free(env->scene->obj);
		env->scene->obj = NULL;
	}
	env->scene->amblight = (t_amblight){0};
	env->scene->cam = (t_camera){0};
	env->scene->light = (t_light){0};
	env->scene->vp = (t_viewport){0};
	env->scene->select_light = false;
	env->scene->select_obj = -1;
	env->scene->obj_num = 0;
}
