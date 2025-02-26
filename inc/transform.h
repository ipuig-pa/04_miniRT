/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:37:41 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/26 17:04:23 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include <stdbool.h>
# include "ray.h"

typedef	struct s_matrix
{
	float	m[4][4];
	bool	exist;
}			t_matrix; //or no need to be a struct, just typedef float [4][4]???

t_ray		m_transform(t_ray r, t_matrix m);
t_matrix	rotate(float r, t_vector a);
t_matrix	translate(t_vector t);
t_matrix	scale(float s);
t_matrix	m_multiply(t_matrix m1, t_matrix m2);

#endif 