#include "all.h"

/**
 * create_commands - Function.
 *
 * @command: parameter1
 * @arv: parameter2
 * @env: parameter3
 * @act: parameter4
 * @prg: parameter5
 *
 * Return: value.
 */


int create_commands(char *command, char **arv, char **env, int act, char *prg)
{
	int return_number = 0;
	char *program_name;

	if (string_compare(command, "exit") == 0)
	{
		(return_number) = _exit_(arv[1]);
	}
	else if (string_compare(command, "env") == 0)
	{

		print_environment_variables(env);
	}
	else
	{
		if (act == 0)
		{
			write(1, prg, string_length(prg));
			write(1, ": 1: ", 5);
			write(1, command, string_length(command));
			write(1, ": not found\n", 12);
		}
		else
		{
			program_name = get_program_name(prg);
			write(1, program_name, string_length(program_name));
			write(1, ": ", 2);
			write(1, command, string_length(command));
			write(1, ": command not found\n", 20);
			free(program_name);
		}
	}
	return (return_number);
}




/**
 * execute - Function.
 *
 * @cmd: parameter1
 * @path: parameter2
 * @arv: parameter3
 * @env: parameter4
 * @act: parameter5
 * @prg: parameter6
 *
 * Return: value.
 */

int execute(char *cmd, char *path, char **arv, char **env, int act, char *prg)
{
	int return_number = 0;
	pid_t id;

	if (string_compare(cmd, "env") == 0)
	{
		(return_number) = create_commands(cmd, arv, env, act, prg);
	}
	else if (path != NULL)
	{
		id = fork();
		if (id == 0)
		{
			execve(path, arv, NULL);
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		(return_number) = create_commands(cmd, arv, env, act, prg);
	}
	return (return_number);
}
