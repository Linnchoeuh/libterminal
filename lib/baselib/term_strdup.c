/*
** *****************************************************************************
** lenny.vigeon
** lenny.vigeon <lenny.vigeon@student-station>
**
** term_strdup.c - 2022
**
** *****************************************************************************
*/

#include "terminal.h"

char *term_strdup(char *s)
{
	int  i;
	char *str;

	i = 0;
	if ((str = malloc(term_strlen(s) + 1)) == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		str[i] = s[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

