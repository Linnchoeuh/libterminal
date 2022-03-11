/**
 * @file terminal_baselib.h
 * @author Lenny Vigeon (lenny.vigeon@ecole-89.com)
 * @version 1.0
 * @date 20-02-2022
 */

#ifndef		__TERMINAL_BASELIB_H__
#define		__TERMINAL_BASELIB_H__

#include	<stdlib.h>

char		*term_strdup(char		*s);

char		*term_strndup(const char	*s,
			      size_t		n);

size_t		term_strlen(char		*s);

size_t		term_strnlen(const char		*s,
			     size_t		n);

int		term_strcmp(const char		*str1,
			    const char		*str2);

int		term_strncmp(const char		*first,
			     const char		*second,
			     size_t		length);

int		term_strcasecmp(const char	*a,
				const char	*b);

int		term_tolower(int c);

#endif  /*      __TERMINAL_BASELIB_H__    */