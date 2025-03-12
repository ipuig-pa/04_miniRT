/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:48:24 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:58:44 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "maths.h"
# include "color.h"
# include "transform.h"
# include <stdbool.h>

typedef struct s_amblight
{
	float	ratio;
	t_color	color;
}			t_amblight;

typedef struct s_camera
{
	t_vector	p;
	t_vector	v;
	float		fov;
}			t_camera;

typedef struct s_viewport
{
	t_vector	front;
	t_vector	right;
	t_vector	up;
	t_vector	o;
	float		px_space;
}				t_viewport;

typedef struct s_light
{
	t_vector	p;
	float		ratio;
	t_color		color;
	t_color		store_col;
}			t_light;

typedef struct s_sph
{
	t_vector	c;
	float		r;
}			t_sph;

typedef struct s_pl
{
	t_vector	p;
	t_vector	n;
}			t_pl;

typedef struct s_cyl
{
	t_vector	c;
	t_vector	b;
	t_vector	a;
	float		r;
	float		h;
}			t_cyl;

typedef struct s_cir
{
	t_vector	c;
	t_vector	n;
	float		r;
}			t_cir;

typedef enum e_objtype
{
	SPH,
	PL,
	CYL,
	CIR
}			t_objtype;

typedef union u_objparam
{
	t_sph	sph;
	t_pl	pl;
	t_cyl	cyl;
	t_cir	cir;
}			t_objparam;

//matte surface, glossy plastic or shiny metal
typedef enum e_mattype
{
	MATTE,
	PLA,
	MET
}			t_mattype;

//MET: a shiny metal may have high k_s (0.8-1.0) and a high n_s (100-200),
//PLA: a glossy plastic a medium k_s (0.4-0.7) and medium n_s (20-50),
//MATTE: a matte surface might have a low k_s (0.1-0.3) and low n_s (1-10)
typedef struct s_material
{
	t_mattype	type;
	float		k_s;
	float		n_s;
}				t_material;

typedef struct s_obj
{
	t_objparam	param;
	t_objtype	type;
	t_color		color;
	t_material	mat;
	t_matrix4	m;
	t_matrix4	inv_m;
}			t_obj;

typedef struct s_scene
{
	t_amblight	amblight;
	t_camera	cam;
	t_light		light;
	t_viewport	vp;
	int			obj_num;
	t_obj		*obj;
	int			select_obj;
	bool		select_light;
	bool		enclosed_light;
	bool		select_width;
	bool		select_height;
}			t_scene;

void	create_viewport(t_scene *scene);

#endif