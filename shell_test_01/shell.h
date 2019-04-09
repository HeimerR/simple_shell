#ifndef _SHELL_H
#define _SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
extern char **environ;
typedef struct builtin
{
	char *input;
	int (*type)(char **argv);
} built_t;
typedef struct paths
{
	char *path;
	int len;
	struct paths *next;

}path_t;
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **create_argv(char *str, int len);
char **_strtok(char *str, char *delim);
int cmpstr(char *haystack, char *needle);
void rmstr(char *str, char *substr);
int check_argv(char **argv, char *argvex, int count);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);
char *_getenv(char *str);
int check_builtin(char **argv);
int f_exit(char **argv);
int f_env(char **argv);
int _strcmp(char *s1, char *s2);
path_t *create_list(char *str);
int add_node_end(path_t **head, char *str);
size_t print_list(path_t *h);
#endif
