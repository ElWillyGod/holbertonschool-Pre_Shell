#include <stdio.h>
int main(int ac, char **av) {
	while (*av != NULL) {
		printf("Arguments %s\n", *av);
		av++;
	}
	return (0);
}
