
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;
#define MAX_ARGS 64
#define MAX_INPUT 1024

typedef struct rep_list Tlist;

struct rep_list
{
	char *direct;
	Tlist *next;
};

char *leer_entrada();

char *dir_command(char *command);

char **separar_string(char *input, char *separador);

char *_getenv(const char *busc);
int _setenv(const char *name, const char *value, int overwrite);

void execute_command(char **args);

void free_list(Tlist *i);
void print_list(Tlist *i);
Tlist *path_in_list();
#endif /* MAIN_H */
