 #include "shell.h"

/**
 * getstdin - getline but only on stdin
 * @lineptr: the buffer
 *
 * Return: number of characters readed
 */

ssize_t getstdin(char **lineptr)
{
	unsigned int len = 0/*, i = 0, nul = 0*/;
	char ch;
	ssize_t readed = len, confr = 0;

	*lineptr = malloc(sizeof(char) * 1);
	for (; lineptr[len]; len++)
		;
	while ((confr = read(STDIN_FILENO, &ch, 1)) > 0)
	{
		readed++;
		if (readed > len)
		{
			*lineptr = _realloc(*lineptr, len, readed);
			len = readed;
		}
		lineptr[0][readed - 1] = ch;
		if (ch == '\n')
			break;
	}
	if (confr == 0)
		return (-1);
	if (readed < len)
		*lineptr = _realloc(*lineptr, len, readed);
	return (readed);
}
