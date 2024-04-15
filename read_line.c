#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char *bufer;
	size_t imput = 0;


	printf("#");
	getline(&bufer, &imput, stdin);
	printf("%s\n%li", bufer, strlen(bufer));

	free(bufer);

	return (1);
}
