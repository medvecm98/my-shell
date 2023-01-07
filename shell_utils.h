#ifndef MY_SHELL_UTILS
#define MY_SHELL_UTILS

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>

int
find_in_path(const char* executable) {
	char* path = getenv("PATH");
	if (!path) {
		printf("PATH variable is not set.");
	}
	char* token = strtok(path, ":");
	while (token) {
		char* output = (char *) malloc(256);
		snprintf(output, strlen(token) + strlen(executable) + 2, "%s/%s", token, executable);
		printf("Executing ... %s \n", output);
		execl(output, NULL);
		token = strtok(NULL, ":");
	}
}

#endif //MY_SHELL_UTILS
