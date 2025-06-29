/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "trad.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
int yyerror(const char *s);
extern int yylineno;

int indent_level = 1;

char* indent() {
    int i;
    int size = indent_level + 1;
    char* buf = malloc(size);
    for(i = 0; i < indent_level; i++) {
        buf[i] = '\t';  // un tab por nivel
    }
    buf[indent_level] = '\0';
    return buf;
}   

char* indent_lines(const char* code) {
    char* result = malloc(strlen(code) * 2);
    result[0] = '\0';
    char* temp = strdup(code);
    char* line = strtok(temp, "\n");
    while (line != NULL) {
        char* ind = indent();
        strcat(result, ind);
        strcat(result, line);
        strcat(result, "\n");
        free(ind);
        line = strtok(NULL, "\n");
    }
    free(temp);
    return result;
}

#line 111 "trad.tab.c"

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

#include "trad.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_REAL = 6,                       /* REAL  */
  YYSYMBOL_DBL_COLON = 7,                  /* DBL_COLON  */
  YYSYMBOL_PRINT = 8,                      /* PRINT  */
  YYSYMBOL_ENDPROGRAM = 9,                 /* ENDPROGRAM  */
  YYSYMBOL_ENDDO = 10,                     /* ENDDO  */
  YYSYMBOL_DO = 11,                        /* DO  */
  YYSYMBOL_IMPLICIT = 12,                  /* IMPLICIT  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_THEN = 14,                      /* THEN  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_ENDIF = 16,                     /* ENDIF  */
  YYSYMBOL_GE = 17,                        /* GE  */
  YYSYMBOL_LE = 18,                        /* LE  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_NE = 20,                        /* NE  */
  YYSYMBOL_AND = 21,                       /* AND  */
  YYSYMBOL_OR = 22,                        /* OR  */
  YYSYMBOL_WRITE = 23,                     /* WRITE  */
  YYSYMBOL_READ = 24,                      /* READ  */
  YYSYMBOL_SELECTCASE = 25,                /* SELECTCASE  */
  YYSYMBOL_CASE = 26,                      /* CASE  */
  YYSYMBOL_CASEDEFAULT = 27,               /* CASEDEFAULT  */
  YYSYMBOL_ENDSELECT = 28,                 /* ENDSELECT  */
  YYSYMBOL_EXIT = 29,                      /* EXIT  */
  YYSYMBOL_CYCLE = 30,                     /* CYCLE  */
  YYSYMBOL_LOGICAL = 31,                   /* LOGICAL  */
  YYSYMBOL_TRUE = 32,                      /* TRUE  */
  YYSYMBOL_FALSE = 33,                     /* FALSE  */
  YYSYMBOL_CHARACTER = 34,                 /* CHARACTER  */
  YYSYMBOL_ID = 35,                        /* ID  */
  YYSYMBOL_NUMBER = 36,                    /* NUMBER  */
  YYSYMBOL_STRING = 37,                    /* STRING  */
  YYSYMBOL_COMENTARIO = 38,                /* COMENTARIO  */
  YYSYMBOL_39_ = 39,                       /* ':'  */
  YYSYMBOL_40_ = 40,                       /* '+'  */
  YYSYMBOL_41_ = 41,                       /* '-'  */
  YYSYMBOL_42_ = 42,                       /* '*'  */
  YYSYMBOL_43_ = 43,                       /* '/'  */
  YYSYMBOL_44_ = 44,                       /* '>'  */
  YYSYMBOL_45_ = 45,                       /* '<'  */
  YYSYMBOL_46_ = 46,                       /* '='  */
  YYSYMBOL_47_ = 47,                       /* ','  */
  YYSYMBOL_48_n_ = 48,                     /* '\n'  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_program = 52,                   /* program  */
  YYSYMBOL_program_body = 53,              /* program_body  */
  YYSYMBOL_declarations = 54,              /* declarations  */
  YYSYMBOL_declaration = 55,               /* declaration  */
  YYSYMBOL_id_list = 56,                   /* id_list  */
  YYSYMBOL_statements = 57,                /* statements  */
  YYSYMBOL_statement = 58,                 /* statement  */
  YYSYMBOL_case_blocks = 59,               /* case_blocks  */
  YYSYMBOL_case_block = 60,                /* case_block  */
  YYSYMBOL_expression = 61                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   360

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      49,    50,    42,    40,    47,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,     2,
      45,    46,    44,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    74,    84,    85,    94,   101,   108,   115,
     125,   130,   135,   140,   150,   151,   157,   165,   169,   177,
     184,   191,   198,   205,   212,   222,   230,   239,   250,   259,
     266,   273,   282,   288,   292,   302,   310,   319,   320,   321,
     322,   328,   334,   340,   346,   352,   358,   364,   370,   376,
     382,   388,   394,   395
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "END",
  "INTEGER", "REAL", "DBL_COLON", "PRINT", "ENDPROGRAM", "ENDDO", "DO",
  "IMPLICIT", "IF", "THEN", "ELSE", "ENDIF", "GE", "LE", "EQ", "NE", "AND",
  "OR", "WRITE", "READ", "SELECTCASE", "CASE", "CASEDEFAULT", "ENDSELECT",
  "EXIT", "CYCLE", "LOGICAL", "TRUE", "FALSE", "CHARACTER", "ID", "NUMBER",
  "STRING", "COMENTARIO", "':'", "'+'", "'-'", "'*'", "'/'", "'>'", "'<'",
  "'='", "','", "'\\n'", "'('", "')'", "$accept", "program",
  "program_body", "declarations", "declaration", "id_list", "statements",
  "statement", "case_blocks", "case_block", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-15)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     287,   -39,   175,   -40,    -3,     2,     7,   -77,   -77,     9,
     -77,    60,    58,    26,    46,   -77,    28,    68,   144,   114,
      37,    38,   114,   114,   -77,    48,   114,   195,   -77,   114,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   217,    44,    49,
     228,   309,     6,   309,   -77,    45,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,    79,    56,
      57,   -20,    94,    95,   102,   106,   110,   195,     6,   114,
     -77,   -77,   -77,   -77,   246,   315,     0,     0,    86,    86,
     -77,   -77,   195,    75,    76,    78,   195,    -4,   -77,    97,
      97,    97,    97,   130,   -77,   -77,    99,    23,   114,   100,
     117,   -77,   -77,   -77,     3,   -77,   -77,   -77,   -77,   101,
     128,   195,   -77,   309,   -77,   -29,   114,    97,   -77,   -77,
     142,   125,   195,   262,   -77,   -77,   112,   -77,    97,   195,
     -77,   -77
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    20,    21,     0,
      31,     0,     0,    23,     0,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,    18,     0,
      25,    15,    52,    53,    39,    37,    38,     0,     0,     0,
       0,    19,     4,    22,    17,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     0,
      46,    47,    48,    49,    50,    51,    40,    41,    42,    43,
      44,    45,     0,     0,     0,     0,     0,     0,    33,     0,
       0,     0,     0,     0,     3,     5,     0,     0,     0,     0,
       0,    36,    28,    32,    10,     6,     7,     9,     8,     0,
       0,     0,    26,    29,    30,     0,     0,     0,     2,    24,
       0,     0,     0,    11,    12,    27,     0,    34,     0,     0,
      13,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   -77,    96,   -77,   -76,   -14,   163,   -77,    88,
     -21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    66,    67,    68,   105,    17,    18,    87,    88,
      37
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    40,    41,    13,    31,    43,    85,    86,    45,    19,
     121,    62,    63,    44,   106,   107,   108,    46,    47,    48,
      49,   122,    85,    86,   102,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    64,   111,   112,
      65,   124,    54,    55,    56,    57,    20,    14,    96,   116,
     117,    21,   130,    94,     1,    23,    22,     2,    15,     3,
      24,    25,    46,    47,    48,    49,    50,    51,    97,     4,
       5,     6,   101,    26,    29,     7,     8,   113,    30,    38,
      39,     9,   110,    42,    10,    52,    53,    54,    55,    56,
      57,    59,    69,    82,    27,   123,    60,   120,    83,    84,
      14,    89,    90,    46,    47,    48,    49,     1,   127,    91,
       2,    15,     3,    92,    93,   131,    46,    47,    48,    49,
      50,    51,     4,     5,     6,    98,    99,   100,     7,     8,
      56,    57,   104,   109,     9,   114,   118,    10,   119,    52,
      53,    54,    55,    56,    57,    14,    32,    33,   -14,    34,
      35,    36,     1,   115,   -14,     2,    15,     3,   125,   -14,
     -14,   126,   129,    12,    95,     0,     0,     4,     5,     6,
     -14,   -14,   -14,     7,     8,   103,    14,     0,     0,     9,
       0,     0,    10,     1,     0,     0,     2,    15,     3,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     4,     5,
       6,     0,     0,     1,     7,     8,     2,    15,     3,     0,
      16,     0,     0,    10,     0,     0,     0,     0,     4,     5,
       6,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       9,     0,     0,    10,    46,    47,    48,    49,    50,    51,
       0,     0,     0,     0,     0,    46,    47,    48,    49,    50,
      51,     0,     0,     0,     0,     0,     0,    52,    53,    54,
      55,    56,    57,    46,    47,    48,    49,    58,    52,    53,
      54,    55,    56,    57,     0,     0,     0,     0,    61,    46,
      47,    48,    49,    50,    51,     0,    52,    53,    54,    55,
      56,    57,     0,     0,     0,     1,     0,     0,     2,     0,
       3,     0,    52,    53,    54,    55,    56,    57,     0,   128,
       4,     5,     6,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     9,     0,     0,    10,    46,    47,    48,    49,
      50,    51,    46,    47,    48,    49,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,    55,    56,    57,    52,    53,    54,    55,    56,
      57
};

