#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t child_pid;
	int status;
	int i;

	for (i = 0; i < 5; i++)
	{
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork failed");
		return (1);
	}

	if (child_pid == 0)
	{
		char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
		printf("Child %d executing 'ls -l /tmp'\n", i + 1);
		execve(argv[0], argv, NULL);
		perror("Execve failed");
		return (1);
	}
	else
	{
		wait(&status);
		printf("Child %d finished\n", i + 1);
	}
	}

	return (0);
}
