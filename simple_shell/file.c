#include "shell.h"

/**
 * file - executes shell commands by reading directly from file
 * @av: arguments vector
 */

void file(char **av)
{
	int i = 1, n = 0, fd, bytes_read, count = 0;
	char buff[1024], *delim = "\n", **lines, **cmd, *temp = NULL;

	while (av[i] != NULL)
	{
		fd = open(av[i], O_RDONLY);
		if (fd < 0)
		{
			fprintf(stderr, "%s: %u: Can't open %s\n", av[0], count, av[i]);
			exit(127);
		}

		bytes_read = read(fd, buff, sizeof(buff));
		if (bytes_read > 0)
		{
			buff[bytes_read - 1] = '\0';
			lines = _strarys(buff, delim);
			if (lines == NULL)
			{
				exit(EXIT_FAILURE);
			}

			for (n = 0; lines[n] != NULL; n++)
			{
				temp = lines[n];
				cmd = _strarys(temp, " ");
				cd_fnct(cmd, av[0], count);
				remove_dp(cmd);
				count++;
			}
			remove_dp(lines);

		}
		close(fd);
		i++;
	}
	exit(0);
}
