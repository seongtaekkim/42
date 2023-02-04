/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:20:30 by susong            #+#    #+#             */
/*   Updated: 2023/02/04 15:13:18 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	check_cylinder_cap(t_cylinder *cylinder,
		t_ray ray, t_hit *hit, double height)
{
	const double	r = cylinder->diameter / 2;
	const t_vec3	circle_center = vplus(cylinder->point,
			vmult(cylinder->dir, height));
	const double	root = vdot(vminus(circle_center, ray.origin),
			cylinder->dir) / vdot(ray.direct, cylinder->dir);
	const double	diameter = vlength(vminus(circle_center,
				vplus(ray.origin, vmult(ray.direct, root))));

	if (fabs(r) < fabs(diameter))
		return (0);
	if (root > hit->distance || root < EPSILON)
		return (0);
	hit->distance = root;
	hit->hit_point = vplus(ray.origin, vmult(ray.direct, root));
	hit->color = cylinder->color;
	if (0 < height)
		hit->hit_normal = cylinder->dir;
	else
		hit->hit_normal = vmult(cylinder->dir, -1);
	return (1);
}

int	set_info_hit(t_cylinder *cylinder,
	t_hit *hit, t_ray ray, double distance)
{
	double	hit_height;

	hit_height = check_height(cylinder,
			vplus(ray.origin, vmult(ray.direct, distance)));
	if (hit_height == 0)
		return (0);
	hit->distance = distance;
	hit->hit_point = vplus(ray.origin, vmult(ray.direct, distance));
	hit->color = cylinder->color;
	hit->hit_normal = cylinder_normal(cylinder,
			vplus(ray.origin, vmult(ray.direct, distance)), hit_height);
	return (1);
}

int	check_cylinder_side(t_cylinder *cylinder,
	t_ray ray, t_hit *hit, double distance)
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	t_vec3	delta;

	delta = vminus(ray.origin, cylinder->point);
	a = vlength2(vcross(ray.direct, cylinder->dir));
	half_b = vdot(vcross(ray.direct, cylinder->dir),
			vcross(delta, cylinder->dir));
	c = vlength2(vcross(delta, cylinder->dir)) - pow(cylinder->diameter / 2, 2);
	discriminant = half_b * half_b - a * c;
	if (discriminant < EPSILON)
		return (0);
	discriminant = sqrt(discriminant);
	distance = (-1 * half_b - discriminant) / a;
	if (distance > hit->distance)
	{
		distance = (-1 * half_b + discriminant) / a;
		if (distance > hit->distance)
			return (0);
	}
	if (!set_info_hit(cylinder, hit, ray, distance))
		return (0);
	return (1);
}

int	check_cylinder(t_cylinder *cylinder, t_ray ray, t_hit *hit)
{
	int	result;

	result = 0;
	result += check_cylinder_side(cylinder, ray, hit, 0.0);
	result += check_cylinder_cap(cylinder, ray, hit, cylinder->height / 2);
	result += check_cylinder_cap(cylinder, ray, hit, -(cylinder->height / 2));
	return (result);
}

int	check_all_cylinder(t_scene scene, t_ray ray, t_hit *hit)
{
	t_cylinder	*cur;
	int			result;

	cur = scene.objects.cylinder;
	result = 0;
	if (cur == NULL)
		return (0);
	result += check_cylinder(cur, ray, hit);
	while (cur->next != NULL)
	{
		cur = cur->next;
		result += check_cylinder(cur, ray, hit);
	}
	return (result);
}
