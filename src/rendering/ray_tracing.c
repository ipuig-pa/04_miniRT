/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:40:28 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/21 19:29:45 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//anything related with the tracing of the rays and render of the image
#include "minirt.h"

//choose if float or double, to have different function prototype in math library function

void	ray_tracer(t_env *env)
{
	int		i;
	int		j;
	t_ray	ray;
	t_hit	hit;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			hit.occur = false;
			cast_ray(&ray, i, j, env->scene);
			find_hit(&hit, &ray, env->scene, -1);
			//how to distinguish if it hits the light
			if (hit.occur == true)
			{
				shading(&hit, &ray, env->scene);
				my_pixel_put(env, j, i, convert_rgba(&ray.color)); //how to handle if it hits nothing, we have to put the background?
			}
			j++;
		}
		i++;
	}
}

//init the ray parameters
//give real world coordinates of its origin (camera)
//uses a viewport at dist 1 from camera, size acc. to FOV
//calculate the vector acc. to camera position and pixel in viewport
//init to filter color (white by def) as the base color of the ray
//return the point of origin
void	cast_ray(t_ray *ray, int i, int j, t_scene *scene)
{
	float	px_space;
	float	half_viewport_w;
	float	half_viewport_h;
	float	v_modul;

	half_viewport_w = tanf(scene->cam->fov / 2.0);
	px_space = 2.0 * half_viewport_w / WINDOW_WIDTH;
	half_viewport_h = WINDOW_HEIGHT * half_viewport_w / WINDOW_WIDTH;
	ray->p = scene->cam->p; //do a hard_copy or like this is ok? (should be ok, because he camera are not supposed to be changed)
	ray->v.x = scene->cam->p.x - half_viewport_w + (j + 0.5) * px_space;
	ray->v.y = scene->cam->p.y + half_viewport_h - (i + 0.5) * px_space;
	ray->v.z = 1.0;
	v_modul = v_modulus(&ray->v);
	ray->v.x = ray->v.x / v_modul;
	ray->v.y = ray->v.y / v_modul;
	ray->v.z = ray->v.z / v_modul;
	ray->color = FILTER; //or take it from the scene file if we are introducing a filter??
	// ray->end = false;
}

//return the point of the first intersect of the ray
//recalculates ray direction (p and v) according to material properties
void	find_hit(t_hit	*hit, t_ray *ray, t_scene *scene, int h) //allocate the hit if needed
{
	int		i;

	i = 0;
	//allocate for a maximum of 2 times for each object?
	//what about planes exactly coincident with the ray? (line contained in a plane)
	while (i < scene->obj_num)//optimize somehow to not iterate through ALL the objects
	{
		if (i != h)
			calc_intersect(hit, ray, scene, i);
		i++;
	}
}

//cast a ray from the light source to the hit point
//finds if it hits some object
//determine if the hit is before or after the light source
//change the ray color according (in light or shadow)
void	shading(t_hit *hit, t_ray *ray, t_scene *scene)
{
	float		hit_light_d;
	t_hit		sh_hit;
	float		cos_theta;

	ray->p = scene->light->p; //do a hard_copy or like this is ok?
	hit_light_d = dist(&scene->light->p, &hit->p);
	ray->v.x = (scene->light->p.x - hit->p.x) / hit_light_d; //unitary vector
	ray->v.y = (scene->light->p.y - hit->p.y) / hit_light_d;
	ray->v.z = (scene->light->p.z - hit->p.z) / hit_light_d;
	//dont know if the initial color of the ray has to be multiplied or added?!?!?
	ray->color = scene->obj[hit->obj_id].color;
	//ray->color = col_prod(ray->color, col_sc_prod(col_prod(scene->obj[hit->obj_id].color, scene->amblight->color), scene->amblight->ratio)); //adding ambient light
	//ray->color = col_add(ray->color, col_sc_prod(col_prod(scene->obj[hit->obj_id].color, scene->amblight->color), scene->amblight->ratio)); //adding ambient light
	sh_hit.occur = false;
	find_hit(&sh_hit, ray, scene, hit->obj_id);
	//if hit then do whatever needed for shadows
	if (sh_hit.occur == false || sh_hit.dist > hit_light_d)//there is no other object intersecting the path from hit object to light
	{
		//ray->color = WHITE;
		find_normal(hit, scene);
		cos_theta = dot_product(&ray->v, &hit->normal);
		// if (cos_theta < 0)
		// 	cos_theta = 0;
		// ray->color = col_sc_prod(ray->color, cos_theta);
		if (cos_theta > 0)
		{
		// printf("L.x:%f ,.y:%f ,.z:%f , HP.x:%f ,.y:%f ,z:%f\n",scene->light->p.x, scene->light->p.y, scene->light->p.z, hit->p.x, hit->p.y, hit->p.z);
			//ray->color = WHITE;
			//ray->color = col_add(ray->color, col_sc_prod(col_prod(scene->obj[hit->obj_id].color, scene->light->color), scene->light->ratio));
			cos_theta = powf(cos_theta, 0.8); //smoothing effect. Needed to get rid of psychodelic patterns?!?!
			//ray->color = col_sc_prod(ray->color, cos_theta);
			//ray->color = col_prod(ray->color, col_sc_prod(col_sc_prod(col_prod(scene->obj[hit->obj_id].color, scene->light->color), scene->light->ratio), cos_theta));
			ray->color = col_add(ray->color, diffuse_comp());
		}
		// if (cos_theta > 0.8)
		// 	ray->color = WHITE;
		// else if (cos_theta > 0.5)
		// 	ray->color = RED;
		// else if (cos_theta > 0)
		// 	ray->color = BLUE;
	}
}

t_color	diffuse_comp(t_hit *hit, t_scene *scene, float cos_theta) //or move everything related to cos_theta inside
{
	t_color	diffuse_col;

	diffuse_col = col_sc_prod(col_sc_prod(col_prod(scene->obj[hit->obj_id].color, scene->light->color), scene->light->ratio), cos_theta);
	return (diffuse_col);
}

t_color	specular()
{
	t_color	spec_col;

	spec_col = scene->light->color * 
}
