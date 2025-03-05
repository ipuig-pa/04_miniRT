/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:37:41 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/05 14:29:09 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include <stdbool.h>
# include "ray.h"

typedef struct s_matrix4
{
	float	m[4][4];
	bool	exist;
}			t_matrix4; //or no need to be a struct, just typedef float [4][4]???

typedef struct s_matrix3
{
	float	m[3][3];
}			t_matrix3;

t_ray		r_transform(t_ray r, t_matrix4 m);
t_vector	v_transform(t_vector v, t_matrix4 m);
t_vector	p_transform(t_vector p, t_matrix4 m);
t_matrix4	rotate(float r, t_vector a);
t_matrix4	translate(t_vector t);
t_matrix4	scale(float sx, float sy, float sz);
t_matrix4	m_multiply(t_matrix4 m1, t_matrix4 m2);
t_matrix4	sm_divide(t_matrix4 m, float s);
t_matrix4	transpose(t_matrix4 m);
t_matrix3	c_minor(t_matrix4 m4, int r, int c);
t_matrix4	adj(t_matrix4 m);
float		det4(t_matrix4 m);
float		det3(t_matrix3 m);
t_matrix4	m_invert(t_matrix4 m);

#endif 