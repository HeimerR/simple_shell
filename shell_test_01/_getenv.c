#include "shell.h"
/**
 * main - stat example
 *
 * Return: Always 0.
 */
char *_getenv(char *name)
{
	unsigned int j = 0;
	char *clone_value;
	char *variable;

	variable =  str_concat(name, "=");
	while(environ[j]) 
	{
	if (cmpstr(environ[j], variable) == 1)
		break;
	j++;
	}
	clone_value = _strdup(environ[j]);
	if (clone_value)
		rmstr(clone_value, variable);
	return (clone_value);
}

