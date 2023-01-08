%{
    enum yytokentype {
        PRARG = 258,
        SEMIC = 259,
        EOL = 260
    };

    char* yylval;
%}

%%

;			{ return SEMIC; }

\n			{ return EOL; }

[^ \t\n]+	{ yylval = yytext; return PRARG; }

[ \t\n]+    {}

%%
