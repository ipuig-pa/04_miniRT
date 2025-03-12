/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:30:03 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 21:26:22 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_prompt3(void)
{
	printf(ITALIC "If cylinder Width or Height are selected:\n\033[0m");
	printf(L_BLUE "Scale just Width / Heigh of the cylinder.\n\033[0m");
	printf(ITALIC "If the Light is selected:\n\033[0m");
	printf(L_BLUE "Change the diffuse light ratio.\n\033[0m");
	printf(ITALIC "If nothing is selected:\n\033[0m");
	printf(L_BLUE "Change the environment light ratio.\n\033[0m");
	printf(B_RED "\nPress '0' in Numeric Pad:\033[0m\n");
	printf(L_BLUE "Erase all changes made,\033[0m");
	printf(L_BLUE " and revert to original parsed scene.\033[0m\n");
	printf(B_RED "\nPress 'ESC' or Click 'X':\033[0m\n");
	printf(L_BLUE "Exit this program!\033[0m\n");
}

static void	print_prompt2(void)
{
	printf(ITALIC "following rotation will be applied to object.\033[0m\n");
	printf(ITALIC "Else, rotation will be applied to Camera\033[0m\n");
	printf(L_BLUE "Rotations:\033[0m\n");
	printf(L_BLUE "↑: tilt UP\t\t↓: tilt DOWN\033[0m\n");
	printf(L_BLUE "←: turn LEFT\t\t→: turn RIGHT\033[0m\n");
	printf(L_BLUE "<: roll LEFT\t\t>: roll RIGHT\033[0m\n");
	printf(B_RED "\nPress '*' in Numeric Pad\033[0m");
	printf(B_RED ", on a selected cylinder:\033[0m\n");
	printf(L_BLUE "Select the width\033[0m\n");
	printf(B_RED "\nPress '/' in Numeric Pad\033[0m");
	printf(B_RED ", on a selected cylinder:\033[0m\n");
	printf(L_BLUE "Select the height\033[0m\n");
	printf(B_RED "\nScroll the wheel:\033[0m\n");
	printf(ITALIC "If any object has been selected:\n\033[0m");
	printf(L_BLUE "Scale the object.\n\033[0m");
	printf(ITALIC "If cylinder Width or Height are selected:\n\033[0m");
	printf(L_BLUE "Scale just Width / Heigh of the cylinder.\n\033[0m");
	printf(ITALIC "If the Light is selected:\n\033[0m");
	printf(L_BLUE "Change the diffuse light ratio.\n\033[0m");
	printf(ITALIC "If nothing is selected:\033[0m\n");
	printf(L_BLUE "Zoom In and Out Camera\033[0m\n");
	printf(B_RED "\n'+' and '-' in Numeric Pad:\033[0m\n");
	printf(ITALIC "If any object has been selected:\n\033[0m");
	printf(L_BLUE "Scale the object.\n\033[0m");
	print_prompt3();
}

static void	print_prompt(void)
{
	printf(PURPLE "\t\t\t🌀Instruction for Keyboard and ");
	printf("Mouse Activties🌀\033[0m\n");
	printf(ITALIC "NOTE:\nWait until high quality image\033[0m");
	printf(ITALIC " of the scene is rendered.\033[0m\n");
	printf(ITALIC "Everytime any change is made,\n\033[0m");
	printf(ITALIC "the scene will be rendered with low quality\033[0m");
	printf(ITALIC " for the reason of performance.\n\033[0m\n");
	printf(B_RED "Press 'SPACE':\033[0m\n");
	printf(L_BLUE "Render current scene with high quality.\n\n\033[0m");
	printf(B_RED "Left Mouse Click on Objects:\033[0m\n");
	printf(L_BLUE "Select the Object clicked\033[0m\n");
	printf(B_RED "\nPress 'L':\033[0m\n");
	printf(L_BLUE "Select Light\033[0m\n");
	printf(B_RED "\n'W'-'A'-'S'-'D'-'Q'-'E':\033[0m\n");
	printf(ITALIC "If any object/light has been selected, \033[0m");
	printf(ITALIC "following movement will be applied to object\033[0m");
	printf(ITALIC "/light.\033[0m\n");
	printf(ITALIC "Else, movement will be applied to Camera\033[0m\n");
	printf(L_BLUE "Translations:\033[0m\n");
	printf(L_BLUE "W: move UP\t\tS: move DOWN\033[0m\n");
	printf(L_BLUE "A: move LEFT\t\tD: move RIGHT\033[0m\n");
	printf(L_BLUE "Q: move FORWARD\t\tE: move BACKARD\033[0m\n");
	printf(B_RED "\n↑ ↓ → ← '<' '>':\033[0m\n");
	printf(ITALIC "If any object has been selected, \033[0m");
	print_prompt2();
}

