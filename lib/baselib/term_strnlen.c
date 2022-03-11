/*
** *****************************************************************************
** lenny.vigeon
** lenny.vigeon <lenny.vigeon@student-station>
**
** term_strnlen.c - 2022
**
** *****************************************************************************
*/

#include "terminal.h"

size_t term_strnlen(const char *s,
					size_t	   n)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && i < n)
		++i;
	return (i);
}

