/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:22:25 by ewu               #+#    #+#             */
/*   Updated: 2025/02/23 11:59:58 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/**
 * typedef struct s_scene
{
	t_amblight	*amblight;
	t_camera	*cam;
	t_light		*light;
	t_obj		*obj;
	int			obj_num;
}			t_scene;
 * typedef struct s_amblight
{
	float	ratio;
	t_color	color;
}			t_amblight;
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

//tokens[1] => ratio(float); tk[2] => rgba
void parse_ambient(t_amblight *amblight, char **tokens)
{
	if (tokens[1] == NULL || tokens[2] == NULL)
	{
		print_err("Invalid number of ambient light!", NULL, NULL);
		return ;
	}
	amblight->ratio = ft_atofloat(tokens[1]);
}