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
char * _strdup(char *str);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
#endif
