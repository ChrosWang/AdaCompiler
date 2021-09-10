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
#line 1 "ada.y" /* yacc.c:339  */

int yylex();
int yyerror(char*);
#include <stdio.h>
#include <string.h>
#include "linkedlist.c"
#include "bintree.c"
#include "record.c"
#include "PatchList.c"
extern int lineno;
extern int instr;
extern int curr_reg;
extern int curr_var;
int proc_size[999];
int proc_i = 0; 
int next_exception = 3;
bool in_exception_part = false; 
int jump_table[999];

#line 86 "y.tab.c" /* yacc.c:339  */

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
    IS = 258,
    BEG = 259,
    END = 260,
    PROCEDURE = 261,
    ID = 262,
    NUMBER = 263,
    TYPE = 264,
    ARRAY = 265,
    RAISE = 266,
    OTHERS = 267,
    RECORD = 268,
    IN = 269,
    OUT = 270,
    RANGE = 271,
    CONSTANT = 272,
    ASSIGN = 273,
    EXCEPTION = 274,
    NULLWORD = 275,
    LOOP = 276,
    IF = 277,
    THEN = 278,
    ELSEIF = 279,
    ELSE = 280,
    EXIT = 281,
    WHEN = 282,
    AND = 283,
    OR = 284,
    EQ = 285,
    NEQ = 286,
    LT = 287,
    GT = 288,
    GTE = 289,
    LTE = 290,
    TICK = 291,
    NOT = 292,
    EXP = 293,
    ARROW = 294,
    OF = 295,
    DOTDOT = 296,
    ENDIF = 297,
    ENDREC = 298,
    ENDLOOP = 299,
    EXITWHEN = 300,
    ACCESS = 301,
    NEW = 302,
    DOTALL = 303
  };
#endif
/* Tokens.  */
#define IS 258
#define BEG 259
#define END 260
#define PROCEDURE 261
#define ID 262
#define NUMBER 263
#define TYPE 264
#define ARRAY 265
#define RAISE 266
#define OTHERS 267
#define RECORD 268
#define IN 269
#define OUT 270
#define RANGE 271
#define CONSTANT 272
#define ASSIGN 273
#define EXCEPTION 274
#define NULLWORD 275
#define LOOP 276
#define IF 277
#define THEN 278
#define ELSEIF 279
#define ELSE 280
#define EXIT 281
#define WHEN 282
#define AND 283
#define OR 284
#define EQ 285
#define NEQ 286
#define LT 287
#define GT 288
#define GTE 289
#define LTE 290
#define TICK 291
#define NOT 292
#define EXP 293
#define ARROW 294
#define OF 295
#define DOTDOT 296
#define ENDIF 297
#define ENDREC 298
#define ENDLOOP 299
#define EXITWHEN 300
#define ACCESS 301
#define NEW 302
#define DOTALL 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "ada.y" /* yacc.c:355  */

    int integer;
    char *var;
    struct LL_node* head;
    struct binary_tree_node* b_node;
    struct address_record* c_record;

#line 230 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 247 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      50,    51,    56,    55,    53,    54,     2,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    49,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    58,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    39,    39,    62,    92,    97,   110,   151,   156,   176,
     179,   181,   225,   265,   267,   269,   272,   274,   276,   277,
     278,   279,   281,   282,   284,   304,   305,   324,   326,   328,
     329,   331,   333,   367,   369,   371,   373,   399,   400,   405,
     569,   570,   571,   589,   597,   599,   602,   604,   607,   609,
     616,   625,   639,   643,   644,   646,   647,   649,   655,   664,
     677,   684,   685,   687,   689,   690,   692,   694,   700,   703,
     717,   720,   769,   778,   781,   794,   797,   811,   820,   822,
     826,   836,   881,   940,   943,   945,   948,   950,   952,   954,
     956,   958,   961,   963,   966,   968,   971,   995,   997,  1025,
    1029,  1034,  1056,  1057,  1062,  1071,  1074
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IS", "BEG", "END", "PROCEDURE", "ID",
  "NUMBER", "TYPE", "ARRAY", "RAISE", "OTHERS", "RECORD", "IN", "OUT",
  "RANGE", "CONSTANT", "ASSIGN", "EXCEPTION", "NULLWORD", "LOOP", "IF",
  "THEN", "ELSEIF", "ELSE", "EXIT", "WHEN", "AND", "OR", "EQ", "NEQ", "LT",
  "GT", "GTE", "LTE", "TICK", "NOT", "EXP", "ARROW", "OF", "DOTDOT",
  "ENDIF", "ENDREC", "ENDLOOP", "EXITWHEN", "ACCESS", "NEW", "DOTALL",
  "';'", "'('", "')'", "':'", "','", "'-'", "'+'", "'*'", "'/'", "'|'",
  "$accept", "program", "main_body", "main_beg", "main_specification",
  "procedure_body", "procedure_begin", "procedure_specification",
  "formal_parameter_part", "parameters", "mode", "type_name",
  "declarative_part", "declarative_part_p", "types", "constant_num",
  "component_list", "component", "objects", "constant",
  "constant_expression", "exceptions", "sequence_of_statements",
  "statement", "opt_assign", "opt_actual_para_part", "expression_list",
  "loop_part", "loop_start", "inside_loop", "loop_statements", "exit_cond",
  "if_statement", "ifcond", "else_if", "then_cond", "else", "endif",
  "condition", "expression", "relation", "simple_expression", "term",
  "factor", "primary", "boolean_operation", "relational_operation",
  "adding_operation", "multiplying_operation", "exception_part",
  "exception_start", "exception_list", "exception_hand", "choice_sequence",
  "identifier_list", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,    59,
      40,    41,    58,    44,    45,    43,    42,    47,   124
};
# endif

