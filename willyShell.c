#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_ARGS 64

char *leer_entrada(){
	char *input;
	size_t input_salida = 0;

	getline(&input, &input_salida, stdin);

	return (input);
}

char **separar_parametros(char *imput){

	char **args = malloc(MAX_ARGS * sizeof(char *));
	int cant_args;

/**	if (imput == NULL || imput[0] == '\0') {
		args[0] = NULL;
		return (args);
	} */

	char *token = strtok(imput, " \n");
	for (cant_args = 0; token; cant_args++) {

		args[cant_args] = token;
		token = strtok(NULL, " \n");
	
	}

	args[cant_args] = NULL;

	return (args);
}

void execute_command(char **args){
	pid_t pid = fork();

	if (pid == -1) {
		perror("ERROR fork");
		exit(100);
	}else if (pid == 0) {
		if (execve(args[0], args, NULL) < 0) {
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

		char **args = separar_parametros(input);

		if (strcmp(args[0], "exit") == 0) {
		break;
		}

		execute_command(args);

		free(input);
		free(args);
	}

	return (0);
}
