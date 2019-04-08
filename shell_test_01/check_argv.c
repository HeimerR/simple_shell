#include "shell.h"
/**
 * main - stat example
 *
 * Return: Always 0.
 */
int check_argv(char **argv, char *argvex, int count)
{
	unsigned int j = 0;
	struct stat st;
	char **paths;
	char *clone_path;
	
        if (stat(argv[0], &st) == 0)
		return (0);
	clone_path = _getenv("PATH");
	paths = _strtok(clone_path, ":");
	while (paths[j])
	{
		clone_path = str_concat(paths[j], "/");
		clone_path = str_concat(clone_path, argv[0]);
//		printf("%s:", clone_path);
       		if (stat(clone_path, &st) == 0)
        	{
		argv[0] = clone_path;
            //		printf(" FOUND\n");
			return (0);
       		}
		j++;
	}
        printf("%s: %d: %s: not found\n", argvex, count, argv[0]);
    return (-1);
}
