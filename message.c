#include "main.h"

/**
 * prompt - function that prompts user for input
 *
 * @av: pointer to string
 * @env: environment variable
 *
 */

void prompt(char **av, char **env)

{
	char *string = NULL;
	int l, status;
	size_t n = 0;
	ssize_t nchar;
	char *argv[] = {NULL, NULL};
	pid_t child_pid;

	while (1)
	{
	if (isatty(STDIN_FILENO))
	printf("cisfun$");
		nchar = getline(&string, &n, stdin);
		if (nchar == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}

		l =0;
			while (string[l])
			{
				if (string[l] == '\n')
					string[l] =0;
			l++;
			}
		argv[0] = string;
		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s : No such file or directory\n", av[0]);
		}
		else
			wait(&status);
	}

}

