/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:53:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:58:30 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include <stdbool.h>

//element of type vector4, used both for vectors and points
typedef struct s_vector // w = 0 for vector and w = 1 for point
{
	float	x;
	float	y;
	float	z;
	float	w;
}			t_vector;

typedef struct s_matrix4
{
	float	m[4][4];
	bool	exist;
}			t_matrix4;

typedef struct s_matrix3
{
	float	m[3][3];
}			t_matrix3;

//linear algebra
t_vector	v_create(float x, float y, float z, float w);
t_vector	v_add(t_vector v1, t_vector v2);
t_vector	v_subt(t_vector v2, t_vector v1);
float		dot_prod(t_vector v1, t_vector v2);
t_vector	cross_prod(t_vector v1, t_vector v2);
t_vector	scalar_mult(t_vector v, float s);
t_vector	element_mult(t_vector v, t_vector s);
t_vector	scalar_div(t_vector v, float s);
t_vector	invert_v(t_vector v);
float		v_modulus(t_vector v);
t_vector	unit_v(t_vector v);
t_vector	v_reflect(t_vector in, t_vector n);

//matrices
t_matrix4	identity(void);
t_matrix4	m_multiply(t_matrix4 m1, t_matrix4 m2);
t_matrix4	sm_divide(t_matrix4 m, float s);
t_matrix4	transpose(t_matrix4 m);
t_matrix3	c_minor(t_matrix4 m4, int r, int c);
t_matrix4	adj(t_matrix4 m);
float		det4(t_matrix4 m);
float		det3(t_matrix3 m);
t_matrix4	m_invert(t_matrix4 m);

//others
float		to_rad(float deg);

#endif