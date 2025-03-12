/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:52:27 by ewu               #+#    #+#             */
/*   Updated: 2025/03/12 20:50:01 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_material(t_obj *obj, char *token)
{
	int	_mat;

	if (!token)
	{
		obj->mat.type = MATTE;
		return ;
	}
	_mat = ft_atoi(token);
	if (_mat == 0 || _mat == 1 || _mat == 2)
	{
		if (_mat == 0)
			obj->mat.type = MATTE;
		else if (_mat == 1)
			obj->mat.type = PLA;
		else if (_mat == 2)
			obj->mat.type = MET;
	}
	else
		obj->mat.type = MATTE;
}

void	get_material(t_obj	*obj)
{
	if (obj->mat.type == MET)
	{
		obj->mat.k_s = 0.9;
		obj->mat.n_s = 200;
	}
	else if (obj->mat.type == PLA)
	{
		obj->mat.k_s = 0.5;
		obj->mat.n_s = 40;
	}
	else if (obj->mat.type == MATTE)
	{
		obj->mat.k_s = 0.1;
		obj->mat.n_s = 1;
	}
}
