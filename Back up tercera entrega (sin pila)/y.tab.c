
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 3 "EA3.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "y.tab.h"
#include "arbol.h"
#include "structs.h"
#define YYERROR_VERBOSE 1
FILE  *yyin;

#define RENGLONES_IMPRESION_ARBOL 500
#define CARACTERES_RENGLON_ARBOL 1000

int contadorString = 0;
int endIf = 1;
int x = 500;

/* --- Tabla de simbolos --- */
typedef struct
{
        char *nombre;
        char *nombreASM;
        char *tipo;
        union Valor{
                int valor_int;
                char *valor_str;
        }valor;
        int longitud;
}t_data;

typedef struct s_simbolo
{
        t_data data;
        struct s_simbolo *next;
}t_simbolo;


typedef struct
{
        t_simbolo *primero;
}t_tabla;

void crearTablaTS();
int insertarTS(const char*, const char*, const char*, int, double);
t_data* crearDatos(const char*, const char*, const char*, int, double);
void guardarTS();
t_tabla tablaTS;

t_simbolo * getLexema(const char *);
char* limpiarString(char*, const char*);
char* reemplazarChar(char*, const char*, const char, const char);
char* reemplazarString(char*, const char*);
char* obtenerID(char*);
char* limpiarPivot(char*);

/* --- Arbol --- */
int num_nodo;
t_arbol programa;
t_nodo_arbol* SPtr;
t_nodo_arbol* ProgPtr;
t_nodo_arbol* SentPtr;
t_nodo_arbol* ReadPtr;
t_nodo_arbol* AsigPtr;
t_nodo_arbol* PosicionPtr;
t_nodo_arbol* ListaPtr;
t_nodo_arbol* WritePtr;
t_nodo_arbol* IdPtr;
t_nodo_arbol* CteSPtr;
t_nodo_arbol* CtePtr;
t_nodo_arbol* PosPtr; //Return de la funcion Posicion - se inicializa en 0
t_nodo_arbol* IdCompPtr; //este es el id que el usuario quiere encontrar
t_nodo_arbol* IfPtr; //Puntero al nodo IF
t_nodo_arbol* IfIzqPtr; //Puntero al nodo IF
t_nodo_arbol* IfDerPtr; //Puntero al nodo IF
t_nodo_arbol* CmpPtr; //seria el == de la comparacion del if
t_nodo_arbol* SaltoPtr; //a donde voy a saltar si encuentra la posicion
t_nodo_arbol* BiPtr; //puntero al salto incondicional
t_nodo_arbol* SumPunt; //puntero al simbolo "+"
t_nodo_arbol* UnoPtr; //1 para sumarle al pos
t_nodo_arbol* AuxPtr; //va a indicar en que posicion de la lista estoy - se inicializa en 1

t_simbolo *lexemaAsig;
t_simbolo *lexemaIzq;
t_simbolo *lexemaDer;

/* --- Assembler --- */
void generarAssembler();
void crearHeader(FILE *);
void crearSeccionData(FILE *);
void crearSeccionCode(FILE *);
void crearFooter(FILE *);



/* Line 189 of yacc.c  */
#line 170 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CTE = 258,
     ID = 259,
     CTE_S = 260,
     ASIGNA = 261,
     PARA = 262,
     PARC = 263,
     CA = 264,
     CC = 265,
     COMA = 266,
     PYC = 267,
     WRITE = 268,
     READ = 269,
     POSICION = 270
   };
#endif
/* Tokens.  */
#define CTE 258
#define ID 259
#define CTE_S 260
#define ASIGNA 261
#define PARA 262
#define PARC 263
#define CA 264
#define CC 265
#define COMA 266
#define PYC 267
#define WRITE 268
#define READ 269
#define POSICION 270




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 101 "EA3.y"

int tipo_int;
char* tipo_str;



