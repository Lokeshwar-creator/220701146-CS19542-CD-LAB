%{
#include <stdio.h>
#include <string.h>

int line = 1;
%}

%%

// Keywords
"int"       { printf("Keyword: %s\n", yytext); }
"float"     { printf("Keyword: %s\n", yytext); }
"char"      { printf("Keyword: %s\n", yytext); }
"return"    { printf("Keyword: %s\n", yytext); }
"if"        { printf("Keyword: %s\n", yytext); }
"else"      { printf("Keyword: %s\n", yytext); }
"while"     { printf("Keyword: %s\n", yytext); }
"for"       { printf("Keyword: %s\n", yytext); }

// Identifiers
[a-zA-Z_][a-zA-Z0-9_]*  { printf("Identifier: %s\n", yytext); }

// Constants (integers and floats)
[0-9]+\.[0-9]+          { printf("Float Constant: %s\n", yytext); }
[0-9]+                 { printf("Integer Constant: %s\n", yytext); }

// Operators
"=="|"!="|"<="|">="|"="|"+"|"-"|"*"|"/"|"<"|">" 
                      { printf("Operator: %s\n", yytext); }

// Delimiters
"(" | ")" | "{" | "}" | ";" | "," 
                      { printf("Delimiter: %s\n", yytext); }

// Whitespace and newline
[ \t]+                { /* Skip spaces/tabs */ }
\n                    { line++; }

// Catch-all
.                     { printf("Unknown character: %s\n", yytext); }

%%

int main(int argc, char **argv) {
    printf("Lexical Analysis Output:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
