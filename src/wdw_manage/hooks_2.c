/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:44:08 by ewu               #+#    #+#             */
/*   Updated: 2025/03/07 10:44:16 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


//⬆️⬇️ => pitch; ⬅️➡️ => yaw(rotate along vp.up axis)
//vector axis: the vectors of up, front and right of viewport
//rotate(): create 4x4 matrix based on GIVEN rad and axis
//change vp.up/right/front; vp.o UNCHANGED!
void	rotate_cam(t_viewport *vp, float rad, t_vector axis)
{
	t_matrix4	rot_m;

	rot_m = rotate(rad, axis);
	vp->front = v_transform(vp->front, rot_m);
	vp->right = v_transform(vp->right, rot_m);
	vp->up = v_transform(vp->up, rot_m);
}

// float: the sensitivity/speed of move
//change vp.o; vp-.up/right/front UNCHANGED!
void	move_cam(t_viewport *vp, t_vector direct, float distance)
{
	t_vector	mv;

	mv = scalar_mult(direct, distance);
	vp->o = v_add(vp->o, mv);
}

//TO IMPLEMENT!!!
void	save_picture(void)
{
	
}

/**
typedef struct s_vector // w = 0 for vector and w = 1 for point
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vector;
typedef struct s_viewport
{
	t_vector	front;
	t_vector	right;
	t_vector	up;
	t_vector	o;
	float		px_space;
}				t_viewport;
 */