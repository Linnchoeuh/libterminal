/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** env_enable_modification - 2022
**
** *****************************************************************************
*/

#include "terminal.h"

bool env_enable_modification(char **env)
{
	size_t i;

	i = 0;
	while (env[i] != NULL)
	{
		if ((env[i] = term_strdup(env[i])) == NULL)
		{
			env_free_var(env);
			return (false);
		}
		i++;
	}
	return (true);
}

