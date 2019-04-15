#include "shell.h"

/**
* f_env - prints envioroment variables
* @argv: unused
* @line: arguments as a single pointer.
* Return: always 0
*/
int f_setenv(char **argv, char *line, bus_t *bus)
{
	int len = 0, file_from, confw = 0, close_file = 0;
	char *confenv;
	(void) bus;
	(void) line;

	if (!argv[1] || !argv[2] || argv[3])
		exit(-1);
	file_from = open("env_file", O_RDWR | O_APPEND);
	if (file_from == -1)
		exit(-1);
	confenv = _getenv(argv[1]);
	if(_strcmp(confenv, "-1") == 0)
	{
		for (len = 0; argv[1][len]; len++)
			;
		confw = write(file_from, argv[1], len);
		if (confw == -1)
			exit(-1);
		confw = write(file_from, "=", 1);
		if (confw == -1)
			exit(-1);
	}
	for (len = 0; argv[2][len]; len++)
		;
	confw = write(file_from, argv[2], len);
	if (confw == -1)
		exit(-1);
	confw = write(file_from, "\n", 1);
	if (confw == -1)
		exit(-1);
	close_file = close(file_from);
	if (close_file == -1)
		return (-1);
	exit(0);
return (0);
}

/**
* f_exit - exit function - exit the shell
* @argv: unused
* @line: arguments as a single pointer.
* Return: always 0
*/
int f_exit(char **argv, char *line, bus_t *bus)
{
	int argmt;
	(void) bus;

	if (argv[1])
	{
		argmt = _atoi(argv[1]);
		if (argmt < 0)
		{
			print_exit_error(argv, bus, argmt);
			free_grid(argv);
			free(line);
			exit(2);
		}
		else
		{
			free_grid(argv);
			free(line);
			exit(253);
		}
	}
	free_grid(argv);
	free(line);
	exit(254);
	return (0);
}
/**
* f_env - prints envioroment variables
* @argv: unused
* @line: arguments as a single pointer.
* Return: always 0
*/
int f_env(char **argv, char *line, bus_t *bus)
{
	int i = 0, j = 0;
	for (; argv[j]; j++)
	{
		if (argv[j][0] == '-')
		{
			if (argv[j][1] == '0' && i != 2)
				i = 1;
			else if (argv[j][1] == 'i')
				i = 2;
			else if (argv[j][1] != '0')
			{
				line[0] = argv[j][1];
				line[1] = '\0';
				write(1, "env: invalid option -- '", 24);
				print_string(line);
				write(1, "'\n", 2);
				exit(125);
			}
		}
	}
	(void) bus;

	if (i != 2)
		j = print_env(i);
	exit(j);
return (0);
}
void print_exit_error(char **argv, bus_t *bus, int argmt)
{
	print_string(bus->arg0);
	write(STDOUT_FILENO, ": ", 2);
	print_integer(bus->count);
	write(STDOUT_FILENO, ": ",2);
	print_string(argv[0]);
	write(STDOUT_FILENO, ": Illegal number:", 17);
	print_integer(argmt);
	write(STDOUT_FILENO, "\n", 1);
}
