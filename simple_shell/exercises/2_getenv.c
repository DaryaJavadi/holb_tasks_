#include <stdio.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name)
{
	for (int i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
		{
			return (environ[i] + strlen(name) + 1);
		}
	}
	return (NULL);
}

int main(void)
{
	printf("%s\n", _getenv("PATH"));
	return (0);
}

