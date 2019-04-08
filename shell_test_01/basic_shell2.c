#include "shell.h"

/**
 *signalc - no ctrl c
 *
 **/
void signalc()
{
        printf("\nGhost-in-the-shell-3 ");
        fflush(stdout);
}

/**
  * main - shell starting
  *
  * Return: Always (0);
**/
int main(int ac, char *argvex[])
{
	char *line = NULL;
	size_t len = 1;
	pid_t child;
	char **argv;
	int confg, count = 0;
	(void) ac;

	if (isatty(STDIN_FILENO))
		printf("Ghost-in-the-shell-1 ");
	signal(SIGINT,  signalc);
	while ((confg = getline(&line, &len, stdin)) != -1)
	{
		count++;
		argv = create_argv(line, confg);
		if(argv && argv[0])
		{
			if (check_builtin(argv) != 0 && check_argv(argv, argvex[0], count) == 0)
			{
				child = fork();
				if (!child)
				{
					if (execve(argv[0], argv, NULL) == -1)
					{
						perror(argvex[0]);
					}
					exit(0);
				}
				else
				{
					wait(NULL);
				}
			}	
		}
		if (isatty(STDIN_FILENO))
		{
			printf("Ghost-in-the-shell-2 ");
		}
		len = 1;
	}
	free(line);
	if (isatty(STDIN_FILENO))
	printf("\n");
	return (0);
}
