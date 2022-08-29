/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:51:10 by seongtki          #+#    #+#             */
/*   Updated: 2022/08/29 10:47:15 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	toupperMessage(int &count, char **messages)
{
	int		index;
	size_t	jndex;

	index = 1;
	while (index < count)
	{
		jndex = 0;
		while (jndex < strlen(messages[index]))
		{
			std::cout << char(toupper(messages[index][jndex]));
			jndex++;
		}
		index++;
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		toupperMessage(argc, argv);
	
	return (0);
}