#define YYPACT_NINF -99

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-99)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      33,    43,    54,   -99,    71,   -99,   -99,    49,    59,    16,
      69,    76,    37,    94,   -99,    40,    51,   -99,    58,    56,
     -99,    99,   107,   -99,    99,   108,   -99,    92,    49,    49,
      49,    11,   -99,    21,    70,    73,    49,    72,     3,    74,
     -99,     7,   110,    92,   -99,    64,   -99,    92,   -99,   -99,
     -99,   -99,   109,   -99,   -99,    80,    99,    65,   -99,    66,
     122,     7,   113,    83,   -99,   -99,    84,   -99,    12,     7,
       9,   112,    63,    85,    39,    48,   -99,    95,   -99,   131,
     111,   -99,    91,     7,   -99,    57,   -99,   -99,   117,     7,
      65,   100,    93,   -99,    96,   -99,   -99,   103,   130,   -99,
     139,   -99,    92,   -24,    63,     7,    98,   -99,     7,   -99,
      -6,    48,   -99,   -99,   -99,   -99,     7,   -99,   -99,   -99,
     -99,   -99,   -99,     7,   -99,   -99,     9,   -99,   -99,     9,
      12,   101,    26,   111,   -99,   -99,   102,   104,   -99,     7,
     124,   -99,    63,   114,   -99,    99,    19,    65,   -99,   115,
     110,   -99,     7,    63,   -99,    -4,   -99,    85,    39,    48,
     -99,   -99,   -99,   -99,   -99,   -18,   -99,   -99,   -99,   112,
      92,   116,    65,   -99,   -99,    99,   147,    63,   -99,    92,
     149,    92,   -99,   -99,   118,   106,   -99,   119,   -99,   -99,
     117,   -99,   120,   -99,   -99,   139,   -99
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     5,     1,    23,     0,   106,
       0,    23,    10,     0,    21,     0,     0,    33,     0,     0,
       8,     0,     0,    22,     0,     0,     4,    38,    23,    23,
      23,     0,   105,     0,     0,     0,    23,    48,     0,     0,
      52,     0,    97,    38,    40,     0,    41,    38,    19,    18,
      20,    17,     0,    36,    32,     0,     0,     0,     9,    16,
       0,     0,    46,     0,    43,    44,    81,    80,     0,     0,
       0,     0,    67,    68,    70,    73,    75,    79,    98,     0,
       0,    37,     0,     0,    55,     0,    53,    56,    62,     0,
       0,     0,     0,    31,     0,    28,    27,     0,    15,    14,
       0,     7,    38,     0,    50,     0,     0,    42,     0,    77,
       0,    72,    63,    60,    84,    85,     0,    86,    87,    88,
      89,    90,    91,     0,    93,    92,     0,    94,    95,     0,
       0,     0,     0,    96,   100,    58,     0,     0,    54,     0,
      65,    34,    35,     0,    25,    30,     0,     0,    13,    12,
      97,    47,     0,    45,    39,     0,    83,    69,    71,    74,
      76,    78,     3,   103,   104,     0,    99,    57,    51,     0,
      38,     0,     0,    29,    26,     0,     0,    49,    82,    38,
       0,    38,    64,    66,     0,     0,    11,     0,   101,   102,
      62,    59,     0,     6,    61,     0,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -16,
     -99,   -98,    13,   150,   -99,   -84,    17,   -99,   -49,   -99,
     -99,   -99,   -42,   -32,   -99,   -99,   -99,   -99,   -99,   -99,
      78,   -99,   -99,   -99,   -25,    -3,   -99,   -99,   -74,   -57,
      53,    47,   -59,    42,   -60,   -99,   -99,   -99,   -99,    22,
     -99,   -99,    41,   -99,   -21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    27,     4,    11,   102,    12,    25,    34,
     100,    54,    13,    14,    15,    97,    91,    92,    16,    17,
     141,    18,    42,    43,   106,    62,   103,    44,    45,    85,
      86,    87,    46,    47,   140,   113,   171,   184,    71,    72,
      73,    74,    75,    76,    77,   116,   123,   126,   129,    79,
      80,   133,   134,   165,    19
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      32,    81,   149,    35,   104,    88,   143,    93,   109,   136,
      63,   111,   110,    84,    66,    67,    66,    67,    51,    66,
      67,   179,   114,   115,   114,   115,    51,   151,    52,   152,
      53,    55,   142,   163,    56,    94,    52,    57,   164,     1,
     180,    48,    49,    50,    68,   156,    68,   178,   153,    60,
       5,   155,    64,    84,     6,     8,     9,    69,    10,    69,
     150,    70,    69,   174,    37,   169,    20,   159,    38,    21,
     161,    37,    95,    96,     7,    38,    22,    39,    40,    41,
      98,    99,     8,    82,    39,    40,    41,    24,   185,    28,
      82,   114,   115,   124,   125,   177,    93,   196,    26,    37,
      29,   137,    83,    38,   127,   128,     9,    30,    31,    83,
      33,    36,    39,    40,    41,   117,   118,   119,   120,   121,
     122,    58,    61,    65,    94,    59,   101,    89,   182,    78,
      90,   105,   107,   130,   108,   112,   131,   188,   132,   190,
     135,   139,   145,   144,   147,   148,    51,   154,   146,   170,
     162,   167,   187,   168,    35,   172,   189,   192,   183,   186,
     195,    23,   173,   138,   175,   194,   181,   191,   193,   157,
     158,   160,   176,     0,   166
};

