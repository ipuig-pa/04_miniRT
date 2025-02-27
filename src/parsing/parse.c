/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:39:42 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/27 11:28:31 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// content: big string of multiple lines(delim by \n)
// lines: split from *content, array of single lines
// line: single line (lines[i])
void	parsing_scene(t_env *env, const char *filename)
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
	env->scene = gc_malloc(sizeof(t_scene));
	if (!env->scene)
		return ((void)(p_err("Memory allocation for t_scene failed!"),
			gc_clean()));
	env->scene->obj_num = count_objs(lines);
	env->scene->obj = gc_malloc(sizeof(t_obj) * (env->scene->obj_num + 1));
	if (!env->scene->obj)
		return ((void)(p_err("Memory allocation for Objects failed!"),
			gc_clean()));
	while (lines[i] && parse_valid_tk(env->scene, lines[i]))
		i++;
	free_double_pointer(lines);
}

// verify token: A, C, L, pl, cy, sp
// space as delim, write prompt to indicate valid input format later??
bool	parse_valid_tk(t_scene *scene, char *line)
{
	char		**tokens;
	static int	i = 0;

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
		parse_plane(&scene->obj[i], tokens);
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		parse_sphere(&scene->obj[i], tokens);
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
	{
		parse_cylinder(&scene->obj[i], tokens);
		i += 2;
	}
	else
		return (p_err("Invalid identifier passed!"), false);
	i++;
	return (free_double_pointer(tokens), true);
}

// void	parsing_scene(t_scene *scene, const char *filename)
// {
// 	char	*content;
// 	char	**lines;
// 	int		i;

// 	i = 0;
// 	content = read_file(filename);
// 	if (!content)
// 		return ((void)p_err("Errors in reading file!"));
// 	lines = gc_split(content, '\n');
// 	gc_free(content);
// 	if (!lines)
// 		return ((void)p_err("Errors in spliting file!"));
// 	scene->obj_num = count_objs(lines);
// 	scene->obj = gc_malloc(sizeof(t_obj) * (scene->obj_num + 1));
// 	while (lines[i] && parse_valid_tk(scene, lines[i]))
// 		i++;
// 	free_double_pointer(lines);
// }