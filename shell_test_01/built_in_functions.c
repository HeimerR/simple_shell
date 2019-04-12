#include "shell.h"
/**
* f_exit - exit function - exit the shell
* @argv: unused
* @line: arguments as a single pointer.
* Return: always 0
*/
int f_exit(char **argv, char *line, bus_t *bus)
{
	(void) argv;
	(void) bus;
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
int f_env(char **argv, char *line, bus_t *bus)
{
	int i = 0;
	(void) argv;
	(void) line;
	(void) bus;

	while (environ[i])
	{
		print_string(environ[i++]);
		write(STDOUT_FILENO, "\n", 1);
	}
	/**
	 *	printf("%s\n", environ[i++]);
	 */
return (0);
}
