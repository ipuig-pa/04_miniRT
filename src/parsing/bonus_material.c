/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:52:27 by ewu               #+#    #+#             */
/*   Updated: 2025/03/10 12:57:58 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// init k_s/n_s data
// 0=>matte; 1=>plastic; 2=>metalic
void	parse_material(t_obj *obj, char *token)
{
	int	_mat;

	if (!token)
	{
		p_err("Lack of identifier for material, default Matte called!");
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
	{
		p_err("Invalid identifier for material, default Matte called!");
		obj->mat.type = MATTE;
	}
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

/**
 typedef struct s_material
 {
	t_mattype		type;
	float			k_s;
	float			n_s;
}					t_material;
MAT: low k_s (0.1-0.3) and low n_s (1-10)
PLA: a medium k_s (0.4-0.7) and medium n_s (20-50)
MET: high k_s (0.8-1.0) and a high n_s (100-200)
*/
// static t_material	parse_matte(void)
// {
// 	t_material	matte;

// 	matte.type = MATTE;
// 	matte.k_s = 0.2f;
// 	matte.k_s = 5.0f;
// 	return (matte);
// }

// // or type = 0/1/2?
// static t_material	parse_pla(void)
// {
// 	t_material	pla;

// 	pla.type = PLA;
// 	pla.k_s = 0.55f;
// 	pla.n_s = 35.5f;
// 	return (pla);
// }

// static t_material	parse_met(void)
// {
// 	t_material	met;

// 	met.type = MET;
// 	met.k_s = 0.9f;
// 	met.n_s = 155.0f;
// }
