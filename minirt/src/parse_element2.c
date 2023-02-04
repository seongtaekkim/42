/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:02:08 by susong            #+#    #+#             */
/*   Updated: 2023/02/03 17:56:29 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	valid_parse_data(char **point, int length)
{
	if (ft_strlen2(point) != length || ft_strncmp(point[length - 1], "\n", 1))
		ft_exit(3);
}

static void	set_attr_sphere(t_sphere *new, char **data, char **point)
{
	int	b;

	b = 0;
	valid_parse_data(data, 4);
	valid_parse_data(point, 3);
	new->center = vec3(ft_atof(point[0], &b),
			ft_atof(point[1], &b), ft_atof(point[2], &b));
	free2(point);
	new->radius = ft_atof(data[2], &b);
	new->radius2 = new->radius * new->radius;
	point = ft_split(data[3], ',');
	valid_parse_data(point, 3);
	new->color = vec3(ft_atoi(point[0], &b) / 255.0,
			ft_atoi(point[1], &b) / 255.0, ft_atoi(point[2], &b) / 255.0);
	new->next = NULL;
	if (b == 1)
		ft_exit(3);
}

void	make_sphere(t_scene *out, char *line)
{
	char		**data;
	char		**point;
	t_sphere	*new;
	t_sphere	*cur;

	new = (t_sphere *)malloc(sizeof(t_sphere));
	if (!new)
		ft_exit(4);
	data = ft_split(line, ' ');
	point = ft_split(data[1], ',');
	set_attr_sphere(new, data, point);
	free2(point);
	free2(data);
	if (out->objects.sphere == NULL)
		out->objects.sphere = new;
	else
	{
		cur = out->objects.sphere;
		while (cur->next != 0)
			cur = cur->next;
		cur->next = new;
	}
	return ;
}

static void	set_attr_sylinder(t_cylinder *new, char **data, char **point)
{
	int	b;

	b = 0;
	valid_parse_data(data, 6);
	valid_parse_data(point, 3);
	new->point = vec3(ft_atof(point[0], &b),
			ft_atof(point[1], &b), ft_atof(point[2], &b));
	free2(point);
	point = ft_split(data[2], ',');
	valid_parse_data(point, 3);
	new->dir = vunit(vec3(ft_atof(point[0], &b),
				ft_atof(point[1], &b), ft_atof(point[2], &b)));
	free2(point);
	new->diameter = ft_atof(data[3], &b);
	new->height = ft_atof(data[4], &b);
	point = ft_split(data[5], ',');
	valid_parse_data(point, 3);
	new->color = vec3(ft_atoi(point[0], &b) / 255.0,
			ft_atoi(point[1], &b) / 255.0, ft_atoi(point[2], &b) / 255.0);
	new->next = NULL;
	if (b == 1)
		ft_exit(3);
}

void	make_cylinder(t_scene *out, char *line)
{
	char		**data;
	char		**point;
	t_cylinder	*new;
	t_cylinder	*cur;

	new = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!new)
		ft_exit(4);
	data = ft_split(line, ' ');
	point = ft_split(data[1], ',');
	set_attr_sylinder(new, data, point);
	free2(point);
	free2(data);
	if (out->objects.cylinder == NULL)
		out->objects.cylinder = new;
	else
	{
		cur = out->objects.cylinder;
		while (cur->next != 0)
			cur = cur->next;
		cur->next = new;
	}
	return ;
}
