 #include "shell.h"
/**
 * _getenv - get a envioromental variable.
 * @name: variable to read
 * Return: value of the variable.
 */
char *_getenv(char *name)
{
	unsigned int j = 0, i = 0, brk = 0;
/*	char *clone_value;*/
	char **variable;
	int file_from, l_read;
	char content[1024];

/*	variable[0] =  str_concat(name, "=");*/
	file_from = open("env_file", O_RDONLY);
	while (brk == 0)
	{
		l_read = read(file_from, content, 1024);
		if (l_read == -1)
			return (NULL);
		variable = _strtok(content, "\n");
		for (i = 0; variable[i] && brk != 1; i++)
		{
			if (cmpstr(variable[i], name) == 1)
				brk = 1;
		}
		if (l_read != 1024 && brk != 1)
			brk = 2;
		j++;
	}
/*	clone_value = _strdup(environ[j]);
	if (clone_value)
	rmstr(clone_value, variable);
	free(variable);*/
	if (brk == 1)
		return (variable[i - 1]);
	return (NULL);
}
