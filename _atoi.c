#include "main.h"

/**
 * interactive - returns true if shell is in interactive mode
 * @info: struct address
 * Return: 0 else 1
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is delimeter
 * @c: char being checked
 * @delim: delimeter string
 * Return: 0 true else 1 false
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (0);
	return (1);
}

/**
 * _isalpha - checks for alphabetic  character
 * @c: Input character
 * Return: 0 (c is alpha) else 1
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (0);
	else
		return (1);
}

/**
 * _atoi - converts string to int
 * @s: converted string
 * Return: 1 if no int else int
 */

int _atoi(char *s)
{
	int i;
	int sign = 1;
	int flag = 0;
	int output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}
