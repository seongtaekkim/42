/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:05:16 by seongtki          #+#    #+#             */
/*   Updated: 2022/12/31 18:31:23 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	ft_str2len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static t_point	*set_mapheight(char **data, t_fdf *fdf)
{
	t_point	*tmp;
	int		index;
	char	**data2;

	index = 0;
	tmp = (t_point *)malloc(sizeof(t_point) * fdf->map.x);
	if (!tmp)
		do_exit(fdf);
	while (data[index])
	{
		data2 = ft_split(data[index], ',');
		tmp[index].z = ft_atoi(data2[0]);
		if (ft_str2len(data2) == 2)
		{
			if (data2[1][0] == '0' && ft_tolower(data2[1][1]) == 'x')
				tmp[index].color = str_to_hexa(data2[1]);
			else
				tmp[index].color = DEFAULT_COLOR;
		}
		else
			tmp[index].color = DEFAULT_COLOR;
		index++;
		free_arr2(data2);
	}
	return (tmp);
}

static int	append_line(char **data, t_fdf *fdf)
{
	t_point	**tmp;
	int		index;

	tmp = (t_point **)malloc(sizeof(t_point *) * fdf->map.y);
	if (!tmp)
		do_exit(fdf);
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

int	read_file(char	*file, t_fdf *fdf)
{
	int		fd;
	char	*line;
	char	*trim_line;
	char	**data;
	int		line_size;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		do_exit(fdf);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		trim_line = ft_strtrim(line, " \n");
		data = ft_split(trim_line, ' ');
		line_size = ft_str2len(data);
		if (fdf->map.x != 0 && line_size != fdf->map.x)
			do_exit(fdf);
		fdf->map.x = line_size;
		fdf->map.y += 1;
		append_line(data, fdf);
		line_free(data, trim_line, line);
	}
	return (0);
}
