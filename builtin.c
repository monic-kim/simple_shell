#inllude "shell.h"
/**
 * _myhistory - shows history list
 * @info:info struct
 * Return: 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - sets alias to atring
 * @str: string
 * @info:info struct
 * Return: 0 (success), 1(error)
 */
int unset_alias(info_t *info, chr *str)
{
	char *s, c;
	int ret;

	s = _strchr(str, '=');
	if (!s)
		return (1);
	c = *s;
	*s = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias,
				node_starts_with(info->alias, str, -1)));
	*s = c;
	return (ret);
}
/**
 * set_alias - 0 (success) , 1(error)
 * @info: info struct
 * @str: string
 * Return: 0 (success) 1 (error)
 */
int set_alias(info_t *info, char *str)
{
	char *s;

	s = _strchr(str, '=');
	if (!s)
		return (1);
	if (!*++s)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - prints an alias string
 * @node: alias node
 * Return: 0 on sccess, 1 on error
 */
int print_alias(list_t *node)
{
	char *s = NULL, *a = NULL;

	if (node)
	{
		s = _strchr(node->str, '=');
		for (a = node->str; a <= s; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(s + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _myalias - mimics alias builtin
 * @info: info struct
 * Return: 0
 */
int _myalias(info_t *info)
{
	int x = 0;
	char *s = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		s = _strchr(info->argv[x], '=');
		if (s)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}
	return (0);
}
