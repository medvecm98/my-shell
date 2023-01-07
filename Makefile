all: my-shell

my-shell: main.c lex.yy.c parser.tab.h parser.tab.c
	gcc -lreadline -Wall -Wpedantic -o my-shell main.c lex.yy.c parser.tab.c -lfl -ly

lex.yy.c: scanner.l
	flex scanner.l

parser.tab.c: parser.tab.h

parser.tab.h: parser.y
	bison -d -Wcounterexamples parser.y
