/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:34:14 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/05 16:19:42 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

t_matrix4	adj(t_matrix4 m)
{
	t_matrix4	adj;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			adj.m[i][j] = powf(-1, i + j) * det3(c_minor(m, i, j));
			j++;
		}
		i++;
	}
	return (adj);
}

float	det4(t_matrix4 m)
{
	float	det;
	int		j;

	det = 0.0;
	j = 0;
	while (j < 4)
	{
		det = det + m.m[0][j] * powf(-1, j) * det3(c_minor(m, 0, j));
		j++;
	}
	return (det);
}

t_matrix3	c_minor(t_matrix4 m4, int r, int c)
{
	int			m4i;
	int			m3i;
	int			m4j;
	int			m3j;
	t_matrix3	m3;

	m4i = 0;
	m3i = 0;
	while (m4i < 4)
	{
		if (m4i == r)
			m4i++;
		if (m4i < 4)
		{
			m4j = 0;
			m3j = 0;
			while (m4j < 4)
			{
				if (m4j == c)
					m4j++;
				if (m4j < 4)
				{
					m3.m[m3i][m3j] = m4.m[m4i][m4j];
					m4j++;
					m3j++;
				}
			}
			m4i++;
			m3i++;
		}
	}
	return (m3);
}

float	det3(t_matrix3 m)
{
	float	det3;

	det3 = m.m[0][0] * m.m[1][1] * m.m[2][2] + \
			m.m[0][1] * m.m[1][2] * m.m[2][0] + \
			m.m[1][0] * m.m[2][1] * m.m[0][2] - \
			m.m[0][2] * m.m[1][1] * m.m[2][0] - \
			m.m[0][1] * m.m[1][0] * m.m[2][2] - \
			m.m[2][1] * m.m[1][2] * m.m[0][0];
	return (det3);
}

t_matrix4	m_invert(t_matrix4 m)
{
	return (sm_divide(adj(transpose(m)), det4(m)));
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