/* Line 214 of yacc.c  */
#line 243 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 255 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   21

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  16
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  16
/* YYNRULES -- Number of states.  */
#define YYNSTATES  31

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      15
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    14,    16,    18,
      21,    25,    34,    42,    44,    48,    51
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      17,     0,    -1,    -1,    18,    19,    -1,    20,    -1,    19,
      20,    -1,    21,    -1,    25,    -1,    22,    -1,    14,     4,
      -1,     4,     6,    23,    -1,    15,     7,     4,    12,     9,
      24,    10,     8,    -1,    15,     7,     4,    12,     9,    10,
       8,    -1,     3,    -1,    24,    11,     3,    -1,    13,     5,
      -1,    13,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   129,   143,   147,   153,   157,   161,   167,
     178,   202,   212,   216,   247,   281,   290
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CTE", "ID", "CTE_S", "ASIGNA", "PARA",
  "PARC", "CA", "CC", "COMA", "PYC", "WRITE", "READ", "POSICION",
  "$accept", "S", "$@1", "prog", "sent", "read", "asig", "posicion",
  "lista", "write", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    16,    18,    17,    19,    19,    20,    20,    20,    21,
      22,    23,    23,    24,    24,    25,    25
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     2,
       3,     8,     7,     1,     3,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     3,     4,     6,
       8,     7,     0,    16,    15,     9,     5,     0,    10,     0,
       0,     0,     0,    13,     0,     0,    12,     0,     0,    11,
      14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     7,     8,     9,    10,    18,    25,    11
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -6
static const yytype_int8 yypact[] =
{
      -6,     2,    -4,    -6,     1,    -1,     7,    -4,    -6,    -6,
      -6,    -6,    -3,    -6,    -6,    -6,    -6,     6,    -6,    10,
       3,     8,    -2,    -6,    11,    -5,    -6,    12,    13,    -6,
      -6
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
      -6,    -6,    -6,    -6,    14,    -6,    -6,    -6,    -6,    -6
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       4,    23,     3,    13,    14,    27,    28,    12,    24,     5,
       6,    15,    17,    19,    20,    21,    30,    22,     0,    26,
      29,    16
};

