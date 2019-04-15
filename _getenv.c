 #include "shell.h"
/**
 * _getenv - get a envioromental variable.
 * @name: variable to read
 * Return: value of the variable.
 */
char *_getenv(char *name)
{
	unsigned int j = 0, i = 0, brk = 0;
	char **variable;
	char *aux;
	int file_from, l_read;
	char content[1100];

	if (content == NULL)
		return (NULL);
	name =  str_concat(name, "=");
	file_from = open("env_file", O_RDONLY);
	while (brk == 0)
	{		l_read = read(file_from, content, 1024);
		for (j = l_read; j < 1100; j++)
			content[j] = '\0';
		if (l_read == -1)
			return (NULL);
		variable = _strtok(content, "\n");
		for (i = 0; variable[i] && brk != 1; i++)
		{
			if (cmpstr(variable[i], name) == 1)
				brk = 1;
			if (brk != 1)
				free(variable[i]);
		}
		if (brk != 1)
			free(variable);
		if (l_read != 1024 && brk != 1)
			brk = 2;
	}
	free(name);
	if (brk == 1)
	{
		for (j = i; variable[j]; j++)
			free(variable[j]);
		aux = _strdup(variable[i - 1]);
		free(variable[i - 1]);
		free(variable);
		return (aux);
	}
	return ("-1");
}
