#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100
void display_prompt(void);
void handle_exit(const char *command);
void handle_env(char *env);
char *construct_full_path(const char *command);
void execute_command(const char *full_path, char *const args[]);
char **get_environment(void);


/**
 * display_prompt - displays the shell prompt.
 */

void display_prompt(void)
{
	printf("simple_shell$ ");
}
/**
 * handle_exit - handles the exit command
 * @command: The command to check
 */

void handle_exit(const char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		exit(0);
	}
}
/**
 * handle_env - handles the env command
 * @env: the environment
 */

void handle_env(char *env)
{
	if (env == NULL)
	{
		printf("Environment is NULL\n");
		return;
	}
	i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
/**
 * construct_full_path - Constructs the full path for the executable.
 * @command: the command to construct the full path
 * Return: Always returns 0 to indicate successful execution.
 *
 */
char *construct_full_path(const char *command)
{
	char *path = "/bin/";
	char *full_path = (char *)malloc(strlen(path) + strlen(command) + 1);

	if (full_path == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	strcpy(full_path, path);
	strcat(full_path, command);
	return (0);
}
/**
 * execute_command - executes the specified command.
 * @full_path: The full path to the executable.
 * @args: The arguments for the executable.
 */
void execute_command(const char *full_path, char *const args[])
{
	if (execve(full_path, args, NULL) == -1)
	{
		perror("execve");
		free((void *)full_path);
		exit(EXIT_FAILURE);
	}
}


/**
 * main - Entry point of the shell program.
 * Return: Always returns 0 to indicate successful execution.
  */

int main(void)
{
	char **env = get_environment();
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		size_t len = strlen(command);

		if (len > 0 && command[len - 1] == '\n')
			command[len - 1] = '\0';
		handle_exit(command);
		if (strcmp(command, "env") == 0)
		{
			continue;
		}
		char *full_path = construct_full_path(command);
		char *args[MAX_COMMAND_LENGTH];
		int i = 0;
		char *token = strtok(command, " \n");

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " \n");
		}
		args[i] = NULL;
		execute_command(full_path, args);
		free(full_path);
	}

	handle_env(char *env);
	return (0);
}
