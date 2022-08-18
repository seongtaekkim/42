/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:05:16 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/18 17:09:52 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*set_mapheight(char **data, t_fdf *fdf)
{
	t_point	*tmp;
	int		index;

	index = 0;
	tmp = (t_point *)malloc(sizeof(t_point) * fdf->map.x);
	while (data[index])
	{
		tmp[index].z = ft_atoi(data[index]);
		index++;
	}
	return (tmp);
}

static int	append_line(char **data, t_fdf *fdf)
{
	t_point	**tmp;
	int		index;

	tmp = (t_point **)malloc(sizeof(t_point *) * fdf->map.y);
	index = fdf->map.y - 1;
	tmp[index] = set_mapheight(data, fdf);
	while (--index >= 0)
	{
		tmp[index] = fdf->map.map[index];
	}
	free(fdf->map.map);
	fdf->map.map = tmp;
	return (0);
}

int	ft_str2len(char **arr)
{
	int	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	read_file(char	*file, t_fdf *fdf)
{
	int		fd;
	char	*line;
	char	*line2;
	char	**data;
	int		line_size;

	fd = open(file, O_RDONLY);
	if (!fd)
		do_exit(fdf);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			do_exit(fdf);
		line2 = ft_strtrim(line, " \n");
		data = ft_split(line2, ' ');
		free(line);
		free(line2);
		line_size = ft_str2len(data);
		if (fdf->map.x != 0 && line_size != fdf->map.x)
			do_exit(fdf);
		fdf->map.x = line_size;
		fdf->map.y += 1;
		append_line(data, fdf);
		free_arr2(data);
	}
	return (0);
}

