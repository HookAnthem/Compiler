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
#line 1 "parser.y" /* yacc.c:339  */

#include <iostream>
#include <fstream>
#include "Global.hpp"
#include "MiddleAsembler.hpp"
extern char * yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char*);
MiddleAsembler MA;

#line 78 "/home/HookShare/New folder/parser.cpp" /* yacc.c:339  */

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
#line 14 "parser.y" /* yacc.c:355  */

int val;
char chr;
char* str;

#line 186 "/home/HookShare/New folder/parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_HOOKSHARE_NEW_FOLDER_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 203 "/home/HookShare/New folder/parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   497

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  250

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   134,   134,   137,   139,   140,   143,   144,   147,   150,
     153,   154,   155,   158,   159,   162,   165,   168,   169,   172,
     175,   177,   178,   181,   182,   185,   188,   189,   190,   194,
     197,   200,   201,   204,   205,   208,   209,   212,   215,   216,
     217,   220,   223,   226,   227,   230,   233,   234,   237,   240,
     241,   244,   245,   248,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   264,   267,   270,   273,   276,
     279,   280,   283,   286,   287,   290,   293,   296,   298,   301,
     304,   307,   308,   311,   315,   318,   319,   323,   326,   327,
     330,   333,   334,   337,   339,   340,   342,   343,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   373,   376,   377,   378
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ARRAY", "ASSIGN", "BEG",
  "CHARACTERCONST", "CHR", "SUCHTHAT", "COM", "CONST", "DIV", "DO", "DOT",
  "DOWNTO", "ELSEIF", "ELSE", "END", "EQUAL", "FOR", "FORWARD", "FUNCTION",
  "GRTEQ", "GRT", "IDENTIFIER", "IF", "NUMBER", "OPENBRAC", "OPEN", "LEG",
  "LES", "SUB", "MOD", "MULT", "NOT", "OF", "ORD", "ADD", "PRED",
  "PROCEDURE", "CLOSEBRAC", "READ", "RECORD", "REF", "REPEAT", "RETURN",
  "CLOSE", "DONE", "STOP", "STRINGCONST", "SUCC", "THEN", "TO", "TYPE",
  "UNTIL", "VAR", "WHILE", "WRITE", "AND", "OR", "NEG", "MIN", "$accept",
  "Program", "ProgramHead", "OptConstDecls", "ConstDecls", "ConstDecl",
  "PFDecls", "PFDecls2", "ProcedureDecl", "PSignature", "ProcedureTop",
  "FunctionDecl", "FSignature", "FunctionTop", "OptFormalParameters",
  "FormalParameters", "FormalParameter", "OptVar", "Body", "Block",
  "StatementList", "OptTypeDecls", "TypeDecls", "TypeDecl", "Type",
  "SimpleType", "RecordType", "FieldDecls", "FieldDecl", "IdentList",
  "ArrayType", "OptVarDecls", "VarDecls", "VarDecl", "Statement",
  "Assignment", "IfStatement", "IfStuff", "IfHead", "ThenPart",
  "ElseIfList", "ElseIfHead", "ElseClause", "WhileStatement", "WhileHead",
  "WhileSymbol", "RepeatStatement", "RepeatSymbol", "ForStatement",
  "ToHead", "ForHead", "StopStatement", "ReturnStatement", "ReadStatement",
  "ReadArgs", "WriteStatement", "WriteArgs", "ProcedureCall",
  "OptArguments", "Arguments", "Expression", "FunctionCall", "LValue", YY_NULLPTR
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
     315,   316
};
# endif

#define YYPACT_NINF -140

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-140)))