static const yytype_int16 yycheck[] =
{
      21,    43,   100,    24,    61,    47,    90,    56,    68,    83,
       7,    70,    69,    45,     7,     8,     7,     8,     7,     7,
       8,    39,    28,    29,    28,    29,     7,    51,    17,    53,
      19,    10,    89,     7,    13,    56,    17,    16,    12,     6,
      58,    28,    29,    30,    37,    51,    37,    51,   105,    36,
       7,   108,    49,    85,     0,     6,     7,    50,     9,    50,
     102,    54,    50,   147,     7,   139,     7,   126,    11,    53,
     130,     7,     7,     8,     3,    11,     7,    20,    21,    22,
      14,    15,     6,    26,    20,    21,    22,    50,   172,    49,
      26,    28,    29,    54,    55,   152,   145,   195,     4,     7,
      49,    44,    45,    11,    56,    57,     7,    49,    52,    45,
       3,     3,    20,    21,    22,    30,    31,    32,    33,    34,
      35,    51,    50,    49,   145,    52,     4,    18,   170,    19,
      50,    18,    49,    38,    50,    23,     5,   179,    27,   181,
      49,    24,    49,    43,    41,    15,     7,    49,    52,    25,
      49,    49,     5,    49,   175,    41,     7,    51,    42,   175,
      40,    11,   145,    85,    49,   190,   169,    49,    49,   116,
     123,   129,   150,    -1,   133
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    60,    61,    63,     7,     0,     3,     6,     7,
       9,    64,    66,    71,    72,    73,    77,    78,    80,   113,
       7,    53,     7,    72,    50,    67,     4,    62,    49,    49,
      49,    52,   113,     3,    68,   113,     3,     7,    11,    20,
      21,    22,    81,    82,    86,    87,    91,    92,    71,    71,
      71,     7,    17,    19,    70,    10,    13,    16,    51,    52,
      71,    50,    84,     7,    49,    49,     7,     8,    37,    50,
      54,    97,    98,    99,   100,   101,   102,   103,    19,   108,
     109,    81,    26,    45,    82,    88,    89,    90,    81,    18,
      50,    75,    76,    77,   113,     7,     8,    74,    14,    15,
      69,     4,    65,    85,    98,    18,    83,    49,    50,   103,
      98,   101,    23,    94,    28,    29,   104,    30,    31,    32,
      33,    34,    35,   105,    54,    55,   106,    56,    57,   107,
      38,     5,    27,   110,   111,    49,    97,    44,    89,    24,
      93,    79,    98,    74,    43,    49,    52,    41,    15,    70,
      81,    51,    53,    98,    49,    98,    51,    99,   100,   101,
     102,   103,    49,     7,    12,   112,   111,    49,    49,    97,
      25,    95,    41,    75,    74,    49,   108,    98,    51,    39,
      58,    94,    81,    42,    96,    74,    68,     5,    81,     7,
      81,    49,    51,    49,    93,    40,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      67,    68,    68,    69,    69,    69,    69,    70,    71,    71,
      71,    71,    72,    72,    73,    73,    73,    74,    74,    75,
      75,    76,    77,    77,    78,    79,    80,    81,    81,    82,
      82,    82,    82,    82,    82,    83,    83,    84,    84,    85,
      85,    86,    87,    88,    88,    89,    89,    90,    90,    91,
      92,    93,    93,    94,    95,    95,    96,    97,    98,    98,
      99,    99,   100,   100,   100,   101,   101,   102,   102,   102,
     103,   103,   103,   103,   104,   104,   105,   105,   105,   105,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   110,
     110,   111,   112,   112,   112,   113,   113
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     8,     1,     2,     9,     1,     2,     3,
       0,     6,     4,     2,     1,     1,     0,     1,     3,     3,
       3,     1,     2,     0,    11,     6,     7,     1,     1,     3,
       2,     1,     3,     1,     5,     1,     3,     2,     0,     4,
       1,     1,     3,     2,     2,     2,     0,     3,     0,     3,
       1,     4,     1,     1,     2,     1,     1,     3,     2,     6,
       3,     5,     0,     1,     2,     0,     1,     1,     1,     3,
       1,     3,     2,     1,     3,     1,     3,     2,     3,     1,
       1,     1,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     1,     2,
       1,     4,     3,     1,     1,     3,     1
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
#line 39 "ada.y" /* yacc.c:1646  */
    {
									printf ("\n*******\nDONE.\n*******\n"); 

									pop();
									FILE * outcode;
							        outcode = fopen("./sample.out", "w");
									for (int i =0; i < instr; i++) {
                                        char snum[5];
                                        sprintf(snum, "%d: ", i);
                                        fprintf(outcode, snum);
                                        char *patcher = (char*)malloc(8 * sizeof(char));
                                        patcher = strstr(output[i], "?");
                                        if (patcher != NULL) {
                                            int content = search_PL(Patch_list, i);
                                            printf("line %d: patch %d\n", i, content);
                                            //sprintf(patcher, "%d", );
                                        }
							        	fprintf(outcode, output[i]);
                                        fflush(outcode);
							    	}

							     	 }
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 65 "ada.y" /* yacc.c:1646  */
    {
                            patch_jump_ex(Patch_list, -3, instr);
                            if ((yyvsp[-2].integer) == 0){
                            if (Patch_list == NULL)
                            {Patch_list = retrieve_PL_ex();}
                            else
                            {toEnd_PL(Patch_list) -> next= retrieve_PL_ex();}
                            pop_PL_ex();
                            printf("Patching exceptions:\n");
                            patch_jump(Patch_list, instr);
                            print_PL(Patch_list);
                          	}
                          	printf("\nPoping scope for %s, so print tree\n", stack_b[count].name); present(stack_b[count-1].root); 
                          							char *temp = (char*)malloc(40 * sizeof(char));
													sprintf(temp, "RETURN: r%d := contents b, 1\n", curr_reg);
													output[instr++] = temp;
													temp = (char*)malloc(40 * sizeof(char));
													sprintf(temp, "b := contents b, 3\n");
													output[instr++] = temp;
													temp = (char*)malloc(40 * sizeof(char));
													sprintf(temp, "pc = r%d\n", curr_reg++);
													output[instr++] = temp;
                                                    add_rear_PL(0, instr);
                                                    add_rear_PL(1, instr+4+proc_size[0]);
                                                    //print_PL(Patch_list);
                          							pop(); }
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 93 "ada.y" /* yacc.c:1646  */
    {add_rear_PL(4, instr);
                        print_PL(Patch_list);
                        push_PL_ex();}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 98 "ada.y" /* yacc.c:1646  */
    {
                        output[instr++] = "b := ?\n"; 
						output[instr++] = "contents b, 0 := ?\n";
						output[instr++] = "contents b, 1 := 4\n";
						output[instr++] = "r1 = 0\n";
                        curr_reg++;
						output[instr++] = "pc := ?\n";
						output[instr++] = "halt\n";
                        push((yyvsp[0].var));
                        printf("\nPushing new scope for %s\n", stack_b[count].name);
                    	}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 113 "ada.y" /* yacc.c:1646  */
    {
                            patch_jump_ex(Patch_list, -3, instr);
                            if ((yyvsp[-2].integer) == 0){
                            if (Patch_list == NULL)
                            {Patch_list = retrieve_PL_ex();}
                            else
                            {toEnd_PL(Patch_list) -> next= retrieve_PL_ex();}
                            pop_PL_ex();
                            printf("Patching exceptions:\n");
                            patch_jump(Patch_list, instr);
                            print_PL(Patch_list);
                            }
                          	int offset; 
    						node* curr_node = search_in_stack((yyvsp[-8].var), &offset);
                            curr_node-> next = (yyvsp[-7].b_node);
                            curr_node-> value = proc_size[proc_i];
                            printf("size of %s is %d", curr_node->symbol, curr_node->value);
                            curr_node->proc_begin = (yyvsp[-4].integer);
                            if (curr_node -> next != NULL) {
                            printf("next of %s is %s\n", curr_node->symbol, curr_node->next->symbol);
                            }
                            printf("\nPoping scope for %s, so print tree\n", stack_b[count].name);
                            present(stack_b[count-1].root);
                            char *temp = (char*)malloc(40 * sizeof(char));
							sprintf(temp, "RETURN: r%d := contents b, 1\n", curr_reg);
							output[instr++] = temp;
							temp = (char*)malloc(40 * sizeof(char));
							sprintf(temp, "b := contents b, 3\n");
							output[instr++] = temp;
							temp = (char*)malloc(40 * sizeof(char));
							sprintf(temp, "pc = r%d\n", curr_reg++);
							output[instr++] = temp;
                            pop();
                            proc_size[proc_i] = 0;
                            proc_i--;

                        }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 152 "ada.y" /* yacc.c:1646  */
    {push_PL_ex();
							(yyval.integer) = instr;
						}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 157 "ada.y" /* yacc.c:1646  */
    {printf("line %d: procedure %s (...)\n", lineno, (yyvsp[0].var));
                        if(recursive_search_local(stack_b[count-1].root, (yyvsp[0].var)) != NULL) {
                            	printf("ERROR: Duplicate IDs!\n");
                            } else {
                                add((yyvsp[0].var));
                                //printf("ADD %s into the tree.\n", $2);
                                int offset;
                                node* curr_node = search_in_stack((yyvsp[0].var), &offset);
                                curr_node = empty_node(curr_node);
                                curr_node->kind = "procedure";
                                //curr_node->next = $3;
                                present(stack_b[count-1].root);
                                //printf("\n");
                            }
                        push((yyvsp[0].var));
                        printf("\nPushing new scope for %s\n", stack_b[count].name);
                        (yyval.var) = (yyvsp[0].var);
                        proc_i++;}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 177 "ada.y" /* yacc.c:1646  */
    {(yyval.b_node) = (yyvsp[-1].b_node);}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 179 "ada.y" /* yacc.c:1646  */
    {(yyval.b_node) = NULL;}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 182 "ada.y" /* yacc.c:1646  */
    {   printf("line %d:", lineno);
                            print((yyvsp[-5].head)); 
                            printf(": %s %s\n", (yyvsp[-3].var), (yyvsp[-2].var));
                            LL_node current;
                            current = (yyvsp[-5].head);
                            node* curr_node;
                            node* previous;
                            node* first;
                            int counter = 0;
                            while(current != NULL) {
                            	if(recursive_search_local(stack_b[count-1].root, current->data) != NULL) {
                            		printf("ERROR: Duplicate IDs!\n");
                            		current = current -> next;
                            		continue;
                            	}

                                add(current->data);
                                //printf("ADD %s into the tree %s.\n", current->data, stack_b[count].name);
                                int offset;
                                curr_node = search_in_stack(current->data, &offset);
                                if (counter == 0) {
                                    first = curr_node;
                                }

                                curr_node = empty_node(curr_node);
                                curr_node->kind = "parameters";
                                curr_node->mode = (yyvsp[-3].var);
                                curr_node->parent_type = search_in_stack((yyvsp[-2].var), &offset);
                                if (counter > 0) {
                                    previous->next = curr_node;
                                    printf("next of %s is %s\n", previous->symbol, previous->next->symbol);
                                }
                                //present(stack_b[count-1].root);
                                //printf("\n");
                                previous = curr_node;
                                current = current -> next;
                                counter++;
                          }

                          curr_node->next = (yyvsp[0].b_node);
                          printf("next of %s is %s\n", curr_node->symbol, curr_node->next->symbol);
                          (yyval.b_node) = first;
                        }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 226 "ada.y" /* yacc.c:1646  */
    {   printf("line %d:", lineno);
                            print((yyvsp[-3].head)); 
                            printf(": %s %s\n", (yyvsp[-1].var), (yyvsp[0].var));
                            LL_node current; 
                            node* curr_node;
                            node* previous;
                            node* first;
                            current = (yyvsp[-3].head);
                            int counter = 0;
                            while(current != NULL) {
                            	if(recursive_search_local(stack_b[count-1].root, current->data) != NULL) {
                            		printf("ERROR: Duplicate IDs!\n");
                            		current = current -> next;
                            		continue;
                            	}
                                add(current->data);
                                //printf("ADD %s into the tree.\n", current->data);
                                int offset;
                                curr_node = search_in_stack(current->data, &offset);
                                if (counter == 0) {
                                    first = curr_node;
                                }
                                curr_node = empty_node(curr_node);
                                curr_node->kind = "parameters";
                                curr_node->mode = (yyvsp[-1].var);
                                curr_node->parent_type = search_in_stack((yyvsp[0].var), &offset);
                                if (counter > 0) {
                                    previous->next = curr_node;
                                    printf("next of %s is %s\n", previous->symbol, previous->next->symbol);
                                }
                                //present(stack_b[count-1].root);
                                previous = curr_node;
                                current = current -> next;
                                counter++;
                          }
                          (yyval.b_node) = first;
                              
                        }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 266 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "in out";}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 268 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "out";}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 270 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "in";}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 272 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "";}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 274 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = (yyvsp[0].var);}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 285 "ada.y" /* yacc.c:1646  */
    {   printf("line %d: type %s is array (%d..%d) of %s\n", lineno, (yyvsp[-9].var), (yyvsp[-5].integer), (yyvsp[-3].integer), (yyvsp[0].var));
                            if(recursive_search_local(stack_b[count-1].root, (yyvsp[-9].var)) != NULL) {
                            	printf("ERROR: Duplicate IDs!\n");
                            } else {
                                add((yyvsp[-9].var));
                                //printf("ADD %s into the tree.\n", $2);
                                int offset;
                                node* curr_node = search_in_stack((yyvsp[-9].var), &offset);
                                curr_node = empty_node(curr_node);
                                curr_node->kind = "type (array)";
                                curr_node->component_type = search_in_stack((yyvsp[0].var), &offset);
                                curr_node->upper = (yyvsp[-3].integer);
                                curr_node->lower = (yyvsp[-5].integer);
                                curr_node->value = ((yyvsp[-3].integer)-(yyvsp[-5].integer)+1) * curr_node->component_type->value;
                                //present(stack_b[count-1].root);
                                //printf("\n");
                            }
                              
                        }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 306 "ada.y" /* yacc.c:1646  */
    {   printf("line %d: type %s is range %d..%d\n", lineno, (yyvsp[-5].var), (yyvsp[-2].integer), (yyvsp[0].integer));
                            if(recursive_search_local(stack_b[count-1].root, (yyvsp[-5].var)) != NULL) {
                            	printf("ERROR: Duplicate IDs!\n");
                            } else {
                                add((yyvsp[-5].var));
                                //printf("ADD %s into the tree.\n", $2);
                                int offset;
                                node* curr_node = search_in_stack((yyvsp[-5].var), &offset);
                                curr_node = empty_node(curr_node);
                                curr_node->kind = "type (range)";
                                curr_node->upper = (yyvsp[0].integer);
                                curr_node->lower = (yyvsp[-2].integer);
                                //present(stack_b[count-1].root);
                                //printf("\n");
                            }
                              
                        }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 325 "ada.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[0].integer);}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 326 "ada.y" /* yacc.c:1646  */
    {(yyval.integer) = 0;}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 334 "ada.y" /* yacc.c:1646  */
    {   printf("line %d:", lineno);
                            print((yyvsp[-2].head)); 
                            printf(": %s\n", (yyvsp[0].var));
                            LL_node current; 
                            current = (yyvsp[-2].head);
                            while(current != NULL) {
                            	if(recursive_search_local(stack_b[count-1].root, current->data) != NULL) {
                            		printf("ERROR: Duplicate IDs!\n");
                            		current = current -> next;
                            		continue;
                            	}
                                add(current->data);
                                printf("ADD %s into the tree.\n", current->data);
                                int offset;
                                node* curr_node = search_in_stack(current->data, &offset);
                                curr_node = empty_node(curr_node);
                                curr_node->kind = "variable";
                                curr_node->parent_type = search_in_stack((yyvsp[0].var), &offset);
                                if (strcmp(curr_node->parent_type->kind, "type (array)") == 0){
                                
                                curr_node->value = 4 + proc_size[proc_i];
                                proc_size[proc_i] = proc_size[proc_i] + curr_node->parent_type->value;                                
                                printf("in array value is %d\n", curr_node->parent_type->value);
                                } else {
                                
                                curr_node->value = 4 + proc_size[proc_i];
                                proc_size[proc_i] = proc_size[proc_i] + curr_node->parent_type->value; 
                                //present(stack_b[count-1].root);
                                //printf("\n");
                                }
                                current = current -> next;
                          }
                        }
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 374 "ada.y" /* yacc.c:1646  */
    {   printf("line %d:", lineno);
                            print((yyvsp[-2].head)); 
                            printf(":exception\n");
                            LL_node current; 
                            current = (yyvsp[-2].head);
                            while(current != NULL) {
                            	if(recursive_search_local(stack_b[count-1].root, current->data) != NULL) {
                            		printf("ERROR: Duplicate IDs!\n");
                            		current = current -> next;
                            		continue;
                            	}
                                add(current->data);
                                printf("ADD %s into the tree.\n", current->data);
                                int offset;
                                node* curr_node = search_in_stack(current->data, &offset);
                                curr_node = empty_node(curr_node);
                                curr_node->kind = "exception";
                                curr_node->value = next_exception;
                                next_exception++;
                                //present(stack_b[count-1].root);
                                //printf("\n");
                                current = current -> next;
                          }
                        }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 406 "ada.y" /* yacc.c:1646  */
    {int offset;
                        node* curr_node = search_in_stack((yyvsp[-3].var), &offset);
                        char *temp = (char*)malloc(40 * sizeof(char));
                        //search the stack for the ID type

                        //read routine
                        if (strcmp(curr_node->kind, "read_routine") == 0) {
                            if ((yyvsp[-2].c_record) ->is_var){ 
                            sprintf(temp, "READ: read contents b, %d\n", (yyvsp[-2].c_record)->var_loc);
                            output[instr++] = temp;
                            }
                            else {sprintf(temp, "READ: read contents r%d, %d\n",(yyvsp[-2].c_record)->reg_number-1, (yyvsp[-2].c_record)->var_loc);
                            output[instr++] = temp;
                            }
                        } 


                        //write routine
                        else if (strcmp(curr_node->kind, "write_routine") == 0) { 
                            for (int i = 0; i < (yyvsp[-2].c_record)->curr_top; i++ ) {
                                temp = (char*)malloc(40 * sizeof(char));
                                sprintf(temp, "WRITE: write %s%d\n",((yyvsp[-2].c_record)->exp_list[i] < 0)? "contents b, ":"r", 
                                                                    ((yyvsp[-2].c_record)->exp_list[i] < 0)? (yyvsp[-2].c_record)->exp_list[i]*-1:(yyvsp[-2].c_record)->exp_list[i]);
                                output[instr++] = temp; 
                            }


                        //procedure call    
                        } else if (strcmp(curr_node->kind, "procedure") == 0) {
                            
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "FUNCTION CALL: r%d := b\n", curr_reg);
                            output[instr++] = temp;
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "b := contents r%d, 0\n", curr_reg);
                            output[instr++] = temp;
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "contents b, 3 := r%d\n", curr_reg);
                            output[instr++] = temp;
                            int offset = 0;
                            search_in_stack(curr_node->symbol, &offset);
                            //printf("FUNCTION CALL: offset is %d\n",offset);
                            if (offset == 0) {
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "contents b, 2 := r%d\n", curr_reg);
                            output[instr++] = temp;
                            }else {
                            for (int i = 0; i < offset; i++){
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "r%d := contents r%d, 2\n", curr_reg, curr_reg);
                            output[instr++] = temp;
                            }
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "contents b, 2 := r%d\n", curr_reg);
                            output[instr++] = temp;
                            }
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "r%d := %d\n", ++curr_reg, 4 + curr_node->value);
                            output[instr++] = temp;
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "contents b, 0 := b + r%d\n", curr_reg);
                            output[instr++] = temp;
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "r%d := ", ++curr_reg);
                            int patch_return = instr;
                            output[instr++] = temp;
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "contents b, 1 := r%d\n", curr_reg++);
                            output[instr++] = temp;
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "JUMP: pc := %d\n", curr_node->proc_begin);
                            output[instr++] = temp;
                            sprintf(output[patch_return], "%s%d\n", output[patch_return], instr);
                            temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "pc := ? if r1\n");
                            output[instr++] = temp;
                            add_PL_ex(instr-1, -7);
                        
                    }


                        //variables 
                        else if (strcmp(curr_node->kind, "variable") == 0 && strcmp(curr_node->parent_type->kind, "integer")==0) {
                            temp = (char*)malloc(100 * sizeof(char));
                            if (offset == 0) {
                            
                            sprintf(temp, "ASSIGNMENTS: contents b, %d := %s%d\n", curr_node->value,
                                                                    (yyvsp[-1].c_record)->is_var? "contents b, ":"r", 
                                                                    (yyvsp[-1].c_record)->is_var?(yyvsp[-1].c_record)->var_loc:(yyvsp[-1].c_record)->reg_number);
                            output[instr++] = temp;
                            } else {
                                temp = (char*)malloc(100 * sizeof(char));
                                sprintf(temp, "NONLOCAL ASSIGNMENTS: r%d := b\n", curr_reg);
                                output[instr++] = temp;
                                for (int i = 0; i<offset; i++){ 
                                    char *temp = (char*)malloc(100 * sizeof(char));
                                    sprintf(temp, "r%d := contents r%d, 2\n", curr_reg, curr_reg);
                                    output[instr++] = temp;
                                }
                                temp = (char*)malloc(100 * sizeof(char));
                                sprintf(temp, "contents r%d, %d := %s%d\n", curr_reg, curr_node->value,
                                                                    (yyvsp[-1].c_record)->is_var? "contents b, ":"r", 
                                                                    (yyvsp[-1].c_record)->is_var?(yyvsp[-1].c_record)->var_loc:(yyvsp[-1].c_record)->reg_number);
                                output[instr++] = temp;
                                curr_reg++;
                            }
                        }



                        //array
                        else if (strcmp(curr_node->kind, "variable") == 0 && strcmp(curr_node->parent_type->kind, "type (array)")==0) {
                            if (offset == 0) {
                            if ((yyvsp[-2].c_record) -> is_var) {
                                    char *temp = (char*)malloc(100 * sizeof(char));
                                    sprintf(temp, "r%d := contents b, %d\n", curr_reg++, (yyvsp[-2].c_record)->var_loc);
                                    output[instr++] = temp;

                            }
                            temp = (char*)malloc(100 * sizeof(char));   
                            sprintf(temp, "ARRAY INDEX: r%d := r%d - %d\n", curr_reg,
                                                                    curr_reg-1, 
                                                                    curr_node->parent_type->lower);
                            output[instr++] = temp;
                            temp = (char*)malloc(100 * sizeof(char));   
                            sprintf(temp, "ASSIGNMENTS: contents b, r%d, %d := %s%d\n", curr_reg, curr_node->value,
                                                                    (yyvsp[-1].c_record)->is_var? "contents b, ":"r", 
                                                                    (yyvsp[-1].c_record)->is_var?(yyvsp[-1].c_record)->var_loc:(yyvsp[-1].c_record)->reg_number);
                            output[instr++] = temp;
                            curr_reg++;
                            } else {
                                temp = (char*)malloc(100 * sizeof(char));
                                sprintf(temp, "NONLOCAL ASSIGNMENTS: r%d := b\n", curr_reg);
                                output[instr++] = temp;
                                for (int i = 0; i<offset; i++){ 
                                    temp = (char*)malloc(100 * sizeof(char));
                                    sprintf(temp, "r%d := contents r%d, 2\n", curr_reg, curr_reg);
                                    output[instr++] = temp;
                                }
                                int reg_for_wb = curr_reg;
                                curr_reg++;
                                if ((yyvsp[-2].c_record) -> is_var) {
                                    char *temp = (char*)malloc(100 * sizeof(char));
                                    sprintf(temp, "r%d := contents b, %d\n", curr_reg++, (yyvsp[-2].c_record)->var_loc);
                                    output[instr++] = temp;

                                }
                                temp = (char*)malloc(100 * sizeof(char));   
                                sprintf(temp, "ARRAY INDEX: r%d := r%d - %d\n", curr_reg,
                                                                    curr_reg-1, 
                                                                    curr_node->parent_type->lower);
                                output[instr++] = temp;
                                int reg_for_index = curr_reg;
                                curr_reg++;
                                temp = (char*)malloc(100 * sizeof(char));
                                sprintf(temp, "contents r%d, r%d, %d := %s%d\n", reg_for_wb, reg_for_index, curr_node->value,
                                                                    (yyvsp[-1].c_record)->is_var? "contents b, ":"r", 
                                                                    (yyvsp[-1].c_record)->is_var?(yyvsp[-1].c_record)->var_loc:(yyvsp[-1].c_record)->reg_number);
                                output[instr++] = temp;
                            }
                        }
                        
                    }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 572 "ada.y" /* yacc.c:1646  */
    {
                        int offset;
                        node* curr_node = search_in_stack((yyvsp[-1].var), &offset);
                        char *temp = (char*)malloc(40 * sizeof(char));
                        if (curr_node != NULL && strcmp(curr_node -> kind, "exception") == 0) {
                        	printf("found exception\n");
                        	temp = (char*)malloc(100 * sizeof(char));
                            sprintf(temp, "r1 = %d\n", curr_node->value);
                            output[instr++] = temp;
                            temp = (char*)malloc(100 * sizeof(char));
                            sprintf(temp, "pc = ?\n");
                            output[instr++] = temp;


                        }
                        add_PL_ex(instr-1, -7);
                        }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 590 "ada.y" /* yacc.c:1646  */
    {
                        	char *temp = (char*)malloc(40 * sizeof(char));
                        	temp = (char*)malloc(100 * sizeof(char));
                            sprintf(temp, "pc = ?\n");
                            output[instr++] = temp;
                            add_rear_PL(instr-1, -3);
                        }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 600 "ada.y" /* yacc.c:1646  */
    {(yyval.c_record) = (yyvsp[0].c_record);}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 602 "ada.y" /* yacc.c:1646  */
    {(yyval.c_record) = NULL;}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 605 "ada.y" /* yacc.c:1646  */
    {(yyval.c_record) = (yyvsp[-1].c_record);}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 607 "ada.y" /* yacc.c:1646  */
    {(yyval.c_record)=NULL;}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 610 "ada.y" /* yacc.c:1646  */
    {
                            if ((yyvsp[0].c_record)->is_var) (yyvsp[-2].c_record)->exp_list[(yyvsp[-2].c_record) -> curr_top++] = -1*(yyvsp[0].c_record) -> var_loc;

                            else (yyvsp[-2].c_record)->exp_list[(yyvsp[-2].c_record) -> curr_top++] = (yyvsp[0].c_record) -> reg_number;
                            (yyval.c_record) = (yyvsp[-2].c_record);
						}
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 617 "ada.y" /* yacc.c:1646  */
    {
                            if ((yyvsp[0].c_record)->is_var) (yyvsp[0].c_record)->exp_list[(yyvsp[0].c_record) -> curr_top++] = -1*(yyvsp[0].c_record) -> var_loc;

                            else (yyvsp[0].c_record)->exp_list[(yyvsp[0].c_record) -> curr_top++] = (yyvsp[0].c_record) -> reg_number;
                            (yyval.c_record) = (yyvsp[0].c_record);
                        }
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 626 "ada.y" /* yacc.c:1646  */
    {
                        if (Patch_list == NULL)
                        {Patch_list = retrieve_PL();}
                        else
                        {toEnd_PL(Patch_list) -> next= retrieve_PL();}
                        pop_PL();
                        patch_jump(Patch_list, instr+1);
                        print_PL(Patch_list);
                        char *temp = (char*)malloc(40 * sizeof(char));
                        sprintf(temp, "ENDLOOP: pc := %d\n", (yyvsp[-3].integer));
                        output[instr++] = temp;
                        }
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 640 "ada.y" /* yacc.c:1646  */
    {push_PL();
                        (yyval.integer) = instr;}
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 650 "ada.y" /* yacc.c:1646  */
    {   char *temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "COND EXIT: pc := ? if r%d\n", (yyvsp[-1].c_record)->reg_number);
                            output[instr++] = temp;
                            add_PL(instr-1, -7);
                        }
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 656 "ada.y" /* yacc.c:1646  */
    {   char *temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "COND EXIT: pc := ?\n");
                            output[instr++] = temp;
                            add_PL(instr-1, -7);
                        }
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 665 "ada.y" /* yacc.c:1646  */
    {
						if (Patch_list == NULL)
                        {Patch_list = retrieve_PL();}
                        else
                        {toEnd_PL(Patch_list) -> next= retrieve_PL();}
                        pop_PL();
                        printf("Patching IFs:\n");
                        patch_jump(Patch_list, instr);
                        print_PL(Patch_list);
						}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 678 "ada.y" /* yacc.c:1646  */
    {	push_PL();
                            char *temp = (char*)malloc(40 * sizeof(char));
                            sprintf(temp, "IF COND: pc := ? if not r%d\n", (yyvsp[-1].c_record)->reg_number);
                            output[instr++] = temp;
                            add_PL(instr-1, -7);}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 695 "ada.y" /* yacc.c:1646  */
    {(yyval.c_record) = (yyvsp[0].c_record);}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 701 "ada.y" /* yacc.c:1646  */
    {(yyval.c_record) = (yyvsp[0].c_record);
						}
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 704 "ada.y" /* yacc.c:1646  */
    {struct address_record* new_record = create_new_record(); 
							char *temp = (char*)malloc(100 * sizeof(char));
							new_record->reg_number = curr_reg;
							sprintf(temp, "BOOLEAN: r%d := %s%d %s %s%d\n", curr_reg++, 
																	(yyvsp[-2].c_record)->is_var? "contents b, ":"r", 
																	(yyvsp[-2].c_record)->is_var?(yyvsp[-2].c_record)->var_loc:(yyvsp[-2].c_record)->reg_number,
																	(yyvsp[-1].var), 
																	(yyvsp[0].c_record)->is_var? "contents b, ":"r", 
																	(yyvsp[0].c_record)->is_var?(yyvsp[0].c_record)->var_loc:(yyvsp[0].c_record)->reg_number);
							output[instr++] = temp;
							(yyval.c_record) = new_record;
						}
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 718 "ada.y" /* yacc.c:1646  */
    {(yyval.c_record) = (yyvsp[0].c_record);
						}
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 721 "ada.y" /* yacc.c:1646  */
    {struct address_record* new_record = create_new_record(); 
							char *temp = (char*)malloc(100 * sizeof(char));
                            if ((yyvsp[-2].c_record)->is_var) {
                                temp = (char*)malloc(40 * sizeof(char));
                                (yyvsp[-2].c_record)-> reg_number = curr_reg;
                                (yyvsp[-2].c_record)-> is_var = false; 
                                sprintf(temp, "NUMBER: r%d := contents b, %d\n", curr_reg++, (yyvsp[-2].c_record)->var_loc);
                                output[instr++] = temp;
                            }
                            if ((yyvsp[0].c_record)->is_var) {
                                temp = (char*)malloc(40 * sizeof(char));
                                (yyvsp[0].c_record)-> reg_number = curr_reg;
                                (yyvsp[0].c_record)-> is_var = false; 
                                sprintf(temp, "NUMBER: r%d := contents b, %d\n", curr_reg++, (yyvsp[0].c_record)->var_loc);
                                output[instr++] = temp;
                            }
                            temp = (char*)malloc(100 * sizeof(char));
							if (strcmp((yyvsp[-1].var), ">") == 0 ) {
							sprintf(temp, "r%d := %s%d < %s%d\n", curr_reg++, 
																	(yyvsp[0].c_record)->is_var? "contents b, ":"r", 
																	(yyvsp[0].c_record)->is_var?(yyvsp[0].c_record)->var_loc:(yyvsp[0].c_record)->reg_number, 
																	(yyvsp[-2].c_record)->is_var? "contents b, ":"r", 
																	(yyvsp[-2].c_record)->is_var?(yyvsp[-2].c_record)->var_loc:(yyvsp[-2].c_record)->reg_number);
							output[instr++] = temp;
                            new_record -> reg_number = curr_reg-1;
							(yyval.c_record) = new_record;
							} else if (strcmp((yyvsp[-1].var), ">=") == 0) {
								sprintf(temp, "r%d := %s%d <= %s%d\n", curr_reg++, 
																	(yyvsp[0].c_record)->is_var? "contents b, ":"r", 
																	(yyvsp[0].c_record)->is_var?(yyvsp[0].c_record)->var_loc:(yyvsp[0].c_record)->reg_number, 
																	(yyvsp[-2].c_record)->is_var? "contents b, ":"r", 
																	(yyvsp[-2].c_record)->is_var?(yyvsp[-2].c_record)->var_loc:(yyvsp[-2].c_record)->reg_number);
							output[instr++] = temp;
                            new_record -> reg_number = curr_reg-1;
							(yyval.c_record) = new_record;
							}else {
							sprintf(temp, "r%d := %s%d %s %s%d\n", curr_reg++, 
																	(yyvsp[-2].c_record)->is_var? "contents b, ":"r", 
																	(yyvsp[-2].c_record)->is_var?(yyvsp[-2].c_record)->var_loc:(yyvsp[-2].c_record)->reg_number,
																	(yyvsp[-1].var), 
																	(yyvsp[0].c_record)->is_var? "contents b, ":"r", 
																	(yyvsp[0].c_record)->is_var?(yyvsp[0].c_record)->var_loc:(yyvsp[0].c_record)->reg_number);
							output[instr++] = temp;
                            new_record -> reg_number = curr_reg-1;
							(yyval.c_record) = new_record;
							}
						}
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 770 "ada.y" /* yacc.c:1646  */
    {	struct address_record* new_record = create_new_record(); 
							char *temp = (char*)malloc(100 * sizeof(char));
							new_record->reg_number = curr_reg;
							sprintf(temp, "NEGATIVE: r%d := -1 * %s%d\n", curr_reg++, 
																	(yyvsp[0].c_record)->is_var? "contents b, ":"r", 
																	(yyvsp[0].c_record)->is_var?(yyvsp[0].c_record)->var_loc:(yyvsp[0].c_record)->reg_number);
							output[instr++] = temp;
							(yyval.c_record) = new_record;}
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 779 "ada.y" /* yacc.c:1646  */
    {(yyval.c_record) = (yyvsp[0].c_record);
						}
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 782 "ada.y" /* yacc.c:1646  */
    {struct address_record* new_record = create_new_record(); 
							char *temp = (char*)malloc(100 * sizeof(char));
							new_record->reg_number = curr_reg;
							sprintf(temp, "ADD: r%d := %s%d %s %s%d\n", curr_reg++, 
																	(yyvsp[-2].c_record)->is_var? "contents b, ":"r", 
																	(yyvsp[-2].c_record)->is_var?(yyvsp[-2].c_record)->var_loc:(yyvsp[-2].c_record)->reg_number, 
																	(yyvsp[-1].var),
																	(yyvsp[0].c_record)->is_var? "contents b, ":"r", 
																	(yyvsp[0].c_record)->is_var?(yyvsp[0].c_record)->var_loc:(yyvsp[0].c_record)->reg_number);
							output[instr++] = temp;
							(yyval.c_record) = new_record;}
