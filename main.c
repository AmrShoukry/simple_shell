#include "all.h"

/**
 * main - Function.
 *
 * @argc: parameter1
 * @argv: parameter2
 *
 * Return: value.
 */

int main(int argc, char **argv)
{
	int active = isatty(STDIN_FILENO);
	int exitNumber = 0;

	if (active == 0)
	{
		exitNumber = non_interactive(argv[0], NULL, environ);
	}
	else
	{
		while (exitNumber == 0)
		{
			exitNumber = interactive(argc, argv, environ);
		}
		if (exitNumber == 20030803)
		{
			exitNumber = 0;
		}
	}
	return (exitNumber);
}
