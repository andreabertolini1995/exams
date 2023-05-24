/* Reproduce exactly the behavior of the function strcspn
(man strcspn). 

The strcspn() function spans the initial part of the null-terminated string s as long as the characters from s do not occur in the null-terminated string charset (it spans the complement of charset).  In other words, it computes the string array index of the first character of s which is also in charset, else the index of the first null character.*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int   is_char_in_charset(char c, const char *charset)
{
    int i;

    i = 0;
    while (charset[i] != '\0')
    {
        if (charset[i] == c)
            return (1);
        i++;
    }
    return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (is_char_in_charset(s[i], reject))
            return (i);
        i++;
    }
    return (i);
}

// int main()
// {
//     const char *str;
//     const char *reject;

//     str = "Weila  sheial";
//     reject = "t";
//     if (strcspn(str, reject) == ft_strcspn(str, reject))
//         printf("Ok");
//     else
//         printf("No");
// }