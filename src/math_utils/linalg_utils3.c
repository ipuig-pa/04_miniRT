/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linalg_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:57:25 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:47:35 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	unit_v(t_vector v)
{
	float		mod;
	t_vector	u_v;

	mod = v_modulus(v);
	u_v.x = v.x / mod;
	u_v.y = v.y / mod;
	u_v.z = v.z / mod;
	u_v.w = 0;
	return (u_v);
}

t_vector	v_reflect(t_vector in, t_vector n)
{
	n = unit_v(n);
	in = unit_v(in);
	return (v_subt(in, scalar_mult(n, 2 * dot_prod(in, n))));
}
