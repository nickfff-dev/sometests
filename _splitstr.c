#include "main.h"

/**
 * _strtow - the function name
 * @str: parameter of type char *.
 * Return: char **.
 */
char **spltstr(char *str)
{
	char **array;
	int i, j, k, l, words = 0, len = 0;

	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}
	for (i = 0; str[i]; i++)
	{
		len++;
	}
	array = malloc(sizeof(char *) * (len + 1));
	if (array == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			for (j = i; str[j] && str[j] != ' '; j++)
			{
				 ;
			}
			array[words] = malloc(sizeof(char) * (j - i + 1));
			if (array[words] == NULL)
			{
				for (k = 0; k < words; k++)
				{
					free(array[k]);
				}
				free(array);
				return (NULL);
			}
			for (l = 0; l < j - i; l++)
			{
				array[words][l] = str[i + l];
			}
			array[words][l] = '\0';
			words++;
			i = j;
		}
	}
	array[words] = NULL;
	return (array);
}
