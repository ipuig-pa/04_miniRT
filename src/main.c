/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:30:03 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 14:30:58 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static void	print_all(t_scene *scene) //TESTING, TO COMMENT!!
// {
// 	int	i;

// 	i = 0;
// 	printf("--------------------------MAIN--------------------------\n");
// 	printf("AMB: rat: %f; col: %f, %f, %f. %f\n", scene->amblight.ratio, scene->amblight.color.rgba[0], scene->amblight.color.rgba[1], scene->amblight.color.rgba[2], scene->amblight.color.rgba[3]);
// 	printf("CAM: point: %f, %f, %f, %f; vect: %f, %f, %f, %f; fov: %f\n", scene->cam.p.x,  scene->cam.p.y,  scene->cam.p.z, scene->cam.p.w, scene->cam.v.x,  scene->cam.v.y,  scene->cam.v.z, scene->cam.v.w, scene->cam.fov);
// 	printf("LIG: point: %f, %f, %f, %f, rat: %f; col: %f, %f, %f, %f\n", scene->light.p.x,  scene->light.p.y,  scene->light.p.z, scene->light.p.w, scene->light.ratio, scene->light.color.s_comp.r, scene->light.color.s_comp.g, scene->light.color.s_comp.b, scene->light.color.s_comp.a);
// 	printf("OBJ: num: %i\n", scene->obj_num);
// 	while (i < scene->obj_num)
// 	{
// 		printf("OBJ %i: type:%i, color: %f, %f, %f, %f, material: %i\n", i, scene->obj[i].type, scene->obj[i].color.rgba[0], scene->obj[i].color.rgba[1], scene->obj[i].color.rgba[2], scene->obj[i].color.rgba[3], scene->obj[i].mat.type);
// 		if (scene->obj[i].type == CIR)
// 			printf("CIR: c: %f, %f, %f, %f; n: %f, %f, %f, %f; r: %f \n", scene->obj[i].param.cir.c.x, scene->obj[i].param.cir.c.y, scene->obj[i].param.cir.c.z, scene->obj[i].param.cir.c.w, scene->obj[i].param.cir.n.x,  scene->obj[i].param.cir.n.y,  scene->obj[i].param.cir.n.z,  scene->obj[i].param.cir.n.w,  scene->obj[i].param.cir.r);
// 		if (scene->obj[i].type == CYL)
// 			printf("CYL: c: %f, %f, %f, %f; b: %f, %f, %f, %f; a: %f, %f, %f, %f; r: %f, a: %f\n", scene->obj[i].param.cyl.c.x, scene->obj[i].param.cyl.c.y, scene->obj[i].param.cyl.c.z, scene->obj[i].param.cyl.c.w, scene->obj[i].param.cyl.b.x, scene->obj[i].param.cyl.b.y, scene->obj[i].param.cyl.b.z, scene->obj[i].param.cyl.b.w, scene->obj[i].param.cyl.a.x, scene->obj[i].param.cyl.a.y, scene->obj[i].param.cyl.a.z, scene->obj[i].param.cyl.a.w, scene->obj[i].param.cyl.r, scene->obj[i].param.cyl.h);
// 		if (scene->obj[i].type == SPH)
// 			printf("SPH: c: %f, %f, %f, %f; r: %f\n", scene->obj[i].param.sph.c.x, scene->obj[i].param.sph.c.y, scene->obj[i].param.sph.c.z, scene->obj[i].param.sph.c.w, scene->obj[i].param.sph.r);
// 		if (scene->obj[i].type == PL)
// 			printf("PL: p: %f, %f, %f, %f; n: %f, %f, %f, %f\n", scene->obj[i].param.pl.p.x, scene->obj[i].param.pl.p.y, scene->obj[i].param.pl.p.z, scene->obj[i].param.pl.p.w, scene->obj[i].param.pl.n.x, scene->obj[i].param.pl.n.y, scene->obj[i].param.pl.n.z, scene->obj[i].param.pl.n.w);
// 		i++;
// 	}
// }


static void	print_instruct(void)
{
	printf("TO DO\n"); //WRITE INSTRUCTIONS ON HOOKS
}

int	main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		return (p_err("Invalid number of arguments! A single rt file should be provided"), 1);
	if (!parsing_scene(&env, av[1]))
		return (1);
	create_viewport(env.scene);
	init_env(&env);
	// print_all(env.scene);
	ray_tracer(&env);
	mlx_put_image_to_window(env.mlx, env.mlx_window, env.img.img, 0, 0);
	set_hooks(&env); //hooks (rotation, translation, etc)
	print_instruct();
	mlx_loop(env.mlx);
	return (0);
}
