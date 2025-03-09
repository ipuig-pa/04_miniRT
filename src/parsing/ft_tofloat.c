/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tofloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:52:40 by ewu               #+#    #+#             */
/*   Updated: 2025/03/09 09:25:45 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	ft_fraction(char **s)
{
	float	frac;
	float	n;

	n = 0.1f;
	frac = 0.0f;
	while (**s >= '0' && **s <= '9')
	{
		frac = frac + (**s - '0') * n;
		n = n / 10;
		(*s)++;
	}
	return (frac);
}

float	ft_atofloat(char *s)
{
	long	i;
	float	frac;
	int		sign;

	sign = 1;
	i = 0;
	frac = 0.0f;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign = -sign;
	}
	while (*s != '.' && *s)
		i = (i * 10) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
		frac = ft_fraction(&s);
	return (sign * (i + frac));
}

/**
 * double	ft_todouble(char *s)
{
	long	i;
	double	f;
	int		sign;
	double	power;

	sign = 1;
	power = 1;
	i = 0;
	f = 0.0;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign = -sign;
	}
	while (*s != '.' && *s)
		i = (i * 10) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
		f = ft_fraction(&s);
	return (sign * (i + f));
}

double	ft_fraction(char **s)
{
	double	f;
	double	n;

	n = 0.1;
	f = 0.0;
	while (**s >= '0' && **s <= '9')
	{
		f = f + (**s - '0') * n;
		n = n / 10;
		(*s)++;
	}
	return (f);
}
 */