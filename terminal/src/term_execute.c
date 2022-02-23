/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** execute.c - 2022
**
** *****************************************************************************
*/

#include "terminal.h"

static void term_executer(char **split_arg,
						  char **path,
						  char **env,
						  int  *out)
{
	char   *tmp;
	char   *program_command;
	size_t i;

	i = 0;
  	(*out) = 0;
	if (path != NULL)
	{
		program_command = split_arg[0];
		while (program_command != NULL && path[i] != NULL)
		{
			split_arg[0] = term_str_append(path[i], "/");
			tmp = split_arg[0];
			split_arg[0] = term_str_append(tmp, program_command);
			free(tmp);
			(*out) = execve(split_arg[0], split_arg, env);
			free(split_arg[0]);
			i++;
		}
		split_arg[0] = program_command;
	}
	else
		(*out) = execve(split_arg[0], split_arg, env);
	write(STDOUT_FILENO, "Command not found.\n", 19);
}

int	term_execute(const char	*cmd,
				 char		**env)
{
	int	  out;
	int	  get;
	char  **split_arg;
	char  **path;
	pid_t fork_id;

	path = NULL;
	if (term_strncmp(cmd, "/", 1) != 0 &&
		term_strncmp(cmd, "./", 2) != 0 &&
		term_strncmp(cmd, "../", 3) != 0)
		path = env_get_path(env);
  	split_arg = term_split_char((char*) cmd, ' ');
  	fork_id = fork();
  	if (fork_id == 0)
    {
		term_executer(split_arg, path, env, &out);
		exit(out);
    }
  	else
    	waitpid(-1, &get, 0);
	term_free_split(split_arg);
	term_free_split(path);
  	return (WEXITSTATUS(get));
}