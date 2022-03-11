/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** env_set_var.c - 2022
**
** *****************************************************************************
*/

#include "terminal_env.h"

static int env_update_var(char   **set,
						  char   **env,
						  size_t i)
{
	char **env_var;
	char *env_data;

	if ((env_var = term_split_str(env[i], '=')) == NULL)
		return (-1);
	if (term_strcasecmp(set[0], env_var[0]) == 0)
	{
		env_data = term_split_merge(set, "=", -1);
		term_split_free(set);
		if (env_data == NULL)
			return (-1);
		free(env[i]);
		env[i] = env_data;
		term_split_free(env_var);
		return (1);
	}
	term_split_free(env_var);
	return (0);
}

bool env_set_var(char *var_name,
				 char *content,
				 char **env)
{
	int    status;
	size_t i;
	char   **set;

	i = 0;
	if ((set = malloc(sizeof(char*) * 3)) == NULL ||
		(set[0] = term_strdup(var_name))  == NULL ||
		(set[1] = term_strdup(content))   == NULL)
	{
		term_split_free(set);
		return (false);
	}
	set[2] = NULL;
	while (env[i] != NULL)
	{
		status = env_update_var(set, env, i);
		if (status == 1)
			return (true);
		else if (status == -1)
			return (false);
		i++;
	}
	term_split_free(set);
	return (false);
}

