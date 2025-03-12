/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:30:03 by ipuig-pa          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/12 12:24:29 by ewu              ###   ########.fr       */
=======
/*   Updated: 2025/03/12 18:27:01 by ipuig-pa         ###   ########.fr       */
>>>>>>> f9627b3d37caab1d10d0f626cc5fb370f63c772b
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
static void	print_prompt3(void)
{
	printf("\033[3;32mIf cylinder Width or Height are selected:\n\033[0m");
	printf("\033[34mScale just Width / Heigh of the cylinder.\n\033[0m");
	printf("\033[3;32mIf the Light is selected:\n\033[0m");
	printf("\033[34mChange the diffuse light ratio.\n\033[0m");
	printf("\033[3;32mIf nothing is selected:\n\033[0m");
	printf("\033[34mChange the environment light ratio.\n\033[0m");
	printf("\033[1;31m\nPress '0' in Numeric Pad:\033[0m\n");
	printf("\033[34mErase all changes made,\033[0m");
	printf("\033[34m and revert to original parsed scene.\033[0m\n");
	printf("\033[1;31m\nPress 'ESC' or Click 'X':\033[0m\n");
	printf("\033[34mExit this program!\033[0m\n");
}

static void	print_prompt2(void)
{
<<<<<<< HEAD
	printf(L_BLUE"↑: rotate UP\t\t↓: rotate DOWN\033[0m\n");
	printf(L_BLUE"←: rotate LEFT\t\t→: rotate RIGHT\033[0m\n");
	printf(L_BLUE">: rotate FORWARD\t<: rotate BACKARD\033[0m\n");
	printf(B_RED"\nScroll the wheel:\033[0m\n");
	printf(ITALIC"If some object has been selected:\n\033[0m");
	printf(L_BLUE"Scale the object.\n\033[0m");
	printf(ITALIC"Else if the Light is selected:\n\033[0m");
	printf(L_BLUE"Change the diffuse light ratio.\n\033[0m");
	printf(ITALIC"If nothing is selected:\033[0m\n");
	printf(L_BLUE"Zoom In and Out Camera\033[0m\n");
	printf(B_RED"\n+ AND -:\033[0m\n");
	printf(ITALIC"If some object has been selected:\n\033[0m");
	printf(L_BLUE"Scale the object.\n\033[0m");
	printf(ITALIC"Else if the Light is selected:\n\033[0m");
	printf(L_BLUE"Change the diffuse light ratio.\n\033[0m");
	printf(ITALIC"If nothing is selected:\n\033[0m");
	printf(L_BLUE"Change the environment light ratio.\n\033[0m");
	printf(B_RED"\nPress '0' in Numeric Pad:\033[0m\n");
	printf(L_BLUE"Erase all changes made,\033[0m");
	printf(L_BLUE" and revert to original scene.\033[0m\n");
	printf(B_RED"\nPress 'ESC' or Click 'X':\033[0m\n");
	printf(L_BLUE"Exit this program!\033[0m\n");
=======
	printf("\033[3;32mfollowing rotation will be applied to object.\033[0m\n");
	printf("\033[3;32mElse, rotation will be applied to Camera\033[0m\n");
	printf("\033[34mRotations:\033[0m\n");
	printf("\033[34m↑: tilt UP\t\t↓: tilt DOWN\033[0m\n");
	printf("\033[34m←: turn LEFT\t\t→: turn RIGHT\033[0m\n");
	printf("\033[34m<: roll LEFT\t\t>: roll RIGHT\033[0m\n");
	printf("\033[1;31m\nPress '*' in Numeric Pad\033[0m");
	printf("\033[1;31m, on a selected cylinder:\033[0m\n");
	printf("\033[34mSelect the width\033[0m\n");
	printf("\033[1;31m\nPress '/' in Numeric Pad\033[0m");
	printf("\033[1;31m, on a selected cylinder:\033[0m\n");
	printf("\033[34mSelect the height\033[0m\n");
	printf("\033[1;31m\nScroll the wheel:\033[0m\n");
	printf("\033[3;32mIf any object has been selected:\n\033[0m");
	printf("\033[34mScale the object.\n\033[0m");
	printf("\033[3;32mIf cylinder Width or Height are selected:\n\033[0m");
	printf("\033[34mScale just Width / Heigh of the cylinder.\n\033[0m");
	printf("\033[3;32mIf the Light is selected:\n\033[0m");
	printf("\033[34mChange the diffuse light ratio.\n\033[0m");
	printf("\033[3;32mIf nothing is selected:\033[0m\n");
	printf("\033[34mZoom In and Out Camera\033[0m\n");
	printf("\033[1;31m\n'+' and '-' in Numeric Pad:\033[0m\n");
	printf("\033[3;32mIf any object has been selected:\n\033[0m");
	printf("\033[34mScale the object.\n\033[0m");
	print_prompt3();
>>>>>>> f9627b3d37caab1d10d0f626cc5fb370f63c772b
}

