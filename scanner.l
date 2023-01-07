%{
#include "parser.tab.h"
%}

%option header-file="lex.yy.h"

%%

;			{ return SEMIC; }

\n			{ return EOL; }

[^ \t]		{ yylval = yytext; return PRARG; }

<<EOF>>		{ return EOL; }

%%
