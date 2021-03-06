#include "shell.h"

/**
 * reverse_str - reverse string
 * @str: string to reverse
 * @size: size of string
 * @keep_first: Keep first element in str like first
 */
void reverse_str(char *str, int size, char keep_first)
{
	int length, iterator;
	char aux;

	if (keep_first)
		reverse_str(str + 1, size - 1, 0);
	else
	{
		length = size % 2 == 0 ? size / 2 : ((size / 2) + 1);
		for  (iterator = 0; iterator < length; iterator++)
		{
			aux = str[iterator];
			str[iterator] = str[size - iterator - 1];
			str[size - iterator - 1] = aux;
		}
	}
}


/**
 * number_to_string - convert number to string
 * you should free the pointer returned
 * @number: number to be printed
 * @base: base to be converted  if want in hexa wit capital letters
 * Return: string converted
 */
char *number_to_string(int number, char base)
{
	int lengh = 0, aux;
	char sign, numbers[] = "0123456789abcdef", *p = malloc(1);

	sign = number < 0;
	if (p == NULL || base > 17)
		return (NULL);
	do {
		if (number < 0)
		{
			p[0] = base == 2 ? '1' : '-';
			lengh++;
			p = _realloc(p, lengh, lengh + 1);
			aux = base == 17 ? number % (base - 1) : number % base;
			p[lengh] = numbers[-aux];
			if (base == 17 && -aux > 9)
				p[lengh] = p[lengh] - 'a' + 'A';
			aux = base == 17 ?  number / (base - 1) : number / base;
			number = -aux;
		}
		else
		{
			if (base == 17)
			{
				p[lengh] = numbers[number % (base - 1)] - 'a' + 'A';
				number /=  (base - 1);
			}
			else
			{
				p[lengh] = numbers[number % base];
				number /=  base;
			}
		}
		lengh++;
		p = _realloc(p, lengh, lengh + 1);
		if (p == NULL)
			return (NULL);
		p[lengh] = '\0';
	} while (number);
	reverse_str(p, lengh, sign);
	return (p);
}
