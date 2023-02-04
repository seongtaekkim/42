/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:22:42 by susong            #+#    #+#             */
/*   Updated: 2023/02/04 15:12:37 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	check_all_sphere(t_scene scene, t_ray ray, t_hit *hit)
{
	t_sphere	*cur;
	int			result;

	result = 0;
	cur = scene.objects.sphere;
	if (!cur)
		return (0);
	result += check_sphere(cur, ray, hit);
	while (cur->next != NULL)
	{
		cur = cur->next;
		result += check_sphere(cur, ray, hit);
	}
	return (result);
}

int	check_sphere(t_sphere *sphere, t_ray ray, t_hit *hit)
{
	const double	b = 2.0f * vdot(ray.direct,
			vminus(ray.origin, sphere->center));
	const double	c = vdot(vminus(ray.origin, sphere->center),
			vminus(ray.origin, sphere->center)) - sphere->radius2;
	const double	nabla = b * b / 4.0f - c;
	double			d1;
	double			d2;

	if (nabla >= 0.0f)
	{
		d1 = -b / 2.0f + sqrt(nabla);
		d2 = -b / 2.0f - sqrt(nabla);
		if (!(d1 < hit->distance || d2 < hit->distance))
			return (0);
		if (d1 > d2)
			hit->distance = d2;
		else
			hit->distance = d1;
		hit->hit_point = vplus(ray.origin, vmult(ray.direct, hit->distance));
		hit->hit_normal = vunit(vminus(hit->hit_point, sphere->center));
		hit->color = sphere->color;
	}
	else
		return (0);
	return (1);
}

int	check_all_plane(t_scene scene, t_ray ray, t_hit *hit)
{
	t_plane	*cur;
	int		result;

	result = 0;
	cur = scene.objects.plane;
	if (!cur)
		return (0);
	result += check_plane(cur, ray, hit);
	while (cur->next != NULL)
	{
		cur = cur->next;
		result += check_plane(cur, ray, hit);
	}
	return (result);
}

int	check_plane(t_plane *plane, t_ray ray, t_hit *hit)
{
	double	distance;
	double	delimeter;
	double	son;

	delimeter = vdot(ray.direct, vunit(plane->dir));
	if (fabs(delimeter) <= EPSILON)
		return (0);
	son = vdot(vminus(plane->point, ray.origin), plane->dir);
	distance = son / delimeter;
	if (distance < hit->distance && distance > EPSILON)
	{
		hit->distance = distance;
		hit->hit_point = vplus(ray.origin, vmult(ray.direct, distance));
		hit->color = plane->color;
		hit->hit_normal = plane->dir;
	}
	return (1);
}
