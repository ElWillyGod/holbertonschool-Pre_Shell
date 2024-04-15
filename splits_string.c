#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
char **separador(char *str){
	char **todo;
	int parametro;
	char *parametro_separado;

	todo = malloc(20 * sizeof(char *)); /* como sacar el tamanio maximo de parametros?? */
	if (!todo)
		return (NULL);

	parametro_separado = strtok(str, " ");
	for (parametro = 0; parametro_separado; parametro++) {
		todo[parametro] = parametro_separado;
		parametro_separado = strtok(NULL, " ");
	
	}

	todo[parametro] = NULL;
	return (todo);
}

int main(){

	char str[] = "string de prueba el separador es el espacio";
	char **todo;
	int i;

	todo = separador(str);
	if (!todo)
		return (1);

	for (i = 0; todo[i]; i++) {

		printf("%s\n", todo[i]);
	
	}

	free(todo);
	return (0);
}
