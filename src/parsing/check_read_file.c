/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_read_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:30:07 by ewu               #+#    #+#             */
/*   Updated: 2025/03/12 20:51:01 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	valid_file(const char *filename)
{
	int			fd;
	const char	*dot_pos;

	dot_pos = ft_strrchr(filename, '.');
	if (!dot_pos || ft_strncmp(dot_pos, ".rt", 4) != 0)
	{
		p_err("Error:\nInvalid filename! Must be .rt extension. Exit!");
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		p_err("Error:\nCannot open file! Exit!");
		close(fd);
		return (-1);
	}
	return (fd);
}

char	*read_file(const char *filename)
{
	int		fd;
	char	*content;
	char	*line;
	char	*tmp;

	fd = valid_file(filename);
	if (fd < 0)
		return (p_err("Error:\n Cannot open file! Exit!"), NULL);
	content = gc_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] != '\0')
		{
			tmp = content;
			content = gc_strjoin(content, line);
			gc_free(tmp);
			tmp = content;
			content = gc_strjoin(content, "\n");
			gc_free(tmp);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), content);
}

int	count_lines(const char *content)
{
	int	i;

	i = 0;
	if (content == NULL)
		return (p_err("Error:\nFail to read file or Empty file! Exit!"), -1);
	while (*content)
	{
		if (*content == '\n')
			i++;
		content++;
	}
	return (i);
}

int	count_objs(char **lines)
{
	int	i;
	int	obj_num;

	i = 0;
	obj_num = 0;
	while (lines[i])
	{
		if (ft_strncmp(lines[i], "sp ", 3) == 0 || \
			ft_strncmp(lines[i], "pl ", 3) == 0)
			obj_num += 1;
		else if (ft_strncmp(lines[i], "cy ", 3) == 0)
			obj_num += 3;
		i++;
	}
	return (obj_num);
}
