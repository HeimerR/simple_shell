#include "shell.h"
/**
 * add_node_end - adds new nodes to the end of the list
 * @head: address new head
 * @str: string to add
 * Return: head
 */
int add_node_end(path_t **head, char *str)
{
	path_t *new_node;
	path_t *aux;

	aux = *head;
	if (*head)
	{
		while (aux->next)
		{
		aux = aux->next;
		}
	}
	new_node = malloc(sizeof(path_t));
	if (new_node == NULL)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (0);
	}
	new_node->path = _strdup(str);
	if (new_node->path == NULL)
	{
		write(STDERR_FILENO, "Error\n", 6);
		free(new_node);
		return (0);
	}
	new_node->len = _strlen(str);
	new_node->next = NULL;
	if (aux)
	aux->next = new_node;
	else
	*head = new_node;
	return (new_node->len);
}
