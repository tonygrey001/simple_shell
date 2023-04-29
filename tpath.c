#include "shell.h"

/**
* test_path - checks whether path is valid
* @path: path from tokens
* @command: command entered
*
* Return: path appended with commandor NULL
*/
char *test_path(char **path, char *command)
{
	int i = 0;
	char *output;

	while (path[i])
	{
		output = append_path(path[i], command);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		i++;
	}
	return (NULL);
}
