#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100



/**
 * display_prompt -displays the shell prompt.
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
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		char *args[MAX_COMMAND_LENGTH];
		char *token = strtok((char *)command, " ");
		int arg_count = 0;

		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
			arg_count++;
		}
		args[arg_count] = NULL;
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			printf("Child process exited with status %d\n", WEXITSTATUS(status));
		else
			printf("Child process did not exit normally\n");
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
