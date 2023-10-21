#include "shell.h"

/**
 * command_chunk - checks validity of command
 * @cmd: command string
 *
 * Return: 0 if path is found but 1 otherwise
 */

int command_chunk(char *cmd)
{
	char *path = _findpath(cmd);

	if (path == NULL)
	{
		return (1);
	}

	return (0);
}
