/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:48:24 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/26 16:14:06 by ipuig-pa         ###   ########.fr       */
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
	t_point		p; //coordinate of the viewpoint
	t_vector	v;
	float		fov; // field of view, store it already converted to rad
}			t_camera;

typedef struct s_viewport
{
	t_vector	front; //dont know if it is really needed or I can erase
	t_vector	right;
	t_vector	up;
	t_point		o;
	float		px_space;
}				t_viewport;

typedef struct s_light
{
	t_point	p;
	float	ratio;
	t_color	color;
}			t_light;

typedef struct s_sph
{
	t_point	c; //coordinates of the sphere center
	float	r; //sphere diameter (maybe it would be more useful to store the radius r instead of diameter d)
}			t_sph;

typedef struct s_pl
{
	t_point		p; //coordinates of a point in the plane
	t_vector	n; //normal vector (and unit vector!!!???)
}			t_pl;

typedef struct s_cyl
{
	t_point		b; //coordinates of the center of the cylinder ->better find b, which is the center at the base, not in the middle of the cyl
	t_vector	a; //axis vector (unit vector???)
	float		r; //cylinder diameter (maybe it would be more useful to store the radius r instead of diameter d)
	float		h; //cylinder height
}			t_cyl;

typedef struct s_cir
{
	t_point		c; //coordinates of the center of the circle
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

typedef struct s_obj
{
	t_objparam	param;
	t_objtype	type;
	t_color		color;
	t_matrix	m; //transformation matrix to apply to the ray when checking if intersection occurs
}			t_obj;

typedef struct s_scene
{
	t_amblight	*amblight; //erase the * for all of them except *obj???
	t_viewport	vp;
	t_camera	*cam;
	t_light		*light;
	t_obj		*obj;//pointer to an object array?? Or use linked list? In principle, an array (allocate enough space for obj_num)
	int			obj_num;//needed or not depending on if we use array or linked list
}			t_scene;

void	create_viewport(t_scene *scene);

#endif