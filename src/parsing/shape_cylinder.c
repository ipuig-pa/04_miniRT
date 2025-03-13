/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:36:32 by ewu               #+#    #+#             */
/*   Updated: 2025/03/13 11:00:53 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_cylinder(t_obj *obj, char **tokens, int i)
{
	if (check_para_num(tokens, 'y') == -1)
		return (-1);
	if (create_surface(&obj[0], tokens) != -1)
	{
		create_basecir(&obj[0], &obj[1]);
		create_topcir(&obj[0], &obj[2]);
	}
	else
		return (-1);
	return (i + 3);
}

int	create_surface(t_obj *obj, char **tokens)
{
	obj->type = CYL;
	obj->color = parse_color(tokens[5]);
	if (is_err_color(obj->color))
		return (-1);
	obj->param.cyl.c = parse_vector(tokens[1], 'p');
	if (obj->param.cyl.c.w == -1.0f)
		return (-1);
	obj->param.cyl.a = parse_vector(tokens[2], 'v');
	if (check_norm_range(obj->param.cyl.a) == -1)
		return (p_err("Error:\nCylinder orientation vector \
out of range! Should be within [-1,1]. Exit!"), -1);
	obj->param.cyl.a = norm_vector(obj->param.cyl.a);
	if (obj->param.cyl.a.w == -1.0f)
		return (-1);
	obj->param.cyl.r = ft_atofloat(tokens[3]) / 2.0f;
	obj->param.cyl.h = ft_atofloat(tokens[4]);
	if (obj->param.cyl.r < 0.0f || obj->param.cyl.h < 0.0f)
		return (p_err("Error:\nDiameter and Height must be \
positive numbers! Exit!"), -1);
	obj->param.cyl.b = v_subt(obj->param.cyl.c, \
						scalar_mult(obj->param.cyl.a, obj->param.cyl.h / 2));
	parse_material(obj, tokens[6]);
	get_material(obj);
	obj->m = identity();
	return (1);
}

void	create_basecir(t_obj *cyl, t_obj *obj)
{
	obj->type = CIR;
	obj->color = cyl->color;
	obj->param.cir.n = norm_vector(invert_v(cyl->param.cyl.a));
	obj->param.cir.r = cyl->param.cyl.r;
	obj->param.cir.c = cyl->param.cyl.b;
	obj->m = identity();
	obj->mat = cyl->mat;
}

void	create_topcir(t_obj *cyl, t_obj *obj)
{
	obj->type = CIR;
	obj->color = cyl->color;
	obj->param.cir.n = norm_vector(cyl->param.cyl.a);
	obj->param.cir.r = cyl->param.cyl.r;
	obj->param.cir.c = v_add(cyl->param.cyl.b, \
						scalar_mult(cyl->param.cyl.a, cyl->param.cyl.h));
	obj->m = identity();
	obj->mat = cyl->mat;
}
