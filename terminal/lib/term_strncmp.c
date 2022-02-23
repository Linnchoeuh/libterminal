/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@csr-pi03.ecole-89.com>
** Ecole 89 - 14/02/2022 10:00:00
**
** - term_strncmp.c -
**
** *****************************************************************************
*/

#include "terminal.h"

int		term_strncmp(const char	*first,
					 const char	*second,
					 size_t		length)
{
	size_t	i;

	i = 0;
	while (first[i] == second[i] && first[i] != '\0' &&
		   i < length)
		++i;
	if (i == length)
		return (0);
	return (first[i] - second[i]);
}

