#include "all.h"

/**
 * string_length - Function.
 *
 * @string: parameter1
 *
 * Return: value.
 */

int string_length(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		i++;
	}

	return (i);
}




/**
 * string_duplicate - Function.
 *
 * @string: parameter1
 *
 * Return: value.
 */

char *string_duplicate(char *string)
{
	int i = 0;
	char *duplication = malloc(sizeof(char) * (string_length(string) + 1));

	if (duplication == NULL)
	{
		perror("Memory allocation failed\n");
		exit(1);
	}
	while (string[i] != '\0')
	{
		duplication[i] = string[i];
		i++;
	}
	duplication[i] = '\0';

	return (duplication);
}




/**
 * string_compare - Function.
 *
 * @string1: parameter1
 * @string2: parameter2
 *
 * Return: value.
 */

int string_compare(char *string1, char *string2)
{
	int i = 0;

	while (string1[i] != '\0')
	{
		if (string1[i] != string2[i])
		{
			return (-1);
		}
		i++;
	}
	while (string2[i] != '\0')
	{
		if (string1[i] != string2[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}




/**
 * string_concatenate - Function.
 *
 * @string1: parameter1
 * @string2: parameter2
 *
 * Return: value.
 */

char *string_concatenate(char *string1, char *string2)
{
	int i = 0;
	int len1 = string_length(string1);
	int len2 = string_length(string2);
	int count = len1 + len2;
	char *new_string;

	new_string = malloc(sizeof(char) * (count + 1));

	if (new_string == NULL)
	{
		perror("Memory allocation failed\n");
		exit(1);
	}

	while (string1[i] != '\0')
	{
		new_string[i] = string1[i];
		i++;
	}
	i = 0;
	while (string2[i] != '\0')
	{
		new_string[len1 + i] = string2[i];
		i++;
	}
	new_string[len1 + i] = '\0';

	return (new_string);
}




/**
 * string_concatenate_with_char - Function.
 *
 * @string1: parameter1
 * @c: parameter2
 * @string2: parameter3
 *
 * Return: value.
 */

char *string_concatenate_with_char(char *string1, char c, char *string2)
{
	int i = 0;
	int len1 = string_length(string1);
	int len2 = string_length(string2);
	int count = len1 + len2 + 1;
	char *new_string;

	new_string = malloc(sizeof(char) * (count + 1));

	if (new_string == NULL)
	{
		perror("Memory allocation failed\n");
		exit(1);
	}

	while (string1[i] != '\0')
	{
		new_string[i] = string1[i];
		i++;
	}
	new_string[i] = c;
	i = 0;
	while (string2[i] != '\0')
	{
		new_string[len1 + 1 + i] = string2[i];
		i++;
	}
	new_string[len1 + 1 + i] = '\0';

	return (new_string);
}
