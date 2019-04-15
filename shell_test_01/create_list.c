#include "shell.h"
/**
* create_list - creates a linked list based on PATH
* @strpath: content of PATH
*
* Return: list head
*/
path_t *create_list(char *strpath)
{
	path_t *head;
	int i = 0, n = 0, len;
	char *tmp;
	char buf[4096]; /*PATH_MAX*/

	tmp = strpath;
	head = NULL;
	while(*tmp != '=')
	{
	tmp++;
	}
	tmp++;
	while (strpath[i])
	{
		if (strpath[i] == ':')
		{
			strpath[i] = '\0';
			n++;
		}
		i++;
	}
	i = 0;
	while (i <= n)
	{
		if (*tmp)
		{
			len = add_node_end(&head, tmp);
			tmp += len + 1;
		}
		else
		{
			if (getcwd(buf, sizeof(buf)) != NULL)
			{
				len = add_node_end(&head, buf);
				tmp += 2;
			}
			else
			{
				perror("getcwd() error");
			}
		}
		i++;
	}
	return (head);
}
