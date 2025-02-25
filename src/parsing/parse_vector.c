/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:37:21 by ewu               #+#    #+#             */
/*   Updated: 2025/02/25 15:46:23 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//Q: do we need both t_pont and t_vector?

// falls into default pos of cam
t_point	err_point(void)
{
	return ((t_point){0, 0, 0});
}

// falls into default direction
t_vector	err_vector(void)
{
	return ((t_vector){0, 0, 1});
}

t_point	parse_point(char *token)
{
	t_point	p;
	char	**coord;

	coord = gc_split(token, ',');
	if (!coord || !coord[0] || !coord[1] || !coord[2])
	{
		p_err("Invalid format of vector! Default position called!");
		free_double_pointer(coord);
		return (err_point());
	}
	p.x = ft_atofloat(coord[0]);
	p.y = ft_atofloat(coord[1]);
	p.z = ft_atofloat(coord[2]);
	free_double_pointer(coord);
	return (p);
}

t_vector	norm_vector(t_point dirct_vec)
{
	t_vector	v;
	float		vec_len;

	v.x = dirct_vec.x;
	v.y = dirct_vec.y;
	v.z = dirct_vec.z;
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

 * typedef struct s_point
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
 */
// float	v_modulus(const t_vector *v)(from linear.h)
