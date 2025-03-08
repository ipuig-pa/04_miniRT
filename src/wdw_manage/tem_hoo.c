/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tem_hoo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:29:58 by ewu               #+#    #+#             */
/*   Updated: 2025/03/08 14:45:05 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scale_obj(int keysym, t_scene *scene)
{
	if (scene->select_obj != -1)
	{
		if (keysym == KEY_PLUS)
			//to scale =>bigger
		else if (keysym == KEY_MINUS)
			//to scale smaller
		else
			return ;
	}
}

void	move_obj(int keysym, t_scene *scene)
{
	if (scene->select_obj != -1)
	{
		if (keysym == OBJ_F)
			//mv frontward
		else if (keysym == OBJ_B)
			//back
		else if (keysym == OBJ_UP)
			//up
		else if (keysym == OBJ_D)
			//down
		else if (keysym == OBJ_L)
			//left
		else if (keysym == OBJ_D)
			//down
		else
			return ;
	}
}
