#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

int _setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || value == NULL)
	{
		return (-1);
	}

	char *cursor = malloc(256 * sizeof(char));
	char *puntero = *environ;

	while (*puntero)
	{
		if (strncmp(puntero, name, strlen(name)) == 0 && puntero[strlen(name)] == '=') {
			if (!overwrite) {
				return (0);
			}

			strcpy(cursor, name);
			strcat(cursor, "=");
			strcat(cursor, value);

			free(puntero);
			puntero = cursor;

			return (0);

		}

		puntero += strlen(puntero) + 1;
	}

	if (!overwrite) {
		return (0);
	}

	/* terminar */

	return (0);
}

void free_list(Tlist *list)
{
	while (list)
	{
		Tlist *aux = list->next;
		free(list->direct);
		free(list);
		list = aux;
	}
}

void print_list(Tlist *head)
{
	Tlist *aux = head;

	while (aux)
	{
		printf("%s\n", aux->direct);
		aux = aux->next;
	}
}

Tlist *path_in_list()
{
	char *path = _getenv("PATH");
	if (!path)
	{
		fprintf(stderr, "Problemas con el PATH");
		exit(19);
	}
	 Tlist *head = NULL;
	Tlist *prev = NULL;
	char *token;
	char *path_copy = strdup(path);
	if (!path_copy)
	{
		fprintf(stderr, "ERROR con la copia");
	}
	
	token = strtok(path_copy, ":");
	while (token)
	{
		Tlist *newNode = malloc(sizeof(Tlist));
		if (!newNode)
		{
			fprintf(stderr, "ya me aburri de los errores, malloc newNode");
			//free(newNode);
			free(path_copy);
			free_list(head);
			exit(20);
		}

		newNode->direct = strdup(token);
		if (!newNode->direct)
		{
			fprintf(stderr, "por las dudas nomas yo que se, error al copiar el token");
			free(newNode);
			free(path_copy);
			free_list(head);
			exit(21);
		}

		newNode->next = NULL;
		if (prev)
		{
			prev->next = newNode;
		}
		else {
		head = newNode;
		}
		prev = newNode;
		token = strtok(NULL, ":");
	}

	free(path_copy);
	free(path);
	return (head);
}
