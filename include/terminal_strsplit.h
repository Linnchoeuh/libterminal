/**
 * @file terminal_strsplit.h
 * @author Lenny Vigeon (lenny.vigeon@ecole-89.com)
 * @date 20-02-2022
 */

#ifndef		__TERMINAL_STRSPLIT_H__
#define		__TERMINAL_STRSPLIT_H__

#include	<stdlib.h>

/**
 * @brief Free a (char **)
 *
 * @param splitted The (char **) you want to free.
 * Must have NULL terminator at his end
 */
void		term_free_split(char		**splitted);

/**
 * @brief Print in STDOUT the (char **) given in splitted
 *
 * @param splitted The (char **) you want to print.
 * @param separator Between each occurrence of the (char **),
 * you will be able to add an intermediary str of your choice.
 */
void		term_print_split(char		**splitted,
				 char		*separator);


/**
 * @brief Takes a (char **) and give back his length.
 *
 * @param split (char **) with a NULL pointer as terminator.
 * @return size_t len of the splitted str.
 */
size_t		term_split_len(char		**split);


/**
 * @brief To add a (char *) in a (char **) variable.
 *
 * @param split The adress of the (char **) you want to use as target.
 * @param new_char The new element you want to add.
 * @param pos The postition it will be added,
 * -1 means to add it at the end of the (char **).
 * @return true on success, false on failure.
 */
bool		term_split_insert(char		***split,
				  char		*new_char,
				  ssize_t	pos);


/**
 * @brief To remove a (char *) from a (char **) variable.
 *
 * @param split The adress of the (char **) you want to use as target.
 * @param pos The postition of the element you want to remove.
 * -1 means to remove the last occurence of the (char **).
 * @return true on success, false on failure.
 */
bool		term_split_remove(char		***split,
				  ssize_t	pos);


/**
 * @brief Split a (char *) element with a given parser.
 * The parser is not kept in the (char **).
 * The (char **) is ended with a NULL pointer.
 *
 * @param str The (char *) you want to split.
 * @param parser To indicate which character trigger a split in the (char **)
 * @return char** on success,
 * NULL if the memory allocation went wrong.
 */
char		**term_split_char(char		*str,
				  char		parser);


/**
 * @brief Takes a (char **) and merge it into a single (char *).
 * The separation parameter is added between each element of the (char **)
 * except at the start and the end.
 *
 * @param splitted The source (char **).
 * @param separation What you want to add betwwen to element of the (char **)
 * @param merge_len How many element of the (char **) you want to merge,
 * -1 means all.
 * @return char* on success,
 * NULL if the memory allocation went wrong.
 */
char		*term_merge_char(char		**splitted,
				 char		*separation,
				 ssize_t	merge_len);


/**
 * @brief Merge two (char *) into one.
 *
 * @param str1 First one.
 * @param str2 Second one.
 * @return char* on success,
 * NULL if the memory allocation went wrong.
 */
char		*term_str_append(char		*str1,
				 char		*str2);

#endif  /*      __TERMINAL_STRSPLIT_H__    */