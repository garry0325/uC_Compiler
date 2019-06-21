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
#line 68 "compiler_hw3.y" /* yacc.c:1909  */

    int i_val;
    double f_val;
    char* string;
    int b_val;
    int v_val;

#line 164 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
