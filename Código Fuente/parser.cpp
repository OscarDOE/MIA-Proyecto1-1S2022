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
#line 1 "parser.y"

#include "scanner.h"
#include <QString>
#include <string>
#include "qdebug.h"
#include <iostream>

#include "mkdisk.h"
#include "rmdisk.h"
#include "fdisk.h"
#include "mount.h"
#include "umount.h"
#include "mkfs.h"
#include "exec.h"
#include "rep.h"
#include "login.h"
#include "mkgrp.h"
#include "mkusr.h"
#include "chgrp.h"
#include "loss.h"


using namespace std;
extern int yylineno;
extern int columna;
extern char *yytext;

int yyerror(const char* mens)
{
std::cout << mens <<" "<<yytext<< std::endl;
return 0;
}

#line 104 "parser.cpp"

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
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    Tbf = 258,
    Tff = 259,
    Twf = 260,
    Tk = 261,
    Tm = 262,
    Tb = 263,
    Tp = 264,
    Te = 265,
    Tl = 266,
    Tfull = 267,
    Tfast = 268,
    T3fs = 269,
    T2fs = 270,
    Trep = 271,
    Tmbr = 272,
    Tdisk = 273,
    Tinode = 274,
    Tjournaling = 275,
    Tblock = 276,
    Tbminode = 277,
    Tbmblock = 278,
    Ttree = 279,
    Tsb = 280,
    Tfile = 281,
    Tls = 282,
    Texec = 283,
    Tsize = 284,
    Tmkdisk = 285,
    Tf = 286,
    Tu = 287,
    Tpath = 288,
    Trmdisk = 289,
    Tfdisk = 290,
    Ttype = 291,
    Tname = 292,
    Tdelete = 293,
    Tadd = 294,
    Tmount = 295,
    Tumount = 296,
    Tid = 297,
    Tmkfs = 298,
    Tfs = 299,
    Truta = 300,
    Troot = 301,
    Tpause = 302,
    Tlogin = 303,
    Tlogout = 304,
    Tmkgrp = 305,
    Trmgrp = 306,
    Tmkusr = 307,
    Trmusr = 308,
    Tchgrp = 309,
    Tuser = 310,
    Tpwd = 311,
    Tgrp = 312,
    Ttouch = 313,
    Tcont = 314,
    Tstdin = 315,
    Tr = 316,
    Tloss = 317,
    num = 318,
    cadena = 319,
    cadena2 = 320,
    cadena3 = 321,
    cadena4 = 322,
    cadena5 = 323,
    identificador = 324,
    ide2 = 325,
    ide3 = 326,
    caracter = 327,
    guion = 328,
    igual = 329
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 40 "parser.y"

char TEXT[256];

class exec *objexec;

class mkdisk *objmkdisk;
class rmdisk *objrmdisk;
class fdisk *objfdisk;
class mount *objmount;
class umount *objumount;
class mkfs *objmkfs;
class rep *objrep;
class login *objlogin;
class mkgrp *objmkgrp;
class mkusr *objmkusr;
class chgrp *objchgrp;
class touch *objtouch;
class loss *objloss;

#line 251 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  51
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   293

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  318

#define YYUNDEFTOK  2
#define YYMAXUTOK   329


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   187,   187,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   211,   215,   216,   217,   218,   219,   220,   221,   222,
     226,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   243,   244,   246,   247,   248,   249,   253,
     254,   255,   256,   260,   264,   265,   266,   267,   268,   269,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     288,   289,   290,   291,   292,   293,   297,   301,   302,   303,
     304,   305,   306,   311,   312,   313,   314,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   331,   335,   336,
     337,   338,   339,   343,   344,   345,   346,   350,   351,   355,
     356,   357,   358,   362,   363,   364,   368,   369,   370,   375,
     376,   377,   381,   382,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   401,   402
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Tbf", "Tff", "Twf", "Tk", "Tm", "Tb",
  "Tp", "Te", "Tl", "Tfull", "Tfast", "T3fs", "T2fs", "Trep", "Tmbr",
  "Tdisk", "Tinode", "Tjournaling", "Tblock", "Tbminode", "Tbmblock",
  "Ttree", "Tsb", "Tfile", "Tls", "Texec", "Tsize", "Tmkdisk", "Tf", "Tu",
  "Tpath", "Trmdisk", "Tfdisk", "Ttype", "Tname", "Tdelete", "Tadd",
  "Tmount", "Tumount", "Tid", "Tmkfs", "Tfs", "Truta", "Troot", "Tpause",
  "Tlogin", "Tlogout", "Tmkgrp", "Trmgrp", "Tmkusr", "Trmusr", "Tchgrp",
  "Tuser", "Tpwd", "Tgrp", "Ttouch", "Tcont", "Tstdin", "Tr", "Tloss",
  "num", "cadena", "cadena2", "cadena3", "cadena4", "cadena5",
  "identificador", "ide2", "ide3", "caracter", "guion", "igual", "$accept",
  "INICIO", "INSTRUCCIONES", "_EXEC", "_MKDISK", "_RMDISK", "_FDISK",
  "_MOUNT", "_UMOUNT", "_MKFS", "_REP", "_LOGIN", "_MKGRP", "_MKUSR",
  "_CHGRP", "_TOUCH", "_LOSS", "PATH", "NAME", "INS", "PWD", "TYPES",
  "TIPO_AJUSTE", "TIPO_UNIDAD", "TIPO_DELETEoTYPES", "TIPO_REP",
  "TIPO_SISTEMA", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329
};
# endif

