#include "all.h"

/**
 * execute_mode - Function.
 *
 * @full_command: parameter1
 * @env: parameter2
 * @active: parameter3
 * @prog: parameter4
 *
 * Return: value.
 */


int execute_mode(char *full_command, char **env, int active, char *prog)
{
	char *command_name, *paths, *paths_copy, *command_path, *trimmed;
	char **arr;
	int exit_number = 0;

	trimmed = trim_string(full_command);
	if (trimmed == NULL)
		return (0);

	command_name = get_first_part(trimmed, ' ');
	paths = get_environment_variable_value(env, "PATH");
	paths_copy = string_duplicate(paths);
	command_path = get_command_path(paths, command_name);
	arr = get_array_from_string(trimmed, ' ', 1);
	exit_number = execute(command_name, command_path, arr, env, active, prog);

	free(arr);
	free(command_path);
	free(command_name);
	free(paths);
	free(paths_copy);
	free(trimmed);

	return (exit_number);
}


/**
 * interactive - Function.
 *
 * @argc: parameter1
 * @argv: parameter2
 * @env: parameter3
 *
 * Return: value.
 */

int interactive(int argc, char **argv, char **env)
{
	size_t length;
	char *full_command = NULL, *full_command2 = NULL;
	int exit_number = 0;

	if (argc == 2)
	{
		exit_number = non_interactive(argv[0], argv[1], env);
		return (exit_number);
	}

	write(1, "$ ", 2);
	if (getline(&full_command, &length, stdin) == -1)
	{
		write(1, "\n", 1);
		free(full_command);
		return (1);
	}
	full_command2 = string_copy_without_delimeter(full_command, '\n');
	exit_number = execute_mode(full_command2, env, 1, argv[0]);

	free(full_command);
	free(full_command2);

	return (exit_number);
}




/**
 * non_interactive - Function.
 *
 * @program_name: parameter1
 * @file_name: parameter2
 * @env: parameter3
 *
 * Return: value.
 */

int non_interactive(char *program_name, char *file_name, char **env)
{
	int fd, exit_number = 0, i = 0;
	char **commands;
	char command[1024] = "";

	if (file_name != NULL)
	{
		fd = open(file_name, O_RDONLY);
		if (fd == -1)
		{
			perror("open failed\n");
			exit(1);
		}
		if (read(fd, command, 1024) == -1)
		{
			perror("read failed\n");
			exit(1);
		}
		if (close(fd) == -1)
		{
			perror("close failed\n");
			exit(1);
		}
	}
	else if (read(STDIN_FILENO, command, 1024) == -1)
	{
		perror("read failed\n");
		exit(1);
	}
	commands = get_array_from_string(command, '\n', 0);
	while (commands[i] != NULL)
	{
		exit_number = execute_mode(commands[i], env, 0, program_name);
		if (exit_number != 0)
			break;
		i++;
	}
	free(commands);
	return (exit_number);
}
