/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:30:54 by ewu               #+#    #+#             */
/*   Updated: 2025/03/12 10:47:42 by ewu              ###   ########.fr       */
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

//get ONE word(token) from *line(single line)
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

//create array of token, and will pass to valid_token_checker()
/** expected outcome:
 * input = "  sp  11,11,11    5   255,211,221"
 * ret following:
 * tokens[0]=sp; tks[1]=11,11,11; tks[2]=5; tks[3]=255..; tks[4]=null
*/
char	**split_tokens(char *line, char delim)
{
	int		i;
	int		j;
	char	**tokens;

	i = 0;
	j = 0;
	tokens = gc_malloc(sizeof(char *) * (count_token(line) + 1));
	if (!tokens)
		// return (p_err("Error:\nFail in creating token array!"), gc_clean(), NULL);
		return (p_err("Error:\nFail in creating token array! Exit!"), NULL);
	while (j < count_token(line))
	{
		while (line[i] && line[i] == delim)
			i++;// space check again
		if (line[i])
		{
			tokens[j] = get_token(line + i, delim);
			if (!tokens[j])
				// return (free_double_pointer(tokens), NULL);
				return (p_err("Error:\nMalloc fail in get token. Exit!"), NULL);
			i = i + ft_strlen(tokens[j]);
			j++;
		}
	}
	tokens[j] = NULL;
	return (tokens);
}

/**
 * typedef struct s_scene
{
	t_amblight	*amblight;
	t_camera	*cam;
	t_light		*light;
	t_obj		*obj;
	int			obj_num;
}			t_scene;
 */
