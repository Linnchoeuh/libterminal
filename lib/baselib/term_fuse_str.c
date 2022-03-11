/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** term_fuse_str.c - 2022
**
** Fuse two char* into one str1 then str2
** *****************************************************************************
*/

#include "terminal_baselib.h"

char *term_fuse_str(char *str1,
					  char *str2)
{
  	char *fuse_str;
	size_t i;
	size_t k;
	size_t target_len;
	size_t new_len;

	target_len = term_strlen(str1);
	new_len = target_len + term_strlen(str2);
	if ((fuse_str = malloc(new_len + 1)) == NULL)
		return (false);
	i = 0;
	while (str1[i] != '\0')
	{
		fuse_str[i] = str1[i];
		i++;
	}
	k = 0;
	while (i < new_len)
	{
		fuse_str[i] = str2[k];
		i++;
		k++;
	}
	fuse_str[i] = '\0';
  	return (fuse_str);
}