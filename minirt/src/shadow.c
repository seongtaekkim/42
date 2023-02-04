/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:33:53 by susong            #+#    #+#             */
/*   Updated: 2023/02/03 20:58:11 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	is_shadow(t_vec3 point, t_scene scene)
{
	t_ray	shadow_ray;
	t_hit	hit;
	double	light_distance;

	hit = init_hit();
	light_distance = vlength(vminus(scene.lights.point, point));
	hit.distance = light_distance;
	shadow_ray.direct = vunit(vminus(scene.lights.point, point));
	shadow_ray.origin = vplus(point, vmult(shadow_ray.direct, 0.01));
	if (check_all_sphere(scene, shadow_ray, &hit)
		&& hit.distance > EPSILON && hit.distance < light_distance)
		return (1);
	if (check_all_cylinder(scene, shadow_ray, &hit)
		&& hit.distance > EPSILON && hit.distance < light_distance)
		return (1);
	if (check_all_plane(scene, shadow_ray, &hit)
		&& hit.distance > EPSILON && hit.distance < light_distance)
		return (1);
	return (0);
}
