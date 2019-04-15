#include "shell.h"
/**
* check_bltin - check if an argument is a built-in function
* @argv: arguments as a dlouble pointer
* @line: arguments as a single string
* @bus: carries variables
* Return: 1 if not is a built in. 0 If it is
*/
int check_bltin(char **argv, char *line, bus_t *bus)
{
	int j = 0;
	int status = 1, status2, status3;
	pid_t child;

	built_t built[] = {
		{"exit", f_exit},
		{"env", f_env},
		{"setenv", f_setenv},
	/*	{"alias", f_alias},  */
		{NULL, NULL}
		};

	while (built[j].input != NULL)
	{
		if (_strcmp(argv[0], built[j].input) == 0)
		{
			child = fork();
			if (!child)
				status = built[j].type(argv, line, bus);
			else
			{ waitpid(-1, &status, 0);
				status2 = WEXITSTATUS(status);
				if (status2 == 254)
				{ free_grid(argv);
					free(line);
					exit(bus->stat);
					break; }
				if (status2 == 253)
				{ status3 = _atoi(argv[1]);
					free_grid(argv);
					free(line);
					exit(status3);
					break; }
				bus->stat = status2;
				status = 0; }
			free(argv[0]);
			break;
		}
		j++;
	}
	return (status);
}
