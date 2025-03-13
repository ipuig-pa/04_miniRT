/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:34:14 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/13 11:14:28 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix4	identity(void)
{
	t_matrix4	m;

	m.m[0][0] = 1;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[0][3] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = 1;
	m.m[1][2] = 0;
	m.m[1][3] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = 1;
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	m.exist = false;
	return (m);
}

t_matrix4	m_multiply(t_matrix4 m1, t_matrix4 m2)
{
	t_matrix4	m;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m.m[i][j] = m1.m[i][0] * m2.m[0][j] + m1.m[i][1] * m2.m[1][j] \
						+ m1.m[i][2] * m2.m[2][j] + m1.m[i][3] * m2.m[3][j];
			j++;
		}
		i++;
	}
	m.exist = true;
	return (m);
}

t_matrix4	sm_divide(t_matrix4 m, float s)
{
	t_matrix4	res_m;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res_m.m[i][j] = m.m[i][j] / s;
			j++;
		}
		i++;
	}
	return (res_m);
}

t_matrix4	transpose(t_matrix4 m)
{
	t_matrix4	t;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			t.m[i][j] = m.m[j][i];
			j++;
		}
		i++;
	}
	return (t);
}

t_matrix4	m_invert(t_matrix4 m)
{
	return (sm_divide(adj(transpose(m)), det4(m)));
}
