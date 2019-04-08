#include "shell.h"
int check_builtin(char **argv)
{
	int j = 0;
	int status = 1;
	built_t built[] = {
		{"exit", f_exit},
		{"env", f_env},
//		{"alias", f_alias},
		{NULL, NULL}
		};
	while (built[j].input != NULL)
	{
//		 printf("hola a todos argv[0]:%s\n", argv[0]);
//		 printf("hola a todos structure:%s\n", built[j].input);
		if (_strcmp(argv[0], built[j].input) == 0)
		{ 
		//	printf("hola a todos:%s\n", argv[0]);
			status = built[j].type(argv);
			break; }
		j++;
	}
return (status);
}
