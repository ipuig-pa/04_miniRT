/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:34:14 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/13 11:25:04 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

static void	add_to_m3(float elem, t_matrix3 *m3)
{
	static int	m3i = 0;
	static int	m3j = 0;

	m3->m[m3i][m3j] = elem;
	if (m3j < 2)
		m3j++;
	else
	{
		m3j = 0;
		if (m3i < 2)
			m3i++;
		else
			m3i = 0;
	}
}

t_matrix3	c_minor(t_matrix4 m4, int r, int c)
{
	int			m4i;
	int			m4j;
	t_matrix3	m3;

	m4i = 0;
	while (m4i < 4)
	{
		if (m4i == r)
			m4i++;
		if (m4i < 4)
		{
			m4j = 0;
			while (m4j < 4)
			{
				if (m4j == c)
					m4j++;
				if (m4j < 4)
					add_to_m3(m4.m[m4i][m4j++], &m3);
			}
			m4i++;
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
