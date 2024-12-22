#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name)
{
    for (int i = 0; environ[i]; i++)
    {
        if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
        {
            return environ[i] + strlen(name) + 1;
        }
    }
    return NULL;
}

int _setenv(const char *name, const char *value, int overwrite)
{
    char *new_var;
    size_t len;
    int i;

    if (name == NULL || value == NULL)
        return -1;

    len = strlen(name) + strlen(value) + 2;
    new_var = malloc(len);
    if (new_var == NULL)
        return -1;

    snprintf(new_var, len, "%s=%s", name, value);

    for (i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
        {
            if (overwrite)
            {
                environ[i] = new_var;
                return 0;
            }
            free(new_var);
            return 0;
        }
    }

    environ[i] = new_var;
    environ[i + 1] = NULL;
    return 0;
}

int _unsetenv(const char *name)
{
    int i, j;

    for (i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
        {
            free(environ[i]);
            for (j = i; environ[j] != NULL; j++)
            {
                environ[j] = environ[j + 1];
            }
            return 0;
        }
    }
    return -1;
}

void print_env(void)
{
    for (int i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
}

int main(void)
{
    _setenv("MY_VAR", "Hello", 1);
    _setenv("PATH", "/usr/local/bin:/usr/bin", 1);
    _setenv("MY_VAR", "World", 1);

    printf("MY_VAR: %s\n", _getenv("MY_VAR"));

    printf("After setting variables:\n");
    print_env();

    _unsetenv("MY_VAR");

    printf("\nAfter unsetting MY_VAR:\n");
    print_env();

    return 0;
}
