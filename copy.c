#include "shell.h"
/**
 * main - main entry to the program
 * Return: return 0 on success
 */

int main(void)
{
	char src[] = "Hello, world!";
	char dest[100];

	_strcpy(dest, src);
	printf("Original: %s\n", src);
	printf("Copied: %s\n", dest);
	return (0);
}

/**
 * _strcpy - copy a string
 * @dest: the destination string
 * @src: the source string
 * Return: pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i, len = 0;

	while (src[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

