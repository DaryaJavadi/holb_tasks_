#include <stdio.h>
#include <string.h>

char *_getenv(const char *name);

void print_path(void)
{
	char *path = _getenv("PATH");
	for (char *dir = strtok(path, ":"); dir; dir = strtok(NULL, ":"))
	printf("%s\n", dir);
}

int main(void)
{
	print_path();
	return (0);
}
