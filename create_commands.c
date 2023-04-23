#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

void set_env(char **arv, char **env);

/**
 * create_commands - Calculate the length of a string.
 *
 * @arv: arr
 * @env: arr
 *
 * Return: The length of the string.
 */

int create_commands(char **arv, char **env)
{
	int executed = 1;

	if (strcmp(arv[0], "env") == 0)
	{
		print_env(env);
	}
	else if (strcmp(arv[0], "setenv") == 0)
	{
		if (arv[1] != NULL && arv[2] != NULL && arv[3] == NULL)
		{
			set_env(arv, env);
printf("\nhappend\n");
		}
		else
		{
			executed = 0;
		}
	}
	else
	{
		executed = 0;
	}
printf("wala\n");
	return (executed);
}
