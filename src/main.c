/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:30:03 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/11 10:31:25 by ipuig-pa         ###   ########.fr       */
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

//MISSING: 
//+ and - have the same effect of scrolling to scale objects / change light ratio (think about env light ratio?!?)
//when nothing is selected scroll is camera zoom and + and - is cahnge env ratio light
//space to rerender in hight quality (sentence for performance reasor, while manipulating it will loose quality)
//Put it alineated without tabs? Just the title?
//
static void	print_prompt2(void)
{
	printf("\t\t\t\t\033[1;35mScroll the wheel:\033[0m\n");
	printf("\t\t\t\t\033[34mZoom In and Out\033[0m\n");
	printf("\t\t\t\t\033[1;35mPress '0' in Numeric Pad:\033[0m\n");
	printf("\t\t\t\t\033[34mErase all changes made,\033[0m");
	printf("\033[34m and revert to original scene.\033[0m\n");
	printf("\t\t\t\t\033[1;30mClick 'X' or Press 'ESC':\033[0m\n");
	printf("\t\t\t\t\033[34mExit this program!\033[0m\n");
}

static void	print_prompt(void)
{
	printf("\t\t\t\033[1;31m🌀Instruction for Keyboard and \033[0m");
	printf("\033[1;31mMouse Activties🌀\033[0m\n");
	printf("\t\t\t\t\033[1;35mLeft Mouse Click on Objects:\033[0m\n");
	printf("\t\t\t\t\033[34mWill Select the Object clicked\033[0m\n");
	printf("\t\t\t\t\033[1;35mPress L:\033[0m\n");
	printf("\t\t\t\t\033[34mWill Select Light\033[0m\n");
	printf("\t\t\t\t\033[1;35mW-A-S-D-Q-E:\033[0m\n");
	printf("\t\t\t\t\033[32mIf any object/light has been selected, \033[0m");
	printf("\033[32mfollowing movement will be applied to object\033[0m");
	printf("\033[32m/light.\033[0m\n");
	printf("\t\t\t\t\033[32mElse, movement will be applied to Camera\033[0m\n");
	printf("\t\t\t\t\033[34mW: move UP\tS: move DOWN\033[0m\n");
	printf("\t\t\t\t\033[34mA: move LEFT\tD: move RIGHT\033[0m\n");
	printf("\t\t\t\t\033[34mQ: move FORWARD\tE: move BACKARD\033[0m\n");
	printf("\t\t\t\t\033[1;35m↑ ↓ → ← < >:\033[0m\n");
	printf("\t\t\t\t\033[32mIf any object has been selected, \033[0m");
	printf("\033[32mfollowing rotation will be applied to object.\033[0m\n");
	printf("\t\t\t\t\033[32mElse, rotation will be applied to Camera\033[0m\n");
	printf("\t\t\t\t\033[34m↑: rotate UP\t\t↓: rotate DOWN\033[0m\n");
	printf("\t\t\t\t\033[34m←: rotate LEFT\t\t→: rotate RIGHT\033[0m\n");
	printf("\t\t\t\t\033[34m>: rotate FORWARD\t<: rotate BACKARD\033[0m\n");
	print_prompt2();
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
	print_prompt();
	mlx_loop(env.mlx);
	return (0);
}
