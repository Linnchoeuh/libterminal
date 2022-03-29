/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** term_get_absolute_path.c - 2022
**
** *****************************************************************************
*/

#include "terminal.h"

static bool path_generator(char ***split_pwd,
						   char **relative_path)
{
	size_t i;

	i = 0;
	while (relative_path[i] != NULL)
	{
		if (term_strcmp(relative_path[i], "..") == 0 ||
			term_strcmp(relative_path[i], "../") == 0)
		{
			if (!term_split_remove(split_pwd, -1))
				return (false);
		}
		else
		{
			if (!term_split_insert(split_pwd, relative_path[i], -1))
				return(false);
		}
		i++;
	}
	return (true);
}

static char **get_split_pwd(char **env)
{
	char *pwd_path;
	char **split_pwd;

	pwd_path = env_get_var(env, "PWD");
	if (pwd_path == NULL)
		return(NULL);
	split_pwd = term_split_str(pwd_path, '/');
	free(pwd_path);
	return (split_pwd);
}

static char **splitted_absolute(char *relative_path,
			 					char **env)
{
	char **split_pwd;
	char **split_relative_path;
	bool pass;

	split_pwd = get_split_pwd(env);
	split_relative_path = term_split_str(relative_path, '/');
	if (split_relative_path == NULL)
	{
		term_split_free(split_pwd);
		return (NULL);
	}
	pass = path_generator(&split_pwd, split_relative_path);
	term_split_free(split_relative_path);
	if (!pass)
	{
		term_split_free(split_pwd);
		return (NULL);
	}
	return(split_pwd);
}

char *term_get_absolute_path(char *relative_path,
			 				 char **env)
{
	char *tmp;
	char *absolute_path;
	char **split_absolute_path;

	split_absolute_path = splitted_absolute(relative_path, env);
	if (split_absolute_path == NULL)
		return (NULL);
	absolute_path = term_split_merge(split_absolute_path, "/", -1);
	term_split_free(split_absolute_path);
	tmp = absolute_path;
	absolute_path = term_str_fuse("/", absolute_path);
	free(tmp);
	return (absolute_path);
}