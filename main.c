#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include "parser.tab.h"
#include "lex.yy.h"
#include "my_list.h"
#include "shell_utils.h"

extern char **environ;
extern int yyparse();
extern int parser_aa;
extern YY_BUFFER_STATE yy_scan_buffer(const char* str);

int
main(int argc, char ** argv) {
	yy_scan_buffer("ls -la");
	yyparse();
	printf("%d\n", parser_aa);
    return 0;
}
