/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** - env_get_var_pos.c -
**
** *****************************************************************************
*/

#include "terminal_env.h"

ssize_t env_get_var_pos(char **env,
					   char *var_name)
{
	size_t i;
	char   **get;

	i = 0;
	while (env[i] != NULL)
	{
		if ((get = term_split_str(env[i], '=')) == NULL)
			return (-2);
		if (term_strcasecmp(var_name, get[0]) == 0)
		{
			term_split_free(get);
			return (i);
		}
		term_split_free(get);
		i++;
	}
	return (-1);
}