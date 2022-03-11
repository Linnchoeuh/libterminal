/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** env_free_var.c - 2022
**
** *****************************************************************************
*/

#include "terminal_env.h"

void env_free_var(char **env)
{
	size_t i;

	i = 0;
	while (env[i] != NULL)
	{
		free(env[i]);
		i++;
	}
}

