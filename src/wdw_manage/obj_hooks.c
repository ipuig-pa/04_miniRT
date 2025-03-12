/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:33:47 by ewu               #+#    #+#             */
/*   Updated: 2025/03/12 18:27:25 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