int	main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
	{
		p_err("Error\nInvalid number of arguments! \
			A single rt file should be provided");
		return (1);
	}
	if (!parsing_scene(&env, av[1]))
		return (1);
	create_viewport(env.scene);
	init_env(&env);
	print_prompt();
	ray_tracer(&env);
	mlx_put_image_to_window(env.mlx, env.mlx_window, env.img.img, 0, 0);
	set_hooks(&env);
	mlx_loop(env.mlx);
	return (0);
}

// env.res.res = 10; ==> for 0313 debugging
// DELETE!! JUST TO GO FASTER IN DEBUGING
// // static void	print_all(t_scene *scene) //TESTING, TO COMMENT!!
// // {
// // 	int	i;

// // 	i = 0;
// // 	printf("--------------------------MAIN--------------------------\n");
// // 	printf("AMB: rat: %f; col: %f, %f, %f. %f\n", scene->amblight.ratio,
// 		scene->amblight.color.rgba[0], scene->amblight.color.rgba[1],
// 		scene->amblight.color.rgba[2], scene->amblight.color.rgba[3]);
// // 	printf("CAM: point: %f, %f, %f, %f; vect: %f, %f, %f, %f; fov: %f\n",
// 		scene->cam.p.x,  scene->cam.p.y,  scene->cam.p.z, scene->cam.p.w,
// 		scene->cam.v.x,  scene->cam.v.y,  scene->cam.v.z, scene->cam.v.w,
// 		scene->cam.fov);
// // 	printf("LIG: point: %f, %f, %f, %f, rat: %f; col: %f, %f, %f, %f\n",
// 		scene->light.p.x,  scene->light.p.y,  scene->light.p.z,
// 		scene->light.p.w, scene->light.ratio, scene->light.color.s_comp.r,
// 		scene->light.color.s_comp.g, scene->light.color.s_comp.b,
// 		scene->light.color.s_comp.a);
// // 	printf("OBJ: num: %i\n", scene->obj_num);
// // 	while (i < scene->obj_num)
// // 	{
// // 		printf("OBJ %i: type:%i, color: %f, %f, %f, %f, material: %i\n", i,
// 			scene->obj[i].type, scene->obj[i].color.rgba[0],
// 			scene->obj[i].color.rgba[1], scene->obj[i].color.rgba[2],
// 			scene->obj[i].color.rgba[3], scene->obj[i].mat.type);
// // 		if (scene->obj[i].type == CIR)
// // 			printf("CIR: c: %f, %f, %f, %f; n: %f, %f, %f, %f; r: %f \n",
// 				scene->obj[i].param.cir.c.x, scene->obj[i].param.cir.c.y,
// 				scene->obj[i].param.cir.c.z, scene->obj[i].param.cir.c.w,
// 				scene->obj[i].param.cir.n.x,  scene->obj[i].param.cir.n.y,
// 					scene->obj[i].param.cir.n.z,  scene->obj[i].param.cir.n.w,
// 					scene->obj[i].param.cir.r);
// // 		if (scene->obj[i].type == CYL)
// // 			printf("CYL: c: %f, %f, %f, %f; b: %f, %f, %f, %f; a: \
//%f, %f, %f,
// 				%f; r: %f, a: %f\n", scene->obj[i].param.cyl.c.x,
// 				scene->obj[i].param.cyl.c.y, scene->obj[i].param.cyl.c.z,
// 				scene->obj[i].param.cyl.c.w, scene->obj[i].param.cyl.b.x,
// 				scene->obj[i].param.cyl.b.y, scene->obj[i].param.cyl.b.z,
// 				scene->obj[i].param.cyl.b.w, scene->obj[i].param.cyl.a.x,
// 				scene->obj[i].param.cyl.a.y, scene->obj[i].param.cyl.a.z,
// 				scene->obj[i].param.cyl.a.w, scene->obj[i].param.cyl.r,
// 				scene->obj[i].param.cyl.h);
// // 		if (scene->obj[i].type == SPH)
// // 			printf("SPH: c: %f, %f, %f, %f; r: %f\n",
// 				scene->obj[i].param.sph.c.x, scene->obj[i].param.sph.c.y,
// 				scene->obj[i].param.sph.c.z, scene->obj[i].param.sph.c.w,
// 				scene->obj[i].param.sph.r);
// // 		if (scene->obj[i].type == PL)
// // 			printf("PL: p: %f, %f, %f, %f; n: %f, %f, %f, %f\n",
// 				scene->obj[i].param.pl.p.x, scene->obj[i].param.pl.p.y,
// 				scene->obj[i].param.pl.p.z, scene->obj[i].param.pl.p.w,
// 				scene->obj[i].param.pl.n.x, scene->obj[i].param.pl.n.y,
// 				scene->obj[i].param.pl.n.z, scene->obj[i].param.pl.n.w);
// // 		i++;
// // 	}
// // }