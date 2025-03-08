/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:33:47 by ewu               #+#    #+#             */
/*   Updated: 2025/03/08 16:14:04 by ipuig-pa         ###   ########.fr       */
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
void	scale_obj(t_env *env, int key)
{
	t_obj	*obj;

	if (env->scene->select_obj != -1)
	{
		obj = &env->scene->obj[env->scene->select_obj];
		if (key == KEY_PLUS)
			o_scale(obj, SCALE, SCALE, SCALE);
		else if (key == KEY_MINUS)
			o_scale(obj, 1.0 / SCALE, 1.0 / SCALE, 1.0 / SCALE);
		loq_rerender(env, false);
	}
}

void	move_obj(t_env *env, int key)
{
	t_obj	*obj;

	if (env->scene->select_obj != -1)
	{
		obj = &env->scene->obj[env->scene->select_obj];
		if (key == OBJ_F)
			o_translate(obj, scalar_mult(env->scene->vp.front, -TRANSL));
		else if (key == OBJ_B)
			o_translate(obj, scalar_mult(env->scene->vp.front, TRANSL));
		else if (key == OBJ_UP)
			o_translate(obj, scalar_mult(env->scene->vp.up, TRANSL));
		else if (key == OBJ_D)
			o_translate(obj, scalar_mult(env->scene->vp.up, -TRANSL));
		else if (key == OBJ_R)
			o_translate(obj, scalar_mult(env->scene->vp.right, TRANSL));
		else if (key == OBJ_L)
			o_translate(obj, scalar_mult(env->scene->vp.right, -TRANSL));
		loq_rerender(env, false);
	}
}
