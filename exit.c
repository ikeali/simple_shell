#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

/**
 * display_prompt - displays the shell prompt.
 */

void display_prompt(void)
{
	printf("simple_shell$ ");
}

/**
 * execute_command - executes the specified command.
 * @command: The command to execute.
 */

void execute_command(const char *command)
{
	if (strlen(command) == 0)
		return;
	char *args[MAX_COMMAND_LENGTH];
	int i = 0;
	char *token = strtok((char *)command, " \n");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;
	if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	char *program = "/bin/ls";

	if (execve(program, args, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
/**
 * main - Entry point of the shell program.
 * Return: Always returns 0 to indicate successful execution.
  */

int main(void)
{
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
		execute_command(command);
	}
	return (0);
}

