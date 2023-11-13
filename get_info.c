"include "shell.h"
/**
* clear_info - initializes info_t struct
* @info: struct address
*/
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->argc = 0;
	info->path = NULL;
}
/**
* set_info - initializes info_t struct
* @av: argument v
* @info: struct address
*/
void set_info(info_t *info, char *av[])
{
	int n = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strow(info->arg, "\t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) *2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info ->arg);
				info->argv[n] = NULL;
			}
		}
		for (n = 0; info->argv && info->argv[n]; n++)
			;
		info->argc = n;
		replace _alias(info);
	}
}
/**
* free_info - free info_t struct
* @info: struct address
* @ALL: true if freimg all fields
*/
void free_info(info_t *info, int ALL)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path =NULL;
	if (ALL)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
		info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
