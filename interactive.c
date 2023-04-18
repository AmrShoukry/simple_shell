#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void print_env(char **env);
int _exit_(char *status);
int non_interactive(int argc, char **env, char *file_name);
char *get_command(char *command);

/**
 * interactive - Calculate the length of a string.
 *
 * @argc: program
 * @argv: environment
 * @env: env
 *
 * Return: The length of the string.
 */

int interactive(int argc, char **argv, char **env)
{
	char *command = NULL;
	char *real_command, *real_command2, *command_name, *command_path;
	char **arv;
	size_t length;
	ssize_t myread;
	int i = 0, count = 0, returnValue = 0;
	pid_t id;

	if (argc == 2)
	{
		(returnValue) = non_interactive(argc, env, argv[1]);
		return (returnValue);
	}

	while (1)
	{
		printf("$ ");
		myread = getline(&command, &length, stdin);
		if (myread == -1)
			break;

		real_command = malloc(sizeof(char) * (myread - 1));
		i = 0;
		while (command[i] != '\0')
		{
			real_command[i] = command[i];
			if (i == myread - 1)
				real_command[i] = '\0';
			i++;
		}
		real_command[i] = '\0';
		i = 0;
		real_command2 = strdup(real_command);
		command_name = strtok(real_command2, " ");
		command_path = get_command(command_name);
		while (command_name != NULL)
		{
			count++;
			command_name = strtok(NULL, " ");
		}
		arv = malloc(sizeof(char *) * count);
		command_name = strtok(real_command, " ");
		while (command_name != NULL)
		{
			arv[i] = command_name;
			command_name = strtok(NULL, " ");
			i++;
		}
		arv[i] = NULL;
		if (command_path != NULL)
		{
			id = fork();
			if (id == 0)
			{
				if (strcmp(arv[0], "env") == 0)
					print_env(env);
				else
					execve(command_path, arv, NULL);
			}
			else
				wait(NULL);
		}
		else
		{
			if (strcmp(arv[0], "exit") == 0)
			{
				(returnValue) = _exit_(arv[1]);
				return (returnValue);
			}
			else
				printf("%s: No such file or directory\n", argv[0]);
		}
	}
	return (returnValue);
}
