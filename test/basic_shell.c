#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t child;
	char *argv[2];

	printf("Ghost-in-the-shell-$ ");
	while ((read = getline(&line, &len, stdin)) != -1) 
	{
			argv[0] = strtok(line, "\n");
			argv[1] = NULL;	
	//		printf("%s", line);
			child = fork();
			if (!child)
			{
    				if (execve(argv[0], argv, NULL) == -1)
   				 {
   				     perror("./shell");
   				 }
			kill(child);
			}
			else
			{
			wait(NULL);
			}
	printf("Ghost-in-the-shell-$ ");
	}
	free(line);
	exit(97);
}

