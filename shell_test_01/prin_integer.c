#include "shell.h"

/**
 * print_integer - print integer
 * @number: number to print
 * Return: count of bytes printed
 */
int print_integer(int number)
{
	char *str;
	int bytes = 0, len = 0;

	str = number_to_string(number, 10);
	if (str == NULL)
		return (_putchar("(null)", 6));
	for (; str[len]; len++)
		;
	bytes += _putchar(str, len);
	free(str);
	return (bytes);
}