static const yytype_int8 yycheck[] =
{
       4,     3,     0,     4,     5,    10,    11,     6,    10,    13,
      14,     4,    15,     7,     4,    12,     3,     9,    -1,     8,
       8,     7
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    18,     0,     4,    13,    14,    19,    20,    21,
      22,    25,     6,     4,     5,     4,    20,    15,    23,     7,
       4,    12,     9,     3,    10,    24,     8,    10,    11,     8,
       3
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 129 "EA3.y"
    {
        printf("\n\nInicia el COMPILADOR\n\n");
    }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 132 "EA3.y"
    {
        SPtr = ProgPtr;
        programa = SPtr;

        generarAssembler();
        guardarTS();
        printf("Regla 0\n");
        printf("\nCompilacion OK.\n");
    }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 143 "EA3.y"
    { printf("Regla 1\n"); 
           ProgPtr = SentPtr;
         }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 147 "EA3.y"
    { printf("Regla 2\n"); 
                ProgPtr = crear_nodo(&num_nodo, "SENT", NODO_SIN_TIPO, ProgPtr, SentPtr);
              }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 153 "EA3.y"
    { printf("Regla 3\n"); 
           SentPtr = ReadPtr;
         }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 157 "EA3.y"
    { printf("Regla 4\n"); 
            SentPtr = WritePtr;
          }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 161 "EA3.y"
    { printf("Regla 5\n"); 
           SentPtr = AsigPtr;
         }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 167 "EA3.y"
    { printf("Regla 6\n");
              char *valor = (char*) malloc(sizeof(char)*200);
              sprintf(valor,"%s",(yyvsp[(2) - (2)].tipo_str));
              valor[strlen(valor)] = '\0';

              IdPtr = crear_nodo(&num_nodo, valor, TIPO_INT, NULL, NULL);
              ReadPtr = crear_nodo(&num_nodo, "READ", NODO_SIN_TIPO, IdPtr, NULL);
            }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 178 "EA3.y"
    { printf("Regla 7\n");
                     
                         SaltoPtr = crear_nodo(&num_nodo, "@salto", AUX, NULL, NULL);

                         AsigPtr = crear_nodo(&num_nodo, ";", NODO_SIN_TIPO, SaltoPtr, AsigPtr);

                         char *valor = (char*) malloc(sizeof(char)*200);
                         sprintf(valor,"%s",(yyvsp[(1) - (3)].tipo_str));
                         obtenerID(valor);
                         limpiarString(valor,valor);
                         valor[strlen(valor)] = '\0';
                         IdPtr = crear_nodo(&num_nodo, valor, TIPO_INT, NULL, NULL);

                         /* char *posi = (char*) malloc(sizeof(char)*200);
                         sprintf(posi,"%s",$3);
                         posi[strlen(valor)] = '\0';
                         PosPtr = crear_nodo(&num_nodo, posi, TIPO_INT, NULL, NULL); */
                         PosPtr = crear_nodo(&num_nodo, "@pos", AUX, ListaPtr, AsigPtr);

                         AsigPtr = crear_nodo(&num_nodo, "ASIGNA", NODO_SIN_TIPO, IdPtr, PosPtr);
                       }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 202 "EA3.y"
    { printf("Regla 8\n"); 
                                            char *valor = (char*) malloc(sizeof(char)*200);
                                            sprintf(valor,"%s",(yyvsp[(3) - (8)].tipo_str));
                                            limpiarPivot(valor);
                                            valor[strlen(valor)] = '\0';
                                            IdPtr = crear_nodo(&num_nodo, valor, TIPO_INT, NULL, NULL);
                                            IdCompPtr = crear_nodo(&num_nodo, "@idComp", AUX, NULL, NULL);
                                            AsigPtr = crear_nodo(&num_nodo, "ASIGNA", NODO_SIN_TIPO, IdCompPtr, IdPtr);
                                          }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 212 "EA3.y"
    { printf("Regla 9\n"); }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 216 "EA3.y"
    { printf("Regla 10\n"); 
          char cad[20];

          //sumatoria del aux
          AuxPtr = crear_nodo(&num_nodo, "@aux", AUX, NULL, NULL);
          UnoPtr = crear_nodo(&num_nodo, "@1", AUX, NULL, NULL);
          SumPunt = crear_nodo(&num_nodo, "+", SUMA, AuxPtr, UnoPtr);

          //lado izquierdo (condicion)
          IfIzqPtr = crear_nodo(&num_nodo, "@idComp", AUX, SumPunt, NULL);

          char *valor = (char*) malloc(sizeof(char)*200);
          itoa((yyvsp[(1) - (1)].tipo_int), cad, 10);
          sprintf(valor,"%s",cad);
          valor[strlen(valor)] = '\0';
          IfDerPtr = crear_nodo(&num_nodo, valor, TIPO_INT, NULL, NULL);
          CmpPtr = crear_nodo(&num_nodo, "CMP", NODO_SIN_TIPO, IfIzqPtr, IfDerPtr);

          //lado derecho (guardar pos y salto)
          PosPtr = crear_nodo(&num_nodo, "@pos", AUX, NULL, NULL);
          AuxPtr = crear_nodo(&num_nodo, "@aux", AUX, NULL, NULL);
          AsigPtr = crear_nodo(&num_nodo, "ASIGNA", NODO_SIN_TIPO, PosPtr, AuxPtr);

          SaltoPtr = crear_nodo(&num_nodo, "@salto", AUX, NULL, NULL);

          BiPtr = crear_nodo(&num_nodo, "BI", NODO_SIN_TIPO, AsigPtr, SaltoPtr);
          
          //padre
          ListaPtr = crear_nodo(&num_nodo, "IF", NODO_SIN_TIPO, CmpPtr, BiPtr);
        }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 247 "EA3.y"
    { printf("Regla 11\n"); 
                     char cad[20];

                     //sumatoria del aux
                     AuxPtr = crear_nodo(&num_nodo, "@aux", AUX, NULL, NULL);
                     UnoPtr = crear_nodo(&num_nodo, "@1", AUX, NULL, NULL);
                     SumPunt = crear_nodo(&num_nodo, "+", SUMA, AuxPtr, UnoPtr);

                     //lado izquierdo (condicion)
                     IfIzqPtr = crear_nodo(&num_nodo, "@idComp", AUX, SumPunt, NULL);

                     char *valor = (char*) malloc(sizeof(char)*200);
                     itoa((yyvsp[(3) - (3)].tipo_int), cad, 10);
                     sprintf(valor,"%s",cad);
                     valor[strlen(valor)] = '\0';
                     IfDerPtr = crear_nodo(&num_nodo, valor, TIPO_INT, NULL, NULL);
                     CmpPtr = crear_nodo(&num_nodo, "CMP", NODO_SIN_TIPO, IfIzqPtr, IfDerPtr);

                     //lado derecho (guardar pos y salto)
                     PosPtr = crear_nodo(&num_nodo, "@pos", AUX, NULL, NULL);
                     AuxPtr = crear_nodo(&num_nodo, "@aux", AUX, NULL, NULL);
                     AsigPtr = crear_nodo(&num_nodo, "ASIGNA", NODO_SIN_TIPO, PosPtr, AuxPtr);

                     SaltoPtr = crear_nodo(&num_nodo, "@salto", AUX, NULL, NULL);

                     BiPtr = crear_nodo(&num_nodo, "BI", NODO_SIN_TIPO, AsigPtr, SaltoPtr);

                     //padre
                     IfPtr = crear_nodo(&num_nodo, "IF", NODO_SIN_TIPO, CmpPtr, BiPtr);
                     ListaPtr = crear_nodo(&num_nodo, ";", NODO_SIN_TIPO, ListaPtr, IfPtr);
                   }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 281 "EA3.y"
    { printf("Regla 12\n"); 
                  char *valor = (char*) malloc(sizeof(char)*200);
                  sprintf(valor,"%s",(yyvsp[(2) - (2)].tipo_str));
                  valor[strlen(valor)] = '\0';

                  CteSPtr = crear_nodo(&num_nodo, valor, TIPO_STRING, NULL, NULL);
                  WritePtr = crear_nodo(&num_nodo, "WRITE",  NODO_SIN_TIPO, CteSPtr, NULL);
                }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 290 "EA3.y"
    { printf("Regla 13\n"); 
               char *valor = (char*) malloc(sizeof(char)*200);
               sprintf(valor,"%s",(yyvsp[(2) - (2)].tipo_str));
               valor[strlen(valor)] = '\0';

               IdPtr = crear_nodo(&num_nodo, valor, TIPO_INT, NULL, NULL);
               WritePtr = crear_nodo(&num_nodo, "WRITE", NODO_SIN_TIPO, IdPtr, NULL);
             }
    break;



/* Line 1455 of yacc.c  */
#line 1692 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 300 "EA3.y"


/*---- Código ----*/

int main(int argc, char *argv[])
{
    if((yyin = fopen(argv[1], "rt"))==NULL)
    {
        printf("\nNo se puede abrir el archivo de prueba: %s\r\n", argv[1]);
        return -1;
    }
    else
    { 
        armar_arbol(&programa);
        num_nodo = 1;

        yyparse();

        //system("Pause");
        escribir_archivo_txt(programa);
        crearTablaTS(); //tablaTS.primero = NULL;
        free_arbol(&programa);
        fclose(yyin);
        return 0;
    }
}

/*---- TS ----*/

int insertarTS(const char *nombre, const char *tipo, const char* valString, int valInt, double valDouble)
{
    t_simbolo *tabla = tablaTS.primero;
    char nombreCTE[50] = "_";
    strcat(nombreCTE, nombre);
    
    while(tabla)
    {
        if(strcmp(tabla->data.nombre, nombre) == 0 || strcmp(tabla->data.nombre, nombreCTE) == 0)
        {
            return 1;
        }
        
        if(tabla->next == NULL)
        {
            break;
        }
        tabla = tabla->next;
    }

    t_data *data = (t_data*)malloc(sizeof(t_data));
    data = crearDatos(nombre, tipo, valString, valInt, valDouble);

    if(data == NULL)
    {
        return 1;
    }

    t_simbolo* nuevo = (t_simbolo*)malloc(sizeof(t_simbolo));

    if(nuevo == NULL)
    {
        return 2;
    }

    nuevo->data = *data;
    nuevo->next = NULL;

    if(tablaTS.primero == NULL)
    {
        tablaTS.primero = nuevo;
    }
    else
    {
        tabla->next = nuevo;
    }

    return 0;
}

t_data* crearDatos(const char *nombre, const char *tipo, const char* valString, int valInt, double valDouble)
{
    char full[50] = "_";
    char aux[100];

    t_data *data = (t_data*)calloc(1, sizeof(t_data));
    if(data == NULL)
    {
        return NULL;
    }

    data->tipo = (char*)malloc(sizeof(char) * (strlen(tipo) + 1));
    strcpy(data->tipo, tipo);

    //Si es una variable
    if(strcmp(tipo, "INTEGER") == 0)
    {
        //Al nombre lo dejo aca porque no lleva _
        data->nombre = (char*)malloc(sizeof(char) * (strlen(nombre) + 1));
        strcpy(data->nombre, nombre);
        data->nombreASM = (char*)malloc(sizeof(char) * (strlen(nombre) + 1));
        strcpy(data->nombreASM, nombre);
        return data;
    }
    else if(strcmp(tipo, "CTE_S") == 0)
    { 
        contadorString++;

        data->valor.valor_str = (char*)malloc(sizeof(char) * strlen(valString) +1);
        strcpy(data->valor.valor_str, valString);

        char auxString[50];
        strcpy(full, ""); 
        strcpy(full, "S_");
        reemplazarString(auxString, nombre);
        strcat(full, auxString);
        char numero[10];
        sprintf(numero, "_%d", contadorString);
        strcat(full, numero);


        data->nombre = (char*)malloc(sizeof(char) * (strlen(valString) + 1));
        data->nombreASM = (char*)malloc(sizeof(char) * (strlen(full) + 1));
        strcpy(data->nombre, full);
        strcpy(data->nombreASM, data->nombre);
        return data;   
    }
    else if(strcmp(tipo, "CTE") == 0)
    {
        data->valor.valor_int = valInt;
        sprintf(aux, "%d", valInt);
        strcat(full, aux);
        data->nombre = (char*)malloc(sizeof(char) * (strlen(full) + 1));
        data->nombre = (char*)malloc(sizeof(char) * strlen(full));
        strcpy(data->nombre, full);
        data->nombreASM = (char*)malloc(sizeof(char) * (strlen(full) + 1));
        strcpy(data->nombreASM, full);
        return data;
    }
    return NULL;
}

void guardarTS()
{
    FILE* arch;
    if((arch = fopen("ts.txt", "wt")) == NULL)
    {
            printf("\nNo se pudo crear la tabla de simbolos.\n\n");
            return;
    }
    else if(tablaTS.primero == NULL)
            return;
    
    fprintf(arch, "%-50s%-25s%-50s%-30s\n", "NOMBRE", "TIPODATO", "VALOR", "LONGITUD");

    t_simbolo *aux;
    t_simbolo *tabla = tablaTS.primero;
    char linea[160];

    while(tabla)
    {
        aux = tabla;
        tabla = tabla->next;
        
        if(strcmp(aux->data.tipo, "INTEGER") == 0) //variable int
        {
            sprintf(linea, "%-50s%-25s%-50s%-ld\n", aux->data.nombre, aux->data.tipo, "--", strlen(aux->data.nombre));
        }
        else if(strcmp(aux->data.tipo, "CTE") == 0)
        {
            sprintf(linea, "%-50s%-25s%-50d%-ld\n", aux->data.nombre, aux->data.tipo, aux->data.valor.valor_int, strlen(aux->data.nombre));
        }
        else if(strcmp(aux->data.tipo, "CTE_S") == 0)
        {
            sprintf(linea, "%-50s%-25s%-50s%-ld\n", aux->data.nombre, aux->data.tipo, aux->data.valor.valor_str, strlen(aux->data.nombre));
        }
        fprintf(arch, "%s", linea);
        free(aux);
    }
    fclose(arch); 
}

void crearTablaTS()
{
    tablaTS.primero = NULL;
}

t_simbolo * getLexema(const char *valor){
    t_simbolo *lexema;
    t_simbolo *tablaSimbolos = tablaTS.primero;

    char nombreLimpio[32];
    limpiarString(nombreLimpio, valor);
    char nombreCTE[32] = "_";
    strcat(nombreCTE, nombreLimpio);
    int esID, esCTE, esASM, esValor =-1;

    while(tablaSimbolos){  
        esID = strcmp(tablaSimbolos->data.nombre, nombreLimpio);
        esCTE = strcmp(tablaSimbolos->data.nombre, nombreCTE);
        esASM = strcmp(tablaSimbolos->data.nombreASM, valor);

        if(strcmp(tablaSimbolos->data.tipo, "CTE_S") == 0)
        {
            esValor = strcmp(valor, tablaSimbolos->data.valor.valor_str);
        }

        if(esID == 0 || esCTE == 0 || esASM == 0 || esValor == 0)
        { 
            lexema = tablaSimbolos;
            return lexema;
        }
        tablaSimbolos = tablaSimbolos->next;
    }
    return NULL;
}

/*    Funciones extras    */

char* limpiarString(char* dest, const char* cad)
{
    int i, longitud, j=0;
    longitud = strlen(cad);
    for(i=0; i<longitud; i++)
    {
        if(cad[i] != '"')
        {
            dest[j] = cad[i];
            j++;
        }
    }
    dest[j] = '\0';
    return dest;
}

char* reemplazarChar(char* dest, const char* cad, const char viejo, const char nuevo)
{
    int i, longitud;
    longitud = strlen(cad);

    for(i=0; i<longitud; i++)
    {
        if(cad[i] == viejo)
        {
            dest[i] = nuevo;
        }
        else
        {
            dest[i] = cad[i];
        }
    }
    dest[i] = '\0';
    return dest;
}

char* reemplazarString(char* dest, const char* cad)
{
    int i, longitud;
    longitud = strlen(cad);

    for(i=0; i<longitud; i++)
    {
        if((cad[i] >= 'a' && cad[i] <= 'z') || (cad[i] >='A' && cad[i] <= 'Z') || (cad[i] >= '0' && cad[i] <= '9'))
        {
            dest[i] = cad[i];
        }
        else
        {
            dest[i] = '_';
        }
    }
    dest[i] = '\0';
    return dest;
}

char* obtenerID(char* cadena)
{
    char* posAsig = strtok(cadena, "=");
    int i;

    for(i=0 ; i<strlen(cadena) ; i++) {
        if(cadena[i] == ' ') {
            cadena[i] = '\0';
        }
    }
    return cadena;
}

char* limpiarPivot(char* cadena)
{
    char* posAsig = strtok(cadena, ";");
    int i;

    for(i=0 ; i<strlen(cadena) ; i++) {
        if(cadena[i] == ' ') {
            cadena[i] = '\0';
        }
    }
    return cadena;
}

/* --- Árbol --- */

int armar_arbol(t_arbol *pa)
{
  t_nodo_arbol *pn = (t_nodo_arbol*) malloc(sizeof(t_nodo_arbol));
  if(pn == NULL) return SIN_MEMORIA;
  pn->numero = 0;
  strcpy(pn->valor,"PRG"); 
  pn->hijo_izq = NULL; 
  pn->hijo_der = NULL; 
  *pa = pn;
  return OK;
}

t_nodo_arbol* crear_nodo(int *n, char *valor, int tipo, t_nodo_arbol *hizq, t_nodo_arbol *hder)
{
  t_nodo_arbol *pn = (t_nodo_arbol*) malloc (sizeof(t_nodo_arbol));
  if(pn == NULL) return NULL;
  pn->numero = *n;
  strcpy(pn->valor,valor);
  pn->tipo = tipo; 
  pn->hijo_izq = hizq; 
  pn->hijo_der = hder; 
  *n = *n + 1;
  return pn;
}

void recorrer_arbol_posorden(t_arbol *pa, FILE *pf)
{
    if(!*pa) 
        return;
    if(!&(*pa)->hijo_izq)
    	return;

    recorrer_arbol_posorden(&(*pa)->hijo_izq,pf);
    recorrer_arbol_posorden(&(*pa)->hijo_der,pf);

	if(strcmpi((*pa)->valor,"READ")==0){
        t_simbolo *lexema = getLexema((*pa)->hijo_izq->valor);
        fprintf(pf, "getFloat %s\nNEWLINE\n\n", lexema->data.nombreASM);
  	}


	if(strcmpi((*pa)->valor,"WRITE")==0){
	    if ((*pa)->hijo_izq->tipo == TIPO_INT)
	    {
	      	fprintf(pf,"displayFloat %s,2\nNEWLINE\n\n",(*pa)->hijo_izq->valor);
	    }
	    else if ((*pa)->hijo_izq->tipo == TIPO_STRING)
	    {
            t_simbolo *lexema = getLexema((*pa)->hijo_izq->valor);
	      	fprintf(pf,"displayString %s\nNEWLINE\n\n",lexema->data.nombreASM);
	    }
  	}

    if(strcmpi((*pa)->valor,"ASIGNA")==0){
        //printf("encontre un asigna\n");
        
        if ((*pa)->hijo_der->tipo == TIPO_INT ) {
            lexemaDer = getLexema((*pa)->hijo_der->valor);
            fprintf(pf,"fld %s\n",lexemaDer->data.nombreASM);
        }
        else {
            fprintf(pf,"fld %s\n",(*pa)->hijo_der->valor);
        }

        if ((*pa)->hijo_izq->tipo == TIPO_INT ) {
            lexemaIzq = getLexema((*pa)->hijo_izq->valor);
            fprintf(pf,"fstp %s\n\n",lexemaIzq->data.nombreASM);
        }
        else {
            fprintf(pf,"fstp %s\n\n",(*pa)->hijo_izq->valor);
        }
    }

    if(strcmpi((*pa)->valor,"IF")==0){
        fprintf(pf, "branch%d:\n\n", endIf);
        endIf = endIf + 1; 
  	}

    if(strcmpi((*pa)->valor,"CMP")==0){

        if ((*pa)->hijo_der->tipo == TIPO_INT ) {
            lexemaDer = getLexema((*pa)->hijo_der->valor);
            fprintf(pf,"fld %s\n",lexemaDer->data.nombreASM);
        }
        else {
            fprintf(pf,"fld %s\n",(*pa)->hijo_der->valor);
        }

        if ((*pa)->hijo_izq->tipo == TIPO_INT ) {
            lexemaIzq = getLexema((*pa)->hijo_izq->valor);
            fprintf(pf,"fld %s\n",lexemaIzq->data.nombreASM);
        }
        else {
            fprintf(pf,"fld %s\n",(*pa)->hijo_izq->valor);
        }
        fprintf(pf, "fxch\nfcom\nfstsw AX\nsahf\n");
        fprintf(pf,"jne branch%d\n\n", endIf);
  	}

    if(strcmpi((*pa)->valor,"+")==0){
        
        fprintf(pf,"fld %s\n",(*pa)->hijo_der->valor);
        fprintf(pf,"fld %s\n",(*pa)->hijo_izq->valor);
        fprintf(pf,"fadd\n\n");
    }

    if(strcmpi((*pa)->valor,"BI")==0){
        fprintf(pf,"jmp branch%d\n\n",x);
    }

    if(strcmp((*pa)->valor,";")==0){
        //printf("encontre una coma\n");
        if((*pa)->hijo_izq->tipo == AUX) {
            fprintf(pf,"branch%d:\n\n",x);
        }
    }


    /* if(strcmpi((*pa)->valor,"MUL")==0){
        if (((*pa)->hijo_izq->tipo == TIPO_INT || (*pa)->hijo_izq->tipo == TIPO_CONST_INT) && ((*pa)->hijo_der->tipo == TIPO_INT || (*pa)->hijo_der->tipo == TIPO_CONST_INT))
        {
            lexemaIzq = getLexema((*pa)->hijo_izq->valor);
            lexemaDer = getLexema((*pa)->hijo_der->valor);

            fprintf(pf,"\tfld \t\t\t%s\n\t",lexemaIzq->data.nombreASM);
            fprintf(pf,"\tfld \t\t\t%s\n\t",lexemaDer->data.nombreASM);
        }
        fprintf(pf,"\tfmul \n\t");
    } */
    
    /* if(strcmpi((*pa)->valor,"MAS")==0){

        if (((*pa)->hijo_izq->tipo == TIPO_INT || (*pa)->hijo_izq->tipo == TIPO_CONST_INT) && ((*pa)->hijo_der->tipo == TIPO_INT || (*pa)->hijo_der->tipo == TIPO_CONST_INT))
        {
            lexemaIzq = getLexema((*pa)->hijo_izq->valor);
            lexemaDer = getLexema((*pa)->hijo_der->valor);

            fprintf(pf,"\tfld \t\t\t%s\n\t",lexemaIzq->data.nombreASM);
            fprintf(pf,"\tfld \t\t\t%s\n\t",lexemaDer->data.nombreASM);
        }
        fprintf(pf,"\tfadd \n\t");
    } */
    
    /* if(strcmpi((*pa)->valor,"DIV")==0){
        if (((*pa)->hijo_izq->tipo == TIPO_INT || (*pa)->hijo_izq->tipo == TIPO_CONST_INT) && ((*pa)->hijo_der->tipo == TIPO_INT || (*pa)->hijo_der->tipo == TIPO_CONST_INT))
        {
            lexemaIzq = getLexema((*pa)->hijo_izq->valor);
            lexemaDer = getLexema((*pa)->hijo_der->valor);

            fprintf(pf,"\tfld \t\t\t%s\n\t",lexemaIzq->data.nombreASM);
            fprintf(pf,"\tfld \t\t\t%s\n\t",lexemaDer->data.nombreASM);
        }
        fprintf(pf,"\tfdiv \n\t");
    } */
    
}

void free_nodo(t_nodo_arbol* pn)
{
    if(pn == NULL) return;
    free_nodo(pn->hijo_izq);
    pn->hijo_izq = NULL;
    free_nodo(pn->hijo_der);
    pn->hijo_der = NULL;
    free(pn);
    pn = NULL;
}

void free_arbol(t_arbol *pa)
{
    free_nodo(*pa);
}

t_nodo_arbol* copiar_nodo(int *n, t_nodo_arbol* pn)
{
  t_nodo_arbol *pnn = (t_nodo_arbol*) malloc (sizeof(t_nodo_arbol));
  if(pn == NULL) return NULL;
  pnn->numero = *n;
  strcpy(pnn->valor,pn->valor); 
  pnn->tipo = pn->tipo; 
  
  *n = *n + 1; 
  
  if(pn->hijo_izq == NULL){
    pnn->hijo_izq = NULL; 
  }else{
      pnn->hijo_izq = copiar_nodo(n,pn->hijo_izq); 
  }
  
  if(pn->hijo_der == NULL){
    pnn->hijo_der = NULL; 
  }else{
      pnn->hijo_der = copiar_nodo(n,pn->hijo_der); 
  }
  
  
  return pnn;
}

void copiar_sin_finalizador(char * dest,char * orig) 
{
    
    while(*orig && *dest)
    {
        *dest = *orig;
        orig++;
        dest++;     
    }
}

int _print_t(t_nodo_arbol *tree, int is_left, int offset, int depth, char * s, int max)
{
    int i;
    char b[50];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%s)", tree->valor);

    int left  = _print_t(tree->hijo_izq,  1, offset, depth + 1, s,max);
    int right = _print_t(tree->hijo_der, 0, offset + left + width, depth + 1, s,max);

    copiar_sin_finalizador(s + (2 * depth)*max + offset + left,b);

    if (depth && is_left) {

      for (i = 0; i < width + right; i++)
                copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset + left + width/2 + i,"-"); 
                copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset + left + width/2 ,"+"); 
                copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset + left + width + right + width/2 ,"+"); 

    } else if (depth && !is_left) {
        for (i = 0; i < left + width; i++)
            copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset - width/2 + i ,"-"); 
            copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset + left + width/2 ,"+"); 
    }

    return left + width + right;
}

