/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** term_str_chain_fuse.c - 2022
**
** *****************************************************************************
*/

#include "terminal_baselib.h"

char *term_str_chain_fuse(ssize_t len, ...)
{
	char *new_str;
	char *get_str;
	ssize_t i;
	va_list ap;

	if (len == 0)
		return (term_strdup(""));
	va_start(ap, len);
	if ((new_str = term_strdup((char*) va_arg(ap, char*))) == NULL)
		return (NULL);
	i = 1;
	while ((len == -1 || i < len) &&
		(get_str = (char*) va_arg(ap, char*)) != NULL)
	{
		term_str_append(&new_str, get_str);
		i++;
	}
	va_end(ap);
	return (new_str);
}