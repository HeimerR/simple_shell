#include "shell.h"
/**
* print_notfound - prints erro command not found
* @argv: arguments double pointer
* @argvex: arguments dlouble pointer with argv[0]
* @bus: carries variables
* @line: arguments as a single pointer
* Return: exit status 127
**/
int print_notfound(char **argv, char **argvex, bus_t *bus, char *line)
{
	int status, status2;
	pid_t child;

	child = fork();
	if (!child)
	{
		print_string(argvex[0]);
		write(STDOUT_FILENO, ": ", 2);
		print_integer(bus->count);
		write(STDOUT_FILENO, ": ", 2);
		print_string(argv[0]);
		write(STDOUT_FILENO, ": not found\n", 12);
		free_grid(argv);
		free(line);
		exit(127);
	}
	else
	{
		wait(&status);
		status2 = WEXITSTATUS(status);
		free(argv[0]);
	}
	return (status2);
}
/**
* execute - execute commands as a child process
* @argv: arguments as a doulble pointer
* @name: argv[0]
* @line: arguments as a single pointer
* Return: exit status
**/
int execute(char **argv, char *name, char *line)
{
	int status, status2;
	pid_t child;
	char *path;

	path = argv[0];
	free(name);
	child = fork();
	if (!child)
	{
		if (execve(path, argv, NULL) == -1)
		{
			perror(path);
		}
		free_grid(argv);
		free(line);
	}
	else
	{
		wait(&status);
		status2 = WEXITSTATUS(status);
	}
	free(path);
	return (status2);
}
/**
 * check_argv -  checks if the arguments is in PATH
 * @argv: arguments taken from getline
 * @argvex: arguments taken from main prototype
 * @bus: carries variables
 * @line: arguments as a single pointer
 * Return: -1 if the argument does not exist in PATH, other cases 0
 */
int check_argv(char **argv, char **argvex, bus_t *bus, char *line)
{
	struct stat st;
	char *clone_path;
	char *clone_path2;
	char *clone_path3;
	char *clone_path4;
	path_t *head_path;
	char *name;
	path_t *clone_path5;

	name = _strdup(argv[0]);
	clone_path = _getenv("PATH");
	if (clone_path && clone_path[0])
	{		head_path = create_list(clone_path);
		while (head_path)
		{		clone_path2 = str_concat(head_path->path, "/");
			clone_path3 = str_concat(clone_path2, argv[0]);
			if (stat(clone_path3, &st) == 0)
			{
				clone_path4 = argv[0];
				argv[0] = clone_path3;
				free(clone_path4);
				free(clone_path2);
				free(clone_path);
				free_list(head_path);
				return (execute(argv, name, line));
			}
			free(clone_path2);
			free(clone_path3);
			clone_path5 = head_path;
			free(head_path->path);
			head_path = head_path->next;
			free(clone_path5);
		}
		free_list(head_path);
	}
	free(clone_path);
	if (stat(argv[0], &st) == 0)
		return (execute(argv, name, line));
	free(name);
	return (print_notfound(argv, argvex, bus, line));
}
