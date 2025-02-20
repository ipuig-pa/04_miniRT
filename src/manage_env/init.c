/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:26:09 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/20 17:10:53 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_env(t_env *env)
{
	env->mlx = mlx_init();
	if (!env->mlx)
		finish_env(env, 1, "Environment can not be initalized");
	env->mlx_window = mlx_new_window(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Scene");//change title to the filename
	if (!env->mlx_window)
		finish_env(env, 1, "Environment can not be initalized");
	env->img.img = mlx_new_image(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!env->img.img)
		finish_env(env, 1, "Environment can not be initalized");
	env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bits_per_pixel, \
					&env->img.line_length, &env->img.endian);
	if (!env->img.addr)
		finish_env(env, 1, "Environment can not be initalized");
	//paint_background(env, BLACK);
}

//Check that everything is what is meant to be
//Add "mlx_destroy_display(env->mlx);" before freeing in Linux environments
void	finish_env(t_env *env, int return_val, char *str)
{
	printf("%s\n", str);//use perror or sterror???
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
