%option noyywrap
%option nounput

%{
#include <cstdlib>
#include <iostream>
#include "Expression.hpp"
#include "Type.hpp"
#include "parser.hpp"
#include "Global.hpp"
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

"˜"  if (printDebug){std::cout << "˜ token" << std::endl;}{return TILD;}
"|"  {if (printDebug){std::cout << "| token" << std::endl;}return OR;}
"~"  {if (printDebug){std::cout << "~ token" << std::endl;}return NOT;}
"&"  {if (printDebug){std::cout << "& token" << std::endl;}return AND;}
","  {if (printDebug){std::cout << ", token" << std::endl;}return COM;}
":"  {if (printDebug){std::cout << ": token" << std::endl;}return SUCHTHAT;}
"("  {if (printDebug){std::cout << "( token" << std::endl;}/*std::cout << "open paren" << std::endl;*/ return OPEN;}
")"  {if (printDebug){std::cout << ") token" << std::endl;}/*std::cout << "close Paren" << std::endl;*/ return CLOSE;}
";"  {if (printDebug){std::cout << "; token" << std::endl;}return DONE;}
"["  {if (printDebug){std::cout << "[ token" << std::endl;}return OPENBRAC;}
"]"  {if (printDebug){std::cout << "] token" << std::endl;}return CLOSEBRAC;}
":=" {if (printDebug){std::cout << ":= token" << std::endl;}return ASSIGN;}
"."  {if (printDebug){std::cout << ". token" << std::endl;}return DOT;}

[a-zA-Z][a-zA-Z0-9_]* {yylval.id = strdup(yytext); if(printDebug){std::cout << "Identifier" << yylval.id << std::endl;} return IDENTIFIER;}
'([a-z]|[A-Z])' {yylval.chr = strdup(yytext); if(printDebug){std::cout << "Character Constant " << yylval.chr << std::endl;}return CHARACTERCONST;}


\"([a-zA-z0-9_!@#$%^&*() \t\n]|(\\\"))*\" {yylval.string = strdup(yytext);if(printDebug){std::cout << "String Value " << yylval.string << std::endl;} return STRINGCONST;}
0([0-9])* {yylval.val = atoi(yytext); if(printDebug){std::cout << "Octal " << yylval.val << std::endl;}return OCTAL;}
0x([0-9])* {yylval.val = atoi(yytext); if(printDebug){std::cout << "HEXADECIMAL " << yylval.val << std::endl;}return HEXADECIMAL;}
[0-9]*\.[0-9]* {yylval.val = atoi(yytext); if(printDebug){std::cout << "Number " << yylval.val << std::endl;}return NUMBER;}

'\\b' {}
'\\t' {}
'\\n' {}
'\\r' {}

\n {}
. { /*std::cout << "Bitter Complaints" << yytext << std::endl; return 0;*/ }
%%
