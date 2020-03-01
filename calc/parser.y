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
%token  BEG 
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
%token  OPENBRAC
%token  CLOSEBRAC
%token  ASSIGN

%token  NL
%token  CR

%token Dot

%type <val> INT_LITERAL
%type <string> STRINGCONST
%type <char> CHARACTERCONST
%type <e> Expr
%type <id> IDENTIFIER
%type <val> HEXADECIMAL
%type <val> OCTAL
%type <val> NUMBER
%type <t> TYPE
%%
Program              : OptConstDecl OptTypeDecl OptVarDecl ProFunkDecl Block DOT {}
		     ;
OptConstDecl         : ConstantDecl {/*$$ ?*/ }
	             |
	             ;
OptTypeDecl          : TypeDecl {/*$$ ?*/ }
	             |
	             ;
OptVarDecl           : VarDecl {/*$$ ?*/ }
	             |
	             ;
ProFunkDecl          : ProFunkDec ProcDecl {}
	             | ProFunkDec FuncDecl {}
	             ;
ConstantDecl         : CONST IdentExpr DONE 
	             ;
IdentExpr            : IDENTIFIER EQUAL Expression
	             ;
ProcDecl             : PROCEDURE IDENTIFIER OPEN FormalParameters CLOSE Type DONE FORWARD DONE 
	             | PROCEDURE IDENTIFIER OPEN FormalParameters CLOSE Type DONE Body DONE 
	             ;
FuncDecl             : FUNCTION IDENTIFIER OPEN FormalParameters CLOSE Type DONE FORWARD DONE
	             | FUNCTION IDENTIFIER OPEN FormalParameters CLOSE Type DONE Body DONE
	             ;
FormalParameters     : %empty {}
		     | VAR IdentList DONE type {}
		     | REF IdentList DONE type {}
		     | FormalParameters DONE VAR IdentList DONE type {}
		     | FormalParameters DONE REF IdentList DONE type {}
		     ;
Body                 : OptConstantDecl OptTypeDecl OptVarDecl Block
                     ;
Block                : BEG StatementSequence END
                     ;
TypeDecl             : TYPE IDENTIFIER EQUAL Type DONE TypeDecl 
	             | IDENTIFIER EQUAL Type DONE TypeDecl 
	             |
	             ;
Type                 : SimpleType { $$ = $1; }
                     | RecordType { $$ = $1; }
                     | ArrayType  { $$ = $1; }
                     ;
SimpleType           : IDENTIFIER { $$ = $1 }
		     ;
RecordType           : RECORD IdentList Type DONE RecordType END
		     |
		     ;
ArrayType            : ARRAY OPENBRAC Expression SUCHTHAT Expression CLOSEBRAC OF Type DONE
		     ;
IdentList            : IDENTIFIER COM IdentList
		     | IDENTIFIER {}
		     ;
VarDecl              : VAR IdentList SUCHTHAT Type DONE VarDecl 
		     |
		     ;
StatementSequence    : Statement DONE StatementSequence 
		     |
		     ;
Statement            : AssignmentStatement {}
		     | IfStatement {}
		     | WhileStatement {}
		     | RepeatStement {}
		     | ForStatement {}
		     | StopStatement {}
		     | ReturnStatement {}
		     | ReadStatement {}
		     | WriteStatement {}
		     | ProcedureCall {}
		     | NullStatement {}
		     ;
AssignmentStatement  : Lvalue ASSIGN Expression {}
		     ;
IfStatement          : IF Expression THEN StatementSequence IfStatement END 
		     | ELSEIF Expression THEN StatementSequence IfStatment 
		     | ELSE Expression THEN StatementSequence 
		     | 
		     ;
WhileStatement       : WHILE Expression DO StatementSequence END
		     ;
RepeatStement        : REPEAT StatementSequence UNTIL Expression 
		     ;
ForStatement         : FOR IDENTIFIER ASSIGN Expression TO Expression DO StatementSequence END
		     | FOR IDENTIFIER ASSIGN Expression TO Expression DO StatementSequence END
		     ;
StopStatement        : STOP
		     ;
ReturnStatement      : RETURN Expression 
		     | RETURN
		     ;
ReadStatement        : READ OPEN ReadStatementInner CLOSE 
		     ;
ReadStatementInner   : LValue COM LValue ReadStatementInner 
		     |
		     ;
WriteStatement       : WRITE OPEN WriteInnerStatement CLOSE
		     ;
WriteInnerStatement  : Expression COM Expression WriteInnerStatement
		     |
		     ;
ProcedureCall        : IDENTIFIER OPEN ProcedureCallInner CLOSE
		     ;
ProcedureCallInner   : Expression COM Expression ProcedureCallInner 
		     |
		     ;
NullStatement        : %empty 
		     ;
Expression           : Expression OR Expression 
		     | Expression AND Expression 
		     | Expression EQUAL Expression 
		     | Expression NEG Expression 
		     | Expression LEG Expression 
		     | Expression GRTEQ Expression 
		     | Expression LES Expression 
		     | Expression GRT Expression 
		     | Expression ADD Expression 
		     | Expression SUB Expression
		     | Expression MULT Expression 
		     | Expression DIV Expression 
		     | Expression MOD Expression 
		     | TILD Expression 
		     | SUB Expression 
		     | OPEN Expression CLOSE 
		     | IDENTIFIER OPEN ExpressionIdentInner CLOSE 
		     | CHR OPEN Expression CLOSE 
		     | ORD OPEN Expression CLOSE 
		     | PRED OPEN Expression CLOSE 
		     | SUCC OPEN Expression CLOSE 
		     | LValue
		     ;
ExpressionIdentInner : Expression COM Expression ExpressionIdentInner 
		     |
		     ;
LValue               : IDENTIFIER DOT IDENTIFIER LValue  
		     | IDENTIFIER OPENBRAC Expression CLOSEBRAC LValue 
		     |
		     ;


%%

void yyerror(const char* msg)
{
  std::cerr << msg << std::endl;
}

