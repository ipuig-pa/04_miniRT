/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:30:54 by ewu               #+#    #+#             */
/*   Updated: 2025/03/13 10:58:57 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// take the retval from read_file() and count
int	count_token(char *line)
{
	int		count;
	bool	within;

	count = 0;
	within = false;
	while (*line)
	{
		if (*line == ' ' || *line == '\t')
			within = false;
		else if (within == false)
		{
			within = true;
			count++;
		}
		line++;
	}
	return (count);
}

// get ONE word(token) from *line(single line)
char	*get_token(char *line, char delim)
{
	int		tk_len;
	char	*token;

	tk_len = 0;
	while (line[tk_len] && line[tk_len] != delim)
		tk_len++;
	token = gc_malloc(sizeof(char) * (tk_len + 1));
	if (!token)
	{
		p_err("Error:\nMalloc fail in read file. Exit!");
		return (NULL);
	}
	ft_strlcpy(token, line, tk_len + 1);
	return (token);
}

char	**split_tokens(char *line, char delim)
{
	int		i;
	int		j;
	char	**tokens;

	i = 0;
	j = 0;
	tokens = gc_malloc(sizeof(char *) * (count_token(line) + 1));
	if (!tokens)
		return (p_err("Error:\nFail in creating token array! Exit!"), NULL);
	while (j < count_token(line))
	{
		while (line[i] && line[i] == delim)
			i++;
		if (line[i])
		{
			tokens[j] = get_token(line + i, delim);
			if (!tokens[j])
				return (p_err("Error:\nMalloc fail in get token. Exit!"), NULL);
			i = i + ft_strlen(tokens[j]);
			j++;
		}
	}
	tokens[j] = NULL;
	return (tokens);
}

int	check_dup(char **lines)
{
	int	i;
	int	cap_a;
	int	cap_c;
	int	cap_l;

	i = 0;
	cap_a = 0;
	cap_c = 0;
	cap_l = 0;
	while (lines[i])
	{
		if (ft_strncmp(lines[i], "A ", 2) == 0)
			cap_a++;
		else if (ft_strncmp(lines[i], "L ", 2) == 0)
			cap_l++;
		else if (ft_strncmp(lines[i], "C ", 2) == 0)
			cap_c++;
		i++;
	}
	if (cap_a > 1 || cap_c > 1 || cap_l > 1)
		return (p_err("Error:\nMore than one Camera/Light/Ambient \
parameter passed! Exit"), exit_on_parse(), 0);
	return (1);
}
