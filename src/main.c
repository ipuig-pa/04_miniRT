/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:30:03 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/07 12:46:47 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		return (1); // and print error wrong number of args
	//check if file (av[1]) can be opened, etc..? (done inside parsing)
	memset(&env, 0, sizeof(t_env));
	if (!parsing_scene(&env, av[1]))
		return (1);
	printf("check1\n");
	init_env(&env);
	printf("check2\n");
	ray_tracer(&env);
	printf("check3\n");
	mlx_put_image_to_window(env.mlx, env.mlx_window, env.img.img, 0, 0);
	// set_hooks(env); //hooks (rotation, translation, etc)
	mlx_loop(env.mlx);
	return (0);
}
