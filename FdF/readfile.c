/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:05:16 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/14 14:06:01 by seongtki         ###   ########.fr       */
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
	fdf->map.map = tmp;
	return (0);
}

int	read_file(char	*file, t_fdf *fdf)
{
	int		fd;
	char	*line;
	char	**data;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		// tmp생성해서 map에 누적저장하는 식으로 쌓는다.
		free(line);
		if (!line)
			break ;
		data = ft_split(line, ' ');
		int	index = 0;
		while (data[index])
			index++;
		fdf->map.x = index;
		fdf->map.y += 1;
		append_line(data, fdf);
	}
	return (0);
}

