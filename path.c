#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Tlist *path_list(){
	char *path = _getenv("PATH");

	if (path == NULL)
	{
		free(path);
		return (NULL);
	}

	Tlist *head = NULL, *cursor = NULL;

	char *dirs = strtok(path, ":");
	while (dirs) {

		Tlist *newNode =  malloc(sizeof(Tlist));
		if (!newNode) {
			perror("error memory 77");
			return (NULL);
		}


		strcpy(newNode->direct, dirs);
		newNode->next = NULL;

		if (!head) {
			head = newNode;
			cursor = newNode;
		}else
		{
			cursor->next = newNode;
			cursor = newNode;
		}
		dirs = strtok(NULL, ":");
	}
	return (head);
}

Tlist *path_addToEnd(Tlist *path, char *direct)
{
	return (NULL); 
}
