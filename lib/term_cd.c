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

	old_pwd = env_get_var("PWD", env);
	env_set_var("PWD", path, env);
	if (old_pwd != NULL)
	{
		env_set_var("OLDPWD", old_pwd, env);
		free(old_pwd);
	}
}

static bool term_cd_home(char **env)
{
	char *path_home;

	if ((path_home = env_get_var("HOME", env)) == NULL)
		return (false);
	chdir(path_home);
	term_update_pwd(path_home, env);
	free(path_home);
	return (true);
}

static void path_generator(char ***split_pwd,
						   char **relative_path)
{
	size_t i;

	i = 0;
	while (relative_path[i] != NULL)
	{
		if (term_strcmp(relative_path[i], "..") == 0 ||
			term_strcmp(relative_path[i], "../") == 0)
			term_split_remove(split_pwd, -1);
		else
			term_split_insert(split_pwd, relative_path[i], -1);
		i++;
	}
}

static char *term_absolute_path(char *path,
			 				 	char **env)
{
	char *pwd;
	char *tmp;
	char *absolute_path;
	char **split_pwd;
	char **relative_path;

	pwd = env_get_var("PWD", env);
	split_pwd = term_split_char(pwd, '/');
	free(pwd);
	relative_path = term_split_char(path, '/');
	path_generator(&split_pwd, relative_path);
	absolute_path = term_merge_char(split_pwd, "/", -1);
	term_free_split(split_pwd);
	term_free_split(relative_path);
	tmp = absolute_path;
	absolute_path = term_str_append(absolute_path, "/");
	free(tmp);
	return (absolute_path);
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
	   (absolute_path = term_absolute_path(path, env)) != NULL)
	{
		term_update_pwd(absolute_path, env);
		free(absolute_path);
	}
	return (true);
}

