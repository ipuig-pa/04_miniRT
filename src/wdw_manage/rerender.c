/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:35:27 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 21:23:32 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	hiq_rerender(t_env *env)
{
	env->scene->select_obj = -1;
	if (env->scene->select_light == true)
	{
		env->scene->select_light = false;
		env->scene->light.color = env->scene->light.store_col;
	}
	env->res.res = 100;
	ray_tracer(env);
	mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
}

void	loq_rerender(t_env *env, bool vp)
{
	if (vp)
		create_viewport(env->scene);
	env->res.res = 10;
	ray_tracer(env);
	mlx_put_image_to_window(env->mlx, env->mlx_window, env->img.img, 0, 0);
}

void	revert_scene(t_env *env)
{
	if (!env->rt_scene_file)
	{
		p_err("Error:\nCannot find rt file, nothing to revert! Exit!");
		return ;
	}
	write(1, "Re-parsing and low quality re-rendering called!\n", 49);
	clean_scene(env);
	if (!parsing_scene(env, env->rt_scene_file))
	{
		p_err("Error:\nFail to Re-load rt file! Exit!");
		return ;
	}
	loq_rerender(env, true);
}
