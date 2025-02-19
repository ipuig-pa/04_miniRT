/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linalg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:17:08 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/19 19:17:22 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linalg.h"

float	dot_vroduct(t_vector *v1, t_vector *v2)
{
	float	res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}

float	scalar_mult(t_vector *v, int s)
{
	float	res;

	res = v.x * s + v.y * s + v.z * s;
	return (res);
}
