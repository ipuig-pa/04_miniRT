/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:19:48 by ewu               #+#    #+#             */
/*   Updated: 2025/03/10 20:39:46 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minirt.h"
#include <unistd.h>// for open, close, read, write
#include <stdio.h> // for printf, perror
#include <stdlib.h>// for malloc, free, exit

void	print_prompt_two(void)
{
	printf("\t\t\t\t\033[1;35mScroll the wheel:\033[0m\n");
	printf("\t\t\t\t\033[34mZoom In and Out\033[0m\n");
	printf("\t\t\t\t\033[1;35mPress '0' in Numeric Pad:\033[0m\n");
	printf("\t\t\t\t\033[34mErase all changes made,\033[0m");
	printf("\033[34m and revert to original scene.\033[0m\n");
	printf("\t\t\t\t\033[1;30mClick 'X' or Press 'ESC':\033[0m\n");
	printf("\t\t\t\t\033[34mExit this program!\033[0m\n");
}

void	print_prompt(void)
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
	print_prompt_two();
}

int	main(void)
{
	print_prompt();
	return (0);
}
