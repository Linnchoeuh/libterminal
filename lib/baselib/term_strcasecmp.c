/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@csr-pi03.ecole-89.com>
** Ecole 89 - 14/02/2022 10:00:00
**
** - term_strcasecmp.c -
**
** *****************************************************************************
*/

#include "terminal_baselib.h"

int	term_strcasecmp(const char	*a,
					const char	*b)
{
	size_t i;

	i = 0;
	while (TERM_TOLOWER(a[i]) == TERM_TOLOWER(b[i]) &&
	    	a[i] != 0 && b[i] != 0)
		++i;
  	return (TERM_TOLOWER(a[i]) - TERM_TOLOWER(b[i]));
}

