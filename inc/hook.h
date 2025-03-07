/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 08:56:13 by ewu               #+#    #+#             */
/*   Updated: 2025/03/06 14:00:02 by ewu              ###   ########.fr       */
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

void	set_hooks(t_env *env);//go to main to init
void	mouse_scroll(int button, float xdelta, float ydelta, t_env *env);//tzoom
int		mouse_move(float xdelta, float ydelta, t_env *env);
void	key_action(int keysym, t_env *env);//direct to sub_func
void	rotate_camera(t_viewport *vp, float rad, t_vector axis);
void	move_camera(t_viewport *vp, t_vector direct, float distance);

#endif