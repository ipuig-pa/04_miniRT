/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:16:50 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/08 15:41:51 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mouse_button(int button, int x, int y, t_env *env)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		mouse_scroll(button, env);
	else if (button == CLICK_SELECT)
		mouse_click(x, y, env);
	return (0);
}

// scroll the wheel to zoom in(UP)/out(DOWN)
// edge case(0 && PI) check; +-3 is randomly set
//if its edge case, return(0) and nothing will be implemented
void	mouse_scroll(int button, t_env *env)
{
	float	rad;

	rad = to_rad(ZOOM);
	if (button == SCROLL_UP)
	{
		if ((env->scene->cam.fov - rad) <= 0)
			return ;
		env->scene->cam.fov -= rad;
	}
	else if (button == SCROLL_DOWN)
	{
		if ((env->scene->cam.fov + rad) >= M_PI)
			return ;
		env->scene->cam.fov += rad;
	}
	loq_rerender(env, true);
}

void	mouse_click(int x, int y, t_env *env)
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
		loq_rerender(env, false);
	}
}

int	mouse_move(int x, int y, t_env *env)
{
	static int	prev_x = WINDOW_WIDTH / 2;
	static int	prev_y = WINDOW_HEIGHT / 2;
	float		dlt_x;
	float		dlt_y;

	if (env->scene->select_obj >= 0)
	{
		dlt_x = x - prev_x;
		dlt_y = y - prev_y;
		prev_x = x;
		prev_y = y;
		//to rotate select_obj();
		//rerender();
		loq_rerender(env, false);
	}
	return (0);//else doing, just return
}
