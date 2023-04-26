#include "shell.h"

/**
 * main - function that starts program execution.
 * @ac: arg count
 * @av: arg vector
 * @env: environment variable
 * Return: 0(success) else 1
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1)
		prompt(av, env);
	return (0);
}
