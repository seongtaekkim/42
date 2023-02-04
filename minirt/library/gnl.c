/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:21:31 by susong            #+#    #+#             */
/*   Updated: 2023/01/19 19:28:28 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*absolute_enter(int fd, char *BUFFER, char *backup)
{
	int		line_numb;
	char	*temp;

	line_numb = 1;
	while (line_numb != '\0')
	{
		line_numb = read(fd, BUFFER, BUFFER_SIZE);
		if (line_numb < 0)
			return (0);
		else if (line_numb == 0)
			break ;
		BUFFER[line_numb] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, BUFFER);
		free(temp);
		if (ft_strchr(backup, '\n'))
			break ;
	}
	return (backup);
}

char	*extract_result(char *result, char *backup)
{
	int	count;

	count = 0;
	while (result[count] != '\n' && result[count] != '\0')
		count++;
	if (result[count] != '\n' && result[count] != '\0')
		return (0);
	backup = ft_substr(result, count + 1, ft_strlen(result) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = 0;
	}
	result[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		buffernow[BUFFER_SIZE + 1];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	result = absolute_enter(fd, buffernow, backup);
	if (!result)
		return (0);
	backup = extract_result(result, backup);
	return (result);
}
