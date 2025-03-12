/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:47:07 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/12 19:40:55 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "env.h"
# include <stdbool.h>
# define ITALIC "\033[3;32m"
# define L_BLUE "\033[34m"
# define RE "\033[0m"	
# define PURPLE "\033[1;35m"
# define B_RED "\033[1;31m"

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