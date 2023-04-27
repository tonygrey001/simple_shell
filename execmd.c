#include "shell.h"

/**
 * execmd - function that executes command.
 * @argv: array of strings.
 * @env: environment variable.
 *
 * return: void
 */

void execmd(char **argv, char **env)
{
	char *string = NULL, *actual_command = NULL;
	pid_t child_pid;
	 int status;

	if (argv)
	{
		string = argv[0];
		actual_command = get_location(string);

			child_pid = fork();
			if (child_pid == -1)
			{
			free(string);
			exit(EXIT_FAILURE);
			}
			if (child_pid == 0)
			{
			if (execve(actual_command, argv, env) == -1)
			printf("%s : No such file or directory\n", argv[0]);
			}
			else
			wait(&status);
	}
}

