/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 08:56:13 by ewu               #+#    #+#             */
/*   Updated: 2025/03/11 10:20:18 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H
# include <stdbool.h>
# include "env.h"
# include "scene.h"

//MAC
# define ESC 53
# define SPACE 49
# define W 13
# define A 0
# define S 1
# define D 2
# define Q 12
# define E 14
# define L 37
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
# define KEY_REVERT 82 //0

// # define OBJ_F 89 //7 forward
// # define OBJ_B 92 //9 back
// # define OBJ_UP 91 //8 up
// # define OBJ_D 87 //5 down
// # define OBJ_R 88 //6 right
// # define OBJ_L 86 //4 left


// //WINDOWS
// # define ESC 27
// # define SPACE 32
// # define W 87
// # define A 65
// # define S 83
// # define D 68
// # define Q 81
// # define E 69
// # define L 76
// # define LEFT 37
// # define RIGHT 39
// # define DOWN 40
// # define UP 38
// # define S_LEFT 49 // 1
// # define S_RIGHT 50 // 2
// # define CLICK_SELECT 1
// # define SCROLL_DOWN 4
// # define SCROLL_UP 5
// # define KEY_PLUS 107
// # define KEY_MINUS 109


// //LINUX
// # define ESC 65307        // Escape key
// # define SPACE 32         // Space bar
// # define W 119            // W key
// # define A 97             // A key
// # define S 115            // S key 
// # define D 100            // D key
// # define Q 113            // Q key
// # define E 101            // E key
// # define L 108            // L key
// # define LEFT 65361       // Left arrow
// # define RIGHT 65363      // Right arrow
// # define DOWN 65364       // Down arrow
// # define UP 65362         // Up arrow
// # define S_LEFT 18        // 1 key
// # define S_RIGHT 19       // 2 key
// # define CLICK_SELECT 1   // Mouse click (typically unchanged)
// # define SCROLL_DOWN 4    // Mouse scroll (typically unchanged)
// # define SCROLL_UP 5      // Mouse scroll (typically unchanged)
// # define KEY_PLUS 43      // + key
// # define KEY_MINUS 45     // - key 
//# define KEY_REVERT

void	set_hooks(t_env *env);
int		key_action(int keysym, t_env *env);
int		mouse_button(int button, int x, int y, t_env *env);
int		close_window(t_env *env);

//element hooks
void	move_elem(int key, t_env *env);
void	rotate_elem(int key, t_env *env);
void	scale_elem(int key, t_env *env);

//object hooks
void	select_obj(int x, int y, t_env *env);
void	scale_obj(int key, t_env *env);
void	move_obj(int key, t_env *env);
void	rotate_obj(int key, t_env *env);

//camera hooks
void	move_cam(int key, t_env *env);
void	rotate_cam(int key, t_env *env);
void	zoom(int key, t_env *env);

//light hooks
void	select_light(t_env *env);
void	move_light(int key, t_env *env);
void	scale_light(int key, t_env *env);

//rerender
void	loq_rerender(t_env *env, bool vp);
void	hiq_rerender(t_env *env);
void	revert_scene(t_env *env);

#endif