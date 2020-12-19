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
#line 2 "alfa.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>
#include "alfa.h"
#include "generacion.h"
#include "tabla_simbolos.h"

extern FILE* yyout;
extern int yylex();
extern size_t nlines;
void yyerror(const char *s);
tablas_smb *tabla;

int num_total_parametros = 0;   /* Numero de parametros para DECLARAR una funcion */
int num_total_varlocs = 0;      /* Numero de variables locales, por ej, dentro de una funcion */
int tamanio = 1;                /* Para controlar el tamaño del identificador */
int tipo;                       /* Para darle un tipo entero o booleano a un identificador */
int funcion_retorno = 0;        /* Comprueba que hay un return en la funcion */
int funcion_tipo;               /* Tipo de una funcion (entero o booleano) */
int etiqueta = 0;

int dentro_par_fun = 0;         /* Esta a 1 si estamos si estamos dentro de los parentesis de una funcion y a 0 si estamos fuera */
int categoria_estructura;       /* Es ESCALAR o VECTOR */
int posicion_parametro = 0;     /* Solo para elementos de tipo parametro, posicion en orden, empieza por 0 */
int posicion = 0;               /* Solo para variables locales, su posición */
int num_arg_funcion = 0;        /* Numero de parametros al LLAMAR a una funcion */

#line 94 "alfa.tab.c" /* yacc.c:339  */

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
   by #include "alfa.tab.h".  */
#ifndef YY_YY_ALFA_TAB_H_INCLUDED
# define YY_YY_ALFA_TAB_H_INCLUDED
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
    TOK_IDENTIFICADOR = 258,
    TOK_CONSTANTE_ENTERA = 259,
    TOK_MAIN = 260,
    TOK_INT = 261,
    TOK_BOOLEAN = 262,
    TOK_ARRAY = 263,
    TOK_FUNCTION = 264,
    TOK_IF = 265,
    TOK_ELSE = 266,
    TOK_WHILE = 267,
    TOK_SCANF = 268,
    TOK_PRINTF = 269,
    TOK_RETURN = 270,
    TOK_PUNTOYCOMA = 271,
    TOK_COMA = 272,
    TOK_PARENTESISIZQUIERDO = 273,
    TOK_PARENTESISDERECHO = 274,
    TOK_CORCHETEIZQUIERDO = 275,
    TOK_CORCHETEDERECHO = 276,
    TOK_LLAVEIZQUIERDA = 277,
    TOK_LLAVEDERECHA = 278,
    TOK_ASIGNACION = 279,
    TOK_MAS = 280,
    TOK_MENOS = 281,
    TOK_DIVISION = 282,
    TOK_ASTERISCO = 283,
    TOK_AND = 284,
    TOK_OR = 285,
    TOK_NOT = 286,
    TOK_IGUAL = 287,
    TOK_DISTINTO = 288,
    TOK_MENORIGUAL = 289,
    TOK_MAYORIGUAL = 290,
    TOK_MENOR = 291,
    TOK_MAYOR = 292,
    TOK_TRUE = 293,
    TOK_FALSE = 294,
    TOK_ERROR = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "alfa.y" /* yacc.c:355  */

  tipo_atributos atributos;

#line 179 "alfa.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ALFA_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 196 "alfa.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   110,   120,   125,   130,   132,   135,   138,
     141,   145,   149,   152,   156,   165,   167,   170,   172,   175,
     196,   211,   234,   236,   239,   241,   244,   249,   263,   265,
     268,   270,   273,   275,   278,   280,   282,   284,   287,   289,
     292,   324,   327,   351,   355,   360,   371,   377,   382,   394,
     400,   419,   424,   439,   451,   463,   475,   487,   499,   511,
     523,   536,   564,   569,   574,   579,   584,   603,   626,   633,
     636,   643,   646,   659,   672,   685,   698,   711,   725,   731,
     738,   747,   757,   768
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_IDENTIFICADOR",
  "TOK_CONSTANTE_ENTERA", "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN",
  "TOK_ARRAY", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_PUNTOYCOMA", "TOK_COMA",
  "TOK_PARENTESISIZQUIERDO", "TOK_PARENTESISDERECHO",
  "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO", "TOK_LLAVEIZQUIERDA",
  "TOK_LLAVEDERECHA", "TOK_ASIGNACION", "TOK_MAS", "TOK_MENOS",
  "TOK_DIVISION", "TOK_ASTERISCO", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_IGUAL", "TOK_DISTINTO", "TOK_MENORIGUAL", "TOK_MAYORIGUAL",
  "TOK_MENOR", "TOK_MAYOR", "TOK_TRUE", "TOK_FALSE", "TOK_ERROR",
  "$accept", "programa", "inicio", "escribir_TS", "escribir_MAIN",
  "declaraciones", "declaracion", "clase", "clase_escalar", "tipo",
  "clase_vector", "identificadores", "funciones", "funcion",
  "fn_declaration", "fn_name", "parametros_funcion",
  "resto_parametros_funcion", "parametro_funcion", "idpf",
  "declaraciones_funcion", "sentencias", "sentencia", "sentencia_simple",
  "bloque", "asignacion", "elemento_vector", "condicional", "if_exp",
  "if_else_exp", "bucle", "while_exp", "while", "lectura", "escritura",
  "retorno_funcion", "exp", "idf_llamada_funcion", "lista_expresiones",
  "resto_lista_expresiones", "comparacion", "constante",
  "constante_logica", "constante_entera", "identificador", YY_NULLPTR
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
     295
};
# endif

