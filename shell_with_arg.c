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

int main(int ac, char *av[], char *env[])
{
	char *cmd = NULL;
	char *token;
	size_t n = 0;
	int i = 0;
	pid_t pid;
	int status;
	char **arr = malloc(sizeof(char *) * 32);

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
			getline(&cmd, &n, stdin);
			token = strtok(cmd, " \n");
			arr[0] = token;
			i = 1;
			while (token != NULL)
			{
				token = strtok(NULL, " \n");
				arr[i] = token;
				i++;
			}
			/* if ((execve(arr[0], arr, NULL) == -1)) */
			if ((execve(arr[0], arr, env) == -1))
			{
				printf("./shell: No such file or directory\n");
				exit(1);
			}
		}
		else
			wait(&status);
	}
	free(cmd);
	return (0);
}
