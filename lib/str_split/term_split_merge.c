/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** - term_merge_char.c -
**
** Takes a (char **) and merge it into a single (char *)
** *****************************************************************************
*/

#include "terminal_strsplit.h"

static void write_into_char(char   *target,
					 		size_t *i,
					 		size_t bytes,
					 		char   *src)
{
	size_t k;

	k = 0;
	while (src[k] != '\0' && *i < bytes)
	{
		target[*i] = src[k];
		k++;
		(*i)++;
	}
}

static size_t get_char_len(char    **splitted,
						   char    *separation,
						   ssize_t merge_len)
{
	size_t  bytes;
	ssize_t str_count;

	str_count = 0;
	bytes = 0;
	while ((str_count < merge_len || merge_len == -1) &&
			splitted[str_count] != NULL)
	{
		bytes += term_strlen(splitted[str_count]);
		str_count++;
	}
	if (str_count > 0 && separation != NULL)
		bytes += term_strlen(separation) * (str_count - 1);
	return (bytes);
}

char *term_split_merge(char 	  **splitted,
					  char 	  *separation,
					  ssize_t merge_len)
{
	char   *merge;
	size_t i;
	size_t k;
	size_t bytes;

	if (splitted == NULL)
		return (NULL);
	bytes = get_char_len(splitted, separation, merge_len);
	if ((merge = malloc(bytes + 1)) == NULL)
		return (NULL);
	merge[bytes] = '\0';
	i = 0;
	k = 0;
	while (i < bytes)
	{
		write_into_char(merge, &i, bytes, splitted[k]);
		if (i < bytes && separation != NULL)
			write_into_char(merge, &i, bytes, separation);
		k++;
	}
	return (merge);
}

