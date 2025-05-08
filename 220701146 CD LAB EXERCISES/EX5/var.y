%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex(void);  // Lexical analyzer function
void yyerror(const char *s);  // Error function
%}

%token VAR  // Token representing a valid variable

%%

input:
      | input line
;

line:
      VAR        { printf("Valid variable: %s\n", yytext); }
    ;

%%

int main() {
    printf("Enter a valid variable name (e.g., variable123): ");
    yyparse();  // Start parsing
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
