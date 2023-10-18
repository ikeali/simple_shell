#include "shell.h"

/**
 * custom_setenv - Initializes or modifies an environment variable.
 * @variable: Name of the environment variable.
 * @value: Value to set for the environment variable.
 *
 * Description:
 * This function initializes a new environment variable
 */

void custom_setenv(const char *variable, const char *value)
{
        int ret = setenv(variable, value, 1);

        if (ret == -1)
        {
                fprintf(stderr, "Failed to set environment variable.\n");
        }
}
/**
 * custom_unsetenv - Removes an environment variable.
 * @variable: Name of the environment variable to be removed.
 *
 * Description:
 * This function removes the specified environment variable.
 */
void custom_unsetenv(const char *variable)
{
        int ret = unsetenv(variable);

        if (ret == -1)
        {
                fprintf(stderr, "Failed to unset environment variable.\n");
        }
}
/**
 * printenv - Print the value of an environment variable.
 * @var_name: The name of the environment variable to print.
 *
 * This function prints the value of the specified environment variable to
 */
void printenv(const char *var_name)
{
        char *value = getenv(var_name);

        if (value != NULL)
        {
                printf("%s=%s\n", var_name, value);
        }
        else
"setenv.c" 68L, 1488C
