#include "shell.h"
/**
* create_argv - transforms getline into double pointer arrays
* @str: pointer to arguments
* @len: arguments length
*
* Return: doble pointer with arguments
*/
char **create_argv(char *str, int len)
{
	char **argv;

	str[len - 1] = '\0';
	argv = _strtok(str, " ");
	return (argv);
}
