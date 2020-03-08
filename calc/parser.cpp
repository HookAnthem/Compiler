/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
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
#line 2 "parser.y" /* yacc.c:355  */

#include <iostream>
#include <map>
#include "Expression.hpp"
#include "Type.hpp"
#include "SymbolTable.hpp"
#include "Global.hpp"
extern int yylex();
void yyerror(const char*);

#line 108 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:355  */

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
    NL = 312,
    CR = 313,
    DOT = 314,
    IDENTIFIER = 315,
    CHARACTERCONST = 316,
    STRINGCONST = 317,
    OCTAL = 318,
    HEXADECIMAL = 319,
    NUMBER = 320
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "parser.y" /* yacc.c:355  */

int val;
char* chr;
char* string;
Expression* e;
char* id;
Type* t;
std::vector<std::string>* typeList;

#line 196 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_HOOKSHARE_ZACH_HOMEWORK_COMPILER_CALC_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 213 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   688

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  256

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   116,   117,   119,   120,   122,   123,   125,
     126,   127,   129,   131,   133,   134,   136,   137,   139,   140,
     141,   142,   143,   145,   147,   149,   151,   152,   154,   155,
     156,   158,   160,   162,   164,   165,   167,   168,   170,   172,
     173,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   187,   189,   191,   192,   194,   195,   197,   199,
     201,   202,   204,   206,   208,   210,   211,   213,   215,   216,
     218,   219,   221,   222,   224,   226,   227,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   257,   258,   260,   261,   262
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ARRAY", "BEG", "CHR", "CONST", "DO",
  "DOWNTO", "ELSE", "ELSEIF", "END", "FOR", "FORWARD", "FUNCTION", "IF",
  "OF", "ORD", "PRED", "PROCEDURE", "READ", "RECORD", "REF", "REPEAT",
  "RETURN", "STOP", "SUCC", "THEN", "TO", "TYPE", "UNTIL", "VAR", "WHILE",
  "WRITE", "SUB", "MULT", "DIV", "MOD", "ADD", "EQUAL", "NEG", "LES",
  "LEG", "GRT", "GRTEQ", "TILD", "AND", "OR", "NOT", "COM", "SUCHTHAT",
  "OPEN", "CLOSE", "DONE", "OPENBRAC", "CLOSEBRAC", "ASSIGN", "NL", "CR",
  "DOT", "IDENTIFIER", "CHARACTERCONST", "STRINGCONST", "OCTAL",
  "HEXADECIMAL", "NUMBER", "$accept", "Program", "OptConstDecl",
  "OptTypeDecl", "OptVarDecl", "ProFunkDecl", "ConstantDecl", "IdentExpr",
  "ProcDecl", "FuncDecl", "FormalParameters", "Body", "Block", "TypeDecl",
  "TypeDeclList", "Type", "SimpleType", "RecordType", "ArrayType",
  "TypeListOpt", "IdentList", "VarDecl", "StatementSequence", "Statement",
  "AssignmentStatement", "IfStatement", "ElseIfStatement", "ElseStatement",
  "WhileStatement", "RepeatStement", "ForStatement", "StopStatement",
  "ReturnStatement", "ReadStatement", "ReadStatementInner",
  "WriteStatement", "WriteInnerStatement", "ProcedureCall",
  "ProcedureCallInner", "NullStatement", "OptExpression", "Expression",
  "ExpressionIdentInner", "LValue", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320
};
# endif

#define YYPACT_NINF -137

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-137)))

