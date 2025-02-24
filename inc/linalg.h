/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linalg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:53:40 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/24 15:34:17 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//For lineal algebra elements: point, vectors, matrices
#ifndef LINALG_H
# define LINALG_H

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}			t_point;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}			t_vector;

// //or ????????????????????????
// typedef struct s_vector
// {
// 	float	x;
// 	float	y;
// 	float	z;
// 	int		w; //being 1 for points and 0 for vectors
// }			t_vector;

float		dot_prod(t_vector v1, t_vector v2);
t_vector	cross_prod(t_vector v1, t_vector v2);
t_vector	scalar_mult(t_vector v, float s);
float		dist(t_point p1, t_point p2);
t_vector	invert_v(t_vector v);
float		v_modulus(t_vector v);
t_vector	point_subt(t_point p2, t_point p1);
t_point		pv_add(t_point p, t_vector v);
t_vector	v_subt(t_vector v2, t_vector v1);

#endif