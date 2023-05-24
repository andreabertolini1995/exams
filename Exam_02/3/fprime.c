/* Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline. */

#include <stdio.h>
#include <stdlib.h>

int    smallest_divisible_prime(int n)
{
    int i;

    i = 2;
    if (n == 1)
        return (1);
    while (i)
    {
        if (n % i == 0)
            return (i);
        i++;
    }
    return (i);
}

void    fprime(int n)
{    
    while (smallest_divisible_prime(n) > 1)
    {
        printf("%d", smallest_divisible_prime(n));  
        n = n / smallest_divisible_prime(n);
        if (n != 1)
            printf("*");
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        printf("\n");
    else if (atoi(argv[1]) == 1)
        printf("%d\n", 1);
    else
        fprime(atoi(argv[1]));
}
