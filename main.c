#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Calculate the length of a string.
 *
 * @argc: number
 * @argv: arv
 * @env: array
 *
 * Return: The length of the string.
 */

int main(int argc, char **argv, char **env)
{
	int active = isatty(STDIN_FILENO);
	int exitNumber = 0;

	if (active == 0 || argc == 10)
		exitNumber = non_interactive(argv[0], env, NULL);
	else
		exitNumber = interactive(argc, argv, env);

	return (exitNumber);
}
