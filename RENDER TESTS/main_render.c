/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:30:03 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/20 18:17:00 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_env		env;
	t_scene		scene;
	t_obj		obj;
	t_amblight	amblight;
	t_camera	cam;
	t_light		light;

	init_env(&env);
	scene.obj_num = 1;
	obj.type = SPH;
	obj.color = GREEN;
	obj.param.sph.c.x = 0.0;
	obj.param.sph.c.y = 0.0;
	obj.param.sph.c.z = 80.0;
	obj.param.sph.d = 80.0;
	amblight.color = WHITE;
	amblight.ratio = 0.1;
	cam.p.x = 0.0;
	cam.p.y = 0.0;
	cam.p.z = 0.0;
	cam.v.x = 0.0;
	cam.v.y = 0.0;
	cam.v.z = 1.0;
	cam.fov = 2.14;
	light.p.x = 0.0;
	light.p.y = 50.0;
	light.p.z = 80.0;
	light.ratio = 0.7;
	light.color = WHITE;
	scene.obj = &obj;
	scene.cam = &cam;
	scene.amblight = &amblight;
	scene.light = &light;
	env.scene = &scene;
	ray_tracer(&env);
	mlx_put_image_to_window(env.mlx, env.mlx_window, env.img.img, 0, 0);
	mlx_loop(env.mlx);
	return (0);
}
