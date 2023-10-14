#ifndef SHELL_H
#define SHELL_H


#define MAX_COMMAND_LENGTH 100

int intadd(int int1, int int2);
void display_prompt(void);
void execute_command(const char *command);
char *search_path(const char *command);





#endif  /* SHELL_H */

