#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "
#define BUFFER_SIZE 1024

int main(void)
{
	char command[BUFFER_SIZE];
	pid_t pid;
	int status;

	while (1) 
	{
		printf(PROMPT);
		fflush(stdout);

	if (fgets(command, BUFFER_SIZE, stdin) == NULL)
	{
		break;
	}

	command[strcspn(command, "\n")] = '\0';

	if (strlen(command) == 0)
	{
		continue;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (1);
	}
	if (pid == 0)
	{
		if (execl(command, command, NULL) == -1)
		{
			perror("Error");
		}
		return (1);
	}
	else
	{
		wait(&status);
	}
	}

	return (0);
}

