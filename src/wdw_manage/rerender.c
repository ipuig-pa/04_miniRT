/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:35:27 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 14:42:54 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	hiq_rerender(t_env *env)
{
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
