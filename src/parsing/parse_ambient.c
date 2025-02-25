/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:22:25 by ewu               #+#    #+#             */
/*   Updated: 2025/02/25 12:25:26 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// tokens[1] => ratio(float); tk[2] => rgba
//A 0.2 255,255,255
void	parse_ambient(t_amblight *amblight, char **tokens)
{
	if (check_para_num(tokens, 'a') == -1)
		return ;//is clean needed?
	amblight->ratio = ft_atofloat(tokens[1]);
	if (amblight->ratio < 0.0f || amblight->ratio > 1.0f)
	{
		p_err("Invalid ambient light value: must be within 0.0-1.0!");
		return ;
	}
	amblight->color = parse_color(tokens[2]);
}

	// if (tokens[1] == NULL || tokens[2] == NULL)
	// {
	// 	p_err("Invalid number of ambient light!");
	// 	return ;
	// }
/**
 * typedef struct s_scene
{
	t_amblight	*amblight;
	t_camera	*cam;
	t_light		*light;
	t_obj		*obj;
	int			obj_num;
}				t_scene;
 * typedef struct s_amblight
{
	float	ratio;
	t_color	color;
}				t_amblight;
 */
