%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char *s);
%}

%option noyywrap

%%

// Digits (Integer numbers)
[0-9]+           { yylval = atoi(yytext); return NUM; }

// Operators
"+"              { return ADD; }
"*"              { return MUL; }

// Parentheses
"("              { return LPAREN; }
")"              { return RPAREN; }

// Whitespace (ignore it)
[ \t\n]+         { /* Skip spaces and newlines */ }

.                { return yytext[0]; }  // Catch-all for any other characters

%%

int main() {
    printf("Enter an expression to evaluate (e.g., 3 + 5 * 2): ");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
