/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:15:59 by ewu               #+#    #+#             */
/*   Updated: 2025/02/23 12:29:55 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	p_err(char *s)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
}

// void	print_err(char *s1, char *s2, char *s3)
// {
// 	ft_putstr_fd(s1, 2);
// 	if (s2)
// 	{
// 		ft_putstr_fd(s2, 2);
// 	}
// 	if (s3)
// 	{
// 		ft_putstr_fd(s3, 2);
// 	}
// 	ft_putstr_fd("\n", 2);
// }
