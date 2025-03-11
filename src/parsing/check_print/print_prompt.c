/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:19:48 by ewu               #+#    #+#             */
/*   Updated: 2025/03/11 12:40:23 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minirt.h"
#include <unistd.h>// for open, close, read, write
#include <stdio.h> // for printf, perror
#include <stdlib.h>// for malloc, free, exit

void	print_prompt_two(void)
{
	printf("\033[34m↑: rotate UP\t\t↓: rotate DOWN\033[0m\n");
	printf("\033[34m←: rotate LEFT\t\t→: rotate RIGHT\033[0m\n");
	printf("\033[34m>: rotate FORWARD\t<: rotate BACKARD\033[0m\n");
	printf("\033[1;31m\nScroll the wheel:\033[0m\n");
	printf("\033[3;32mIf some object has been selected:\n\033[0m");
	printf("\033[34mScale the object.\n\033[0m");
	printf("\033[3;32mElse if the Light is selected:\n\033[0m");
	printf("\033[34mChange the diffuse light ratio.\n\033[0m");
	printf("\033[3;32mIf nothing is selected:\033[0m\n");
	printf("\033[34mZoom In and Out Camera\033[0m\n");
	printf("\033[1;31m\n+ AND -:\033[0m\n");
	printf("\033[3;32mIf some object has been selected:\n\033[0m");
	printf("\033[34mScale the object.\n\033[0m");
	printf("\033[3;32mElse if the Light is selected:\n\033[0m");
	printf("\033[34mChange the diffuse light ratio.\n\033[0m");
	printf("\033[3;32mIf nothing is selected:\n\033[0m");
	printf("\033[34mChange the environment light ratio.\n\033[0m");
	printf("\033[1;31m\nPress '0' in Numeric Pad:\033[0m\n");
	printf("\033[34mErase all changes made,\033[0m");
	printf("\033[34m and revert to original scene.\033[0m\n");
	printf("\033[1;31m\nPress 'ESC' or Click 'X':\033[0m\n");
	printf("\033[34mExit this program!\033[0m\n");
}

void	print_prompt(void)
{
	printf("\t\t\t\033[1;35m🌀Instruction for Keyboard and \033[0m");
	printf("\033[1;35mMouse Activties🌀\033[0m\n");
	printf("\033[3;32mNOTE:\nEverytime any change is made, \033[0m\n");
	printf("\033[3;32mthe scene will be rendered with low quality\033[0m");
	printf("\033[3;32m for the reason of performance.\n\033[0m\n");
	printf("\033[1;31mPress 'SPACE':\033[0m\n");
	printf("\033[34mRender current scene with high quality.\n\n\033[0m");
	printf("\033[1;31mLeft Mouse Click on Objects:\033[0m\n");
	printf("\033[34mSelect the Object clicked\033[0m\n");
	printf("\033[1;31m\nPress L:\033[0m\n");
	printf("\033[34mSelect Light\033[0m\n");
	printf("\033[1;31m\nW-A-S-D-Q-E:\033[0m\n");
	printf("\033[3;32mIf any object/light has been selected, \033[0m");
	printf("\033[3;32mfollowing movement will be applied to object\033[0m");
	printf("\033[3;32m/light.\033[0m\n");
	printf("\033[3;32mElse, movement will be applied to Camera\033[0m\n");
	printf("\033[34mW: move UP\t\tS: move DOWN\033[0m\n");
	printf("\033[34mA: move LEFT\t\tD: move RIGHT\033[0m\n");
	printf("\033[34mQ: move FORWARD\t\tE: move BACKARD\033[0m\n");
	printf("\033[1;31m\n↑ ↓ → ← < >:\033[0m\n");
	printf("\033[3;32mIf any object has been selected, \033[0m");
	printf("\033[3;32mfollowing rotation will be applied to object.\033[0m\n");
	printf("\033[3;32mElse, rotation will be applied to Camera\033[0m\n");
	print_prompt_two();
}

int	main(void)
{
	print_prompt();
	return (0);
}
