#include "shell.h"

/**
 * _noinput - handles the non interactive aspect of the simple shell.
 * @env: environmental variables.
 * @fname:file name of program.
 * @c: command line count.
 */

void _noinput(__attribute__((unused)) char **env, char *fname, int c)
{
	char *buff = malloc(1024), *delim = "\n", **arr = NULL, **cmd = NULL;
	char *temp = NULL, *buff_h;
	ssize_t bytes_read;
	int i;

	if (buff == NULL)
		exit(0);

	buff_h = buff;
	while ((bytes_read = read(STDIN_FILENO, buff, 1024)) > 0)
	{

		buff[bytes_read - 1] = '\0';
		while (*buff == ' ' || *buff == '\n')
			buff++;
		if (*buff == '\0')
		{
			free(buff_h);
			exit(0);
		}
		arr = _strarys(buff, delim);
		if (arr[0] == NULL)
		{
			free(buff_h);
			exit(0);
		}
		for (i = 0; arr[i] != NULL; i++)
		{
			temp = arr[i];
			cmd = _strarys(temp, " ");
			cd_fnct(cmd, fname, c);
			remove_dp(cmd);
			c++;
		}
		remove_dp(arr);
	}

	free(buff_h);
	exit(0);
}
