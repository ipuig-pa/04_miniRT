/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:36:10 by ewu               #+#    #+#             */
/*   Updated: 2025/03/11 13:44:49 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// error and validation check
void		p_err(char *s);
void		clean_scene(t_env *env);
int			valid_file(const char *filename);
int			parse_valid_tk(t_scene *scene, char *line, int i);

// read file and create token
int			count_token(char *line);
int			count_objs(char **lines);
int			count_lines(const char *content);
char		*read_file(const char *filename);
char		*get_token(char *content, char delim);
char		**split_tokens(char *content, char delim);

// math
float		ft_atofloat(char *s);

// util
int			para_nbr(char **arr);
int			check_para_num(char **tokens, char key);
int			check_para_2(char **tokens, char key);
bool		valid_color_val(t_color clr);
t_color		err_color(void);
t_vector	err_point(void);
t_vector	parse_vector(char *token, char key);
t_vector	err_vector(void);
t_vector	norm_vector(t_vector dirct_vec);
void		parse_material(t_obj *obj, char *token);
void		get_material(t_obj	*obj);

// main parser
int			parsing_scene(t_env *env, const char *filename);
t_color		parse_color(char *token);
void		parse_ambient(t_amblight *amblight, char **tokens);
void		parse_camera(t_camera *camera, char **tokens);
void		parse_light(t_light *light, char **tokens);
void		parse_cylinder(t_obj *obj, char **tokens);
int			create_surface(t_obj *obj, char **tokens);
void		create_topcir(t_obj *cyl, t_obj *obj);
void		create_basecir(t_obj *cyl, t_obj *obj);
void		parse_sphere(t_obj *obj, char **tokens);
void		parse_plane(t_obj *obj, char **tokens);

//void		parsing_scene(t_scene *scene, const char *filename);
#endif