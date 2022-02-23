/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** term_split_len.c - 2022
**
** *****************************************************************************
*/

#include "terminal.h"

size_t term_split_len(char **split)
{
	size_t len;

	if (split == NULL)
		return (0);
	len = 0;
	while (split[len] != NULL)
		len++;
	return (len);
}