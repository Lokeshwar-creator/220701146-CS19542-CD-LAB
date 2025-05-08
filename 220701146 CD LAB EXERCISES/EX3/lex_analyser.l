%{
#include <stdio.h>
#include <string.h>

int line = 1;
%}

%option noyywrap

%%

// ----------------------------
// Keywords
// ----------------------------
"int"|"float"|"char"|"if"|"else"|"for"|"while"|"return" {
    printf("Keyword: %s\n", yytext);
}

// ----------------------------
// Identifiers
// ----------------------------
[a-zA-Z_][a-zA-Z0-9_]* {
    printf("Identifier: %s\n", yytext);
}

// ----------------------------
// Constants
// ----------------------------
[0-9]+\.[0-9]+    { printf("Float Constant: %s\n", yytext); }
[0-9]+            { printf("Integer Constant: %s\n", yytext); }

// ----------------------------
// Operators
// ----------------------------
"=="|"!="|"<="|">="|"="|"+"|"-"|"*"|"/"|"<"|">" {
    printf("Operator: %s\n", yytext);
}

// ----------------------------
// Delimiters
// ----------------------------
"(" | ")" | "{" | "}" | ";" | "," {
    printf("Delimiter: %s\n", yytext);
}

// ----------------------------
// Comments
// ----------------------------
// Single-line comments
"//".* {
    printf("Single-line Comment: %s\n", yytext);
}

// Multi-line comments
"/*"([^*]|\*+[^*/])*\*+"/" {
    printf("Multi-line Comment: %s\n", yytext);
}

// ----------------------------
// Whitespace and Newlines
// ----------------------------
[ \t]+    ;           // Skip spaces and tabs
\n        { line++; } // Count lines

// ----------------------------
// Unknown Characters
// ----------------------------
.         { printf("Unknown character: %s\n", yytext); }

%%

int main() {
    printf("Lexical Analysis Output:\n");
    yylex();
    return 0;
}