#define YYPACT_NINF -39

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-39)))

#define YYTABLE_NINF -68

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,   -39,    19,     3,   -39,    45,   -39,   -39,     7,   -39,
      45,    41,   -39,   -39,   -39,    30,    48,   -39,   -39,    67,
      69,    80,     7,   -39,    48,   117,    70,   -39,    41,   -39,
      76,    84,   117,   -39,    -9,    90,   -39,   104,    17,    17,
      86,   117,    94,   -39,   -39,    87,   -39,    93,   102,   -39,
      99,   105,   -39,   -39,   -39,     7,   -39,   -39,   -39,   103,
      17,    17,    17,   -39,    27,    17,    17,    17,   -39,   -39,
     -39,   -21,   107,   -39,   -39,   -39,   -21,   -39,   -39,   -39,
      17,   100,   106,   117,    17,   130,   115,   119,   -39,    44,
     -21,   -21,    66,   118,    39,   -39,    17,    17,    17,    17,
      17,    17,    17,   -21,   117,   117,   113,    11,   -39,   -39,
     116,     7,   -39,   -39,   -39,    17,    17,    17,    17,    17,
      17,   -39,    39,    39,   -39,   -39,     6,     6,    89,   120,
     121,   122,   -39,   -39,    45,   119,   -21,   -21,   -21,   -21,
     -21,   -21,    17,   -39,   -39,   129,   -39,   -39,   -39,   -39,
      89,   -39
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     1,     0,    12,    13,     0,     4,
       6,     0,     9,    11,    10,     0,    18,     7,    83,     0,
      15,     0,     0,     5,    18,     0,     0,     8,     0,    82,
       0,     0,     0,    17,     0,     0,    49,     0,     0,     0,
       0,    30,     0,    33,    34,     0,    38,     0,     0,    39,
       0,     0,    35,    36,    37,    23,    16,    14,    21,     0,
       0,     0,     0,    50,    61,     0,     0,     0,    80,    81,
      65,    51,     0,    62,    78,    79,    52,    19,    31,    32,
       0,     0,     0,     0,     0,     0,     0,    25,     2,     0,
      40,    45,     0,     0,    57,    60,     0,     0,     0,     0,
       0,     0,    69,    41,     0,     0,     0,     0,    27,    26,
       0,     0,    22,    42,    63,     0,     0,     0,     0,     0,
       0,    64,    53,    54,    55,    56,    58,    59,    71,     0,
       0,     0,    47,    48,    29,    25,    72,    73,    74,    75,
      76,    77,     0,    68,    66,    43,    44,    28,    20,    24,
      71,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -39,   -39,   -39,   -39,   -39,   -10,   -39,   -39,   -39,    -6,
     -39,   114,   123,   -39,   -39,   -39,   -39,     8,    35,   -39,
     -39,   -29,   -39,   -39,   -39,   -39,   -15,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -38,   -39,   -39,    -2,
     -39,   -39,   -39,   128,   -39
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    16,    32,     9,    10,    11,    12,    13,
      14,    19,    23,    24,    25,    26,    86,   112,    87,   109,
     148,    40,    41,    42,    43,    44,    70,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    71,    72,   129,   143,
      93,    73,    74,    75,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    76,    15,    59,    96,    97,    98,    99,   100,   101,
      45,    60,    78,     6,     7,    61,    31,    45,     1,     4,
      64,    29,    89,    90,    91,     5,    45,    92,    94,    95,
     133,    96,    97,    98,    99,    65,    96,    97,    98,    99,
     100,   101,   103,    66,    18,   -67,   107,    60,    67,    85,
      21,     6,     7,     8,   106,    68,    69,    22,   122,   123,
     124,   125,   126,   127,   128,   113,    98,    99,    45,    96,
      97,    98,    99,   100,   101,   130,   131,   136,   137,   138,
     139,   140,   141,    27,    29,   114,    28,    58,    55,    45,
      45,    96,    97,    98,    99,   100,   101,    57,   115,   116,
     117,   118,   119,   120,   150,    85,   142,    63,    62,    77,
      79,    80,    81,    82,    96,    97,    98,    99,   100,   101,
      34,    83,   104,    84,   147,   102,    88,    35,   105,    36,
      37,    38,    39,   108,   110,   111,   132,   121,   134,   144,
     -46,     0,    56,   149,   145,   146,   135,    33,   151,    30
};

