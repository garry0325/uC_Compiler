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
#line 2 "compiler_hw3.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
extern int error;

FILE *file;


/* Symbol table function - you can add new function if needed. */
void yyerror(char*);
int lookup_symbol(char*, int);
void create_symbol(int);
void insert_symbol(char*, char*, char*, int, int, char*, char*);
void dump_symbol(int);

char name[64];
char entryType[16];
char dataType[16];
extern int scopeLevel;

void gencode_function();

int localVariableIndex;
int intFloatString;
char addingFunctionType[16];
char funcName[64];

struct symbolTableStruct {
    char name[64];
    char entryType[16];
    char dataType[16];
    int scopeLevel;
    char formalParameters[64];
};

struct indexAndTypeStruct {
	int index;
	char type;
};

struct symbolTableStruct symbolTable[30];
int currentIndex;
int formalPIndex;
char errorMessage[64];

char jFileContent[4096];

struct indexAndTypeStruct checkIndex(char *, int);
void arithmetic(char *, int, char*);
int ifbuffer;
int labelnumber;
int whileCount;
int inLoop;
char arithmeticBuffer[1024];


#line 129 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PRINT = 258,
    SEMICOLON = 259,
    ADD = 260,
    SUB = 261,
    MUL = 262,
    DIV = 263,
    MOD = 264,
    INC = 265,
    DEC = 266,
    MT = 267,
    LT = 268,
    MTE = 269,
    LTE = 270,
    EQ = 271,
    NE = 272,
    ADDASGN = 273,
    SUBASGN = 274,
    MULASGN = 275,
    DIVASGN = 276,
    MODASGN = 277,
    AND = 278,
    OR = 279,
    NOT = 280,
    LB = 281,
    RB = 282,
    LCB = 283,
    RCB = 284,
    LSB = 285,
    RSB = 286,
    COMMA = 287,
    IF = 288,
    ELSE = 289,
    FOR = 290,
    WHILE = 291,
    C_COMMENT = 292,
    CPP_COMMENT = 293,
    I_CONST = 294,
    F_CONST = 295,
    S_CONST = 296,
    INT = 297,
    FLOAT = 298,
    BOOL = 299,
    STRING = 300,
    VOID = 301,
    TR = 302,
    FA = 303,
    RET = 304,
    ID = 305,
    ASGN = 306
  };
#endif
/* Tokens.  */
#define PRINT 258
#define SEMICOLON 259
#define ADD 260
#define SUB 261
#define MUL 262
#define DIV 263
#define MOD 264
#define INC 265
#define DEC 266
#define MT 267
#define LT 268
#define MTE 269
#define LTE 270
#define EQ 271
#define NE 272
#define ADDASGN 273
#define SUBASGN 274
#define MULASGN 275
#define DIVASGN 276
#define MODASGN 277
#define AND 278
#define OR 279
#define NOT 280
#define LB 281
#define RB 282
#define LCB 283
#define RCB 284
#define LSB 285
#define RSB 286
#define COMMA 287
#define IF 288
#define ELSE 289
#define FOR 290
#define WHILE 291
#define C_COMMENT 292
#define CPP_COMMENT 293
#define I_CONST 294
#define F_CONST 295
#define S_CONST 296
#define INT 297
#define FLOAT 298
#define BOOL 299
#define STRING 300
#define VOID 301
#define TR 302
#define FA 303
#define RET 304
#define ID 305
#define ASGN 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 68 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char* string;
    int b_val;
    int v_val;

#line 279 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 296 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   509

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,     2,     2,     2,    52,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,     2,
       2,     2,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    55,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    56,     2,    53,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   108,   108,   124,   131,   132,   133,   134,   135,   140,
     141,   142,   144,   162,   188,   189,   190,   191,   195,   196,
     197,   198,   199,   200,   204,   208,   209,   213,   217,   224,
     225,   228,   235,   239,   244,   248,   252,   256,   263,   265,
     269,   276,   277,   281,   282,   286,   287,   291,   292,   296,
     297,   301,   302,   306,   308,   331,   332,   333,   334,   335,
     336,   340,   341,   345,   353,   361,   362,   366,   367,   368,
     369,   370,   375,   381,   382,   392,   405,   406,   410,   416,
     420,   421,   422,   423,   424,   425,   426,   430,   431,   437,
     438,   442,   443,   447,   448,   452,   453,   457,   473,   474,
     478,   493,   503,   504,   505,   506,   510,   516,   534,   549,
     573,   589,   606,   628,   629,   645,   669,   693,   709,   710,
     714,   715,   719
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "SEMICOLON", "ADD", "SUB",
  "MUL", "DIV", "MOD", "INC", "DEC", "MT", "LT", "MTE", "LTE", "EQ", "NE",
  "ADDASGN", "SUBASGN", "MULASGN", "DIVASGN", "MODASGN", "AND", "OR",
  "NOT", "LB", "RB", "LCB", "RCB", "LSB", "RSB", "COMMA", "IF", "ELSE",
  "FOR", "WHILE", "C_COMMENT", "CPP_COMMENT", "I_CONST", "F_CONST",
  "S_CONST", "INT", "FLOAT", "BOOL", "STRING", "VOID", "TR", "FA", "RET",
  "ID", "ASGN", "'&'", "'~'", "'!'", "'^'", "'|'", "'?'", "':'", "$accept",
  "primary_expression", "constant", "postfix_expression",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "declaration", "declaration_specifiers", "type",
  "declarator", "parameter_list", "parameter_declaration", "statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "selection_statement2",
  "elseifes", "elseifesss", "iteration_statement", "whilehead",
  "while_statement", "jump_statement", "print_statement",
  "function_statement_semicolon", "function_statement", "program",
  "external_declaration", "function_definition", YY_NULLPTR
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
     305,   306,    38,   126,    33,    94,   124,    63,    58
};
# endif

