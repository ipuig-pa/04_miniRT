/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:42:11 by ewu               #+#    #+#             */
/*   Updated: 2025/03/07 11:36:53 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * to check valid number of parameter for each parser
 * a, l, c, sp, pl, y
 * */

int	para_nbr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	check_para_num(char **tokens, char key)
{
	if (key == 'a')
	{
		if (!tokens[1] || !tokens[2] || para_nbr(tokens) != 3)
			return (p_err("Invalid number of Ambient light!"), -1);
		return (0);
	}
	else if (key == 'c')
	{
		if (!tokens[1] || !tokens[2] || !tokens[3] || para_nbr(tokens) != 4)
			return (p_err("Invalid number of Camera parameter!"), -1);
		return (0);
	}
	else if (key == 'l')
	{
		if (!tokens[1] || !tokens[2] || !tokens[3] || para_nbr(tokens) != 4)
			return (p_err("Invalid number of Light parameter!"), -1);
		return (0);
	}
	else
		return (check_para_2(tokens, key));
}

//include here option for material!?! (so || (para_nbr != 4 && para_nbr != 5))

//sp 0,0,0 20 255,0,0; p=4
//pl 0,-10,0 0,1,0 255,255,0; p=4
//cy 50,0,20 0,1,0 14.2 21.42 10,0,255; para = 6
int	check_para_2(char **tokens, char key)
{
	if (key == 's')
	{
		if (!tokens[1] || !tokens[2] || !tokens[3] || para_nbr(tokens) != 4)
			return (p_err("Invalid number for Sphere object!"), -1);
		return (0);
	}
	else if (key == 'p')
	{
		if (!tokens[1] || !tokens[2] || !tokens[3] || para_nbr(tokens) != 4)
			return (p_err("Invalid number for Plane object!"), -1);
		return (0);
	}
	else if (key == 'y')
	{
		if (!tokens[1] || !tokens[2] || !tokens[3] || !tokens[4] || !tokens[5] \
			|| para_nbr(tokens) != 6)
			return (p_err("Invalid number for Cylinder object!"), -1);
		return (0);
	}
	else
		return (p_err("Invalid key passed for parameter number check!"), -1);
}
