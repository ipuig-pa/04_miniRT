/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:33:47 by ewu               #+#    #+#             */
/*   Updated: 2025/03/12 12:28:56 by ipuig-pa         ###   ########.fr       */
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

void	select_obj(int x, int y, t_env *env)
{
	t_ray	ray;
	t_hit	hit;

	cast_ray(&ray, y, x, env->scene);
	find_hit(&hit, ray, env->scene, -1);
	if (hit.occur == true)
	{
		if (env->scene->obj[hit.obj_id].type == CIR)
		{
			while (env->scene->obj[hit.obj_id].type != CYL)
				hit.obj_id--;
		}
		if (env->scene->select_obj == hit.obj_id)
			env->scene->select_obj = -1;
		else
			env->scene->select_obj = hit.obj_id;
		if (env->scene->select_light == true)
		{
			env->scene->select_light = false;
			env->scene->light.color = env->scene->light.store_col;
		}
	}
	else
		env->scene->select_obj = -1;
	loq_rerender(env, false);
}

void	move_obj(int key, t_env *env)
{
	t_obj	*obj;

	if (env->scene->select_obj != -1)
	{
		obj = &env->scene->obj[env->scene->select_obj];
		if (key == W)
			o_translate(obj, scalar_mult(env->scene->vp.up, TRANSL));
		else if (key == A)
			o_translate(obj, scalar_mult(env->scene->vp.right, -TRANSL));
		else if (key == S)
			o_translate(obj, scalar_mult(env->scene->vp.up, -TRANSL));
		else if (key == D)
			o_translate(obj, scalar_mult(env->scene->vp.right, TRANSL));
		else if (key == Q)
			o_translate(obj, scalar_mult(env->scene->vp.front, -TRANSL));
		else if (key == E)
			o_translate(obj, scalar_mult(env->scene->vp.front, TRANSL));
		loq_rerender(env, false);
	}
}

void	rotate_obj(int key, t_env *env)
{
	t_obj	*obj;
	float	rad;

	if (env->scene->select_obj != -1)
	{
		obj = &env->scene->obj[env->scene->select_obj];
		rad = to_rad(ROT);
		if (key == LEFT)
			o_rotate(obj, rad, env->scene->vp.up);
		else if (key == RIGHT)
			o_rotate(obj, -rad, env->scene->vp.up);
		else if (key == DOWN)
			o_rotate(obj, rad, env->scene->vp.right);
		else if (key == UP)
			o_rotate(obj, -rad, env->scene->vp.right);
		else if (key == S_LEFT)
			o_rotate(obj, -rad, env->scene->vp.front);
		else if (key == S_RIGHT)
			o_rotate(obj, rad, env->scene->vp.front);
		loq_rerender(env, false);
	}
}

void	scale_obj(int key, t_env *env)
{
	t_obj	*obj;

	if (env->scene->select_obj != -1)
	{
		obj = &env->scene->obj[env->scene->select_obj];
		if (obj->type == CYL && \
			(env->scene->select_height || env->scene->select_width))
			scale_cyl(key, env);
		else
		{
			obj = &env->scene->obj[env->scene->select_obj];
			if (key == KEY_PLUS || key == SCROLL_UP)
				o_scale(obj, SCALE, SCALE, SCALE);
			else if (key == KEY_MINUS || key == SCROLL_DOWN)
				o_scale(obj, 1.0 / SCALE, 1.0 / SCALE, 1.0 / SCALE);
		}
		loq_rerender(env, false);
	}
}

/*
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
}*/

/*
void	rotate_obj(t_obj *obj, float dx, float dy, t_viewport vp)
{
	float	rad;
	float	tan;
	float	tan30;
	float	tan60;

	tan60 = sqrtf(3.0);
	tan30 = 1.0 / tan60;
	tan = fabs(dy) / fabs(dx);
	rad = to_rad(ROT);
	if (dx < 0 || (dy > 0 && !(tan < tan60)))
	{
		if (dy > 0 || tan < tan30)
			rad = -rad;
	}
	if (tan < tan30)
		o_rotate(obj, ROT, vp.up);
	else if (tan < tan60)
		o_rotate(obj, ROT, vp.front);
	else
		o_rotate(obj, ROT, vp.right);
}*/
