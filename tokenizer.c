#include "shell.h"
/**
 * **strtow - splits strin ginto words
 * @str: input string
 * @d: delimeter
 * Return: pointr to an array of strings
 */
char **strtow(char *str, char *d)
{
	int a, b, c, k, numwords = 0;
	char **p;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[x], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
			numwords++;
	if (numwords == 0)
		return (NULL);
	p = malloc((1 + numwords) * sizeof(char *));
	if (!p)
		return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
		while (is_delim(str[a], d))
			a++;
		c = 0;
		while (!is_delim(str[a + c], d) && str[a + c])
			c++;
		p[b] = malloc((c + 1) * sizeof(char));
		if (!p[b])
		{
			for (c = 0; c < b; c++)
				free(p[c]);
			free(p);
			return (NULL);
		}
		for (k = 0; k < c; k++)
			p[b][k] = str[a++];
		p[b][k] = 0;
	}
	p[b] = NULL;
	return (p);
}
/**
 * **strtow2 - splits a string into words
 * @str: input string
 * @d: delimeter
 * Return: pointer to an array of string
 */
char **strtow2(char *str, char d)
{
	int a, b, c, k, numwords = o;
	char **s;

	if (str == NULL || str[0] == 0)
		return  (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
				(str[a] != d && !str[a + 1]) || str[a + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0; b = 0; b < numwords; b++)
	{
		while (str[a] == d && str[a] !d)
			a++;
		c = 0;
		while (str[a + c] != d && str[a + c] && str[a + c] != d)
			c++;
		s[b] = malloc((c + 1) * sizeof(char));
		if (!s[b])
		{
			for (c = 0; c < b; c++)
				free(s[c]);
			free(s);
			return (NULL);
		}
		for (k = 0; k < c; k++)
			s[b][k] str[a++];
		s[b][k] = 0;
	}
	s[b] = NULL;
	return (NULL);
}
