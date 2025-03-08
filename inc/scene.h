/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:48:24 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 13:19:59 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//For definition of the elements of the scene
#ifndef SCENE_H
# define SCENE_H

# include "linalg.h"
# include "color.h"
# include "transform.h"

//colors maybe also as an structure of 3 int: R, G, B??

typedef struct s_amblight
{
	float	ratio;
	t_color	color;
}			t_amblight;

typedef struct s_camera
{
	t_vector	p; //coordinate of the viewpoint
	t_vector	v;
	float		fov; // field of view, store it already converted to rad
}			t_camera;

typedef struct s_viewport
{
	t_vector	front; //dont know if it is really needed or I can erase
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
}			t_light;

typedef struct s_sph
{
	t_vector	c; //coordinates of the sphere center
	float		r; //sphere diameter (maybe it would be more useful to store the radius r instead of diameter d)
}			t_sph;

typedef struct s_pl
{
	t_vector	p; //coordinates of a point in the plane
	t_vector	n; //normal vector (and unit vector!!!???)
}			t_pl;

typedef struct s_cyl
{
	t_vector	c; //coordinates of the center of the cylinder
	t_vector	b; //coordinates of the center at the base, not in the middle of the cyl as c
	t_vector	a; //axis vector (unit vector???)
	float		r; //cylinder diameter (maybe it would be more useful to store the radius r instead of diameter d)
	float		h; //cylinder height
}			t_cyl;

typedef struct s_cir
{
	t_vector	c; //coordinates of the center of the circle
	t_vector	n; //normal vector (unit vector???)
	float		r; //circle radius
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
	t_sph	sph; //use it as the direct object or as pointers to?
	t_pl	pl;
	t_cyl	cyl;
	t_cir	cir;
}			t_objparam;

typedef enum e_mattype
{
	MATTE, //matte surface
	PLA, //glossy plastic
	MET //shiny metal
}			t_mattype;

//A shiny metal might have a high k_s (0.8-1.0) and a high n_s (100-200), a glossy plastic might have a medium k_s (0.4-0.7) and medium n_s (20-50), a matte surface might have a low k_s (0.1-0.3) and low n_s (1-10)
typedef struct s_material
{
	t_mattype	type;
	float		k_s;
	float		n_s; //This controls the size and concentration of the specular highlight. It's typically a positive value, often between 1 and 1000. It determines how "focused" or "sharp" the highlight appears. Higher values create smaller, more focused highlights (like polished metal). Lower values create broader highlights (like matte plastic)
}				t_material;

typedef struct s_obj
{
	t_objparam	param;
	t_objtype	type;
	t_color		color;
	t_material	mat;
	t_matrix4	m; //transformation matrix to apply to the ray when checking if intersection occur
	t_matrix4	inv_m; //transformation matrix to apply to the ray when checking if intersection occur
}			t_obj;

typedef struct s_scene
{
	t_amblight	amblight;
	t_camera	cam;
	t_light		light;
	t_viewport	vp;
	t_obj		*obj;
	int			select_obj;
	int			obj_num;
}			t_scene;
// t_amblight	*amblight; //erase the * for all of them except *obj???
// t_camera	*cam;
// t_light		*light;

void	create_viewport(t_scene *scene);

#endif