#define YYPACT_NINF (-148)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,   -58,   -50,   -48,     0,    14,    28,    36,    38,  -148,
      43,  -148,    52,    52,    53,    53,    64,    81,    85,    98,
    -148,    44,    86,   102,  -148,   100,    92,   105,  -148,   124,
      96,    39,    97,   133,  -148,    18,   103,    -8,   111,   158,
    -148,  -148,    51,   118,   118,    -2,   126,   -32,   127,   159,
    -148,  -148,   128,   129,   130,   131,   132,    46,   134,   136,
     137,   138,   139,   154,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   135,   149,   150,    62,   151,   152,   153,
     155,    58,   156,   157,   160,    29,   161,   162,   163,   164,
      65,   165,   166,    25,   167,   168,  -148,  -148,   178,   -23,
     169,   114,   125,   -12,   114,   170,   171,   172,   173,   174,
     175,   114,   181,   185,   186,   114,   176,   177,   179,   180,
     114,   189,   185,   186,   114,   187,   -34,    30,   192,   182,
     183,   184,   188,   190,   191,   193,   194,   114,   -34,   195,
     196,   -12,    30,   -12,    99,   197,   198,   199,   -12,   -24,
     -24,   200,   201,   202,   -34,   -24,   -24,   -34,   203,   204,
     205,   -24,   -34,   206,   207,   114,   219,   209,   210,   211,
     212,  -148,  -148,   -12,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,   114,   125,   -12,
     114,   224,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,   225,   185,   186,   114,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,   226,   185,   186,   114,   187,
     -34,    30,   227,  -148,  -148,   114,   -34,  -148,  -148,  -148,
    -148,  -148,  -148,    30,   -12,    99,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,   -12,   -24,   -24,  -148,  -148,  -148,  -148,
     -24,   -24,   -34,  -148,  -148,   -24,   -34,  -148,  -148,   228,
     229,   114,   230,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,    10,     0,     9,     0,     3,     0,     4,     0,
       5,     0,     6,     0,     7,     0,     8,     0,    11,     0,
      13,    14,     0,    15,    16,     0,    17,     0,    18,     0,
      19,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    89,     0,    98,    99,   100,   101,   102,    63,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    61,   107,   108,    65,    67,    69,     0,     0,     0,
       0,     0,    21,    23,   116,   117,   118,    27,   119,   120,
     121,    29,    25,     0,     0,     0,     0,    30,    32,    40,
      34,    36,   113,   114,   115,    38,   106,   103,   104,   105,
      46,   122,   123,    42,    48,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    52,     0,     0,    53,    57,    55,
     136,   135,    59,     0,     0,     0,    71,   111,   112,   109,
     110,    75,    73,     0,     0,     0,    76,    78,    80,    82,
       0,     0,     0,    84,    86,     0,     0,    88,    94,     0,
       0,     0,     0,    97,    62,    60,    64,    66,    68,    22,
      26,    28,    24,    31,    39,    33,    35,    37,    45,    41,
      47,    49,    51,    56,    54,    58,    70,    74,    72,    77,
      79,    81,    83,    85,    92,    91,    87,    93
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,   215,   217,  -148,  -148,  -148,  -104,  -136,  -124,
    -147,   -30,  -117,  -110,  -138,    61,     5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    24,    26,    28,    30,    32,    34,    36,
      22,    38,    40,    43,    46,    48,    50,   179,   230,   194,
     261,   225,   207,   211,   233,   191,   252
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     195,    94,   244,   262,   248,   219,   168,   202,   267,   268,
     169,   212,   226,   220,   273,    21,   217,   247,   266,   249,
     221,   269,   257,    23,   256,    25,   274,    95,    96,    97,
     227,   228,     1,   243,    82,   229,   170,   171,   172,   258,
     259,    98,   231,   232,     2,   260,     3,    83,    84,   283,
       4,     5,   192,    91,    78,    92,     6,     7,   193,     8,
      79,   277,    80,     9,    10,    11,    12,    13,    14,    15,
      16,   151,    74,    27,    17,   286,    75,    52,    18,   106,
     163,    53,   164,   107,   152,   153,    54,    29,   108,    55,
      56,   109,   110,   284,   145,   139,   287,   290,    51,   140,
     146,    31,   147,   299,   298,   291,    87,    88,    89,    33,
     302,    35,   292,   250,   251,   303,    37,   307,   308,   294,
     158,   159,   160,   309,   310,    39,    42,   295,   312,    59,
     304,    60,    61,    62,   296,    58,   311,    45,    64,   306,
     313,   301,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    65,    47,    66,    67,    68,    49,    57,
      69,    70,    71,    72,   129,    63,   130,   131,   132,    73,
      76,   133,   134,   135,   136,    77,    81,   316,   174,   175,
     176,   177,   178,   116,    85,   117,   118,   119,   204,   205,
     206,    90,   208,   209,   210,    86,   222,   223,   224,    93,
      99,   100,   101,   102,   103,   104,   105,   167,   111,   297,
     112,   113,   114,   115,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   137,   138,   141,   142,   143,    41,   144,
     148,   149,    44,   196,   150,   154,   155,   156,   157,   161,
     162,   165,   166,   173,   203,   197,   198,   199,   200,   201,
     213,   214,   218,   215,   216,   234,   235,   236,   237,   285,
     305,     0,   238,     0,   239,   240,     0,   241,   242,   245,
     246,   253,   254,   255,   263,   264,   265,   270,   271,   272,
     275,   276,   278,   279,   280,   281,   282,   288,   289,   293,
     300,   314,   315,   317
};