static const yytype_int16 yycheck[] =
{
      10,    39,     8,    32,    25,    26,    27,    28,    29,    30,
      25,    20,    41,     6,     7,    24,    22,    32,     5,     0,
       3,     4,    60,    61,    62,    22,    41,    65,    66,    67,
      19,    25,    26,    27,    28,    18,    25,    26,    27,    28,
      29,    30,    80,    26,     3,    18,    84,    20,    31,    55,
      20,     6,     7,     8,    83,    38,    39,     9,    96,    97,
      98,    99,   100,   101,   102,    21,    27,    28,    83,    25,
      26,    27,    28,    29,    30,   104,   105,   115,   116,   117,
     118,   119,   120,    16,     4,    19,    17,     3,    18,   104,
     105,    25,    26,    27,    28,    29,    30,    21,    32,    33,
      34,    35,    36,    37,   142,   111,    17,     3,    18,    23,
      16,    24,    19,    11,    25,    26,    27,    28,    29,    30,
       3,    22,    22,    18,   134,    18,    23,    10,    22,    12,
      13,    14,    15,     3,    19,    16,    23,    19,    22,    19,
      11,    -1,    28,   135,    23,    23,   111,    24,   150,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    42,    43,     0,    22,     6,     7,     8,    46,
      47,    48,    49,    50,    51,    50,    44,    46,     3,    52,
      85,    20,     9,    53,    54,    55,    56,    16,    17,     4,
      84,    50,    45,    53,     3,    10,    12,    13,    14,    15,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    18,    52,    21,     3,    62,
      20,    24,    18,     3,     3,    18,    26,    31,    38,    39,
      67,    77,    78,    82,    83,    84,    77,    23,    62,    16,
      24,    19,    11,    22,    18,    50,    57,    59,    23,    77,
      77,    77,    77,    81,    77,    77,    25,    26,    27,    28,
      29,    30,    18,    77,    22,    22,    62,    77,     3,    60,
      19,    16,    58,    21,    19,    32,    33,    34,    35,    36,
      37,    19,    77,    77,    77,    77,    77,    77,    77,    79,
      62,    62,    23,    19,    22,    59,    77,    77,    77,    77,
      77,    77,    17,    80,    19,    23,    23,    46,    61,    58,
      77,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    44,    45,    46,    46,    47,    48,
      48,    49,    50,    50,    51,    52,    52,    53,    53,    54,
      55,    56,    57,    57,    58,    58,    59,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    64,    64,    65,    65,
      66,    66,    67,    68,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    78,    79,    79,
      80,    80,    81,    81,    81,    81,    81,    81,    82,    82,
      83,    83,    84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     0,     0,     0,     1,     2,     3,     1,
       1,     1,     1,     1,     5,     1,     3,     2,     0,     3,
       6,     3,     2,     0,     3,     0,     2,     1,     1,     0,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     5,     5,     3,     5,     4,     4,     1,
       2,     2,     2,     3,     3,     3,     3,     2,     3,     3,
       2,     1,     1,     3,     3,     1,     4,     1,     2,     0,
       3,     0,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1
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
#line 106 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
                               escribir_fin(yyout);
                               LiberarTablas(tabla);}
#line 1395 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 111 "alfa.y" /* yacc.c:1646  */
    {  tabla = CrearTablas();
                                if(tabla == NULL){
                                  printf("No existe la tabla de símbolos\n");
                                  return -1;
                                }
                                escribir_subseccion_data(yyout);
                                escribir_cabecera_bss(yyout);
                              }
#line 1408 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 121 "alfa.y" /* yacc.c:1646  */
    {
                               escribir_segmento_codigo(yyout);
                              }
