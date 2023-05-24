/* Write a program that takes a single string in snake_case format and converts it into a string
in lowerCalmelCase format. */

#include <stdlib.h>
#include <unistd.h>

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	count_underscores(char *str)
{
	int i;
	int underscore;

	underscore = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '_')
			underscore++;
		i++;
	}
	return (underscore);
}

char	*snake_to_camel(char *str)
{
	char *camel;
	int	i;
	int j;

	camel = (char *) malloc (sizeof(char) * (ft_strlen(str) - count_underscores(str)));
	if (camel == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '_')
		{
			i++;
			camel[j] = str[i] - 32;
		}
		else
			camel[j] = str[i];
		i++;
		j++;
	}
	return (camel);
}

int main(int argc, char **argv)
{
	char *str;

	if (argc != 2)
		ft_putchar('\n');
	else
	{
		str = snake_to_camel(argv[1]);
		ft_putstr(str, ft_strlen(argv[1]) - count_underscores(argv[1]));
		free(str);
	}
}