/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linalg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:57:14 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/21 12:09:20 by ipuig-pa         ###   ########.fr       */
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

float		dot_product(const t_vector *v1, const t_vector *v2);
float		scalar_mult(const t_vector *v, int s);
float		dist(const t_point *p1, const t_point *p2);
t_vector	invert_v(t_vector *v);
float		v_modulus(const t_vector *v);


#endif