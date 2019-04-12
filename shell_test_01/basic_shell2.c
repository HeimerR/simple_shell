#include "shell.h"

/**
 *signalc - no ctrl c
 *@a: not used
 **/
void signalc(int a)
{
	(void) a;
	write(STDOUT_FILENO, "\nGhost-in-the-shell-3 ", 22);
//	printf("\nGhost-in-the-shell-%i ", a);
	fflush(stdout);
}

/**
  * main - shell starting
  * @ac: number of arguments
  * @argvex: arguments
  * Return: Always (0);
**/
int main(int ac, char *argvex[])
{
	char *line = NULL;
	bus_t bus0 = {.stat = 0, .count = 0};
	bus_t *bus;
	char **argv;
	int confg;
	(void) ac;
	
	bus = &bus0;
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "Ghost-in-the-shell-1 ", 21);
	signal(SIGINT,  signalc);
	while ((confg = getstdin(&line)) != -1)
	{
		bus->count++;
		argv = create_argv(line, confg);
		if (argv && argv[0])
		{
			if (check_bltin(argv, line,  bus) != 0)
			check_argv(argv, argvex, bus->count, line);
		}
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "Ghost-in-the-shell-2 ", 21);
	}
		free(line);
	if (isatty(STDIN_FILENO))
		printf("\n");
/*
*	free_grid(argv);
*/
	return (0);
}
