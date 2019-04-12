#include "shell.h"
/**
* check_bltin - check if an argument is a built-in function
* @argv: arguments as a dlouble pointer
* @line: arguments as a single string
* Return: 1 if not is a built in. 0 If it is
*/
int check_bltin(char **argv, char *line, bus_t *bus)
{
	int j = 0;
	int status = 1;
	pid_t child;

	built_t built[] = {
		{"exit", f_exit},
		{"env", f_env},
	/*	{"alias", f_alias},  */
		{NULL, NULL}
		};
	while (built[j].input != NULL)
	{
		if (_strcmp(argv[0], built[j].input) == 0)
		{
			child = fork();
			if (!child)
			{
				status = built[j].type(argv, line, bus);
				exit(0);
			}
			else
				wait(NULL);
				break;
		}
		j++;
	}
	return (status);
}
