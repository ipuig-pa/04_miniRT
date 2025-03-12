/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:37:13 by ewu               #+#    #+#             */
/*   Updated: 2025/03/12 20:33:44 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//pl 0,-10,0 0,1,0 255,255,0 para=4
int	parse_plane(t_obj *obj, char **tokens, int i)
{
	if (check_para_num(tokens, 'p') == -1)
		return (-1);
	obj->type = PL;
	obj->color = parse_color(tokens[3]);
	if (is_err_color(obj->color))
		return (-1);
	obj->param.pl.p = parse_vector(tokens[1], 'p');
	if (obj->param.pl.p.w == -1.0f)
		return (-1);
	obj->param.pl.n = norm_vector(parse_vector(tokens[2], 'v'));
	if (obj->param.pl.n.w == -1.0f)
		return (-1);
	if (check_norm_range(obj->param.pl.n) == -1)
		return (p_err("Error:\nPlane orientation vector \
			out of range! Should be within [-1,1]. Exit!"), -1);
	obj->m = identity();
	parse_material(obj, tokens[4]);
	get_material(obj);
	return (i + 1);
}