#define YYTABLE_NINF -29

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-29)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,    -9,    29,    30,    23,    60,    -9,  -140,  -140,     7,
      49,    59,    53,   447,  -140,    82,    90,   447,    91,  -140,
     447,  -140,  -140,    93,   -14,  -140,  -140,  -140,  -140,    71,
    -140,   111,   447,  -140,     7,  -140,   114,    -6,  -140,  -140,
    -140,  -140,  -140,   103,  -140,   110,    59,  -140,   113,  -140,
    -140,   115,   116,  -140,   447,   447,   447,   117,   124,  -140,
     125,   159,  -140,    44,   134,   447,   401,   122,   401,   447,
    -140,     7,    66,     7,  -140,     7,   401,   -24,     7,   447,
     447,   447,   130,   447,    -2,  -140,  -140,     9,   113,  -140,
    -140,   -12,   447,   447,   193,  -140,   118,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
    -140,   447,   447,   447,   447,    96,   147,   401,  -140,    -7,
      44,     3,   401,  -140,   447,     7,    71,   140,   112,    -3,
     447,    11,   401,   401,   401,  -140,   225,   131,  -140,   113,
     120,  -140,  -140,  -140,    -2,   141,  -140,   144,   145,  -140,
     126,   136,  -140,   127,   143,   249,   129,  -140,   281,   313,
     345,  -140,   433,   433,   433,   433,   433,     5,  -140,  -140,
       5,   118,   118,   433,   401,  -140,   447,   122,  -140,   447,
    -140,   401,   112,  -140,  -140,  -140,   401,  -140,  -140,   447,
      37,  -140,    51,  -140,   133,  -140,  -140,  -140,     0,    10,
      92,    10,  -140,  -140,  -140,  -140,  -140,   401,    44,   401,
     102,  -140,  -140,    -2,  -140,   137,    23,   138,  -140,  -140,
     148,   139,  -140,   113,   146,   150,   149,   447,   151,  -140,
      53,  -140,  -140,   -30,   106,  -140,  -140,   164,   377,  -140,
      30,  -140,    -2,    -2,   152,  -140,  -140,  -140,    -2,  -140
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     0,    34,     0,     4,     7,     1,    64,
       0,     0,    50,     0,     6,     0,   126,     0,     0,    79,
      86,    84,    77,     0,     0,    32,    54,    55,    71,     0,
      56,     0,     0,    57,    64,    58,     0,     0,    59,    60,
      61,    62,    63,     0,     2,     0,    33,    36,     0,    12,
      98,     0,   126,   114,     0,     0,     0,     0,     0,   121,
       0,     0,   113,   116,     0,    95,    68,     0,    85,     0,
      30,    64,    74,    64,    67,    64,    76,     0,    64,     0,
       0,     0,     0,     0,     0,    35,    47,     0,    49,    52,
       3,     9,     0,    95,     0,   117,   118,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     0,     0,     0,     0,    94,    97,   126,     0,
      89,     0,    92,    31,     0,    64,     0,     0,    69,     0,
       0,     0,    82,    81,    65,   124,     0,     0,    41,     0,
       0,    38,    39,    40,     0,     0,    51,     0,     0,    10,
       0,     0,    11,     0,     0,     0,     0,   115,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     112,   100,   111,   110,    83,    93,     0,     0,    87,     0,
      90,    72,    73,    70,    66,    75,    78,    80,   125,     0,
       0,    44,     0,    37,     0,    46,    20,    16,     5,    22,
       5,    22,    99,   123,   119,   120,   122,    96,    88,    91,
       0,    42,    43,     0,    53,     0,    34,     0,    27,    26,
       0,    21,    24,     0,     0,     0,     0,     0,     0,    13,
      50,    14,    15,    28,     0,    17,    18,     0,     0,    45,
       0,    23,     0,     0,     0,    29,    25,    19,     0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,  -140,   183,  -140,   194,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,     1,  -140,   -34,  -140,     8,   -39,
     -28,   -11,  -140,   157,  -139,  -140,  -140,  -140,    17,  -118,
    -140,   -21,  -140,   132,   142,  -140,  -140,  -140,  -140,    84,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,   119,  -140,
     -13,  -140,     2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   216,     6,     7,    90,    91,   149,   150,
     151,   152,   153,   154,   220,   221,   222,   223,   217,    10,
      24,    12,    46,    47,   140,   141,   142,   190,   191,    87,
     143,    49,    88,    89,    25,    26,    27,    28,    29,    74,
      72,   126,   127,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,   119,    41,   121,    42,   115,   116,
     117,    62,    63
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,   137,   177,    70,    66,   194,    77,    68,    79,   147,
       1,    43,   179,   218,   185,     5,   100,   144,   145,    76,
     215,   192,   138,    71,     1,   219,    15,   148,   187,     8,
     130,    16,    17,    71,   -28,     9,    43,   107,   108,   178,
     139,    94,    95,    96,    71,   128,    80,   129,    18,   180,
     131,    19,    20,   218,   211,    21,   122,    82,    71,   213,
     145,    86,    44,    22,    23,   219,   132,   133,   134,   120,
     136,    83,   192,    43,   228,    43,    11,    43,    13,   155,
      43,   124,   125,    45,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   182,   171,   172,
     173,   174,     1,   246,   247,   234,    64,    81,    48,   249,
     227,   181,   224,   100,   242,   145,    82,   186,    65,    67,
     101,    69,    73,    75,   102,   103,    78,    43,    84,   100,
      83,   104,   105,   106,   107,   108,   101,    86,   114,   109,
     102,   103,   175,    92,    93,    97,   118,   104,   105,   106,
     107,   108,    98,    99,   135,   109,   176,   184,   189,    71,
     111,   112,   113,   207,   199,   195,   209,   193,   196,   197,
     100,   201,   243,   198,   200,   203,   210,   101,   113,   208,
     214,   102,   103,     4,   229,   231,   233,   248,   104,   105,
     106,   107,   108,   235,   232,   237,   109,   236,   239,   241,
      14,   245,   226,    85,   100,   230,   110,   212,   225,   240,
     183,   101,   156,   123,   238,   102,   103,   111,   112,   113,
     146,     0,   104,   105,   106,   107,   108,     0,     0,     0,
     109,     0,     0,     0,     0,     0,   100,     0,     0,   157,
       0,     0,     0,   101,     0,     0,     0,   102,   103,     0,
       0,   111,   112,   113,   104,   105,   106,   107,   108,     0,
     100,     0,   109,     0,     0,   188,     0,   101,     0,     0,
       0,   102,   103,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   111,   112,   113,   109,     0,     0,     0,
       0,     0,   100,     0,     0,   202,     0,     0,     0,   101,
       0,     0,     0,   102,   103,     0,     0,   111,   112,   113,
     104,   105,   106,   107,   108,     0,     0,     0,   109,     0,
       0,     0,     0,     0,   100,     0,     0,   204,     0,     0,
       0,   101,     0,     0,     0,   102,   103,     0,     0,   111,
     112,   113,   104,   105,   106,   107,   108,     0,     0,     0,
     109,     0,     0,     0,     0,     0,   100,     0,     0,   205,
       0,     0,     0,   101,     0,     0,     0,   102,   103,     0,
       0,   111,   112,   113,   104,   105,   106,   107,   108,     0,
       0,     0,   109,     0,     0,     0,     0,     0,   100,     0,
       0,   206,     0,     0,     0,   101,     0,     0,     0,   102,
     103,     0,     0,   111,   112,   113,   104,   105,   106,   107,
     108,     0,   100,     0,   109,     0,     0,   244,     0,   101,
       0,     0,     0,   102,   103,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   111,   112,   113,   109,     0,
       0,     0,     0,     0,   100,     0,     0,     0,     0,     0,
       0,   -29,     0,    50,    51,   -29,   -29,     0,     0,   111,
     112,   113,   -29,   -29,   106,   107,   108,     0,     0,     0,
     109,    52,     0,    53,     0,    54,     0,     0,    55,     0,
       0,    56,     0,    57,     0,    58,     0,     0,     0,     0,
       0,     0,     0,   -29,     0,     0,    59,    60
};