static const yytype_int16 yycheck[] =
{
      14,    22,    23,    42,    18,    26,    26,    27,    29,    49,
      39,     5,     6,    27,    90,    91,    92,    17,    18,    19,
      20,    50,    26,    27,    28,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    31,    15,    16,
      34,   117,    42,    43,    44,    45,    49,     1,    69,    46,
      47,    49,   128,    67,     8,    46,    49,    11,    12,    13,
       0,     3,    17,    18,    19,    20,    21,    22,    82,    23,
      24,    25,    86,    47,    46,    29,    30,    98,    10,    42,
      42,    35,    96,    35,    38,    40,    41,    42,    43,    44,
      45,    47,    47,    14,    48,   116,    47,   111,    42,    42,
       1,     7,     7,    17,    18,    19,    20,     8,   122,     7,
      11,    12,    13,     7,     4,   129,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    50,    50,    49,    29,    30,
      44,    45,    35,     3,    35,    35,    35,    38,    10,    40,
      41,    42,    43,    44,    45,     1,    32,    33,     4,    35,
      36,    37,     8,    36,    10,    11,    12,    13,    16,    15,
      16,    36,    50,     0,    68,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    87,     1,    -1,    -1,    35,
      -1,    -1,    38,     8,    -1,    -1,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    23,    24,
      25,    -1,    -1,     8,    29,    30,    11,    12,    13,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    23,    24,
      25,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    38,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    17,    18,    19,    20,    50,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    50,    17,
      18,    19,    20,    21,    22,    -1,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,     8,    -1,    -1,    11,    -1,
      13,    -1,    40,    41,    42,    43,    44,    45,    -1,    47,
      23,    24,    25,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    38,    17,    18,    19,    20,
      21,    22,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    40,    41,    42,    43,    44,
      45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    11,    13,    23,    24,    25,    29,    30,    35,
      38,    52,    58,    42,     1,    12,    35,    57,    58,    49,
      49,    49,    49,    46,     0,     3,    47,    48,    57,    46,
      10,    57,    32,    33,    35,    36,    37,    61,    42,    42,
      61,    61,    35,    61,    57,    61,    17,    18,    19,    20,
      21,    22,    40,    41,    42,    43,    44,    45,    50,    47,
      47,    50,     5,     6,    31,    34,    53,    54,    55,    47,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    14,    42,    42,    26,    27,    59,    60,     7,
       7,     7,     7,     4,    57,    54,    61,    57,    50,    50,
      49,    57,    28,    60,    35,    56,    56,    56,    56,     3,
      57,    15,    16,    61,    35,    36,    46,    47,    35,    10,
      57,    39,    50,    61,    56,    16,    36,    57,    47,    50,
      56,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    54,    54,    55,    55,    55,    55,
      56,    56,    56,    56,    57,    57,    57,    57,    57,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    60,    60,    60,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     2,     0,     2,     3,     3,     3,     3,
       1,     3,     3,     5,     1,     2,     1,     3,     2,     3,
       1,     1,     4,     2,     8,     3,     7,     9,     6,     7,
       7,     1,     2,     1,     5,     7,     2,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: statement PROGRAM ID program_body END PROGRAM ID  */
#line 68 "trad.y"
    {
        printf("#include <iostream>\nusing namespace std;\n\nint main() {\n%s\treturn 0;\n}\n", (yyvsp[-4].str));
    }
#line 1286 "trad.tab.c"
    break;

  case 3: /* program_body: declarations statements  */
#line 75 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 1);
        sprintf((yyval.str), "%s%s", (yyvsp[-1].str), (yyvsp[0].str));
        free((yyvsp[-1].str)); free((yyvsp[0].str));
    }
