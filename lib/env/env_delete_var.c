/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** env_delete_var - 2022
**
** *****************************************************************************
*/

#include "terminal_env.h"

bool env_delete_var(char ***env,
					char *name)
{
	return (term_split_remove(env, env_get_var_pos(*env, name)));
}

