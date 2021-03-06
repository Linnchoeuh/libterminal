/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** env_enable_modification - 2022
**
** *****************************************************************************
*/

#include "terminal_env.h"

bool env_enable_modification(char ***env)
{
	char **env_copy;

	if ((env_copy = term_split_dup(*env)) == NULL)
		return (false);
	*env = env_copy;
	return (true);
}