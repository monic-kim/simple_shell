#include " shell.h"
/**
 * bfree - frees and NULLs address
 * @p: pointer to free
 * Return: 1 if free, 0 if not
 */
int bfree(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
