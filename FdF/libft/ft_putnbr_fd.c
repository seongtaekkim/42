/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongtki <seongtki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:43:14 by seongtki          #+#    #+#             */
/*   Updated: 2022/07/11 14:37:32 by seongtki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr(int nb, int fd)
{
	int	sign;

	sign = -1;
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10, fd);
		ft_putnbr(8, fd);
	}
	else if (nb < 0)
	{
		ft_putchar('-', fd);
		nb = nb * sign;
		ft_putnbr(nb, fd);
	}
	else
	{
		if (nb < 10)
			ft_putchar(nb + '0', fd);
		else
		{
			ft_putnbr(nb / 10, fd);
			ft_putchar(nb % 10 + '0', fd);
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd == -1)
		return ;
	else
		ft_putnbr(n, fd);
}