#line 1296 "trad.tab.c"
    break;

  case 4: /* declarations: %empty  */
#line 84 "trad.y"
     { (yyval.str) = strdup(""); }
#line 1302 "trad.tab.c"
    break;

  case 5: /* declarations: declaration declarations  */
#line 86 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 1);
        sprintf((yyval.str), "%s%s", (yyvsp[-1].str), (yyvsp[0].str));
        free((yyvsp[-1].str)); free((yyvsp[0].str));
    }
#line 1312 "trad.tab.c"
    break;

  case 6: /* declaration: INTEGER DBL_COLON id_list  */
#line 95 "trad.y"
    {
        char* ind = indent();
        (yyval.str) = malloc(strlen(ind) + strlen((yyvsp[0].str)) + 30);
        sprintf((yyval.str), "%sint %s = 0;\n", ind, (yyvsp[0].str));
        free(ind); free((yyvsp[0].str));
    }
#line 1323 "trad.tab.c"
    break;

  case 7: /* declaration: REAL DBL_COLON id_list  */
#line 102 "trad.y"
    {
        char* ind = indent();
        (yyval.str) = malloc(strlen(ind) + strlen((yyvsp[0].str)) + 40);
        sprintf((yyval.str), "%sfloat %s;\n", ind, (yyvsp[0].str));
        free(ind); free((yyvsp[0].str));
    }
