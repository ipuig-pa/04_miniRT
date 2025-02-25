/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:39:42 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/25 11:01:11 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// main parsing (with error checking)
// directs to specific fts
// verify token: A(ambient), C(camera), L(light)
// pl(plane), cy(cylinder), sp(sphere)

// content: big string of multiple lines(delim by \n)
// lines: split from *content, array of single lines
// line: single line (lines[i])
void	parsing_scene(t_scene *scene, const char *filename)
{
	char	*content;
	char	**lines;
	int		i;

	i = 0;
	content = read_file(filename);
	if (!content)
		return ((void)p_err("Errors in reading file!"));
	lines = gc_split(content, '\n');
	gc_free(content);
	if (!lines)
		return ((void)p_err("Errors in spliting file!"));
	scene->obj_num = count_objs(lines);
	scene->obj = gc_malloc(sizeof(t_obj) * (scene->obj_num + 1));
	while (lines[i] && parse_valid_tk(scene, lines[i]))
		i++;
	free_double_pointer(lines);
}
//or no +1 for a NULL space at end??

// NOTE: may i make some change to obj struct?
// space as delim, write prompt to indicate valid input format later??
bool	parse_valid_tk(t_scene *scene, char *line)
{
	char	**tokens;

	tokens = split_tokens(line, ' ');
	if (tokens == NULL || tokens[0] == '\0')
		return (p_err("Empty input or Malloc failed!"), false);
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		parse_ambient(scene->amblight, tokens);
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		parse_camera(scene->cam, tokens);
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		parse_light(scene->light, tokens);
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		parse_plane(scene->obj->param.pl, tokens);
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		parse_sphere(scene->obj->param.sph, tokens);
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		parse_cylinder(scene->obj->param.cyl, scene->obj->param.cir, tokens);
	else
		return (p_err("Invalid identifier passed!"), false);
	return (free_double_pointer(tokens), true);
}
