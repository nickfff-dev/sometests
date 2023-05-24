#include "main.h"

/**
  * execute_command - the function name
  * @array: parameter of type char **.
  * Return: int .
 */
int execute_command(char **array)
{
	int status = 0;
	struct stat st;
	char **env;
	pid_t child_pid;
	int i, j;

	if (_strcmp(array[0], "exit") == 0)
	{
		free(array);
		exit(0);
	}
	if (_strcmp(array[0], "env") == 0)
	{
		env = environ;
		for (i = 0; env[i] != NULL; i++)
		{
			for (j = 0; env[i][j] != '\0'; j++)
			{
				_putchar(env[i][j]);
			}
			_putchar('\n');
		}
		free(array);
		return (0);
	}
	if (array[0][0] == '/')
	{
		if (stat(array[0], &st) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error");
				exit(1);
			}
			if (child_pid == 0)
			{
				if (execve(array[0], array, environ) == -1)
				{
					perror("Error");
					exit(1);
				}
			}
			else
			{
				wait(&status);
				free(array);
				return (0);
			}
		}
		else
		{
			perror("Error");
			free(array);
			return (1);
		}
	}
	else
	{
		status = execute_path_commands(array);
		return (status);
	}
	return (0);
}
