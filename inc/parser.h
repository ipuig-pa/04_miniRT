/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:36:10 by ewu               #+#    #+#             */
/*   Updated: 2025/02/22 15:01:32 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

void	print_err(char *s1, char *s2, char *s3);
bool	valid_color_val(t_color clr);
int		valid_file(const char *filename);
bool parse_valid_tk(t_scene *scene, char *content);

char *read_file(const char *filename);
int count_para(char *line);
char *get_token(char *content, char delim);
char	**split_tokens(char *content, char delim);

#endif