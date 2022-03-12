/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** env_replace_var_alias.c - 2022
**
** *****************************************************************************
*/

#include "terminal_env.h"

bool env_replace_var_alias(char	**env,
						   char	**split_arg)
{
	size_t i;
	char   *env_content;

	i = 0;
	while (split_arg != NULL && split_arg[i] != NULL)
	{
		if (split_arg[i][0] == '$')
		{
			if ((env_content =
				env_get_var(&split_arg[i][1], env)) == NULL)
				return (false);
			free(split_arg[i]);
			split_arg[i] = env_content;
		}
		i++;
	}
	return (true);
}

