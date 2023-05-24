/* Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.*/

#include <stdio.h>

int		max(int* tab, unsigned int len)
{
    unsigned int i;
    int max;

    i = 0;
    max = tab[i];
    i++;
    while (i < len)
    {
        if (tab[i] > max)
            max = tab[i];
        i++;
    }
    return (max);
}

int main()
{
    int tab[5] = {3, 42, 7, 1, 32};

    printf("%d\n", max(tab, 5));
}