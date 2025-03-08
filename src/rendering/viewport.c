/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:32:19 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 09:35:05 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_viewport(t_scene *scene)
{
	t_vector	world_vert;
	float		half_vp_w;
	float		half_vp_h;

	world_vert = v_create(0.0, 1.0, 0.0, 0.0);
	scene->vp.right = unit_v(cross_prod(scene->cam.v, world_vert));
	scene->vp.up = unit_v(cross_prod(scene->vp.right, scene->cam.v));
	scene->vp.front = unit_v(scene->cam.v);
	half_vp_w = tanf(scene->cam.fov / 2.0);
	half_vp_h = WINDOW_HEIGHT * half_vp_w / WINDOW_WIDTH;
	scene->vp.px_space = 2.0 * half_vp_w / WINDOW_WIDTH;
	scene->vp.o = v_add(scene->cam.p, scene->vp.front);
	scene->vp.o = v_add(scene->vp.o, scalar_mult(scene->vp.right, -half_vp_w));
	scene->vp.o = v_add(scene->vp.o, scalar_mult(scene->vp.up, half_vp_h));
}