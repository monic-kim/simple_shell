#include "shell.h"
/**
 * _memset - fills memory with a constant byte
 * @s: pointer to memory area
 * @b: byte to fil
 * @n: amount of bytes
 * Return: a pointer to an array of strings
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		s[x] = b;
	return (s);
}
/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **c = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(c);
}
/**
 * _realloc - reallocates
 * @p: pointer
 * @old_size: byte size of prev block
 * @new_size:byte size pf new nlock
 * Return: pointer to the old block nae
 */
void *_realloc(void *p, unsigned int old_size, unsigned int new_size)
{
	char *c;

	if (!p)
		return (malloc(new_size));
	if (!new_size)
		return (free(p), NULL);
	if (new_size == old_size)
		return (p);
	c = malloc(new_size);
	if (!c)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		c[old_size] = ((char *)p)[old_size];
	free(p);
	return (C);
}
