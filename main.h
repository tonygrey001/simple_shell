#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

void prompt(char **av, char **env);
char *strtok(char *str, const char *delim);
char *get_location(char *command);
#endif
