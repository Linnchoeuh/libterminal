/*
** *****************************************************************************
** lenny.vigeon
** lenny.vigeon <lenny.vigeon@student-station>
**
** term_free_split.c - 2022
**
** print the content of a char**
** *****************************************************************************
*/

#include "terminal_strsplit.h"

void term_split_print(char **splitted,
					  char *separator)
{
	size_t i;

	if (splitted == NULL)
		return;
	i = 0;
	while (splitted[i] != NULL)
	{
		write(STDOUT_FILENO, splitted[i], term_strlen(splitted[i]));
		write(STDOUT_FILENO, separator, term_strlen(separator));
		++i;
	}
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "\033[00m", 6);
}

