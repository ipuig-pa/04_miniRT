/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:37:21 by ewu               #+#    #+#             */
/*   Updated: 2025/03/12 20:56:33 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	err_vector(void)
{
	t_vector	err_vector;

	err_vector.x = -INFINITY;
	err_vector.y = -INFINITY;
	err_vector.z = -INFINITY;
	err_vector.w = -1.0f;
	return (err_vector);
}

t_vector	parse_vector(char *token, char key)
{
	t_vector	p;
	char		**coord;

	coord = gc_split(token, ',');
	if (!coord)
		return (p_err("Error:\nMalloc failed! Exit"), err_vector());
	if (!coord[0] || !coord[1] || !coord[2])
		return (free_double_pointer(coord), \
		p_err("Error:\nInvalid vector! Must be \
			the format of (x, y, z). Exit"), err_vector());
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
		p_err("Error:\nInvalid vector orientation! Exit!");
		return (err_vector());
	}
	v.x = v.x / vec_len;
	v.y = v.y / vec_len;
	v.z = v.z / vec_len;
	return (v);
}

int	check_norm_range(t_vector v)
{
	if ((v.x > 1.0f || v.x < -1.0f) || \
		(v.y > 1.0f || v.y < -1.0f) || \
		(v.z > 1.0f || v.z < -1.0f))
		return (-1);
	return (1);
}
