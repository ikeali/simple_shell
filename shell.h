#ifndef _SHELL_H_
#define _SHELL_H_

char **get_environment();
#define CHUNK_SIZE 100
#define MAX_COMMAND_LENGTH 100

void display_prompt(void);
void handle_env(void);
void handle_exit(const char *command);
char *construct_full_path(const char *command);
void execute_command(const char *full_path, char *const args[]);
void tokenize(const char *command)
typedef struct
{
<<<<<<< HEAD
	char *type;
	int (*func)(info_t *);

} builtin_table;
typedef struct denum
{
	int cnt;
} denum;

/* toem_shloop.c */

int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* toem_parser.c */

int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loophsh.c */

int loophsh(char **);

/* toem_errors.c */

void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_lists.c */

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* toem_lists1.c */

size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* toem_string.c */

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* toem_delimiter_checker.c */

int is_chain(info_t *, char *, size_t *);
void probe_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

/* toem_string1.c */

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_exits.c */

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);


/* toem_errors1.c */

int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* toem_builtin.c */

int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* toem_builtin1.c */

int _myhistory(info_t *);
int _myalias(info_t *);

/*toem_getline.c */

ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* toem_tokenizer.c */

char **strtow(char *, char *);
char **strtow2(char *, char);

/* toem_realloc.c */

char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* toem_memory.c */

int bfree(void **);

/* toem_atoi.c */

int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* toem_getinfo.c */

void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* toem_environ.c */

char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* toem_getenv.c */

char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* toem_history.c */

char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

#endif
=======
        char buffer[CHUNK_SIZE];
        int index;
        int size;
} Buffer;
char *read_line(Buffer *buf);
void refill_buffer(Buffer *buf);
char *custom_getline(void);
void custom_setenv(const char *variable, const char *value)
void custom_unsetenv(const char *variable)
void printenv(const char *var_name)
void handle_exit(const char *arg)
void update_pwd(void)
void change_directory(const char *path)

#endif  // SHELL_H
>>>>>>> 5f43b41af3778b7755a4325f12d7a876d8b3c7b6
