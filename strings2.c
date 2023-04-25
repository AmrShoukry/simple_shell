#include "all.h"

/**
 * string_copy_without_delimeter - Function.
 *
 * @string: parameter1
 * @delimeter: parameter2
 *
 * Return: value.
 */

char *string_copy_without_delimeter(char *string, char delimeter)
{
	int i = 0;
	char *new = malloc(sizeof(char) * (string_length(string) + 1));

	if (new == NULL)
	{
		perror("Memory allocation failed\n");
		exit(1);
	}

	while (string[i] != '\0' && string[i] != delimeter)
	{
		new[i] = string[i];
		i++;
	}
	new[i] = '\0';

	return (new);
}




/**
 * get_first_part - Function.
 *
 * @string: parameter1
 * @delimeter: parameter2
 *
 * Return: value.
 */

char *get_first_part(char *string, char delimeter)
{
	int old_cursor = 0;
	int new_cursor = 0;
	char *first_part;

	while (string[new_cursor] != '\0' && string[new_cursor] != delimeter)
	{
		new_cursor++;
	}

	first_part = malloc(sizeof(char) * (new_cursor - old_cursor + 1));
	if (first_part == NULL)
	{
		perror("Memory allocation failed\n");
		exit(1);
	}
	while (new_cursor > old_cursor)
	{
		first_part[old_cursor] = string[old_cursor];
		old_cursor++;
	}
	first_part[old_cursor] = '\0';

	return (first_part);
}




/**
 * trim_string - Function.
 *
 * @string: parameter1
 *
 * Return: value.
 */

char *trim_string(char *string)
{
	int i = 0;
	int space_counter = 0;
	int length = string_length(string);
	char *trimmed;

	if (string == NULL)
	{
		return (NULL);
	}
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
		{
			space_counter++;
		}
		else
		{
			break;
		}
		i++;
	}
	if (space_counter == length)
	{
		return (NULL);
	}
	else
	{
		trimmed = malloc(sizeof(char) * (length - space_counter + 1));
		if (trimmed == NULL)
		{
			perror("Memory allocation failed\n");
			exit(1);
		}
		for (i = space_counter; i < length; i++)
		{
			trimmed[i - space_counter] = string[i];
		}
		trimmed[i - space_counter] = '\0';
		return (trimmed);
	}
}





/**
 * get_program_name - Function.
 *
 * @prog_name: parameter1
 *
 * Return: value.
 */

char *get_program_name(char *prog_name)
{
	int i = 0;
	int j = 2;
	int length = string_length(prog_name) - 2;
	char *name = malloc(sizeof(char) * (length + 1));

	if (name == NULL)
	{
		perror("Memory allocation failed\n");
		exit(1);
	}
	while (i < length)
	{
		name[i] = prog_name[j];
		i++;
		j++;
	}
	name[i] = '\0';

	return (name);
}
