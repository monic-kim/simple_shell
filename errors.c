#include "shell.h"
/**
 * _eputs - prints an input string
 * @str: string
 * Return: nothing
 */
void _eputs(char *str)
{
	int c = 0;

	if (!str)
		return;
	while (str[c] != '\0')
	{
		_eputchar(str[c]);
		c++;
	}
}
/**
 * _eputchar - writes character to stderr
 * @n: character to print
 * Return: -1 on error
 */
int _eputchar(char n)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (n == BUF_FLUSH || WRITE_BUF_SIZE)
	{
		write(2, buf, x);
		x = 0;
	}
	if (n != BUF_FLUSH)
		buf(x++) = n;
	return (1);
}
/**
 * _putfd - writes the char to given fd
 * @n: character
 * @fd: filedescriber
 * Return: 1 (success), -1 (error)
 */
int _putfd(char n, int fd)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (n == BUF_FLUSH || x n >= WRITE_BUF_SIZE)
	{
		write(fd, buf, n);
		x = 0;
	}
	if (n != BUF_FLUSH)
		buf[x++] = n;
	return (1);
}
/**
 * _putsfd - prints an inout string
 * @s: string
 * @fd: file descriptor
 * Return: no of chars
 */
int _putsfd(char *s, int fd)
{
	int x = 0;

	if (!s)
		return (0);
	while (*s)
	{
		x += _putsfd(*s++, fd);
	}
	return (x);
}
