#include "shell.h"
/**
 * is_chain - test if current char is a chain delimeter
 * @info: info struct
 * @buf: the char buffer
 * @p: address of current position
 * Return: 1 if delimeter, 0 if not
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t n = *p;
	
	if (buf[n] == '|' && buf[n + 1] == '|')
	{
		buf[n] = 0;
		n++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[n] == '&' && buf[n + 1] == '&')
	{
		buf[n] = 0;
		n++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[n] == ';')
	{
		buf[n] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = n;
	return (1);
}
/**
 * check_chain - checks chaining based on list status
 * @info: info struct
 * @p:position in buf
 * @i: starting position in buf
 * @buf: buffer
 * @len: length of buf
 * Return:void/
 */
void check_chain(info_t *info, char *buf, size_t *p, size_ i, size_t len)
{
	size_t n = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			n = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			n = len;\}
		}
	}
	*p = n;
}
/**
 * replace_alias - replaces an alises
 * @info: info struct
 * Return: 1 if replaced, 0 if not
 */
int replace_alias(info_t *info)
{
	int j;
	list_t *node;
	char *p;

	for (j = 0; j < 10; j++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}
/**
 * replace_vars - replaces vars int the string
 * @info:info struct
 * Return: 1 if replaced. 0 if not
 */
int replace_vars(info_t *info)
{
	int x = 0;
	list_t *node;

	for (x = 0; info->argv[x]; x++)
	{
		if (info->argv[x][0] != '$' || !info->argv[x][1])
			continue;
		if(!_strcmp(info->argv[x], "$?"))
		{
			replace_string(&(info->argv[x]),
					_strdup(convert_number(getid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[x][1], '=');
		if (node)
		{
			replace_string(&(info->argv[x]), _strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[x], _strdup(""));
	}
	return (0);
}
/**
 * replace_string - replaces string
 * @old: addresses of old string
 * @new: new string
 * Return: 1 if replaced 0 if not
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
			
