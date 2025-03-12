/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:26:09 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 21:08:15 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_env(t_env *env)
{
	env->mlx = mlx_init();
	if (!env->mlx)
		finish_env(env, 1, "Error:\nEnvironment can not be initalized");
	env->mlx_window = mlx_new_window(env->mlx, WDW_WIDTH, WDW_HEIGHT, "Scene");
	if (!env->mlx_window)
		finish_env(env, 1, "Error:\nEnvironment can not be initalized");
	env->img.img = mlx_new_image(env->mlx, WDW_WIDTH, WDW_HEIGHT);
	if (!env->img.img)
		finish_env(env, 1, "Error:\nEnvironment can not be initalized");
	env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bits_per_pixel, \
					&env->img.line_length, &env->img.endian);
	if (!env->img.addr)
		finish_env(env, 1, "Error:\nEnvironment can not be initalized");
	env->res.res = 100;
}

void	finish_env(t_env *env, int return_val, char *str)
{
	p_err(str);
	if (env)
	{
		if (env->img.img)
			mlx_destroy_image(env->mlx, env->img.img);
		if (env->mlx_window)
			mlx_destroy_window(env->mlx, env->mlx_window);
		if (env->mlx)
			free(env->mlx);
	}
	gc_clean();
	exit (return_val);
}
