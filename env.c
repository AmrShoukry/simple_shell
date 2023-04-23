#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * print_env - Calculate the length of a string.
 *
 * @env: program
 *
 * Return: The length of the string.
 */


void print_env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}


/**
 * set_row - Calculate the length of a string.
 *
 * @selected_key: key
 * @new_value: value
 * @full_length: num
 *
 * Return: The length of the string.
 */

char *set_row(char *selected_key, char *new_value, int full_length)
{
	char *new_row;

	new_row = malloc(sizeof(char) * (full_length + 2));
	strcpy(new_row, selected_key);
	strcat(new_row, "=");
	strcat(new_row, new_value);

	return (new_row);
}

/**
 * set_env - Calculate the length of a string.
 *
 * @arv: arr
 * @env: arr
 *
 * Return: The length of the string.
 */

void set_env(char **arv, char **env)
{
	char *cpy = NULL, *key, *new_row;
	char **custom;
	int i = 0, count = 0, found = 0;
	char *selected_key = arv[1];
	char *new_value = arv[2];
	int full_length = strlen(selected_key) + strlen(new_value);

	while (env[i] != NULL)
	{
printf("env[%i]: %s\n", i, env[i]);
		cpy = strdup(env[i]);
printf("wait\n");
		key = strtok(cpy, "=");
		if (strcmp(selected_key, key) == 0)
		{
			new_row = set_row(selected_key, new_value, full_length);
			env[i] = new_row;
			free(new_row);
			free(cpy);
			found = 1;
			break;
		}
		i++;
		free(cpy);
	}
	if (found == 0)
	{
		i = 0;
		while (env[i] != NULL)
		{
			i++;
			count++;
		}
		custom = malloc(sizeof(char *) * (count + 2));
		i = 0;
		while (env[i] != NULL)
		{
			custom[i] = env[i];
			i++;
		}
		new_row = set_row(selected_key, new_value, full_length);
		custom[i] = new_row;
		custom[i + 1] = NULL;
		env = custom;
		free(custom);
		free(new_row);
	}
}

/**
 * _exit_ - Calculate the length of a string.
 *
 * @status: program
 *
 * Return: The length of the string.
 */

int _exit_(char *status)
{
	int number = 0;
	int index = 0;

	if (status == NULL)
	{
		return (0);
	}

	while (status[index] != '\0')
	{
		if (status[index] >= '0' && status[index] <= '9')
		{
			number = (number * 10) + (status[index] - 48);
		}
		else
		{
			return (1);
		}
		index++;
	}
	return (number);
}