#define YYTABLE_NINF -75

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,   -47,    36,    13,  -137,     5,    -5,  -137,     8,    19,
    -137,   228,  -137,    26,    22,  -137,  -137,    30,    38,    40,
      41,   228,   228,   228,    42,  -137,  -137,  -137,  -137,   641,
      12,    34,    46,    35,    39,   228,   228,   228,   228,   641,
     641,   529,   174,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,    43,    44,    47,    22,
    -137,    49,  -137,  -137,  -137,    22,    34,   357,    45,    48,
    -137,  -137,    51,   548,   567,   586,   605,  -137,  -137,   641,
       7,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,  -137,   228,   228,    85,    56,    53,
    -137,    54,    55,   228,    60,   357,   228,  -137,   228,    63,
      67,   252,    66,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,   -49,    69,    70,  -137,  -137,  -137,
    -137,  -137,   228,  -137,   453,   624,  -137,    34,    83,  -137,
      19,    68,   497,    65,   327,  -137,   641,   384,   228,   206,
    -137,    73,  -137,   228,   -17,   -17,   641,  -137,   228,    77,
      34,  -137,   228,   357,  -137,    71,   -40,   228,   357,    14,
     641,  -137,    15,   641,  -137,   641,    22,    22,    21,    27,
     475,    22,    79,   439,    37,  -137,    65,   641,   283,   228,
    -137,   228,  -137,    81,    86,    34,   -10,    34,   124,  -137,
      53,   228,   228,   228,   134,    12,  -137,   641,   641,    34,
      34,    91,    22,    22,    92,    34,  -137,   398,   422,   515,
     357,   135,  -137,  -137,    32,    95,    98,    33,  -137,   357,
     357,   357,   351,  -137,    99,    13,   100,    34,    34,   101,
     105,   298,   313,    37,  -137,    19,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,   156,  -137
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     5,     4,     0,     0,     1,     0,     8,
       6,     0,    12,     0,     0,     9,     7,     0,     0,     0,
       0,     0,     0,     0,   106,   100,   102,   103,   101,    13,
      99,     0,    36,     0,     0,     0,     0,     0,     0,    91,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      31,     0,    28,    29,    30,     0,     0,    74,     0,     0,
      11,    10,     0,     0,     0,     0,     0,    92,    93,   105,
       0,    86,    87,    88,    89,    85,    79,    80,    83,    81,
      84,    82,    78,    77,   107,     0,     0,     0,     0,    26,
      37,     0,     0,     0,     0,    74,    76,    62,     0,     0,
     106,    74,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,     0,     0,     0,     2,    95,    96,
      97,    98,     0,    94,     0,     0,    32,     0,     0,    25,
       8,     0,     0,     0,    74,    63,    75,     0,     0,     0,
      24,     0,    40,     0,    18,    18,   104,   108,     0,     0,
       0,    38,     0,    74,   106,     0,    66,     0,    74,     0,
      69,    70,     0,    73,    39,    52,     0,     0,     0,     0,
       0,    34,     0,     0,    54,    64,     0,    59,    74,     0,
      67,     0,    71,     0,     0,     0,     0,     0,     0,    35,
      26,     0,     0,     0,    56,    65,    58,    68,    72,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
      74,     0,    20,    19,     3,     0,     0,     3,    33,    74,
      74,    74,    57,    53,     0,     5,     0,     0,     0,     0,
       0,    74,    74,    54,    16,     8,    17,    22,    21,    14,
      15,    61,    60,    55,     0,    23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,   164,   -67,  -136,  -137,  -137,  -137,  -137,  -137,
      17,   -54,   -84,  -137,   -26,   -60,  -137,  -137,  -137,    -1,
     -14,  -137,   -64,   -57,  -137,  -137,   -56,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,   -20,  -137,   -27
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   235,     9,    15,    34,     4,     6,    70,    71,
     178,   236,    72,    10,   139,    61,    62,    63,    64,    97,
      98,    16,   111,   112,   113,   114,   204,   221,   115,   116,
     117,   118,   119,   120,   165,   121,   169,   122,   172,   123,
     145,    29,    80,    30
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,    39,    40,    41,   161,   176,   101,   153,     1,   186,
      56,    57,   212,     5,   177,    73,    74,    75,    76,    56,
      57,   213,    79,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     7,    58,     1,     1,
     124,   144,     8,    67,    11,   234,   239,   203,    12,   102,
      14,   100,   103,    68,   151,    59,   132,   104,    69,   133,
     105,   106,   107,   189,   191,    31,   190,   192,    13,   108,
     109,    56,    57,   195,   196,   134,   135,   159,   124,   197,
     196,    35,    32,   142,   124,    66,   146,   151,   147,    36,
     -74,    37,    38,    42,    60,    65,   136,   110,    95,   184,
     182,    96,    99,    94,   188,   125,   137,   140,   126,   254,
     127,   143,   156,   138,   148,   141,   166,   124,   149,   152,
     154,   155,   160,   185,   162,   164,   174,   151,   170,   173,
     181,   151,   200,   175,   209,   211,   124,   214,   180,   210,
     215,   124,   183,   220,   224,   227,   233,   187,   237,   222,
     223,   238,   244,   246,   249,   228,   232,   124,   250,   205,
      67,   124,   193,   194,     3,   241,   242,   243,   245,   207,
     255,   208,   179,   240,   216,   151,     0,   247,   248,    17,
     199,   217,   218,   219,   151,   151,   151,   253,     0,     0,
       0,    18,    19,   124,     0,     0,     0,     0,   225,   226,
      20,     0,   124,   124,   124,   124,     0,     0,    21,     0,
       0,    17,     0,     0,   124,   124,   124,     0,     0,    22,
       0,     0,     0,    18,    19,    23,    78,     0,     0,     0,
       0,     0,    20,    17,    24,     0,    25,    26,    27,    28,
      21,     0,     0,     0,     0,    18,    19,     0,     0,     0,
       0,    22,     0,     0,    20,     0,     0,    23,   171,     0,
       0,     0,    21,   150,   102,     0,    24,   103,    25,    26,
      27,    28,   104,    22,     0,   105,   106,   107,     0,    23,
       0,     0,     0,     0,   108,   109,     0,     0,    24,     0,
      25,    26,    27,    28,   206,   102,     0,     0,   103,     0,
       0,     0,     0,   104,     0,     0,   105,   106,   107,   251,
     102,     0,   110,   103,     0,   108,   109,     0,   104,     0,
       0,   105,   106,   107,   252,   102,     0,     0,   103,     0,
     108,   109,     0,   104,     0,     0,   105,   106,   107,   102,
       0,     0,   103,   110,     0,   108,   109,   104,     0,     0,
     105,   106,   107,     0,     0,     0,     0,   167,   110,   108,
     109,     0,     0,   102,     0,     0,   103,     0,     0,   102,
       0,   104,   103,   110,   105,   106,   107,   104,     0,     0,
     105,   106,   107,   108,   109,     0,     0,   110,     0,   108,
     109,   168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -74,   229,     0,     0,     0,     0,
       0,   110,     0,     0,     0,     0,     0,   110,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,   230,
      54,    55,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     0,    54,    55,     0,   201,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,   202,    54,    55,
       0,     0,     0,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,    54,    55,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,    54,
      55,     0,     0,     0,     0,     0,     0,     0,   157,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,    54,    55,     0,   163,     0,     0,     0,     0,     0,
     198,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,   231,    54,    55,     0,     0,     0,     0,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,    54,    55,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,    54,    55,     0,     0,     0,
       0,    77,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,     0,    54,    55,     0,     0,     0,     0,
     128,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,    54,    55,     0,     0,     0,     0,   129,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,    54,    55,     0,     0,     0,     0,   130,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,    54,    55,     0,     0,     0,     0,   131,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
      54,    55,     0,     0,   158,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,    54,    55
};

