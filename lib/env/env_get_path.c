/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** env_get_path.c - 2022
**
** *****************************************************************************
*/

#include "terminal_env.h"

char **env_get_path(char **env)
{
	char *path_var;
	char **path;


	if ((path_var = env_get_var("PATH", env)) == NULL)
		return (NULL);
	path = term_split_str(path_var, ':');
	free(path_var);
	return (path);
}

