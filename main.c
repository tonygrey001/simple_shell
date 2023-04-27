#include "shell.h"

/**
 * main - function that starts program execution.
 * @ac: arg count
 * @argv: arg vector
 * @env: environment variable
 * Return: 0(success) else 1
 */

int main(int ac, char **argv, char **env)
{

	char *prompt = "cisfun$";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t n_chars;
	const char *delim = " \n";
	int n_tokens = 0;
	char *token;
	int i;
	(void)ac;

		while (1)
	{
	if (isatty(STDIN_FILENO))
	printf("%s", prompt);
	n_chars = getline(&lineptr, &n, stdin);
	if (n_chars == -1)
		{
	printf("Exiting shell....\n");
		return (-1);
		}
		lineptr_copy = malloc(sizeof(char) * n_chars);
			if (lineptr_copy == NULL)
				{
				perror("tsh: memory allocation error");
				return (-1);
				}
				strcpy(lineptr_copy, lineptr);
				token = strtok(lineptr, delim);

					while (token != NULL)
				{
					n_tokens++;
					token = strtok(NULL, delim);
				}
					n_tokens++;

					argv = malloc(sizeof(char *) * n_tokens);
					token = strtok(lineptr_copy, delim);
					for (i = 0; token != NULL; i++)
				{
				argv[i] = malloc(sizeof(char) * strlen(token));
				strcpy(argv[i], token);

				token = strtok(NULL, delim);
				}
				argv[i] = NULL;
			execmd(argv, env);
	}

	free(lineptr_copy);
	free(lineptr);

	return (0);
}
