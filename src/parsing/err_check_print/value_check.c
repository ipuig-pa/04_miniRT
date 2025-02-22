/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:13:06 by ewu               #+#    #+#             */
/*   Updated: 2025/02/22 14:44:04 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*check valid range of value*/

/**
 * typedef union u_color
{
	struct		s_comp
	{
		float	r;
		float	g;
		float	b;
		float	a;
	}			s_comp;
	float		rgba[4];
}				t_color;
 */
bool	valid_color_val(t_color clr)
{
	if (clr.s_comp.a >= 0 && clr.s_comp.a <= 255 && clr.s_comp.r >= 0
		&& clr.s_comp.r <= 255 && clr.s_comp.g >= 0 && clr.s_comp.g <= 255
		&& clr.s_comp.b >= 0 && clr.s_comp.b <= 255)
		return (true);
	return (false);
}
