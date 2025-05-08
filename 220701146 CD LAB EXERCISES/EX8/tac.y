%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex(void);  // Lexical analyzer function
void yyerror(const char *s);  // Error function

int temp_counter = 0;  // To generate unique temporary variables for TAC

// Function to generate temporary variables
char* new_temp() {
    static char temp[10];
    sprintf(temp, "t%d", temp_counter++);
    return temp;
}

%}

%token INT IDENTIFIER NUM ADD SUB MUL DIV ASSIGN LPAREN RPAREN SEMICOLON
%left ADD SUB
%left MUL DIV
%%

program:
    statement_list
;

statement_list:
      statement
    | statement_list statement
;

statement:
      IDENTIFIER ASSIGN expression SEMICOLON { 
          printf("%s = %s\n", $1, $3); 
      }
    ;

expression:
      term                   { $$ = $1; }
    | expression ADD term    { $$ = new_temp(); printf("%s = %s + %s\n", $$, $1, $3); }
    | expression SUB term    { $$ = new_temp(); printf("%s = %s - %s\n", $$, $1, $3); }
    ;

term:
      factor                 { $$ = $1; }
    | term MUL factor        { $$ = new_temp(); printf("%s = %s * %s\n", $$, $1, $3); }
    | term DIV factor        { $$ = new_temp(); printf("%s = %s / %s\n", $$, $1, $3); }
    ;

factor:
      IDENTIFIER             { $$ = $1; }
    | NUM                    { $$ = new_temp(); printf("%s = %d\n", $$, $1); }
    | LPAREN expression RPAREN { $$ = $2; }
    ;

%%

int main() {
    printf("Enter a simple C program (e.g., x = a + b * c): ");
    yyparse();  // Start parsing
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
