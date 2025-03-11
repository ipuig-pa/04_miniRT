/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:32:33 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/03/11 19:08:50 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	inside_sph(t_vector p, t_sph *sph)
{
	if (v_modulus(v_subt(p, sph->c)) <= sph->r)
		return (true);
	return (false);
}

static float	inside_cyl(t_vector p, t_cyl *cyl)
{
	t_vector	b_p;
	float		proj;
	float		rej;
	float		cos;
	float		sin;

	b_p = v_subt(p, cyl->b);
	cos = dot_prod(unit_v(b_p), cyl->a);
	proj = cos * v_modulus(b_p);
	if (proj <= cyl->h)
	{
		sin = sqrtf(1.0 - cos * cos);
		rej = sin * v_modulus(b_p);
		if (rej <= cyl->r)
			return (true);
	}
	return (false);
}

static bool	check_inside(t_vector light, t_scene *scene, int i) //or put this chunk of code inside the find_hit function
{
	float	t;

	t = -1;
	if (scene->obj[i].type == SPH)
		return (inside_sph(light, &scene->obj[i].param.sph));
	else if (scene->obj[i].type == CYL)
		return (inside_cyl(light, &scene->obj[i].param.cyl));
	return (false);
}

void	check_enclosed_light(t_scene *scene)
{
	int		i;
	bool	inside;

	i = 0;
	scene->enclosed_light = false;
	while (i < scene->obj_num)//optimize somehow to not iterate through ALL the objects??
	{
		if (scene->obj[i].m.exist == true)
			inside = check_inside(v_transform(scene->light.p, scene->obj[i].inv_m, 'p'), scene, i);
		else
			inside = check_inside(scene->light.p, scene, i);
		if (inside)
			scene->enclosed_light = true;
		i++;
	}
}
