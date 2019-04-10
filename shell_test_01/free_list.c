#include "shell.h"
/**
 * free_list - fress linked lists
 * @head: head of the list
 * Return: no return
 */
void free_list(path_t *head)
{
	path_t *aux;
	path_t *aux2;

	aux = head;
	while (aux)
	{
	aux2 = aux;
	free(aux->path);
	free(aux);
	aux = aux2->next;
	}
}

