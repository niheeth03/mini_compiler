%{
    #include <stdio.h>
    #include<stdlib.h>
    #include "y.tab.h"
%}

alpha [A-Za-z]
digit [0-9]
point "."
comp    "=="|"<"|">"|"<="|">="|"<>"|"!="

%%
"{" return LBracket;
"}" return RBracket;

{digit}+{point}{digit}{digit}+ { strcpy(yylval.addr ,yytext); return DoubleNUM; };
{digit}+{point}{digit}{digit}+ { strcpy(yylval.addr ,yytext); return FloatNUM; };
{digit}+ { strcpy(yylval.addr ,yytext); return NUM; };


"int" return INT;
"char" return CHAR;
"long" return LONG;
"float" return FLOAT;
"double" return DOUBLE;
"string" return STRING;
"||" return or;
"&&" return and;
{comp}      {strcpy(yylval.addr, yytext);  return COMP;}
"++"     return INC;
"--"     return DEC;
"if" return IF;
"else" return ELSE;
"while" return While;
{alpha}({alpha}|{digit})* { strcpy(yylval.addr ,yytext); return ID; };

[ \t\n] ;

"$" return 0;

. return yytext[0];

%%
