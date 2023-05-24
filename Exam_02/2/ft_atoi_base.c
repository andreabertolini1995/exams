/* Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.*/

#include <stdio.h>
#include <stdlib.h>

int is_valid(char c)
{
    char digits[17] = "0123456789abcdef";
    char digits2[17] = "0123456789ABCDEF";
    int i;

    i = 0;
    while (i < 16)
    {
        if (c == digits[i] || c == digits2[i])
            return (1);
        i++;
    }
    return (0);
}

int value_of(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    else if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10); // only partially clear the 10 here
    else if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (0);
}

int ft_atoi_base(const char *str, int str_base)
{
    int i;
    int sign;
    int final_number;

    final_number = 0;
    sign = 1;
    i = 0;
    while (str[i] == ' ' || (str[i] == '\t' && str[i] <= '\r'))
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (is_valid(str[i]))
    {
        final_number = final_number * str_base + value_of(str[i]);
        i++;
    }
    return (final_number * sign);
}

int main(int argc, char **argv)
{
    if (argc == 3)
        printf("%d\n", ft_atoi_base(argv[1], atoi(argv[2])));
    return (0);
}