int escribir_archivo_txt(t_nodo_arbol *tree)
{
    
  FILE *f = fopen("Intermedia.txt", "w+");
    if (f == NULL)
    {
        puts("Error abriendo archivo de notacion intermedia");
        exit(1);
    }
    int i;
  char * s = (char *) malloc(sizeof(char) * RENGLONES_IMPRESION_ARBOL * CARACTERES_RENGLON_ARBOL);

  for (i = 0; i < RENGLONES_IMPRESION_ARBOL * CARACTERES_RENGLON_ARBOL; i++)
  {
    if(i == 0 || i % (CARACTERES_RENGLON_ARBOL - 1))
        sprintf(s + i, "%c", ' ');
    else
        sprintf(s + i, "%c", '\0');
  }

    _print_t(tree, 0, 0, 0, s,CARACTERES_RENGLON_ARBOL);

    for (i = 0; i < RENGLONES_IMPRESION_ARBOL; i++)
    {
        fprintf(f, "%s\n", s + i*CARACTERES_RENGLON_ARBOL);
    }    
    fclose(f);
}

/* --- Funciones para Assembler --- */

void generarAssembler(){
    FILE* archAssembler = fopen("Final.asm","wt");

    crearHeader(archAssembler);
    crearSeccionData(archAssembler);
    crearSeccionCode(archAssembler);
    printf("antes del arbol\n");
    recorrer_arbol_posorden(&programa, archAssembler);
    printf("despues del arbol\n");
    crearFooter(archAssembler);
    fclose(archAssembler);
}

