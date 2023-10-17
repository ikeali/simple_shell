#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CHUNK_SIZE 100
typedef struct {
    char buffer[CHUNK_SIZE];
    int index;
    int size;
} Buffer;

char *read_line(Buffer *buf);
void refill_buffer(Buffer *buf);
char *custom_getline(void);
/**
 * custom_getline - Reads input from standard input,returns a line of input.
 *
 * Return: On success, a string containing the line of input.
 *         On end of file or error, NULL is returned.
 *
 * Note: The caller is responsible for freeing the allocated memory.
 */
char *custom_getline(void)
{
	Buffer buf = { {0}, 0, 0 };

	return (read_line(&buf));
}
/**
 * read_line - Reads a line from the input using a buffer.
 *
 * @buf: Pointer to the buffer struct to use.
 *
 * Return: A dynamically allocated string containing the line read.
 *         Returns NULL on end of file or error.
 */
char *read_line(Buffer *buf)
{
	char *line = NULL;
	int line_length = 0;

	while (1)
	{
		if (buf->index >= buf->size)
		{
			refill_buffer(buf);
			if (buf->size <= 0)
			{
				if (line_length == 0)
				{
					return (NULL);
				}
				else
				{
					line = realloc(line, line_length + 1);
					line[line_length] = '\0';
					return (line);
				}
			}
		}
		char c = buf->buffer[buf->index++];

		if (c == '\n')
		{
			line = realloc(line, line_length + 1);
			line[line_length] = '\0';
			return (line);
		}
		else
		{
			line = realloc(line, line_length + 2);
			line[line_length++] = c;
		}
	}
}
/**
 * refill_buffer - Refills the buffer with new data from the input.
 *
 * @buf: Pointer to the buffer struct to refill.
 */
void refill_buffer(Buffer *buf)
{
	buf->size = read(0, buf->buffer, CHUNK_SIZE);
	buf->index = 0;
}
/**
 * main - Entry point of the program.
 *
 * Return: Always returns 0 to indicate successful execution.
 */
int main(void)
{
	char *line;

	while (1)
	{
		printf("Enter a line: ");
		line = custom_getline();
		if (line == NULL)
		{
			printf("EOF or error encountered. Exiting.\n");
			break;
		}
		printf("You entered: %s\n", line);
		free(line);
	}
	return (0);
}

