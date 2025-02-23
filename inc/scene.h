/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:48:24 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/23 15:11:21 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//For definition of the elements of the scene
#ifndef SCENE_H
# define SCENE_H

# include "linalg.h"
# include "color.h"

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

typedef struct s_light
{
	t_point	p;
	float	ratio;
	t_color	color;
}			t_light;

typedef struct s_sph
{
	t_point	c; //coordinates of the sphere center
	float	d; //sphere diameter (maybe it would be more useful to store the radius r instead of diameter d)
}			t_sph;

typedef struct s_pl
{
	t_point		p; //coordinates of a point in the plane
	t_vector	v; //normal vector
}			t_pl;

typedef struct s_cyl
{
	t_point		c; //coordinates of the center of the cylinder
	t_vector	v;
	float		d; //cylinder diameter (maybe it would be more useful to store the radius r instead of diameter d)
	float		h; //cylinder height
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
	t_objparam	param;
	t_objtype	type;
	t_color		color;
}			t_obj;

//PTR to mlx42 added(comment out now, just for you to see hpw it like)
typedef struct s_scene
{
	// mlx_t		*mlx;
	// mlx_image_t	*scene_img;
	// char		*obj_name;
	t_amblight	*amblight;
	t_camera	*cam;
	t_light		*light;
	t_obj		*obj;//pointer to an object array?? Or use linked list? In principle, an array (allocate enough space for obj_num)
	int			obj_num;//needed or not depending on if we use array or linked list
}			t_scene;

#endif