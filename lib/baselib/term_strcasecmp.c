/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@csr-pi03.ecole-89.com>
** Ecole 89 - 14/02/2022 10:00:00
**
** - term_strcasecmp.c -
**
** *****************************************************************************
*/

#include "terminal.h"

int	term_strcasecmp(const char	*a,
					const char	*b)
{
	size_t i;

	i = 0;
	while (term_tolower(a[i]) == term_tolower(b[i]) &&
	    	a[i] != 0 && b[i] != 0)
		++i;
  	return (term_tolower(a[i]) - term_tolower(b[i]));
}

