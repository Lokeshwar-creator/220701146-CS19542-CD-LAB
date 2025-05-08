%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);  // Forward declaration for the lexer
void yyerror(const char *s);
%}

%option noyywrap

%%

// Valid variable: starts with a letter followed by letters or digits
[a-zA-Z][a-zA-Z0-9]*   { return VAR; }  // Return a token for valid variable

// Whitespace (ignore it)
[ \t\n]+   { /* Ignore whitespace */ }

.         { return yytext[0]; }  // Catch-all for any other characters

%%

int main() {
    printf("Enter a valid variable name (e.g., variable123): ");
    yyparse();  // Start parsing
    return 0;
}

// Error handler for parsing
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
