#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - main function
 * infos this prog will prompt a simple shell to simply run a program on it
 * by passing the complet program path
 *
 * Return: 0
 */

int main(void)
{
	char cmdPath[20];
	/* char *argv[] = {cmdPath, NULL}; */
	char *argv[2];
	pid_t pid;
	int status;

	argv[0] = cmdPath;
	argv[1] = NULL;

	while (1)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("An error occured!");
			exit(1);
		}
		else if (pid == 0)
		{
			printf("#cisfun$ ");
			fgets(cmdPath, 20, stdin);
			cmdPath[strlen(cmdPath) - 1] = 0;

			if ((execve(argv[0], argv, NULL) == -1))
			{
				printf("./shell: No such file or directory\n");
				exit(1);
			}
		}
		else
			wait(&status);
	}
	return (0);
}
