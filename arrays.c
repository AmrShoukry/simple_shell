#include "all.h"

/**
 * get_number_of_elements - Function.
 *
 * @string: parameter1
 * @delimeter: parameter2
 * @start: parameter3
 *
 * Return: value.
 */

int get_number_of_elements(char *string, char delimeter, int start)
{
	int i = 0;
	int counter = 0;
	int lock = 0;

	if (string == NULL)
	{
		return (0);
	}
	counter = start;

	while (string[i] != '\0')
	{
		if (string[i] == delimeter)
		{
			if (lock == 0)
			{
				counter++;
				lock = 1;
			}
		}
		else
		{
			lock = 0;
		}
		i++;
	}
	return (counter);
}




/**
 * get_array_from_string - Function.
 *
 * @string: parameter1
 * @delimeter: parameter2
 * @start: parameter3
 *
 * Return: value.
 */

char **get_array_from_string(char *string, char delimeter, int start)
{
	int i = 0;
	int number = get_number_of_elements(string, delimeter, start);
	char **arr = NULL;
	char *del;

	arr = malloc(sizeof(char *) * (number + 1));
	if (arr == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}

	if (delimeter == ' ')
		del = " ";
	else if (delimeter == '\n')
		del = "\n";

	arr[i] = strtok(string, del);
	while (arr[i] != NULL)
	{
		i++;
		arr[i] = strtok(NULL, del);
	}
	arr[i] = NULL;

	return (arr);
}
