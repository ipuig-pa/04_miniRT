/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:37:41 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/11 11:50:28 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include <stdbool.h>
# include "ray.h"
# include "linalg.h"

# define TRANSL 1.0f
# define ROT 5.0f
# define ZOOM 15.0f
# define SCALE 1.2f
# define ILLUM 1.1f

//forward declarations
struct	s_scene;
struct	s_obj;
struct	s_camera;
struct	s_light;
struct	s_viewport;

typedef struct s_matrix4
{
	float	m[4][4];
	bool	exist;
}			t_matrix4; //or no need to be a struct, just typedef float [4][4]???

typedef struct s_matrix3
{
	float	m[3][3];
}			t_matrix3;

//transforms
t_ray		r_transform(t_ray r, t_matrix4 m);
t_vector	v_transform(t_vector v, t_matrix4 m, char key);
t_matrix4	translate(t_vector t);
t_matrix4	rotate(float r, t_vector a);
t_matrix4	scale(float sx, float sy, float sz);

//obj transforms
void		o_rotate(struct s_obj *obj, float r, t_vector a);
void		o_translate(struct s_obj *obj, t_vector t);
void		o_scale(struct s_obj *obj, float sx, float sy, float sz);
void		transform_caps(struct s_obj *obj, t_matrix4 m);
void		scale_caps(struct s_obj *obj, t_vector s);

//cam transforms
void		cam_translate(t_scene *scene, struct s_camera *cam, t_vector tv);
void		cam_rotate(t_scene *scene, struct s_camera *cam, float r, t_vector a);
void		vp_rotate(t_scene *scene, float r, t_vector a);
// void		viewport_transform(struct s_viewport *vp, t_matrix4 m);

//light transforms
void		light_translate(struct s_light *light, t_vector tv);
void		light_scale(float *ratio, float factor);

//matrix_utils
t_matrix4	identity(void);
t_matrix4	m_multiply(t_matrix4 m1, t_matrix4 m2);
t_matrix4	sm_divide(t_matrix4 m, float s);
t_matrix4	transpose(t_matrix4 m);
t_matrix3	c_minor(t_matrix4 m4, int r, int c);
t_matrix4	adj(t_matrix4 m);
float		det4(t_matrix4 m);
float		det3(t_matrix3 m);
t_matrix4	m_invert(t_matrix4 m);

#endif 