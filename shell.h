#ifndef _SHELL_H_
#define _SHELL_H_

char **get_environment();
#define CHUNK_SIZE 100

void display_prompt(void);
void handle_env(void);
void handle_exit(const char *command);
char *construct_full_path(const char *command);
void execute_command(const char *full_path, char *const args[]);

typedef struct
{
        char buffer[CHUNK_SIZE];
        int index;
        int size;
} Buffer;
char *read_line(Buffer *buf);
void refill_buffer(Buffer *buf);
char *custom_getline(void);

#endif  // SHELL_H
