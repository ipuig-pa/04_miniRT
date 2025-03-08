/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_read_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:30:07 by ewu               #+#    #+#             */
/*   Updated: 2025/03/08 14:12:04 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/** FUNC:
 * to read *.rt and error check
 * retval: fd of file.rt
 */
int	valid_file(const char *filename)
{
	int			fd;
	const char	*dot_pos;

	dot_pos = ft_strrchr(filename, '.');
	if (!dot_pos || ft_strncmp(dot_pos, ".rt", 4) != 0)
	{
		p_err("Invalid filename! Must be .rt extension.");
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		p_err("Cannot open file!");
		close(fd);
		return (-1);
	}
	return (fd);
}

// empty in main parsing already, but can also write smth here for safety
bool	empty_check(int fd);

// Q: do we have to change all-related ft_func in get_next_line() into gc_func()?

char	*read_file(const char *filename)
{
	int		fd;
	char	*content;
	char	*line;
	char	*tmp;

	fd = valid_file(filename);
	if (fd < 0)
		return (p_err("Errors in file validation or opening file!"), NULL);
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
// not using gc here, cuz no gc in GNL

int	count_lines(const char *content)
{
	int	i;

	i = 0;
	if (content == NULL)
		return (p_err("Fail to read file or Empty file!"), gc_clean(),
			-1);
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
