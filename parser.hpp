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

#ifndef YY_YY_HOME_HOOKSHARE_NEW_FOLDER_PARSER_HPP_INCLUDED
# define YY_YY_HOME_HOOKSHARE_NEW_FOLDER_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ARRAY = 258,
    ASSIGN = 259,
    BEG = 260,
    CHARACTERCONST = 261,
    CHR = 262,
    SUCHTHAT = 263,
    COM = 264,
    CONST = 265,
    DIV = 266,
    DO = 267,
    DOT = 268,
    DOWNTO = 269,
    ELSEIF = 270,
    ELSE = 271,
    END = 272,
    EQUAL = 273,
    FOR = 274,
    FORWARD = 275,
    FUNCTION = 276,
    GRTEQ = 277,
    GRT = 278,
    IDENTIFIER = 279,
    IF = 280,
    NUMBER = 281,
    OPENBRAC = 282,
    OPEN = 283,
    LEG = 284,
    LES = 285,
    SUB = 286,
    MOD = 287,
    MULT = 288,
    NOT = 289,
    OF = 290,
    ORD = 291,
    ADD = 292,
    PRED = 293,
    PROCEDURE = 294,
    CLOSEBRAC = 295,
    READ = 296,
    RECORD = 297,
    REF = 298,
    REPEAT = 299,
    RETURN = 300,
    CLOSE = 301,
    DONE = 302,
    STOP = 303,
    STRINGCONST = 304,
    SUCC = 305,
    THEN = 306,
    TO = 307,
    TYPE = 308,
    UNTIL = 309,
    VAR = 310,
    WHILE = 311,
    WRITE = 312,
    AND = 313,
    OR = 314,
    NEG = 315,
    MIN = 316
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "parser.y" /* yacc.c:1909  */

int val;
char chr;
char* str;

#line 122 "/home/HookShare/New folder/parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_HOOKSHARE_NEW_FOLDER_PARSER_HPP_INCLUDED  */
