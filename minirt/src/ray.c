/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:39:49 by susong            #+#    #+#             */
/*   Updated: 2023/02/04 15:14:37 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_ray	ray_init(t_scene scene, double x, double y)
{
	t_ray	out;
	t_vec3	temp;
	double	v;
	double	u;

	v = x / (MLX_WIDTH - 1) * MLX_ASPECT * 2;
	u = y / (MLX_HEIGHT - 1) * 2;
	temp = vplus(vmult(scene.viewport.right, v), vmult(scene.viewport.down, u));
	out.distance = 0;
	out.origin = vplus(scene.viewport.origin, temp);
	out.direct = vunit(vminus(out.origin, scene.camera.point));
	return (out);
}

t_hit	init_hit(void)
{
	t_hit	out;

	out.distance = MAX;
	out.hit_point = vec3(0, 0, 0);
	out.hit_normal = vec3(0, 0, 0);
	out.color = vec3(0, 0, 0);
	return (out);
}

t_color3	make_color(t_scene scene, t_ray ray)
{
	t_hit		hit;
	t_color3	color;

	hit = init_hit();
	check_all_sphere(scene, ray, &hit);
	check_all_plane(scene, ray, &hit);
	check_all_cylinder(scene, ray, &hit);
	if (hit.distance != MAX)
	{
		if (is_shadow(hit.hit_point, scene))
			color = vmult(scene.lights.amb_color, scene.lights.amb_brightness);
		else
		{
			color = vmult(scene.lights.light_color, diffuse(scene, hit));
			color = vplus(vmult_(scene.lights.amb_color,
						vmult(hit.color, scene.lights.amb_brightness)), color);
		}
	}
	else
		color = vec3(1, 1, 1);
	return (color);
}
