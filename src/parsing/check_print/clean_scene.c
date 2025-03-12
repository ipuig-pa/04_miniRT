/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:04:39 by ewu               #+#    #+#             */
/*   Updated: 2025/03/12 11:38:28 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//set obj == null to avid dangling ptr, for safety reason
void	clean_scene(t_env *env)
{
	if (!env->scene)
		return ((void)p_err("Error:\nNo proper scene data found!"), gc_clean());
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
