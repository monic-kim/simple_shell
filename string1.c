#include "shell.h"
/**
 * _strcpy - copies a string
 * @dest: destination string
 * @src: source string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int n = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[n])
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = 0;
	return (dest);
}
/**
 * _strdup - duplicates a string
 * @str: string
 * Return: pointer to the string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}
/**
 * _puts - prints an input string
 * @str: string to print
 * Return: nothing
 */
void _puts(char *str)
{
	int n = 0;

	if (!str)
		return;
	while (str[n] != '\0')
	{
		_putchar(str[i]);
		n++;
	}
}
/**
 * _putchar - writes the char to stdout
 * @c: char to print
 * Return: 1 (success)
 * -1 (error
 */
int _putchar(char c)
{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(1, buf, m)
			m = 0;
	}
	if (c != BUF_FLUSH)
		buf[m++] = c;
}
