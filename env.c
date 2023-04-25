#include "all.h"

/**
 * get_environment_value_helper - Function.
 *
 * @l: parameter1
 * @n: parameter2
 * @m: parameter3
 * @e: parameter4
 * @v: parameter5
 *
 * Return: value.
 */

void get_environment_value_helper(int *l, int *n, int m, char **e, char *v)
{
	while (e[*l][*n] != '\0' && e[*l][*n] != '\n')
	{
		v[*n - m] = e[*l][*n];
		*n = *n + 1;
	}
	v[*n - m] = '\0';
}

/**
 * get_environment_variable_value_helper2 - Function.
 *
 * @n1: parameter1
 * @n2: parameter2
 * @n3: parameter3
 *
 * Return: value.
 */

void get_environment_variable_value_helper2(int *n1, int *n2, int *n3)
{
	*n1 = *n1 + 1;
	*n2 = 0;
	*n3 = 0;
}



/**
 * get_environment_variable_value - Function.
 *
 * @env: parameter1
 * @text: parameter2
 *
 * Return: value.
 */

char *get_environment_variable_value(char **env, char *text)
{
	int line = 0, old_cursor = 0, new_cursor = 0, found = 0, count = 0, minus = 0;
	char *value;

	while (env[line] != NULL)
	{
		while (env[line][new_cursor] != '\0' && env[line][new_cursor] != '\n')
		{
			if (env[line][new_cursor] == '=')
			{
				found = 1;
				while (new_cursor > old_cursor && env[line][old_cursor] != '\0')
				{
					if (env[line][old_cursor] != text[old_cursor])
						found = 0;
					old_cursor++;
				}
				if (found == 1)
				{
					old_cursor = ++new_cursor;
					minus = new_cursor;
					while (env[line][old_cursor] != '\0' && env[line][old_cursor++] != '\n')
						count++;
					value = malloc(sizeof(char) * (count + 1));
					if (value == NULL)
					{
						perror("Memory allocation failed");
						exit(1);
					}
					get_environment_value_helper(&line, &new_cursor, minus, env, value);
					value[new_cursor - minus] = '\0';
					return (value);
				}
				break;
			}
			new_cursor++;
		}
		get_environment_variable_value_helper2(&line, &new_cursor, &old_cursor);
	}
	return (NULL);
}




/**
 * print_environment_variables - Function.
 *
 * @env: parameter1
 *
 * Return: value.
 */

void print_environment_variables(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		write(1, env[i], string_length(env[i]));
		write(1, "\n", 1);
		i++;
	}
}



/**
 * get_command_path - Function.
 *
 * @paths: parameter1
 * @command: parameter2
 *
 * Return: value.
 */


char *get_command_path(char *paths, char *command)
{
	char *path, *program;

	if (access(command, X_OK) == 0)
	{
		return (command);
	}

	path = strtok(paths, ":");
	while (path != NULL)
	{
		program = string_concatenate_with_char(path, '/', command);
		if (access(program, X_OK) == 0)
		{
			return (program);
		}
		else
		{
			free(program);
		}
		path = strtok(NULL, ":");
	}

	return (NULL);
}
