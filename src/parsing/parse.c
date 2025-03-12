/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:39:42 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 20:59:07 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// content: big string of multiple lines(delim by \n)
// lines: split from *content, array of single lines
// line: single line (lines[i])
int	parsing_scene(t_env *env, const char *filename)
{
	char	**lines;

	if (!read_and_split(filename, &lines))
		return (0);
	if (!init_parse_scene(env, filename, lines))
		return (0);
	if (!check_dup(lines))
		return (0);
	free_double_pointer(lines);
	env->scene->select_obj = -1;
	env->scene->select_light = false;
	env->scene->select_width = false;
	env->scene->select_height = false;
	return (1);
}

int	read_and_split(const char *filename, char ***lines)
{
	char	*content;

	content = read_file(filename);
	if (content == NULL)
		return (exit_on_parse(), 0);
	*lines = gc_split(content, '\n');
	gc_free(content);
	if (!(*lines))
	{
		p_err("Error:\nFail to split file! Exit!");
		exit_on_parse();
		return (0);
	}
	return (1);
}

int	init_parse_scene(t_env *env, const char *filename, char **lines)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	env->scene = gc_malloc(sizeof(t_scene));
	env->rt_scene_file = gc_strdup(filename);
	if (!env->scene)
		return (p_err("Error:\nMemory allocation for t_scene failed! Exit!"),
			exit_on_parse(), 0);
	env->scene->obj_num = count_objs(lines);
	env->scene->obj = gc_malloc(sizeof(t_obj) * (env->scene->obj_num + 1));
	if (!env->scene->obj)
		return (p_err("Error:\nMemory allocation for Objects failed! Exit!"),
			exit_on_parse(), 0);
	while (lines[i])
	{
		j = parse_valid_tk(env->scene, lines[i], j);
		if (j == -1)
			return (exit_on_parse(), 0);
		i++;
	}
	return (1);
}

// valid specifier: A, C, L, pl, cy, sp
int	parse_valid_tk(t_scene *scene, char *line, int i)
{
	char	**tokens;

	tokens = split_tokens(line, ' ');
	if (!tokens || !tokens[0])
		return (p_err("Error:\n Malloc failed! Exit!"), -1);
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		return (parse_ambient(&scene->amblight, tokens, i));
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		return (parse_camera(&scene->cam, tokens, i));
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		return (parse_light(&scene->light, tokens, i));
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		return (parse_plane(&scene->obj[i], tokens, i));
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		return (parse_sphere(&scene->obj[i], tokens, i));
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
		return (parse_cylinder(&scene->obj[i], tokens, i));
	else
		return (p_err("Error:\nInvalid identifier passed! Exit!"), -1);
	return (free_double_pointer(tokens), i);
}
