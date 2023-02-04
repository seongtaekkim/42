/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:40:01 by susong            #+#    #+#             */
/*   Updated: 2023/02/04 18:53:17 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	name_check(char *name)
{
	int	index;

	index = 0;
	if (!name)
		return (1);
	while (name[index])
		index++;
	if (index < 3)
		return (1);
	if (name[index - 1] == 't' && name[index - 2] == 'r'
		&& name[index - 3] == '.')
		return (0);
	else
		return (1);
}

void	make_viewport(t_scene *out)
{
	t_vec3	temp;

	out->viewport.height = 2;
	out->viewport.width = MLX_ASPECT * out->viewport.height;
	out->viewport.focal_length
		= MLX_ASPECT / tan((out->camera.fov / 2) * M_PI / 180);
	if (vlength(vcross(vec3(0, 1, 0), out->camera.dir)))
		out->viewport.right = vunit(vcross(out->camera.dir, vec3(0, 1, 0)));
	else
		out->viewport.right = vunit(vcross(out->camera.dir, vec3(0, 0, -1)));
	out->viewport.down = vmult(vunit(\
	vcross(out->viewport.right, out->camera.dir)), -1);
	temp = vplus(out->camera.point, vmult(\
	out->camera.dir, out->viewport.focal_length));
	temp = vplus(temp, vmult(out->viewport.right, (float)(MLX_ASPECT)));
	temp = vminus(temp, vmult(out->viewport.down, (float)1));
	out->viewport.right = vmult(out->viewport.right, -1);
	out->viewport.origin = temp;
	return ;
}

static void	make_shape(char *line, t_scene *out, t_acl_check *acl_check)
{
	if (ft_strncmp(line, "\n", 1))
		return ;
	if (ft_strncmp(line, "A ", 2))
		make_ambient(out, line, acl_check);
	else if (ft_strncmp(line, "C ", 2))
		make_camera(out, line, acl_check);
	else if (ft_strncmp(line, "L ", 2))
		make_light(out, line, acl_check);
	else if (ft_strncmp(line, "pl ", 3))
		make_plane(out, line);
	else if (ft_strncmp(line, "sp ", 3))
		make_sphere(out, line);
	else if (ft_strncmp(line, "cy ", 3))
		make_cylinder(out, line);
	else
		ft_exit(3);
}

t_scene	init_scene(char *filename)
{
	int			fd;
	t_scene		out;
	char		*line;
	t_acl_check	acl_check;

	fd = 0;
	line = 0;
	acl_check.ambient = 0;
	acl_check.camera = 0;
	acl_check.light = 0;
	ft_memset(&out, 0, sizeof(out));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_exit(2);
	line = get_next_line(fd);
	while (line > 0)
	{
		make_shape(line, &out, &acl_check);
		free(line);
		line = get_next_line(fd);
	}
	check_value_range(out, &acl_check);
	make_viewport(&out);
	close(fd);
	return (out);
}
