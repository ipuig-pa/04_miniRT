/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 08:56:13 by ewu               #+#    #+#             */
/*   Updated: 2025/03/08 15:02:31 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H
# include <stdbool.h>

# define ESC 53
# define SPACE 49
# define W 13
# define A 0
# define S 1
# define D 2
# define Q 12
# define E 14
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define S_LEFT 43 // <
# define S_RIGHT 47 // >
# define CLICK_SELECT 1
# define SCROLL_DOWN 4
# define SCROLL_UP 5
# define KEY_PLUS 69
# define KEY_MINUS 78
# define OBJ_F 89 //7 forward
# define OBJ_B 92 //9 back
# define OBJ_UP 91 //8 up
# define OBJ_D 87 //5 down
# define OBJ_L 86 //4 left
# define OBJ_R 88 //6 right

void	set_hooks(t_env *env);
int		mouse_scroll(int button, int x, int y, t_env *env);
int		mouse_click(int button, int x, int y, t_env *env);
int		mouse_move(int x, int y, t_env *env);
int		key_action(int keysym, t_env *env);
void	scale_obj(int keysym, t_scene *scene);
void	move_obj(int keysym, t_scene *scene);
void	loq_rerender(t_env *env, bool vp);
void	hiq_rerender(t_env *env);


#endif