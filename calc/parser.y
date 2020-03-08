%code requires
{
#include <iostream>
#include <map>
#include "Expression.hpp"
#include "Type.hpp"
#include "SymbolTable.hpp"
#include "Global.hpp"
extern int yylex();
void yyerror(const char*);
}

%union
{
int val;
char* chr;
char* string;
Expression* e;
char* id;
Type* t;
}
 


%token  ARRAY
%token  BEG 
%token  CHR
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

%token  DOT
%token  IDENTIFIER 
%token  CHARACTERCONST
%token  STRINGCONST
%token  OCTAL
%token  HEXADECIMAL
%token  NUMBER


%type <id> IDENTIFIER 
%type <chr> CHARACTERCONST
%type <string> STRINGCONST
%type <val> OCTAL
%type <val> HEXADECIMAL
%type <val> NUMBER
%type <e> Expression 
%type <t> Type SimpleType RecordType ArrayType

%%
Program              : OptConstDecl OptTypeDecl OptVarDecl ProFunkDecl Block DOT { YYACCEPT; }
		     ;
OptConstDecl         : %empty {}
	             | ConstantDecl { }
	             ;
OptTypeDecl          : %empty {}
	             | TypeDecl { }
	             ;
OptVarDecl           : VarDecl { }
	             | %empty {}
	             ;
ProFunkDecl          : %empty {}
	             | ProFunkDecl FuncDecl {}
		     | ProFunkDecl ProcDecl {}
	             ;
ConstantDecl         : CONST IdentExpr DONE {}
	             ;
IdentExpr            : IDENTIFIER EQUAL Expression {SYMBOL_TABLE.Store(std::string($1), $3);}
	             ;
ProcDecl             : PROCEDURE IDENTIFIER OPEN FormalParameters CLOSE Type DONE FORWARD DONE {} 
	             | PROCEDURE IDENTIFIER OPEN FormalParameters CLOSE Type DONE Body DONE {}
	             ;
FuncDecl             : FUNCTION IDENTIFIER OPEN FormalParameters CLOSE Type DONE FORWARD DONE {}
	             | FUNCTION IDENTIFIER OPEN FormalParameters CLOSE Type DONE Body DONE {}
	             ;
FormalParameters     : %empty {}
		     | VAR IdentList DONE Type {}
		     | REF IdentList DONE Type {}
		     | FormalParameters DONE VAR IdentList DONE Type {}
		     | FormalParameters DONE REF IdentList DONE Type {} 
		     ;
Body                 : OptConstDecl OptTypeDecl OptVarDecl Block {}
                     ;
Block                : BEG StatementSequence END {}
                     ;
TypeDecl             : TYPE IDENTIFIER EQUAL Type DONE TypeDeclList {SYMBOL_TABLE.Store(std::string($2),$4);}  
	             ;
TypeDeclList         : %empty {}
	             | IDENTIFIER EQUAL Type DONE TypeDeclList {}
		     ;
Type                 : SimpleType { $$ = $1; } 
                     | RecordType { $$ = nullptr; }
                     | ArrayType  { $$ = nullptr;}
                     ;
SimpleType           : IDENTIFIER {$$ =SYMBOL_TABLE.TypeLookup(std::string($1));}
		     ;
RecordType           : RECORD TypeListOpt END {/*$$ = dynamic_cast<Type *>(new RecordType($2));*/}
		     ;
ArrayType            : ARRAY OPENBRAC Expression SUCHTHAT Expression CLOSEBRAC OF Type {$$ = dynamic_cast<Type *>(new ArrayType($3, $5, $8));} 
		     ;
TypeListOpt          : %empty {}
		     | IdentList SUCHTHAT Type DONE TypeListOpt /*{$$ = new Record($1,$3)}*/ 
		     ;
IdentList            : IDENTIFIER {}
		     | IDENTIFIER COM IdentList {}
		     ;
VarDecl              : VAR IdentList SUCHTHAT Type DONE OptVarDecl {} 
		     ;
StatementSequence    : StatementSequence Statement DONE {}  
		     | Statement DONE {}
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
AssignmentStatement  : LValue ASSIGN Expression {/*Assign($1, $3);*/}
		     ;
IfStatement          : IF Expression THEN StatementSequence ElseIfStatement ElseStatement END {} 
		     ;
ElseIfStatement      : %empty {}
		     | ELSEIF Expression THEN StatementSequence ElseIfStatement {}
		     ;
ElseStatement        : %empty {}
		     | ELSE StatementSequence {}
		     ;
WhileStatement       : WHILE Expression DO StatementSequence END {}
		     ;
RepeatStement        : REPEAT StatementSequence UNTIL Expression {}
		     ;
ForStatement         : FOR IDENTIFIER ASSIGN Expression TO Expression DO StatementSequence END {}
		     | FOR IDENTIFIER ASSIGN Expression DOWNTO Expression DO StatementSequence END {}
		     ;
StopStatement        : STOP {}
		     ;
ReturnStatement      : RETURN OptExpression {}
		     ;
ReadStatement        : READ OPEN ReadStatementInner CLOSE {}
		     ;
ReadStatementInner   : LValue COM LValue {}
		     | LValue {}
		     ;
WriteStatement       : WRITE OPEN WriteInnerStatement CLOSE 
		     ;
WriteInnerStatement  : WriteInnerStatement COM Expression {}
		     | Expression {}
		     ;
ProcedureCall        : IDENTIFIER OPEN CLOSE {}
		     | IDENTIFIER OPEN ProcedureCallInner CLOSE {}
		     ;
ProcedureCallInner   : ProcedureCallInner COM Expression {} 
		     | Expression {}
		     ;
NullStatement        : %empty {} 
		     ;
OptExpression        : Expression 
		     | %empty {}
		     ;
Expression           : Expression OR Expression {$$ = Or($1,$3);} 
		     | Expression AND Expression {$$ = And($1,$3);} 
		     | Expression EQUAL Expression {$$ = equal($1,$3);} 
		     | Expression NEG Expression {$$ = neg($1,$3);} 
		     | Expression LEG Expression {$$ = leg($1,$3);} 
		     | Expression GRTEQ Expression {$$ = grteq($1,$3);} 
		     | Expression LES Expression {$$ = les($1,$3);} 
		     | Expression GRT Expression {$$ = grt($1,$3);} 
		     | Expression ADD Expression {$$ = add($1,$3);} 
		     | Expression SUB Expression {$$ = sub($1,$3);} 
		     | Expression MULT Expression {$$ = mult($1,$3);} 
		     | Expression DIV Expression {$$ = div($1,$3);} 
		     | Expression MOD Expression {$$ = mod($1,$3);} 
		     | TILD Expression {} 
		     | SUB Expression {} 
		     | OPEN Expression CLOSE {}  
		     | IDENTIFIER OPEN CLOSE {} 
		     | IDENTIFIER OPEN ExpressionIdentInner CLOSE {} 
		     | CHR OPEN Expression CLOSE {} 
		     | ORD OPEN Expression CLOSE {} 
		     | PRED OPEN Expression CLOSE {} 
		     | SUCC OPEN Expression CLOSE {} 
		     | LValue {}
		     | STRINGCONST {} 
		     ;
ExpressionIdentInner : ExpressionIdentInner COM Expression {}
		     | Expression {}
		     ;
LValue               : IDENTIFIER {}  
		     | LValue DOT IDENTIFIER {}
		     | LValue IDENTIFIER OPENBRAC Expression CLOSEBRAC {}
		     ;
%%

void yyerror(const char* msg)
{
  std::cerr << msg << std::endl;
}

