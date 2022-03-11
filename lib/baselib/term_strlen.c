/*
** *****************************************************************************
** lenny.vigeon
** lenny.vigeon <lenny.vigeon@student-station>
**
** term_strlen.c - 2022
**
** *****************************************************************************
*/

#include "terminal_baselib.h"

size_t term_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}