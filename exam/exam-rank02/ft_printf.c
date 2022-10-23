# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
#include <stdio.h>

int cnt = 0;

void put_int(long d)
{
	if (d < 10)
	{
		char a = d + '0';
		write(1, &a, 1);
		cnt++;
		return ;
	}
	put_int(d / 10);
	char a = (d % 10) + '0';
	write(1, &a, 1);
	cnt++;
}

void put_hax(unsigned int d)
{
	if (d >= 16)
		put_hax(d / 16);
	write(1, &"0123456789abcdef"[d % 16], 1);
	cnt++;
}

int ft_printf(const char *data, ...)
{
	va_list ap;
	int i = 0;

	va_start(ap, data);
	while (data[i])
	{
		if (data[i] == '%')
		{
			i++;
			if (data[i])
			{
				if (data[i] == 's')
				{
					char *ret = va_arg(ap, char*);
					int length = 0;
					if (!ret)
					{
						write(1, "(null)", 6);
						cnt += 6;
					}
					else 
					{
						while (ret[length])
							length++;
						write(1, ret, length);
						cnt += length;
					}
				}
				else if (data[i] == 'd')
				{
					long long d = va_arg(ap, int);
					if (d < 0)
					{
						write(1, "-", 1);
						d = -1 * d;
						cnt++;
					}
					put_int(d);

				}
				else if (data[i] == 'x')
				{
					 int d = va_arg(ap,  int);
					put_hax(d);
				}
			}
		}
		else
			cnt += write(1, &(data[i]), 1);
		i++;
	}
	va_end(ap);
	return (cnt);
}

#include <stdio.h>
int main(void)
{
	char *str = NULL;
	ft_printf("%d\n", 2147483648);
	ft_printf("%d\n", -2147483649);
	ft_printf("%d\n", 00);
	ft_printf("%s\n", "abcde");
	printf("%x\n", -1234);
	ft_printf("%x\n", -1234);
	//ft_printf("%s", str);
}