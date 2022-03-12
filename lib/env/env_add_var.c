/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** env_add_var - 2022
**
** *****************************************************************************
*/

#include "terminal_env.h"

bool env_add_var(char ***env,
				 char *name,
				 char *content)
{
	char *var_str;
	bool success;

	var_str = term_str_chain_fuse(-1, name, "=", content, NULL);
	if (var_str == NULL)
		return (false);
	success = term_split_insert(env, var_str, -1);
	free(var_str);
	return (success);
}

