#include "shell.h"
/**
 *checker - function checks  built in function
 *@cmd: tokenized command
 *@buf: line drived
 *Return: 1 or 0
 */
int checker(char **cmd, char *buf)
{
	if (handle_builtin(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		execution(cmd[0], cmd);
		return (1);
	}
	return (0);
}