#line 1334 "trad.tab.c"
    break;

  case 8: /* declaration: CHARACTER DBL_COLON id_list  */
#line 108 "trad.y"
                                 {
        char* ind = indent();
        (yyval.str) = malloc(strlen(ind) + strlen((yyvsp[0].str)) + 60);
        sprintf((yyval.str), "%sstring %s;\n", ind, (yyvsp[0].str));
        free(ind); free((yyvsp[0].str));
    }
#line 1345 "trad.tab.c"
    break;

  case 9: /* declaration: LOGICAL DBL_COLON id_list  */
#line 115 "trad.y"
                                {
        char* ind = indent();
        (yyval.str) = malloc(strlen(ind) + strlen((yyvsp[0].str)) + 40);
        sprintf((yyval.str), "%sbool %s = false;\n", ind, (yyvsp[0].str));
        free(ind); free((yyvsp[0].str));
    }
#line 1356 "trad.tab.c"
    break;

  case 10: /* id_list: ID  */
#line 125 "trad.y"
       { 
        (yyval.str) = malloc(strlen((yyvsp[0].str)) + 5);
        sprintf((yyval.str), "%s", (yyvsp[0].str));
        free((yyvsp[0].str));
    }
#line 1366 "trad.tab.c"
    break;

  case 11: /* id_list: ID '=' expression  */
