#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

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
    printf("Before unsetting MY_VAR:\n");
    print_env();

    _unsetenv("MY_VAR");

    printf("\nAfter unsetting MY_VAR:\n");
    print_env();

    return 0;
}
