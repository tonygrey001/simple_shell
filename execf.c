#include "shell.h"

/**
* exit_cmd - function that handles eexit shell
* @command: tokenized command
* @line: tokenized command
* @line: input read from stdin
*
* Return: void
*/
void exit_cmd(char **command, char *line)
{
	free(line);
	free_buffers(command);
	exit(0);
}