#line 2321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 795 "ada.y" /* yacc.c:1646  */
    {(yyval.c_record) = (yyvsp[0].c_record);
						}
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 798 "ada.y" /* yacc.c:1646  */
    {	struct address_record* new_record = create_new_record(); 
							char *temp = (char*)malloc(100 * sizeof(char));
							new_record->reg_number = curr_reg;
							sprintf(temp, "MULTIPLY: r%d := %s%d %s %s%d\n", curr_reg++, 
																	(yyvsp[-2].c_record)->is_var? "contents b, ":"r", 
																	(yyvsp[-2].c_record)->is_var?(yyvsp[-2].c_record)->var_loc:(yyvsp[-2].c_record)->reg_number,
																	(yyvsp[-1].var), 
																	(yyvsp[0].c_record)->is_var? "contents b, ":"r", 
																	(yyvsp[0].c_record)->is_var?(yyvsp[0].c_record)->var_loc:(yyvsp[0].c_record)->reg_number);
							output[instr++] = temp;
							(yyval.c_record) = new_record;
}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 812 "ada.y" /* yacc.c:1646  */
    {struct address_record* new_record = create_new_record(); 
							char *temp = (char*)malloc(100 * sizeof(char));
							new_record->reg_number = curr_reg;
							sprintf(temp, "NEGATION: r%d := not %s%d\n", curr_reg++, 
																	(yyvsp[0].c_record)->is_var? "contents b, ":"r", 
																	(yyvsp[0].c_record)->is_var?(yyvsp[0].c_record)->var_loc:(yyvsp[0].c_record)->reg_number);
							output[instr++] = temp;
							(yyval.c_record) = new_record;}
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 821 "ada.y" /* yacc.c:1646  */
    {(yyval.c_record) = (yyvsp[-2].c_record);}
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 823 "ada.y" /* yacc.c:1646  */
    {(yyval.c_record) = (yyvsp[0].c_record);
						}