static void	print_prompt(void)
{
<<<<<<< HEAD
	printf(PURPLE"\t\t\t🌀Instruction for Keyboard and ");
	printf("Mouse Activties🌀\n"RE);
	printf(ITALIC"NOTE:\nEverytime any change is made, \033[0m\n");
	printf(ITALIC"the scene will be rendered with low quality\033[0m");
	printf(ITALIC" for the reason of performance.\n\033[0m\n");
	printf(B_RED"Press 'SPACE':\033[0m\n");
	printf(L_BLUE"Render current scene with high quality.\n\n\033[0m");
	printf(B_RED"Left Mouse Click on Objects:\033[0m\n");
	printf(L_BLUE"Select the Object clicked\033[0m\n");
	printf(B_RED"\nPress L:\033[0m\n");
	printf(L_BLUE"Select Light\033[0m\n");
	printf(B_RED"\nW-A-S-D-Q-E:\033[0m\n");
	printf(ITALIC"If any object/light has been selected, \033[0m");
	printf(ITALIC"following movement will be applied to object\033[0m");
	printf(ITALIC"/light.\033[0m\n");
	printf(ITALIC"Else, movement will be applied to Camera\033[0m\n");
	printf(L_BLUE"W: move UP\t\tS: move DOWN\033[0m\n");
	printf(L_BLUE"A: move LEFT\t\tD: move RIGHT\033[0m\n");
	printf(L_BLUE"Q: move FORWARD\t\tE: move BACKARD\033[0m\n");
	printf(B_RED"\n↑ ↓ → ← < >:\033[0m\n");
	printf(ITALIC"If any object has been selected, \033[0m");
	printf(ITALIC"following rotation will be applied to object.\033[0m\n");
	printf(ITALIC"Else, rotation will be applied to Camera\033[0m\n");
=======
	printf("\t\t\t\033[1;35m🌀Instruction for Keyboard and \033[0m");
	printf("\033[1;35mMouse Activties🌀\033[0m\n");
	printf("\033[3;32mNOTE:\nWait until high quality image\033[0m");
	printf("\033[3;32m of the scene is rendered.\033[0m\n");
	printf("\033[3;32mEverytime any change is made,\n\033[0m");
	printf("\033[3;32mthe scene will be rendered with low quality\033[0m");
	printf("\033[3;32m for the reason of performance.\n\033[0m\n");
	printf("\033[1;31mPress 'SPACE':\033[0m\n");
	printf("\033[34mRender current scene with high quality.\n\n\033[0m");
	printf("\033[1;31mLeft Mouse Click on Objects:\033[0m\n");
	printf("\033[34mSelect the Object clicked\033[0m\n");
	printf("\033[1;31m\nPress 'L':\033[0m\n");
	printf("\033[34mSelect Light\033[0m\n");
	printf("\033[1;31m\n'W'-'A'-'S'-'D'-'Q'-'E':\033[0m\n");
	printf("\033[3;32mIf any object/light has been selected, \033[0m");
	printf("\033[3;32mfollowing movement will be applied to object\033[0m");
	printf("\033[3;32m/light.\033[0m\n");
	printf("\033[3;32mElse, movement will be applied to Camera\033[0m\n");
	printf("\033[34mTranslations:\033[0m\n");
	printf("\033[34mW: move UP\t\tS: move DOWN\033[0m\n");
	printf("\033[34mA: move LEFT\t\tD: move RIGHT\033[0m\n");
	printf("\033[34mQ: move FORWARD\t\tE: move BACKARD\033[0m\n");
	printf("\033[1;31m\n↑ ↓ → ← '<' '>':\033[0m\n");
	printf("\033[3;32mIf any object has been selected, \033[0m");
>>>>>>> f9627b3d37caab1d10d0f626cc5fb370f63c772b
	print_prompt2();
}

int	main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
<<<<<<< HEAD
		return (p_err("Error\nInvalid number of arguments! \
			A single rt file should be provided"), 1);
=======
	{
		p_err("Error\nInvalid number of arguments! \
			A single rt file should be provided");
		return (1);
	}
>>>>>>> f9627b3d37caab1d10d0f626cc5fb370f63c772b
	if (!parsing_scene(&env, av[1]))
		return (1);
	create_viewport(env.scene);
	init_env(&env);
	print_prompt();
	env.res.res = 10; //DELETE!! JUST TO GO FASTER IN DEBUGING
	ray_tracer(&env);
	mlx_put_image_to_window(env.mlx, env.mlx_window, env.img.img, 0, 0);
	set_hooks(&env);
	mlx_loop(env.mlx);
	return (0);
}
