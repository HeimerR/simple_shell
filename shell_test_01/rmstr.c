#include "shell.h"
/**
* rmstr - removes string from another
* @str: main string
* @substr: string to remove
* Return: no return
*/
void rmstr(char *str, char *substr)
{
	int i = 0, j = 0;

	while (substr[i])
		i++;
	while (str[j + i])
	{
	str[j] = str[j + i];
	j++;
	}
	str[j] = '\0';
}
