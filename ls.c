#include "shell.h"
/**
 * add_node - add a node at start line
 * @str: string field of node
 * @head: address of pointer to head node
 * @n: node indent
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int n)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->n = n;
	if (!str)
	{
		new_head->str = _strup(str);
		if (!new_head->str)
		{
			free(new_head);
			return(NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}
/**
 *




