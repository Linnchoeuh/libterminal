/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** - term_split_remove.c - 2022
**
** *****************************************************************************
*/

#include "terminal_strsplit.h"

bool term_split_remove(char    ***split,
					   ssize_t pos)
{
	char	**new_split;
	ssize_t i;
	ssize_t k;
	ssize_t len;

	len = term_split_len(*split);
	if ((new_split = malloc((len + 1) * sizeof(char*))) == NULL)
		return (false);
	new_split[len] = NULL;
	i = 0;
	k = 0;
	pos = (pos == -1) ? (len - 1) : (pos);
	while (i < len)
	{
		(k == pos) ? free((*split)[k]) : 0;
		k += (k == pos) ? 1 : 0;
		new_split[i] = (*split)[k];
		i++;
		k++;
	}
	free(*split);
	(*split) = new_split;
	return (true);
}

