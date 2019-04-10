#include "shell.h"

/**
 * print_string - print string
 * @valist: valist
 * @opt: option to print
 * Return: count of bytes printed
 */
int print_string(char *str)
{
	int len = 0;

        if (str == NULL)
                return (_putchar("(null)", 6));
	for (; str[len]; len++)
		;
        return (_putchar(str, len));
}
