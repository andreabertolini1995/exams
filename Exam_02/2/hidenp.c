/* Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline. */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void    hidenp(char *small, char *big)
{
    int i;
    int j;
    int count;

    count = 0;
    i = 0;
    j = 0;
    while (big[j] != '\0')
    {
        if (small[i] == big[j])
        {
            count++;
            i++;
        }
        j++;
    }
    if (count == ft_strlen(small))
    {
        ft_putchar('1');
        ft_putchar('\n');
    }
    else
    {
        ft_putchar('0');
        ft_putchar('\n');
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
        ft_putchar('\n');
    else
        hidenp(argv[1], argv[2]);
}