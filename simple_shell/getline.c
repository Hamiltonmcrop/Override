#include "shell.h"

/**
 * pwd_show - function that reads from a stream using buffer
 * @lineptr: pointer to the line
 * @n: number of line
 * @stream: stream of characters
 *
 * Return: -1
 */

ssize_t pwd_show(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];

	static char *ptr = buffer;

	static int chars_left;

	int i, j, read_chars;

	if (chars_left <= 0)
	{
		read_chars = fread(buffer, 1, BUFFER_SIZE - 1, stream);
		if (read_chars <= 0)
			return (-1);

		buffer[read_chars] = '\0';
		ptr = buffer;
		chars_left = read_chars;
	}

	for (i = 0; i < chars_left; i++)
	{
		if (ptr[i] == '\n')
		{
			ptr[i] = '\0';

			*lineptr = malloc(i + 1);
			if (*lineptr == NULL)
				return (-1);

			for (j = 0; j <= i; j++)
				(*lineptr)[j] = ptr[j];

			ptr += i + 1;
			chars_left -= i + 1;
			*n = i + 1;
			return (i + 1);
		}
	}
	return (-1);
}