#line 1416 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 126 "alfa.y" /* yacc.c:1646  */
    {
                               escribir_inicio_main(yyout);
                              }
#line 1424 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 131 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R2:\t<declaraciones> ::= <declaracion>\n");}
#line 1430 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 133 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
#line 1436 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 136 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");}
#line 1442 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 139 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R5:\t<clase> ::= <clase_escalar>\n");
                               categoria_estructura = ESCALAR;}
#line 1449 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 142 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R7:\t<clase> ::= <clase_vector>\n");
                               categoria_estructura = VECTOR;}
#line 1456 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 146 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R9:\t<clase_escalar> ::= <tipo>\n");
                               tamanio = 1;}
#line 1463 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 150 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R10:\t<tipo> ::= int\n");
                               tipo = ENTERO;}
#line 1470 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 153 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R11:\t<tipo> ::= boolean\n");
                               tipo = BOOLEANO;}
#line 1477 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 157 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
                              int longitud = (yyvsp[-1].atributos).valor_entero;
                              if(longitud <= 0 || longitud > MAX_TAMANIO_VECTOR){
                                printf("****Error semantico en lin %lu: El tamanyo del vector %s excede los limites permitidos (1,64).\n", nlines, (yyvsp[-4].atributos).lexema);
                                LiberarTablas(tabla);
                                return -1;
                              }}
