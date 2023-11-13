#include "shell.h"
/**
 * _myenv - prints current environment
 * @info: structure with potential args
 * Return: 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 * _getenv - gets value of environ variable
 * @info:structur ewith potential args
 * @name: var name
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *n;

	while (node)
	{
		n = starts_with(node->str, name);
		if (n && *n)
			return (n);
		node = node->next;
	}
	return (NULL);
}
/**
 * _mysetenv - initiates new envirinment
 * @info: structure with potential args
 * Return: 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Wrong number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (1);
}
/**
 * _myunsetenv - removes an environment variable
 * @info: structure with potential args
 * Return: 0
 */
int _myunsetenv(info_t *info)
{
	int x;

	if (info->argc == 1)
	{
		_eputs("too few arguments.\n");
		return (1);
	}
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);
	return (0);
}
/**
 * populate_env_list - populates env linked list
 * @info: structure with potential args
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t n;

	for (n = 0; environ[n]; n++)
		add_node_end(&node, environ[n], 0)
			info->env = node;
	return (0);
}
