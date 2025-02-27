/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:30:03 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/27 15:20:33 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_env		env;
	t_scene		scene;
	t_obj		obj[8];
	t_amblight	amblight;
	t_camera	cam;
	t_light		light;
	float		temp;

	init_env(&env);
	scene.obj_num = 8;
	obj[7].type = SPH;
	obj[7].color = PINK;
	obj[7].param.sph.c.x = 0.0;
	obj[7].param.sph.c.y = 0.0;
	obj[7].param.sph.c.z = -200.0;
	obj[7].param.sph.c.w = 1;
	obj[7].param.sph.r = 5.0;
	obj[1].type = SPH;
	obj[1].color = RED;
	obj[1].param.sph.c.x = 0.0;
	obj[1].param.sph.c.y = 20.0;
	obj[1].param.sph.c.z = -200.0;
	obj[1].param.sph.c.w = 1;
	obj[1].param.sph.r = 2.5;
	obj[2].type = PL;
	obj[2].color = BLUE;
	obj[2].param.pl.n.x = 0.0;
	obj[2].param.pl.n.y = 1.0;
	obj[2].param.pl.n.z = 0.0;
	obj[2].param.pl.n.w = 0;
	obj[2].param.pl.p.x = 0.0;
	obj[2].param.pl.p.y = -7.0;
	obj[2].param.pl.p.z = 0.0;
	obj[2].param.pl.p.w = 1;
	obj[3].type = PL;
	obj[3].color = GREEN;
	obj[3].param.pl.n.x = 0.0;
	obj[3].param.pl.n.y = 0.0;
	obj[3].param.pl.n.z = 1.0;
	obj[3].param.pl.n.w = 0;
	obj[3].param.pl.p.x = 0.0;
	obj[3].param.pl.p.y = 0.0;
	obj[3].param.pl.p.z = -250.0;
	obj[3].param.pl.p.w = 1;
	obj[4].type = PL;
	obj[4].color = PINK;
	obj[4].param.pl.n.x = 1.0;
	obj[4].param.pl.n.y = 0.0;
	obj[4].param.pl.n.z = 0.0;
	obj[4].param.pl.n.w = 0;
	obj[4].param.pl.p.x = -7.0;
	obj[4].param.pl.p.y = 0.0;
	obj[4].param.pl.p.z = 0.0;
	obj[4].param.pl.p.w = 1;
	obj[0].type = CYL;
	obj[0].color = RED;
	obj[0].param.cyl.b.x = 2.0;
	obj[0].param.cyl.b.y = 3.0;
	obj[0].param.cyl.b.z = -150.0;
	obj[0].param.cyl.b.w = 1;
	obj[0].param.cyl.a.x = 2.0; //not working bc vector is not unit
	obj[0].param.cyl.a.y = -1.0;
	obj[0].param.cyl.a.z = 1.0;
	obj[0].param.cyl.a.w = 0;
	(void) temp;
	temp = v_modulus(obj[0].param.cyl.a);
	obj[0].param.cyl.a.x = 2.0 / temp;
	obj[0].param.cyl.a.y = -1.0 / temp;
	obj[0].param.cyl.a.z = 1.0 / temp;
	obj[0].param.cyl.r = 1.5;
	obj[0].param.cyl.h = 10;
	obj[6].type = CIR;
	obj[6].color = RED;
	obj[6].param.cir.c = obj[0].param.cyl.b;
	obj[6].param.cir.n = obj[0].param.cyl.a;
	obj[6].param.cir.r = obj[0].param.cyl.r;
	obj[5].type = CIR;
	obj[5].color = RED;
	obj[5].param.cir.c = pv_add(obj[0].param.cyl.b, scalar_mult(obj[0].param.cyl.a, obj[0].param.cyl.h));
	obj[5].param.cir.n = invert_v(obj[0].param.cyl.a);
	obj[5].param.cir.r = obj[0].param.cyl.r;
	obj[0].m.exist = false;
	obj[1].m.exist = false;
	obj[2].m.exist = false;
	obj[3].m.exist = false;
	obj[4].m.exist = false;
	obj[5].m.exist = false;
	obj[6].m.exist = false;
	obj[7].m.exist = false;
	amblight.color = WHITE;
	amblight.ratio = 0.1;
	cam.p.x = 0.0;
	cam.p.y = 0.0;
	cam.p.z = 0.0;
	cam.p.w = 1;
	cam.v.x = 0.0;
	cam.v.y = 0.0;
	cam.v.z = -1.0;
	cam.v.w = 0;
	cam.fov = 0.5;
	light.p.x = 6.0;
	light.p.y = 0.0;
	//light.p.y = 500.0;
	light.p.z = -50.0;
	//light.p.z = 150.0;
	light.p.w = 1;
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
