/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:20:30 by susong            #+#    #+#             */
/*   Updated: 2023/02/02 17:02:59 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	check_height(t_cylinder *cylinder, t_vec3 point)
{
	double	hit;
	double	max;

	max = cylinder->height / 2;
	hit = vdot(vminus(point, cylinder->point), cylinder->dir);
	if (fabs(hit) > max)
		return (0);
	return (hit);
}

t_vec3	cylinder_normal(t_cylinder *cylinder, t_vec3 point, double height)
{
	t_vec3	hit_center;
	t_vec3	result;

	hit_center = vplus(cylinder->point, vmult(cylinder->dir, height));
	result = vminus(point, hit_center);
	return (vunit(result));
}
