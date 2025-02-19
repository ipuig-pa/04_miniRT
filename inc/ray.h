/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:52:45 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/19 12:57:30 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "linalg.h"

typedef struct s_ray
{
	t_point		p; //these will keep changing as the ray is reflected, refracted or absorbed
	t_vector	v;
	int			color; //in hex
	bool		end;
}			t_ray;

#endif