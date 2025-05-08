%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char *s);
%}

%option noyywrap

%%

// Keywords
"if"              { return IF; }
"else"            { return ELSE; }
"while"           { return WHILE; }
"for"             { return FOR; }
"switch"          { return SWITCH; }
"case"            { return CASE; }
"break"           { return BREAK; }

// Identifiers (variables)
[a-zA-Z_][a-zA-Z0-9_]*  { return IDENTIFIER; }

// Numbers (constants)
[0-9]+            { return NUM; }

// Operators
"+"               { return ADD; }
"-"               { return SUB; }
"*"               { return MUL; }
"/"               { return DIV; }
"="               { return ASSIGN; }
"=="              { return EQ; }

// Parentheses and braces
"("               { return LPAREN; }
")"               { return RPAREN; }
"{"               { return LBRACE; }
"}"               { return RBRACE; }

// Semicolon
";"               { return SEMICOLON; }

// Whitespace (skip)
[ \t\n]+          { /* Ignore whitespace */ }

.                 { return yytext[0]; }  // Catch-all for any other characters

%%

int main() {
    printf("Enter a C control structure (e.g., if (x == 10) { ... }): ");
    yyparse();  // Start parsing
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
