#include "shell.h"

/**
 * cd_fnct - handles all functions from main
 * @av: array of arguments feom mamin
 * @f_name: name of shell executable
 * @count: line count
 * Return: 0 or -1
 */

void cd_fnct(char **av, char *f_name, size_t count)
{
	int exit_stat = 0;

	if (_strcmp(av[0], "exit") == 0)
	{
		if (av[1] != NULL)
			exit_stat = atoi(av[1]);

		remove_dp(av);
		move_out(exit_stat);
	}
	else if (_strcmp(av[0], "env") == 0)
	{
		show_dir();
		return;
	}
	else if (_strcmp(av[0], "cd") == 0)
	{
		cd(av);
		return;
	}

	run_prgm(av, f_name, count);
}
