%{
#include <iostream>
#include <fstream>
#include "Global.hpp"
#include "MiddleAsembler.hpp"
extern char * yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char*);
MiddleAsembler MA;
%}

%union
{
int val;
char chr;
char* str;
}

%error-verbose
%token ARRAY 
%token ASSIGN 
%token BEG 
%token CHARACTERCONST 
%token CHR 
%token SUCHTHAT 
%token COM 
%token CONST 
%token DIV 
%token DO 
%token DOT 
%token DOWNTO 
%token ELSEIF 
%token ELSE 
%token END 
%token EQUAL 
%token FOR 
%token FORWARD 
%token FUNCTION 
%token GRTEQ 
%token GRT 
%token IDENTIFIER
%token IF 
%token NUMBER 
%token OPENBRAC 
%token OPEN 
%token LEG 
%token LES 
%token SUB 
%token MOD 
%token MULT
%token NOT 
%token OF
%token ORD 
%token ADD 
%token PRED 
%token PROCEDURE 
%token CLOSEBRAC
%token READ 
%token RECORD 
%token REF 
%token REPEAT 
%token RETURN 
%token CLOSE 
%token DONE 
%token STOP 
%token STRINGCONST 
%token SUCC
%token THEN 
%token TO 
%token TYPE 
%token UNTIL 
%token VAR 
%token WHILE 
%token WRITE

%left AND OR
%right NOT
%nonassoc EQUAL LEG GRTEQ GRT LES NEG 
%left ADD SUB 
%left DIV MOD MULT
%right MIN 

%type <chr> CHARACTERCONST
%type <val> Arguments 
%type <val> ArrayType 
%type <val> Assignment
%type <val> Block 
%type <val> Body  
%type <val> ElseClause 
%type <val> ElseIfHead 
%type <val> ElseIfList 
%type <val> Expression 
%type <val> FSignature 
%type <val> FieldDecl 
%type <val> FieldDecls
%type <val> ForHead 
%type <val> ForStatement 
%type <val> FormalParameter
%type <val> FormalParameters  
%type <val> FunctionCall 
%type <val> NUMBER 
%type <val> IdentList 
%type <val> OptVar 
%type <val> IfHead 
%type <val> IfStatement 
%type <val> LValue 
%type <val> OptArguments 
%type <val> OptFormalParameters  
%type <val> PSignature 
%type <val> ProcedureCall
%type <val> ReadArgs
%type <val> ReadStatement 
%type <val> RecordType 
%type <val> RepeatStatement
%type <val> RepeatSymbol 
%type <val> ReturnStatement 
%type <val> SimpleType 
%type <val> Statement 
%type <val> StatementList 
%type <val> StopStatement 
%type <val> ThenPart 
%type <val> ToHead 
%type <val> Type 
%type <val> WhileHead 
%type <val> WhileStatement 
%type <val> WhileSymbol
%type <val> WriteArgs 
%type <val> WriteStatement  
%type <str> IDENTIFIER 
%type <str> STRINGCONST 

%%
Program : ProgramHead Block DOT {}
				;

ProgramHead : OptConstDecls OptTypeDecls OptVarDecls PFDecls
            ;
OptConstDecls : CONST ConstDecls
	      |
	      ;

ConstDecls : ConstDecls ConstDecl
	   | ConstDecl
           ;

ConstDecl : IDENTIFIER EQUAL Expression DONE {MA.storeConst($1,$3);}
	  ;

PFDecls : PFDecls2 {}
        ;

PFDecls2 : PFDecls2 ProcedureDecl
        | PFDecls2 FunctionDecl
        |
        ;

ProcedureDecl : PSignature DONE FORWARD DONE {}
              | PSignature DONE Body DONE {MA.doProcedureEpilogue();}
	      ;

PSignature : ProcedureTop OPEN OptFormalParameters CLOSE {}
           ;

ProcedureTop : PROCEDURE IDENTIFIER {MA.doProcedurePrologue($2);}
             ;

FunctionDecl : FSignature DONE FORWARD DONE {}
	     | FSignature DONE Body DONE {}
             ;

