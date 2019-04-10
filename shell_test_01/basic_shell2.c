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
	pid_t child;
	char **argv;
	int confg, count = 0;
	(void) ac;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "Ghost-in-the-shell-1 ", 21);
	signal(SIGINT,  signalc);
	while ((confg = getstdin(&line)) != -1)
	{
		count++;
		argv = create_argv(line, confg);
		if (argv && argv[0])
		{
			if (check_bltin(argv, line) != 0 && check_argv(argv, argvex[0], count) == 0)
			{
				child = fork();
				if (!child)
				{
					if (execve(argv[0], argv, NULL) == -1)
						perror(argvex[0]);
					free_grid(argv);
					free(line);
					exit(0);
				}
				else
					wait(NULL);
			}
		}
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "Ghost-in-the-shell-2 ", 21);
	}
		free(line);
	if (isatty(STDIN_FILENO))
		printf("\n");
	return (0);
}
