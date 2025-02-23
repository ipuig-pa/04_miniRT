/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_read_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:30:07 by ewu               #+#    #+#             */
/*   Updated: 2025/02/23 13:01:19 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/** FUNC:
 * to read *.rt and error check
 */
//retval: fd of file.rt
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

//Q: do we have to change all-related ft_func in get_next_line() into gc_func()?
char *read_file(const char *filename)
{
	int fd;
	char *content;
	char *line;
	char *tmp;

	fd = valid_file(filename);
	if (fd < 0)
		return (p_err("Errors in file validation or opening file!"), NULL);
	content = gc_strdup("");
	//create empty str
	while(get_next_line(fd) != NULL)
	//read as long as line exist
	{
		line = get_next_line(fd);
		if (line[0] != '\0')
		//skip empty
		{
			tmp = content;
			content = gc_strjoin(content, line);
			gc_free(tmp);
			tmp = content;
			content = gc_strjoin(content, "\n");
			gc_free(tmp);
		}
		free(line);
		//not using gc here, cuz no gc in GNL
	}
	return (close(fd), content);
}
