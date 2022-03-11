/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** term_split_insert.c - 2022
**
** *****************************************************************************
*/

#include "terminal_strsplit.h"

void term_apply_insert(char    **split,
					   char    ***new_split,
					   char    *new_char_copy,
					   ssize_t pos)
{
	size_t	k;
	ssize_t i;
	ssize_t len;

	i = 0;
	k = 0;
	len = term_split_len(split) + 1;
	pos = (pos == -1) ? (len - 1) : (pos);
	while (i < len)
	{
		if (i == pos)
		{
			(*new_split)[i] = new_char_copy;
			i++;
		}
		(*new_split)[i] = split[k];
		i++;
		k++;
	}
}

bool term_split_insert(char ***split,
					   char *new_char,
					   ssize_t pos)
{
	char   **new_split;
	char   *new_char_copy;
	size_t len;

	len = term_split_len(*split) + 1;
	if ((new_split = malloc((len + 1) * sizeof(char*))) == NULL)
		return (false);
	if ((new_char_copy = term_strdup(new_char)) == NULL)
	{
		free(new_split);
		return (false);
	}
	new_split[len] = NULL;
	term_apply_insert(*split, &new_split, new_char_copy, pos);
	free(*split);
	(*split) = new_split;
	return (true);
}