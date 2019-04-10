#include "shell.h"
/**
* f_exit - exit function - exit the shell
* @argv: unused
* @line: arguments as a single pointer.
* Return: always 0
*/
int f_exit(char **argv, char *line)
{
	(void) argv;
	free_grid(argv);
	free(line);
	exit(127);
	return (0);
}
/**
* f_env - prints envioroment variables
* @argv: unused
* @line: arguments as a single pointer.
* Return: always 0
*/
int f_env(char **argv, char *line)
{
	int i = 0;
	(void) argv;
	(void) line;

	while (environ[i])
		printf("%s\n", environ[i++]);
return (0);
}
