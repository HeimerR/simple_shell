#include "shell.h"
/**
* cmpstr - locates a substring
* @haystack: input array
* @needle: bytes to accept
* Return: 1 found, 0 no found
*/
int cmpstr(char *haystack, char *needle)
{
	int i = 0;

	while (haystack[i])
	{
		if (needle[i] == '\0')
			return (1);
		if (needle[i] == haystack[i])
			i++;
		else
			return (0);		
	}
return (0);
}
