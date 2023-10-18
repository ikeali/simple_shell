#ifndef _SHELL_H_
#define _SHELL_H_

char **get_environment();
#define CHUNK_SIZE 100
#define MAX_COMMAND_LENGTH 100

void display_prompt(void);
void handle_env(void);
void handle_exit(const char *command);
char *construct_full_path(const char *command);
/*void execute_command(const char *full_path, char *const args[]);*/
void execute_command(const char *command);
void tokenize(const char *command);

	
typedef struct {
    char buffer[CHUNK_SIZE];
    int index;
    int size;
} Buffer;

char *read_line(Buffer *buf);
void refill_buffer(Buffer *buf);
char *custom_getline(void);
void custom_setenv(const char *variable, const char *value);
void custom_unsetenv(const char *variable);
void printenv(const char *var_name);
void handle_exit(const char *arg);
void update_pwd(void);
void change_directory(const char *path);

#endif  // SHELL_H
