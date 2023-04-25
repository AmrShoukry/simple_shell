#ifndef ALL

#define ALL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

extern char **environ;

int string_length(char *string);
char *string_duplicate(char *string);
int string_compare(char *string1, char *string2);
char *string_concatenate(char *string1, char *string2);
char *string_concatenate_with_char(char *string1, char c, char *string2);
char *string_copy_without_delimeter(char *string, char delimeter);
char *get_first_part(char *string, char delimeter);
char *trim_string(char *string);
char *get_program_name(char *prog_name);

int get_number_of_elements(char *string, char delimeter, int start);
char **get_array_from_string(char *string, char delimeter, int start);

int _exit_(char *status);

void get_environment_value_helper(int *l, int *n, int m, char **e, char *v);
void get_environment_variable_value_helper2(int *n1, int *n2, int *n3);
char *get_environment_variable_value(char **env, char *text);
void print_environment_variables(char **env);
char *get_command_path(char *paths, char *command);

int create_commands(char *command, char **arv, char **env, int act, char *prg);
int execute(char *cmd, char *path, char **arv, char **env, int act, char *prg);

int interactive(int argc, char **argv, char **env);
int non_interactive(char *program_name, char *file_name, char **env);
int execute_mode(char *full_command, char **env, int active, char *prog);

#endif