#define YYPACT_NINF -103

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-103)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     341,  -103,  -103,  -103,  -103,  -103,  -103,    15,   341,    39,
    -103,  -103,    41,     4,     8,  -103,  -103,  -103,  -103,    -1,
    -103,   113,   104,   134,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,    18,  -103,   -38,     0,  -103,     3,  -103,  -103,  -103,
    -103,   389,   389,  -103,     7,    14,  -103,    62,   299,  -103,
    -103,  -103,   323,  -103,    69,  -103,   389,  -103,   109,    81,
    -103,  -103,  -103,     9,    49,    51,    47,    -5,  -103,  -103,
       5,  -103,   101,  -103,  -103,   186,  -103,  -103,  -103,    10,
    -103,    71,    10,  -103,  -103,  -103,   125,  -103,  -103,  -103,
     341,   118,  -103,   145,  -103,  -103,   439,   254,  -103,   152,
     160,  -103,  -103,  -103,  -103,  -103,   366,  -103,   455,  -103,
     159,   159,   159,   159,   159,   159,  -103,   144,   439,  -103,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     439,  -103,   439,     4,  -103,  -103,   138,   439,  -103,  -103,
    -103,   158,   167,   232,    42,   305,   305,  -103,  -103,  -103,
     168,   174,   299,  -103,   198,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,    16,  -103,  -103,  -103,   109,   109,  -103,     9,
      49,    51,    47,   -14,  -103,   238,   169,    10,    73,   200,
     201,   439,  -103,   321,   371,  -103,  -103,  -103,  -103,   389,
     182,  -103,   238,    10,  -103,  -103,  -103,  -103,    10,    79,
      10,    88,  -103,   439,  -103,  -103,  -103,    10,  -103,    10,
     183,  -103,  -103,  -103
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    67,    68,    70,    69,    71,   121,     0,    66,     0,
     118,   120,     0,    72,     0,    65,     1,   119,    72,     0,
      63,     0,     0,     0,   122,    73,     4,     5,     6,     7,
       8,     0,    75,    79,     0,    76,     0,    93,    20,    21,
      19,     0,     0,    87,     0,     0,   106,     0,     2,    18,
      22,    23,     9,     3,    14,    24,     0,    25,    29,    32,
      33,    38,    41,    43,    45,    47,    49,    51,    53,    61,
       0,    91,     0,    92,    80,     0,    89,    81,    82,     0,
      83,     0,     0,    84,    85,    86,     0,    64,    78,    74,
       0,     0,     2,     9,    15,    16,     0,     0,   108,     0,
       0,    59,    60,    56,    57,    58,     0,    55,     0,    12,
       0,     0,     0,     0,     0,     0,    13,     0,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,    88,    90,     0,     0,   101,   113,
      77,     0,     0,     2,     0,     0,     0,   109,   110,   117,
       0,     0,     2,    54,     0,    35,    34,    37,    36,    39,
      40,    11,     0,    26,    27,    28,    30,    31,    42,    44,
      46,    48,    50,     0,    62,     0,     0,     0,     0,     0,
       0,     0,    97,     0,     0,   115,   116,   114,    10,     0,
       0,    95,     0,     0,    99,   107,   111,   112,     0,     0,
       0,     0,    52,     0,    96,    98,   104,     0,   102,     0,
      38,   105,   103,   100
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,    12,   -16,  -103,    52,  -103,   -49,    19,  -103,  -103,
      13,    86,    87,    85,    89,    91,  -103,    29,  -102,   175,
     -95,   -19,     2,  -103,   212,  -103,   147,   -79,   233,  -103,
     171,   -69,  -103,  -103,  -103,    80,  -103,  -103,  -103,  -103,
    -103,  -103,   149,  -103,   246,  -103
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,   181,
      70,     6,    72,     8,    14,    34,    35,    73,    74,    75,
      76,    77,    78,    79,   176,   177,    80,    81,    82,    83,
      84,    85,    86,     9,    10,    11
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     136,   144,     7,   138,    71,    31,   153,   119,    20,   131,
      15,     7,    88,    36,    37,    38,    39,    40,   132,   129,
      41,    42,    87,   162,    33,    22,    25,    89,   146,    91,
     174,   100,    90,    96,    22,   173,    23,   132,    23,    16,
      97,    12,   178,    44,   189,    45,    46,   188,   132,    26,
      27,    28,   130,    93,    93,    21,    71,    29,    30,    47,
      48,   125,    49,    50,    51,    13,    98,    12,    93,   182,
     128,   163,   164,   165,   132,   142,   183,   184,   145,   153,
     116,     1,     2,     3,     4,     5,   123,   124,   199,   201,
     151,    18,    33,    94,    95,   117,   191,   137,   194,   118,
     195,    26,    27,    28,   126,   132,   207,   127,   144,    29,
      30,   132,    99,   204,   205,   209,   120,   121,   122,   206,
     132,   208,   155,   156,   157,   158,   159,   160,   211,   139,
     212,    32,    93,    93,    93,    93,    93,    36,    37,    38,
      39,    40,   166,   167,    41,    42,     1,     2,     3,     4,
       5,   133,    26,    27,    28,   109,   147,    26,    27,    28,
      29,    30,    23,    43,   148,    29,    30,    44,   141,    45,
      46,   161,   175,    26,    27,    28,     1,     2,     3,     4,
       5,    29,    30,    47,    48,   179,    49,    50,    51,    36,
      37,    38,    39,    40,   180,   185,    41,    42,    26,    27,
      28,   186,   187,   192,   196,   197,    29,    30,   203,    92,
     213,   168,   170,   169,    23,   134,   210,   171,   202,    44,
     172,    45,    46,   108,    19,    26,    27,    28,     1,     2,
       3,     4,     5,    29,    30,    47,    48,   140,    49,    50,
      51,    36,    37,    38,    39,    40,   135,    24,    41,    42,
     101,   102,   103,   104,   105,    17,   193,   154,    37,    38,
      39,    40,     0,     0,    41,    42,    23,     0,     0,     0,
       0,   190,     0,    45,    46,     0,     0,    26,    27,    28,
       0,     0,     0,   107,     0,    29,    30,    47,    48,     0,
      49,    50,    51,    26,    27,    28,     1,     2,     3,     4,
       5,    29,    30,     0,   143,     0,    49,    50,    51,    37,
      38,    39,    40,     0,     0,    41,    42,   101,   102,   103,
     104,   105,     0,     0,     0,   106,    38,    39,    40,     0,
       0,    41,    42,   109,     0,   110,   111,   112,   113,   114,
     115,     0,     0,     0,    26,    27,    28,     0,   198,     0,
     107,     0,    29,    30,     0,   143,     0,    49,    50,    51,
      26,    27,    28,     0,     0,     0,     0,     0,    29,    30,
       0,   143,     0,    49,    50,    51,    38,    39,    40,     0,
       0,    41,    42,     1,     2,     3,     4,     5,     0,     0,
       0,     0,     0,   149,    38,    39,    40,     0,   200,    41,
      42,     0,     0,     0,     0,    26,    27,    28,     0,     0,
      26,    27,    28,    29,    30,     0,   150,     0,    29,    30,
       0,   143,     0,    49,    50,    51,     0,     0,    26,    27,
      28,     0,     0,     0,     0,     0,    29,    30,     0,    92,
       0,    49,    50,    51,    38,    39,    40,     0,     0,    41,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40,     0,     0,    41,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    27,
      28,     0,     0,     0,     0,     0,    29,    30,     0,   143,
       0,    49,    50,    51,    26,    27,    28,     0,     0,     0,
       0,     0,    29,    30,     0,   152,     0,    49,    50,    51
};

