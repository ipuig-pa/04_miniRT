/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:30:03 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/05 17:39:17 by ipuig-pa         ###   ########.fr       */
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

	obj[0].type = SPH;
	obj[0].color = PINK;
	obj[0].param.sph.c = v_create(0.0, 0.0, -200.0, 1.0);
	obj[0].param.sph.r = 5.0;

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

	obj[5].type = CYL;
	obj[5].color = RED;
	obj[5].param.cyl.c = v_create(2.0, 3.0, -150.0, 1.0);
	// obj[5].param.cyl.a = unit_v(v_create(0.0, 0.0, 1.0, 0.0));
	obj[5].param.cyl.a = unit_v(v_create(2.0, -1.0, 1.0, 0.0));
	obj[5].param.cyl.r = 1.5;
	obj[5].param.cyl.h = 10.0;
	obj[5].param.cyl.b = v_subt(obj[5].param.cyl.c, scalar_mult(obj[5].param.cyl.a, obj[5].param.cyl.h / 2));

	obj[6].type = CIR;
	obj[6].color = RED;
	obj[6].param.cir.c = obj[5].param.cyl.b;
	obj[6].param.cir.n = invert_v(obj[5].param.cyl.a);
	obj[6].param.cir.r = obj[5].param.cyl.r;

	obj[7].type = CIR;
	obj[7].color = RED;
	obj[7].param.cir.c = v_add(obj[5].param.cyl.b, scalar_mult(obj[5].param.cyl.a, obj[5].param.cyl.h));
	obj[7].param.cir.n = obj[5].param.cyl.a;
	obj[7].param.cir.r = obj[5].param.cyl.r;

	obj[0].m = identity();
	obj[1].m = identity();
	obj[2].m = identity();
	obj[3].m = identity();
	obj[4].m = identity();
	obj[5].m = identity();
	obj[6].m = identity();
	obj[7].m = identity();

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
