#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
int main(){
	int i;

	for (i = 0; i < 5; i++) {

		pid_t pid = fork();

		if (pid == 0) {
			char *args[] = {"/bin/ls", "-l", "/tmp", NULL};
			execve(args[0], args, NULL);

			exit(1);
		}else if (pid > 0) {

			int estado;
			waitpid(pid, &estado, 0);
		
		}else {
		exit(1);
		}

	}

	return (0);
}