static const yytype_int16 yycheck[] =
{
      14,    21,    22,    23,   140,    22,    66,    56,     6,    49,
      59,    60,    22,    60,    31,    35,    36,    37,    38,    59,
      60,    31,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     0,     3,     6,     6,
      67,   105,    29,     4,    39,    13,    13,    10,    53,    12,
      31,    65,    15,    14,   111,    21,    49,    20,    19,    52,
      23,    24,    25,    49,    49,    39,    52,    52,    60,    32,
      33,    59,    60,    52,    53,    95,    96,   137,   105,    52,
      53,    51,    60,   103,   111,    50,   106,   144,   108,    51,
      53,    51,    51,    51,    60,    49,    11,    60,    54,   163,
     160,    54,    53,    60,   168,    60,    50,    53,    60,   245,
      59,    51,   132,    60,    51,    60,   143,   144,    51,    53,
      51,    51,    39,    52,    56,    60,    53,   184,   148,   149,
      53,   188,    53,   153,    53,   195,   163,   197,   158,    53,
      16,   168,   162,     9,    53,    53,    11,   167,    53,   209,
     210,    53,    53,    53,    53,   215,   220,   184,    53,   186,
       4,   188,   176,   177,     0,   229,   230,   231,   235,   189,
     254,   191,   155,   227,   200,   232,    -1,   237,   238,     5,
     181,   201,   202,   203,   241,   242,   243,   243,    -1,    -1,
      -1,    17,    18,   220,    -1,    -1,    -1,    -1,   212,   213,
      26,    -1,   229,   230,   231,   232,    -1,    -1,    34,    -1,
      -1,     5,    -1,    -1,   241,   242,   243,    -1,    -1,    45,
      -1,    -1,    -1,    17,    18,    51,    52,    -1,    -1,    -1,
      -1,    -1,    26,     5,    60,    -1,    62,    63,    64,    65,
      34,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    26,    -1,    -1,    51,    52,    -1,
      -1,    -1,    34,    11,    12,    -1,    60,    15,    62,    63,
      64,    65,    20,    45,    -1,    23,    24,    25,    -1,    51,
      -1,    -1,    -1,    -1,    32,    33,    -1,    -1,    60,    -1,
      62,    63,    64,    65,    11,    12,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    23,    24,    25,    11,
      12,    -1,    60,    15,    -1,    32,    33,    -1,    20,    -1,
      -1,    23,    24,    25,    11,    12,    -1,    -1,    15,    -1,
      32,    33,    -1,    20,    -1,    -1,    23,    24,    25,    12,
      -1,    -1,    15,    60,    -1,    32,    33,    20,    -1,    -1,
      23,    24,    25,    -1,    -1,    -1,    -1,    30,    60,    32,
      33,    -1,    -1,    12,    -1,    -1,    15,    -1,    -1,    12,
      -1,    20,    15,    60,    23,    24,    25,    20,    -1,    -1,
      23,    24,    25,    32,    33,    -1,    -1,    60,    -1,    32,
      33,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,     7,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    60,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     7,
      46,    47,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    46,    47,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    28,    46,    47,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    46,    47,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    46,    47,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      55,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    27,    46,    47,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    46,    47,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    46,    47,    -1,    -1,    -1,
      -1,    52,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,
      52,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    46,    47,    -1,    -1,    -1,    -1,    52,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      46,    47,    -1,    -1,    50,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    67,    68,    72,    60,    73,     0,    29,    69,
      79,    39,    53,    60,    31,    70,    87,     5,    17,    18,
      26,    34,    45,    51,    60,    62,    63,    64,    65,   107,
     109,    39,    60,    86,    71,    51,    51,    51,    51,   107,
     107,   107,    51,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    46,    47,    59,    60,     3,    21,
      60,    81,    82,    83,    84,    49,    50,     4,    14,    19,
      74,    75,    78,   107,   107,   107,   107,    52,    52,   107,
     108,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,    60,    54,    54,    85,    86,    53,
      86,    81,    12,    15,    20,    23,    24,    25,    32,    33,
      60,    88,    89,    90,    91,    94,    95,    96,    97,    98,
      99,   101,   103,   105,   109,    60,    60,    59,    52,    52,
      52,    52,    49,    52,   107,   107,    11,    50,    60,    80,
      53,    60,   107,    51,    88,   106,   107,   107,    51,    51,
      11,    89,    53,    56,    51,    51,   107,    55,    50,    81,
      39,    70,    56,    27,    60,   100,   109,    30,     7,   102,
     107,    52,   104,   107,    53,   107,    22,    31,    76,    76,
     107,    53,    81,   107,    88,    52,    49,   107,    88,    49,
      52,    49,    52,    86,    86,    52,    53,    52,    55,    85,
      53,     8,    28,    10,    92,   109,    11,   107,   107,    53,
      53,    81,    22,    31,    81,    16,    80,   107,   107,   107,
       9,    93,    81,    81,    53,    86,    86,    53,    81,     7,
       7,    27,    88,    11,    13,    68,    77,    53,    53,    13,
      77,    88,    88,    88,    53,    69,    53,    81,    81,    53,
      53,    11,    11,    92,    70,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    71,    72,    73,    74,    74,    75,    75,    76,    76,
      76,    76,    76,    77,    78,    79,    80,    80,    81,    81,
      81,    82,    83,    84,    85,    85,    86,    86,    87,    88,
      88,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    90,    91,    92,    92,    93,    93,    94,    95,
      96,    96,    97,    98,    99,   100,   100,   101,   102,   102,
     103,   103,   104,   104,   105,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   108,   108,   109,   109,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     1,     0,     1,     1,     0,     0,
       2,     2,     3,     3,     9,     9,     9,     9,     0,     4,
       4,     6,     6,     4,     3,     6,     0,     5,     1,     1,
       1,     1,     3,     8,     0,     5,     1,     3,     6,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     7,     0,     5,     0,     2,     5,     4,
       9,     9,     1,     2,     4,     3,     1,     4,     3,     1,
       3,     4,     3,     1,     0,     1,     0,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     3,     4,     4,     4,     4,     4,     1,
       1,     1,     1,     1,     3,     1,     1,     3,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 114 "parser.y" /* yacc.c:1646  */
    { YYACCEPT; }
#line 1557 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 116 "parser.y" /* yacc.c:1646  */
    {}
#line 1563 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 117 "parser.y" /* yacc.c:1646  */
    { }
#line 1569 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 119 "parser.y" /* yacc.c:1646  */
    {}
#line 1575 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 120 "parser.y" /* yacc.c:1646  */
    { }
#line 1581 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 122 "parser.y" /* yacc.c:1646  */
    { }
#line 1587 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 123 "parser.y" /* yacc.c:1646  */
    {}
#line 1593 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 125 "parser.y" /* yacc.c:1646  */
    {}
#line 1599 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 126 "parser.y" /* yacc.c:1646  */
    {}
#line 1605 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 127 "parser.y" /* yacc.c:1646  */
    {}
#line 1611 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 129 "parser.y" /* yacc.c:1646  */
    {}
#line 1617 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 131 "parser.y" /* yacc.c:1646  */
    {SYMBOL_TABLE.Store(std::string((yyvsp[-2].id)), (yyvsp[0].e));}
#line 1623 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 133 "parser.y" /* yacc.c:1646  */
    {}
#line 1629 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 134 "parser.y" /* yacc.c:1646  */
    {}
#line 1635 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 136 "parser.y" /* yacc.c:1646  */
    {}
#line 1641 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 137 "parser.y" /* yacc.c:1646  */
    {}
#line 1647 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 139 "parser.y" /* yacc.c:1646  */
    {}
#line 1653 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 140 "parser.y" /* yacc.c:1646  */
    {}
#line 1659 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 141 "parser.y" /* yacc.c:1646  */
    {}
#line 1665 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 142 "parser.y" /* yacc.c:1646  */
    {}
#line 1671 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 143 "parser.y" /* yacc.c:1646  */
    {}
#line 1677 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 145 "parser.y" /* yacc.c:1646  */
    {}
#line 1683 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 147 "parser.y" /* yacc.c:1646  */
    {}
#line 1689 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 149 "parser.y" /* yacc.c:1646  */
    {SYMBOL_TABLE.Store(std::string((yyvsp[-4].id)),(yyvsp[-2].t));}
#line 1695 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 151 "parser.y" /* yacc.c:1646  */
    {}
#line 1701 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 152 "parser.y" /* yacc.c:1646  */
    {}
#line 1707 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 154 "parser.y" /* yacc.c:1646  */
    {}
#line 1713 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 155 "parser.y" /* yacc.c:1646  */
    {}
#line 1719 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 156 "parser.y" /* yacc.c:1646  */
    {}
#line 1725 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 158 "parser.y" /* yacc.c:1646  */
    {(yyval.t) = SYMBOL_TABLE.TypeLookup(std::string((yyvsp[0].id)));}
#line 1731 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 160 "parser.y" /* yacc.c:1646  */
    {}
#line 1737 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 162 "parser.y" /* yacc.c:1646  */
    {/*$$ = dynamic_cast<Type *>(new ArrayType($3, $5, $8));*/}
#line 1743 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 164 "parser.y" /* yacc.c:1646  */
    {}
#line 1749 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 165 "parser.y" /* yacc.c:1646  */
    {/*$$ = new RecordType($1,$3)*/}
#line 1755 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 167 "parser.y" /* yacc.c:1646  */
    {/* $$ = new std::vector<std::string>(1, std::string($1))*/}
#line 1761 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 168 "parser.y" /* yacc.c:1646  */
    {/* $1->push_back($3)*/ }
#line 1767 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 170 "parser.y" /* yacc.c:1646  */
    {}
#line 1773 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 172 "parser.y" /* yacc.c:1646  */
    {}
#line 1779 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 173 "parser.y" /* yacc.c:1646  */
    {}
#line 1785 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 175 "parser.y" /* yacc.c:1646  */
    {}
#line 1791 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 176 "parser.y" /* yacc.c:1646  */
    {}
#line 1797 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 177 "parser.y" /* yacc.c:1646  */
    {}
#line 1803 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 178 "parser.y" /* yacc.c:1646  */
    {}
#line 1809 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 179 "parser.y" /* yacc.c:1646  */
    {}
#line 1815 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 180 "parser.y" /* yacc.c:1646  */
    {}
#line 1821 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 181 "parser.y" /* yacc.c:1646  */
    {}
#line 1827 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 182 "parser.y" /* yacc.c:1646  */
    {}
#line 1833 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 183 "parser.y" /* yacc.c:1646  */
    {}
#line 1839 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 184 "parser.y" /* yacc.c:1646  */
    {}
#line 1845 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 185 "parser.y" /* yacc.c:1646  */
    {}
#line 1851 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 187 "parser.y" /* yacc.c:1646  */
    {Assign((yyvsp[-2].e), (yyvsp[0].e));}
#line 1857 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 189 "parser.y" /* yacc.c:1646  */
    {}
#line 1863 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 191 "parser.y" /* yacc.c:1646  */
    {}
#line 1869 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 192 "parser.y" /* yacc.c:1646  */
    {}
#line 1875 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 194 "parser.y" /* yacc.c:1646  */
    {}
#line 1881 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 195 "parser.y" /* yacc.c:1646  */
    {}
#line 1887 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 197 "parser.y" /* yacc.c:1646  */
    {}
#line 1893 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 199 "parser.y" /* yacc.c:1646  */
    {}
#line 1899 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 201 "parser.y" /* yacc.c:1646  */
    {}
#line 1905 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 202 "parser.y" /* yacc.c:1646  */
    {}
#line 1911 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 204 "parser.y" /* yacc.c:1646  */
    {}
#line 1917 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 206 "parser.y" /* yacc.c:1646  */
    {}
#line 1923 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 208 "parser.y" /* yacc.c:1646  */
    {}
#line 1929 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 210 "parser.y" /* yacc.c:1646  */
    {}
#line 1935 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 211 "parser.y" /* yacc.c:1646  */
    {}
#line 1941 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 215 "parser.y" /* yacc.c:1646  */
    {/*WriteFunction($3)*/}
#line 1947 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 216 "parser.y" /* yacc.c:1646  */
    {/*WriteFunction($1)*/}
#line 1953 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 218 "parser.y" /* yacc.c:1646  */
    {}
#line 1959 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 219 "parser.y" /* yacc.c:1646  */
    {}
#line 1965 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 221 "parser.y" /* yacc.c:1646  */
    {}
#line 1971 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 222 "parser.y" /* yacc.c:1646  */
    {}
#line 1977 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 224 "parser.y" /* yacc.c:1646  */
    {}
#line 1983 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 227 "parser.y" /* yacc.c:1646  */
    {}
#line 1989 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 229 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = Or((yyvsp[-2].e),(yyvsp[0].e));}
#line 1995 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 230 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = And((yyvsp[-2].e),(yyvsp[0].e));}
#line 2001 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 231 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = equal((yyvsp[-2].e),(yyvsp[0].e));}
#line 2007 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 232 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = neg((yyvsp[-2].e),(yyvsp[0].e));}
#line 2013 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 233 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = leg((yyvsp[-2].e),(yyvsp[0].e));}
#line 2019 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 234 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = grteq((yyvsp[-2].e),(yyvsp[0].e));}
#line 2025 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 235 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = les((yyvsp[-2].e),(yyvsp[0].e));}
#line 2031 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 236 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = grt((yyvsp[-2].e),(yyvsp[0].e));}
#line 2037 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 237 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = add((yyvsp[-2].e),(yyvsp[0].e));}
#line 2043 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 238 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = sub((yyvsp[-2].e),(yyvsp[0].e));}
#line 2049 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 239 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = mult((yyvsp[-2].e),(yyvsp[0].e));}
#line 2055 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 240 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = div((yyvsp[-2].e),(yyvsp[0].e));}
#line 2061 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 241 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = mod((yyvsp[-2].e),(yyvsp[0].e));}
#line 2067 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 242 "parser.y" /* yacc.c:1646  */
    { }
#line 2073 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 243 "parser.y" /* yacc.c:1646  */
    {}
#line 2079 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 244 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = (yyvsp[-1].e);}
#line 2085 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 245 "parser.y" /* yacc.c:1646  */
    {}
#line 2091 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 246 "parser.y" /* yacc.c:1646  */
    {}
#line 2097 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 247 "parser.y" /* yacc.c:1646  */
    {}
#line 2103 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 248 "parser.y" /* yacc.c:1646  */
    {}
#line 2109 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 249 "parser.y" /* yacc.c:1646  */
    {}
#line 2115 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 250 "parser.y" /* yacc.c:1646  */
    {}
#line 2121 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 251 "parser.y" /* yacc.c:1646  */
    { (yyval.e) = (yyvsp[0].e);}
#line 2127 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 252 "parser.y" /* yacc.c:1646  */
    { (yyval.e) = new Expression(STRING_LIST.storage(std::string((yyvsp[0].string))), &TYPE_STR);}
#line 2133 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 253 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = new Expression((yyvsp[0].val), &TYPE_INT);}
#line 2139 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 254 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = new Expression((yyvsp[0].val), &TYPE_INT);}
#line 2145 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 255 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = new Expression((yyvsp[0].val), &TYPE_INT);}
#line 2151 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 257 "parser.y" /* yacc.c:1646  */
    {}
#line 2157 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 258 "parser.y" /* yacc.c:1646  */
    {}
#line 2163 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 260 "parser.y" /* yacc.c:1646  */
    {(yyval.e) = Lvalue((yyvsp[0].id));}
#line 2169 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 261 "parser.y" /* yacc.c:1646  */
    {}
#line 2175 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 262 "parser.y" /* yacc.c:1646  */
    {}
#line 2181 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
    break;


#line 2185 "/home/HookShare/Zach/homework/compiler/calc/parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 264 "parser.y" /* yacc.c:1906  */


void yyerror(const char* msg)
{
  std::cerr << msg << std::endl;
}