FSignature : FunctionTop OPEN OptFormalParameters CLOSE SUCHTHAT Type {}
           ;

FunctionTop : FUNCTION IDENTIFIER {ignoreFunction(); }

OptFormalParameters : FormalParameters {}
                    | {}
                    ;

FormalParameters : FormalParameters DONE FormalParameter {}
                 | FormalParameter {}
                 ;

FormalParameter : OptVar IdentList SUCHTHAT Type {MA.makeParameters($2,$4);}
                ;

OptVar : VAR {}
       | REF {}
       | {}
       ;


Body : OptConstDecls OptTypeDecls OptVarDecls Block {}
     ;

Block : BEG StatementList END {}
      ;

StatementList : StatementList DONE Statement {}
              | Statement {}
              ;

OptTypeDecls : TYPE TypeDecls
             |
             ;

TypeDecls    : TypeDecls TypeDecl
             | TypeDecl
             ;

TypeDecl : IDENTIFIER EQUAL Type DONE {SYMBOL_TABLE.storeType($1, $3);}
         ;

Type : SimpleType {}
     | RecordType {}
     | ArrayType {}
     ;

SimpleType : IDENTIFIER {$$ = SYMBOL_TABLE.lookupType($1);}
           ;

RecordType : RECORD FieldDecls END {$$ = $2;}
           ;

FieldDecls : FieldDecls FieldDecl {$$ = MA.mergeRecords($1,$2);}
           | FieldDecl {}
           ;

FieldDecl : IdentList SUCHTHAT Type DONE {$$ = MA.makeRecordVars($1,$3);}
          ;

IdentList : IdentList COM IDENTIFIER {$$ = MA.appendStrList($1,$3);}
          | IDENTIFIER {$$ = MA.makeStrList($1);}
          ;

ArrayType : ARRAY OPENBRAC Expression SUCHTHAT Expression CLOSEBRAC OF Type {$$ = MA.buildArray($3,$5,$8);}
          ;

OptVarDecls : VAR VarDecls
            |
            ;

VarDecls    : VarDecls VarDecl
            | VarDecl
            ;

VarDecl : IdentList SUCHTHAT Type DONE {MA.makeVars($1,$3);}
        ;

Statement : Assignment {}
          | IfStatement {MA.endIf();}
          | WhileStatement {MA.endWhile($1);}
          | RepeatStatement {}
          | ForStatement {MA.endFor($1);}
          | StopStatement {}
          | ReturnStatement {}
          | ReadStatement {}
          | WriteStatement {}
          | ProcedureCall {}
          | {}
          ;

Assignment : LValue ASSIGN Expression {MA.assignExprToLval($1, $3);}
           ;

IfStatement : IfStuff ElseIfList ElseClause END {}
            ;

IfStuff : IfHead ThenPart {MA.doElse($1);}
        ;

IfHead : IF Expression {$$ = MA.startIf($2,false);}
       ;

ThenPart : THEN StatementList {}
         ;

ElseIfList : ElseIfList ElseIfHead ThenPart {MA.doElse($2);}
           | {}
           ;

ElseIfHead : ELSEIF Expression {$$ = MA.startIf($2,true);}
           ;

ElseClause : ELSE StatementList {}
           | {}
           ;

WhileStatement : WhileHead DO StatementList END {}
               ;

WhileHead : WhileSymbol Expression {MA.startWhile($1,$2);}
          ;

WhileSymbol : WHILE {$$ = MA.preWhile();}

RepeatStatement : RepeatSymbol StatementList UNTIL Expression {MA.endRepeat($1,$4);}
                ;

RepeatSymbol : REPEAT {$$ = MA.startRepeat();}
             ;

ForStatement : ToHead DO StatementList END{$$ = $1;}
             ;

ToHead : ForHead TO Expression {$$ = MA.compareFor($1,$3,true);}
       | ForHead DOWNTO Expression {$$ = MA.compareFor($1,$3,false);}
       ;

ForHead : FOR IDENTIFIER ASSIGN Expression {$$ = MA.startFor($2,$4);}
        ;


StopStatement : STOP {stop();}
              ;

