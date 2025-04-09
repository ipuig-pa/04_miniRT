/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:30:03 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/04/09 16:10:49 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_prompt3(void)
{
	printf(ITALIC "If cylinder Width or Height are selected:\n"RE);
	printf(L_BLUE "Scale just Width / Heigh of the cylinder.\n"RE);
	printf(ITALIC "If the Light is selected:\n"RE);
	printf(L_BLUE "Change the diffuse light ratio.\n"RE);
	printf(ITALIC "If nothing is selected:\n"RE);
	printf(L_BLUE "Change the environment light ratio.\n"RE);
	printf(B_RED "\nPress '0' in Numeric Pad:\n"RE);
	printf(L_BLUE "Erase all changes made,");
	printf(L_BLUE " and revert to original parsed scene.\n"RE);
	printf(B_RED "\nPress 'ESC' or Click 'X':\n"RE);
	printf(L_BLUE "Exit this program!\n"RE);
}

static void	print_prompt2(void)
{
	printf(ITALIC "following rotation will be applied to object.\n"RE);
	printf(ITALIC "Else, rotation will be applied to Camera\n"RE);
	printf(L_BLUE "Rotations:\n"RE);
	printf(L_BLUE "↑: tilt UP\t\t↓: tilt DOWN\n"RE);
	printf(L_BLUE "←: turn LEFT\t\t→: turn RIGHT\n"RE);
	printf(L_BLUE "<: roll LEFT\t\t>: roll RIGHT\n"RE);
	printf(B_RED "\nPress '*' in Numeric Pad");
	printf(B_RED ", on a selected cylinder:\n"RE);
	printf(L_BLUE "Select the width\n"RE);
	printf(B_RED "\nPress '/' in Numeric Pad");
	printf(B_RED ", on a selected cylinder:\n"RE);
	printf(L_BLUE "Select the height\n"RE);
	printf(B_RED "\nScroll the wheel:\n"RE);
	printf(ITALIC "If any object has been selected:\n"RE);
	printf(L_BLUE "Scale the object.\n"RE);
	printf(ITALIC "If cylinder Width or Height are selected:\n"RE);
	printf(L_BLUE "Scale just Width / Heigh of the cylinder.\n"RE);
	printf(ITALIC "If the Light is selected:\n"RE);
	printf(L_BLUE "Change the diffuse light ratio.\n"RE);
	printf(ITALIC "If nothing is selected:\n"RE);
	printf(L_BLUE "Zoom In and Out Camera\n"RE);
	printf(B_RED "\n'+' and '-' in Numeric Pad:\n"RE);
	printf(ITALIC "If any object has been selected:\n"RE);
	printf(L_BLUE "Scale the object.\n"RE);
	print_prompt3();
}

static void	print_prompt(void)
{
	printf(PURPLE "\t\t\t🌀Instruction for Keyboard and ");
	printf("Mouse Activities🌀\n"RE);
	printf(ITALIC "NOTE:\nWait until high quality image"RE);
	printf(ITALIC " of the scene is rendered.\n"RE);
	printf(ITALIC "Everytime any change is made,\n"RE);
	printf(ITALIC "the scene will be rendered with low quality"RE);
	printf(ITALIC " for the reason of performance.\n\n"RE);
	printf(B_RED "Press 'SPACE':\n"RE);
	printf(L_BLUE "Render current scene with high quality.\n\n"RE);
	printf(B_RED "Left Mouse Click on Objects:\n"RE);
	printf(L_BLUE "Select or Deselect the Object clicked\n"RE);
	printf(B_RED "\nPress 'L':\n"RE);
	printf(L_BLUE "Select or Deselect Light\n"RE);
	printf(B_RED "\n'W'-'A'-'S'-'D'-'Q'-'E':\n"RE);
	printf(ITALIC "If any object/light has been selected, "RE);
	printf(ITALIC "following movement will be applied to object"RE);
	printf(ITALIC "/light.\n"RE);
	printf(ITALIC "Else, movement will be applied to Camera\n"RE);
	printf(L_BLUE "Translations:\n"RE);
	printf(L_BLUE "W: move UP\t\tS: move DOWN\n"RE);
	printf(L_BLUE "A: move LEFT\t\tD: move RIGHT\n"RE);
	printf(L_BLUE "Q: move FORWARD\t\tE: move BACWKARD\n"RE);
	printf(B_RED "\n↑ ↓ → ← '<' '>':\n"RE);
	printf(ITALIC "If any object has been selected, "RE);
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
