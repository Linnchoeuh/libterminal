/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** - env_get_var.c -
**
** Takes a (char **) and merge it into a single (char *)
** *****************************************************************************
*/

#include "terminal.h"

char *env_get_var(char *var_name,
				  char **env)
{
	size_t i;
	char   **get;
	char   *env_data;

	i = 0;
	while (env[i] != NULL)
	{
		if ((get = term_split_char(env[i], '=')) == NULL)
			return (NULL);
		if (term_strcasecmp(var_name, get[0]) == 0)
		{
			env_data = (get[1] != NULL) ? term_strdup(get[1]) :
										  term_strdup("");
			term_free_split(get);
			if (env_data == NULL)
				return (NULL);
			return (env_data);
		}
		term_free_split(get);
		i++;
	}
	return (NULL);
}