#include "shell.h"
/**
 * _strncpy - copies a string
 * @dest: destination string
 * @src: source string
 * @c:amount of characters
 * Return: concatenated sting
 */
char *_strncpy(char *dest, char *src, int c)
{
	int x, y;
	char *s = dest;

	x = 0;
	while (src[x] != '\0' && x < c - 1)
	{
		dest[x] = src[x];
		x++;
	}
	if (x < c)
	{
		y = 1;
		while (y < c)
		{
			dest[y] = '\0';
			y++;
		}
	}
	return (s);
}
/**
 *  _strncat - concatenates 2 strings
 *  @dest: destination string
 *  @src: source string
 *  @n: amount of bytes to use
 *  Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int k, l;
	char *s = dest;

	k = 0;
	l = 0;
	while (dest[k] != '\0')
		k++;
	while (src[l] != '\0' && l < n)
	{
		dest[k] = src[l];
		k++;
		l++;
	}
	if (l < n)
		dest[k] = '\0';
	return (s);
}
/**
 * _strchr - locates a char in a string
 * @str: string to parse
 * @c: char to look for
 * Return: a pointer to the  memory area
 */
char *_strchr(char *str, char c)
{
	do  {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');
	return (NULL);
}
