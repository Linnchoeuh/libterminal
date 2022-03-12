/**
 * @file terminal.h
 * @author Lenny Vigeon (lenny.vigeon@ecole-89.com)
 * @brief Useful set of function to create a terminal and interact with
 * @version 1.0
 * @date 20-02-2022
 */

#ifndef		__TERMINAL_H__
#define		__TERMINAL_H__

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdbool.h>
#include	<sys/wait.h>
#include	<signal.h>

#include 	"terminal_baselib.h"
#include 	"terminal_strsplit.h"
#include 	"terminal_env.h"

/**
 * @brief Read STDIN until find a '\\n' and return a (char *) of it.
 * The '\\n' character is not kept.
 *
 * @param block_sigint Ignore CTRL+C (SIGINT) signal
 * @return char* On success a char with what was written in STDIN,
 * NULL if CTRL+D is invoked or if it fails.
 */
char		*read_entry(bool		block_sigint);


/**
 * @brief Read STDIN until find a '\\n' and
 * return a (char **) with NULL terminator at the end.
 * The (char **) separation is related to the spaces
 * the user puts on STDIN.
 * The '\\n' character is not kept.
 *
 * @param entry_header Example : bash> [user message]
 * @param block_sigint Block CTRL+C emited signal.
 * @return char**
 */
char		**get_entry(char		*entry_header,
			    bool		block_sigint);


/**
 * @brief Makes possible to execute every program in the computer.
 * It handle installed and local program,
 * and generate the path to launch them when it's necessary.
 *
 * @param cmd A char* that contains the command and it's parameter
 * @param env Environment variable
 * @return int Executed program output
 */
int		term_execute(const char		*cmd,
			     char		**env);


/**
 * @brief Change directory function (cd), works the same as
 * the real cd command.
 *
 * @param path Where you want to go.
 * @param env Environment variable (Optional but this remove features)
 * You must use env_enable_modification()
 * in order to use this function.
 * @return true if cd moved to the aked directory,
 * false if it failed to go to the asked directory.
 */
bool		term_cd(char			*path,
			char			**env);

#endif  /*      __TERMINAL_H__    */