#line 130 "trad.y"
                      {
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 4);
        sprintf((yyval.str), "%s = %s", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1376 "trad.tab.c"
    break;

  case 12: /* id_list: ID ',' id_list  */
#line 135 "trad.y"
                   {
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 4);
        sprintf((yyval.str), "%s, %s", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1386 "trad.tab.c"
    break;

  case 13: /* id_list: ID '=' expression ',' id_list  */
#line 140 "trad.y"
                                  {
        (yyval.str) = malloc(strlen((yyvsp[-4].str)) + strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 6);
        sprintf((yyval.str), "%s = %s, %s", (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-4].str)); free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1396 "trad.tab.c"
    break;

  case 14: /* statements: statement  */
#line 150 "trad.y"
              { (yyval.str) = (yyvsp[0].str); }
#line 1402 "trad.tab.c"
    break;

  case 15: /* statements: statement statements  */
#line 152 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 1);
        sprintf((yyval.str), "%s%s", (yyvsp[-1].str), (yyvsp[0].str));
        free((yyvsp[-1].str)); free((yyvsp[0].str));
    }
#line 1412 "trad.tab.c"
    break;

  case 16: /* statements: IMPLICIT  */
#line 158 "trad.y"
    {
        char* ind = indent();
        (yyval.str) = malloc(strlen(ind) + 30);
        sprintf((yyval.str), "%s// implicit none (todas las variables deben ser declaradas)\n", ind);
        free(ind);
    }
#line 1423 "trad.tab.c"
    break;

  case 17: /* statements: error '\n' statements  */
#line 165 "trad.y"
                            {
        fprintf(stderr, "Se recuperó de un error en la línea.\n");
        (yyval.str) = (yyvsp[0].str);
    }
#line 1432 "trad.tab.c"
    break;

  case 18: /* statements: error statements  */
#line 169 "trad.y"
                       {
        fprintf(stderr, "Se recuperó de un error.\n");
        (yyval.str) = (yyvsp[0].str);
    }
#line 1441 "trad.tab.c"
    break;

  case 19: /* statement: ID '=' expression  */
#line 178 "trad.y"
    {
        char* ind = indent();
        (yyval.str) = malloc(strlen(ind) + strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 10);
        sprintf((yyval.str), "%s%s = %s;\n", ind, (yyvsp[-2].str), (yyvsp[0].str));
        free(ind); free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1452 "trad.tab.c"
    break;

  case 20: /* statement: EXIT  */
#line 185 "trad.y"
    {
        char* ind = indent();
        (yyval.str) = malloc(20);
        sprintf((yyval.str), "%sbreak;\n", ind);
        free(ind);
    }
#line 1463 "trad.tab.c"
    break;

  case 21: /* statement: CYCLE  */
#line 192 "trad.y"
    {
        char* ind = indent();
        (yyval.str) = malloc(24);
        sprintf((yyval.str), "%scontinue;\n", ind);
        free(ind);
    }
#line 1474 "trad.tab.c"
    break;

  case 22: /* statement: PRINT '*' ',' expression  */
#line 199 "trad.y"
    {
        char* ind = indent();
        (yyval.str) = malloc(strlen(ind) + strlen((yyvsp[0].str)) + 20);
        sprintf((yyval.str), "%scout << %s;\n", ind, (yyvsp[0].str));
        free(ind); free((yyvsp[0].str));
    }
#line 1485 "trad.tab.c"
    break;

  case 23: /* statement: PRINT '*'  */
#line 206 "trad.y"
    {
        char* ind = indent();
        (yyval.str) = malloc(30);
        sprintf((yyval.str), "%scout << endl;\n", ind);
        free(ind);
    }
#line 1496 "trad.tab.c"
    break;

  case 24: /* statement: DO ID '=' expression ',' expression statements ENDDO  */
#line 213 "trad.y"
    {
        char* ind = indent();
        char* body = indent_lines((yyvsp[-1].str));
        int size = strlen(ind) + strlen((yyvsp[-6].str)) + strlen((yyvsp[-4].str)) + strlen((yyvsp[-2].str)) + strlen(body) + 200;
        (yyval.str) = malloc(size);
        sprintf((yyval.str), "%sfor (int %s = %s; %s <= %s; %s++) {\n%s%s}\n",
                ind, (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-6].str), (yyvsp[-2].str), (yyvsp[-6].str), body, ind);
        free((yyvsp[-6].str)); free((yyvsp[-4].str)); free((yyvsp[-2].str)); free((yyvsp[-1].str)); free(body); free(ind);
    }
#line 1510 "trad.tab.c"
    break;

  case 25: /* statement: DO statements ENDDO  */
#line 222 "trad.y"
                          {
        char* ind = indent();
        char* body = indent_lines((yyvsp[-1].str));
        (yyval.str) = malloc(strlen(ind) + strlen(body) + 50);
        sprintf((yyval.str), "%swhile (true) {\n%s%s}\n", ind, body, ind);
        free(ind); free(body); free((yyvsp[-1].str));
    }
#line 1522 "trad.tab.c"
    break;

  case 26: /* statement: IF '(' expression ')' THEN statements ENDIF  */
#line 231 "trad.y"
    {
        char* ind = indent();
        char* then_body = indent_lines((yyvsp[-1].str));
        int size = strlen(ind) + strlen((yyvsp[-4].str)) + strlen(then_body) + 50;
        (yyval.str) = malloc(size);
        sprintf((yyval.str), "%sif (%s) {\n%s%s}\n", ind, (yyvsp[-4].str), then_body, ind);
        free((yyvsp[-4].str)); free((yyvsp[-1].str)); free(then_body); free(ind);
    }
#line 1535 "trad.tab.c"
    break;

  case 27: /* statement: IF '(' expression ')' THEN statements ELSE statements ENDIF  */
#line 240 "trad.y"
    {
        char* ind = indent();
        char* then_body = indent_lines((yyvsp[-3].str));
        char* else_body = indent_lines((yyvsp[-1].str));
        int size = strlen(ind) + strlen((yyvsp[-6].str)) + strlen(then_body) + strlen(else_body) + 100;
        (yyval.str) = malloc(size);
        sprintf((yyval.str), "%sif (%s) {\n%s%s} else {\n%s%s}\n",
                ind, (yyvsp[-6].str), then_body, ind, else_body, ind);
        free((yyvsp[-6].str)); free((yyvsp[-3].str)); free((yyvsp[-1].str)); free(then_body); free(else_body); free(ind);
    }
#line 1550 "trad.tab.c"
    break;

  case 28: /* statement: SELECTCASE '(' expression ')' case_blocks ENDSELECT  */
#line 251 "trad.y"
    {
        char* ind = indent();
        char* body = indent_lines((yyvsp[-1].str));
        int size = strlen(ind) + strlen((yyvsp[-3].str)) + strlen(body) + 200;
        (yyval.str) = malloc(size); 
        sprintf((yyval.str), "%sswitch (%s) {\n%s%s}\n", ind, (yyvsp[-3].str), body, ind);
        free((yyvsp[-3].str)); free((yyvsp[-1].str)); free(body); free(ind);
    }
#line 1563 "trad.tab.c"
    break;

  case 29: /* statement: WRITE '(' '*' ',' '*' ')' expression  */
#line 260 "trad.y"
    {
        char* ind = indent();
        (yyval.str) = malloc(strlen(ind) + strlen((yyvsp[0].str)) + 40);
        sprintf((yyval.str), "%scout << %s << endl;\n", ind, (yyvsp[0].str));
        free(ind); free((yyvsp[0].str));
    }
#line 1574 "trad.tab.c"
    break;

  case 30: /* statement: READ '(' '*' ',' '*' ')' ID  */
#line 267 "trad.y"
    {
        char* ind = indent();
        (yyval.str) = malloc(strlen(ind) + strlen((yyvsp[0].str)) + 20);
        sprintf((yyval.str), "%scin >> %s;\n", ind, (yyvsp[0].str));
        free(ind); free((yyvsp[0].str));
    }
#line 1585 "trad.tab.c"
    break;

  case 31: /* statement: COMENTARIO  */
#line 273 "trad.y"
                 {
        char* ind = indent();
        (yyval.str) = malloc(strlen(ind) + strlen((yyvsp[0].str)) + 10);
        sprintf((yyval.str), "%s//%s\n", ind, (yyvsp[0].str));
        free(ind); free((yyvsp[0].str));
    }
#line 1596 "trad.tab.c"
    break;

  case 32: /* case_blocks: case_blocks case_block  */
#line 283 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 1);
        sprintf((yyval.str), "%s%s", (yyvsp[-1].str), (yyvsp[0].str));
        free((yyvsp[-1].str)); free((yyvsp[0].str));
    }
