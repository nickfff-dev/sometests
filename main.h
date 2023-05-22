#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
char **spltstr(char *str);
char *_strcat(char *dest, char *src);
char *_getenv(char *name);
int _strlen(char *s);

#endif