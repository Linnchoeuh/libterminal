/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** term_str_append.c - 2022
**Fuse two char* into one str1 then str2
** *****************************************************************************
*/

#include "terminal.h"

char *term_str_append(char *str1,
					  char *str2)
{
  	char   *fuse;
	size_t i;
	size_t size1;
	size_t size2;

  	size1 = term_strlen(str1);
  	size2 = term_strlen(str2);
  	if ((fuse = malloc(size1 + size2 + 1)) == NULL)
    	return (NULL);
	i = 0;
  	while (i < size1)
    {
      	fuse[i] = str1[i];
      	++i;
    }
  	while (i < size1 + size2)
    {
      	fuse[i] = str2[i - size1];
      	++i;
    }
  	fuse[i] = 0;
  	return (fuse);
}