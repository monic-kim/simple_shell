#include "shell.h"
/**
 * list_len - determine length of linked list
 * @p: pointer to first node
 * Return: size of list
 */
ssize_t list_len(const list_t *p)
{
	size_t x = 0;

	while (p)
	{
		p = p->next;
		x++;
	}
	return (x);
}
/**
 * list_to_strings - returns an array of strings
 * @h: pointer to first node
 * Return: array of strings
 */
char **list_to_strings(list_t *h)
{
	list_t *node = h;
	size_t x = list_len(h), y;
	char **strs;
	char *str;

	if (!head || !x)
		return (NULL);
	strs = malloc(sizeof(char *) * (x + 1));
	if (!strs)
		return (NULL);
	for (x = 0; node; node = node->next, x++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (y = 0; y < x; y++)
				free(strs[j]);
			freee(strs);
			return (NULL);
		}
		sr = _strcpy(str, node->str);
		strs[x] = str;
	}
	strs[x] = NULL;
	return (strs);
}
/**
 * print_list - prints all the elements of a linked list
 * @head: pointe to first node
 * Return: size of list
 */
size_t print_list(const list_t *head)
{
	size_t x = 0;

	while (head)
	{
		_puts(convert_number(head->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		x++;
	}
	return (x);
}
/**
 * node_starts_with - returns node whose starts with
 * prefix
 * @node: pointer t list
 * @prefix: string to match
 * @n: next char after prefix
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char n)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == n)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t x = 0;

	while (head)
	{
		if (head == node)
			return (x);
		head = head->next;
		x++;
	}
	return (-1);
}
