/* Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.*/

#include <unistd.h>

void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
        // print_bits(res);
        // write(1, &"\n", 1);
		octet = octet / 2;
		i--;
	}
	return (res);
}

int main()
{
    unsigned char octet = 21;
    unsigned char res;

    print_bits(octet);
    res = reverse_bits(octet);
    write(1, &"\n", 1);
    print_bits(res);
}


// unsigned char	reverse_bits(unsigned char octet)
// {
//     unsigned char   res;
//     int             i;

//     i = 8;
//     res = 0;
//     while (i > 0)
//     {
//         res = res * 2 + (octet % 2);
//         octet = octet / 2;
//         i--;
//     }
//     return (res);
// }

// void print_bits(unsigned char octet)
// {
//     unsigned char   bit;
//     int             i;

//     i = 7;
//     while (i > 0)
//     {
//         bit = (octet >> i & 1) + '0';
//         write(1, &bit, 1);
//         i--;
//     }
// }

// unsigned char swap_bits(unsigned char octet)
// {
//     return (octet >> 4 | octet << 4);
// }