#line 2371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 827 "ada.y" /* yacc.c:1646  */
    {
							struct address_record* new_record = create_new_record(); 
							char *temp = (char*)malloc(40 * sizeof(char));
							new_record->reg_number = curr_reg;
							sprintf(temp, "NUMBER: r%d := %d\n", curr_reg++, (yyvsp[0].integer));
							output[instr++] = temp;
							(yyval.c_record) = new_record;

						}
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 837 "ada.y" /* yacc.c:1646  */
    {
                            struct address_record* new_record = create_new_record();
                            node * curr_node; 
							int offset = 0;
							curr_node = search_in_stack((yyvsp[0].var), &offset);
							//printf("offset is %d\n",offset);
							if (strcmp((yyvsp[0].var), "true") == 0 || strcmp((yyvsp[0].var), "false") == 0) {
								struct address_record* new_record = create_new_record(); 
								char *temp = (char*)malloc(40 * sizeof(char));
								new_record->reg_number = curr_reg;
								sprintf(temp, "r%d := %s\n", curr_reg++, (yyvsp[0].var));
								output[instr++] = temp;
								(yyval.c_record) = new_record;
							} else {
                            if (offset == 0) {
                                new_record -> var_loc = curr_node -> value;
                                char *temp = (char*)malloc(40 * sizeof(char));
								//new_record->reg_number = curr_reg;
								new_record-> is_var = true; 
								//sprintf(temp, "NUMBER: r%d := contents b, %d\n", curr_reg++, new_record->var_loc);
								//output[instr++] = temp;
								(yyval.c_record) = new_record;
                                
                            } else {
                               	char *temp = (char*)malloc(100 * sizeof(char));
								sprintf(temp, "r%d := b\n", curr_reg);
								output[instr++] = temp;
                                new_record -> var_loc = curr_node -> value;
								for (int i = 0; i<offset; i++){ 
									char *temp = (char*)malloc(100 * sizeof(char));
									sprintf(temp, "r%d := contents r%d, 2\n", curr_reg, curr_reg);
									output[instr++] = temp;
								}
								curr_reg++;
                                temp = (char*)malloc(100 * sizeof(char));
                                new_record->reg_number = curr_reg;
                                sprintf(temp, "r%d := contents r%d, %d\n", curr_reg++, curr_reg-1,new_record -> var_loc);
                                output[instr++] = temp;

                            }
                              (yyval.c_record) = new_record;
                          }

						}
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 882 "ada.y" /* yacc.c:1646  */
    {
                            struct address_record* new_record = create_new_record();
                            node * curr_node; 
                            int offset = 0;
                            curr_node = search_in_stack((yyvsp[-3].var), &offset);
                            //printf("offset is %d\n",offset);
                            if (offset == 0) {
                            if ((yyvsp[-1].c_record) -> is_var) {
                                    char *temp = (char*)malloc(100 * sizeof(char));
                                    sprintf(temp, "r%d := contents b, %d\n", curr_reg++, (yyvsp[-1].c_record)->var_loc);
                                    output[instr++] = temp;

                            }
                            char *temp = (char*)malloc(100 * sizeof(char));   
                            sprintf(temp, "ARRAY INDEX: r%d := r%d - %d\n", curr_reg,
                                                                    curr_reg-1, 
                                                                    curr_node->parent_type->lower);
                            curr_reg++;
                            output[instr++] = temp;
                            temp = (char*)malloc(100 * sizeof(char));   
                            sprintf(temp, "r%d := contents b, r%d, %d\n", curr_reg, curr_reg-1, curr_node->value);                            
                            output[instr++] = temp;
                            new_record->reg_number = curr_reg;
                            curr_reg++;
                            (yyval.c_record) = new_record;
                                
                            } else {
                                char *temp = (char*)malloc(100 * sizeof(char));
                                sprintf(temp, "r%d := b\n", curr_reg);
                                output[instr++] = temp;
                                new_record -> var_loc = curr_node -> value;
                                for (int i = 0; i<offset; i++){ 
                                    char *temp = (char*)malloc(100 * sizeof(char));
                                    sprintf(temp, "r%d := contents r%d, 2\n", curr_reg, curr_reg);
                                    output[instr++] = temp;
                                }
                                curr_reg++;
                                if ((yyvsp[-1].c_record) -> is_var) {
                                    char *temp = (char*)malloc(100 * sizeof(char));
                                    sprintf(temp, "r%d := contents b, %d\n", curr_reg++, (yyvsp[-1].c_record)->var_loc);
                                    output[instr++] = temp;

                                }
                                temp = (char*)malloc(100 * sizeof(char));   
                                sprintf(temp, "ARRAY INDEX: r%d := r%d - %d\n", curr_reg,
                                                                    curr_reg-1, 
                                                                    curr_node->parent_type->lower);
                                curr_reg++;
                                output[instr++] = temp;
                                temp = (char*)malloc(100 * sizeof(char));
                                new_record->reg_number = curr_reg;
                                sprintf(temp, "r%d := contents r%d, r%d, %d\n", curr_reg++, curr_reg-1, curr_reg -2, new_record -> var_loc);
                                output[instr++] = temp;

                            }
                              (yyval.c_record) = new_record;
                          }
