/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** term_split_dup - 2022
**
** *****************************************************************************
*/

#include "terminal_strsplit.h"

char **term_split_dup(char **split)
{
	size_t i;
	char **split_copy;

	i = 0;
	split_copy = malloc((term_split_len(split) + 1) * sizeof(char*));
	if (split_copy == NULL)
		return (NULL);
	while (split[i] != NULL)
	{
		if ((split_copy[i] = term_strdup(split[i])) == NULL)
		{
			term_split_free(split_copy);
			return (NULL);
		}
		i++;
	}
	split_copy[i] = NULL;
	return (split_copy);
}