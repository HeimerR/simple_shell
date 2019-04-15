#include "shell.h"
/**
 * print_env - prints enviromental variables
 * @i: aux
 * Return: Always 0.
 */
int print_env(int i)
{
	int file_from, j = 0, k = 0, brk = 0;
	ssize_t  l_read = 1024, l_write, close_file;
	char content[1024];

	file_from = open("env_file", O_RDONLY);
	while (brk == 0)
	{
		l_read = read(file_from, content, 1024);
		if (l_read != 1024)
			brk = 1;
		if (i == 1)
		{
			for (j = 0, k = 0; content[j]; j++)
			{
				if (content[j] == '\n')
				{
					for (k = j; content[j]; j++)
						content[j] = content[j + 1];
					l_read--;
					j = k;
				}
			}
			j = k;
		}
		l_write = write(STDOUT_FILENO, content, l_read);
		if (l_write == -1)
		return (-1);
	}
	close_file = close(file_from);
	if (close_file == -1)
		return (-1);
return (0);
}