#line 1606 "trad.tab.c"
    break;

  case 33: /* case_blocks: case_block  */
#line 288 "trad.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1612 "trad.tab.c"
    break;

  case 34: /* case_block: CASE '(' NUMBER ')' statements  */
#line 293 "trad.y"
    {
        char* ind = indent();
        char* body = indent_lines((yyvsp[0].str));
        int size = strlen(ind) * strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) *strlen(body) + 40;
        (yyval.str) = malloc(size);
        sprintf((yyval.str), "%scase %s:\n%sbreak;\n$s",ind, (yyvsp[-2].str),body, ind);
        free((yyvsp[-2].str)); free((yyvsp[0].str));

    }
#line 1626 "trad.tab.c"
    break;

  case 35: /* case_block: CASE '(' NUMBER ':' NUMBER ')' statements  */
#line 303 "trad.y"
    {
        int size = strlen((yyvsp[-4].str)) + strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 100;
        (yyval.str) = malloc(size);
        sprintf((yyval.str), "    default:\n        if ($switch_var >= %s && $switch_var <= %s) {\n%s        break;\n        }\n",
                (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-4].str)); free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1638 "trad.tab.c"
    break;

  case 36: /* case_block: CASEDEFAULT statements  */
#line 311 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[0].str)) + 40);
        sprintf((yyval.str), "    default:\n%s        break;\n", (yyvsp[0].str));
        free((yyvsp[0].str));
    }
