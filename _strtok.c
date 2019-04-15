#include "shell.h"
/**
* finallyfree - free memory
* @i: interator
* @p: pointer
*/
void finallyfree(char **p, int i)
{
	int j;

	for (j = 0; j < i; j++)
	{
		free(p[j]);
	}
	free(p);
}
/**
* _strtok - concatenates all the arguments of your program
* @str: array
* @delim: delimiter
* Return: duble pointer
*/
char **_strtok(char *str, char *delim)
{
	int k = 0, i = 0, count = 0, height = 0, word = 0;
	char **p;

	if (str == 0 || *str == 0)
		return (NULL);
	while (str[i] != '\0')
	{
		count++;
		if (str[i] != delim[0] && str[i + 1] ==  delim[0])
		{ height++; }
	i++;
	}
	height++;
	if (height == 0)
		return (NULL);
	p = (char **)malloc(sizeof(char *) * (height + 1));
	if (p  == NULL)
		return (NULL);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] !=  delim[0])
			count++;
		if (count > 0 && (str[i + 1] ==  delim[0] || str[i + 1] == '\0'))
		{
			p[word] = (char *)malloc((count + 1) * sizeof(char));
			if (p[word] == NULL)
			{ finallyfree(p, word);
				return (NULL); }
			for (k = 0; k < count; k++)
				p[word][k] = str[i - count + 1 + k];
			p[word][k] = '\0';
			word++;
			count = 0;
		}
		i++;
	}
	p[height] = '\0';
	return (p);
}
