/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:40:35 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/06 10:49:24 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
