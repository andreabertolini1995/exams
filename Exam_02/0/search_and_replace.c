/* Write a program that takes 3 arguments, the first argument is a string in which to replace a letter (2nd argument) by another one (3rd argument)*/

#include <unistd.h>

int    ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

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

char    *search_and_replace(char *str, char *old, char *new)
{
    int i;
    int j;
    int k;

    i = 0;
    while (str[i] != '\0')
    {
        j = 0;
        while (str[i] == old[j] && j < ft_strlen(old))
        {
            i++;
            j++;
        }
        if (ft_strlen(old) == j)
        {
            k = j - 1;
            while (k >= 0)
            {
                str[i - 1] = new[k];
                k--;
                i--;
            }
        }
        i++;
    }
    return (str);
}

int main(int argc, char **argv)
{
    if (argc != 4)
        ft_putchar('\n');
    else
        ft_putstr(search_and_replace(argv[1], argv[2], argv[3]));
}
