#include "shell.h"
/**
 * hsh - main shell loop
 * @info: info struct
 * @av: the arg vector
 * Return: 0 (success) 1 (error)
 */
int hsh(info_t *info, char **av)
{
	ssize_t l = 0;
	int builtin_ret = 0;

	while (l != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$");
		_eputchar(BUF_FLUSH);
		l = get_input(info);
		if (l != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) $$ info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->err_num);
	}
	return (builtin_ret);
}
/**
 * find_builtin - finds a builitin command
 * @info: info struct
 * Return: -1 if builtin and successful
 * 1 if builtin found but no successful
 * -2 if builin signals ext()
 */
int find_builtin(info_t *info)
{
	int  x, built_in_ret = -1;
	built_in_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};
	for (x = 0; builtinbl[x]. type; x++)
		if (_strcmp(info->argv[0], builtintbl[a]. type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[x] . func(info);
			break;
		}
	return (built_in_ret);
}
/**
 * find_cmg - finds a command in path
 * @info: info struct
 * Return: void
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int x, y;

	info->path = info->argv[0];
	if (info->linecount_flag == -1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (x = 0, y = 0; info->arg[x]; a++)
		if (!is_delim(info->arg[x], "\t\n"))
			b++;
	if (!k)
		return;
	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->arg[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			nfo->atatus = 127;
			print_error(info, "not found\n");
		}
	}
}
/**
 * fork_cmd - forks an exc thread to run cmd
 * @info: info struct
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork;
	if (chld_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTTUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}



