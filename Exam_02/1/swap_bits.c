/* Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

A byte is 8 bits. Example: 10110101. */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

unsigned char	swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}

// int	main(int argc, char **argv)
// {
// 	unsigned char c;

//     (void) argc;
// 	c = atoi(argv[1]);
//     printf("%d\n", c);
//     printf("%d\n", swap_bits(c));
// 	return (0);
// }
