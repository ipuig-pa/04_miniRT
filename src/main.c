/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:30:03 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/20 16:30:31 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		return (1); // and print error wrong number of args
	//check if file (av[1]) can be opened, etc..? (here or inside parsing??)
	parse(&env, av[1]);
	init_env(&env);
	ray_tracer(&env);
	mlx_put_image_to_window(env.mlx, env.mlx_window, env.img.img, 0, 0);
	//hooks (rotation, translation, etc)
	mlx_loop(env.mlx);
	return (0);
}