#line 2496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 941 "ada.y" /* yacc.c:1646  */
    {(yyval.c_record) = (yyvsp[-1].c_record);}
#line 2502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 944 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "and";}
#line 2508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 946 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "or";}
#line 2514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 949 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "=";}
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 951 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "/=";}
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 953 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "<";}
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 955 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = ">";}
#line 2538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 957 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = ">=";}
#line 2544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 959 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "<=";}
#line 2550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 962 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "+";}
#line 2556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 964 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "-";}
#line 2562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 967 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "*";}
#line 2568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 969 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "/";}
#line 2574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 972 "ada.y" /* yacc.c:1646  */
    {
                            patch_jump_ex(Patch_list, -4, instr-1);
				
                            for(int i = 1; i < next_exception; i++) {
                                if (jump_table[i] == 0)
                                jump_table[i] = instr+next_exception-1;
                            }
                            for(int i = 1; i < next_exception; i++){
                            char *temp = (char*)malloc(40 * sizeof(char));
                            temp = (char*)malloc(100 * sizeof(char));
                            sprintf(temp, "pc = %d\n", jump_table[i]);
                            output[instr++] = temp;
                            }
                            if (Patch_list == NULL)
                            {Patch_list = retrieve_PL_ex();}
                            else
                            {toEnd_PL(Patch_list) -> next= retrieve_PL_ex();}
                            pop_PL_ex();
                            printf("Patching exceptions:\n");
                            patch_jump(Patch_list, instr);
                            print_PL(Patch_list);
						}
