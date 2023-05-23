#include "main.h"

/**
  * _getenv - the function name
  * @name: parameter of type const char *.
  * Return: char *.
 */
char *_getenv(char *name)
{
	int i;
	int len;
	char *env;
	char *env_name;
	char *env_value;

	len = _strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		env = environ[i];
		env_name = env;
		env_value = _strchr(env, '=');
		if (env_value == NULL)
		{
			continue;
		}
		if (_strncmp(env_name, name, len) == 0)
		{
			return (env_value + 1);
		}
	}
	return (NULL);
}
