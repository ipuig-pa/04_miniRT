/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:48:24 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/19 17:15:14 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//For definition of the elements of the scene
#ifndef SCENE_H
# define SCHE_H
# include "linalg.h"

//colors maybe also as an structure of 3 int: R, G, B??

typedef struct s_amblight
{
	float	ratio;
	int		color; //in hex
}			t_amblight;

typedef struct s_camera
{
	t_point		p; //coordinate of the viewpoint
	t_vector	v;
	float		fov; // field of view, in degrees? Or already converted to rad?
}			t_camera;

typedef struct s_light
{
	t_point	p_light;
	float	br_ratio;
	int		color; //in hex
}			t_light;

typedef struct s_sph
{
	t_point	c; //coordinates of the sphere center
	float	d; //sphere diameter
	int		color; //in hex //DELETE IF WE USE THE T_OBJ
}			t_sph;

typedef struct s_pl
{
	t_point		p; //coordinates of a point in the plane
	t_vector	v; //normal vector
	int			color; //in hex //DELETE IF WE USE THE T_OBJ
}			t_pl;

typedef struct s_cyl
{
	t_point		c; //coordinates of the center of the cylinder
	t_vector	axis;
	float		d; //cylinder diameter
	float		h; //cylinder height
	int			color; //in hex //DELETE IF WE USE THE T_OBJ
}			t_cyl;

typedef enum e_objtype
{
	SPH,
	PL,
	CYL
}			t_objtype;

typedef union u_objparam
{
	t_sph	sph; //use it as the direct object or as pointers to?
	t_pl	pl;
	t_cyl	cyl;
}			t_objparam;

typedef struct s_obj
{
	t_objparam	*param;
	t_objtype	type;
	int			color; //in hex
}			t_obj;

typedef struct s_scene
{
	t_amblight	*amblight;
	t_camera	*cam;
	t_light		*light;
	t_obj		*obj;//pointer to an object array?? Or use linked list? In principle, an array (allocate enough space for obj_num)
	int			obj_num;//needed or not depending on if we use array or linked list
}			t_scene;

#endif