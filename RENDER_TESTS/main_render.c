/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:30:03 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/22 19:04:19 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_env		env;
	t_scene		scene;
	t_obj		obj[5];
	t_amblight	amblight;
	t_camera	cam;
	t_light		light;

	init_env(&env);
	scene.obj_num = 5;
	obj[0].type = SPH;
	obj[0].color = PINK;
	obj[0].param.sph.c.x = 0.0;
	obj[0].param.sph.c.y = 0.0;
	obj[0].param.sph.c.z = 200.0;
	obj[0].param.sph.d = 10.0;
	obj[1].type = SPH;
	obj[1].color = RED;
	obj[1].param.sph.c.x = 0.0;
	obj[1].param.sph.c.y = 20.0;
	obj[1].param.sph.c.z = 200.0;
	obj[1].param.sph.d = 5.0;
	obj[2].type = PL;
	obj[2].color = GREEN;
	obj[2].param.pl.v.x = 0.0;
	obj[2].param.pl.v.y = 1.0;
	obj[2].param.pl.v.z = 0.0;
	obj[2].param.pl.p.x = 0.0;
	obj[2].param.pl.p.y = -7.0;
	obj[2].param.pl.p.z = 0.0;
	obj[3].type = PL;
	obj[3].color = GREEN;
	obj[3].param.pl.v.x = 0.0;
	obj[3].param.pl.v.y = 0.0;
	obj[3].param.pl.v.z = 1.0;
	obj[3].param.pl.p.x = 0.0;
	obj[3].param.pl.p.y = 0.0;
	obj[3].param.pl.p.z = 207.0;
	obj[4].type = PL;
	obj[4].color = GREEN;
	obj[4].param.pl.v.x = 1.0;
	obj[4].param.pl.v.y = 0.0;
	obj[4].param.pl.v.z = 0.0;
	obj[4].param.pl.p.x = -7.0;
	obj[4].param.pl.p.y = 0.0;
	obj[4].param.pl.p.z = 0.0;
	amblight.color = WHITE;
	amblight.ratio = 0.1;
	cam.p.x = 0.0;
	cam.p.y = 0.0;
	cam.p.z = 0.0;
	cam.v.x = 0.0;
	cam.v.y = 0.0;
	cam.v.z = 1.0;
	cam.fov = 0.5;
	light.p.x = 6.0;
	light.p.y = 0.0;
	//light.p.y = 500.0;
	light.p.z = 200.0;
	//light.p.z = 150.0;
	light.ratio = 0.6;
	light.color = WHITE;
	scene.obj = obj;
	scene.cam = &cam;
	scene.amblight = &amblight;
	scene.light = &light;
	env.scene = &scene;
	ray_tracer(&env);
	mlx_put_image_to_window(env.mlx, env.mlx_window, env.img.img, 0, 0);
	mlx_loop(env.mlx);
	return (0);
}
