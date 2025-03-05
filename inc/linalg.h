/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linalg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:53:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/05 16:52:00 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//For lineal algebra elements: point, vectors, matrices
#ifndef LINALG_H
# define LINALG_H

//element of type vector4, used both for vectors and points
typedef struct s_vector // w = 0 for vector and w = 1 for point
{
	float	x;
	float	y;
	float	z;
	float	w;
}			t_vector;

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

#endif