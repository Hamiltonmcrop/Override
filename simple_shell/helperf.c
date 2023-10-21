#include "shell.h"

/**
 * _strcpy - copies the string from src, including the terminating
 * @dest: where string will be copied to
 * @src: where we are copying from
 *
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int i, n = 0;

	while (src[n] != '\0')
		n++;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: first string
 * @src: second string
 * Return: appended string
 */

char *_strcat(char *dest, char *src)
{
	int dc = 0, sc = 0;

	while (dest[dc] != '\0')
		dc++;

	for (sc = 0; src[sc] != '\0'; sc++)
	{
		dest[dc] = src[sc];
		dc++;
	}
	dest[dc] = '\0';
	return (dest);
}

/**
 * _strdup - makes a DMA copy of a string from an existing string
 * @str: string to be copied
 * Return: NULL is str is NULL or allocation fails, pointer to copy otherwise
 */

char *_strdup(char *str)
{
	char *copy;

	int i;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)

	copy = (char *) malloc((i + 1) * sizeof(char));

	if (copy == NULL)

		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		copy[i] = str[i];

	copy[i] = '\0';

	return (copy);
}

/**
 * _strlen - returns the length of a string
 * @s: string to be checked
 * Return: length of string
 */

int _strlen(char *s)
{
	int lent = 0;

	while (*s != '\0')
	{
		s++;
		lent++;
	}
	return (lent);
}

/**
 * _strncpy - copies a string from src to dest
 * @n: number of bytes to be copied
 * @dest: where string wiol be copied to
 * @src: source string
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int c = 0;

	while (c < n && src[c] != '\0')
	{
		dest[c] = src[c];
		c++;
	}
	while (c < n)
	{
		dest[c] = '\0';
		c++;
	}

	return (dest);
}
