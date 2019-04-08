#include "shell.h"

int f_exit(char **argv)
{
	(void) argv;

	exit(0);
return(0);
}


int f_env(char **argv)
{
	int i = 0;
	(void) argv;

	while(environ[i])
		printf("%s\n", environ[i++]);
return (0);
}
