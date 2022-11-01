#include "philo.h"

t_bool	_atoi(const char *str, int *output)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == 0 || *str == '-')
		return (false);
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + (*str++ - '0');
		else
			return (false);
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			return (false);
	}
	*output = result * sign;
	return (true);
}
