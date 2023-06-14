/* Write a function named ft_printf that will mimic the real printf but it will manage only the following conversions:

s (string)
d (decimal) 
x (lowercase hexademical)
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int    ft_putchar_count(char c)
{
    write(1, &c, 1);
    return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

// This is the version that works
int	ft_putstr_count(char *s)
{
	int	length;

	length = ft_strlen(s);
	write(1, s, length);
	return (length);
}

int ft_putnbr_count(int n)
{
    int count;

    count = 0;
    if (n >= 0 && n <= 9)
    {
        count = count + ft_putchar_count(n + 48);
    } 
    else if (n >= 10)
    {
        count = count + ft_putnbr_count(n / 10);
        count = count + ft_putchar_count((n % 10) + 48);
    }
    else if (n < 0)
    {
        count = count + ft_putchar_count('-');
        count = count + ft_putnbr_count(-n);
    }
    else if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        count = count + 11;
    }
    return (count);
}

int ft_puthex_count(unsigned int n)
{
    int             count;

    count = 0;
    if (n >= 0 && n <= 9)
        count = count + ft_putnbr_count(n);
    else if (n >= 10 && n < 16)
        count = count + ft_putchar_count(n + 87);
    else
    {
        count = count + ft_puthex_count(n / 16);
        count = count + ft_puthex_count(n % 16);
    }
    return (count);
}

int	ft_printf(const char *str, ...) // can we omit "str"? I don't think so
{
    va_list ap;
    char    *s;
    int     i;
    int     count;

    va_start(ap, str);
    count = 0;
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            if (str[i + 1] == 's') // string
            {
                s = va_arg(ap, char*);
                if (s == NULL)
                    count = count + ft_putstr_count("(null)");
                else
                    count = count + ft_putstr_count(s);
            }
            else if (str[i + 1] == 'd') // decimal
                count = count + ft_putnbr_count(va_arg(ap, int));
            else if (str[i + 1] == 'x') // lowercase hexadecimal
                count = count + ft_puthex_count(va_arg(ap, unsigned int));
            i++;
        }
        else
            count = count + ft_putchar_count(str[i]); // print normally the string
        i++;
    }
    va_end(ap);
    return (count);
}

int main()
{
    printf("%d\n", printf("this is a string: %s, this is a number %d and this is an hexadecimal %x\n", "42", 42, -42));
    ft_printf("%d\n", ft_printf("this is a string: %s, this is a number %d and this is an hexadecimal %x\n","42", 42, -42));
}
