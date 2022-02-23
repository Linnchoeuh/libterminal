/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** - Get_Entry -
**
** Read STDIN until find a '\\n' and
** return a (char **) with NULL terminator at the end.
** The (char **) separation is related to the spaces the user puts in STDIN.
** The '\n' character is not kept.
** *****************************************************************************
*/

#include "terminal.h"

char **get_entry(char *entry_header,
				 bool block_sigint)
{
	char *command;
	char **splitted_command;

	write(STDOUT_FILENO, entry_header, term_strlen(entry_header));
	if ((command = read_entry(block_sigint)) == NULL)
		return (NULL);
	splitted_command = term_split_char(command, ' ');
	free(command);
	return (splitted_command);
}

