/* Write a program that takes a string and displays this string after rotating it one word to the left.
    Thus, the first word becomes the last, and others stay in the same order.*/

#include <unistd.h>
#include <stdio.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int    ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
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

void    print_second_part(char *str, int i)
{
    ft_putnbr(ft_strlen(str));
    while (i < ft_strlen(str)) // Can't calculate the length of the input string (there is no null operator at the end)
    {
        ft_putnbr(i);
        ft_putchar('\n');
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        while (str[i] != ' ' && str[i] != '\t')
        {
            ft_putchar(str[i]);
            i++;
        }
        ft_putchar(' ');
        i++;
    }
}

void    print_first_word(char *str, int i)
{
    int j;

    j = 0;
    while (j < i)
    {
        while (str[j] == ' ' || str[j] == '\t')
            j++;
        while (str[j] != ' ' && str[j] != '\t')
        {
            ft_putchar(str[j]);
            j++;
        }
        j++;
    }
}

int    find_end_first_word(char *str)
{
    int i;

    i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i] != ' ' && str[i] != '\t')
        i++;
    return (i);
}

int main(int argc, char **argv)
{
    int end_first_word;

    end_first_word = 0;
    if (argc < 2)
        ft_putchar('\n');
    else
    {
        end_first_word = find_end_first_word(argv[1]);
        print_second_part(argv[1], end_first_word);
        print_first_word(argv[1], end_first_word);
    }
}
