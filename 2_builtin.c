#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024
/**
 * update_pwd - Update the PWD environment variable to the current directory
 *
 * Return: None
 */

void update_pwd(void)
{
	char cwd[MAX_PATH_LENGTH];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		setenv("PWD", cwd, 1);
	}
	else
	{
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
}

/**
 * change_directory - converts the current directory of the process
 * @path: The directory to convert to, If NULL or "~", it convert to $HOME
 *
 * Return: None
 */

void change_directory(const char *path)
{
	const char *dir = (path == NULL) ? getenv("HOME") : path;

	if (chdir(dir) != 0)
	{
		perror("chdir");
	}
	else
	{
		update_pwd();
	}
}

/**
 * main - Entry point of the program
 * @argc: The number of arguments passed to the program
 * @argv: array of strings containing the arguments
 *
 * Return: 0 (success), other values on failure
 */

int main(int argc, char *argv[])
{
	if (argc == 1 || (argc == 2 && strcmp(argv[1], "~") == 0))
	{
		change_directory(NULL);
	}
	else if
		(argc == 2 && strcmp(argv[1], "-") == 0)
		{
			char *previous_dir = getenv("OLDPWD");

			if (previous_dir != NULL)
			{
				change_directory(previous_dir);
			}
			else
			{
				printf("cd: OLDPWD not set\n");
			}
		}
	else if
		(argc == 2)
		{
			change_directory(argv[1]);
		}
	else
	{
		printf("cd: too many arguments\n");
	}
	return (0);
}
