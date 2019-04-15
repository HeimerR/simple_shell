#include "shell.h"
/**
 * main - copies the content of a file to another file.
 * @ac: number of arguments
 * @av: array of arguments
 * Return: Always 0.
 */
int print_env(int i)
{
	int file_from, j = 0, k = 0, brk = 0;
	ssize_t  l_read = 1024, l_write, close_file;
	char content[1024];

	file_from = open("env_file", O_RDONLY);
	if (file_from == -1)
		return (-1);
	while (brk == 0)
	{
		l_read = read(file_from, content, 1024);
		if (l_read == -1)
			return(-1);
		if (l_read != 1024)
			brk = 1;
		if (i == 1)
		{
			for(j = 0, k = 0; content[j]; j++)
			{
				if (content[j] == '\n')
				{
					for(k = j; content[j]; j++)
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
/*	{ dprintf(STDERR_FILENO, "Error: Can't close fd  %d\n", file_from);
		exit(100); }
	close_file = close(file_to);
	if (close_file == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't close fd  %d\n", file_to);
		exit(100); }*/
return (0);
}