static const yytype_int16 yycheck[] =
{
      79,    96,     0,    82,    23,    21,   108,    56,     4,     4,
       8,     9,    50,     3,     4,     5,     6,     7,    32,    24,
      10,    11,     4,   118,    22,    26,    27,    27,    97,    26,
     132,    47,    32,    26,    26,   130,    28,    32,    28,     0,
      26,    26,   137,    33,    58,    35,    36,    31,    32,    39,
      40,    41,    57,    41,    42,    51,    75,    47,    48,    49,
      50,    52,    52,    53,    54,    50,     4,    26,    56,    27,
      23,   120,   121,   122,    32,    91,   145,   146,    97,   181,
      11,    42,    43,    44,    45,    46,     5,     6,   183,   184,
     106,    50,    90,    41,    42,    26,   175,    26,   177,    30,
      27,    39,    40,    41,    55,    32,    27,    56,   203,    47,
      48,    32,    50,   192,   193,    27,     7,     8,     9,   198,
      32,   200,   110,   111,   112,   113,   114,   115,   207,     4,
     209,    27,   120,   121,   122,   123,   124,     3,     4,     5,
       6,     7,   123,   124,    10,    11,    42,    43,    44,    45,
      46,    50,    39,    40,    41,    10,     4,    39,    40,    41,
      47,    48,    28,    29,     4,    47,    48,    33,    50,    35,
      36,    27,    34,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    27,    52,    53,    54,     3,
       4,     5,     6,     7,    27,    27,    10,    11,    39,    40,
      41,    27,     4,    34,     4,     4,    47,    48,    26,    50,
      27,   125,   127,   126,    28,    29,   203,   128,   189,    33,
     129,    35,    36,    48,    12,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    90,    52,    53,
      54,     3,     4,     5,     6,     7,    75,    14,    10,    11,
      18,    19,    20,    21,    22,     9,   176,   108,     4,     5,
       6,     7,    -1,    -1,    10,    11,    28,    -1,    -1,    -1,
      -1,    33,    -1,    35,    36,    -1,    -1,    39,    40,    41,
      -1,    -1,    -1,    51,    -1,    47,    48,    49,    50,    -1,
      52,    53,    54,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    -1,    52,    53,    54,     4,
       5,     6,     7,    -1,    -1,    10,    11,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    26,     5,     6,     7,    -1,
      -1,    10,    11,    10,    -1,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    39,    40,    41,    -1,    27,    -1,
      51,    -1,    47,    48,    -1,    50,    -1,    52,    53,    54,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    50,    -1,    52,    53,    54,     5,     6,     7,    -1,
      -1,    10,    11,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    27,     5,     6,     7,    -1,    27,    10,
      11,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,    -1,
      39,    40,    41,    47,    48,    -1,    50,    -1,    47,    48,
      -1,    50,    -1,    52,    53,    54,    -1,    -1,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    50,
      -1,    52,    53,    54,     5,     6,     7,    -1,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     6,     7,    -1,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    50,
      -1,    52,    53,    54,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    50,    -1,    52,    53,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,    44,    45,    46,    80,    81,    82,   102,
     103,   104,    26,    50,    83,    81,     0,   103,    50,    83,
       4,    51,    26,    28,    87,    27,    39,    40,    41,    47,
      48,    61,    27,    81,    84,    85,     3,     4,     5,     6,
       7,    10,    11,    29,    33,    35,    36,    49,    50,    52,
      53,    54,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      79,    80,    81,    86,    87,    88,    89,    90,    91,    92,
      95,    96,    97,    98,    99,   100,   101,     4,    50,    27,
      32,    26,    50,    60,    63,    63,    26,    26,     4,    50,
      61,    18,    19,    20,    21,    22,    26,    51,    78,    10,
      12,    13,    14,    15,    16,    17,    11,    26,    30,    65,
       7,     8,     9,     5,     6,    52,    55,    56,    23,    24,
      57,     4,    32,    50,    29,    89,    86,    26,    86,     4,
      85,    50,    61,    50,    79,    80,    90,     4,     4,    27,
      50,    61,    50,    77,   101,    60,    60,    60,    60,    60,
      60,    27,    79,    65,    65,    65,    66,    66,    70,    71,
      72,    73,    74,    79,    77,    34,    93,    94,    79,    27,
      27,    78,    27,    90,    90,    27,    27,     4,    31,    58,
      33,    86,    34,    94,    86,    27,     4,     4,    27,    79,
      27,    79,    76,    26,    86,    86,    86,    27,    86,    27,
      69,    86,    86,    27
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    61,    61,    61,    62,
      62,    62,    62,    62,    63,    63,    63,    63,    64,    64,
      64,    64,    64,    64,    65,    66,    66,    66,    66,    67,
      67,    67,    68,    69,    69,    69,    69,    69,    70,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    78,    78,    78,    78,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    82,
      82,    82,    83,    83,    83,    83,    84,    84,    85,    85,
      86,    86,    86,    86,    86,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    90,    91,    91,    92,    93,    93,
      94,    95,    95,    95,    95,    95,    96,    97,    98,    98,
      98,    99,    99,   100,   100,   101,   101,   101,   102,   102,
     103,   103,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     2,     2,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       3,     3,     1,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       2,     1,     1,     1,     2,     4,     5,     4,     3,     2,
       5,     2,     6,     7,     6,     7,     1,     4,     2,     3,
       3,     5,     5,     2,     4,     4,     4,     3,     1,     2,
       1,     1,     3
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
#line 108 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	(yyval.string) = (yyvsp[0].string);
    	if(lookup_symbol((yyvsp[0].string), -2) == 0) {
    		strcpy(errorMessage, "\0");
    		strcpy(errorMessage, "Undeclared variable ");
    		strcat(errorMessage, (yyvsp[0].string));
    		yyerror(errorMessage);
    		}
    		
    	// check if is function
    	struct indexAndTypeStruct temp;
    	temp = checkIndex((yyvsp[0].string), -2);
    	if(temp.index != -3) {	// is a function name
    		strcpy(funcName, (yyvsp[0].string));
    		}
    	}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 124 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	
    }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 131 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); intFloatString = 0; }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 132 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); intFloatString = 1; }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 133 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); intFloatString = 2; }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 140 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 144 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	arithmetic((yyvsp[-1].string), 0, "1");
    	fprintf(file, "%s", arithmeticBuffer);
    	strcpy(arithmeticBuffer, "");
    	
    	struct indexAndTypeStruct temp;
    	temp = checkIndex((yyvsp[-1].string), scopeLevel - inLoop);
    	if(temp.index == -1) {
    		fprintf(file, "\tputstatic compiler_hw3/%s %c\n", (yyvsp[-1].string), temp.type);
    		}
    	else {
    		switch(temp.type) {
    				case 'I': fprintf(file, "\tistore %d\n", temp.index); break;
    				case 'F': fprintf(file, "\tfstore %d\n", temp.index); break;
    				default: break;
    				}
    		}
    	}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 162 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	arithmetic((yyvsp[-1].string), 1, "1");

    	fprintf(file, "%s", arithmeticBuffer);
    	strcpy(arithmeticBuffer, "");
    	struct indexAndTypeStruct temp;
    	temp = checkIndex((yyvsp[-1].string), scopeLevel - inLoop);
    	if(temp.index == -1) {
    		fprintf(file, "\tputstatic compiler_hw3/%s %c\n", (yyvsp[-1].string), temp.type);
    		}
    	else {
    		switch(temp.type) {
    				case 'I': fprintf(file, "\tistore %d\n", temp.index); break;
    				case 'F': fprintf(file, "\tfstore %d\n", temp.index); break;
    				default: break;
    				}
    		}
    	}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 188 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 189 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 190 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 191 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 204 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 208 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 209 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	arithmetic((yyvsp[-2].string), 2, (yyvsp[0].string));
    	(yyval.string) = "done";
    	}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 213 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	arithmetic((yyvsp[-2].string), 3, (yyvsp[0].string));
    	(yyval.string) = "done";
    	}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 217 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	arithmetic((yyvsp[-2].string), 4, (yyvsp[0].string));
    	(yyval.string) = "done";
    	}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 224 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 225 "compiler_hw3.y" /* yacc.c:1646  */
    {
    		arithmetic((yyvsp[-2].string), 0, (yyvsp[0].string));
    	}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 228 "compiler_hw3.y" /* yacc.c:1646  */
    {
	    	fprintf(file, "sub");
    		arithmetic((yyvsp[-2].string), 1, (yyvsp[0].string));
    	}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 244 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	arithmetic((yyvsp[-2].string), 5, (yyvsp[0].string));
    	ifbuffer = 2;
    	}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 248 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	arithmetic((yyvsp[-2].string), 5, (yyvsp[0].string));
    	ifbuffer = 3;
    	}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 252 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	arithmetic((yyvsp[-2].string), 5, (yyvsp[0].string));
    	ifbuffer = 4;
    	}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 256 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	arithmetic((yyvsp[-2].string), 5, (yyvsp[0].string));
    	ifbuffer = 5;
    	}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 265 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	arithmetic((yyvsp[-2].string), 5, (yyvsp[0].string));
    	ifbuffer = 0;
    	}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 269 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	arithmetic((yyvsp[-2].string), 5, (yyvsp[0].string));
    	ifbuffer = 1;
    	}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 308 "compiler_hw3.y" /* yacc.c:1646  */
    {	// lhs of the '='
    	// first check 
    	// check if the variable is in the table
    	fprintf(file, "%s", arithmeticBuffer);
    	strcpy(arithmeticBuffer, "");
    	
    	struct indexAndTypeStruct temp;
    	temp = checkIndex((yyvsp[-2].string), scopeLevel - inLoop);
    	if(temp.index == -1) {
    		fprintf(file, "\tputstatic compiler_hw3/%s %c\n", (yyvsp[-2].string), temp.type);
    		}
    	else {
    		switch(temp.type) {
    				case 'I': fprintf(file, "\tistore %d\n", temp.index); break;
    				case 'F': fprintf(file, "\tfstore %d\n", temp.index); break;
    				default: break;
    				}
    		}
    }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 345 "compiler_hw3.y" /* yacc.c:1646  */
    {  // meet regular declaration
    	insert_symbol((yyvsp[-1].string), "variable", dataType, scopeLevel, 0, NULL, NULL);
    	strcpy(name, "\0");
    	strcpy(dataType, "\0");
    	
    	//
    	}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 353 "compiler_hw3.y" /* yacc.c:1646  */
    {  // meet regular declaration // 'constant' was changed from 'assignment_expression'
    	insert_symbol((yyvsp[-3].string), "variable", dataType, scopeLevel, 0, NULL, (yyvsp[-1].string));
    	strcpy(name, "\0");
    	strcpy(dataType, "\0");
		}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 366 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy(dataType, (yyvsp[0].string)); }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 367 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy(dataType, (yyvsp[0].string)); }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 368 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy(dataType, (yyvsp[0].string)); }
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 369 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy(dataType, (yyvsp[0].string)); }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 370 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy(dataType, (yyvsp[0].string)); }
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 375 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	(yyval.string) = (yyvsp[0].string);
    	insert_symbol((yyvsp[0].string), "function", dataType, -3, 0, NULL, NULL);
    	strcpy(dataType, "\0");
    	formalPIndex = currentIndex;
    }
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 381 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[-1].string); }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 382 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	char type = 'I';
    	if(strcmp(addingFunctionType, "float") == 0)
    		type = 'F';
    	else if(strcmp(addingFunctionType, "void") == 0)
    		type = 'V';
    	fprintf(file, ")%c\n", type);
    	fprintf(file, ".limit stack 50\n"
    					".limit locals 50\n");
    	}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 392 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	char type = 'I';
    	if(strcmp((yyvsp[-2].string), "main") != 0) {
			if(strcmp(addingFunctionType, "float") == 0)
				type = 'F';
			fprintf(file, "V)%c\n", type);
			fprintf(file, ".limit stack 50\n"
    						".limit locals 50\n");
    		}
    	}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 410 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	insert_symbol((yyvsp[0].string), "parameter", dataType, 1, 0, NULL, NULL);
    	insert_symbol(NULL, NULL, NULL, -1, 1, dataType, NULL);
    	strcpy(name, "\0");
    	strcpy(dataType, "\0");
    	}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 431 "compiler_hw3.y" /* yacc.c:1646  */
    {
	dump_symbol(scopeLevel+1);
	}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 457 "compiler_hw3.y" /* yacc.c:1646  */
    {
		labelnumber = 0;
		switch(ifbuffer) {
			case 0:	fprintf(file, "\tifne Label_%d\n", labelnumber); break;
			case 1: fprintf(file, "\tifeq Label_%d\n", labelnumber); break;
			case 2: fprintf(file, "\tifge Label_%d\n", labelnumber); break;
			case 3: fprintf(file, "\tifle Label_%d\n", labelnumber); break;
			case 4: fprintf(file, "\tifgt Label_%d\n", labelnumber); break;
			case 5: fprintf(file, "\tiflt Label_%d\n", labelnumber); break;
			default: break;
			}
		labelnumber = labelnumber + 1;
		}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 478 "compiler_hw3.y" /* yacc.c:1646  */
    {
		switch(ifbuffer) {
			case 0:	fprintf(file, "\tifne Label_%d\n", labelnumber); break;
			case 1: fprintf(file, "\tifeq Label_%d\n", labelnumber); break;
			case 2: fprintf(file, "\tifge Label_%d\n", labelnumber); break;
			case 3: fprintf(file, "\tifle Label_%d\n", labelnumber); break;
			case 4: fprintf(file, "\tifgt Label_%d\n", labelnumber); break;
			case 5: fprintf(file, "\tiflt Label_%d\n", labelnumber); break;
			default: break;
			}
		labelnumber = labelnumber + 1;
		}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 493 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	fprintf(file, "\tgoto LABEL_BEGIN%d\n", whileCount);
    	fprintf(file, "LABEL_FALSE%d:\n", whileCount);
    	fprintf(file, "\tgoto EXIT_%d\n", whileCount);
    	fprintf(file, "EXIT_%d:\n", whileCount);
    	
    	inLoop = 0;
    	whileCount = whileCount + 1;
    	}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 510 "compiler_hw3.y" /* yacc.c:1646  */
    {
		fprintf(file, "LABEL_BEGIN%d:\n", whileCount);
		}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 516 "compiler_hw3.y" /* yacc.c:1646  */
    {
		switch(ifbuffer) {
			case 0: fprintf(file, "\tifeq LABEL_TRUE%d\n", whileCount); break;
			case 1: fprintf(file, "\tifne LABEL_TRUE%d\n", whileCount); break;
			case 2: fprintf(file, "\tiflt LABEL_TRUE%d\n", whileCount); break;
			case 3: fprintf(file, "\tifgt LABEL_TRUE%d\n", whileCount); break;
			case 4: fprintf(file, "\tifle LABEL_TRUE%d\n", whileCount); break;
			case 5: fprintf(file, "\tifge LABEL_TRUE%d\n", whileCount); break;
			default: break;
			}
		fprintf(file, "\tgoto LABEL_FALSE%d\n", whileCount);
		fprintf(file, "LABEL_TRUE%d:\n", whileCount);
		
		inLoop = 1;
		}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 534 "compiler_hw3.y" /* yacc.c:1646  */
    {
    /*
    	if(strcmp(addingFunctionType, "int") == 0)
	    	fprintf(file, "\tireturn\n");
	    else if(strcmp(addingFunctionType, "float") == 0)
			fprintf(file, "\tfreturn\n");
		else if(strcmp(addingFunctionType, "void") == 0)
			fprintf(file, "\treturn\n");
		else if(strcmp(addingFunctionType, "bool") == 0)
			fprintf(file, "\tireturn\n");
		else fprintf(file, "\treturn\n");*/
		
		fprintf(file, "\treturn\n");
		fprintf(file, ".end method\n");
    	}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 549 "compiler_hw3.y" /* yacc.c:1646  */
    {	// RET expression SEMICOLON
    	struct indexAndTypeStruct temp;
    	temp = checkIndex((yyvsp[-1].string), scopeLevel - inLoop);
    	
    	if(temp.index == -1) { // return a global variable
    		fprintf(file, "\tgetstatic compiler_hw3/%s\n", (yyvsp[-1].string));
    		}
    	else {
    		if(strcmp(addingFunctionType, "int") == 0)
    			fprintf(file, "\tiload %d\n", temp.index);
    		else if(strcmp(addingFunctionType, "float") == 0)
    			fprintf(file, "\tfload %d\n", temp.index);
    		else if(strcmp(addingFunctionType, "bool") == 0)
    			fprintf(file, "\tiload %d\n", temp.index);
    		}
    	if(strcmp(addingFunctionType, "int") == 0)
    		fprintf(file, "\tireturn\n");
    	else if(strcmp(addingFunctionType, "float") == 0)
    		fprintf(file, "\tfreturn\n");
    	else if(strcmp(addingFunctionType, "bool") == 0)
    		fprintf(file, "\tireturn\n");
    		
    	fprintf(file, ".end method\n");
    	}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 573 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	fprintf(file, "\tldc %s\n", (yyvsp[-1].string));
    	if(intFloatString == 0)
    		fprintf(file, "\tireturn\n");
    	else if(intFloatString == 1)
    		fprintf(file, "\tfreturn\n");
    	else if(intFloatString == 2)
    		fprintf(file, "\tireturn\n");
    		
    	fprintf(file, ".end method\n");
    	
    	intFloatString = -1;
    	}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 589 "compiler_hw3.y" /* yacc.c:1646  */
    {
		struct indexAndTypeStruct temp;
		temp = checkIndex((yyvsp[-2].string), scopeLevel - inLoop);
    	if(temp.index == -1) {
    		fprintf(file, "\tgetstatic compiler_hw3/%s %c\n", (yyvsp[-2].string), temp.type);
    		}
    	else {
    		switch(temp.type) {
    				case 'I': fprintf(file, "\tiload %d\n", temp.index); break;
    				case 'F': fprintf(file, "\tfload %d\n", temp.index); break;
    				default: break;
    				}
    		}
    	fprintf(file, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
    					"\tswap\n"
    					"\tinvokevirtual java/io/PrintStream/println(%c)V\n", temp.type);				
	}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 606 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(intFloatString == 2)
			fprintf(file, "\tldc \"%s\"\n", (yyvsp[-2].string));
		else
			fprintf(file, "\tldc %s\n", (yyvsp[-2].string));
		
		char append[100];
		if(intFloatString == 2)
			strcpy(append, "Ljava/lang/String;");
		else if(intFloatString == 1)
			strcpy(append, "F");
		else if(intFloatString == 0)
			strcpy(append, "I");
		fprintf(file, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
    					"\tswap\n"
    					"\tinvokevirtual java/io/PrintStream/println(%s)V\n",append);
    					
    	intFloatString = -1;
	}
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 629 "compiler_hw3.y" /* yacc.c:1646  */
    {
		struct indexAndTypeStruct temp;
		temp = checkIndex((yyvsp[-3].string), scopeLevel - inLoop);
		if(temp.index == -2) {	// global
			fprintf(file, "\tputstatic compiler_hw3/%s %c\n", (yyvsp[-3].string), temp.type);
		}
		else {
			if(temp.type == 'I')
				fprintf(file, "\tistore %d\n", temp.index);
			else if(temp.type == 'F')
				fprintf(file, "\tfstore %d\n", temp.index);
			}
		}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 645 "compiler_hw3.y" /* yacc.c:1646  */
    {	// ID LB expression RB
		if(lookup_symbol((yyvsp[-3].string), -3) == 0) {
			strcpy(errorMessage, "\0");
			strcpy(errorMessage, "Undeclared function ");
			strcat(errorMessage, (yyvsp[-3].string));
			yyerror(errorMessage);
			}
		else {
			struct indexAndTypeStruct temp;
			temp = checkIndex((yyvsp[-1].string), scopeLevel - inLoop);
			if(temp.index == -1)
				fprintf(file, "\tgetstatic compiler_hw3/%s %c\n", (yyvsp[-1].string), temp.type);
			else {
				if(temp.type == 'I')
					fprintf(file, "\tiload %d\n", temp.index);
				else if(temp.type == 'F')
					fprintf(file, "\tfload %d\n", temp.index);
				}
				
			char t = temp.type;
			temp = checkIndex((yyvsp[-3].string), -2);
			fprintf(file, "\tinvokestatic compiler_hw3/%s(%c)%c\n", (yyvsp[-3].string), t, temp.type);
			}
		}
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 669 "compiler_hw3.y" /* yacc.c:1646  */
    {	// ID LB expression RB
		if(lookup_symbol((yyvsp[-3].string), -3) == 0) {
			strcpy(errorMessage, "\0");
			strcpy(errorMessage, "Undeclared function ");
			strcat(errorMessage, (yyvsp[-3].string));
			yyerror(errorMessage);
			}
		else {
			fprintf(file, "\tldc %s\n", (yyvsp[-1].string));
			char t;
			switch(intFloatString) {
				case 0: t = 'I'; break;
				case 1: t = 'F'; break;
				case 2: t = 'I'; break;
				default: break;
				}
				
			struct indexAndTypeStruct temp;
			temp = checkIndex((yyvsp[-3].string), -2);
			fprintf(file, "\tinvokestatic compiler_hw3/%s(%c)%c\n", (yyvsp[-3].string), t, temp.type);
			
			intFloatString = -1;
			}
		}
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 693 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(lookup_symbol((yyvsp[-2].string), -3) == 0) {
			strcpy(errorMessage, "\0");
			strcpy(errorMessage, "Undeclared function ");
			strcat(errorMessage, (yyvsp[-2].string));
			yyerror(errorMessage);
			}
		else {
			struct indexAndTypeStruct temp;
			temp = checkIndex((yyvsp[-2].string), -2);
			fprintf(file, "\tinvokevirtual compiler_hw3/%s(V)%c\n", (yyvsp[-2].string), temp.type);
			}
		}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 714 "compiler_hw3.y" /* yacc.c:1646  */
    {  }
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 719 "compiler_hw3.y" /* yacc.c:1646  */
    {
    	localVariableIndex = 0;
    	}
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2275 "y.tab.c" /* yacc.c:1646  */
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
#line 725 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char** argv)
{   
	error = 0;
	yylineno = 1;
	printf("%d: ", yylineno);
	
	scopeLevel = 0;
	
	currentIndex = -1;
	formalPIndex = -1;
    create_symbol(0);
    
    // new to hw3
    file = fopen("compiler_hw3.j", "w");
    
    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");
                    //".method public static main([Ljava/lang/String;)V\n");
	
	// new to hw3
	localVariableIndex = 0;
	intFloatString = -1;
	whileCount = 0;
	inLoop = 0;
	strcpy(arithmeticBuffer, "");

	int result;
	result = yyparse();
	if(!result) {
		dump_symbol(0);
		printf("\n\nTotal lines: %d \n", yylineno);
		}
		
	fclose(file);
	
    return 0;
}