#line 1489 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 166 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R18:\t<identificadores> ::= <identificador>\n");}
#line 1495 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 168 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
#line 1501 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 171 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R20:\t<funciones> ::= <funcion> <funciones>\n");}
#line 1507 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 173 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R21:\t<funciones> ::= \n");}
#line 1513 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 176 "alfa.y" /* yacc.c:1646  */
    {
                              fprintf(yyout,";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");
                              if (funcion_retorno < 1){
                                printf("****Error semantico en lin %lu : Funcion %s sin sentencia return\n", nlines, (yyvsp[-2].atributos).lexema);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              simbolo *simbolo;
                              simbolo = BusquedaElemento(tabla, (yyvsp[-2].atributos).lexema);
                              if (simbolo == NULL){
                                printf("****Error en la tabla de simbolos\n");
                                LiberarTablas(tabla);
                                return -1;
                              }
                              simbolo->n_parametros = num_total_parametros;
                              num_total_parametros = 0;
                              num_total_varlocs = 0;
                              posicion_parametro = 0;
                              }
#line 1537 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 197 "alfa.y" /* yacc.c:1646  */
    {
                               simbolo *simbolo;
                               simbolo = BusquedaElemento(tabla, (yyvsp[-5].atributos).lexema);
                               if (simbolo == NULL){
                                 printf("****Error en la tabla de simbolos\n");
                                 LiberarTablas(tabla);
                                 return -1;
                               }
                               simbolo->n_parametros = num_total_parametros;
                               simbolo->n_varloc = num_total_varlocs;
                               strcpy((yyval.atributos).lexema, (yyvsp[-5].atributos).lexema);
                               declararFuncion(yyout, (yyvsp[-5].atributos).lexema, num_total_varlocs);
                              }
#line 1555 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 212 "alfa.y" /* yacc.c:1646  */
    {
                                /* La funcion no existia y la metemos en tabla simbolos */
                                if (BusquedaElemento(tabla, (yyvsp[0].atributos).lexema) == NULL){
                                  strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
                                  /* Abrimos ambito local de tipo funcion en la tabla */
                                  AperturaAmbito(tabla, (yyvsp[0].atributos).lexema, 0, 0);
                                  /* Reseteamos los valores */
                                  tamanio = 1;
                                  num_total_varlocs = 0;
                                  posicion_parametro = 0;
                                  num_total_parametros = 0;
                                  funcion_retorno = 0;
                                  funcion_tipo = tipo;
                                }
                                /* La funcion ya existe */
                                else{
                                  printf("****Error semantico en lin %lu: Declaracion duplicada\n", nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                              }
#line 1581 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 235 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1587 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 237 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R24:\t<parametros_funcion> ::= \n");}
#line 1593 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 240 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1599 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 242 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R26:\t<resto_parametros_funcion> ::= \n");}
#line 1605 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 245 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
                               num_total_parametros++;
                               posicion_parametro++;}
#line 1613 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 250 "alfa.y" /* yacc.c:1646  */
    {
                               if(BusquedaEnAmbitoActual(tabla, (yyvsp[0].atributos).lexema) == NULL){
                                if(InsercionElemento(tabla, (yyvsp[0].atributos).lexema, PARAMETRO, tipo, ESCALAR, 1, 0, posicion_parametro, 0, 0) == FATAL_ERROR){
                                  printf("****Error en la tabla de simbolos\n");
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                               }else{
                                 printf("****Error semantico en lin %lu: Declaracion duplicada.\n", nlines);
                                 LiberarTablas(tabla);
                                 return -1;
                               }
                              }
#line 1631 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 264 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
#line 1637 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 266 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R29:\t<declaraciones_funcion> ::= \n");}
#line 1643 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 269 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R30:\t<sentencias> ::= <sentencia>\n");}
#line 1649 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 271 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
#line 1655 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 274 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
#line 1661 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 276 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R33:\t<sentencia> ::= <bloque>\n");}
#line 1667 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 279 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R34:\t<sentencia_simple> ::= <asignacion>\n");}
#line 1673 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 281 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R35:\t<sentencia_simple> ::= <lectura>\n");}
#line 1679 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 283 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R36:\t<sentencia_simple> ::= <escritura>\n");}
#line 1685 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 285 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
#line 1691 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 288 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R40:\t<bloque> ::= <condicional>\n");}
#line 1697 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 290 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R41:\t<bloque> ::= <bucle>\n");}
#line 1703 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 293 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R43:\t<asignacion> ::= <identificador> = <exp>\n");
                                simbolo *simbolo;
                                if((simbolo = BusquedaElemento(tabla, (yyvsp[-2].atributos).lexema)) == NULL){
                                  printf("****Error semantico en lin %lu: Acceso a variable no declarada (%s)\n", nlines, (yyvsp[-2].atributos).lexema);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                if (simbolo->categoria_estructura == VECTOR) {
                                  printf("****Error semantico en lin %lu: Asignacion incompatible. \n", nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                if (simbolo->categoria == FUNCION) {
                                  printf("****Error semantico en lin %lu: Asignacion incompatible. \n", nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }

                                if (simbolo->tipo != (yyvsp[0].atributos).tipo) {
                                  printf("****Error semantico en lin %lu: Asignacion incompatible. \n", nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                if(Ambito(tabla) == GLOBAL){
                                  asignar(yyout, (yyvsp[-2].atributos).lexema, (yyvsp[0].atributos).es_direccion);
                                }else{
                                  escribirVariableLocal(yyout,simbolo->posicion);
                                  asignarDestinoEnPila(yyout,(yyvsp[0].atributos).es_direccion);
                                }
                              }
#line 1739 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 325 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}
#line 1745 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 328 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
                              simbolo *simbolo;
                              if ((simbolo = BusquedaElemento(tabla, (yyvsp[-3].atributos).lexema)) == NULL){
                                printf("****Error semantico en lin %lu: Acceso a variable no declarada (%s).\n", nlines, (yyvsp[-3].atributos).lexema);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              if (simbolo->categoria_estructura != VECTOR) {
                                printf("****Error semantico en lin %lu: Intento de indexacion que no es de tipo vector.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              if ((yyvsp[-1].atributos).tipo != ENTERO) {
                                printf("****Error semantico en lin %lu: El indice en una operacion de indexacion tiene que ser de tipo entero.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              (yyval.atributos).tipo = simbolo->tipo;
                              (yyval.atributos).es_direccion = 1;
                              (yyval.atributos).valor_entero = (yyvsp[-1].atributos).valor_entero;
                              //TODO USAR AQUI EL Escribir elemento vector
                              }
#line 1772 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 352 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
                              ifthen_fin(yyout, (yyvsp[-4].atributos).etiqueta);
                              }
#line 1780 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 356 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
                              ifthenelse_fin(yyout, (yyvsp[-4].atributos).etiqueta);
                              }
#line 1788 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 361 "alfa.y" /* yacc.c:1646  */
    {
                              if ((yyvsp[0].atributos).tipo != BOOLEANO) {
                                printf("****Error semantico en lin %lu: Condicional con condicion tipo int.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              (yyval.atributos).etiqueta = etiqueta++;
                              ifthen_inicio(yyout, (yyvsp[0].atributos).es_direccion, (yyval.atributos).etiqueta);
                              }
#line 1802 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 372 "alfa.y" /* yacc.c:1646  */
    {
                              (yyval.atributos).etiqueta = (yyvsp[-4].atributos).etiqueta;
                              ifthenelse_fin_then(yyout, (yyval.atributos).etiqueta);
                              }
#line 1811 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 378 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
                              while_fin(yyout, (yyvsp[-3].atributos).etiqueta);
                              }
#line 1819 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 383 "alfa.y" /* yacc.c:1646  */
    {
                              if ((yyvsp[-1].atributos).tipo != BOOLEANO) {
                                printf("****Error semantico en lin %lu: Condicional con condicion tipo int.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }

                              (yyval.atributos).etiqueta =(yyvsp[-3].atributos).etiqueta;
                              while_exp_pila(yyout, (yyvsp[-1].atributos).es_direccion, (yyval.atributos).etiqueta);
                              }
#line 1834 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 395 "alfa.y" /* yacc.c:1646  */
    {
                              (yyval.atributos).etiqueta = etiqueta++;
                              while_inicio(yyout, (yyval.atributos).etiqueta);
                              }
#line 1843 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 401 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R54:\t<lectura> ::= scanf <identificador>\n");
                               simbolo *simbolo;
                               simbolo = BusquedaElemento(tabla, (yyvsp[0].atributos).lexema);

                               /* Si el simbolo no estaba declarado */
                               if (simbolo == NULL){
                                printf("****Error semantico en lin %lu: Acceso a variable no declarada (%s).\n", nlines, (yyvsp[0].atributos).lexema);
                                LiberarTablas(tabla);
                                return -1;
                               }
                               /* Solo leemos ESCALAR y VARIABLE o PARAMETRO */
                               if (simbolo->categoria_estructura == VECTOR || simbolo->categoria == FUNCION){
                                printf("****Error semantico en lin %lu: Variable local de tipo no escalar.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                               }
                              leer(yyout, (yyvsp[0].atributos).lexema, simbolo->tipo);}
#line 1865 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 420 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R56:\t<escritura> ::= printf <exp>\n");
                               operandoEnPilaAArgumento(yyout, (yyvsp[0].atributos).es_direccion);
                               escribir(yyout, 0, (yyvsp[0].atributos).tipo);}
#line 1873 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 425 "alfa.y" /* yacc.c:1646  */
    {if (dentro_par_fun == 1){
                                printf("****Error semantico en lin %lu: Sentencia de retorno fuera del cuerpo de una funcion.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              fprintf(yyout,";R61:\t<retorno_funcion> ::= return <exp>\n");
                              if (funcion_tipo != (yyvsp[0].atributos).tipo){
                                printf("****Error semantico en lin %lu: Tipo incorrecto en retorno.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              funcion_retorno++;
                              retornarFuncion(yyout, (yyvsp[0].atributos).es_direccion);}
#line 1891 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 440 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R72:\t<exp> ::= <exp> + <exp>\n");
                                if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Operacion aritmetica con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                sumar(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
                                (yyval.atributos).tipo = ENTERO;
                                (yyval.atributos).es_direccion = 0;
                              }
#line 1907 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 452 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R73:\t<exp> ::= <exp> - <exp>\n");
                                if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Operacion aritmetica con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                restar(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
                                (yyval.atributos).tipo = ENTERO;
                                (yyval.atributos).es_direccion = 0;
                              }
#line 1923 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 464 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R74:\t<exp> ::= <exp> / <exp>\n");
                                if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Operacion aritmetica con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                dividir(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
                                (yyval.atributos).tipo = ENTERO;
                                (yyval.atributos).es_direccion = 0;
                              }
#line 1939 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 476 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R75:\t<exp> ::= <exp> * <exp>\n");
                                if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Operacion aritmetica con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                multiplicar(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
                                (yyval.atributos).tipo = ENTERO;
                                (yyval.atributos).es_direccion = 0;
                              }
#line 1955 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 488 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R76:\t<exp> ::= - <exp>\n");
                                if((yyvsp[0].atributos).tipo == BOOLEANO){
                                  printf("****Error semantico en lin %lu: Operacion aritmetica con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                cambiar_signo(yyout, (yyvsp[0].atributos).es_direccion);
                                (yyval.atributos).tipo = ENTERO;
                                (yyval.atributos).es_direccion = 0;
                              }
#line 1971 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 500 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R77:\t<exp> ::= exp> && <exp>\n");
                                if(((yyvsp[-2].atributos).tipo == ENTERO) || ((yyvsp[0].atributos).tipo == ENTERO)){
                                  printf("****Error semantico en lin %lu: Operacion logica con operandos int.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                y(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
                                (yyval.atributos).tipo = BOOLEANO;
                                (yyval.atributos).es_direccion = 0;
                              }
#line 1987 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 512 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R78:\t<exp> ::= <exp> || <exp>\n");
                                if(((yyvsp[-2].atributos).tipo == ENTERO) || ((yyvsp[0].atributos).tipo == ENTERO)){
                                  printf("****Error semantico en lin %lu: Operacion logica con operandos int.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                o(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
                                (yyval.atributos).tipo = BOOLEANO;
                                (yyval.atributos).es_direccion = 0;
                              }
#line 2003 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 524 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R79:\t<exp> ::= ! <exp>\n");
                                if((yyvsp[0].atributos).tipo == ENTERO){
                                  printf("****Error semantico en lin %lu: Operacion logica con operandos int.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                no(yyout, (yyvsp[0].atributos).es_direccion, etiqueta);
                                etiqueta++;
                                (yyval.atributos).tipo = BOOLEANO;
                                (yyval.atributos).es_direccion = 0;
                              }
#line 2020 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 537 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R80:\t<exp> ::= <identificador>\n");
                              simbolo *simbolo;
                              if ((simbolo = BusquedaElemento(tabla, (yyvsp[0].atributos).lexema)) == NULL){
                                printf("****Error semantico en lin %lu: Acceso a variable no declarada (%s).\n", nlines, (yyvsp[0].atributos).lexema);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              if (simbolo->categoria == FUNCION || simbolo->categoria_estructura == VECTOR) {
                                printf("****Error semantico en lin %lu: Asignacion incompatible.\n", nlines); //DUDA: No se si es este error
                                LiberarTablas(tabla);
                                return -1;
                              }
                              (yyval.atributos).tipo = simbolo->tipo;
                              (yyval.atributos).es_direccion = 1;
                              if (simbolo->categoria == PARAMETRO) {
                                escribirParametro(yyout, simbolo->posicion, num_total_parametros);
                              } else if (simbolo->categoria == VARIABLE) {
                                  if (Ambito(tabla) == LOCAL) {
                                    escribirVariableLocal(yyout, simbolo->posicion_varloc);
                                  }
                                  else {
                                    escribir_operando(yyout, (yyvsp[0].atributos).lexema, 1);
                                    if ( dentro_par_fun == 1){
                                      operandoEnPilaAArgumento(yyout, 1);
                                    }
                                  }
                              }}
#line 2052 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 565 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R81:\t<exp> ::= <constante>\n");
                                (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
                              }
#line 2061 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 570 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R82:\t<exp> ::= ( <exp> )\n");
                                (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
                              }
#line 2070 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 575 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R83:\t<exp> ::= ( <comparacion> )\n");
                                (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
                              }
#line 2079 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 580 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R85:\t<exp> ::= <elemento_vector>\n");
                                (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
                              }
#line 2088 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 585 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");
                              simbolo *simbolo;
                              if ((simbolo = BusquedaElemento(tabla, (yyvsp[-3].atributos).lexema)) == NULL) {
                                printf("****Error semantico en lin %lu: Acceso a variable no declarada (%s).\n", nlines, (yyvsp[-3].atributos).lexema);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              if (num_arg_funcion == simbolo->n_parametros) {
                                printf("****Error semantico en lin %lu: Numero incorrecto de parametros en llamada a función.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              (yyval.atributos).tipo = simbolo->tipo;
                              llamarFuncion(yyout, (yyvsp[-3].atributos).lexema, simbolo->n_parametros);
                              limpiarPila(yyout, simbolo->n_parametros);
                              dentro_par_fun = 0;
                              }
#line 2110 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 604 "alfa.y" /* yacc.c:1646  */
    {
                                simbolo *simbolo;
                                if (dentro_par_fun == 1){
                                  printf("****Error semantico en lin %lu: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n", nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                if ((simbolo = BusquedaElemento(tabla, (yyvsp[0].atributos).lexema)) == NULL){
                                  printf("****Error semantico en lin %lu: Acceso a variable no declarada (%s).\n", nlines, (yyvsp[0].atributos).lexema);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                if (simbolo->categoria != FUNCION) {
                                  printf("****Error semantico en lin %lu: Intento de llamar a una variable en vez de funcion.\n", nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                num_arg_funcion = 0;
                                dentro_par_fun = 1;
                                strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
                              }
#line 2136 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 627 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
                                if(dentro_par_fun == 1){
                                  num_arg_funcion++;
                                }
                              }
#line 2147 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 634 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R90:\t<lista_expresiones> ::= \n");}
#line 2153 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 637 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");
                                if(dentro_par_fun == 1){
                                  num_arg_funcion++;
                                }
                              }
#line 2164 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 644 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R92:\t<resto_lista_expresiones> ::= \n");}
#line 2170 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 647 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R93:\t<comparacion> ::= <exp> == <exp>\n");
                                if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Comparacion con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                igual(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
                                etiqueta++;
                                (yyval.atributos).tipo = BOOLEANO;
                                (yyval.atributos).es_direccion = 0;
                              }
#line 2187 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 660 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R94:\t<comparacion> ::= <exp> != <exp>\n");
                                if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Comparacion con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                distinto(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
                                etiqueta++;
                                (yyval.atributos).tipo = BOOLEANO;
                                (yyval.atributos).es_direccion = 0;
                              }
#line 2204 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 673 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R95:\t<comparacion> ::= <exp> <= <exp>\n");
                                if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Comparacion con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                menor_igual(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
                                etiqueta++;
                                (yyval.atributos).tipo = BOOLEANO;
                                (yyval.atributos).es_direccion = 0;
                              }
#line 2221 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 686 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R96:\t<comparacion> ::= <exp> >= <exp>\n");
                                if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Comparacion con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                mayor_igual(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
                                etiqueta++;
                                (yyval.atributos).tipo = BOOLEANO;
                                (yyval.atributos).es_direccion = 0;
                              }
#line 2238 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 699 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R97:\t<comparacion> ::= <exp> < <exp>\n");
                                if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Comparacion con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                menor(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
                                etiqueta++;
                                (yyval.atributos).tipo = BOOLEANO;
                                (yyval.atributos).es_direccion = 0;
                              }
#line 2255 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 712 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R98:\t<comparacion> ::= <exp> > <exp>\n");
                                if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Comparacion con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                mayor(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
                                etiqueta++;
                                (yyval.atributos).tipo = BOOLEANO;
                                (yyval.atributos).es_direccion = 0;
                              }
#line 2272 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 726 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R99:\t<constante> ::= <constante_logica>\n");
                                (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
                              }
#line 2282 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 732 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R100:\t<constante> ::= <constante_entera>\n");
                                (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
                              }
#line 2292 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 739 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R102:\t<constante_logica> ::= true\n");
                                (yyval.atributos).tipo = BOOLEANO;
                                (yyval.atributos).es_direccion = 0;
                                char v[1];
                                sprintf(v,"1");
                                escribir_operando(yyout,v,0);
                              }
#line 2305 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 748 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R103:\t<constante_logica> ::= false\n");
                                (yyval.atributos).tipo = BOOLEANO;
                                (yyval.atributos).es_direccion = 0;
                                char v[1];
                                sprintf(v,"0");
                                escribir_operando(yyout,v,0);
                              }
#line 2318 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 758 "alfa.y" /* yacc.c:1646  */
    {
                                fprintf(yyout,";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");
                                (yyval.atributos).tipo = ENTERO;
                                (yyval.atributos).es_direccion = 0;
                                (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
                                char v[MAX_TAM_ENTERO];
                                sprintf(v,"%d",(yyval.atributos).valor_entero);
                                escribir_operando(yyout,v,0);
                              }
#line 2332 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 769 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout,";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
                               /* Si la variable no estaba declarada antes, la declaramos */
                               if (BusquedaEnAmbitoActual(tabla, (yyvsp[0].atributos).lexema) == NULL){
                                if (Ambito(tabla) == LOCAL){
                                  num_total_varlocs++;
                                  posicion++;
                                  InsercionElemento(tabla, (yyvsp[0].atributos).lexema, VARIABLE, tipo, categoria_estructura, tamanio, num_total_parametros, posicion, 0, num_total_varlocs);
                                }
                                if (Ambito(tabla) == GLOBAL){
                                  InsercionElemento(tabla, (yyvsp[0].atributos).lexema, VARIABLE, tipo, categoria_estructura, tamanio, num_total_parametros, posicion, 0, num_total_varlocs);
                                  declarar_variable(yyout, (yyvsp[0].atributos).lexema, tipo, tamanio);
                                }
                               }
                               /* Ya existia la variable luego error por duplicado*/
                               else{
                                printf("****Error semantico en lin %lu: Declaracion duplicada.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                               }}
#line 2356 "alfa.tab.c" /* yacc.c:1646  */
    break;


#line 2360 "alfa.tab.c" /* yacc.c:1646  */
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
#line 788 "alfa.y" /* yacc.c:1906  */


void yyerror(const char *s){
  extern size_t nlines;
  extern size_t ncols;
  extern int err_morf;
  extern int yyleng;
  if(!err_morf){
    printf("****Error sintáctico en [lin %lu col %lu]\n",nlines, ncols-yyleng);
    return;
  }
  err_morf = 0;
  return;
}
