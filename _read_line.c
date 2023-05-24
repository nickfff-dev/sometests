#include "main.h"

/**
  * read_line - the function name
  * Return: char *.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		perror("Error");
		exit(1);
	}
	if (line[0] == '\n')
	{
		free(line);
		exit(1);
	}
	else
	{
		if (line[nread - 1] == '\n')
		{
			line[nread - 1] = '\0';
			--nread;
		}
		return (line);
	}
}
