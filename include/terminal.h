/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@stu018.cst.bunny.local>
** Ecole 89 - 24/01/2022 10:00:00
**
** - Terminal.h -
**
** *****************************************************************************
*/

#ifndef		__TERMINAL_H__
#define		__TERMINAL_H__

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdbool.h>
#include	<sys/wait.h>
#include	<signal.h>

char		*read_entry(bool		block_sigint);

char		**get_entry(char		*command_header,
			    bool		block_sigint);

int		term_execute(const char		*cmd,
			     char		**env);

bool		term_cd(char			*path,
			char			**env);

// env var manipulation

char		*env_get_var(char		*var_name,
			     char		**env);

bool		env_set_var(char		*var_name,
			    char		*content,
			    char		**env);

char		**env_get_path(char		**env);

bool		env_replace_var_alias(char	**split_arg,
				      char	**env);

bool		env_enable_modification(char	**env);

void		env_free_var(char		**env);

// char ** manipulation

size_t		term_split_len(char		**split);

bool		term_split_insert(char		***split,
				  char		*new_char,
				  ssize_t	pos);

bool		term_split_remove(char		***split,
				  ssize_t	pos);

char		**term_split_char(char		*command,
				  char		parser);

char		*term_merge_char(char		**splitted,
				 char		*separation,
				 ssize_t	merge_len);

char		*term_str_append(char		*str1,
				 char		*str2);

// lib c reproduction function

char		*term_strdup(char		*s);

char		*term_strndup(const char	*s,
			      size_t		n);

size_t		term_strlen(char		*s);

size_t		term_strnlen(const char		*s,
			     size_t		n);

void		term_free_split(char		**splitted);

void		term_print_split(char		**splitted,
				 char		*separator);

int		term_strcmp(const char		*str1,
			    const char		*str2);

int		term_strncmp(const char		*first,
			     const char		*second,
			     size_t		length);

int		term_strcasecmp(const char	*a,
				const char	*b);

int	term_tolower(int c);

#endif  /*      __TERMINAL_H__    */

