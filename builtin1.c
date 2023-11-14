#include "shell.h"
/**
 * _myhistory - displays history list
 * @info: struct address
 * Return: always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - sets alias to stirng
 * @info:parameter struct
 * @str: string alias
 * Return: always 0 (success) ,1 if not
 */
int unset_alias(info_t *info, char *str)
{
	char *n, s;
	int ret;

	n = _strchr(str, '=');
	if (!n)
		return (1);
	s = *n;
	*n = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias,
				node_starts_with(info->alias, str, -1)));
	*n = s;
	return (ret);
}
/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: string alias
 * Return:0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *n;

	n = _strchr(str, ' = ');
	if (!n)
		return (1);
	if (!*++n)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - prints an alias string
 * @node: alias node
 * Return: 0 on success , 1 on error
 */
int print_alias(list_t *node)
{
	char *n = NULL, *x = NULL;

	if (node)
	{
		n = _strchr(node->str, ' = ');
		for (x = node->str; x <= n; x++)
			_putchar(*x);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n ");
		return (0);
	}
	return (1);
}
/**
 * _myalias - mimics alias builtin
 * @info: structure with potential args
 * Return: 0
 */
int _myalias(info_t *info)
{
	int x = 0;
	char *n = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		n = _strchr(info->argv[x], '=');
		else
			print_alias(node_starts_with(info->alias,
						info->argv[x], '='));
	}
	return (0);
}
