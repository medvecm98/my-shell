all: my-shell

my-shell: main.c lex.yy.c
	gcc -lreadline -Wall -Wpedantic -O0 -g3 -o my-shell main.c lex.yy.c -lfl

lex.yy.c: scanner.l
	flex scanner.l

clean:
	rm -rf my-shell
	rm -rf lex.yy.c lex.yy.h
