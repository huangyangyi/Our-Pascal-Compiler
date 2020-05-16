%option noyywrap yylineno caseless
%{
#include <cstring>
#include "pascal.y.h"
using namespace std;

#define YY_USER_ACTION yylloc->begin.line = yylloc->end.line = yylineno-1; \
    yylloc->begin.column = yycolumn; yylloc->end.column = yycolumn+yyleng-1; \
    yycolumn += yyleng;
%}

/* TODO: Pascal reserved keywords, reference P13 1.3.1*/
KWD_ABSOLUTE absolute
KWD_AND and 
KWD_ARRAY array 
KWD_ASM asm 
KWD_BEGIN begin 
KWD_CASE case

/* TODO: Some of the Pascal base types here: P24 3.1*/
TYPE_INT_32 int
TYPE_INT_64 longint

TYPE_FLOAT_32 float
/* Values here*/
SIGN "+"|"-"
VALUE_INT [0-9]+
VALUE_FLOAT ([0-9]+\.[0-9]+)|([0-9]+\.[0-9]+e{SIGN}?[0-9]+)|([0-9]+e{SIGN}?[0-9]+)
VALUE_CHAR \'.\'
VALUE_ESC_CHAR '\'#\'
VALUE_STR \'([^']|{VALUE_ESC_CHAR})*\'

/* TODO: Pascal symbols here: */
SYM_ADD "+"

/* TODO: Other tokens */
COMMENT "{"[^\}]*"}"
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
%%

KWD_ABSOLUTE {
    return KWD_ABSOLUTE;
}

KWD_AND {
    return KWD_AND;
}

KWD_ARRAY {
    return KWD_ARRAY;
}

IDENTIFIER {
    if (yyleng >= MAX_STR_LEN) {
        fprintf(stderr, "Identifier too long\n");
        yyerror(yytext);
    }
    else {
        strcpy_s(yylval.str, yytext, yyleng);
        yylval.str[yyleng] = '\0';
    }
    return IDENTIFIER;
}

{COMMENT} {}

\n|(\r\n) {
    yycolumn = 1;
}
" "|\t {}

. {
    printf("unknown character %d\n", (int) yytext[0]);
    return yytext[0];
}
%%

void yyerror(const char *s) {
    fprintf(stderr, "LexError: %s (at Line %d, Column%d)\n", s, yylloc->begin.line, yylloc->end.line);
}