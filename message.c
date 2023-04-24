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
	char *string, *actual_command = NULL;
	int l, m, status;
	size_t n = 0;
	ssize_t nchar;
	char *argv[10];
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

		l = 0;
			while (string[l])
			{
				if (string[l] == '\n')
					string[l] = 0;
			l++;
			}
		m = 0;
		argv[m] = strtok(string, " ");
		while (argv[m])
		{
			m++;
			argv[m] = strtok(NULL, " ");
		}
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
			printf("%s : No such file or directory\n", av[0]);
			}

		else
			wait(&status);
	}

}