ReturnStatement : RETURN Expression {}
                | RETURN {}
                ;


ReadStatement : READ OPEN ReadArgs CLOSE {MA.clearExpressions();}
              ;

ReadArgs : ReadArgs COM LValue {MA.readToLval($3);}
         | LValue                  {MA.readToLval($1);}
         ;

WriteStatement : WRITE OPEN WriteArgs CLOSE {}
               ;

WriteArgs : WriteArgs COM Expression {MA.unOp($3,&MiddleAsembler::writeExpression);}
          | Expression                   {MA.unOp($1,&MiddleAsembler::writeExpression);}
          ;

ProcedureCall : IDENTIFIER OPEN OptArguments CLOSE {MA.precallProcedure($1);}
              ;
OptArguments : Arguments {}
             |           {}
             ;
Arguments : Arguments COM Expression {MA.addArgument($3);}
          | Expression                   {MA.addArgument($1);}
          ;

Expression : CHARACTERCONST                         {$$ = MA.charLiteral(yylval.chr);}
           | CHR OPEN Expression CLOSE  {$$ = MA.charCast($3);}
           | Expression AND Expression         {$$ = MA.binOp($1,$3,&MiddleAsembler::binOpAnd);}
           | Expression DIV Expression         {$$ = MA.binOp($1,$3,&MiddleAsembler::binOpDiv);}
           | Expression EQUAL Expression          {$$ = MA.binOp($1,$3,&MiddleAsembler::binOpEq);}
           | Expression GRTEQ Expression         {$$ = MA.binOp($1,$3,&MiddleAsembler::binOpGteq);}
           | Expression GRT Expression          {$$ = MA.binOp($1,$3,&MiddleAsembler::binOpGt);}
           | Expression LEG Expression         {$$ = MA.binOp($1,$3,&MiddleAsembler::binOpLteq);}
           | Expression LES Expression          {$$ = MA.binOp($1,$3,&MiddleAsembler::binOpLt);}
           | Expression SUB Expression       {$$ = MA.binOp($1,$3,&MiddleAsembler::binOpSub);}
           | Expression MOD Expression         {$$ = MA.binOp($1,$3,&MiddleAsembler::binOpMod);}
           | Expression MULT Expression        {$$ = MA.binOp($1,$3,&MiddleAsembler::binOpMult);}
           | Expression NEG Expression         {$$ = MA.binOp($1,$3,&MiddleAsembler::binOpNeq);}
           | Expression OR Expression          {$$ = MA.binOp($1,$3,&MiddleAsembler::binOpOr);}
           | Expression ADD Expression        {$$ = MA.binOp($1,$3,&MiddleAsembler::binOpAdd);}
           | FunctionCall                        {ignoreFunction();}
           | NUMBER                               {$$ = MA.intLiteral($1);}
           | OPEN Expression CLOSE        {$$ = $2;}
           | LValue                              {}
           | SUB Expression %prec MIN   {$$ = MA.unOp($2,&MiddleAsembler::unOpNeg);}
           | NOT Expression                    {$$ = MA.unOp($2,&MiddleAsembler::unOpNot);}
           | ORD OPEN Expression CLOSE  {$$ = MA.intCast($3);}
           | PRED OPEN Expression CLOSE {$$ = MA.unOp($3,&MiddleAsembler::unOpDecr);}
           | STRINGCONST                            {$$ = MA.stringLiteral($1);}
           | SUCC OPEN Expression CLOSE {$$ = MA.unOp($3,&MiddleAsembler::unOpIncr);}
           ;

FunctionCall : IDENTIFIER OPEN OptArguments CLOSE {ignoreFunction();}
             ;

LValue : LValue DOT IDENTIFIER {$$ = MA.getLvalRec($1,$3);}
       | LValue OPENBRAC Expression CLOSEBRAC {$$ = MA.getLvalArr($1,$3);}
       | IDENTIFIER {$$ = MA.getLval($1);}
       ;
%%

void yyerror(const char* s)
{
  std::cerr << s << " at line " << yylineno;
  std::cerr << " near \"" << yytext << "\"" << std::endl;
  throw /*control back to main*/;
}
