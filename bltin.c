#include "shell.h"

/**
* handle_builtin - function handles execution of builtins
* @commandline: tokenized commands
* @line: input read from stdin
*
* Return: 1 or 0
*/
int handle_builtin(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(*command, builtin.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (_strcmp(*command, builtin.exit) == 0)
	{
		exit_cmd(command, line);
		return (1);
	}
	return (0);
}
