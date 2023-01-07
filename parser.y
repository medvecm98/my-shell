%token PRARG
%token SEMIC
%token EOL

%define api.value.type {char*}

%{
#include "my_list.h"
%}

%%

command:
	   | first_subcommand EOL
	   | first_subcommand SEMIC command
	   ;

first_subcommand: subcommand
				;

subcommand: PRARG { $$ = $1; list_add($1); }
		  | PRARG subcommand { $$ = $1; list_add($1); }
		  ;

%%
