#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int cnt = 0;

void put_int(long d)
{
    if (d >= 10)
        put_int(d / 10);
    char c = d % 10 + '0';
    write(1, &c, 1);
    cnt++;
}

void put_hax(unsigned int u)
{
    if (u >= 16)
        put_hax(u / 16);
    write(1, &"0123456789abcdef"[u % 16], 1);
    cnt++;
}

int ft_printf(const char *data, ...)
{
    cnt = 0;
    int i = 0;
    va_list ap;

    va_start(ap, data);

    while (data[i])
    {
        if (data[i] == '%')
        {
            i++;
            if (data[i] == 's')
            {
                char *str = va_arg(ap, char *);
                int length = 6;
                if (str == NULL)
                {
                    write(1, "(null)", length);
                }
                else
                {
                    length = 0;
                    while (str[length])
                        length++;
                    write(1, str, length);
                }
                cnt += length;
            }
            else if (data[i] == 'd')
            {
                long d = va_arg(ap, int);
                if (d < 0)
                {
                    write(1, "-", 1);
                    d = d * -1;
                    cnt++;
                }
                put_int(d);
            }
            else if (data[i] == 'x')
            {
                int n = va_arg(ap, int);
                put_hax(n);
            }
            i++;
        }
        else
        {
            cnt += write(1, &data[i++], 1);
        }
    }

    va_end(ap);

    return (cnt);
}




int main(void)
{
	char *str = NULL;
	ft_printf("%d\n", 2147483647);
	ft_printf("%d\n", -2147483648);
	ft_printf("%d\n", 00);
	ft_printf("%s\n", str);
	printf("%x\n", -1234);
	ft_printf("%x\n", -1234);
	//ft_printf("%s", str);
}