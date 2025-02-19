/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:30:03 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/19 10:38:22 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	main(int ac, char **av)
{
	t_scene	*scene;

	if (ac != 2)
		return (1); // and print error wrong number of args
	//check if file can be opened, etc..? (here or inside parsing??)
	//parse(scene, av[1]);
	//init_minilibx
	render(scene, mlx);
	return (0);
}
