#include "shell.h"

/**
 * handle_input - function that handles the input in shell
 * @av: argument count
 * @f_name: name of file
 * @count: prompt display tracker
 *
 * Return: 0
 */

void handle_input(char **av, char *f_name, size_t count)
{
	if (av == NULL)
		return;

	cd_fnct(av, f_name, count);
		remove_dp(av);
}
/**
 * with_input - function that display the interactive mode
 * @env: environment vector
 * @f_name: name of the file
 * Return: 0
 */

void with_input(char **env, char *f_name)
{
	char *buff = NULL, **av = NULL, *delim = "\n";

	size_t len = 0, count = 0;
	ssize_t read;

	(void)env;

	while (1)
	{
		printf("$ ");
		read = getline(&buff, &len, stdin);
		if (read == -1)
		{
			perror("getline failed");
			free(buff);
			printf("\n");
			exit(EXIT_FAILURE);
		}
		signal(SIGINT, SIG_IGN);
		av = _strarys(buff, delim);
		free(buff);
		buff = NULL;
		handle_input(av, f_name, ++count);
	}
}

/**
 * main - simple shell core. this is where the primary engine lives
 * @ac: argument count
 * @av: argument vector
 * @env: environment vector
 *
 * Return: 0 success
 */
int main(int ac, char **av, char **env)
{
	char *f_name = av[0];

	int count = 0;

	signal(SIGINT, SIG_IGN);
	if (ac > 1)
		file(av);
	else if (!isatty(STDIN_FILENO))
	{
		_noinput(env, f_name, count);
	}
	else
		with_input(env, f_name);
	return (0);
}