void yyerror(char *s)
{
    printf("\n\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n| Unmatched token: %s", yytext);
    printf("\n|-----------------------------------------------|\n");
    error = 1;
    exit(-1);
}

void create_symbol(int head) {
	for(int i=head; i<30; i++) {
		strcpy(symbolTable[i].name, "\0");
		strcpy(symbolTable[i].entryType, "\0");
		strcpy(symbolTable[i].dataType, "\0");
		symbolTable[i].scopeLevel = -1;
		strcpy(symbolTable[i].formalParameters, "\0");
		}
}

void insert_symbol(char *insertName, char *insertEntryType, char *insertDataType, int insertScopeLevel, int addFunctionParameter, char *parameter, char *value) {
	if(addFunctionParameter) {
		if(strlen(symbolTable[formalPIndex].formalParameters) == 0) {
			strcpy(symbolTable[formalPIndex].formalParameters, parameter);
			}
		else {
			strcat(symbolTable[formalPIndex].formalParameters, ", ");
			strcat(symbolTable[formalPIndex].formalParameters, parameter);
			}
		}
	else {
		int result = lookup_symbol(insertName, insertScopeLevel);
		if(result == 0) {
			currentIndex = currentIndex + 1;
			strcpy(symbolTable[currentIndex].name, insertName);
			strcpy(symbolTable[currentIndex].entryType, insertEntryType);
			strcpy(symbolTable[currentIndex].dataType, insertDataType);
			if(insertScopeLevel == -3) insertScopeLevel = 0;
			symbolTable[currentIndex].scopeLevel = insertScopeLevel;
			
			// add global variable to .j
			char typeDescriptor;
			if(strcmp(insertDataType, "int") == 0) typeDescriptor = 'I';
			else if(strcmp(insertDataType, "float") == 0) typeDescriptor = 'F';
			else if(strcmp(insertDataType, "bool") == 0) typeDescriptor = 'B';
			else if(strcmp(insertDataType, "void") == 0) typeDescriptor = 'V';

			if(strcmp(insertEntryType, "variable") == 0 && insertScopeLevel == 0) {	// assemble global variable
				if(value == NULL)
					fprintf(file, ".field public static %s %c\n", insertName, typeDescriptor);
				else
					fprintf(file, ".field public static %s %c = %s\n", insertName, typeDescriptor, value);
				}
			else if(strcmp(insertEntryType, "function") == 0 && strcmp(insertName, "main") == 0) {	// assemble main
				fprintf(file, ".method public static main([Ljava/lang/String;)%c\n", typeDescriptor);
				fprintf(file, ".limit stack 50\n.limit locals 50\n");
				
				}
			else if(strcmp(insertEntryType, "variable") == 0 && insertScopeLevel !=0) {	//assemble local variable
				if(value == NULL)
					fprintf(file, "\tldc 0\n");
				else
					fprintf(file, "\tldc %s\n", value);
					
				if(strcmp(insertDataType, "string") == 0)
					fprintf(file, "\tastore %d\n", localVariableIndex);
				else if(strcmp(insertDataType, "int") == 0)
					fprintf(file, "\tistore %d\n", localVariableIndex);
				else if(strcmp(insertDataType, "float") == 0)
					fprintf(file, "\tfstore %d\n", localVariableIndex);
				else if(strcmp(insertDataType, "bool") == 0)
					fprintf(file, "\tistore %d\n", localVariableIndex);
			
				localVariableIndex++;
				}
			else if(strcmp(insertEntryType, "function") == 0) {
				fprintf(file, ".method public static %s(", insertName);
				strcpy(addingFunctionType, insertDataType);
				}
			if(strcmp(insertEntryType, "parameter") == 0) {
				char type;
				if(strcmp(insertDataType, "string") == 0) {
					type = 'I';
					}
				else if(strcmp(insertDataType, "int") == 0) {
					type = 'I';
					}
				else if(strcmp(insertDataType, "float") == 0) {
					type = 'F';
					}
				else if(strcmp(insertDataType, "bool") == 0) {
					type = 'I';
					}
					
				fprintf(file, "%c", type);
				
				localVariableIndex++;
				}				
			}
		else if(result == 1) {
			strcpy(errorMessage, "\0");
			strcat(errorMessage, "Redeclared variable ");
			strcat(errorMessage, insertName);
			yyerror(errorMessage);
			}
		else if(result == 2) {
			strcpy(errorMessage, "\0");
			strcat(errorMessage, "Redeclared function ");
			strcat(errorMessage, insertName);
			yyerror(errorMessage);
			}
		else if(result == 3) {
			strcpy(errorMessage, "\0");
			strcat(errorMessage, "Variable declared with name ");
			strcat(errorMessage, insertName);
			yyerror(errorMessage);
			}
		else if(result == 4) {
			strcpy(errorMessage, "\0");
			strcat(errorMessage, "Function declared with name ");
			strcat(errorMessage, insertName);
			yyerror(errorMessage);
			}
		}
}