static const yytype_int16 yycheck[] =
{
     104,    33,   138,   150,   142,   122,    29,   111,   155,   156,
      33,   115,    46,   123,   161,    73,   120,   141,   154,   143,
     124,   157,    46,    73,   148,    73,   162,    59,    60,    61,
      64,    65,    16,   137,    42,    69,    59,    60,    61,    63,
      64,    73,    12,    13,    28,    69,    30,    55,    56,   173,
      34,    35,    64,    55,    36,    57,    40,    41,    70,    43,
      42,   165,    44,    47,    48,    49,    50,    51,    52,    53,
      54,    42,    33,    73,    58,   199,    37,    33,    62,    33,
      55,    37,    57,    37,    55,    56,    42,    73,    42,    45,
      46,    45,    46,   197,    36,    33,   200,   214,     0,    37,
      42,    73,    44,   241,   240,   215,    55,    56,    57,    73,
     246,    73,   216,    14,    15,   253,    73,   264,   265,   236,
      55,    56,    57,   270,   271,    73,    73,   237,   275,    29,
     254,    31,    32,    33,   238,    33,   272,    73,    33,   263,
     276,   245,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    29,    73,    31,    32,    33,    73,    73,
      36,    37,    38,    39,    29,    73,    31,    32,    33,    73,
      73,    36,    37,    38,    39,    42,    73,   281,    64,    65,
      66,    67,    68,    29,    73,    31,    32,    33,     3,     4,
       5,    73,     6,     7,     8,    37,     9,    10,    11,    73,
      73,    42,    74,    74,    74,    74,    74,    29,    74,   239,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    13,    74,
      74,    74,    15,    63,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    63,    74,    74,    74,    74,    74,
      74,    74,    63,    74,    74,    63,    74,    74,    74,   198,
     255,    -1,    74,    -1,    74,    74,    -1,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    63,    74,    74,    74,    74,    63,    63,    63,
      63,    63,    63,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    28,    30,    34,    35,    40,    41,    43,    47,
      48,    49,    50,    51,    52,    53,    54,    58,    62,    76,
      77,    73,    85,    73,    78,    73,    79,    73,    80,    73,
      81,    73,    82,    73,    83,    73,    84,    73,    86,    73,
      87,    87,    73,    88,    88,    73,    89,    73,    90,    73,
      91,     0,    33,    37,    42,    45,    46,    73,    33,    29,
      31,    32,    33,    73,    33,    29,    31,    32,    33,    36,
      37,    38,    39,    73,    33,    37,    73,    42,    36,    42,
      44,    73,    42,    55,    56,    73,    37,    55,    56,    57,
      73,    55,    57,    73,    33,    59,    60,    61,    73,    73,
      42,    74,    74,    74,    74,    74,    33,    37,    42,    45,
      46,    74,    74,    74,    74,    74,    29,    31,    32,    33,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    29,
      31,    32,    33,    36,    37,    38,    39,    74,    74,    33,
      37,    74,    74,    74,    74,    36,    42,    44,    74,    74,
      74,    42,    55,    56,    74,    74,    74,    74,    55,    56,
      57,    74,    74,    55,    57,    74,    74,    29,    29,    33,
      59,    60,    61,    74,    64,    65,    66,    67,    68,    92,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   100,    64,    70,    94,    92,    63,    74,    74,    74,
      74,    74,    92,    63,     3,     4,     5,    97,     6,     7,
       8,    98,    92,    74,    74,    74,    74,    92,    63,    97,
      98,    92,     9,    10,    11,    96,    46,    64,    65,    69,
      93,    12,    13,    99,    63,    74,    74,    74,    74,    74,
      74,    74,    74,    92,    93,    74,    74,    94,    99,    94,
      14,    15,   101,    74,    74,    74,    94,    46,    63,    64,
      69,    95,    95,    74,    74,    74,    93,    95,    95,    93,
      74,    74,    74,    95,    93,    74,    74,    92,    63,    74,
      74,    74,    74,    94,    92,   100,    94,    92,    63,    63,
      97,    98,    92,    63,    97,    98,    92,    96,    93,    99,
      63,    92,    93,    99,    94,   101,    94,    95,    95,    95,
      95,    93,    95,    93,    63,    63,    92,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    75,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    79,    79,    79,    79,    79,    79,    79,    79,
      80,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    82,    82,    83,    84,    84,    84,    84,    84,    84,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      86,    86,    86,    86,    86,    86,    87,    88,    88,    88,
      88,    88,    88,    89,    89,    89,    89,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    91,    92,    92,
      92,    92,    92,    93,    93,    93,    93,    94,    94,    95,
      95,    95,    95,    96,    96,    96,    97,    97,    97,    98,
      98,    98,    99,    99,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       1,     4,     5,     4,     5,     4,     5,     4,     5,     4,
       4,     5,     4,     5,     4,     5,     4,     5,     4,     5,
       4,     5,     4,     3,     2,     5,     4,     5,     4,     5,
       4,     5,     4,     4,     5,     4,     5,     4,     5,     4,
       5,     4,     5,     4,     5,     4,     5,     4,     5,     4,
       5,     4,     5,     4,     5,     4,     4,     5,     4,     5,
       4,     5,     4,     5,     4,     5,     4,     5,     4,     3,
       2,     5,     5,     5,     4,     3,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 187 "parser.y"
                       { }
#line 1746 "parser.cpp"
    break;

  case 3:
#line 190 "parser.y"
                                      {(yyvsp[0].objmkdisk)->CrearMkdisk((yyvsp[0].objmkdisk));}
#line 1752 "parser.cpp"
    break;

  case 4:
#line 191 "parser.y"
                             {(yyvsp[0].objrmdisk)->EliminarDisco((yyvsp[0].objrmdisk));}
#line 1758 "parser.cpp"
    break;

  case 5:
#line 192 "parser.y"
                           {(yyvsp[0].objfdisk)->AdmiDisco((yyvsp[0].objfdisk));}
#line 1764 "parser.cpp"
    break;

  case 6:
#line 193 "parser.y"
                          {(yyvsp[0].objmount)->MontarParticion((yyvsp[0].objmount));}
#line 1770 "parser.cpp"
    break;

  case 7:
#line 194 "parser.y"
                            {(yyvsp[0].objumount)->DesmontarParticion((yyvsp[0].objumount));}
#line 1776 "parser.cpp"
    break;

  case 8:
#line 195 "parser.y"
                        {(yyvsp[0].objmkfs)->FormatoMkfs((yyvsp[0].objmkfs));}
#line 1782 "parser.cpp"
    break;

  case 9:
#line 196 "parser.y"
                        {(yyvsp[0].objexec)->ejecutar((yyvsp[0].objexec));}
#line 1788 "parser.cpp"
    break;

  case 10:
#line 197 "parser.y"
                      {(yyvsp[0].objrep)->CrearRep((yyvsp[0].objrep));}
#line 1794 "parser.cpp"
    break;

  case 11:
#line 198 "parser.y"
                          {(yyvsp[0].objlogin)->Login((yyvsp[0].objlogin));}
#line 1800 "parser.cpp"
    break;

  case 12:
#line 199 "parser.y"
                     {login obj; obj.Logout();}
#line 1806 "parser.cpp"
    break;

  case 13:
#line 200 "parser.y"
                          {(yyvsp[0].objmkgrp)->crearGrupo((yyvsp[0].objmkgrp));}
#line 1812 "parser.cpp"
    break;

  case 14:
#line 201 "parser.y"
                          {(yyvsp[0].objmkgrp)->eliminarGrupo((yyvsp[0].objmkgrp));}
#line 1818 "parser.cpp"
    break;

  case 15:
#line 202 "parser.y"
                          {(yyvsp[0].objmkusr)->crearUsuario((yyvsp[0].objmkusr));}
#line 1824 "parser.cpp"
    break;

  case 16:
#line 203 "parser.y"
                          {(yyvsp[0].objmkusr)->eliminarUsuario((yyvsp[0].objmkusr));}
#line 1830 "parser.cpp"
    break;

  case 17:
#line 204 "parser.y"
                          {(yyvsp[0].objchgrp)->cambiarGrupo((yyvsp[0].objchgrp));}
#line 1836 "parser.cpp"
    break;

  case 18:
#line 205 "parser.y"
                          {}
#line 1842 "parser.cpp"
    break;

  case 19:
#line 206 "parser.y"
                        {(yyvsp[0].objloss)->lossPart((yyvsp[0].objloss));}
#line 1848 "parser.cpp"
    break;

  case 20:
#line 207 "parser.y"
                   {}
#line 1854 "parser.cpp"
    break;

  case 21:
#line 211 "parser.y"
                                  {exec *file= new exec(); file->contenido=(yyvsp[0].TEXT); (yyval.objexec)=file;}
#line 1860 "parser.cpp"
    break;

  case 22:
#line 215 "parser.y"
                                          {int tam=atoi((yyvsp[0].TEXT)); (yyvsp[-4].objmkdisk)->size=tam; (yyval.objmkdisk)=(yyvsp[-4].objmkdisk);}
#line 1866 "parser.cpp"
    break;

  case 23:
#line 216 "parser.y"
                                   {int tam=atoi((yyvsp[0].TEXT)); mkdisk *disco=new mkdisk(); disco->size=tam; (yyval.objmkdisk)=disco;}
#line 1872 "parser.cpp"
    break;

  case 24:
#line 217 "parser.y"
                                            {(yyvsp[-4].objmkdisk)->ruta=(yyvsp[0].TEXT); (yyval.objmkdisk)=(yyvsp[-4].objmkdisk);}
#line 1878 "parser.cpp"
    break;

  case 25:
#line 218 "parser.y"
                                    {mkdisk *disco=new mkdisk(); disco->ruta=(yyvsp[0].TEXT); (yyval.objmkdisk)=disco;}
#line 1884 "parser.cpp"
    break;

  case 26:
#line 219 "parser.y"
                                                {(yyvsp[-4].objmkdisk)->ajuste=(yyvsp[0].TEXT); (yyval.objmkdisk)=(yyvsp[-4].objmkdisk);}
#line 1890 "parser.cpp"
    break;

  case 27:
#line 220 "parser.y"
                                        {mkdisk *disco=new mkdisk(); disco->ajuste=(yyvsp[0].TEXT); (yyval.objmkdisk)=disco;}
#line 1896 "parser.cpp"
    break;

  case 28:
#line 221 "parser.y"
                                                {(yyvsp[-4].objmkdisk)->unidad=(yyvsp[0].TEXT); (yyval.objmkdisk)=(yyvsp[-4].objmkdisk);}
#line 1902 "parser.cpp"
    break;

  case 29:
#line 222 "parser.y"
                                        {mkdisk *disco=new mkdisk(); disco->unidad=(yyvsp[0].TEXT); (yyval.objmkdisk)=disco;}
#line 1908 "parser.cpp"
    break;

  case 30:
#line 226 "parser.y"
                                   {rmdisk *disco=new rmdisk(); disco->path=(yyvsp[0].TEXT); (yyval.objrmdisk)=disco;}
#line 1914 "parser.cpp"
    break;

  case 31:
#line 230 "parser.y"
                                         {int tam=atoi((yyvsp[0].TEXT)); (yyvsp[-4].objfdisk)->size=tam; (yyval.objfdisk)=(yyvsp[-4].objfdisk);}
#line 1920 "parser.cpp"
    break;

  case 32:
#line 231 "parser.y"
                                   {int tam=atoi((yyvsp[0].TEXT)); fdisk *disco= new fdisk(); disco->size=tam; (yyval.objfdisk)=disco;}
#line 1926 "parser.cpp"
    break;

  case 33:
#line 232 "parser.y"
                                               {(yyvsp[-4].objfdisk)->unidad=(yyvsp[0].TEXT); (yyval.objfdisk)=(yyvsp[-4].objfdisk);}
#line 1932 "parser.cpp"
    break;

  case 34:
#line 233 "parser.y"
                                        {fdisk *disco=new fdisk(); disco->unidad=(yyvsp[0].TEXT); (yyval.objfdisk)=disco;}
#line 1938 "parser.cpp"
    break;

  case 35:
#line 234 "parser.y"
                                           {(yyvsp[-4].objfdisk)->ruta=(yyvsp[0].TEXT); (yyval.objfdisk)=(yyvsp[-4].objfdisk);}
#line 1944 "parser.cpp"
    break;

  case 36:
#line 235 "parser.y"
                                    {fdisk *disco=new fdisk(); disco->ruta=(yyvsp[0].TEXT); (yyval.objfdisk)=disco;}
#line 1950 "parser.cpp"
    break;

  case 37:
#line 236 "parser.y"
                                           {(yyvsp[-4].objfdisk)->tipo=(yyvsp[0].TEXT); (yyval.objfdisk)=(yyvsp[-4].objfdisk);}
#line 1956 "parser.cpp"
    break;

  case 38:
#line 237 "parser.y"
                                     {fdisk * disco=new fdisk(); disco->tipo=(yyvsp[0].TEXT); (yyval.objfdisk)=disco;}
#line 1962 "parser.cpp"
    break;

  case 39:
#line 238 "parser.y"
                                               {(yyvsp[-4].objfdisk)->ajuste=(yyvsp[0].TEXT); (yyval.objfdisk)=(yyvsp[-4].objfdisk);}
#line 1968 "parser.cpp"
    break;

  case 40:
#line 239 "parser.y"
                                        {fdisk *disco=new fdisk(); disco->ajuste=(yyvsp[0].TEXT); (yyval.objfdisk)=disco;}
#line 1974 "parser.cpp"
    break;

  case 41:
#line 240 "parser.y"
                                                          {(yyvsp[-4].objfdisk)->eliminar=(yyvsp[0].TEXT); (yyval.objfdisk)=(yyvsp[-4].objfdisk);}
#line 1980 "parser.cpp"
    break;

  case 42:
#line 241 "parser.y"
                                                   {fdisk * disco=new fdisk(); disco->eliminar=(yyvsp[0].TEXT); (yyval.objfdisk)=disco;}
#line 1986 "parser.cpp"
    break;

  case 43:
#line 243 "parser.y"
                                  {(yyvsp[-2].objfdisk)->eliminar="FAST"; (yyval.objfdisk)=(yyvsp[-2].objfdisk);}
#line 1992 "parser.cpp"
    break;

  case 44:
#line 244 "parser.y"
                           {fdisk * disco=new fdisk(); disco->eliminar="FAST"; (yyval.objfdisk)=disco;}
#line 1998 "parser.cpp"
    break;

  case 45:
#line 246 "parser.y"
                                           {(yyvsp[-4].objfdisk)->nombre=(yyvsp[0].TEXT); (yyval.objfdisk)=(yyvsp[-4].objfdisk);}
#line 2004 "parser.cpp"
    break;

  case 46:
#line 247 "parser.y"
                                    {fdisk * disco=new fdisk(); disco->nombre=(yyvsp[0].TEXT); (yyval.objfdisk)=disco;}
#line 2010 "parser.cpp"
    break;

  case 47:
#line 248 "parser.y"
                                         {int tam=atoi((yyvsp[0].TEXT));(yyvsp[-4].objfdisk)->agregar=tam; (yyval.objfdisk)=(yyvsp[-4].objfdisk);}
#line 2016 "parser.cpp"
    break;

  case 48:
#line 249 "parser.y"
                                  {int tam=atoi((yyvsp[0].TEXT)); fdisk * disco=new fdisk(); disco->agregar=tam; (yyval.objfdisk)=disco;}
#line 2022 "parser.cpp"
    break;

  case 49:
#line 253 "parser.y"
                                         {(yyvsp[-4].objmount)->ruta=(yyvsp[0].TEXT); (yyval.objmount)=(yyvsp[-4].objmount);}
#line 2028 "parser.cpp"
    break;

  case 50:
#line 254 "parser.y"
                                    {mount * montar=new mount(); montar->ruta=(yyvsp[0].TEXT); (yyval.objmount)=montar;}
#line 2034 "parser.cpp"
    break;

  case 51:
#line 255 "parser.y"
                                           {(yyvsp[-4].objmount)->nombre=(yyvsp[0].TEXT); (yyval.objmount)=(yyvsp[-4].objmount);}
#line 2040 "parser.cpp"
    break;

  case 52:
#line 256 "parser.y"
                                    {mount * montar=new mount(); montar->nombre=(yyvsp[0].TEXT); (yyval.objmount)=montar;}
#line 2046 "parser.cpp"
    break;

  case 53:
#line 260 "parser.y"
                                {umount *unmontar = new umount(); unmontar->id=(yyvsp[0].TEXT); (yyval.objumount)=unmontar;}
#line 2052 "parser.cpp"
    break;

  case 54:
#line 264 "parser.y"
                                     {(yyvsp[-4].objmkfs)->id= (yyvsp[0].TEXT); (yyval.objmkfs)=(yyvsp[-4].objmkfs);}
#line 2058 "parser.cpp"
    break;

  case 55:
#line 265 "parser.y"
                                 {mkfs *Disco = new mkfs(); Disco->id = (yyvsp[0].TEXT); (yyval.objmkfs)=Disco;}
#line 2064 "parser.cpp"
    break;

  case 56:
#line 266 "parser.y"
                                                      {(yyvsp[-4].objmkfs)->tipo= (yyvsp[0].TEXT); (yyval.objmkfs)=(yyvsp[-4].objmkfs);}
#line 2070 "parser.cpp"
    break;

  case 57:
#line 267 "parser.y"
                                                 {mkfs *Disco = new mkfs(); Disco->tipo = (yyvsp[0].TEXT); (yyval.objmkfs)=Disco;}
#line 2076 "parser.cpp"
    break;

  case 58:
#line 268 "parser.y"
                                               {(yyvsp[-4].objmkfs)->fs= (yyvsp[0].TEXT); (yyval.objmkfs)=(yyvsp[-4].objmkfs);}
#line 2082 "parser.cpp"
    break;

  case 59:
#line 269 "parser.y"
                                          {mkfs *Disco = new mkfs(); Disco->fs = (yyvsp[0].TEXT); (yyval.objmkfs)=Disco;}
#line 2088 "parser.cpp"
    break;

  case 60:
#line 274 "parser.y"
                                            {(yyvsp[-4].objrep)->nombre= (yyvsp[0].TEXT); (yyval.objrep)=(yyvsp[-4].objrep);}
#line 2094 "parser.cpp"
    break;

  case 61:
#line 275 "parser.y"
                                        {rep *reporte = new rep(); reporte->nombre = (yyvsp[0].TEXT); (yyval.objrep)=reporte;}
#line 2100 "parser.cpp"
    break;

  case 62:
#line 276 "parser.y"
                                         {(yyvsp[-4].objrep)->ruta= (yyvsp[0].TEXT); (yyval.objrep)=(yyvsp[-4].objrep);}
#line 2106 "parser.cpp"
    break;

  case 63:
#line 277 "parser.y"
                                    {rep *reporte = new rep(); reporte->ruta = (yyvsp[0].TEXT); (yyval.objrep)=reporte;}
#line 2112 "parser.cpp"
    break;

  case 64:
#line 278 "parser.y"
                                      {(yyvsp[-4].objrep)->id= (yyvsp[0].TEXT); (yyval.objrep)=(yyvsp[-4].objrep);}
#line 2118 "parser.cpp"
    break;

  case 65:
#line 279 "parser.y"
                                 {rep *reporte = new rep(); reporte->id = (yyvsp[0].TEXT); (yyval.objrep)=reporte;}
#line 2124 "parser.cpp"
    break;

  case 66:
#line 280 "parser.y"
                                         {(yyvsp[-4].objrep)->ruta= (yyvsp[0].TEXT); (yyval.objrep)=(yyvsp[-4].objrep);}
#line 2130 "parser.cpp"
    break;

  case 67:
#line 281 "parser.y"
                                    {rep *reporte = new rep(); reporte->ruta = (yyvsp[0].TEXT); (yyval.objrep)=reporte;}
#line 2136 "parser.cpp"
    break;

  case 68:
#line 282 "parser.y"
                                        {int tam=atoi((yyvsp[0].TEXT));(yyvsp[-4].objrep)->root=tam; (yyval.objrep)=(yyvsp[-4].objrep);}
#line 2142 "parser.cpp"
    break;

  case 69:
#line 283 "parser.y"
                                   {int tam=atoi((yyvsp[0].TEXT));rep *reporte = new rep(); reporte->root = tam; (yyval.objrep)=reporte;}
#line 2148 "parser.cpp"
    break;

  case 70:
#line 288 "parser.y"
                                       {(yyvsp[-4].objlogin)->id= (yyvsp[0].TEXT); (yyval.objlogin)=(yyvsp[-4].objlogin);}
#line 2154 "parser.cpp"
    break;

  case 71:
#line 289 "parser.y"
                                 {login *usuario = new login(); usuario->id = (yyvsp[0].TEXT); (yyval.objlogin)=usuario;}
#line 2160 "parser.cpp"
    break;

  case 72:
#line 290 "parser.y"
                                         {(yyvsp[-4].objlogin)->pwd= (yyvsp[0].TEXT); (yyval.objlogin)=(yyvsp[-4].objlogin);}
#line 2166 "parser.cpp"
    break;

  case 73:
#line 291 "parser.y"
                                  {login *usuario = new login(); usuario->pwd = (yyvsp[0].TEXT); (yyval.objlogin)=usuario;}
#line 2172 "parser.cpp"
    break;

  case 74:
#line 292 "parser.y"
                                          {(yyvsp[-4].objlogin)->user= (yyvsp[0].TEXT); (yyval.objlogin)=(yyvsp[-4].objlogin);}
#line 2178 "parser.cpp"
    break;

  case 75:
#line 293 "parser.y"
                                   {login *usuario = new login(); usuario->user = (yyvsp[0].TEXT); (yyval.objlogin)=usuario;}
#line 2184 "parser.cpp"
    break;

  case 76:
#line 297 "parser.y"
                                   {mkgrp *grupo = new mkgrp; grupo->nombre =(yyvsp[0].TEXT); (yyval.objmkgrp)=grupo;}
#line 2190 "parser.cpp"
    break;

  case 77:
#line 301 "parser.y"
                                         {(yyvsp[-4].objmkusr)->usr=(yyvsp[0].TEXT); (yyval.objmkusr)=(yyvsp[-4].objmkusr);}
#line 2196 "parser.cpp"
    break;

  case 78:
#line 302 "parser.y"
                                   {mkusr *usuario = new mkusr; usuario->usr =(yyvsp[0].TEXT); (yyval.objmkusr)=usuario;}
#line 2202 "parser.cpp"
    break;

  case 79:
#line 303 "parser.y"
                                         {(yyvsp[-4].objmkusr)->pwd=(yyvsp[0].TEXT); (yyval.objmkusr)=(yyvsp[-4].objmkusr);}
#line 2208 "parser.cpp"
    break;

  case 80:
#line 304 "parser.y"
                                  {mkusr *usuario = new mkusr; usuario->pwd =(yyvsp[0].TEXT); (yyval.objmkusr)=usuario;}
#line 2214 "parser.cpp"
    break;

  case 81:
#line 305 "parser.y"
                                          {(yyvsp[-4].objmkusr)->grp=(yyvsp[0].TEXT); (yyval.objmkusr)=(yyvsp[-4].objmkusr);}
#line 2220 "parser.cpp"
    break;

  case 82:
#line 306 "parser.y"
                                   {mkusr *usuario = new mkusr; usuario->grp =(yyvsp[0].TEXT); (yyval.objmkusr)=usuario;}
#line 2226 "parser.cpp"
    break;

  case 83:
#line 311 "parser.y"
                                         {(yyvsp[-4].objchgrp)->usr=(yyvsp[0].TEXT); (yyval.objchgrp)=(yyvsp[-4].objchgrp);}
#line 2232 "parser.cpp"
    break;

  case 84:
#line 312 "parser.y"
                                   {chgrp *grupo = new chgrp; grupo->usr =(yyvsp[0].TEXT); (yyval.objchgrp)=grupo;}
#line 2238 "parser.cpp"
    break;

  case 85:
#line 313 "parser.y"
                                          {(yyvsp[-4].objchgrp)->grp=(yyvsp[0].TEXT); (yyval.objchgrp)=(yyvsp[-4].objchgrp);}
#line 2244 "parser.cpp"
    break;

  case 86:
#line 314 "parser.y"
                                   {chgrp *grupo = new chgrp; grupo->grp =(yyvsp[0].TEXT); (yyval.objchgrp)=grupo;}
#line 2250 "parser.cpp"
    break;

  case 87:
#line 318 "parser.y"
                                         {}
#line 2256 "parser.cpp"
    break;

  case 88:
#line 319 "parser.y"
                                    {}
#line 2262 "parser.cpp"
    break;

  case 89:
#line 320 "parser.y"
                             {}
#line 2268 "parser.cpp"
    break;

  case 90:
#line 321 "parser.y"
                      {}
#line 2274 "parser.cpp"
    break;

  case 91:
#line 322 "parser.y"
                                          {}
#line 2280 "parser.cpp"
    break;

  case 92:
#line 323 "parser.y"
                                         {}
#line 2286 "parser.cpp"
    break;

  case 93:
#line 324 "parser.y"
                                         {}
#line 2292 "parser.cpp"
    break;

  case 94:
#line 325 "parser.y"
                                  {}
#line 2298 "parser.cpp"
    break;

  case 95:
#line 326 "parser.y"
                                {}
#line 2304 "parser.cpp"
    break;

  case 96:
#line 327 "parser.y"
                         {}
#line 2310 "parser.cpp"
    break;

  case 97:
#line 331 "parser.y"
                               {loss *part = new loss; part->id=(yyvsp[0].TEXT); (yyval.objloss)=part;}
#line 2316 "parser.cpp"
    break;

  case 98:
#line 335 "parser.y"
                  {}
#line 2322 "parser.cpp"
    break;

  case 99:
#line 336 "parser.y"
                    {}
#line 2328 "parser.cpp"
    break;

  case 100:
#line 337 "parser.y"
                    {}
#line 2334 "parser.cpp"
    break;

  case 101:
#line 338 "parser.y"
                    {}
#line 2340 "parser.cpp"
    break;

  case 102:
#line 339 "parser.y"
                    {}
#line 2346 "parser.cpp"
    break;

  case 103:
#line 343 "parser.y"
                  {}
#line 2352 "parser.cpp"
    break;

  case 104:
#line 344 "parser.y"
                    {}
#line 2358 "parser.cpp"
    break;

  case 105:
#line 345 "parser.y"
                          {}
#line 2364 "parser.cpp"
    break;

  case 106:
#line 346 "parser.y"
                  {}
#line 2370 "parser.cpp"
    break;

  case 107:
#line 350 "parser.y"
                  {}
#line 2376 "parser.cpp"
    break;

  case 108:
#line 351 "parser.y"
                 {}
#line 2382 "parser.cpp"
    break;

  case 109:
#line 355 "parser.y"
                  {}
#line 2388 "parser.cpp"
    break;

  case 110:
#line 356 "parser.y"
                          {}
#line 2394 "parser.cpp"
    break;

  case 111:
#line 357 "parser.y"
                  {}
#line 2400 "parser.cpp"
    break;

  case 112:
#line 358 "parser.y"
                 {}
#line 2406 "parser.cpp"
    break;

  case 113:
#line 362 "parser.y"
              {}
#line 2412 "parser.cpp"
    break;

  case 114:
#line 363 "parser.y"
               {}
#line 2418 "parser.cpp"
    break;

  case 115:
#line 364 "parser.y"
               {}
#line 2424 "parser.cpp"
    break;

  case 116:
#line 368 "parser.y"
               {}
#line 2430 "parser.cpp"
    break;

  case 117:
#line 369 "parser.y"
                {}
#line 2436 "parser.cpp"
    break;

  case 118:
#line 370 "parser.y"
                {}
#line 2442 "parser.cpp"
    break;

  case 119:
#line 375 "parser.y"
              {}
#line 2448 "parser.cpp"
    break;

  case 120:
#line 376 "parser.y"
               {}
#line 2454 "parser.cpp"
    break;

  case 121:
#line 377 "parser.y"
               {}
#line 2460 "parser.cpp"
    break;

  case 122:
#line 381 "parser.y"
                 {}
#line 2466 "parser.cpp"
    break;

  case 123:
#line 382 "parser.y"
                  {}
#line 2472 "parser.cpp"
    break;

  case 124:
#line 386 "parser.y"
                {}
#line 2478 "parser.cpp"
    break;

  case 125:
#line 387 "parser.y"
                  {}
#line 2484 "parser.cpp"
    break;

  case 126:
#line 388 "parser.y"
                   {}
#line 2490 "parser.cpp"
    break;

  case 127:
#line 389 "parser.y"
                        {}
#line 2496 "parser.cpp"
    break;

  case 128:
#line 390 "parser.y"
                   {}
#line 2502 "parser.cpp"
    break;

  case 129:
#line 391 "parser.y"
                     {}
#line 2508 "parser.cpp"
    break;

  case 130:
#line 392 "parser.y"
                     {}
#line 2514 "parser.cpp"
    break;

  case 131:
#line 393 "parser.y"
                  {}
#line 2520 "parser.cpp"
    break;

  case 132:
#line 394 "parser.y"
                {}
#line 2526 "parser.cpp"
    break;

  case 133:
#line 395 "parser.y"
                  {}
#line 2532 "parser.cpp"
    break;

  case 134:
#line 396 "parser.y"
                {}
#line 2538 "parser.cpp"
    break;

  case 135:
#line 401 "parser.y"
                {}
#line 2544 "parser.cpp"
    break;

  case 136:
#line 402 "parser.y"
                 {}
#line 2550 "parser.cpp"
    break;


#line 2554 "parser.cpp"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
