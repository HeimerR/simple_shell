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
/**
 * struct builtin - built-in functions
 * @input: string - function name (built-in)
 * @type: pointer ti built-in function
 *
 * Description: holds and match names with built-in
 *  functions
 */
typedef struct builtin
{
	char *input;
	int (*type)(char **argv, char *line);
} built_t;
/**
 * struct paths - singly linked list
 * @path: string - (malloc'ed string) - single path
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 *  holds single paths from variable PATH
 */
typedef struct paths
{
	char *path;
	int len;
	struct paths *next;
} path_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
char **create_argv(char *str, int len);
char **_strtok(char *str, char *delim);
int cmpstr(char *haystack, char *needle);
void rmstr(char *str, char *substr);
int check_argv(char **argv, char *argvex, int count);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);
char *_getenv(char *str);
int check_bltin(char **argv, char *line);
int f_exit(char **argv, char *line);
int f_env(char **argv, char *line);
int _strcmp(char *s1, char *s2);
ssize_t getstdin(char **lineptr);
path_t *create_list(char *str);
int add_node_end(path_t **head, char *str);
size_t print_list(path_t *h);
void free_grid(char **grid);
void free_list(path_t *head_path);
#endif
