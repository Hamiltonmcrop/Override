#include "shell.h"

/**
 * show_dir - prints the environmental variable
 */

void show_dir(void)
{
	char **env = environ;
	int i;

	for (i = 0; env[i] != NULL; i++)
		printf("%s\n", env[i]);
}
