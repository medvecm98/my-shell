%token PRARG
%token SEMIC
%token EOL

%{
%}

%code requires {
#include <sys/queue.h>
#include <stdio.h>

}

%code {

struct entry {
    char* prarg;
    LIST_ENTRY(entry) entries;
};

struct listhead head;
struct entry* last;

}

%define api.value.type {char*}

%%

command:
	   | first_subcommand EOL
	   | first_subcommand SEMIC command
	   ;

first_subcommand: subcommand { printf("list init\n"); LIST_INIT(&head); }
				;

subcommand: PRARG tail_args { struct entry* e = malloc(struct entry*); e->prarg = $1; LIST_INSERT_HEAD(&head, e, entries); last = e; }
		  ;

tail_args: PRARG tail_args { struct entry* e = malloc(struct entry*); e->prarg = $1; LIST_INSERT_AFTER(e, last, entries); last = e; }
		 | { printf("end of list\n"); }
	     ;

%%
