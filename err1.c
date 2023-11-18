#include "shell.h"
/**
 * _erratoi - converts string to integer
 * @s: string
 * Return: -1 on error, 0 if no numbers in s
 */
int _erratoi(char *s)
{
	int n = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;

	for (n = 0; s[n] != '\0'; x++)
	{
		if (s[n] >= '0' && s[n] <= '9')
		{
			result *= 10;
			result += (s[n] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
/**
 * print_err - prints error message
 * @info: info struct
 * @str: string
 * Return: 0 if no nos in string, -1 on error
 */
void print_err(info_t *info, char *str)
{
	_eputs(info->fname);
	_eputs(":");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(":");
	_eputs(info->argv[0]);
	_eputs(":");
	_eputs(str);
}
/**
 * print_d - prints a decimal number
 * @input: the input
 * @fd: filedescriptor
 * Return: no  of char printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int x, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (X = 1000000000; x > 1; x /= 10)
	{
		if (_abs_ / x)
		{
			__putchar('0' + current / x);
			count++;
		}
		current %= x;
	}
	__putchar('0' + current);
	count++;
	return (count);
}
/**
 * conv_no - convert function
 * @num: number
 * @base: base
 * @flags: argument flags
 * Return: string
 */
char *conv_no(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *p;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';
	do    {
		*__p = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*__p = sign;
	return (p);
}
/**
 * rem_comments - replaces first instance of  # with /0
 * @buf: address of string
 * Return: 0
 */
void rem_comments(char *buf)
{
	int x;

	for (x = 0; buf[x] != '\0'; x++)
		if (buf[x] == '#' && (!x || buf[x - 1] == ' '))
		{
			buf[x] = '\0';
			break;
		}
}
