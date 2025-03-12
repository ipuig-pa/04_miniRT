/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tofloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:52:40 by ewu               #+#    #+#             */
/*   Updated: 2025/03/12 20:51:32 by ewu              ###   ########.fr       */
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
