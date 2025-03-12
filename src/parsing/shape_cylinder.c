/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:36:32 by ewu               #+#    #+#             */
/*   Updated: 2025/03/12 10:38:42 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// obj[0]=> curved part, obj[1][2]=> 2 circles
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
		return (p_err("Error:\nFail to create cylinder! Exit!"), -1);
	return (i + 3);
}

/**
 * typedef struct s_cyl
{
	t_point		b; 
	t_vector	a;
	float		r;
	float		h; //cylinder height
}				t_cyl;
 * cy (b: 50,0,20) (a: 0,1,0) (d: 14.2) (h: 21.42) 10,0,255; para = 6
 */

//returns a point (w == 1)
// static t_vector	pt_sub_vc(t_vector p, t_vector v)
// {
// 	t_vector	base;

// 	base.x = p.x - v.x;
// 	base.y = p.y - v.y;
// 	base.z = p.z - v.z;
// 	base.w = p.w - v.w;
// 	return (base);
// }

int	create_surface(t_obj *obj, char **tokens)
{
	obj->type = CYL;
	obj->color = parse_color(tokens[5]);
	if (is_err_color(obj->color))
		return (-1);
	obj->param.cyl.c = parse_vector(tokens[1], 'p');
	if (obj->param.cyl.c.w == -1.0f)
		return (-1);
	obj->param.cyl.a = norm_vector(parse_vector(tokens[2], 'v'));
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

/**
typedef struct s_cir
{
	t_point		c; //coordinates of the center of the circle
	t_vector	n; //normal vector (unit vector???)
	float		r; //circle radius
}				t_cir;
 */

// passed_pt is a POINT, w==1


//the first is subtracting axis * h/2 and the second is adding axis * h/2 to the center of the cyl

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
// include obj circle (cir), and for each cyl, create 2 objects circles:
// ==> create_cir() func
// * one with c = b (center at the base of the cylinder, being the base
// of the cylinder: c - h/2*a),  n = invert_v(cyl->a)
// * other with c = pv_add(c, scalar_mult(cyl->a, cyl->h)), and n = cyl->a