/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:14:24 by susong            #+#    #+#             */
/*   Updated: 2023/01/31 16:05:56 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	diffuse(t_scene scene, t_hit hit)
{
	t_vec3	dir_to_light;
	double	light;

	dir_to_light = vunit(vminus(scene.lights.point, hit.hit_point));
	light = vdot(dir_to_light, hit.hit_normal);
	if (light <= 0)
		light = 0;
	return (light);
}
