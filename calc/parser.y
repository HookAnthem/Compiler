%{
#include <iostream>
#include <map>

#include "symbol_table.hpp"

extern int yylex();
void yyerror(const char*);
%}

%union
{
int val;
Expr* e;
char* id;
Type* t;
}

%token  ARRAY
%token  BEGIN
%token  CHAR
%token  CONST
%token  DO
%token  DOWNTO
%token  ELSE
%token  ELSEIF
%token  END
%token  FOR
%token  FORWARD
%token  FUNCTION
%token  IF
%token  OF
%token  ORD
%token  PRED
%token  PROCEDURE
%token  READ
%token  RECORD
%token  REF
%token  REPEAT
%token  RETURN
%token  STOP
%token  SUCC
%token  THEN
%token  TO
%token  TYPE
%token  UNTIL
%token  VAR
%token  WHILE
%token  WRITE

%token  SUB
%token  MULT
%token  DIV
%token  MOD
%token  ADD

%token  EQUAL
%token  NEG
%token  LES
%token  LEG
%token  GRT
%token  GRTEQ

%token  TILD
%token  AND
%token  OR
%token  NOT
%token  AND
%token  MEMA
%token  COM
%token  SUCHTHAT
%token  OPEN
%token  CLOSE
%token  DONE
%token  OPEN
%token  CLOSE
%token  EQUAL

%token  NL
%token  CR


%type <val> INT_LITERAL
%type <e> Expr
%type <id> ID_TOKEN
%type <t> TYPE

%%

StatementList : StatementList Statement{}
              | {};
Statement : Expression DONE {std::cout << $1 << std::endl;}
          | LET ID EQUAL Expression DONE{symbol_table.store($2,$4);delete($2);}
          | DONE{};
Expression : Expression ADD Term {$$ = $1 + $3;}
           | Expression SUB Term {$$ = $1 - $3;}
           | Term {$$ = $1;};

Term : Term MULT Factor { $$ = $1 * $3;}
     | Term Factor { $$ = $1 * $2;}
     | Term DIV Factor { $$ = $1 / $3;}
     | Factor {$$ = $1;}
     ;
Factor : OPEN Expression CLOSE {$$ = $2;}
       | NUMBER {$$ = $1;}
       | ID {$$ = symbol_table.lookup($1);delete($1);}
       ;

%%

void yyerror(const char* msg)
{
  std::cerr << msg << std::endl;
}

