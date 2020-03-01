%{
#include <cstdlib>

#include "parser.hpp"
%}

%option noyywrap
%%
[$] {}
"ARRAY | array"         {return ARRAY;}
"BEGIN| begin"          {return BEG;}
"CHR | chr"             {return CHAR;}
"CONST | const"         {return CONST;}
"DO | do"               {return DO;}
"DOWNTO | downto"       {return DOWNTO;}
"ELSE | else"           {return ELSE;}
"ELSEIF | elseif"       {return ELSEIF;}
"END | end"             {return END;}
"FOR | for"             {return FOR;}
"FORWARD | forward"     {return FORWARD;}
"FUNCTION | function"   {return FUNCTION;}
"IF | if"               {return IF;}
"OF | of"               {return OF;}
"ORD | ord"             {return ORD;}
"PRED | pred"           {return PRED;}
"PROCEDURE | procedure" {return PROCEDURE;}
"READ | read"           {return READ;}
"RECORD | record"       {return RECORD;}
"REF | ref"             {return REF;}
"REPEAT | repeat"       {return REPEAT;}
"RETURN | return"       {return RETURN;}
"STOP |stop"            {return STOP;}
"SUCC | succ"           {return SUCC;}
"THEN | then"           {return THEN;}
"TO | to"               {return TO;}
"TYPE | type"           {return TYPE;}
"UNTIL | until"         {return UNTIL;}
"VAR | var"             {return VAR;}
"WHILE | while"         {return WHILE;}
"WRITE | write"         {return WRITE;}



"-" {return SUB;}
"*" {return MULT;}
"/" {return DIV;}
"%" {return MOD;}
"+" {return ADD;}

"=" {return EQUAL;}
"<>" {return NEG;}
"<"  {return LES;}
"<=" {return LEG;}
">" {return GRT;}
">=" {return GRTEQ;}

"˜" {return TILD;}
"&" {return AND;}
"|" {return OR;}
"~" {return NOT;}
"&" {return AND;}
"." {return MEMA;}
"," {return COM;}
":" {return SUCHTHAT;}
"(" {return OPEN;}
")" {return CLOSE;}
";" {return DONE;}
"[" {return OPENBRAC;}
"]" {return CLOSEBRAC;}
":=" {return ASSIGN;}

"\n" {return NL;}
"\r" {return CR;}
"." {return DOT;}

([a-z]|[A-Z]([a-z]|[A-Z]|_|[0=9])* {yylval.id = strdup(yytext);return IDENTIFIER;}
'([a-z]|[A-Z])' {yylval.id = strdup(yytext);return CHARACTERCONST;}
\"[a-z]|[A-Z]|[0-9]|_ \t\n]|(\\")*\" {yylval.id = strdup(yytext);return STRINGCONST;}


0([0-9])* {yylval.val = atof(yytext); return OCTAL;}
0x([0-9])* {yylval.val = atof(yytext); return HEXADECIMAL;}
[0-9]*\.[0-9]* {yylval.val = atof(yytext);return NUMBER;}


* return ERROR;
