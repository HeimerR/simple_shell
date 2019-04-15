 #include "shell.h"

/**
 * getstdin - getline but only on stdin
 * @lineptr: the buffer
 *
 * Return: number of characters readed
 */

ssize_t getstdin(char **lineptr)
{
	unsigned int len = 8, readed = 0;
	char ch;
	ssize_t confr = 0;

	lineptr[0] = malloc(sizeof(lineptr[0]));
	while ((confr = read(STDIN_FILENO, &ch, 1)) > 0)
	{
		readed++;
		if (readed > len && len >= 8)
		{
			lineptr[0] = _realloc(*lineptr, len, readed);
			len = readed;
		}
		lineptr[0][readed - 1] = ch;
		if (ch == '\n')
			break;
	}
	if (confr == 0)
		return (-1);
	if (readed < len && len > 8)
		*lineptr = _realloc(*lineptr, len, readed);
	return (confr = readed);
}
