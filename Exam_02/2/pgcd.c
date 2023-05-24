/* Write a program that takes two strings representing two strictly positive integers that fit in an int.
Display their highest common denominator followed by a newline (It's always a
strictly positive integer).*/

#include <stdio.h>
#include <stdlib.h>

int min(int n1, int n2)
{
	if (n1 <= n2)
		return (n1);
	else
		return (n2);
}

int find_higher_common_denominator(int n1, int n2)
{
	int	i;     
	int den;

	i = 0;
	den = 1;
	while (i < min(n1, n2))
	{
		if (n1 % (i + 1) == 0 && n2 % (i + 1) == 0)
			den = i + 1;
		i++;
	}
	return (den);
}

int main(int argc, char **argv)
{
	if (argc != 3)
		printf("\n");
	else
		printf("%d\n", find_higher_common_denominator(atoi(argv[1]), atoi(argv[2])));
}
	