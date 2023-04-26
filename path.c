#include "shell.h"
/**
 * get_location - a function that looks for the path of a command.
 * @string: pointer to the address of the command
 *
 * return: NULL
 */

char *get_location(char *string)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		path_copy = strdup(path);
		command_length = strlen(string);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, string);
			strcat(file_path, "\0");

				if (stat(file_path, &buffer) == 0)
				{
					free(path_copy);
					return (file_path);
				}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}

			free(path_copy);

				if (stat(string, &buffer) == 0)
				{
					return (string);
				}
		return (NULL);
	}
	return (NULL);
}
