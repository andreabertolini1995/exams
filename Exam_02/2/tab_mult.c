/* Write a program that displays a number's multiplication table. */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n >= 0 && n < 10)
	{
		ft_putchar(n + 48);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
	else if (n < 0)
	{
		ft_putchar(45);
		ft_putnbr(-n);
	}
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	final_number;
	int	i;

	sign = 1;
	final_number = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		while ((str[i] >= '0') && (str[i] <= '9'))
		{
			final_number = final_number * 10 + (str[i] - 48);
			i++;
		}
		return (final_number * sign);
	}
	return (final_number * sign);
}

void    fill_multiplication_table(int n)
{
    int i;

    i = 1;
    while (i <= 9)
    {
		ft_putnbr(i);
        ft_putstr(" x ");
        ft_putnbr(n);
        ft_putstr(" = ");
        ft_putnbr(n * i);
        ft_putchar('\n');
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        ft_putchar('\n');
    else
        fill_multiplication_table(ft_atoi(argv[1]));
}