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
				node_starts_with((info->alias, str, -1)));
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

