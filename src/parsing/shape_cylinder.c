/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:36:32 by ewu               #+#    #+#             */
/*   Updated: 2025/03/06 13:47:56 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// obj[0]=> curved part, obj[1][2]=> 2 circles
void	parse_cylinder(t_obj *obj, char **tokens)
{
	if (check_para_num(tokens, 'y') == -1)
	{
		gc_clean();
		return ;
	}
	create_surface(&obj[0], tokens);
	create_topcir(&obj[1], tokens);
	create_basecir(&obj[2], tokens);
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
static t_vector	pt_sub_vc(t_vector p, t_vector v)
{
	t_vector	base;

	base.x = p.x - v.x;
	base.y = p.y - v.y;
	base.z = p.z - v.z;
	base.w = p.w - v.w;
	return (base);
}

void	create_surface(t_obj *obj, char **tokens)
{
	t_vector	c;

	obj->type = CYL;
	obj->color = parse_color(tokens[5]);
	obj->param.cyl.a = norm_vector(parse_point(tokens[2]));
	obj->param.cyl.r = ft_atofloat(tokens[3]) / 2.0f;
	obj->param.cyl.h = ft_atofloat(tokens[4]);
	c = parse_point(tokens[1]);
	obj->param.cyl.b = pt_sub_vc(c, scalar_mult(obj->param.cyl.a,
				obj->param.cyl.h / 2));
	if (obj->param.cyl.r < 0.0f || obj->param.cyl.h < 0.0f)
	{
		p_err("Diameter and Height must be positive numbers!");
		gc_clean();
		return ;
	}
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
void	create_basecir(t_obj *obj, char **tokens)
{
	t_vector	passed_pt;
	t_vector	tmp_n;

	obj->type = CIR;
	obj->color = parse_color(tokens[5]);
	tmp_n = norm_vector(parse_point(tokens[2]));
	obj->param.cir.n = invert_v(tmp_n);
	obj->param.cir.r = ft_atofloat(tokens[3]) / 2.0f;
	passed_pt = parse_point(tokens[1]);
	obj->param.cir.c = pt_sub_vc(passed_pt, scalar_mult(obj->param.cir.n,
				obj->param.cyl.h / 2));
	if (obj->param.cir.r < 0.0f)
	{
		p_err("Diameter must be positive numbers!");
		gc_clean();
		return ;
	}
}

void	create_topcir(t_obj *obj, char **tokens)
{
	t_vector	passed_pt;

	obj->type = CIR;
	obj->color = parse_color(tokens[5]);
	obj->param.cir.n = norm_vector(parse_point(tokens[2]));
	obj->param.cir.r = ft_atofloat(tokens[3]) / 2.0f;
	passed_pt = parse_point(tokens[1]);
	obj->param.cir.c = v_add(passed_pt, scalar_mult(obj->param.cir.n,
				obj->param.cyl.h / 2));
	if (obj->param.cir.r < 0.0f)
	{
		p_err("Diameter must be positive numbers!");
		gc_clean();
		return ;
	}
}
// include obj circle (cir), and for each cyl, create 2 objects circles:
// ==> create_cir() func
// * one with c = b (center at the base of the cylinder, being the base
// of the cylinder: c - h/2*a),  n = invert_v(cyl->a)
// * other with c = pv_add(c, scalar_mult(cyl->a, cyl->h)), and n = cyl->a