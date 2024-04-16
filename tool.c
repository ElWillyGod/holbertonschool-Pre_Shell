#include "main.h"

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
