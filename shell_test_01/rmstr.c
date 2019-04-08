#include "shell.h"


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
