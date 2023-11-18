#iclude "shell.h"
/**
 * input_buf - buffers chained comments
 * @info: info struct
 * @buf: address of buffer
 * @len: address of len var
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t l = 0;
	ssize_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		l = getline(buf, &len_p, stdin);
#else
		l = _getline(info, buf, &len_p);
#endif

		if (l > 0)
		{
			if ((*buf)[l - 1] == '\n')
			{
				(*buf)[l - 1] = '\0' :
					l--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = l;
				info->cmd_buf = buf;
			}
		}
	}
	return (l);
}
/**
 * get_input - gets a line - a new line
 * @info: info struct
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t x, y, len;
	ssize_t l = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLASH);
	l = input_buf(info, &buf, &len);
	if (l == -1)
		return (-1);
	if (len)
	{
		y = 1;
		p = buf + x;

		check_chain(info, buf, &y, x, len);
		while (y < len)
		{
			if (is_chain(info, buf, &y))
				break;
			y++;
		}
		x = y + 1;
		if (x >= len)
		{
			x = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}
		*buf_p = p;
		return (_strlen(p));
	}
	*buf_p = buf;
	return (l);
	_getline();
}
