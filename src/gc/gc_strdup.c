/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:46:41 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/19 11:23:03 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*gc_strdup(const char *s1)
{
	char	*p;
	size_t	len;

	len = ft_strlen(s1);
	p = (char *)gc_malloc(len + 1);
	if (p == NULL)
	{
		return (NULL);
	}
	p = (char *)ft_memcpy((void *)p, (const void *)s1, len + 1);
	return (p);
}
