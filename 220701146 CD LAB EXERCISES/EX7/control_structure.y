%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex(void);  // Lexical analyzer function
void yyerror(const char *s);  // Error function
%}

%token IF ELSE WHILE FOR SWITCH CASE BREAK
%token IDENTIFIER NUM
%token ADD SUB MUL DIV ASSIGN EQ
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON

%%

program:
      | program statement
;

statement:
      IF LPAREN expression RPAREN statement  { printf("Valid if statement\n"); }
    | IF LPAREN expression RPAREN statement ELSE statement  { printf("Valid if-else statement\n"); }
    | WHILE LPAREN expression RPAREN statement  { printf("Valid while loop\n"); }
    | FOR LPAREN expression SEMICOLON expression SEMICOLON expression RPAREN statement  { printf("Valid for loop\n"); }
    | SWITCH LPAREN expression RPAREN LBRACE case_statements RBRACE  { printf("Valid switch-case statement\n"); }
    | BREAK SEMICOLON  { printf("Valid break statement\n"); }
    ;

expression:
      IDENTIFIER               { printf("Valid identifier: %s\n", yytext); }
    | NUM                      { printf("Valid number: %s\n", yytext); }
    | IDENTIFIER ASSIGN expression  { printf("Valid assignment\n"); }
    | expression ADD expression
    | expression SUB expression
    | expression MUL expression
    | expression DIV expression
    | LPAREN expression RPAREN
;

case_statements:
      case_statement
    | case_statements case_statement
;

case_statement:
      CASE NUM COLON statement  { printf("Valid case: %s\n", yytext); }
    ;

%%

int main() {
    printf("Enter a C control structure (e.g., if (x == 10) { ... }): ");
    yyparse();  // Start parsing
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
