#include "shell.h"
/**
 * ignore_comments - get a envioromental variable.
 * @line: variable to read
 * Return: no return
 */
void ignore_comments(char *line)
{
	int i = 0;
	int flag = 0;

	while (line[i])
	{
		if (line[i] == '#')
		{
			line[i] = ' ';
			while (line[i])
				line[i++] = ' ';
			flag = 1;
		}
	if (flag == 0)
		i++;
	}
}

