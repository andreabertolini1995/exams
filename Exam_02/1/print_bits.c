/* Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END. */

#include <unistd.h>
#include <stdio.h>

// void	print_bits(unsigned char octet)
// {
//     int	i;
// 	unsigned char 	bit;

//     i = 7;
// 	while (i > 0)
// 	{
// 		bit = (octet >> i & 1) + '0';
// 		write(1, &bit, 1);
//         i--;
// 	}
// }


int main()
{
	unsigned char octet;

	octet = 42;
	printf("%c\n", octet >> 7);
	print_bits(octet);

}
