/**
 * @file terminal_baselib.h
 * @author Lenny Vigeon (lenny.vigeon@ecole-89.com)
 * @date 20-02-2022
 */

#ifndef		__TERMINAL_BASELIB_H__
#define		__TERMINAL_BASELIB_H__

#include	<stdlib.h>
#include	<stdbool.h>
#include	<stdarg.h>
#include	<unistd.h>

#define TERM_TOLOWER(c) (((c) >= 'A' && (c) <= 'Z') ? ((c) + ('a' - 'A')) : (c))
#define TERM_TOUPPER(c) (((c) >= 'a' && (c) <= 'z') ? ((c) - ('a' - 'A')) : (c))

char *term_strdup(char *s);

char *term_strndup(const char *s,
			      size_t n);

size_t term_strlen(char	*s);

size_t term_strnlen(const char *s,
			    	size_t n);

int	term_strcmp(const char *str1,
			    const char *str2);

int	term_strncmp(const char *first,
			     const char	*second,
			     size_t	length);

int	term_strcasecmp(const char	*a,
					const char	*b);

/**
 * @brief Merge two (char *) into one.
 *
 * @param str1 First one.
 * @param str2 Second one.
 * @return char* on success,
 * NULL if the memory allocation went wrong.
 */
char		*term_str_fuse(char	*str1,
						   char	*str2);

/**
 * @brief Add at the next of target str, the merge content.
 * The fusion of this will be in target.
 *
 * @param target A overreferenced char* that will be edited.
 * @param merge The part that will be added at the target
 *
 * @return true on success, false on failure
 */
bool term_str_append(char **target,
				   	 char *merge);

/**
 * @brief Makes possible to fuse more than two str a the same time.
 * You can precise how many element you want to fuse in len,
 * but also set at -1 and just put a NULL a the of your list of str.
 *
 * @param len The amount of str to fuse. -1 to fuse them all,
 * but you have to add a NULL at the end of yout list.
 * @param ... Only expect str (char *) or NULL.
 *
 * @return char* The fusion of all the str given.
 * NULL on failure.
 */
char *term_str_chain_fuse(ssize_t len, ...);

#endif  /*      __TERMINAL_BASELIB_H__    */