/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:39:42 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/07 15:26:49 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_all(t_scene *scene) //TESTING, TO DELETE!!
{
	int	i;

	i = 0;
	printf("--------------------------PARSING--------------------------\n");
	printf("AMB: rat: %f; col: %f, %f, %f. %f\n", scene->amblight.ratio, scene->amblight.color.rgba[0], scene->amblight.color.rgba[1], scene->amblight.color.rgba[2], scene->amblight.color.rgba[3]);
	printf("CAM: point: %f, %f, %f, %f; vect: %f, %f, %f, %f; fov: %f\n", scene->cam.p.x,  scene->cam.p.y,  scene->cam.p.z, scene->cam.p.w, scene->cam.v.x,  scene->cam.v.y,  scene->cam.v.z, scene->cam.v.w, scene->cam.fov);
	printf("LIG: point: %f, %f, %f, %f, rat: %f; col: %f, %f, %f, %f\n", scene->light.p.x,  scene->light.p.y,  scene->light.p.z, scene->light.p.w, scene->light.ratio, scene->light.color.s_comp.r, scene->light.color.s_comp.g, scene->light.color.s_comp.b, scene->light.color.s_comp.a);
	printf("OBJ: num: %i\n", scene->obj_num);
	while (i < scene->obj_num)
	{
		printf("OBJ %i: type:%i, color: %f, %f, %f, %f, material: %i\n", i, scene->obj[i].type, scene->obj[i].color.rgba[0], scene->obj[i].color.rgba[1], scene->obj[i].color.rgba[2], scene->obj[i].color.rgba[3], scene->obj[i].mat.type);
		if (scene->obj[i].type == CIR)
			printf("CIR: c: %f, %f, %f, %f; n: %f, %f, %f, %f; r: %f \n", scene->obj[i].param.cir.c.x, scene->obj[i].param.cir.c.y, scene->obj[i].param.cir.c.z, scene->obj[i].param.cir.c.w, scene->obj[i].param.cir.n.x,  scene->obj[i].param.cir.n.y,  scene->obj[i].param.cir.n.z,  scene->obj[i].param.cir.n.w,  scene->obj[i].param.cir.r);
		if (scene->obj[i].type == CYL)
			printf("CYL: c: %f, %f, %f, %f; b: %f, %f, %f, %f; a: %f, %f, %f, %f; r: %f, a: %f\n", scene->obj[i].param.cyl.c.x, scene->obj[i].param.cyl.c.y, scene->obj[i].param.cyl.c.z, scene->obj[i].param.cyl.c.w, scene->obj[i].param.cyl.b.x, scene->obj[i].param.cyl.b.y, scene->obj[i].param.cyl.b.z, scene->obj[i].param.cyl.b.w, scene->obj[i].param.cyl.a.x, scene->obj[i].param.cyl.a.y, scene->obj[i].param.cyl.a.z, scene->obj[i].param.cyl.a.w, scene->obj[i].param.cyl.r, scene->obj[i].param.cyl.h);
		if (scene->obj[i].type == SPH)
			printf("SPH: c: %f, %f, %f, %f; r: %f\n", scene->obj[i].param.sph.c.x, scene->obj[i].param.sph.c.y, scene->obj[i].param.sph.c.z, scene->obj[i].param.sph.c.w, scene->obj[i].param.sph.r);
		if (scene->obj[i].type == PL)
			printf("PL: p: %f, %f, %f, %f; n: %f, %f, %f, %f\n", scene->obj[i].param.pl.p.x, scene->obj[i].param.pl.p.y, scene->obj[i].param.pl.p.z, scene->obj[i].param.pl.p.w, scene->obj[i].param.pl.n.x, scene->obj[i].param.pl.n.y, scene->obj[i].param.pl.n.z, scene->obj[i].param.pl.n.w);
		i++;
	}
}

// content: big string of multiple lines(delim by \n)
// lines: split from *content, array of single lines
// line: single line (lines[i])
int	parsing_scene(t_env *env, const char *filename)
{
	char	*content;
	char	**lines;
	int		i;

	i = 0;
	content = read_file(filename);
	if (!content)
		return (p_err("Errors in reading file!"), 0);
	lines = gc_split(content, '\n');
	gc_free(content);
	if (!lines)
		return (p_err("Errors in spliting file!"), 0);
	env->scene = gc_malloc(sizeof(t_scene));
	if (!env->scene)
	{
		p_err("Memory allocation for t_scene failed!");
		return (gc_clean(), 0);
	}
	env->scene->obj_num = count_objs(lines);
	env->scene->obj = gc_malloc(sizeof(t_obj) * (env->scene->obj_num + 1));
	if (!env->scene->obj)
	{
		p_err("Memory allocation for Objects failed!");
		return (gc_clean(), 0);
	}
	while (lines[i] && parse_valid_tk(env->scene, lines[i]))
		i++;
	print_all(env->scene); //TESTING, TO DELETE
	free_double_pointer(lines);
	return (1);
}

// verify token: A, C, L, pl, cy, sp
// space as delim, write prompt to indicate valid input format later??
bool	parse_valid_tk(t_scene *scene, char *line)
{
	char		**tokens;
	static int	i = 0;

	tokens = split_tokens(line, ' ');
	if (!tokens || !tokens[0])
		return (p_err("Empty input or Malloc failed!"), false);
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		parse_ambient(&scene->amblight, tokens);
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
		parse_camera(&scene->cam, tokens);
	else if (ft_strncmp(tokens[0], "L", 2) == 0)
		parse_light(&scene->light, tokens);
	else if (ft_strncmp(tokens[0], "pl", 3) == 0)
		parse_plane(&scene->obj[i++], tokens);
	else if (ft_strncmp(tokens[0], "sp", 3) == 0)
		parse_sphere(&scene->obj[i++], tokens);
	else if (ft_strncmp(tokens[0], "cy", 3) == 0)
	{
		parse_cylinder(&scene->obj[i++], tokens);
		i += 2;
	}
	else
		return (p_err("Invalid identifier passed!"), false);
	return (free_double_pointer(tokens), true);
}

// void	parsing_scene(t_scene *scene, const char *filename)
// {
// 	char	*content;
// 	char	**lines;
// 	int		i;

// 	i = 0;
// 	content = read_file(filename);
// 	if (!content)
// 		return ((void)p_err("Errors in reading file!"));
// 	lines = gc_split(content, '\n');
// 	gc_free(content);
// 	if (!lines)
// 		return ((void)p_err("Errors in spliting file!"));
// 	scene->obj_num = count_objs(lines);
// 	scene->obj = gc_malloc(sizeof(t_obj) * (scene->obj_num + 1));
// 	while (lines[i] && parse_valid_tk(scene, lines[i]))
// 		i++;
// 	free_double_pointer(lines);
// }