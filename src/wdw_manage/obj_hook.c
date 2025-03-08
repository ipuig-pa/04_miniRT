/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:33:47 by ewu               #+#    #+#             */
/*   Updated: 2025/03/08 14:45:34 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// typedef struct s_ray
// {
// 	t_vector	o; //origin point. these will keep changing as the ray is reflected, refracted or absorbed
// 	t_vector	d; //direction (unitary vector)
// 	t_color		color; //in hex
// 	// bool		end; //?? neeeded?
// }			t_ray;

// typedef struct s_hit
// {
// 	t_vector	p;
// 	t_vector	real_p;
// 	int			obj_id; //then, they have to be in an array, not a linked list
// 	float		dist; //distance from the camera to the point of intersection
// 	float		light_dist; //distance from the hit point to the light
// 	bool		occur;
// 	t_vector	normal;
// }			t_hit;
/**
 * CLICK: to select
 * MOVE: to rot
 * KEYS: +/- tp scale
*/
int	mouse_click(int button, int x, int y, t_env *env)
{
	t_ray	ray;
	t_hit	hit;

	if (button == CLICK_SELECT)
	{
		hit.occur = false;
		cast_ray(&ray, y, x, env->scene);//get ray from coord of obj
		find_hit(&hit, ray, env->scene, -1);
		if (hit.occur == true)
		{
			env->scene->select_obj = env->scene->obj[hit.obj_id];
		}
	}
	return (0);
}

int	mouse_move(int x, int y, t_env *env)
{
	static int	prev_x = WINDOW_WIDTH / 2;
	static int	prev_y = WINDOW_HEIGHT / 2;
	float		dlt_x;
	float		dlt_y;

	dlt_x = x - prev_x;
	dlt_y = y - prev_y;
	prev_x = x;
	prev_y = y;
	if (&env->scene->select_obj)
	{
		//to rotate select_obj();
		//rerender();
	}
	return (0);//else doing, just return
}
