#include "shell.h"
/**
 * _realloc - reallocates a memory block
 * @ptr: initial pointer
 * @old_size: initial size
 * @new_size: new size
 * Return: pointer to array
 */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *clone, *relloc, *aux;
	unsigned int i;

	if (ptr != NULL)
		clone = ptr;
	else
	{
	aux = malloc(sizeof(char) * new_size);
	return (aux);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{ free(ptr);
		return (0); }
	relloc = malloc(sizeof(char) * new_size);
	if (relloc == NULL)
		return (0);
	for (i = 0; i < old_size || i < new_size; i++)
	{
		*(relloc + i) = clone[i];
	}
	free(ptr);
	return (relloc);
}
