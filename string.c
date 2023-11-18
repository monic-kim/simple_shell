#include "shell.h"
/**
 * _strlen - returns length of string
 * @s: string
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int n = 0;

	if (!s)
		return (0);
	while (*s++)
		n++;
	return (n);
}
/**
 * _strcmp - comparison of two strings
 * @s1: forst string
 * @s2: second string
 * Return: negative if s1< s2
 * positive if s1 > s2, 0 if s1 = s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
/**
 * starts_with - if needle startts with haystack
 * @haystack: string to serch
 * @needle: substring to find
 * Return: addresss of next char or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
/**
 * _strcat - concatenates tw strigs
 * @dest: destination string
 * @src: source string
 * Return: pointer to dest buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}


