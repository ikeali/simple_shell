#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

/**
 * tokenize - Tokenizes a command string into separate arguments.
 *
 * @command: The command string to be tokenized.
 *
 * Description:
 *   It allocates memory for each argument and prints each token.
 */
void tokenize(const char *command)
{
	char *args[MAX_COMMAND_LENGTH];
	int i = 0;
	int arg_len = 0;
	int command_len = strlen(command);

	for (int j = 0; j <= command_len; j++)
	{
		if (command[j] == ' ' || command[j] == '\n' || command[j] == '\0')
		{
			if (arg_len > 0)
			{
				args[i] = (char *)malloc(arg_len + 1);
				if (args[i] == NULL)
				{
					perror("malloc");
					exit(EXIT_FAILURE);
				}
				strncpy(args[i], command + j - arg_len, arg_len);
				args[i][arg_len] = '\0';
				i++;
				arg_len = 0;
			}
		}
		else
		{
			arg_len++;
		}
	}
	for (int j = 0; j < i; j++)
	{
		printf("Token %d: %s\n", j, args[j]);
		free(args[j]);
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
	tokenize(command);
		return (0);
}

