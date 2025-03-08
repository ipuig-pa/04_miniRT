/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:44:08 by ewu               #+#    #+#             */
/*   Updated: 2025/03/08 10:52:36 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//⬆️⬇️ => pitch; ⬅️➡️ => yaw(rotate along vp.up axis)
//vector axis: the vectors of up, front and right of viewport
//rotate(): create 4x4 matrix based on GIVEN rad and axis
//change vp.up/right/front; vp.o UNCHANGED!

void	cam_rotate(t_camera *cam, float r, t_vector a)
{
	t_vector	ref;

	ref = cam->p;
	cam->v = v_transform(cam->v, m_multiply(m_multiply(translate(ref),rotate(r,a)),translate(invert_v(ref))), 'v');
}

// float: the sensitivity/speed of move
//change vp.o; vp-.up/right/front UNCHANGED!
void	cam_translate(t_camera *cam, t_vector tv)
{
	cam->p = v_transform(cam->p, translate(tv), 'p');
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