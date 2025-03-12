/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:47:07 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 18:06:21 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "env.h"
# include <stdbool.h>

typedef union u_color
{
	struct s_comp
	{
		float	r;
		float	g;
		float	b;
		float	a;
	}			s_comp;
	float	rgba[4];
}			t_color;

void	my_pixel_put(t_env *env, int x, int y, int color);
void	clamp_col(t_color *color);
int		convert_rgba(t_color *color);
t_color	col_prod(t_color c1, t_color c2);
t_color	col_sc_prod(t_color c, float s);
t_color	col_add(t_color c1, t_color c2);
t_color	set_color(float r, float g, float b, float a);
bool	is_white(t_color col);
t_color	complementary(t_color col);

#endif