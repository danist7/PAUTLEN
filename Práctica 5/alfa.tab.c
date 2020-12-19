/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "alfa.y"

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

int dentro_llamada_fun = 0;         /* Esta a 1 si estamos si estamos dentro de los parentesis de una funcion y a 0 si estamos fuera */
int categoria_estructura;       /* Es ESCALAR o VECTOR */
int posicion_parametro = 0;     /* Solo para elementos de tipo parametro, posicion en orden, empieza por 0 */
int posicion = 0;               /* Solo para variables locales, su posición */
int num_arg_funcion = 0;        /* Numero de parametros al LLAMAR a una funcion */

#line 98 "alfa.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 30 "alfa.y"

  tipo_atributos atributos;

#line 195 "alfa.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ALFA_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
static const yytype_int16 yyrline[] =
{
       0,   103,   103,   108,   118,   123,   128,   130,   133,   136,
     139,   143,   147,   150,   154,   169,   171,   174,   176,   179,
     202,   217,   240,   242,   245,   247,   250,   256,   270,   272,
     275,   277,   280,   282,   285,   287,   289,   291,   294,   296,
     299,   331,   351,   380,   384,   389,   400,   406,   411,   423,
     429,   448,   453,   468,   480,   492,   504,   516,   528,   540,
     552,   565,   593,   598,   603,   608,   613,   632,   655,   662,
     665,   672,   675,   688,   701,   714,   727,   740,   754,   760,
     767,   776,   786,   797
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
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-68)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      13,   -38,     6,     9,   -38,     7,   -38,   -38,    14,   -38,
       7,    31,   -38,   -38,   -38,    21,    33,   -38,   -38,    32,
      34,    46,    14,   -38,    33,    23,    35,   -38,    31,    36,
      49,    23,   -38,   -12,    37,   -38,    53,     1,     1,    43,
      23,    42,   -38,   -38,    60,   -38,    48,    75,   -38,    55,
      69,   -38,   -38,   -38,    14,   -38,   -38,   -38,    65,     1,
       1,     1,   -38,   -11,   -38,     1,     1,     1,   -38,   -38,
     -38,    44,    79,   -38,   -38,   -38,    44,   -38,   -38,   -38,
       1,    85,    86,    23,     1,   106,    91,    95,   -38,   110,
      44,    44,    66,    99,    17,   -38,     1,     1,     1,     1,
       1,     1,     1,    44,    23,    23,    97,   100,   -38,   -38,
     101,    14,   -38,   -38,   -38,     1,     1,     1,     1,     1,
       1,   -38,    17,    17,   -38,   -38,   -38,    17,    87,   102,
     109,   111,   -38,   -38,     7,    95,    44,    44,    44,    44,
      44,    44,     1,   -38,   -38,   122,   -38,   -38,   -38,   -38,
      87,   -38
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     0,     1,     0,    12,    13,     0,     4,
       6,     0,     9,    11,    10,     0,    18,     7,    83,     0,
      15,     0,     0,     5,    18,     0,     0,     8,     0,     0,
       0,     0,    17,     0,     0,    49,     0,     0,     0,     0,
      30,     0,    33,    34,     0,    38,     0,     0,    39,     0,
       0,    35,    36,    37,    23,    16,    14,    21,     0,     0,
       0,     0,    50,    61,    82,     0,     0,     0,    80,    81,
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
static const yytype_int8 yypgoto[] =
{
     -38,   -38,   -38,   -38,   -38,   -10,   -38,   -38,   -38,    -5,
     -38,    94,   117,   -38,   -38,   -38,   -38,     8,    38,   -38,
     -38,   -29,   -38,   -38,   -38,   -38,   -15,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -37,   -38,   -38,    -8,
     -38,   -38,   -38,   -38,   -38
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    16,    31,     9,    10,    11,    12,    13,
      14,    19,    23,    24,    25,    26,    86,   112,    87,   109,
     148,    39,    40,    41,    42,    43,    70,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    71,    72,   129,   143,
      93,    73,    74,    75,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    76,    58,    15,    63,    64,     4,   -67,    59,    59,
      44,    78,    60,     6,     7,     8,    44,    30,     1,    65,
       6,     7,    89,    90,    91,    44,    33,    66,    92,    94,
      95,     5,    67,    34,    18,    35,    36,    37,    38,    68,
      69,    21,    22,   103,    98,    99,   100,   107,    27,    85,
      29,    28,    57,    54,   106,    61,    62,    56,    79,   122,
     123,   124,   125,   126,   127,   128,    77,    81,    44,    96,
      97,    98,    99,   100,   101,   130,   131,    83,   136,   137,
     138,   139,   140,   141,    80,   114,    82,    84,    88,    44,
      44,    96,    97,    98,    99,   100,   101,   102,   115,   116,
     117,   118,   119,   120,   142,   150,    85,   104,   105,   108,
     110,   111,    96,    97,    98,    99,   100,   101,   121,   133,
     132,   144,    55,   134,   147,    96,    97,    98,    99,   100,
     101,   113,   145,   -46,   146,    96,    97,    98,    99,   100,
     101,    32,   151,   149,     0,     0,     0,     0,     0,   135
};

