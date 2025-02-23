/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:39:42 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/23 11:39:32 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// main parsing (with error checking)
// directs to specific fts
// verify token: A(ambient), C(camera), L(light)
// pl(plane), cy(cylinder), sp(sphere)

//NOTE: may i make some change to obj struct?
bool	parse_valid_tk(t_scene *scene, char *content)
{
	char	**tokens;

	tokens = split_tokens(content, ' ');
	// space as delim, write prompt to indicate valid input format later??
	if (tokens == NULL || tokens[0] == '\0')
		return (print_err("Empty input or Malloc failed!", NULL, NULL), false);
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		parse_ambient(scene->amblight, tokens); // member func implemnted later
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		parse_camera(scene->cam, tokens);
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		parse_light(scene->light, tokens);
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		parse_plane(scene->obj->param.pl, tokens);
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		parse_sphere(scene->obj->param.sph, tokens);
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		parse_cylinder(scene->obj->param.cyl, tokens);
	else
		return (print_err("Invalid identifier passed!", NULL, NULL), false);
	free_double_pointer(tokens);
	return (true);
}
