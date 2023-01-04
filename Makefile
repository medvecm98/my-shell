all: my-shell

my-shell: main.c
	gcc -lreadline -Wall -Wpedantic -o my-shell main.c
