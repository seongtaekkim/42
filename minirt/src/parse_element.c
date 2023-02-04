/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:02:08 by susong            #+#    #+#             */
/*   Updated: 2023/02/04 15:13:47 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	make_ambient(t_scene *out, char *line, t_acl_check *acl_check)
{
	char	**data;
	char	**rgb;
	int		b;

	b = 0;
	acl_check->ambient++;
	if (acl_check->ambient > 1)
		ft_exit(3);
	data = ft_split(line, ' ');
	valid_parse_data(data, 3);
	out->lights.amb_brightness = ft_atof(data[1], &b);
	rgb = ft_split(data[2], ',');
	valid_parse_data(rgb, 3);
	out->lights.amb_color.x = ft_atoi(rgb[0], &b) / 255.0;
	out->lights.amb_color.y = ft_atoi(rgb[1], &b) / 255.0;
	out->lights.amb_color.z = ft_atoi(rgb[2], &b) / 255.0;
	free2(data);
	free2(rgb);
	if (b == 1)
		ft_exit(3);
	return ;
}

void	make_camera(t_scene *out, char *line, t_acl_check *acl_check)
{
	char	**data;
	char	**point;
	int		b;

	b = 0;
	acl_check->camera++;
	if (acl_check->camera > 1)
		ft_exit(3);
	data = ft_split(line, ' ');
	valid_parse_data(data, 4);
	point = ft_split(data[1], ',');
	valid_parse_data(point, 3);
	out->camera.point = vec3(ft_atof(point[0], &b),
			ft_atof(point[1], &b), ft_atof(point[2], &b));
	free2(point);
	point = ft_split(data[2], ',');
	valid_parse_data(point, 3);
	out->camera.dir = vunit(vec3(ft_atof(point[0], &b),
				ft_atof(point[1], &b), ft_atof(point[2], &b)));
	free2(point);
	out->camera.fov = ft_atof(data[3], &b);
	free2(data);
	if (b == 1)
		ft_exit(3);
	return ;
}

void	make_light(t_scene *out, char *line, t_acl_check *acl_check)
{
	char	**data;
	char	**point;
	int		b;

	b = 0;
	acl_check->light++;
	if (acl_check->light > 1)
		ft_exit(3);
	data = ft_split(line, ' ');
	point = ft_split(data[1], ',');
	valid_parse_data(data, 4);
	valid_parse_data(point, 3);
	out->lights.point = vec3(ft_atof(point[0], &b),
			ft_atof(point[1], &b), ft_atof(point[2], &b));
	free2(point);
	out->lights.brightness = ft_atof(data[2], &b);
	point = ft_split(data[3], ',');
	valid_parse_data(point, 3);
	out->lights.light_color = vec3(ft_atoi(point[0], &b) / 255.0,
			ft_atoi(point[1], &b) / 255.0, ft_atoi(point[2], &b) / 255.0);
	free2(point);
	free2(data);
	if (b == 1)
		ft_exit(3);
	return ;
}

static void	set_attr_plane(t_plane *new, char **data, char **point)
{
	int	b;

	b = 0;
	valid_parse_data(data, 4);
	valid_parse_data(point, 3);
	new->point = vec3(ft_atof(point[0], &b),
			ft_atof(point[1], &b), ft_atof(point[2], &b));
	free2(point);
	point = ft_split(data[2], ',');
	valid_parse_data(point, 3);
	new->dir = vunit(vec3(ft_atof(point[0], &b),
				ft_atof(point[1], &b), ft_atof(point[2], &b)));
	free2(point);
	point = ft_split(data[3], ',');
	valid_parse_data(point, 3);
	new->color = vec3(ft_atoi(point[0], &b) / 255.0,
			ft_atoi(point[1], &b) / 255.0, ft_atoi(point[2], &b) / 255.0);
	if (b == 1)
		ft_exit(3);
}

void	make_plane(t_scene *out, char *line)
{
	char	**data;
	char	**point;
	t_plane	*new;
	t_plane	*cur;

	new = (t_plane *)malloc(sizeof(t_plane));
	if (!new)
		ft_exit(4);
	data = ft_split(line, ' ');
	point = ft_split(data[1], ',');
	set_attr_plane(new, data, point);
	free2(point);
	free2(data);
	new->next = NULL;
	if (out->objects.plane == 0)
		out->objects.plane = new;
	else
	{
		cur = out->objects.plane;
		while (out->objects.plane->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
}
