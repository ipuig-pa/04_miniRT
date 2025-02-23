/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:30:54 by ewu               #+#    #+#             */
/*   Updated: 2025/02/23 11:19:42 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// take the retval from read_file() and count
int	count_para(char *content)
{
	int		count;
	bool	within;

	count = 0;
	within = false;
	while (*content)
	{
		if (*content == ' ' || *content == '\t')
			within = false;
		else if (within == false)
		{
			within = true;
			count++;
		}
		content++;
	}
	return (count);
}

//get ONE word(token) from *content(ret by read_file())
char	*get_token(char *content, char delim)
{
	int		tk_len;
	char	*token;

	tk_len = 0;
	while (content[tk_len] && content[tk_len] != delim)
		tk_len++;
	token = gc_malloc(sizeof(char) * (tk_len + 1));
	if (!token)
		return (NULL);
	ft_strlcpy(token, content, tk_len + 1);
	return (token);
}

//create array of token, and will pass to valid_token_checker()
/** expected outcome:
 * input = "  sp  11,11,11    5   255,211,221"
 * ret:
 * tokens[0]=sp; tks[1]=11,11,11; tks[2]=5; tks[3]=255..; tks[4]=null
*/
char	**split_tokens(char *content, char delim)
{
	int		i;
	int		j;
	char	**tokens;

	i = 0;
	j = 0;
	tokens = gc_malloc(sizeof(char *) * (count_para(content) + 1));
	if (!tokens)
		return (NULL);
	while (j < count_para(content))
	{
		while (content[i] && content[i] == delim)
			i++;// space check again
		if (content[i])
		{
			tokens[j] = get_token(content + i, delim);
			if (!tokens[j])
				return (free_double_pointer(tokens), NULL);
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
