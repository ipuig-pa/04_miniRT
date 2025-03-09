/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:30:41 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/09 12:31:18 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	light_translate(t_light *light, t_vector tv)
{
	light->p = v_transform(light->p, translate(tv), 'p');
}

//increase or decrease light ratio
void	light_scale(t_light *light, float factor)
{
	light->ratio = light->ratio * factor;
	if (light->ratio < 0)
		light->ratio = 0; 
	if (light->ratio > 1)
		light->ratio = 1; 
}