static const yytype_int16 yycheck[] =
{
      13,     3,     9,    17,    17,   144,    34,    20,    14,    21,
      10,     9,     9,    43,    17,    24,    11,     8,     9,    32,
      20,   139,    24,    47,    10,    55,    19,    39,    17,     0,
      54,    24,    25,    47,    24,     5,    34,    32,    33,    46,
      42,    54,    55,    56,    47,    73,    52,    75,    41,    46,
      78,    44,    45,    43,    17,    48,    69,    13,    47,     8,
       9,    24,    13,    56,    57,    55,    79,    80,    81,    67,
      83,    27,   190,    71,   213,    73,    53,    75,    18,    92,
      78,    15,    16,    24,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   125,   111,   112,
     113,   114,    10,   242,   243,   223,    24,     4,    55,   248,
       8,   124,    20,    11,     8,     9,    13,   130,    28,    28,
      18,    28,    51,    12,    22,    23,    12,   125,    18,    11,
      27,    29,    30,    31,    32,    33,    18,    24,     4,    37,
      22,    23,    46,    28,    28,    28,    24,    29,    30,    31,
      32,    33,    28,    28,    24,    37,     9,    17,    27,    47,
      58,    59,    60,   176,    28,    24,   179,    47,    24,    24,
      11,    28,     8,    47,    47,    46,   189,    18,    60,   177,
      47,    22,    23,     0,    47,    47,    47,    35,    29,    30,
      31,    32,    33,    47,    46,    46,    37,    47,    47,   233,
       6,   240,   201,    46,    11,   216,    47,   190,   200,   230,
     126,    18,    93,    71,   227,    22,    23,    58,    59,    60,
      88,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    46,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,    -1,
      -1,    58,    59,    60,    29,    30,    31,    32,    33,    -1,
      11,    -1,    37,    -1,    -1,    40,    -1,    18,    -1,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    58,    59,    60,    37,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    46,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    22,    23,    -1,    -1,    58,    59,    60,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    46,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    22,    23,    -1,    -1,    58,
      59,    60,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    46,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,    -1,
      -1,    58,    59,    60,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    11,    -1,
      -1,    46,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,
      23,    -1,    -1,    58,    59,    60,    29,    30,    31,    32,
      33,    -1,    11,    -1,    37,    -1,    -1,    40,    -1,    18,
      -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    58,    59,    60,    37,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,     6,     7,    22,    23,    -1,    -1,    58,
      59,    60,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      37,    24,    -1,    26,    -1,    28,    -1,    -1,    31,    -1,
      -1,    34,    -1,    36,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    63,    64,    65,    24,    66,    67,     0,     5,
      81,    53,    83,    18,    67,    19,    24,    25,    41,    44,
      45,    48,    56,    57,    82,    96,    97,    98,    99,   100,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   117,   119,   124,    13,    24,    84,    85,    55,    93,
       6,     7,    24,    26,    28,    31,    34,    36,    38,    49,
      50,   122,   123,   124,    24,    28,   122,    28,   122,    28,
      17,    47,   102,    51,   101,    12,   122,    82,    12,    14,
      52,     4,    13,    27,    18,    85,    24,    91,    94,    95,
      68,    69,    28,    28,   122,   122,   122,    28,    28,    28,
      11,    18,    22,    23,    29,    30,    31,    32,    33,    37,
      47,    58,    59,    60,     4,   120,   121,   122,    24,   116,
     124,   118,   122,    96,    15,    16,   103,   104,    82,    82,
      54,    82,   122,   122,   122,    24,   122,     3,    24,    42,
      86,    87,    88,    92,     8,     9,    95,    21,    39,    70,
      71,    72,    73,    74,    75,   122,   120,    46,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,    46,     9,     9,    46,     9,
      46,   122,    82,   101,    17,    17,   122,    17,    40,    27,
      89,    90,    91,    47,    86,    24,    24,    24,    47,    28,
      47,    28,    46,    46,    46,    46,    46,   122,   124,   122,
     122,    17,    90,     8,    47,    20,    65,    80,    43,    55,
      76,    77,    78,    79,    20,    80,    76,     8,    86,    47,
      83,    47,    46,    47,    91,    47,    47,    46,   122,    47,
      93,    78,     8,     8,    40,    81,    86,    86,    35,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    65,    65,    66,    66,    67,    68,
      69,    69,    69,    70,    70,    71,    72,    73,    73,    74,
      75,    76,    76,    77,    77,    78,    79,    79,    79,    80,
      81,    82,    82,    83,    83,    84,    84,    85,    86,    86,
      86,    87,    88,    89,    89,    90,    91,    91,    92,    93,
      93,    94,    94,    95,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    97,    98,    99,   100,   101,
     102,   102,   103,   104,   104,   105,   106,   107,   108,   109,
     110,   111,   111,   112,   113,   114,   114,   115,   116,   116,
     117,   118,   118,   119,   120,   120,   121,   121,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   123,   124,   124,   124
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     4,     2,     0,     2,     1,     4,     1,
       2,     2,     0,     4,     4,     4,     2,     4,     4,     6,
       2,     1,     0,     3,     1,     4,     1,     1,     0,     4,
       3,     3,     1,     2,     0,     2,     1,     4,     1,     1,
       1,     1,     3,     2,     1,     4,     3,     1,     8,     2,
       0,     2,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     4,     2,     2,     2,
       3,     0,     2,     2,     0,     4,     2,     1,     4,     1,
       4,     3,     3,     4,     1,     2,     1,     4,     3,     1,
       4,     3,     1,     4,     1,     0,     3,     1,     1,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     3,     1,     2,     2,     4,
       4,     1,     4,     4,     3,     4,     1
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
#line 134 "parser.y" /* yacc.c:1646  */
    {}
#line 1517 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 147 "parser.y" /* yacc.c:1646  */
    {MA.storeConst((yyvsp[-3].str),(yyvsp[-1].val));}
#line 1523 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 150 "parser.y" /* yacc.c:1646  */
    {}
#line 1529 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 158 "parser.y" /* yacc.c:1646  */
    {}
#line 1535 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 159 "parser.y" /* yacc.c:1646  */
    {MA.doProcedureEpilogue();}
#line 1541 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 162 "parser.y" /* yacc.c:1646  */
    {}
#line 1547 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 165 "parser.y" /* yacc.c:1646  */
    {MA.doProcedurePrologue((yyvsp[0].str));}
#line 1553 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 168 "parser.y" /* yacc.c:1646  */
    {}
#line 1559 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 169 "parser.y" /* yacc.c:1646  */
    {}
#line 1565 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 172 "parser.y" /* yacc.c:1646  */
    {}
#line 1571 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 175 "parser.y" /* yacc.c:1646  */
    {ignoreFunction(); }
#line 1577 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 177 "parser.y" /* yacc.c:1646  */
    {}
#line 1583 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 178 "parser.y" /* yacc.c:1646  */
    {}
#line 1589 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 181 "parser.y" /* yacc.c:1646  */
    {}
#line 1595 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 182 "parser.y" /* yacc.c:1646  */
    {}
#line 1601 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 185 "parser.y" /* yacc.c:1646  */
    {MA.makeParameters((yyvsp[-2].val),(yyvsp[0].val));}
#line 1607 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 188 "parser.y" /* yacc.c:1646  */
    {}
#line 1613 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 189 "parser.y" /* yacc.c:1646  */
    {}
#line 1619 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 190 "parser.y" /* yacc.c:1646  */
    {}
#line 1625 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 194 "parser.y" /* yacc.c:1646  */
    {}
#line 1631 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 197 "parser.y" /* yacc.c:1646  */
    {}
#line 1637 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 200 "parser.y" /* yacc.c:1646  */
    {}
#line 1643 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 201 "parser.y" /* yacc.c:1646  */
    {}
#line 1649 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 212 "parser.y" /* yacc.c:1646  */
    {SYMBOL_TABLE.storeType((yyvsp[-3].str), (yyvsp[-1].val));}
#line 1655 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 215 "parser.y" /* yacc.c:1646  */
    {}
#line 1661 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 216 "parser.y" /* yacc.c:1646  */
    {}
#line 1667 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 217 "parser.y" /* yacc.c:1646  */
    {}
#line 1673 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 220 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = SYMBOL_TABLE.lookupType((yyvsp[0].str));}
#line 1679 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 223 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[-1].val);}
#line 1685 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 226 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.mergeRecords((yyvsp[-1].val),(yyvsp[0].val));}
#line 1691 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 227 "parser.y" /* yacc.c:1646  */
    {}
#line 1697 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 230 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.makeRecordVars((yyvsp[-3].val),(yyvsp[-1].val));}
#line 1703 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 233 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.appendStrList((yyvsp[-2].val),(yyvsp[0].str));}
#line 1709 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 234 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.makeStrList((yyvsp[0].str));}
#line 1715 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 237 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.buildArray((yyvsp[-5].val),(yyvsp[-3].val),(yyvsp[0].val));}
#line 1721 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 248 "parser.y" /* yacc.c:1646  */
    {MA.makeVars((yyvsp[-3].val),(yyvsp[-1].val));}
#line 1727 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 251 "parser.y" /* yacc.c:1646  */
    {}
#line 1733 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 252 "parser.y" /* yacc.c:1646  */
    {MA.endIf();}
#line 1739 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 253 "parser.y" /* yacc.c:1646  */
    {MA.endWhile((yyvsp[0].val));}
#line 1745 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 254 "parser.y" /* yacc.c:1646  */
    {}
#line 1751 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 255 "parser.y" /* yacc.c:1646  */
    {MA.endFor((yyvsp[0].val));}
#line 1757 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 256 "parser.y" /* yacc.c:1646  */
    {}
#line 1763 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 257 "parser.y" /* yacc.c:1646  */
    {}
#line 1769 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 258 "parser.y" /* yacc.c:1646  */
    {}
#line 1775 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 259 "parser.y" /* yacc.c:1646  */
    {}
#line 1781 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 260 "parser.y" /* yacc.c:1646  */
    {}
#line 1787 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 261 "parser.y" /* yacc.c:1646  */
    {}
#line 1793 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 264 "parser.y" /* yacc.c:1646  */
    {MA.assignExprToLval((yyvsp[-2].val), (yyvsp[0].val));}
#line 1799 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 267 "parser.y" /* yacc.c:1646  */
    {}
#line 1805 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 270 "parser.y" /* yacc.c:1646  */
    {MA.doElse((yyvsp[-1].val));}
#line 1811 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 273 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.startIf((yyvsp[0].val),false);}
#line 1817 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 276 "parser.y" /* yacc.c:1646  */
    {}
#line 1823 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 279 "parser.y" /* yacc.c:1646  */
    {MA.doElse((yyvsp[-1].val));}
#line 1829 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 280 "parser.y" /* yacc.c:1646  */
    {}
#line 1835 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 283 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.startIf((yyvsp[0].val),true);}
#line 1841 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 286 "parser.y" /* yacc.c:1646  */
    {}
#line 1847 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 287 "parser.y" /* yacc.c:1646  */
    {}
#line 1853 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 290 "parser.y" /* yacc.c:1646  */
    {}
#line 1859 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 293 "parser.y" /* yacc.c:1646  */
    {MA.startWhile((yyvsp[-1].val),(yyvsp[0].val));}
#line 1865 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 296 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.preWhile();}
#line 1871 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 298 "parser.y" /* yacc.c:1646  */
    {MA.endRepeat((yyvsp[-3].val),(yyvsp[0].val));}
#line 1877 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 301 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.startRepeat();}
#line 1883 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 304 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[-3].val);}
#line 1889 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 307 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.compareFor((yyvsp[-2].val),(yyvsp[0].val),true);}
#line 1895 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 308 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.compareFor((yyvsp[-2].val),(yyvsp[0].val),false);}
#line 1901 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 311 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.startFor((yyvsp[-2].str),(yyvsp[0].val));}
#line 1907 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 315 "parser.y" /* yacc.c:1646  */
    {stop();}
#line 1913 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 318 "parser.y" /* yacc.c:1646  */
    {}
#line 1919 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 319 "parser.y" /* yacc.c:1646  */
    {}
#line 1925 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 323 "parser.y" /* yacc.c:1646  */
    {MA.clearExpressions();}
#line 1931 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 326 "parser.y" /* yacc.c:1646  */
    {MA.readToLval((yyvsp[0].val));}
#line 1937 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 327 "parser.y" /* yacc.c:1646  */
    {MA.readToLval((yyvsp[0].val));}
#line 1943 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 330 "parser.y" /* yacc.c:1646  */
    {}
#line 1949 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 333 "parser.y" /* yacc.c:1646  */
    {MA.unOp((yyvsp[0].val),&MiddleAsembler::writeExpression);}
#line 1955 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 334 "parser.y" /* yacc.c:1646  */
    {MA.unOp((yyvsp[0].val),&MiddleAsembler::writeExpression);}
#line 1961 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 337 "parser.y" /* yacc.c:1646  */
    {MA.precallProcedure((yyvsp[-3].str));}
#line 1967 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 339 "parser.y" /* yacc.c:1646  */
    {}
#line 1973 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 340 "parser.y" /* yacc.c:1646  */
    {}
#line 1979 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 342 "parser.y" /* yacc.c:1646  */
    {MA.addArgument((yyvsp[0].val));}
#line 1985 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 343 "parser.y" /* yacc.c:1646  */
    {MA.addArgument((yyvsp[0].val));}
#line 1991 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 346 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.charLiteral(yylval.chr);}
#line 1997 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 347 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.charCast((yyvsp[-1].val));}
#line 2003 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 348 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.binOp((yyvsp[-2].val),(yyvsp[0].val),&MiddleAsembler::binOpAnd);}
#line 2009 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 349 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.binOp((yyvsp[-2].val),(yyvsp[0].val),&MiddleAsembler::binOpDiv);}
#line 2015 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 350 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.binOp((yyvsp[-2].val),(yyvsp[0].val),&MiddleAsembler::binOpEq);}
#line 2021 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 351 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.binOp((yyvsp[-2].val),(yyvsp[0].val),&MiddleAsembler::binOpGteq);}
#line 2027 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 352 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.binOp((yyvsp[-2].val),(yyvsp[0].val),&MiddleAsembler::binOpGt);}
#line 2033 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 353 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.binOp((yyvsp[-2].val),(yyvsp[0].val),&MiddleAsembler::binOpLteq);}
#line 2039 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 354 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.binOp((yyvsp[-2].val),(yyvsp[0].val),&MiddleAsembler::binOpLt);}
#line 2045 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 355 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.binOp((yyvsp[-2].val),(yyvsp[0].val),&MiddleAsembler::binOpSub);}
#line 2051 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 356 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.binOp((yyvsp[-2].val),(yyvsp[0].val),&MiddleAsembler::binOpMod);}
#line 2057 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 357 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.binOp((yyvsp[-2].val),(yyvsp[0].val),&MiddleAsembler::binOpMult);}
#line 2063 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 358 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.binOp((yyvsp[-2].val),(yyvsp[0].val),&MiddleAsembler::binOpNeq);}
#line 2069 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 359 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.binOp((yyvsp[-2].val),(yyvsp[0].val),&MiddleAsembler::binOpOr);}
#line 2075 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 360 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.binOp((yyvsp[-2].val),(yyvsp[0].val),&MiddleAsembler::binOpAdd);}
#line 2081 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 361 "parser.y" /* yacc.c:1646  */
    {ignoreFunction();}
#line 2087 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 362 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.intLiteral((yyvsp[0].val));}
#line 2093 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 363 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[-1].val);}
#line 2099 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 364 "parser.y" /* yacc.c:1646  */
    {}
#line 2105 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 365 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.unOp((yyvsp[0].val),&MiddleAsembler::unOpNeg);}
#line 2111 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 366 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.unOp((yyvsp[0].val),&MiddleAsembler::unOpNot);}
#line 2117 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 367 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.intCast((yyvsp[-1].val));}
#line 2123 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 368 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.unOp((yyvsp[-1].val),&MiddleAsembler::unOpDecr);}
#line 2129 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 369 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.stringLiteral((yyvsp[0].str));}
#line 2135 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 370 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.unOp((yyvsp[-1].val),&MiddleAsembler::unOpIncr);}
#line 2141 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 373 "parser.y" /* yacc.c:1646  */
    {ignoreFunction();}
#line 2147 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 376 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.getLvalRec((yyvsp[-2].val),(yyvsp[0].str));}
#line 2153 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 377 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.getLvalArr((yyvsp[-3].val),(yyvsp[-1].val));}
#line 2159 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 378 "parser.y" /* yacc.c:1646  */
    {(yyval.val) = MA.getLval((yyvsp[0].str));}
#line 2165 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
    break;


#line 2169 "/home/HookShare/New folder/parser.cpp" /* yacc.c:1646  */
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
#line 380 "parser.y" /* yacc.c:1906  */


void yyerror(const char* s)
{
  std::cerr << s << " at line " << yylineno;
  std::cerr << " near \"" << yytext << "\"" << std::endl;
  throw /*control back to main*/;
}
