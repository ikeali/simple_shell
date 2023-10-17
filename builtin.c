#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
/**
 * handle_exit - Handle the built-in exit command.
 * @arg: The argument containing the exit status.
 * Return: void
 *
 * This function processes the exit command, terminating the shell with the
 */
void handle_exit(const char *arg)
{
        if (arg == NULL)
        {
                exit(EXIT_SUCCESS);
        }
        else
        {
                int status = atoi(arg);

                exit(status);
        }
}
/**
 * main - Entry point of the shell program.
 * Return: Always returns 0 to indicate successful execution.
  */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	printf("Enter a command: ");
	fgets(command, MAX_COMMAND_LENGTH, stdin);
	size_t len = strlen(command);

	if (len > 0 && command[len - 1] == '\n')
	{
		command[len - 1] = '\0';
	}
	if (strncmp(command, "exit", 4) == 0)
	{
		char *arg = strtok(command + 4, " \n");

		handle_exit(arg);
	}
	return (0);
}
