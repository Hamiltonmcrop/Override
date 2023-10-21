#include "shell.h"

/**
 * cd - changes the pwd
 * @av: argument vector
 *
 * Return: 0 on success and 1 on failure
 */

int cd(char **av)
{
	char newDir[1024];
	char *homeDir = getenv("HOME");
	char *prevDir = NULL;
	char *currentDir = getcwd(NULL, 0);
	unsigned int len = 0;

	while (av[len] != NULL)
		len++;
	if (len == 1)
		_strcpy(newDir, homeDir);
	else if (len == 2)
	{
		if (_strcmp(av[1], "-") == 0)
		{
			if (prevDir != NULL)
				_strcpy(newDir, prevDir);
			else
				fprintf(stderr, "cd: no previous directory\n");
			return (1);
		}
		else
			_strcpy(newDir, av[1]);
	}
	else
	{
		fprintf(stderr, "cd: too many arguments\n");
		return (1);
	}
	prevDir = currentDir;
	if (chdir(newDir) != 0)
	{
		perror("cd");
		return (1);
	}
	setenv("PWD", newDir, 1);
	free(currentDir);

	return (0);
}
