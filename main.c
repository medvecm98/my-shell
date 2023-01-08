#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/queue.h>
#include <string.h>
#include "shell_utils.h"

#define PRARG 258
#define SEMIC 259
#define EOL 260

extern char **environ;
extern char* yylval;

struct entry {
    char* prarg;
    LIST_ENTRY(entry) entries;
};

LIST_HEAD(listhead, entry);

struct list_wrapper {
	struct listhead head;
	char* command;
	struct entry* last;
};

int
main(int argc, char ** argv) {
	int head_inserted = 0;
	int command_found = 0;
	struct list_wrapper wrapper;

	LIST_INIT(&wrapper.head);

	yy_scan_string("ls -la\n");
	int tok;
	while (tok = yylex()) {
		switch (tok) {
			case PRARG:
				size_t yylval_length = strlen(yylval);
				if (!command_found) {
					wrapper.command = malloc(yylval_length);
					strncpy(wrapper.command, yylval, yylval_length);
					command_found = 1;
					break;
				}
				struct entry* e = malloc(sizeof(struct entry));
				e->prarg = malloc(yylval_length);
				strncpy(e->prarg, yylval, yylval_length);
				if (!head_inserted) {
					LIST_INSERT_HEAD(&wrapper.head, e, entries);
					head_inserted = 1;
				}
				else {
					LIST_INSERT_AFTER(wrapper.last, e, entries);
				}
				wrapper.last = e;
				break;
			default:
				break;
		}
	}

	printf("command: %s\narguments:\n", wrapper.command);
	struct entry* iter;
	LIST_FOREACH(iter, &wrapper.head, entries) {
		printf("%s\n", iter->prarg);
	}


    return 0;
}
