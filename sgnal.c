#include "shell.h"

/**
 *handle_signal- function keeps track for interactive mode
 *@m: number
 *Return: void
 */

void handle_signal(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
