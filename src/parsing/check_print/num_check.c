/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:42:11 by ewu               #+#    #+#             */
/*   Updated: 2025/03/13 11:02:15 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
			return (p_err("Error:\nInvalid number of Ambient light!"), -1);
		return (0);
	}
	else if (key == 'c')
	{
		if (!tokens[1] || !tokens[2] || !tokens[3] || para_nbr(tokens) != 4)
			return (p_err("Error:\nInvalid number of Camera parameter!"), -1);
		return (0);
	}
	else if (key == 'l')
	{
		if (!tokens[1] || !tokens[2] || !tokens[3] || para_nbr(tokens) != 4)
			return (p_err("Error:\nInvalid number of Light parameter!"), -1);
		return (0);
	}
	else
		return (check_para_2(tokens, key));
}

int	check_para_2(char **tokens, char key)
{
	if (key == 's')
	{
		if (!tokens[1] || !tokens[2] || !tokens[3] || para_nbr(tokens) > 5)
			return (p_err("Error:\nInvalid Sphere parameter! Must be: \
sp Coodinate Diameter Color"), -1);
		return (0);
	}
	else if (key == 'p')
	{
		if (!tokens[1] || !tokens[2] || !tokens[3] || para_nbr(tokens) > 5)
			return (p_err("Error:\nInvalid Plane parameter! Must be: \
pl Coordinate Vector_Orientation Color"), -1);
		return (0);
	}
	else if (key == 'y')
	{
		if (!tokens[1] || !tokens[2] || !tokens[3] || !tokens[4] || !tokens[5] \
			|| para_nbr(tokens) > 7)
			return (p_err("Error:\nInvalid Cylinder parameter! Must be: \
cy Coodinate Vector_Orientation Diameter Height Color"), -1);
		return (0);
	}
	else
		return (p_err("Error:\nInvalid key passed for \
parameter number check!"), -1);
}
