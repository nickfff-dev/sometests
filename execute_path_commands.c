#include "main.h"

/**
  * execute_path_commands - the function name
  * @array: parameter of type char **.
  * Return: int .
 */
int execute_path_commands(char **array)
{
	int status = 0;
	char *path_env = NULL;
	struct stat st;
	char *path = NULL;
	char *token, *path_env_copy;
	pid_t child_pid;

	path_env = _getenv("PATH");
	if (path_env == NULL)
	{
		perror("Error");
		exit(1);
	}
	path_env_copy = _strdup(path_env);
	if (path_env_copy == NULL)
	{
		perror("Error");
		exit(1);
	}
	token = strtok(path_env_copy, ":");
	while (token != NULL)
	{
		path = malloc(sizeof(char) *
		(_strlen(token) + _strlen(array[0]) + 2));
		if (path == NULL)
		{
			perror("Error");
			exit(1);
		}
		path = _strcat(path, token);
		path = _strcat(path, "/");
		path = _strcat(path, array[0]);
		if (stat(path, &st) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				exit(1);
			}
			if (child_pid == 0)
			{
				if (execve(path, array, environ) == -1)
				{
					perror("Error");
					exit(1);
				}
			}
			else
			{
				wait(&status);
				free(array);
				free(path);
				free(path_env_copy);
				return (0);
			}
		}
		else
		{
			free(path);
			token = strtok(NULL, ":");
			continue;
		}
	}
	free(path_env_copy);
	return (1);
}
