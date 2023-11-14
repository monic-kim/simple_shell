#include "shell.h"
/**
 * is_cmd - checks if a file is an
 * executable file
 * @info: structure with potential args
 * @path: path to the file
 * Return: 1 if true, 0 if false
 */
int_is_cmd(info_t *info, char *path)
{
	struct stat st;
	(void)info;

	if (!path || stat(path, &st))
		return (0);
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * dup_chars - duplicates chars
 * @pstr: path string
 * @start:starting index
 * @stop: stopping index
 * Return: pointer to new buffer
 */
char *dup_chars(char *pstr, int start, int stop)
{
	static char buf[1024];
	int x = 0, k = 0;

	for (k = 0, x = start; x < stop; x++)
		if (pstr[x] != ':')
			buf[k++] = pstr[x];
	buf[k] = 0;
	return (buf);
}
/**
 * find_path - finds cmd in path string
 * @info: info struct
 * @pstr:path string
 * @cmd: the cmd to find
 * Return: path of cmd if found, NULL if not
 */
char *find_path(info_t *info, char *pstr, char *cmd)
{
	int n = 0, curr_pos = 0;
	char *path;

	if (!pstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pstr[n] || pstr[n] == ':')
		{
			path = dup_chars(pstr, curr_pos, x);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pstr[n])
				break;
			curr_pos = n;
		}
		n++;
	}
	return (NULL);
}
