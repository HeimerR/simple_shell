#include "shell.h"

int cp_env(void)
{
	int status, i = 0;

	status = create_file("env_file", NULL);
	if (status == -1)
		return (status);
	while(environ[i])
	{
		status = append_text_to_file("env_file", environ[i]);
		if (status == -1)
			return (status);
		status = append_text_to_file("env_file", "\n");
		if (status == -1)
			return (status);
		i++;
	}
return (status);
}
