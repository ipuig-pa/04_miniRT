/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:12:59 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 21:26:43 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//handle allocation fail using gc_malloc, forcing cleaning everything before
//if malloc fails, exit whole program
void	gc_malloc_error(void)
{
	t_gc_list	**gc_list;

	gc_list = get_gc_list();
	if (gc_list)
	{
		gc_clean();
		perror ("minishell: heap allocation fail\n");
	}
}
