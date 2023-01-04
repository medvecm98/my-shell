#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char* line = readline("yolo> ");
    printf("%s\n", line);
    return 0;
}