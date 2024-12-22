#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

char *find_file_in_path(const char *filename)
{
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");
	struct stat st;

	while (dir)
	{
	char full_path[1024];
	snprintf(full_path, sizeof(full_path), "%s/%s", dir, filename);
	if (stat(full_path, &st) == 0)
	{
		return (strdup(full_path));
	}
	dir = strtok(NULL, ":");
	}

	return (NULL);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Usage: %s filename ...\n", argv[0]);
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		char *result = find_file_in_path(argv[i]);
		if (result)
		{
			printf("%s: %s\n", argv[i], result);
			free(result);
		}
		else
		{
			printf("%s: NOT FOUND\n", argv[i]);
		}
	}

	return (0);
}

