#include "main.h"

/**
 * _strchr -  returns pointer to first occurence of a char
 * @s: the string to look in
 * @c: the char to find
 * Return: pointer to char or NULL
 */

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (s + i);
		}
	}
	if (s[i] == c)
	{
		return (s + i);
	}
	return (NULL);
}
