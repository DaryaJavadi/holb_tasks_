#include <stdio.h>

extern char **environ;
int main(void)
{
	for (int i = 0; environ[i] != NULL; i++)
	{
		printf("Environment: %s\n", environ[i]);
	}
	return (0);
}