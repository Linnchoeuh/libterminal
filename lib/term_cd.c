/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** term_cd.c - 2022
**
** *****************************************************************************
*/

#include "terminal.h"

#define NO_PATH "Unable to go to the given path.\n"

static void term_update_pwd(char *path,
							char **env)
{
	char *old_pwd;

	old_pwd = env_get_var(env, "PWD");
	env_set_var(env, "PWD", path);
	if (old_pwd != NULL)
	{
		env_set_var(env, "OLDPWD", old_pwd);
		free(old_pwd);
	}
}

static bool term_cd_home(char **env)
{
	char *path_home;

	if ((path_home = env_get_var(env, "HOME")) == NULL)
		return (false);
	chdir(path_home);
	term_update_pwd(path_home, env);
	free(path_home);
	return (true);
}

bool term_cd(char *path,
			 char **env)
{
	char *absolute_path;

	if ((path == NULL || path[0] == '\0') && env != NULL)
		return(term_cd_home(env));
	if (chdir(path) == -1)
	{
		write(STDERR_FILENO, NO_PATH, 32);
		return (false);
	}
	if (env != NULL &&
	   (absolute_path = term_get_absolute_path(path, env)) != NULL)
	{
		term_update_pwd(absolute_path, env);
		free(absolute_path);
	}
	return (true);
}

