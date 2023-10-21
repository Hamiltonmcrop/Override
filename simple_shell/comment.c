#include "shell.h"

/**
 * blue_check - checks and filters out blue_checks from array
 * @arr: array of strings
 */

void blue_check(char *arr[])
{
	int i = 0, n;

	if (arr[0][0] == '#')
		exit(0);
	while (arr[i] != NULL)
	{
		if (_strcmp(arr[i], "#") == 0)
		{
			arr[i] = NULL;
			return;
		}
		for (n = 0; arr[i][n] != '\0'; n++)
		{
			if (arr[i][n] == '#')
			{
				if (arr[i][n - 1] != ' ')
					return;
				arr[i][n] = '\0';
				if (arr[i + 1] != NULL)
				{
					arr[i + 1] = NULL;
					return;
				}
				return;
			}
		}
		i++;
	}
}
