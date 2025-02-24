/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:36:32 by ewu               #+#    #+#             */
/*   Updated: 2025/02/24 16:02:51 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*parse sp, cy, pl funcs*/

//include obj circle (cir), and for each cyl, create 2 objects circles:
// * one with c = b (center at the base of the cylinder, being the base of the cylinder: c - h/2*a),  n = invert_v(cyl->a)
// * other with c = pv_add(c, scalar_mult(cyl->a, cyl->h)), and n = cyl->a