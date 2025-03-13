/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:22:25 by ewu               #+#    #+#             */
/*   Updated: 2025/03/13 11:01:49 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_ambient(t_amblight *amblight, char **tokens, int i)
{
	if (check_para_num(tokens, 'a') == -1)
		return (-1);
	amblight->ratio = ft_atofloat(tokens[1]);
	if (amblight->ratio < 0.0f || amblight->ratio > 1.0f)
		return (p_err("Error:\nInvalid ambient light value! \
Must be within [0.0-1.0]! Exit!"), -1);
	amblight->color = parse_color(tokens[2]);
	if (is_err_color(amblight->color))
		return (-1);
	return (i);
}
