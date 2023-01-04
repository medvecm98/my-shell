#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

int
find_in_path(const char* executable) {
	char* path = getenv("PATH");
	if (!path) {
		printf("PATH variable is not set.");
	}
	char* token = strtok(path, ":");
	while (token) {
		char* output = malloc(256);
		snprintf(output, strlen(token) + strlen(executable) + 2, "%s/%s", token, executable);
		printf("Executing ... %s \n", output);
		execl(output, NULL);
		token = strtok(NULL, ":");
	}
}

int
main(int argc, char ** argv) {
    while (1) {
        char* line = readline("mysh> ");
        int pid = fork();
        if (pid == 0) {
			find_in_path(line);
			warn("mysh: %s", line);
        }
        else {
			int wstatus;
            waitpid(pid, &wstatus, 0);
        }
        free(line);
    }
    return 0;
}