#line 1648 "trad.tab.c"
    break;

  case 37: /* expression: NUMBER  */
#line 319 "trad.y"
           { (yyval.str) = strdup((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 1654 "trad.tab.c"
    break;

  case 38: /* expression: STRING  */
#line 320 "trad.y"
             { (yyval.str) = strdup((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 1660 "trad.tab.c"
    break;

  case 39: /* expression: ID  */
#line 321 "trad.y"
         { (yyval.str) = strdup((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 1666 "trad.tab.c"
    break;

  case 40: /* expression: expression '+' expression  */
#line 323 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 5);
        sprintf((yyval.str), "(%s + %s)", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1676 "trad.tab.c"
    break;

  case 41: /* expression: expression '-' expression  */
#line 329 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 5);
        sprintf((yyval.str), "(%s - %s)", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1686 "trad.tab.c"
    break;

  case 42: /* expression: expression '*' expression  */
#line 335 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 5);
        sprintf((yyval.str), "(%s * %s)", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1696 "trad.tab.c"
    break;

  case 43: /* expression: expression '/' expression  */
#line 341 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 5);
        sprintf((yyval.str), "(%s / %s)", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1706 "trad.tab.c"
    break;

  case 44: /* expression: expression '>' expression  */
#line 347 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 5);
        sprintf((yyval.str), "%s > %s", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1716 "trad.tab.c"
    break;

  case 45: /* expression: expression '<' expression  */
#line 353 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 5);
        sprintf((yyval.str), "%s < %s", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1726 "trad.tab.c"
    break;

  case 46: /* expression: expression GE expression  */
#line 359 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 6);
        sprintf((yyval.str), "%s >= %s", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1736 "trad.tab.c"
    break;

  case 47: /* expression: expression LE expression  */
#line 365 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 6);
        sprintf((yyval.str), "%s <= %s", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1746 "trad.tab.c"
    break;

  case 48: /* expression: expression EQ expression  */
#line 371 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 6);
        sprintf((yyval.str), "%s == %s", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1756 "trad.tab.c"
    break;

  case 49: /* expression: expression NE expression  */
#line 377 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 6);
        sprintf((yyval.str), "%s != %s", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1766 "trad.tab.c"
    break;

  case 50: /* expression: expression AND expression  */
#line 383 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 6);
        sprintf((yyval.str), "%s && %s", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1776 "trad.tab.c"
    break;

  case 51: /* expression: expression OR expression  */
#line 389 "trad.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 6);
        sprintf((yyval.str), "%s || %s", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1786 "trad.tab.c"
    break;

  case 52: /* expression: TRUE  */
#line 394 "trad.y"
           { (yyval.str) = strdup("true"); }
#line 1792 "trad.tab.c"
    break;

  case 53: /* expression: FALSE  */
#line 395 "trad.y"
            { (yyval.str) = strdup("false"); }
#line 1798 "trad.tab.c"
    break;


#line 1802 "trad.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 399 "trad.y"


int yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis en la línea %d: %s\n", yylineno, s);
    return 0;
}


int main() {
    int result = yyparse();
    if (result != 0) {
        fprintf(stderr, "Se encontraron errores durante el análisis.\n");
    }
    return result;
}
