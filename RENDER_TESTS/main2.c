/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:30:03 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/07 15:44:14 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_all(t_scene *scene) //TESTING, TO COMMENT!!
{
	int	i;

	i = 0;
	printf("--------------------------MAIN--------------------------\n");
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

int	main(void)
{
	t_env		env;
	t_scene		scene;
	t_obj		obj[5];

	init_env(&env);
	scene.obj_num = 5;

	obj[0].type = SPH;
	obj[0].color = PINK;
	obj[0].mat.type = MATTE;
	obj[0].param.sph.c = v_create(0.0, 0.0, -200.0, 1.0);
	obj[0].param.sph.r = 5.0;

	// obj[1].type = SPH;
	// obj[1].color = RED;
	// obj[1].mat.type = MET;
	// obj[1].param.sph.c = v_create(0.0, 20.0, -200.0, 1.0);
	// obj[1].param.sph.r = 2.5;

	obj[1].type = PL;
	obj[1].color = BLUE;
	obj[1].mat.type = MATTE;
	obj[1].param.pl.p = v_create(0.0, -7.0, 0.0, 1.0);
	obj[1].param.pl.n = v_create(0.0, 1.0, 0.0, 0.0);

	// obj[3].type = PL;
	// obj[3].color = GREEN;
	// obj[3].mat.type = MET;
	// obj[3].param.pl.n = v_create(0.0, 0.0, 1.0, 0.0);
	// obj[3].param.pl.p = v_create(0.0, 0.0, -250.0, 1.0);

	// obj[4].type = PL;
	// obj[4].color = PINK;
	// obj[4].mat.type = PLA;
	// obj[4].param.pl.n = v_create(1.0, 0.0, 0.0, 0.0);
	// obj[4].param.pl.p = v_create(-7.0, 0.0, 0.0, 1.0);

	obj[2].type = CYL;
	obj[2].color = RED;
	obj[2].mat.type = MATTE;
	obj[2].param.cyl.c = v_create(2.0, 3.0, -150.0, 1.0);
	obj[2].param.cyl.a = unit_v(v_create(0.0, 1.0, 1.0, 0.0));
	obj[2].param.cyl.r = 1.5;
	obj[2].param.cyl.h = 10.0;
	obj[2].param.cyl.b = v_subt(obj[2].param.cyl.c, scalar_mult(obj[2].param.cyl.a, obj[2].param.cyl.h / 2));

	obj[3].type = CIR;
	obj[3].color = RED;
	obj[3].mat.type = obj[2].mat.type;
	obj[3].param.cir.c = obj[2].param.cyl.b;
	obj[3].param.cir.n = invert_v(obj[2].param.cyl.a);
	obj[3].param.cir.r = obj[2].param.cyl.r;

	obj[4].type = CIR;
	obj[4].color = RED;
	obj[4].mat.type = obj[2].mat.type;
	obj[4].param.cir.c = v_add(obj[2].param.cyl.b, scalar_mult(obj[2].param.cyl.a, obj[2].param.cyl.h));
	obj[4].param.cir.n = obj[2].param.cyl.a;
	obj[4].param.cir.r = obj[2].param.cyl.r;

	obj[0].m = identity();
	obj[1].m = identity();
	obj[2].m = identity();
	obj[3].m = identity();
	obj[4].m = identity();
	// obj[5].m = identity();
	// obj[6].m = identity();
	// obj[7].m = identity();

	int	i = 0;
	while (i < scene.obj_num)
	{
		get_material(&obj[i]);
		i++;
	}

	scene.obj = obj;

	scene.amblight.color = WHITE;
	scene.amblight.ratio = 0.1;

	scene.cam.p = v_create(0.0, 0.0, 0.0, 1.0);
	scene.cam.v = v_create(0.0, 0.0, -1.0, 0.0);
	scene.cam.fov = 0.5;

	scene.light.p = v_create (2.0, 3.0, -140.0, 1.0);
	scene.light.ratio = 0.6;
	scene.light.color = WHITE;

	env.scene = &scene;

	print_all(env.scene);
	ray_tracer(&env);
	mlx_put_image_to_window(env.mlx, env.mlx_window, env.img.img, 0, 0);
	mlx_loop(env.mlx);
	return (0);
}