int lookup_symbol(char *lookupName, int lookupScopeLevel) {
	int same = 0;
	if(lookupScopeLevel == -3) {	// function name looks for same function or variable names
		for(int i=0; i<30; i++) {
			if(strcmp(symbolTable[i].name, lookupName) == 0) {
				if(strcmp(symbolTable[i].entryType, "function") == 0)
					same = 2;	// function name meets same function name
				else if(strcmp(symbolTable[i].entryType, "variable") == 0)
					same = 3;	// function name meets same variable name
				break;
				}
			}
		}
	else {	
		for(int i=0; i<30; i++) {
			if(strcmp(symbolTable[i].name, lookupName) == 0 && strcmp(symbolTable[i].entryType, "function") == 0 && lookupScopeLevel == 0) {
				same = 4;	// global variable declared with existing function name
				break;
				}
			if(strcmp(symbolTable[i].name, lookupName) == 0 && (symbolTable[i].scopeLevel == lookupScopeLevel || lookupScopeLevel == -2)) {
				same = 1;	// for redeclared variable name
				break;
				}
			}
		}
	return same;
}

void dump_symbol(int scope) {
	int startFrom=-1;
	for(int i=0; i<=currentIndex; i++) {
		if(symbolTable[i].scopeLevel == scope) {
			startFrom = i;
			break;
			}
		}
	if(startFrom == -1) return;

    printf("\n\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");

	for(int i=startFrom; symbolTable[i].scopeLevel == scope; i++) {
		printf("%-10d%-10s%-12s%-10s%-10d%-10s\n", i - startFrom, symbolTable[i].name, symbolTable[i].entryType, symbolTable[i].dataType, symbolTable[i].scopeLevel, symbolTable[i].formalParameters);
		currentIndex = currentIndex - 1;
		
		}
	create_symbol(startFrom);
}

