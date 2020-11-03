%option noyywrap
%option nounput

%{
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "Global.hpp"
#include "parser.hpp"

%}

%%


[$] { }
ARRAY|array         {if (printDebug){std::cout << "array Token" << std::endl;}return ARRAY;}
BEGIN|begin         {if (printDebug){std::cout << "begin token" << std::endl;} return BEG;}
CHR|chr             {if (printDebug){std::cout << "Chr Token" << std::endl;}return CHR;}
CONST|const         {if (printDebug){std::cout << "const Token" << std::endl;}return CONST;}
DO|do               {if (printDebug){std::cout << "Do token" << std::endl;}return DO;}
DOWNTO|downto       {if (printDebug){std::cout << "DownTo Token" << std::endl;}return DOWNTO;}
ELSE|else           {if (printDebug){std::cout << "Else Token" << std::endl;}return ELSE;}
ELSEIF|elseif       {if (printDebug){std::cout << "ElseIf Token" << std::endl;}return ELSEIF;}
END|end             {if (printDebug){std::cout << "End Token" << std::endl;}return END;}
FOR|for             {if (printDebug){std::cout << "For Token" << std::endl;}return FOR;}
FORWARD|forward     {if (printDebug){std::cout << "Forward Token" << std::endl;}return FORWARD;}
FUNCTION|function   {if (printDebug){std::cout << "Function Token" << std::endl;}return FUNCTION;}
IF|if               {if (printDebug){std::cout << "if Token" << std::endl;}return IF;}
OF|of               {if (printDebug){std::cout << "of Token" << std::endl;}return OF;}
ORD|ord             {if (printDebug){std::cout << "ord Token" << std::endl;}return ORD;}
PRED|pred           {if (printDebug){std::cout << "pred token" << std::endl;}return PRED;}
PROCEDURE|procedure {if (printDebug){std::cout << "procedure token" << std::endl;}return PROCEDURE;}
READ|read           {if (printDebug){std::cout << "read token" << std::endl;}return READ;}
RECORD|record       {if (printDebug){std::cout << "record token" << std::endl;}return RECORD;}
REF|ref             {if (printDebug){std::cout << "ref token" << std::endl;}return REF;}
REPEAT|repeat       {if (printDebug){std::cout << "repeat token" << std::endl;}return REPEAT;}
RETURN|return       {if (printDebug){std::cout << "return token" << std::endl;}return RETURN;}
STOP|stop           {if (printDebug){std::cout << "stop token" << std::endl;}return STOP;}
SUCC|succ           {if (printDebug){std::cout << "succ token" << std::endl;}return SUCC;}
THEN|then           {if (printDebug){std::cout << "Then Token" << std::endl;}return THEN;}
TO|to               {if (printDebug){std::cout << "To token" << std::endl;}return TO;}
TYPE|type           {if (printDebug){std::cout << "Type Token" << std::endl;}return TYPE;}
UNTIL|until         {if (printDebug){std::cout << "Until Token" << std::endl;}return UNTIL;}
VAR|var             {if (printDebug){std::cout << "var token" << std::endl;}return VAR;}
WHILE|while         {if (printDebug){std::cout << "while Token" << std::endl;}return WHILE;}
WRITE|write         {if (printDebug){std::cout << "write token" << std::endl;} return WRITE;}



"-"  {if (printDebug){std::cout << "- Token" << std::endl;}return SUB;}
"*"  {if (printDebug){std::cout << "* token" << std::endl;}return MULT;}
"/"  {if (printDebug){std::cout << "/ Token" << std::endl;}return DIV;}
"%"  {if (printDebug){std::cout << "% token" << std::endl;}return MOD;}
"+"  {if (printDebug){std::cout << "+ token" << std::endl;}return ADD;}

"="  {if (printDebug){std::cout << "= token" << std::endl;}return EQUAL;}
"<>" {if (printDebug){std::cout << "<> token" << std::endl;}return NEG;}
"<"  {if (printDebug){std::cout << "< token" << std::endl;}return LES;}
"<=" {if (printDebug){std::cout << "<= token" << std::endl;}return LEG;}
">"  {if (printDebug){std::cout << "> token" << std::endl;}return GRT;}
">=" {if (printDebug){std::cout << ">= token" << std::endl;}return GRTEQ;}

"|"  {if (printDebug){std::cout << "| token" << std::endl;}return OR;}
"~"  {if (printDebug){std::cout << "~ token" << std::endl;}return NOT;}
"&"  {if (printDebug){std::cout << "& token" << std::endl;}return AND;}
","  {if (printDebug){std::cout << ", token" << std::endl;}return COM;}
":"  {if (printDebug){std::cout << ": token" << std::endl;}return SUCHTHAT;}
"("  {if (printDebug){std::cout << "( token" << std::endl;}return OPEN;}
")"  {if (printDebug){std::cout << ") token" << std::endl;}return CLOSE;}
";"  {if (printDebug){std::cout << "; token" << std::endl;}return DONE;}
"["  {if (printDebug){std::cout << "[ token" << std::endl;}return OPENBRAC;}
"]"  {if (printDebug){std::cout << "] token" << std::endl;}return CLOSEBRAC;}
":=" {if (printDebug){std::cout << ":= token" << std::endl;}return ASSIGN;}
"."  {if (printDebug){std::cout << ". token" << std::endl;}return DOT;}

[a-zA-Z][a-zA-Z0-9_]* {yylval.str = strdup(yytext); if(printDebug){std::cout << "Identifier" << yylval.str << std::endl;} return IDENTIFIER;}


[0][0-7]+          {yylval.val = strtol(yytext,nullptr,0);return NUMBER;}
[0][x][0-9a-fA-F]+ {yylval.val = strtol(yytext,nullptr,0);return NUMBER;}
[0-9]+[0-9]*       {yylval.val = strtol(yytext,nullptr,0);return NUMBER;}


'\\b' {yylval.chr = '\b';if(printDebug){std::cout << "Character Constant " << yylval.chr << std::endl;}return CHARACTERCONST;}
'\\t' {yylval.chr = '\t';if(printDebug){std::cout << "Character Constant " << yylval.chr << std::endl;}return CHARACTERCONST;}
'\\n' {yylval.chr = '\n';if(printDebug){std::cout << "Character Constant new Line " << yylval.chr << std::endl;}return CHARACTERCONST;}
'\\r' {yylval.chr = '\r';if(printDebug){std::cout << "Character Constant " << yylval.chr << std::endl;}return CHARACTERCONST;}
'\\?.' {yylval.chr = yytext[1]; if(printDebug){std::cout << "Character Constant " << yylval.chr << std::endl;}return CHARACTERCONST;}

\"([a-zA-z0-9_!@#$%^&*()=+\-*:, / <> \t\n]|(\\\"))*\" {yylval.str = strdup(yytext);if(printDebug){std::cout << "String Value " << yylval.str << std::endl;} return STRINGCONST;}
\n {}
. { /*std::cout << "Bitter Complaints" << yytext << std::endl; return 0;*/ }
%%
