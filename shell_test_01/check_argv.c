#include "shell.h"
/**
 * check_argv -  checks if the arguments is in PATH
 * @argv: arguments taken from getline
 * @argvex: arguments taken from main prototype
 * @count: counter - number of getline calls
 * Return: -1 if the argument does not exist in PATH, other cases 0
 */
int check_argv(char **argv, char *argvex, int count)
{
	struct stat st;
	char *clone_path;
	char *clone_path2;
	char *clone_path3;
	char *clone_path4;
	path_t *head_path;

	clone_path = _getenv("PATH");
	if (clone_path && clone_path[0])
	{
		head_path = create_list(clone_path);
		while (head_path)
		{
			clone_path2 = str_concat(head_path->path, "/");
			clone_path3 = str_concat(clone_path2, argv[0]);
			if (stat(clone_path3, &st) == 0)
			{
				clone_path4 = argv[0];
				argv[0] = clone_path3;
				free(clone_path4);
				free(clone_path2);
				free(clone_path);
				free_list(head_path);
				return (0);
			}
			free(clone_path2);
			free(clone_path3);
			head_path = head_path->next;
		}
		free_list(head_path);
	}
	free(clone_path);
	if (stat(argv[0], &st) == 0)
	{
		return (0);
	}
	printf("%s: %d: %s: not found\n", argvex, count, argv[0]);
	return (-1);
}
