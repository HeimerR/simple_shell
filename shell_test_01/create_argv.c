#include "shell.h"
/**
* create_argv - reallocates a memory block
* @ptr: initial pointer
* @old_size: initial size
* @new_size: new size
* Return: pointer to array
*/
char **create_argv(char *str, int len)
{
	char **argv;
	unsigned int i = 0;
	
	str[len - 1] = '\0';
	argv = _strtok(str, " ");	
	while (argv && argv[i])
	{
	i++;
	}
return(argv);
}
