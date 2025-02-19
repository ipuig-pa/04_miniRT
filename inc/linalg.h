/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linalg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:57:14 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/19 10:06:55 by ipuig-pa         ###   ########.fr       */
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

//or ????????????????????????
typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
	int		w; //being 1 for points and 0 for vectors
}			t_vector;

#endif