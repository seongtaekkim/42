#include "philo.h"

int	_atoi(const char *str, int *flag)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == 0)
		*flag = 0;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + (*str++ - '0');
		else
		{
			*flag = 0;
			return (-1);
		}
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			*flag = 0;
	}
	return (result * sign);
}
