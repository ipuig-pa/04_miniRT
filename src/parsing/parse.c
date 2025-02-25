/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:39:42 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/25 11:39:36 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// main parsing (with error checking)
// directs to specific fts
// verify token: A(ambient), C(camera), L(light)
// pl(plane), cy(cylinder), sp(sphere)

// NOTE: may i make some change to obj struct?
// space as delim, write prompt to indicate valid input format later??
bool	parse_valid_tk(t_scene *scene, char *line)
{
	char		**tokens;
	static int	i;

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
		parse_plane(scene->obj[i]->param.pl, tokens);
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		parse_sphere(scene->obj[i]->param.sph, tokens);
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
	{
		parse_cylinder(scene->obj, i, [i]->param.cyl, tokens); //change depending on how the circles are parsed
	}
	else
		return (p_err("Invalid identifier passed!"), false);
	i++;
	return (free_double_pointer(tokens), true);
}

// content: big string of multiple lines(delim by \n)
// lines: split from *content
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
	//or no +1 for a NULL space at end??
	while (lines[i] && parse_valid_tk(scene, lines[i]))
		i++;
	free_double_pointer(lines);
}
