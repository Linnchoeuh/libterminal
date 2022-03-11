/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@csr-pi03.ecole-89.com>
** Ecole 89 - 14/02/2022 10:00:00
**
** - term_tolower.c -
**
** *****************************************************************************
*/

#include "terminal_baselib.h"

int	term_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

