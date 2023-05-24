/* Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline. */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

void    ft_putnbr(int n)
{
    if (n == -2147483648)
        ft_putstr("-2147483648");
    else if (n >= 0 && n <= 9)
        ft_putchar(n + 48);
    else if (n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else if (n < 0)
    {
        ft_putchar('-');
        ft_putnbr(-n);
    }
}

int ft_atoi(char *str)
{
    int i;
    int sign;
    int final_number;

    final_number = 0;
    sign = 1;
    i = 0;
    while (str[i] == ' ' || (str[i] == '\t' && str[i] <= '\r'))
        i++;
    if (str[i] == '-' || str[i] == '+')  // if here instead of while to reproduce exactly atoi
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        final_number = final_number * 10 + (str[i] - 48);
        i++;
    }
    return (final_number * sign);
}

void	print_hex(int n)
{
	if (n >= 0 && n <= 9)
		ft_putnbr(n);
    else if (n > 9 && n <=15)
        ft_putchar(n + 87);
	else
	{
		print_hex(n / 16);
		print_hex(n % 16);
	}
}

int main(int argc, char **argv)
{
    if (argc != 2)
        ft_putchar('\n');
    else
    {
        // print_hex(ft_atoi(argv[1]));
        printf("%d\n", ft_atoi(argv[1]));
        printf("%d\n", atoi(argv[1]));
    }
}

