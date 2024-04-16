#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
char *leer_entrada(){
	char *input;
	size_t input_salida = 0;

	getline(&input, &input_salida, stdin);

	return (input);
}

char **separar_string(char *input, char *separador){

	char **args = malloc(MAX_ARGS * sizeof(char *));
	int cant_args;

/**	if (input == NULL || input[0] == '\0') {
		args[0] = NULL;
		return (args);
	} */

	char *token = strtok(input, separador);
	for (cant_args = 0; token; cant_args++) {

		args[cant_args] = token;
		token = strtok(NULL, separador);
	
	}

	args[cant_args] = NULL;

	return (args);
}
char *_getenv(const char *var)
{
	if (var == NULL)
		return (NULL);

	char *cursor = malloc(256 * sizeof(char));
	char *puntero = *environ;

	while (*puntero) {
		if (strncmp(puntero, var, strlen(var)) == 0 && puntero[strlen(var)] == '=') {
			strcpy(cursor, puntero);
			return (cursor);
		}
		puntero += strlen(puntero) + 1;
	}

	free(cursor);
	return (NULL);

}
char *dir_command(char * command){
	char *path, *temp;

	path = _getenv("PATH");
	if (!path || !(*path)){

		free(path);
		return (NULL);

	}
	temp = strtok(path, ":");
	while (temp) {
		char aux[MAX_INPUT];
		strcpy(aux, temp);
		strcat(aux, "/");
		strcat(aux, command);

		if (access(aux, X_OK) == 0) {
			return strdup(aux);
		}

		temp = strtok(NULL, ":");
	}
	return (NULL);
}
void execute_command(char **args){

	char *comando = args[0];

	if (comando[0] != '/' && comando[0] != '.') {
		comando = dir_command(comando);
	}
	pid_t pid = fork();

	if (pid == -1) {
		perror("ERROR fork");
		exit(100);
	}else if (pid == 0) {
		if (execve(comando, args, NULL) < 0) {
			perror("ERROR command");
			exit(99);
		}
	}else {
	wait(NULL);
	}
}

int main(){
	while (1) {
		printf("WillyShel> ");
		char *input = leer_entrada();
		size_t input_leida = strlen(input);

		if (input_leida <= 1)
			continue;

		char **args = separar_string(input, " \n");

		if (strcmp(args[0], "exit") == 0) {
			free(input);
			free(args);
			free(input_leida);
			break;
		}

		execute_command(args);

		free(input);
		free(args);
	}


	return (0);
}
