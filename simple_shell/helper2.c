#include "shell.h"

/**
 * _strchr - searches for a character in a string and returns a pointer
 * to that character
 * @s: string to be searched
 * @c: character to be searched for
 * Return: pointer or NULL
 */

char *_strchr(const char *s, char c)
{
	int i = 0;

	while (s[i] != '\0' && s[i] != c)
		i++;

	if (s[i] == c)
		return ((char *)&s[i]);

	return (NULL);
}

/**
 * _strcmp - compares 2 strimgs and return an int
 * depending on whish is greater
 * @s1: first string to compare
 * @s2: second string
 * Return: int
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}

	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else
		return (s1[i] - s2[i]);
}