void arithmetic(char *num1, int ari, char *num2) {
		char bu[128], buff[256];
		strcpy(buff, "");
    	int intOrFloat = 0;	// 0 int 1 float
    	
    	
		struct indexAndTypeStruct temp;
    	
    	if(strcmp(num1, "done") != 0) {
			temp = checkIndex(num1, scopeLevel - inLoop);
			if(temp.index == -2) {	// is a number
				if(strstr(num1, ".") != NULL) {	// is a float
					sprintf(bu, "\tldc %s\n", num1);
					intOrFloat = 1;
					}
				else	//is an int
					sprintf(bu, "\tldc %s\n", num1);
				}
			else if(temp.index == -1){	// is a global variable
				sprintf(bu, "\tgetstatic compiler_hw3/%s %c\n", num1, temp.type);
				if(temp.index == 'F')
					intOrFloat = 1;
				}
			else {	// is a local variable
				if(temp.type == 'I')
					sprintf(bu, "\tiload %d\n", temp.index);
				else if(temp.type == 'F') {
					sprintf(bu, "\tfload %d\n", temp.index);
					intOrFloat = 1;
					}
				}
			strcat(buff, bu);
			}
		else {
			strcat(buff, arithmeticBuffer);
			}
		
		
		if(strcmp(num2, "done") != 0) {
			temp = checkIndex(num2, scopeLevel - inLoop);
			if(temp.index == -2) {	// is a number
				if(strstr(num2, ".") != NULL)	// is a float
					sprintf(bu, "\tldc %s\n", num2);
				else{	//is an int
					sprintf(bu, "\tldc %s\n", num2);
					}
				}
			else if(temp.index == -1)	// is a global variable
				sprintf(bu, "\tgetstatic compiler_hw3/%s %c\n", num2, temp.type);
			else {	// is a local variable
				if(temp.type == 'I')
					sprintf(bu, "\tiload %d\n", temp.index);
				else if(temp.type == 'F')
					sprintf(bu, "\tfload %d\n", temp.index);
				}
			strcat(buff, bu);
			}
		else {
			strcat(buff, arithmeticBuffer);
			}
    	
    		
    	char operand[20];
    	if(intOrFloat == 0)
    		strcpy(operand, "i");
		else
			strcpy(operand, "f");
			
		switch(ari) {
			case 0: strcat(operand, "add"); break;
			case 1: strcat(operand, "sub"); break;
			case 2: strcat(operand, "mul"); break;
			case 3: strcat(operand, "div"); break;
			case 4: strcat(operand, "mod"); break;
			case 5: strcat(operand, "sub"); break;
			default: break;
			}
		sprintf(bu, "\t%s\n", operand);
		strcat(buff, bu);
		strcat(arithmeticBuffer, buff);
		return;
}

