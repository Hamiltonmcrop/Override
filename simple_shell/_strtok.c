#include "shell.h"

/**
 * _strtok - custom function
 * @str: string to be tokenized
 * @delim: delimeter that separates
 *
 * Return: 0
 */

char *_strtok(char *str, const char *delim)
{
	static char *last;

	char *start, *end, *copy;

	if (str != NULL)
		last = str;

	if (last == NULL || *last == '\0')
		return (NULL);

	start = last;
	while (*start != '\0' && _strchr(delim, *start))
		start++;

	if (*start == '\0')
		return (NULL);

	end = start;
	while (*end != '\0' && !(_strchr(delim, *end)))
		end++;

	copy = malloc((end - start) + 1);
	if (copy == NULL)
		exit(EXIT_FAILURE);

	_strncpy(copy, start, end - start);
	copy[end - start] = '\0';

	last = (*end == '\0') ? NULL : end + 1;

	return (copy);
}
