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

