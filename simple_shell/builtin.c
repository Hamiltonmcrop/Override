#include "shell.h"

/**
 * ext_built - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int ext_built(info_t *info)
{
	int exitcheck;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = err_tot(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			err_print(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = err_tot(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * ent_cdd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int ent_cdd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		char_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = info_env(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = info_env(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (cmp_string(info->argv[1], "-") == 0)
	{
		if (!info_env(info, "OLDPWD="))
		{
			char_puts(s);
			_putchar('\n');
			return (1);
		}
		char_puts(info_env(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = info_env(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		err_print(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		eenv_set_env(info, "OLDPWD", info_env(info, "PWD="));
		eenv_set_env(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * srch_hlp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int srch_hlp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	char_puts("help call works. Function not yet implemented \n");
	if (0)
		char_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