#line 2601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 995 "ada.y" /* yacc.c:1646  */
    {(yyval.integer) = 0;}
#line 2607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 998 "ada.y" /* yacc.c:1646  */
    {
                            for (int i =1; i<next_exception;i++) {
                            jump_table[i] = 0;
                        }
                        	char *temp = (char*)malloc(40 * sizeof(char));
                        	temp = (char*)malloc(100 * sizeof(char));
                            sprintf(temp, "pc = ?\n");
                            output[instr++] = temp;
                        	temp = (char*)malloc(100 * sizeof(char));
                            sprintf(temp, "pc = r1, ?\n");
                            output[instr++] = temp;
                            
                            if (Patch_list == NULL)
                        	{Patch_list = retrieve_PL_ex();}
                       		else
                        	{
                        	printf("Patching procedures:\n");
                        	toEnd_PL(Patch_list) -> next= retrieve_PL_ex();}
                        	pop_PL_ex();
                        	patch_jump(Patch_list, instr-1);
                            
                        	print_PL(Patch_list);
                        	push_PL_ex();
                        	add_PL_ex(instr-2, -7);
                        	add_rear_PL(instr-1, -4);
                        }
#line 2638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1026 "ada.y" /* yacc.c:1646  */
    {
                            
						}
#line 2646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1030 "ada.y" /* yacc.c:1646  */
    {
                        	
                        }
