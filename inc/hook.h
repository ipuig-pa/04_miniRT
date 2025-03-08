/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 08:56:13 by ewu               #+#    #+#             */
/*   Updated: 2025/03/08 10:29:53 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# define ESC 53
# define SPACE 49
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
// # define CLICK 1
# define SCROLL_DOWN 4
# define SCROLL_UP 5

void	set_hooks(t_env *env);
int		mouse_scroll(int button, int xdelta, int ydelta, t_env *env);
int		mouse_move(int xdelta, int ydelta, t_env *env);
int		key_action(int keysym, t_env *env);
void	save_picture(void); // to implement!?!??

#endif