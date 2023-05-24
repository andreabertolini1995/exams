/* Write a program that takes three strings:
    - The first and the third one are representartions of base-10 signed integers that fit in an int
    - The second one is an arithmetic operator chosen from: + - * / %
The program must display the result of the requested arithmetic operation, followed by a newline,.
*/

#include <stdio.h>
#include <stdlib.h>

void    do_op(int n1, char op, int n2)
{
    int result;

    result = 0;
    if (op == '*')
        result = n1 * n2;
    else if (op == '/')
        result = n1 / n2;
    else if (op == '+')
        result = n1 + n2;
    else if (op == '-')
        result = n1 - n2;
    else if (op == '%')
        result = n1 % n2;
    printf("%d\n", result);
}

int main(int argc, char **argv)
{
    if (argc != 4)
        printf("\n");
    else
        do_op(atoi(argv[1]), argv[2][0], atoi(argv[3]));
}