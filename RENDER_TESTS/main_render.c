/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:30:03 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/03 13:04:24 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_env		env;
	t_scene		scene;
	t_obj		obj[8];

	init_env(&env);
	scene.obj_num = 8;

	obj[7].type = SPH;
	obj[7].color = PINK;
	obj[7].param.sph.c = v_create(0.0, 0.0, -200.0, 1.0);
	obj[7].param.sph.r = 5.0;

	obj[1].type = SPH;
	obj[1].color = RED;
	obj[1].param.sph.c = v_create(0.0, 20.0, -200.0, 1.0);
	obj[1].param.sph.r = 2.5;

	obj[2].type = PL;
	obj[2].color = BLUE;
	obj[2].param.pl.n = v_create(0.0, 1.0, 0.0, 0.0);
	obj[2].param.pl.p = v_create(0.0, -7.0, 0.0, 1.0);

	obj[3].type = PL;
	obj[3].color = GREEN;
	obj[3].param.pl.n = v_create(0.0, 0.0, 1.0, 0.0);
	obj[3].param.pl.p = v_create(0.0, 0.0, -250.0, 1.0);

	obj[4].type = PL;
	obj[4].color = PINK;
	obj[4].param.pl.n = v_create(1.0, 0.0, 0.0, 0.0);
	obj[4].param.pl.p = v_create(-7.0, 0.0, 0.0, 1.0);

	obj[0].type = CYL;
	obj[0].color = RED;
	obj[0].param.cyl.b = v_create(2.0, 3.0, -150.0, 1.0);
	obj[0].param.cyl.a = unit_v(v_create(2.0, -1.0, 1.0, 0.0));
	obj[0].param.cyl.r = 1.5;
	obj[0].param.cyl.h = 10.0;

	obj[6].type = CIR;
	obj[6].color = RED;
	obj[6].param.cir.c = obj[0].param.cyl.b;
	obj[6].param.cir.n = obj[0].param.cyl.a;
	obj[6].param.cir.r = obj[0].param.cyl.r;

	obj[5].type = CIR;
	obj[5].color = RED;
	obj[5].param.cir.c = v_add(obj[0].param.cyl.b, scalar_mult(obj[0].param.cyl.a, obj[0].param.cyl.h));
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

	scene.obj = obj;

	scene.amblight.color = WHITE;
	scene.amblight.ratio = 0.1;

	scene.cam.p = v_create(0.0, 0.0, 0.0, 1.0);
	scene.cam.v = v_create(0.0, 0.0, -1.0, 0.0);
	scene.cam.fov = 0.5;

	scene.light.p = v_create(6.0, 0.0, -50.0, 1.0);
	scene.light.ratio = 0.6;
	scene.light.color = WHITE;

	env.scene = &scene;

	ray_tracer(&env);
	mlx_put_image_to_window(env.mlx, env.mlx_window, env.img.img, 0, 0);
	mlx_loop(env.mlx);
	return (0);
}
