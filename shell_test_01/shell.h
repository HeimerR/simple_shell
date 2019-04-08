#ifndef _SHELL_H
#define _SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **create_argv(char *str, int len);
char **_strtok(char *str, char *delim);
int cmpstr(char *haystack, char *needle);
void rmstr(char *str, char *substr);
int check_argv(char **argv);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);
char *_getenv(char *str);
#endif
