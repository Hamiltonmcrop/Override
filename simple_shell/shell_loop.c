#include "shell.h"

/**
 * hsh - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(info_t *info, char **av)
{
	ssize_t r = 0;
	int int_built_ret = 0;

	while (r != -1 && int_built_ret != -2)
	{
		delete_dat(info);
		if (int_shell(info))
			char_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = int_inpt(info);
		if (r != -1)
		{
			puts_data(info, av);
			int_built_ret = get_in(info);
			if (int_built_ret == -1)
				get_command(info);
		}
		else if (int_shell(info))
			_putchar('\n');
		free_info(info, 0);
	}
	wrt_only(info);
	free_info(info, 1);
	if (!int_shell(info) && info->status)
		exit(info->status);
	if (int_built_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (int_built_ret);
}

/**
 * get_in - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int get_in(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", ext_built},
		{"env", my_info_env},
		{"help", srch_hlp},
		{"history", hist_cd},
		{"setenv", set_my_info},
		{"unsetenv", myunset_my_info},
		{"cd", ent_cdd},
		{"alias", al_my},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (cmp_string(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * get_command - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void get_command(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!int_she_del(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = get_dir(info, info_env(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		remove_command(info);
	}
	else
	{
		if ((int_shell(info) || info_env(info, "PATH=")
			|| info->argv[0][0] == '/') && on_command(info, info->argv[0]))
			remove_command(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			err_print(info, "not found\n");
		}
	}
}

/**
 * remove_command - forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void remove_command(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				err_print(info, "Permission denied\n");
		}
	}
}
