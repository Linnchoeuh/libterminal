/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** term_str_append.c - 2022
**
** *****************************************************************************
*/

#include "terminal_baselib.h"

bool term_str_append(char **target,
				   		char *merge)
{
	char *new_str;

	if ((new_str = term_fuse_str(*target, merge)) == NULL)
		return (false);
	free(*target);
	*target = new_str;
	return (true);
}