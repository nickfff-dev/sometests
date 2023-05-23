#include "main.h"

/**
  * _strcmp - the function name
  * @s1: parameter of type char *.
  * @s2: parameter of type char *.
  * Return: int .
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	if (s1[i] != s2[i])
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}
