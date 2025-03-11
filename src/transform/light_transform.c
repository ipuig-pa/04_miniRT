/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:30:41 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/11 10:49:57 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	light_translate(t_light *light, t_vector tv)
{
	light->p = v_transform(light->p, translate(tv), 'p');
}

//increase or decrease light ratio
void	light_scale(float *ratio, float factor)
{
	*ratio = *ratio * factor;
	if (*ratio < 0)
		*ratio = 0;
	if (*ratio > 1)
		*ratio = 1;
}
