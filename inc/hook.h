/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 08:56:13 by ewu               #+#    #+#             */
/*   Updated: 2025/03/08 14:49:44 by ipuig-pa         ###   ########.fr       */
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
# define S_LEFT 43
# define S_RIGHT 47
# define CLICK_SELECT 1
# define SCROLL_DOWN 4
# define SCROLL_UP 5
# define DEFAULT_X

void	set_hooks(t_env *env);
int		mouse_scroll(int button, int x, int y, t_env *env);
int		mouse_click(int button, int x, int y, t_env *env);
int		mouse_move(int x, int y, t_env *env);
int		key_action(int keysym, t_env *env);
void	loq_rerender(t_env *env, bool vp);
void	hiq_rerender(t_env *env);


#endif