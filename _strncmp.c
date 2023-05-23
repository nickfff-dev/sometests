#include "main.h"

/**
  * _strncmp - the function name
  * @s1: parameter of type const char *.
  * @s2: parameter of type const char *.
  * @n: parameter of type size_t .
  * Return: int .
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	if (i != n)
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}
