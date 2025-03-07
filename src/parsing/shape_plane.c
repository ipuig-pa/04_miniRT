/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:37:13 by ewu               #+#    #+#             */
/*   Updated: 2025/03/07 14:46:42 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * typedef struct s_pl
{
	t_point		p; //coordinates of a point in the plane
	t_vector	n; //normal vector
}			t_pl;
pl 0,-10,0 0,1,0 255,255,0 para=4
 */
void	parse_plane(t_obj *obj, char **tokens)
{
	if (check_para_num(tokens, 'p') == -1)
		return (gc_clean());
	obj->type = PL;
	obj->color = parse_color(tokens[3]);
	obj->param.pl.p = parse_vector(tokens[1], 'p');
	obj->param.pl.n = norm_vector(parse_vector(tokens[2], 'v'));
	obj->m = identity();
	obj->mat.type = 0;
	get_material(obj);
}
