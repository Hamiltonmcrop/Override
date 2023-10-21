#include "shell.h"

/**
 * d2s - converts a dynamic string to static memory
 * @dynamic_str: dynamic string to be copied
 * Return: pointer to copied string
 */

char *d2s(char *dynamic_str)
{
	static char stat_buff[STAT_BUFF_SIZE];

	if (dynamic_str == NULL)
	{
		stat_buff[0] = '\0';
	}

	else
	{
		_strncpy(stat_buff, dynamic_str, STAT_BUFF_SIZE - 1);
		stat_buff[STAT_BUFF_SIZE - 1] = '\0';
	}
	return (stat_buff);
}
