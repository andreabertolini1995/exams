/* Write a function who takes two unsigned int as parameters and returns the 
computed LCM of those parameters.*/

#include <stdio.h>

int min(unsigned int a, unsigned int b)
{
    if (a <= b)
        return (a);
    else
        return (b);
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
    int i;
    int lcm;

    lcm = 0;
    if (a == 0 || b == 0)
        return (lcm);
    i = min(a, b);
    while (i)
    {
        if (i % a == 0 && i % b == 0)
        {
            // printf("%d\n", i);
            lcm = i;
            return (lcm);
        }
        i++;
    }
    return (lcm);
}

// int main()
// {
//     int a;
//     int b;

//     a = 42;
//     b = 17;
//     lcm(a, b);
// }