#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdarg.h>

/**
 * free_array - Free.
 *
 * @arr: array
 */

void free_array(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}


/**
 * free_strings - Free.
 *
 * @num: num
 *
 */


void free_strings(int num, ...)
{
	int i = 0;
	va_list args;

	va_start(args, num);

	for (i = 0; i < num; i++)
	{
		char *str = va_arg(args, char *);

		free(str);
		i++;
	}

	va_end(args);
}
