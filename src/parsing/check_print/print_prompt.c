/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:19:48 by ewu               #+#    #+#             */
/*   Updated: 2025/03/09 19:43:31 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minirt.h"
#include <unistd.h>// for open, close, read, write
#include <stdio.h> // for printf, perror
#include <stdlib.h>// for malloc, free, exit

void	print_prompt(void)
{
	printf("\033[1;31m🌀Instruction for Keyboard and Mouse Activties.\033[0m\n");
	printf("\t\t\033[1;30mW-A-S-D-Q-E:\033[0m\n");
	printf("\t\t\033[34mdetail to add\033[0m\n");
	printf("\t\t\033[1;30m↑ ↓ → ← < >:\033[0m\n");
	printf("\t\t\033[34mdetail to add\033[0m\n");
	printf("\t\t\033[1;30mLeft Mouse Click:\033[0m\n");
	printf("\t\t\033[34mdetail to add\033[0m\n");
	printf("\t\t\033[1;30mScroll the wheel:\033[0m\n");
	printf("\t\t\033[34mdetail to add\033[0m\n");
	printf("\t\t\033[1;30m0 in Numeric Pad:\033[0m\n");
	printf("\t\t\033[34mdetail to add\033[0m\n");
	printf("\t\t\033[1;30mClick 'X' or Press 'ESC':\033[0m\n");
	printf("\t\t\033[34mExit this program!\033[0m\n");
}

// int	main(void)
// {
// 	print_prompt();
// 	return (0);
// }
