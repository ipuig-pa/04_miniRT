/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:36:10 by ewu               #+#    #+#             */
/*   Updated: 2025/02/24 13:36:49 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// error and validation check
void		p_err(char *s);
int			valid_file(const char *filename);
bool		parse_valid_tk(t_scene *scene, char *line);

// read file and create token
int			count_token(char *line);
int			count_objs(char **lines);
char		*read_file(const char *filename);
char		*get_token(char *content, char delim);
char		**split_tokens(char *content, char delim);

// math
float		ft_atofloat(char *s);

// util
int			para_nbr(char **arr);
bool		valid_color_val(t_color clr);
t_color		err_color(void);
t_point		err_point(void);
t_point		parse_point(char *token);
t_vector	err_vector(void);
t_vector	norm_vector(t_point dirct_vec);

// main parser
void		parsing_scene(t_scene *scene, const char *filename);
void		parse_ambient(t_amblight *amblight, char **tokens);
void		parse_camera(t_camera *camera, char **tokens);
void		parse_light(t_light *light, char **tokens);
t_color		parse_color(char *token);

#endif