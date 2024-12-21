#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid;

	printf("Before fork\n");

	pid = fork();

	if (pid == -1)
	{
	perror("fork failed");
	return 1;
	}

	printf("After fork\n");

	pid_t my_pid = getpid();
	printf("My pid is %d\n", my_pid);

	if (pid == 0)
	{
	printf("(%d) I am the child.\n", my_pid);
	}
	else
	{
	printf("(%d)  I am your father.\n", my_pid, pid);
	}

	return 0;
}
