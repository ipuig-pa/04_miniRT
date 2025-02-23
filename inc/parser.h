/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:36:10 by ewu               #+#    #+#             */
/*   Updated: 2025/02/23 21:40:09 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// error and validation check
void		p_err(char *s);
int			valid_file(const char *filename);
bool		parse_valid_tk(t_scene *scene, char *content);

// read file/input
char		*read_file(const char *filename);
int			count_para(char *line);
char		*get_token(char *content, char delim);
char		**split_tokens(char *content, char delim);

// math
float		ft_atofloat(char *s);

// util
int			para_nbr(char **arr);

// main parser
bool		valid_color_val(t_color clr);
t_color		parse_color(char *token);
t_color		err_color(void);
void		parse_ambient(t_amblight *amblight, char **tokens);

t_point		err_point(void);
t_point		parse_point(char *token);
t_vector	err_vector(void);
t_vector	norm_vector(t_point dirct_vec);

#endif