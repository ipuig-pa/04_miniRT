/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:37:21 by ewu               #+#    #+#             */
/*   Updated: 2025/03/11 14:37:25 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Q: do we need both t_pont and t_vector?

// falls into default pos of cam
t_vector	err_point(void)
{
	return ((t_vector){0.0f, 0.0f, 0.0f, 1.0f});
}

// falls into default direction
t_vector	err_vector(void)
{
	return ((t_vector){0.0f, 0.0f, 1.0f, 0.0f});
}

t_vector	parse_vector(char *token, char key)
{
	t_vector	p;
	char		**coord;

	coord = gc_split(token, ',');
	if (!coord)
		return (p_err("Error:\nInvalid format of vector! Default \
			position called!"), err_point());
	if (!coord[0] || !coord[1] || !coord[2])
		return (free_double_pointer(coord), err_point());
	p.x = ft_atofloat(coord[0]);
	p.y = ft_atofloat(coord[1]);
	p.z = ft_atofloat(coord[2]);
	if (key == 'p')
		p.w = 1.0f;
	else if (key == 'v')
		p.w = 0.0f;
	free_double_pointer(coord);
	return (p);
}

t_vector	norm_vector(t_vector dirct_vec)
{
	t_vector	v;
	float		vec_len;

	v.x = dirct_vec.x;
	v.y = dirct_vec.y;
	v.z = dirct_vec.z;
	v.w = 0.0f;
	vec_len = v_modulus(v);
	if (vec_len == 0)
	{
		p_err("Invalid Camera direction! Default orientation called!");
		return (err_vector());
	}
	v.x = v.x / vec_len;
	v.y = v.y / vec_len;
	v.z = v.z / vec_len;
	return (v);
}

/**
para for: POSITION of Cam, normed vector
//element of type vector4, used both for vectors and points
typedef struct s_vector // w = 0 for vector and w = 1 for point
{
	float	x;
	float	y;
	float	z;
	float	w;
}			t_vector;
 */
// float	v_modulus(const t_vector *v)(from linear.h)
