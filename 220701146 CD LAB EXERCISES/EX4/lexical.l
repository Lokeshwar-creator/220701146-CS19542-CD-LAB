%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);  // Forward declaration for the lexer
void yyerror(const char *s);
%}

%option noyywrap

%%

// Number (Integer) - to be processed by the parser
[0-9]+        { return NUM; }

// Operators
"+"           { return ADD; }
"-"           { return SUB; }
"*"           { return MUL; }
"/"           { return DIV; }

// Parentheses
"("           { return LPAREN; }
")"           { return RPAREN; }

// Whitespace (ignore it)
[ \t\n]+      { /* Ignore whitespace */ }

.             { return yytext[0]; }  // Catch-all for any other characters

%%

int main() {
    printf("Enter a mathematical expression (e.g., 3 + 5 * (2 - 1)): ");
    yyparse();  // Start parsing
    return 0;
}

// Error handler for parsing
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
