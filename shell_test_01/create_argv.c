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
	
	str[len - 1] = '\0';
	argv = _strtok(str, " ");	
return(argv);
}
