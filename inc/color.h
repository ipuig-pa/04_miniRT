/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:47:07 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/10 13:29:29 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "env.h"
# include <stdbool.h>

# define BLACK ((t_color){{0, 0, 0, 0}})
# define WHITE ((t_color){{1, 1, 1, 0}})
# define RED ((t_color){{1, 0, 0, 0}})
# define GREEN ((t_color){{0, 1, 0, 0}})
# define BLUE ((t_color){{0, 0, 1, 0}})
# define PINK ((t_color){{1, 0, 1, 0}})
# define FILTER WHITE //or define when init the scene, so we can change it even in the parsing as a bonus??

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