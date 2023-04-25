#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

void print_env(char **env);
int _exit_(char *status);
void free_strings(int num, ...);

/**
 * set_commands - Calculate the length of a string.
 *
 * @commands: program
 * @file_name: name
 *
 * Return: The length of the string.
 */

int set_commands(char **commands, char *file_name)
{
	int i = 0, fd;
	int command_no = 0;
	char *token;
	char command[1024];

	if (file_name != NULL)
	{
		fd = open(file_name, O_RDONLY);
		read(fd, command, 1024);
	}
	else
	{
		read(STDIN_FILENO, command, 1024);
	}

	token = strtok(command, "\n");
	while (token != NULL && strlen(token) > 1)
	{
		commands[i] = token;
		command_no++;
		token = strtok(NULL, "\n");
		i++;
	}
	commands[i] = NULL;

	return (command_no);
}

/**
 * get_command - Calculate the length of a string.
 *
 * @command: program
 *
 * Return: The length of the string.
 */



char *get_command(char *command)
{
	char *pathenv = getenv("PATH");
	char *path_env = strdup(pathenv);
	char *directory;
	char *full_path;

	if (access(command, X_OK) == 0)
	{
		free(path_env);
		return (command);
	}

	directory = strtok(path_env, ":");
	while (directory != NULL)
	{
		full_path = malloc(strlen(directory) + strlen(command) + 2);
		strcpy(full_path, directory);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_env);
			return (full_path);
		}
		free(full_path);
		directory = strtok(NULL, ":");
	}
	free(path_env);
	return (NULL);
}



/**
 * non_interactive - Calculate the length of a string.
 *
 * @programName: program
 * @env: environment
 * @file_name: name
 *
 * Return: The length of the string.
 */

int non_interactive(char *programName, char **env, char *file_name)
{
	char *commandReal2, *token, *commands[1024], *commandResult;
	int arguments_no = 0, i = 0, lines = 0, command_no, returnValue;
	char **arv;
	pid_t id;

	command_no = set_commands(commands, file_name);
	while (lines < command_no)
	{
		commandReal2 = strdup(commands[lines]);
		token = strtok(commandReal2, " ");
		while (token != NULL)
		{
			arguments_no++;
			token = strtok(NULL, " ");
		}
		arv = malloc(sizeof(char *) * arguments_no);
		token = strtok(commands[lines], " ");
		i = 0;
		while (token != NULL)
		{
			arv[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		commandResult = get_command(commands[lines]);
		if (commandResult == NULL)
		{
			if (strcmp(arv[0], "exit") == 0)
			{
				(returnValue) = _exit_(arv[1]);
				return (returnValue);
			}
			else
				printf("%s: 1: %s: not found\n", programName, arv[0]);
		}
		else
		{
			id = fork();
			if (id == 0)
			{
				if (strcmp(arv[0], "env") == 0)
					print_env(env);
				else
					execve(commandResult, arv, NULL);
			}
			else
				wait(NULL);
		}
		lines++;
		free_strings(2, arv, commandReal2);
		arguments_no = 0;
	}
	return (0);
}