struct indexAndTypeStruct checkIndex(char *name, int scope) {
	struct indexAndTypeStruct ret;
	int index = -1;
	int matchedName = 0;
	char type = 'n';
	for(int i=0; i<=currentIndex; i++) {
		if((symbolTable[i].scopeLevel == scope && (strcmp(symbolTable[i].entryType, "variable") == 0 || strcmp(symbolTable[i].entryType, "parameter") == 0)) || (strcmp(symbolTable[i].entryType, "function") == 0 && scope == -2)) {
			index = index + 1;
			if(strcmp(symbolTable[i].name, name) == 0) {
				matchedName = 1;
				if(strcmp(symbolTable[i].dataType, "int") == 0)
					type = 'I';
				else if(strcmp(symbolTable[i].dataType, "float") == 0)
					type = 'F';
				else if(strcmp(symbolTable[i].dataType, "string") == 0)
					type = 'I';
				else if(strcmp(symbolTable[i].dataType, "bool") == 0)
					type = 'I';
				else if(strcmp(symbolTable[i].dataType, "void") == 0)
					type = 'V';
				break;
				}
			}
		}
	if(matchedName == 0 && scope != 0) {
		ret = checkIndex(name, 0);
		}
	else {
		if(scope == 0 && matchedName == 1)
			ret.index = -1;
		else if(scope == 0 && matchedName == 0)
			ret.index = -2;
		else if(scope == -2 && matchedName == 0)
			ret.index = -3;
		else
			ret.index = index;
		ret.type = type;
		}
	return ret;
}
