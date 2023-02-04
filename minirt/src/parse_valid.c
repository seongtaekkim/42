/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:40:01 by susong            #+#    #+#             */
/*   Updated: 2023/02/04 15:28:08 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static void	check_val_object2(t_scene out)
{
	const t_cylinder	*c = out.objects.cylinder;

	while (c)
	{
		if (!(c->color.x >= 0.0 && c->color.x <= 1.0)
			|| !(c->color.y >= 0.0 && c->color.y <= 1.0)
			|| !(c->color.z >= 0.0 && c->color.z <= 1.0))
			ft_exit(3);
		if (c->diameter <= 0.0 || c->height <= 0.0)
			ft_exit(3);
		c = c->next;
	}
}

static void	check_val_object1(t_scene out)
{
	const t_plane	*p = out.objects.plane;
	const t_sphere	*s = out.objects.sphere;

	while (p)
	{
		if (!(p->color.x >= 0.0 && p->color.x <= 1.0)
			|| !(p->color.y >= 0.0 && p->color.y <= 1.0)
			|| !(p->color.z >= 0.0 && p->color.z <= 1.0))
			ft_exit(3);
		p = p->next;
	}
	while (s)
	{
		if (!(s->color.x >= 0.0 && s->color.x <= 1.0)
			|| !(s->color.y >= 0.0 && s->color.y <= 1.0)
			|| !(s->color.z >= 0.0 && s->color.z <= 1.0))
			ft_exit(3);
		if (s->radius <= 0.0)
			ft_exit(3);
		s = s->next;
	}
}

static void	check_val_acl(t_scene out)
{
	if (!(out.camera.fov >= 0 && out.camera.fov <= 180))
		ft_exit(3);
	if (!(out.lights.amb_brightness >= 0.0 && out.lights.amb_brightness <= 1.0))
		ft_exit(3);
	if (!(out.lights.brightness >= 0.0 && out.lights.brightness <= 1.0))
		ft_exit(3);
	if (!(out.lights.amb_color.x >= 0.0 && out.lights.amb_color.x <= 1.0)
		|| !(out.lights.amb_color.y >= 0.0 && out.lights.amb_color.y <= 1.0)
		|| !(out.lights.amb_color.z >= 0.0 && out.lights.amb_color.z <= 1.0))
		ft_exit(3);
	if (!(out.lights.light_color.x >= 0.0 && out.lights.light_color.x <= 1.0)
		|| !(out.lights.light_color.y >= 0.0 && out.lights.light_color.y <= 1.0)
		|| !(out.lights.light_color.z >= 0.0
			&& out.lights.light_color.z <= 1.0))
		ft_exit(3);
}

static void	check_camara(t_acl_check *acl_check)
{
	if (acl_check->camera != 1)
		ft_exit(5);
}

void	check_value_range(t_scene out, t_acl_check *acl_check)
{
	check_camara(acl_check);
	check_val_acl(out);
	check_val_object1(out);
	check_val_object2(out);
}
