%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

int yylex(void);
void yyerror(const char *s);
%}

%option noyywrap

%%

// Keywords
"int"             { return INT; }

// Identifiers (variables)
[a-zA-Z_][a-zA-Z0-9_]*  { return IDENTIFIER; }

// Numbers (constants)
[0-9]+            { yylval = atoi(yytext); return NUM; }

// Operators
"+"               { return ADD; }
"-"               { return SUB; }
"*"               { return MUL; }
"/"               { return DIV; }
"="               { return ASSIGN; }

// Parentheses and semicolons
"("               { return LPAREN; }
")"               { return RPAREN; }
";"               { return SEMICOLON; }

// Whitespace (skip)
[ \t\n]+          { /* Ignore whitespace */ }

.                 { return yytext[0]; }  // Catch-all for any other characters

%%

int main() {
    printf("Enter a simple C program (e.g., x = a + b * c): ");
    yyparse();  // Start parsing
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
