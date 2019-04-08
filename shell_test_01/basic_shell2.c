#include "shell.h"
/**
  * main - shell starting
  *
  * Return: Always (0);
**/
int main(void)
{
	char *line = NULL;
	size_t len = 1;
	pid_t child;
	char **argv;
	int confg;

	if (isatty(STDIN_FILENO))
		printf("Ghost-in-the-shell-1 ");
	while ((confg = getline(&line, &len, stdin)) != -1)
	{
		argv = create_argv(line, confg);
		if(argv && argv[0])
		{
			check_argv(argv);
			child = fork();
			if (!child)
			{
				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("./shell");
				}
				exit(98);
			}
			else
			{
				wait(NULL);
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
