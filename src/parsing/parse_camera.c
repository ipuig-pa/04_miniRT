/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:30:00 by ewu               #+#    #+#             */
/*   Updated: 2025/02/25 12:29:44 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/** PARA: coordinate of camera POS(x,y,z) ==> 'p'
 * norm-ed vector => 'v'
 * fov: in rad(0-Pi)
 * eg: C 0.1,0.1,0.1 0.0,0.0,1.0 Pi(need converting)
 */
void	parse_camera(t_camera *camera, char **tokens)
{
	float	degree;

	if (check_para_num(tokens, 'a') == -1)
		return ;
	camera->p = parse_point(tokens[1]);
	camera->v = norm_vector(parse_point(tokens[2]));
	degree = ft_atofloat(tokens[2]);
	if (degree <= 0.0f || degree > 180.0f)
	{
		p_err("Invalid degree/radians of FOV!");
		return ;
	}
	camera->fov = degree * (M_PI / 180.0f);
}

	// if (tokens[1] == NULL || tokens[2] == NULL || tokens[3] == NULL)
	// {
	// 	p_err("Invalid number of Camera parameter!");
	// 	return ;
	// }
/**
typedef struct s_camera
{
	t_point		p;
	t_vector	v;
	float		fov; // field of view, store it already converted to rad
}				t_camera;
typedef struct s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef struct s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;
 */
