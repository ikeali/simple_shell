#include "shell.h"

/**
 * interactive - this returns true when shell is in an interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - probe if character is a delimeter
 * @c: the char to probe
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - probe for alphabetic character
 * @c: character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - change a string to integer
 * @s: the string to be changed
 * Return: 0 if no numbers in string, changed number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int outcome = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			outcome *= 10;
			outcome += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -outcome;
	else
		output = outcome;

	return (output);
}
