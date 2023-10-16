<<<<<<< HEAD
#include "shell.h"

/**
 * _strncpy - copy a string
 * @dest: destination string to be copied to
 * @src: the source string
 *
 * @n: amount of characters to be copied
 * Return: concatenated string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - concatenate on two string
 * @dest: first string
 * @src: second string
 * @n: amount of bytes to be use
 *
 * Return: the concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strchr - locate a character in string
 * @s: string to be parse
 * @c: character to look for
 *
 * Return: pointer to memory area (s)
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
=======
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

>>>>>>> e2ce69a7cb5603f2def628b5744c8f7ec6c44ef6
