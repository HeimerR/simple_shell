#include "shell.h"
/**
* check_bltin - check if an argument is a built-in function
* @argv: arguments as a dlouble pointer
* @line: arguments as a single string
* Return: 1 if not is a built in. 0 If it is
*/
int check_bltin(char **argv, char *line)
{
	int j = 0;
	int status = 1;

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
			status = built[j].type(argv, line);
			break;
		}
		j++;
	}
	return (status);
}