static const yytype_int16 yycheck[] =
{
      10,    38,    31,     8,     3,     4,     0,    18,    20,    20,
      25,    40,    24,     6,     7,     8,    31,    22,     5,    18,
       6,     7,    59,    60,    61,    40,     3,    26,    65,    66,
      67,    22,    31,    10,     3,    12,    13,    14,    15,    38,
      39,    20,     9,    80,    27,    28,    29,    84,    16,    54,
       4,    17,     3,    18,    83,    18,     3,    21,    16,    96,
      97,    98,    99,   100,   101,   102,    23,    19,    83,    25,
      26,    27,    28,    29,    30,   104,   105,    22,   115,   116,
     117,   118,   119,   120,    24,    19,    11,    18,    23,   104,
     105,    25,    26,    27,    28,    29,    30,    18,    32,    33,
      34,    35,    36,    37,    17,   142,   111,    22,    22,     3,
      19,    16,    25,    26,    27,    28,    29,    30,    19,    19,
      23,    19,    28,    22,   134,    25,    26,    27,    28,    29,
      30,    21,    23,    11,    23,    25,    26,    27,    28,    29,
      30,    24,   150,   135,    -1,    -1,    -1,    -1,    -1,   111
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    42,    43,     0,    22,     6,     7,     8,    46,
      47,    48,    49,    50,    51,    50,    44,    46,     3,    52,
      85,    20,     9,    53,    54,    55,    56,    16,    17,     4,
      50,    45,    53,     3,    10,    12,    13,    14,    15,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    18,    52,    21,     3,    62,    20,
      24,    18,     3,     3,     4,    18,    26,    31,    38,    39,
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
static const yytype_int8 yyr1[] =
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
static const yytype_int8 yyr2[] =
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

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 104 "alfa.y"
                              {fprintf(yyout,";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
                               escribir_fin(yyout);
                               LiberarTablas(tabla);}
#line 1491 "alfa.tab.c"
    break;

  case 3:
#line 109 "alfa.y"
                              {  tabla = CrearTablas();
                                if(tabla == NULL){
                                  printf("No existe la tabla de símbolos\n");
                                  return -1;
                                }
                                escribir_subseccion_data(yyout);
                                escribir_cabecera_bss(yyout);
                              }
#line 1504 "alfa.tab.c"
    break;

  case 4:
#line 119 "alfa.y"
                              {
                               escribir_segmento_codigo(yyout);
                              }
#line 1512 "alfa.tab.c"
    break;

  case 5:
#line 124 "alfa.y"
                              {
                               escribir_inicio_main(yyout);
                              }
#line 1520 "alfa.tab.c"
    break;

  case 6:
#line 129 "alfa.y"
                              {fprintf(yyout,";R2:\t<declaraciones> ::= <declaracion>\n");}
#line 1526 "alfa.tab.c"
    break;

  case 7:
#line 131 "alfa.y"
                              {fprintf(yyout,";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
#line 1532 "alfa.tab.c"
    break;

  case 8:
#line 134 "alfa.y"
                              {fprintf(yyout,";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");}
#line 1538 "alfa.tab.c"
    break;

  case 9:
#line 137 "alfa.y"
                              {fprintf(yyout,";R5:\t<clase> ::= <clase_escalar>\n");
                               categoria_estructura = ESCALAR;}
#line 1545 "alfa.tab.c"
    break;

  case 10:
#line 140 "alfa.y"
                              {fprintf(yyout,";R7:\t<clase> ::= <clase_vector>\n");
                               categoria_estructura = VECTOR;}
#line 1552 "alfa.tab.c"
    break;

  case 11:
#line 144 "alfa.y"
                              {fprintf(yyout,";R9:\t<clase_escalar> ::= <tipo>\n");
                               tamanio = 1;}
#line 1559 "alfa.tab.c"
    break;

  case 12:
#line 148 "alfa.y"
                              {fprintf(yyout,";R10:\t<tipo> ::= int\n");
                               tipo = ENTERO;}
#line 1566 "alfa.tab.c"
    break;

  case 13:
#line 151 "alfa.y"
                              {fprintf(yyout,";R11:\t<tipo> ::= boolean\n");
                               tipo = BOOLEANO;}
#line 1573 "alfa.tab.c"
    break;

  case 14:
#line 155 "alfa.y"
                              {fprintf(yyout,";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
                              tamanio = (yyvsp[-1].atributos).valor_entero;
                              if(tamanio <= 0 || tamanio > MAX_TAMANIO_VECTOR){
                                printf("****Error semantico en lin %lu: El tamanyo del vector excede los limites permitidos (1,64).\n", nlines); //TODO en el enunciado nos piden aqui dar el nombre del vector pero no se puede
                                LiberarTablas(tabla);
                                return -1;
                              }
                              if (Ambito(tabla) == LOCAL) {
                                printf("****Error semantico en lin %lu: Declaracion de vector en ambito local.\n", nlines); //DUDA: He puesto esto para el error 15 pero no estoy seguro
                                LiberarTablas(tabla);
                                return -1;
                              }
                              }
#line 1591 "alfa.tab.c"
    break;

  case 15:
#line 170 "alfa.y"
                              {fprintf(yyout,";R18:\t<identificadores> ::= <identificador>\n");}
#line 1597 "alfa.tab.c"
    break;

  case 16:
#line 172 "alfa.y"
                              {fprintf(yyout,";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
#line 1603 "alfa.tab.c"
    break;

  case 17:
#line 175 "alfa.y"
                              {fprintf(yyout,";R20:\t<funciones> ::= <funcion> <funciones>\n");}
#line 1609 "alfa.tab.c"
    break;

  case 18:
#line 177 "alfa.y"
                              {fprintf(yyout,";R21:\t<funciones> ::= \n");}
#line 1615 "alfa.tab.c"
    break;

  case 19:
#line 180 "alfa.y"
                              {
                              fprintf(yyout,";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");
                              if (funcion_retorno < 1){
                                printf("****Error semantico en lin %lu : Funcion %s sin sentencia de retorno\n", nlines, (yyvsp[-2].atributos).lexema);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              CierreAmbito(tabla);
                              // Tras cerrar el simbolo guardamos la informacion pertinente en el simbolo de la tabla global
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
#line 1641 "alfa.tab.c"
    break;

  case 20:
#line 203 "alfa.y"
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
#line 1659 "alfa.tab.c"
    break;

  case 21:
#line 218 "alfa.y"
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
#line 1685 "alfa.tab.c"
    break;

  case 22:
#line 241 "alfa.y"
                              {fprintf(yyout,";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1691 "alfa.tab.c"
    break;

  case 23:
#line 243 "alfa.y"
                              {fprintf(yyout,";R24:\t<parametros_funcion> ::= \n");}
#line 1697 "alfa.tab.c"
    break;

  case 24:
#line 246 "alfa.y"
                              {fprintf(yyout,";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1703 "alfa.tab.c"
    break;

  case 25:
#line 248 "alfa.y"
                              {fprintf(yyout,";R26:\t<resto_parametros_funcion> ::= \n");}
#line 1709 "alfa.tab.c"
    break;

  case 26:
#line 251 "alfa.y"
                              {fprintf(yyout,";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
                               num_total_parametros++;
                               posicion_parametro++;
                              }
#line 1718 "alfa.tab.c"
    break;

  case 27:
#line 257 "alfa.y"
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
#line 1736 "alfa.tab.c"
    break;

  case 28:
#line 271 "alfa.y"
                              {fprintf(yyout,";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
#line 1742 "alfa.tab.c"
    break;

  case 29:
#line 273 "alfa.y"
                              {fprintf(yyout,";R29:\t<declaraciones_funcion> ::= \n");}
#line 1748 "alfa.tab.c"
    break;

  case 30:
#line 276 "alfa.y"
                              {fprintf(yyout,";R30:\t<sentencias> ::= <sentencia>\n");}
#line 1754 "alfa.tab.c"
    break;

  case 31:
#line 278 "alfa.y"
                              {fprintf(yyout,";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
#line 1760 "alfa.tab.c"
    break;

  case 32:
#line 281 "alfa.y"
                              {fprintf(yyout,";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
#line 1766 "alfa.tab.c"
    break;

  case 33:
#line 283 "alfa.y"
                              {fprintf(yyout,";R33:\t<sentencia> ::= <bloque>\n");}
#line 1772 "alfa.tab.c"
    break;

  case 34:
#line 286 "alfa.y"
                              {fprintf(yyout,";R34:\t<sentencia_simple> ::= <asignacion>\n");}
#line 1778 "alfa.tab.c"
    break;

  case 35:
#line 288 "alfa.y"
                              {fprintf(yyout,";R35:\t<sentencia_simple> ::= <lectura>\n");}
#line 1784 "alfa.tab.c"
    break;

  case 36:
#line 290 "alfa.y"
                              {fprintf(yyout,";R36:\t<sentencia_simple> ::= <escritura>\n");}
#line 1790 "alfa.tab.c"
    break;

  case 37:
#line 292 "alfa.y"
                              {fprintf(yyout,";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
#line 1796 "alfa.tab.c"
    break;

  case 38:
#line 295 "alfa.y"
                              {fprintf(yyout,";R40:\t<bloque> ::= <condicional>\n");}
#line 1802 "alfa.tab.c"
    break;

  case 39:
#line 297 "alfa.y"
                              {fprintf(yyout,";R41:\t<bloque> ::= <bucle>\n");}
#line 1808 "alfa.tab.c"
    break;

  case 40:
#line 300 "alfa.y"
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
#line 1844 "alfa.tab.c"
    break;

  case 41:
#line 332 "alfa.y"
                              {fprintf(yyout,";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
                                simbolo *simbolo;
                                if ((simbolo = BusquedaElemento(tabla, (yyvsp[-2].atributos).lexema)) == NULL){
                                  printf("****Error semantico en lin %lu: Acceso a variable no declarada (%s).\n", nlines, (yyvsp[-2].atributos).lexema);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                if ((yyvsp[-2].atributos).tipo != (yyvsp[0].atributos).tipo) {
                                  printf("****Error semantico en lin %lu: Asignacion incompatible.\n", nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                char aux[MAX_TAM_ENTERO];
                                sprintf(aux, "%d", (yyvsp[-2].atributos).valor_entero);
                                escribir_operando(yyout, aux, 0);
                                escribir_elemento_vector(yyout, simbolo->identificador, simbolo->tamanio, (yyvsp[0].atributos).es_direccion);
                                asignarDestinoEnPila(yyout, (yyvsp[0].atributos).es_direccion);
                              }
#line 1867 "alfa.tab.c"
    break;

  case 42:
#line 352 "alfa.y"
                              {fprintf(yyout,";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
                              simbolo *simbolo;
                              if ((simbolo = BusquedaElemento(tabla, (yyvsp[-3].atributos).lexema)) == NULL){
                                printf("****Error semantico en lin %lu: Acceso a variable no declarada (%s).\n", nlines, (yyvsp[-3].atributos).lexema);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              if (Ambito(tabla) == LOCAL) {
                                printf("****Error semantico en lin %lu: Acceso vector en ambito local.\n", nlines); //DUDA: Error extra
                                LiberarTablas(tabla);
                                return -1;
                              }
                              if (simbolo->categoria_estructura != VECTOR) {
                                printf("****Error semantico en lin %lu: Intento de indexacion de una variable que no es de tipo vector.\n", nlines);
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
                              escribir_elemento_vector(yyout, simbolo->identificador, simbolo->tamanio, (yyvsp[-1].atributos).es_direccion);
                              }
#line 1899 "alfa.tab.c"
    break;

  case 43:
#line 381 "alfa.y"
                              {fprintf(yyout,";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
                              ifthen_fin(yyout, (yyvsp[-4].atributos).etiqueta);
                              }
#line 1907 "alfa.tab.c"
    break;

  case 44:
#line 385 "alfa.y"
                              {fprintf(yyout,";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
                              ifthenelse_fin(yyout, (yyvsp[-4].atributos).etiqueta);
                              }
#line 1915 "alfa.tab.c"
    break;

  case 45:
#line 390 "alfa.y"
                              {
                              if ((yyvsp[0].atributos).tipo != BOOLEANO) {
                                printf("****Error semantico en lin %lu: Condicional con condicion de tipo int.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              (yyval.atributos).etiqueta = etiqueta++;
                              ifthen_inicio(yyout, (yyvsp[0].atributos).es_direccion, (yyval.atributos).etiqueta);
                              }
#line 1929 "alfa.tab.c"
    break;

  case 46:
#line 401 "alfa.y"
                              {
                              (yyval.atributos).etiqueta = (yyvsp[-4].atributos).etiqueta;
                              ifthenelse_fin_then(yyout, (yyval.atributos).etiqueta);
                              }
#line 1938 "alfa.tab.c"
    break;

  case 47:
#line 407 "alfa.y"
                              {fprintf(yyout,";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
                              while_fin(yyout, (yyvsp[-3].atributos).etiqueta);
                              }
#line 1946 "alfa.tab.c"
    break;

  case 48:
#line 412 "alfa.y"
                              {
                              if ((yyvsp[-1].atributos).tipo != BOOLEANO) {
                                printf("****Error semantico en lin %lu: Bucle con condicion de tipo int.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }

                              (yyval.atributos).etiqueta =(yyvsp[-3].atributos).etiqueta;
                              while_exp_pila(yyout, (yyvsp[-1].atributos).es_direccion, (yyval.atributos).etiqueta);
                              }
#line 1961 "alfa.tab.c"
    break;

  case 49:
#line 424 "alfa.y"
                              {
                              (yyval.atributos).etiqueta = etiqueta++;
                              while_inicio(yyout, (yyval.atributos).etiqueta);
                              }
#line 1970 "alfa.tab.c"
    break;

  case 50:
#line 430 "alfa.y"
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
#line 1992 "alfa.tab.c"
    break;

  case 51:
#line 449 "alfa.y"
                              {fprintf(yyout,";R56:\t<escritura> ::= printf <exp>\n");
                               operandoEnPilaAArgumento(yyout, (yyvsp[0].atributos).es_direccion);
                               escribir(yyout, 0, (yyvsp[0].atributos).tipo);}
#line 2000 "alfa.tab.c"
    break;

  case 52:
#line 454 "alfa.y"
                              {if (dentro_llamada_fun == 1){
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
#line 2018 "alfa.tab.c"
    break;

  case 53:
#line 469 "alfa.y"
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
#line 2034 "alfa.tab.c"
    break;

  case 54:
#line 481 "alfa.y"
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
#line 2050 "alfa.tab.c"
    break;

  case 55:
#line 493 "alfa.y"
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
#line 2066 "alfa.tab.c"
    break;

  case 56:
#line 505 "alfa.y"
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
#line 2082 "alfa.tab.c"
    break;

  case 57:
#line 517 "alfa.y"
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
#line 2098 "alfa.tab.c"
    break;

  case 58:
#line 529 "alfa.y"
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
#line 2114 "alfa.tab.c"
    break;

  case 59:
#line 541 "alfa.y"
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
#line 2130 "alfa.tab.c"
    break;

  case 60:
#line 553 "alfa.y"
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
#line 2147 "alfa.tab.c"
    break;

  case 61:
#line 566 "alfa.y"
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
                                escribirParametro(yyout, simbolo->posicion, posicion_parametro);
                              } else if (simbolo->categoria == VARIABLE) {
                                  if (Ambito(tabla) == LOCAL) {
                                    escribirVariableLocal(yyout, simbolo->posicion_varloc);
                                  }
                                  else {
                                    escribir_operando(yyout, (yyvsp[0].atributos).lexema, 1);
                                    if ( dentro_llamada_fun == 1){
                                      operandoEnPilaAArgumento(yyout, 1);
                                    }
                                  }
                              }}
#line 2179 "alfa.tab.c"
    break;

  case 62:
#line 594 "alfa.y"
                              {fprintf(yyout,";R81:\t<exp> ::= <constante>\n");
                                (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
                              }
#line 2188 "alfa.tab.c"
    break;

  case 63:
#line 599 "alfa.y"
                              {fprintf(yyout,";R82:\t<exp> ::= ( <exp> )\n");
                                (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
                              }
#line 2197 "alfa.tab.c"
    break;

  case 64:
#line 604 "alfa.y"
                              {fprintf(yyout,";R83:\t<exp> ::= ( <comparacion> )\n");
                                (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
                              }
#line 2206 "alfa.tab.c"
    break;

  case 65:
#line 609 "alfa.y"
                              {fprintf(yyout,";R85:\t<exp> ::= <elemento_vector>\n");
                                (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
                              }
#line 2215 "alfa.tab.c"
    break;

  case 66:
#line 614 "alfa.y"
                              {fprintf(yyout,";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");
                              simbolo *simbolo;
                              if ((simbolo = BusquedaElemento(tabla, (yyvsp[-3].atributos).lexema)) == NULL) {
                                printf("****Error semantico en lin %lu: Acceso a variable no declarada (%s).\n", nlines, (yyvsp[-3].atributos).lexema);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              if (num_arg_funcion != simbolo->n_parametros) {
                                printf("****Error semantico en lin %lu: Numero incorrecto de parametros en llamada a función.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              (yyval.atributos).tipo = simbolo->tipo;
                              llamarFuncion(yyout, (yyvsp[-3].atributos).lexema, simbolo->n_parametros);
                              limpiarPila(yyout, simbolo->n_parametros);
                              dentro_llamada_fun = 0;
                              }
#line 2237 "alfa.tab.c"
    break;

  case 67:
#line 633 "alfa.y"
                              {
                                simbolo *simbolo;
                                if (dentro_llamada_fun == 1){
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
                                dentro_llamada_fun = 1;
                                strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
                              }
#line 2263 "alfa.tab.c"
    break;

  case 68:
#line 656 "alfa.y"
                              {
                                fprintf(yyout,";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
                                if(dentro_llamada_fun == 1){
                                  num_arg_funcion++;
                                }
                              }
#line 2274 "alfa.tab.c"
    break;

  case 69:
#line 663 "alfa.y"
                              {fprintf(yyout,";R90:\t<lista_expresiones> ::= \n");}
#line 2280 "alfa.tab.c"
    break;

  case 70:
#line 666 "alfa.y"
                              {
                                fprintf(yyout,";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");
                                if(dentro_llamada_fun == 1){
                                  num_arg_funcion++;
                                }
                              }
#line 2291 "alfa.tab.c"
    break;

  case 71:
#line 673 "alfa.y"
                              {fprintf(yyout,";R92:\t<resto_lista_expresiones> ::= \n");}
#line 2297 "alfa.tab.c"
    break;

  case 72:
#line 676 "alfa.y"
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
#line 2314 "alfa.tab.c"
    break;

  case 73:
#line 689 "alfa.y"
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
#line 2331 "alfa.tab.c"
    break;

  case 74:
#line 702 "alfa.y"
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
#line 2348 "alfa.tab.c"
    break;

  case 75:
#line 715 "alfa.y"
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
#line 2365 "alfa.tab.c"
    break;

  case 76:
#line 728 "alfa.y"
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
#line 2382 "alfa.tab.c"
    break;

  case 77:
#line 741 "alfa.y"
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
#line 2399 "alfa.tab.c"
    break;

  case 78:
#line 755 "alfa.y"
                              {
                                fprintf(yyout,";R99:\t<constante> ::= <constante_logica>\n");
                                (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
                              }
#line 2409 "alfa.tab.c"
    break;

  case 79:
#line 761 "alfa.y"
                              {
                                fprintf(yyout,";R100:\t<constante> ::= <constante_entera>\n");
                                (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
                                (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
                              }
#line 2419 "alfa.tab.c"
    break;

  case 80:
#line 768 "alfa.y"
                              {
                                fprintf(yyout,";R102:\t<constante_logica> ::= true\n");
                                (yyval.atributos).tipo = BOOLEANO;
                                (yyval.atributos).es_direccion = 0;
                                char v[1];
                                sprintf(v,"1");
                                escribir_operando(yyout,v,0);
                              }
#line 2432 "alfa.tab.c"
    break;

  case 81:
#line 777 "alfa.y"
                              {
                                fprintf(yyout,";R103:\t<constante_logica> ::= false\n");
                                (yyval.atributos).tipo = BOOLEANO;
                                (yyval.atributos).es_direccion = 0;
                                char v[1];
                                sprintf(v,"0");
                                escribir_operando(yyout,v,0);
                              }
#line 2445 "alfa.tab.c"
    break;

  case 82:
#line 787 "alfa.y"
                              {
                                fprintf(yyout,";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");
                                (yyval.atributos).tipo = ENTERO;
                                (yyval.atributos).es_direccion = 0;
                                (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
                                char v[MAX_TAM_ENTERO];
                                sprintf(v,"%d",(yyval.atributos).valor_entero);
                                escribir_operando(yyout,v,0);
                              }
#line 2459 "alfa.tab.c"
    break;

  case 83:
#line 798 "alfa.y"
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
#line 2483 "alfa.tab.c"
    break;


#line 2487 "alfa.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 817 "alfa.y"


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
