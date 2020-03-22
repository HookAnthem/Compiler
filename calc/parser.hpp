/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_HOME_HOOKSHARE_ZACH_HOMEWORK_COMPILER_CALC_PARSER_HPP_INCLUDED
# define YY_YY_HOME_HOOKSHARE_ZACH_HOMEWORK_COMPILER_CALC_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 2 "parser.y" /* yacc.c:1909  */

#include <iostream>
#include <map>
#include "Expression.hpp"
#include "Type.hpp"
#include "SymbolTable.hpp"
#include "Writing.hpp"
#include "Global.hpp"
extern int yylex();
void yyerror(const char*);

#line 56 "/home/HookShare/Zach/homework/compiler/calc/parser.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ARRAY = 258,
    BEG = 259,
    CHR = 260,
    CONST = 261,
    DO = 262,
    DOWNTO = 263,
    ELSE = 264,
    ELSEIF = 265,
    END = 266,
    FOR = 267,
    FORWARD = 268,
    FUNCTION = 269,
    IF = 270,
    OF = 271,
    ORD = 272,
    PRED = 273,
    PROCEDURE = 274,
    READ = 275,
    RECORD = 276,
    REF = 277,
    REPEAT = 278,
    RETURN = 279,
    STOP = 280,
    SUCC = 281,
    THEN = 282,
    TO = 283,
    TYPE = 284,
    UNTIL = 285,
    VAR = 286,
    WHILE = 287,
    WRITE = 288,
    SUB = 289,
    MULT = 290,
    DIV = 291,
    MOD = 292,
    ADD = 293,
    EQUAL = 294,
    NEG = 295,
    LES = 296,
    LEG = 297,
    GRT = 298,
    GRTEQ = 299,
    TILD = 300,
    AND = 301,
    OR = 302,
    NOT = 303,
    COM = 304,
    SUCHTHAT = 305,
    OPEN = 306,
    CLOSE = 307,
    DONE = 308,
    OPENBRAC = 309,
    CLOSEBRAC = 310,
    ASSIGN = 311,
    DOT = 312,
    IDENTIFIER = 313,
    CHARACTERCONST = 314,
    STRINGCONST = 315,
    OCTAL = 316,
    HEXADECIMAL = 317,
    NUMBER = 318
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "parser.y" /* yacc.c:1909  */

int val;
char* chr;
char* string;
char char_spec;
Expression* e;
char* id;
Type* t;
std::vector<std::string>* typeList;

#line 143 "/home/HookShare/Zach/homework/compiler/calc/parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_HOOKSHARE_ZACH_HOMEWORK_COMPILER_CALC_PARSER_HPP_INCLUDED  */