void crearHeader(FILE *archAssembler){
    fprintf(archAssembler, "%s\n%s\n\n", "include number.asm", "include macros2.asm");
    fprintf(archAssembler, "%-30s%-30s\n", ".MODEL LARGE", "; Modelo de memoria");
    fprintf(archAssembler, "%-30s%-30s\n", ".386", "; Tipo de procesador");
    fprintf(archAssembler, "%-30s%-30s\n\n", ".STACK 200h", "; Bytes en el stack");
}

void crearSeccionData(FILE *archAssembler){
    t_simbolo *aux;
    t_simbolo *tablaSimbolos = tablaTS.primero;

    fprintf(archAssembler, "%s\n\n", ".DATA");

    while(tablaSimbolos){
        aux = tablaSimbolos;
        tablaSimbolos = tablaSimbolos->next;
        
        if(strcmp(aux->data.tipo, "INTEGER") == 0){
            fprintf(archAssembler, "%-15s%-15s%-15s%-15s\n", aux->data.nombreASM, "dd", "?", "; Variable int");
        }
        else if(strcmp(aux->data.tipo, "CTE") == 0){ 
            char valor[50];
            sprintf(valor, "%d.0", aux->data.valor.valor_int);
            fprintf(archAssembler, "%-15s%-15s%-15s%-15s\n", aux->data.nombreASM, "dd", valor, "; Constante int");
        }
        else if(strcmp(aux->data.tipo, "CTE_S") == 0){
            char valor[150];
            sprintf(valor, "%s, '$', %d dup (?)",aux->data.valor.valor_str, strlen(aux->data.valor.valor_str) - 2);
            fprintf(archAssembler, "%-50s%-10s%-44s%-15s\n", aux->data.nombreASM, "db", valor, "; Constante string");
        }
    }
    fprintf(archAssembler, "%-15s%-15s%-15s%-15s\n", "@salto", "dd", "10.0", "; lugar a donde voy a saltar");
    fprintf(archAssembler, "%-15s%-15s%-15s%-15s\n", "@pos", "dd", "-1.0", "; primera posicion encontrada en la lista");
    fprintf(archAssembler, "%-15s%-15s%-15s%-15s\n", "@idComp", "dd", "-1.0", "; pivot ingresado por el usuario");
    fprintf(archAssembler, "%-15s%-15s%-15s%-15s\n", "@aux", "dd", "0.0", "; posicion de la lista en la que voy");
    fprintf(archAssembler, "%-15s%-15s%-15s%-15s\n", "@1", "dd", "1.0", "; constante para incrementar @aux");
}

void crearSeccionCode(FILE *archAssembler){
    fprintf(archAssembler, "\n%s\n\n%s\n\n", ".CODE", "inicio:");
    fprintf(archAssembler, "%-30s%-30s\n", "mov AX,@DATA", "; Inicializa el segmento de datos");
    fprintf(archAssembler, "%-30s\n%-30s\n\n", "mov DS,AX", "mov ES,AX");
}

void crearFooter(FILE *archAssembler){
    fprintf(archAssembler, "\n%-30s%-30s\n", "mov AX,4C00h", "; Indica que debe finalizar la ejecución");
    fprintf(archAssembler, "%s\n\n%s", "int 21h", "END inicio");
}