#line 2654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1035 "ada.y" /* yacc.c:1646  */
    {
                        
						printf("search for %s\n", (yyvsp[-2].var));
                        
                        char *temp = (char*)malloc(40 * sizeof(char));
                        	
                        	temp = (char*)malloc(100 * sizeof(char));
                            sprintf(temp, "r1 = 0\n");
                            output[instr++] = temp;
                            temp = (char*)malloc(100 * sizeof(char));
                            sprintf(temp, "pc = ?\n");
                            output[instr++] = temp;
                            add_PL_ex(instr-1, -7);
                        
                        

                        
                    }
#line 2677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1058 "ada.y" /* yacc.c:1646  */
    {int offset;
                            node* curr_node = search_in_stack((yyvsp[0].var), &offset);
                            jump_table[curr_node->value] = instr; 
                            (yyval.var) = (yyvsp[0].var);}
#line 2686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1063 "ada.y" /* yacc.c:1646  */
    {
                            for(int i = 1; i < next_exception; i++) {
                                if (jump_table[i] == 0)
                                jump_table[i] = instr;
                            }
                            
                            (yyval.var) = NULL;}
#line 2698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1072 "ada.y" /* yacc.c:1646  */
    {(yyvsp[0].head) = insert((yyvsp[0].head), (yyvsp[-2].var));
                         (yyval.head) = (yyvsp[0].head); }
#line 2705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1075 "ada.y" /* yacc.c:1646  */
    {LL_node head; 
                         head = init((yyvsp[0].var));
                         (yyval.head) = head;
                        }
#line 2714 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2718 "y.tab.c" /* yacc.c:1646  */
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
#line 1082 "ada.y" /* yacc.c:1906  */

int main()
{
  push("Outer_Context");
  node* curr_node;
  int offset;
  add("boolean");
  curr_node = search_in_stack("boolean", &offset);
  curr_node -> value = 1; 
  curr_node -> kind = "boolean";
  add("integer"); 
  curr_node = search_in_stack("integer", &offset);
  curr_node -> value = 1; 
  curr_node -> kind = "integer";
  add("true");
  curr_node = search_in_stack("true", &offset);
  curr_node -> value = 1; 
  add("false");
  curr_node = search_in_stack("false", &offset);
  curr_node -> value = 1; 
  add("maxint");
  add("read");
  curr_node = search_in_stack("read", &offset);
  curr_node -> value = 1;
  curr_node -> kind = "read_routine";
  add("write");
  curr_node = search_in_stack("write", &offset);
  curr_node -> value = 1;
  curr_node -> kind = "write_routine";
  add("constant_error");
  curr_node = search_in_stack("constant_error", &offset);
  curr_node -> value = 1;
  curr_node -> kind = "exception";
  add("numeric_error");
  curr_node = search_in_stack("numeric_error", &offset);
  curr_node -> value = 2;
  curr_node -> kind = "exception";

  printf("OC tree is created!\n\n");
  yyparse();
}
