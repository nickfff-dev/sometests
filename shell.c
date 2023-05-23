#include "main.h"

/**
  * main - The entry point of the program
  * Return: int .
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;

	ssize_t nread;
	pid_t child_pid;
	int status;
	char **array = NULL;

	struct stat st;
	char *path = NULL;
	char *path_env = NULL;
	char *token;
	char *path_env_copy;

	while (1)
	{
		printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			perror("Error");
			exit(1);
		}
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		else
		{
			if (line[nread - 1] == '\n')
			{
				line[nread - 1] = '\0';
				--nread;
			}
			array = spltstr(line);
			if (array == NULL)
			{
				perror("Error");
				free(line);
				continue;
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
						free(line);

					}
				}
				else
				{
					perror("Error");
					free(array);
					free(line);
					continue;
				}
			}
			else
			{
				path_env = _getenv("PATH");
				if (path_env == NULL)
				{
					perror("Error");
					continue;
				}
				path_env_copy = _strdup(path_env);
				if (path_env_copy == NULL)
				{
					perror("Error");
					continue;
				}
				for (token = strtok(path_env_copy, ":"); token != NULL; token = strtok(NULL, ":"))
				{
					path = (char *)malloc(sizeof(char) * (_strlen(token) + _strlen(array[0]) + 2));
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
							break;
						}

				}
					else
					{
						free(path);
						continue;
					}
			
			}
				free(path_env_copy);
				continue;
			
			}
		}}
		
}
