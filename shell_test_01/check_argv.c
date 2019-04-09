#include "shell.h"
/**
 * check_argv -  checks if the arguments is in PATH
 *
 * Return: -1 if the argument does not exist in PATH, other cases 0
 */
int check_argv(char **argv, char *argvex, int count)
{
	struct stat st;
	(void) argv;
	(void) argvex;
	(void) count;
	char *clone_path;
	char *clone_path2;
	path_t *head_path;
	
	clone_path = _getenv("PATH");

	if(clone_path && clone_path[0])
	{
		head_path = create_list(clone_path);
		while (head_path)
		{
			clone_path2 = str_concat(head_path->path, "/");
			clone_path2 = str_concat(clone_path2, argv[0]);
	       		if (stat(clone_path2, &st) == 0)
	        	{
			argv[0] = clone_path2;
				return (0);
	       		}
			head_path = head_path->next;
		}
	}
	if (stat(argv[0], &st) == 0)
		return (0);		
        printf("%s: %d: %s: not found\n", argvex, count, argv[0]);
    	return (-1);
}
