#include "shell.h"
/**
 * interactive - retuns true if shell is interactive mode
 * @info: struct address
 * Return: 1 if interactive mode ,0 if not
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd >= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @del: the delimeter stirng
 * @c: character
 * Return: 1 if tue ,0 if false
 */
int is_delim(char c, char *del)
{
	while (*del)
		if (*del++ == c)
			return (1);
	return (0);
}
/**
 * _isalpha - checks for alphabetic character
 * @h: character to input
 * Return: 1 if h is alphabetic,0 if not
 */
int _isalpha(int h)
{
	if ((h >= 'a' && h <= 'z') || (h >= 'A' && h <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _atoi - converts a string to an nteger
 * @s: string o be converted
 * Return: 0 if no numbers in string, converted numbers otherwise
 */
int _atoi(char *s)
{
	int n, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (n = 0; s[n] != '\0' && flag != 2; n++)
	{
		if (s[n] >= '0' && s[n] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[n] - '0');
		}
		else if
			(flag == 1)
				flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}
