#include <stdio.h>

extern char **environ;

int main(int argc, char **argv, char **env)
{
	printf("env: %p, environ: %p\n", (void *)env, (void *)environ);
	return (0);
}
