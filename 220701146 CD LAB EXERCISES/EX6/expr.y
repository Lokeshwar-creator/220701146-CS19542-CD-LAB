%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex(void);  // Lexical analyzer function
void yyerror(const char *s);  // Error function

int result;  // Variable to store the result of the evaluation

%}

%token NUM
%token ADD MUL LPAREN RPAREN

%%

expr:
      expr ADD term   { result = $1 + $3; }
    | term            { result = $1; }
    ;

term:
      term MUL factor { result = $1 * $3; }
    | factor          { result = $1; }
    ;

factor:
      NUM             { result = $1; }
    | LPAREN expr RPAREN { result = $2; }
    ;

%%

int main() {
    printf("Enter an expression to evaluate (e.g., 3 + 5 * 2): ");
    yyparse();  // Start parsing
    printf("Result: %d\n", result);  // Output the result
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
