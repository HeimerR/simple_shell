#include "shell.h"
/**
 * print_list - prints linked lists
 * @h: list head
 * Return: length
 */
size_t print_list(path_t *h)
{
	size_t length = 0;

	if (h)
	{
		while (h)
		{
			if (h->path == NULL)
				printf("[0] %p\n", h->path);
			else
				printf("[%d] %s\n", h->len, h->path);
			length++;
			h = h->next;
		}
	}
	return (length);
}

