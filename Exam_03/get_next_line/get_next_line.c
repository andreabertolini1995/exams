/* 
LINE
Your function must return a line that has been read from the file descriptor passed as parameter. 
The line should be returned including the '\n' in case there is one at the end of the line that has been read.

BUFFER
When you've reached the EOF, you must store the current buffer in a char * and return it.

NULL
If the buffer is empty you must return NULL. In case of error return NULL.
In case of not returning NULL, the pointer should be free-able.

MEMORY
Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions. Your function must be memory leak free.

FUNCTION
Calling your function get_next_line in a loop will therefore allow you to read the text avaiable on a file descriptor one line at a time until the end of the text, no matter the size or either the text or one of its lines.

FILE
Finally we consider that get_next_line has an undefined behaviour when reading from a binary file.*/

#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h>

char *get_next_line(int fd)
{
    int     i;
    int     readout;
    char    character;
    char    *buffer = malloc(10000); // could be higher

    i = 0;
    readout = 0;
    if (BUFFER_SIZE <= 0) // equal to zero
        return NULL;
    while ((readout = read(fd, &character, 1)) > 0) // reading one character at the time
    {
        buffer[i++] = character; // storing the character in the buffer
        if (character == '\n')
            break ;
    }
    buffer[i] = '\0'; // closing up the line
    if (readout == -1 || i == 0|| (!buffer[i - 1] && !readout)) // couldn't open the file or the file is empty 
    {
        free(buffer);
        return (NULL);
    }
    return (buffer);
}

int main()
{
    int i = 0;
    int fd = open("test.txt", O_RDONLY);
    while (i < 15)
    {
        printf("%s", get_next_line(fd));
        i++;
    }
}