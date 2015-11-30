/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         JsonRideFileparse
#define yylex           JsonRideFilelex
#define yyerror         JsonRideFileerror
#define yydebug         JsonRideFiledebug
#define yynerrs         JsonRideFilenerrs


/* Copy the first part of user declarations.  */
#line 1 "JsonRideFile.y" /* yacc.c:339  */

/*
 * Copyright (c) 2010 Mark Liversedge (liversedge@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

// This grammar should work with yacc and bison, but has
// only been tested with bison. In addition, since qmake
// uses the -p flag to rename all the yy functions to
// enable multiple grammars in a single executable you
// should make sure you use the very latest bison since it
// has been known to be problematic in the past. It is
// know to work well with bison v2.4.1.
//
// To make the grammar readable I have placed the code
// for each nterm at column 40, this source file is best
// edited / viewed in an editor which is at least 120
// columns wide (e.g. vi in xterm of 120x40)
//
//
// The grammar is specific to the RideFile format serialised
// in writeRideFile below, this is NOT a generic json parser.

#include "JsonRideFile.h"

// now we have a reentrant parser we save context data
// in a structure rather than in global variables -- so
// you can run the parser concurrently.
struct JsonContext {

    // the scanner
    void *scanner;

    // Set during parser processing, using same
    // naming conventions as yacc/lex -p
    RideFile *JsonRide;

    // term state data is held in these variables
    RideFilePoint JsonPoint;
    RideFileInterval JsonInterval;
    RideFileCalibration JsonCalibration;
    QString JsonString,
                JsonTagKey, JsonTagValue,
                JsonOverName, JsonOverKey, JsonOverValue;
    double JsonNumber;
    QStringList JsonRideFileerrors;
    QMap <QString, QString> JsonOverrides;

};

#define YYSTYPE QString

// Lex scanner
extern int JsonRideFilelex(YYSTYPE*,void*); // the lexer aka yylex()
extern int JsonRideFilelex_init(void**);
extern void JsonRideFile_setString(QString, void *);
extern int JsonRideFilelex_destroy(void*); // the cleaner for lexer

// yacc parser
void JsonRideFileerror(void*jc, const char *error) // used by parser aka yyerror()
{ static_cast<JsonContext*>(jc)->JsonRideFileerrors << error; }

//
// Utility functions
//

// Escape special characters (JSON compliance)
static QString protect(const QString string)
{
    QString s = string;
    s.replace("\\", "\\\\"); // backslash
    s.replace("\"", "\\\""); // quote
    s.replace("\t", "\\t");  // tab
    s.replace("\n", "\\n");  // newline
    s.replace("\r", "\\r");  // carriage-return
    s.replace("\b", "\\b");  // backspace
    s.replace("\f", "\\f");  // formfeed
    s.replace("/", "\\/");   // solidus

    // add a trailing space to avoid conflicting with GC special tokens
    s += " "; 

    return s;
}

// extract scanner from the context
#define scanner jc->scanner


#line 175 "JsonRideFile.tab.c" /* yacc.c:339  */

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
   by #include "JsonRideFile.tab.h".  */
#ifndef YY_JSONRIDEFILE_JSONRIDEFILE_TAB_H_INCLUDED
# define YY_JSONRIDEFILE_JSONRIDEFILE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int JsonRideFiledebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    JS_STRING = 258,
    JS_INTEGER = 259,
    JS_FLOAT = 260,
    RIDE = 261,
    STARTTIME = 262,
    RECINTSECS = 263,
    DEVICETYPE = 264,
    IDENTIFIER = 265,
    OVERRIDES = 266,
    TAGS = 267,
    INTERVALS = 268,
    NAME = 269,
    START = 270,
    STOP = 271,
    CALIBRATIONS = 272,
    VALUE = 273,
    REFERENCES = 274,
    SAMPLES = 275,
    SECS = 276,
    KM = 277,
    WATTS = 278,
    NM = 279,
    CAD = 280,
    KPH = 281,
    HR = 282,
    ALTITUDE = 283,
    LAT = 284,
    LON = 285,
    HEADWIND = 286,
    SLOPE = 287,
    TEMP = 288,
    LRBALANCE = 289,
    LTE = 290,
    RTE = 291,
    LPS = 292,
    RPS = 293,
    THB = 294,
    SMO2 = 295,
    RVERT = 296,
    RCAD = 297,
    RCON = 298,
    LPCO = 299,
    RPCO = 300,
    LPPB = 301,
    RPPB = 302,
    LPPE = 303,
    RPPE = 304,
    LPPPB = 305,
    RPPPB = 306,
    LPPPE = 307,
    RPPPE = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int JsonRideFileparse (struct JsonContext *jc);

#endif /* !YY_JSONRIDEFILE_JSONRIDEFILE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 279 "JsonRideFile.tab.c" /* yacc.c:358  */

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
#define YYLAST   245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  256

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
       2,     2,     2,     2,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   122,   122,   123,   127,   128,   131,   132,   133,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   151,
     156,   157,   158,   163,   164,   164,   166,   171,   174,   175,
     175,   176,   177,   178,   183,   184,   184,   185,   188,   191,
     196,   197,   197,   198,   199,   200,   198,   212,   213,   213,
     214,   215,   216,   214,   228,   232,   232,   233,   240,   241,
     241,   242,   262,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   304,
     305,   308
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "JS_STRING", "JS_INTEGER", "JS_FLOAT",
  "RIDE", "STARTTIME", "RECINTSECS", "DEVICETYPE", "IDENTIFIER",
  "OVERRIDES", "TAGS", "INTERVALS", "NAME", "START", "STOP",
  "CALIBRATIONS", "VALUE", "REFERENCES", "SAMPLES", "SECS", "KM", "WATTS",
  "NM", "CAD", "KPH", "HR", "ALTITUDE", "LAT", "LON", "HEADWIND", "SLOPE",
  "TEMP", "LRBALANCE", "LTE", "RTE", "LPS", "RPS", "THB", "SMO2", "RVERT",
  "RCAD", "RCON", "LPCO", "RPCO", "LPPB", "RPPB", "LPPE", "RPPE", "LPPPB",
  "RPPPB", "LPPPE", "RPPPE", "'{'", "'}'", "','", "':'", "'['", "']'",
  "$accept", "document", "ride_list", "ride", "rideelement_list",
  "rideelement", "starttime", "recordint", "devicetype", "identifier",
  "overrides", "overrides_list", "override", "override_name",
  "override_values", "override_value_list", "override_value",
  "override_key", "tags", "tags_list", "tag", "tag_key", "tag_value",
  "intervals", "interval_list", "interval", "$@1", "$@2", "$@3",
  "calibrations", "calibration_list", "calibration", "$@4", "$@5", "$@6",
  "references", "reference_list", "reference", "samples", "sample_list",
  "sample", "series_list", "series", "number", "string", YY_NULLPTR
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
     305,   306,   307,   308,   123,   125,    44,    58,    91,    93
};
# endif

#define YYPACT_NINF -185

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-185)))

#define YYTABLE_NINF -33

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,   -45,     8,    21,   -33,  -185,    -6,   -25,  -185,     8,
      -2,  -185,  -185,    29,    31,    32,    35,    36,    37,    38,
      39,    40,    41,   -19,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,    49,    34,    49,    49,    33,
      45,    42,    43,    44,    47,  -185,    -2,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,    89,    49,    90,    91,    92,    96,
    -185,    49,   -43,  -185,   -15,  -185,    46,  -185,   127,   -37,
    -185,   137,   -32,  -185,    87,   -31,  -185,    87,   -27,  -185,
      95,  -185,    89,  -185,  -185,    49,    49,    97,    90,  -185,
      98,    91,  -185,    99,   100,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   128,
     129,   130,   131,   132,   133,   134,   138,   135,    92,  -185,
     -13,  -185,    96,  -185,   140,  -185,  -185,  -185,  -185,    49,
    -185,    49,  -185,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,  -185,    30,  -185,  -185,
      87,  -185,    49,   142,   143,   144,  -185,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,  -185,   -11,  -185,   141,   145,  -185,  -185,  -185,  -185,
      49,    49,   169,   186,  -185,  -185,   146,   147,    34,    34,
     149,   150,  -185,  -185,   191,   190,   152,   153,    34,    34,
    -185,  -185,   156,   157,  -185,  -185
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     4,     0,     0,     1,     0,
       0,     2,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     0,   101,    19,    99,
     100,    20,    21,    22,     0,     0,     0,     0,     0,     0,
       7,     0,     0,    24,     0,    35,     0,    38,     0,     0,
      41,     0,     0,    48,     0,     0,    55,     0,     0,    59,
       0,    27,     0,    23,    34,     0,     0,     0,     0,    40,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,    62,     0,    58,     0,    25,    36,    37,    39,     0,
      42,     0,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,    56,    61,
       0,    60,     0,     0,     0,     0,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    93,    92,    94,    95,    96,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    97,
      98,    63,     0,    29,     0,    33,    26,    43,    50,    28,
       0,     0,     0,     0,    30,    31,     0,     0,     0,     0,
       0,     0,    44,    51,     0,     0,     0,     0,     0,     0,
      45,    52,     0,     0,    46,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -185,  -185,   151,   204,  -185,   168,  -185,  -185,  -185,  -185,
    -185,  -185,   136,  -185,  -185,  -185,  -184,  -185,  -185,  -185,
     139,  -185,  -185,  -185,  -185,   148,  -185,  -185,  -185,  -185,
    -185,   154,  -185,  -185,  -185,  -185,  -185,    88,  -185,  -185,
      83,  -185,   -73,   -90,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    23,    24,    25,    26,    27,    28,
      29,    62,    63,    80,   183,   222,   223,   224,    30,    64,
      65,    66,   137,    31,    69,    70,   232,   244,   252,    32,
      72,    73,   233,   245,   253,    33,    75,    76,    34,    78,
      79,   130,   126,    51,   127
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,     1,    52,    53,   131,    13,    14,    15,    16,    17,
      18,    19,     6,    82,     1,    20,    83,    21,    22,    88,
      67,     8,    89,     9,    91,   128,    81,    92,   129,   132,
      11,     9,   133,    47,    49,    50,    45,    46,    49,    50,
      84,    85,   179,   180,   229,   230,   234,   235,    10,     2,
      67,   138,    47,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    35,   219,    36,    37,
      47,    54,    38,    39,    40,    41,    42,    43,    44,    55,
      56,    57,    58,    86,   184,    59,   185,   221,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    87,   220,    61,    68,    71,    74,   225,   240,   241,
      77,    90,   134,     7,   139,   141,   143,   144,   250,   251,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   236,   169,   170,   171,   172,   173,
     174,   175,   177,   176,   182,   225,   225,   226,   231,   227,
     228,   237,   -32,   238,   239,   242,   243,   246,   247,   248,
     249,   254,   255,    12,    60,   181,   178,     0,   135,     0,
       0,     0,     0,     0,   136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   140,     0,     0,     0,
       0,     0,     0,     0,     0,   142
};

static const yytype_int16 yycheck[] =
{
      35,     6,    37,    38,    77,     7,     8,     9,    10,    11,
      12,    13,    57,    56,     6,    17,    59,    19,    20,    56,
      55,     0,    59,    56,    56,    56,    61,    59,    59,    56,
      55,    56,    59,     3,     4,     5,    55,    56,     4,     5,
      55,    56,    55,    56,    55,    56,   230,   231,    54,    54,
      85,    86,     3,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    57,   177,    57,    57,
       3,    58,    57,    57,    57,    57,    57,    57,    57,    54,
      58,    58,    58,    57,   139,    58,   141,   180,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    14,   177,    54,    54,    54,    54,   182,   238,   239,
      54,    14,    57,     2,    57,    57,    57,    57,   248,   249,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    15,    57,    57,    57,    57,    57,
      57,    57,    57,    55,    54,   230,   231,    55,    57,    56,
      56,    15,    57,    57,    57,    56,    56,    16,    18,    57,
      57,    55,    55,     9,    46,   132,   128,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    54,    61,    62,    63,    57,    62,     0,    56,
      54,    55,    63,     7,     8,     9,    10,    11,    12,    13,
      17,    19,    20,    64,    65,    66,    67,    68,    69,    70,
      78,    83,    89,    95,    98,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    55,    56,     3,   104,     4,
       5,   103,   104,   104,    58,    54,    58,    58,    58,    58,
      65,    54,    71,    72,    79,    80,    81,   104,    54,    84,
      85,    54,    90,    91,    54,    96,    97,    54,    99,   100,
      73,   104,    56,    59,    55,    56,    57,    14,    56,    59,
      14,    56,    59,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,   102,   104,    56,    59,
     101,   102,    56,    59,    57,    72,    80,    82,   104,    57,
      85,    57,    91,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    55,    57,    97,    55,
      56,   100,    54,    74,   104,   104,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     104,   102,    75,    76,    77,   104,    55,    56,    56,    55,
      56,    57,    86,    92,    76,    76,    15,    15,    57,    57,
     103,   103,    56,    56,    87,    93,    16,    18,    57,    57,
     103,   103,    88,    94,    55,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      67,    68,    69,    70,    71,    71,    72,    73,    74,    75,
      75,    76,    77,    76,    78,    79,    79,    80,    81,    82,
      83,    84,    84,    86,    87,    88,    85,    89,    90,    90,
      92,    93,    94,    91,    95,    96,    96,    97,    98,    99,
      99,   100,   101,   101,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   103,
     103,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     1,     3,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     5,     1,     3,     5,     1,     3,     1,
       3,     3,     1,     1,     5,     1,     3,     3,     1,     1,
       5,     1,     3,     0,     0,     0,    16,     5,     1,     3,
       0,     0,     0,    16,     5,     1,     3,     3,     5,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1
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
      yyerror (jc, YY_("syntax error: cannot back up")); \
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
                  Type, Value, jc); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct JsonContext *jc)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (jc);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct JsonContext *jc)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, jc);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, struct JsonContext *jc)
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
                                              , jc);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, jc); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, struct JsonContext *jc)
{
  YYUSE (yyvaluep);
  YYUSE (jc);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (struct JsonContext *jc)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

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
      yychar = yylex (&yylval, scanner);
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
        case 19:
#line 151 "JsonRideFile.y" /* yacc.c:1646  */
    {
                                          QDateTime aslocal = QDateTime::fromString(jc->JsonString, DATETIME_FORMAT);
                                          QDateTime asUTC = QDateTime(aslocal.date(), aslocal.time(), Qt::UTC);
                                          jc->JsonRide->setStartTime(asUTC.toLocalTime());
                                        }
#line 1540 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 156 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonRide->setRecIntSecs(jc->JsonNumber); }
#line 1546 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 157 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonRide->setDeviceType(jc->JsonString); }
#line 1552 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 158 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonRide->setId(jc->JsonString); }
#line 1558 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 166 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonRide->metricOverrides.insert(jc->JsonOverName, jc->JsonOverrides);
                                                      jc->JsonOverrides.clear();
                                                    }
#line 1566 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 171 "JsonRideFile.y" /* yacc.c:1646  */
    { if (jc->JsonString == "Time Riding") jc->JsonOverName = "Time Moving";
                                          else jc->JsonOverName = jc->JsonString; }
#line 1573 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 176 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonOverrides.insert(jc->JsonOverKey, jc->JsonOverValue); }
#line 1579 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 177 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonOverKey = jc->JsonString; }
#line 1585 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 178 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonOverValue = jc->JsonString; }
#line 1591 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 185 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonRide->setTag(jc->JsonTagKey, jc->JsonTagValue); }
#line 1597 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 188 "JsonRideFile.y" /* yacc.c:1646  */
    { if (jc->JsonString == "Time Riding") jc->JsonTagKey = "Time Moving";
                                          else jc->JsonTagKey = jc->JsonString; }
#line 1604 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 191 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonTagValue = jc->JsonString; }
#line 1610 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 198 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonInterval.name = jc->JsonString; }
#line 1616 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 199 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonInterval.start = jc->JsonNumber; }
#line 1622 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 200 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonInterval.stop = jc->JsonNumber; }
#line 1628 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 202 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonRide->addInterval(RideFileInterval::USER,
                                                                jc->JsonInterval.start,
                                                                jc->JsonInterval.stop,
                                                                jc->JsonInterval.name);
                                          jc->JsonInterval = RideFileInterval();
                                        }
#line 1639 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 214 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonCalibration.name = jc->JsonString; }
#line 1645 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 215 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonCalibration.start = jc->JsonNumber; }
#line 1651 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 216 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonCalibration.value = jc->JsonNumber; }
#line 1657 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 218 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonRide->addCalibration(jc->JsonCalibration.start,
                                                                   jc->JsonCalibration.value,
                                                                   jc->JsonCalibration.name);
                                          jc->JsonCalibration = RideFileCalibration();
                                        }
#line 1667 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 229 "JsonRideFile.y" /* yacc.c:1646  */
    {
                                          jc->JsonPoint = RideFilePoint();
                                        }
#line 1675 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 233 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonRide->appendReference(jc->JsonPoint);
                                          jc->JsonPoint = RideFilePoint();
                                        }
#line 1683 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 242 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonRide->appendPoint(jc->JsonPoint.secs, jc->JsonPoint.cad,
                                                    jc->JsonPoint.hr, jc->JsonPoint.km, jc->JsonPoint.kph,
                                                    jc->JsonPoint.nm, jc->JsonPoint.watts, jc->JsonPoint.alt,
                                                    jc->JsonPoint.lon, jc->JsonPoint.lat,
                                                    jc->JsonPoint.headwind,
                                                    jc->JsonPoint.slope, jc->JsonPoint.temp, jc->JsonPoint.lrbalance,
                                                    jc->JsonPoint.lte, jc->JsonPoint.rte,
                                                    jc->JsonPoint.lps, jc->JsonPoint.rps,
                                                    jc->JsonPoint.lpco, jc->JsonPoint.rpco,
                                                    jc->JsonPoint.lppb, jc->JsonPoint.rppb,
                                                    jc->JsonPoint.lppe, jc->JsonPoint.rppe,
                                                    jc->JsonPoint.lpppb, jc->JsonPoint.rpppb,
                                                    jc->JsonPoint.lpppe, jc->JsonPoint.rpppe,
                                                    jc->JsonPoint.smo2, jc->JsonPoint.thb,
                                                    jc->JsonPoint.rvert, jc->JsonPoint.rcad, jc->JsonPoint.rcontact,
                                                    jc->JsonPoint.tcore,
                                                    jc->JsonPoint.interval);
                                          jc->JsonPoint = RideFilePoint();
                                        }
#line 1707 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 263 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.secs = jc->JsonNumber; }
#line 1713 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 264 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.km = jc->JsonNumber; }
#line 1719 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 265 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.watts = jc->JsonNumber; }
#line 1725 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 266 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.nm = jc->JsonNumber; }
#line 1731 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 267 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.cad = jc->JsonNumber; }
#line 1737 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 268 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.kph = jc->JsonNumber; }
#line 1743 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 269 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.hr = jc->JsonNumber; }
#line 1749 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 270 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.alt = jc->JsonNumber; }
#line 1755 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 271 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.lat = jc->JsonNumber; }
#line 1761 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 272 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.lon = jc->JsonNumber; }
#line 1767 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 273 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.headwind = jc->JsonNumber; }
#line 1773 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 274 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.slope = jc->JsonNumber; }
#line 1779 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 275 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.temp = jc->JsonNumber; }
#line 1785 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 276 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.lrbalance = jc->JsonNumber; }
#line 1791 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 277 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.lte = jc->JsonNumber; }
#line 1797 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 278 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.rte = jc->JsonNumber; }
#line 1803 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 279 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.lps = jc->JsonNumber; }
#line 1809 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 280 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.rps = jc->JsonNumber; }
#line 1815 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 281 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.lpco = jc->JsonNumber; }
#line 1821 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 282 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.rpco = jc->JsonNumber; }
#line 1827 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 283 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.lppb = jc->JsonNumber; }
#line 1833 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 284 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.rppb = jc->JsonNumber; }
#line 1839 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 285 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.lppe = jc->JsonNumber; }
#line 1845 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 286 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.rppe = jc->JsonNumber; }
#line 1851 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 287 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.lpppb = jc->JsonNumber; }
#line 1857 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 288 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.rpppb = jc->JsonNumber; }
#line 1863 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 289 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.lpppe = jc->JsonNumber; }
#line 1869 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 290 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.rpppe = jc->JsonNumber; }
#line 1875 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 291 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.smo2 = jc->JsonNumber; }
#line 1881 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 292 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.thb = jc->JsonNumber; }
#line 1887 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 293 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.rvert = jc->JsonNumber; }
#line 1893 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 294 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.rcad = jc->JsonNumber; }
#line 1899 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 295 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonPoint.rcontact = jc->JsonNumber; }
#line 1905 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 296 "JsonRideFile.y" /* yacc.c:1646  */
    { }
#line 1911 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 304 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonNumber = QString((yyvsp[0])).toInt(); }
#line 1917 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 305 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonNumber = QString((yyvsp[0])).toDouble(); }
#line 1923 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 308 "JsonRideFile.y" /* yacc.c:1646  */
    { jc->JsonString = (yyvsp[0]); }
#line 1929 "JsonRideFile.tab.c" /* yacc.c:1646  */
    break;


#line 1933 "JsonRideFile.tab.c" /* yacc.c:1646  */
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
      yyerror (jc, YY_("syntax error"));
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
        yyerror (jc, yymsgp);
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
                      yytoken, &yylval, jc);
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
                  yystos[yystate], yyvsp, jc);
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
  yyerror (jc, YY_("memory exhausted"));
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
                  yytoken, &yylval, jc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, jc);
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
#line 310 "JsonRideFile.y" /* yacc.c:1906  */



static int jsonFileReaderRegistered =
    RideFileFactory::instance().registerReader(
        "json", "GoldenCheetah Json", new JsonFileReader());

RideFile *
JsonFileReader::openRideFile(QFile &file, QStringList &errors, QList<RideFile*>*) const
{
    // Read the entire file into a QString -- we avoid using fopen since it
    // doesn't handle foreign characters well. Instead we use QFile and parse
    // from a QString
    QString contents;
    if (file.exists() && file.open(QFile::ReadOnly | QFile::Text)) {

        // read in the whole thing
        QTextStream in(&file);
        // GC .JSON is stored in UTF-8 with BOM(Byte order mark) for identification
        in.setCodec ("UTF-8");
        contents = in.readAll();
        file.close();

        // check if the text string contains the replacement character for UTF-8 encoding
        // if yes, try to read with Latin1/ISO 8859-1 (assuming this is an "old" non-UTF-8 Json file)
        if (contents.contains(QChar::ReplacementCharacter)) {
           if (file.exists() && file.open(QFile::ReadOnly | QFile::Text)) {
             QTextStream in(&file);
             in.setCodec ("ISO 8859-1");
             contents = in.readAll();
             file.close();
           }
         }

    } else {

        errors << "unable to open file" + file.fileName();
        return NULL; 
    }

    // create scanner context for reentrant parsing
    JsonContext *jc = new JsonContext;
    JsonRideFilelex_init(&scanner);

    // inform the parser/lexer we have a new file
    JsonRideFile_setString(contents, scanner);

    // setup
    jc->JsonRide = new RideFile;
    jc->JsonRideFileerrors.clear();

    // set to non-zero if you want to
    // to debug the yyparse() state machine
    // sending state transitions to stderr
    //yydebug = 0;

    // parse it
    JsonRideFileparse(jc);

    // clean up
    JsonRideFilelex_destroy(scanner);

    // Only get errors so fail if we have any
    // and always delete context now we're done
    if (errors.count()) {
        errors << jc->JsonRideFileerrors;
        delete jc->JsonRide;
        delete jc;
        return NULL;
    } else {
        RideFile *returning = jc->JsonRide;
        delete jc;
        return returning;
    }
}

// Writes valid .json (validated at www.jsonlint.com)
bool
JsonFileReader::writeRideFile(Context *, const RideFile *ride, QFile &file) const
{
    // can we open the file for writing?
    if (!file.open(QIODevice::WriteOnly)) return false;

    // truncate existing
    file.resize(0);

    // setup streamer
    QTextStream out(&file);
    // unified codepage and BOM for identification on all platforms
    out.setCodec("UTF-8");
    out.setGenerateByteOrderMark(true);

    // start of document and ride
    out << "{\n\t\"RIDE\":{\n";

    // first class variables
    out << "\t\t\"STARTTIME\":\"" << protect(ride->startTime().toUTC().toString(DATETIME_FORMAT)) << "\",\n";
    out << "\t\t\"RECINTSECS\":" << ride->recIntSecs() << ",\n";
    out << "\t\t\"DEVICETYPE\":\"" << protect(ride->deviceType()) << "\",\n";
    out << "\t\t\"IDENTIFIER\":\"" << protect(ride->id()) << "\"";

    //
    // OVERRIDES
    //
    bool nonblanks = false; // if an override has been deselected it may be blank
                            // so we only output the OVERRIDES section if we find an
                            // override whilst iterating over the QMap

    if (ride->metricOverrides.count()) {


        QMap<QString,QMap<QString, QString> >::const_iterator k;
        for (k=ride->metricOverrides.constBegin(); k != ride->metricOverrides.constEnd(); k++) {

            // may not contain anything
            if (k.value().isEmpty()) continue;

            if (nonblanks == false) {
                out << ",\n\t\t\"OVERRIDES\":[\n";
                nonblanks = true;

            }
            // begin of overrides
            out << "\t\t\t{ \"" << k.key() << "\":{ ";

            // key/value pairs
            QMap<QString, QString>::const_iterator j;
            for (j=k.value().constBegin(); j != k.value().constEnd(); j++) {

                // comma separated
                out << "\"" << j.key() << "\":\"" << j.value() << "\"";
                if (j+1 != k.value().constEnd()) out << ", ";
            }
            if (k+1 != ride->metricOverrides.constEnd()) out << " }},\n";
            else out << " }}\n";
        }

        if (nonblanks == true) {
            // end of the overrides
            out << "\t\t]";
        }
    }

    //
    // TAGS
    //
    if (ride->tags().count()) {

        out << ",\n\t\t\"TAGS\":{\n";

        QMap<QString,QString>::const_iterator i;
        for (i=ride->tags().constBegin(); i != ride->tags().constEnd(); i++) {

                out << "\t\t\t\"" << i.key() << "\":\"" << protect(i.value()) << "\"";
                if (i+1 != ride->tags().constEnd()) out << ",\n";
                else out << "\n";
        }

        // end of the tags
        out << "\t\t}";
    }

    //
    // INTERVALS
    //
    if (!ride->intervals().empty()) {

        out << ",\n\t\t\"INTERVALS\":[\n";
        bool first = true;

        foreach (RideFileInterval *i, ride->intervals()) {
            if (first) first=false;
            else out << ",\n";

            out << "\t\t\t{ ";
            out << "\"NAME\":\"" << protect(i->name) << "\"";
            out << ", \"START\": " << QString("%1").arg(i->start);
            out << ", \"STOP\": " << QString("%1").arg(i->stop) << " }";
        }
        out <<"\n\t\t]";
    }

    //
    // CALIBRATION
    //
    if (!ride->calibrations().empty()) {

        out << ",\n\t\t\"CALIBRATIONS\":[\n";
        bool first = true;

        foreach (RideFileCalibration *i, ride->calibrations()) {
            if (first) first=false;
            else out << ",\n";

            out << "\t\t\t{ ";
            out << "\"NAME\":\"" << protect(i->name) << "\"";
            out << ", \"START\": " << QString("%1").arg(i->start);
            out << ", \"VALUE\": " << QString("%1").arg(i->value) << " }";
        }
        out <<"\n\t\t]";
    }

    //
    // REFERENCES
    //
    if (!ride->referencePoints().empty()) {

        out << ",\n\t\t\"REFERENCES\":[\n";
        bool first = true;

        foreach (RideFilePoint *p, ride->referencePoints()) {
            if (first) first=false;
            else out << ",\n";

            out << "\t\t\t{ ";

            if (p->watts > 0) out << " \"WATTS\":" << QString("%1").arg(p->watts);
            if (p->cad > 0) out << " \"CAD\":" << QString("%1").arg(p->cad);
            if (p->hr > 0) out << " \"HR\":"  << QString("%1").arg(p->hr);

            // sample points in here!
            out << " }";
        }
        out <<"\n\t\t]";
    }

    //
    // SAMPLES
    //
    if (ride->dataPoints().count()) {

        out << ",\n\t\t\"SAMPLES\":[\n";
        bool first = true;

        foreach (RideFilePoint *p, ride->dataPoints()) {

            if (first) first=false;
            else out << ",\n";

            out << "\t\t\t{ ";

            // always store time
            out << "\"SECS\":" << QString("%1").arg(p->secs);

            if (ride->areDataPresent()->km) out << ", \"KM\":" << QString("%1").arg(p->km);
            if (ride->areDataPresent()->watts) out << ", \"WATTS\":" << QString("%1").arg(p->watts);
            if (ride->areDataPresent()->nm) out << ", \"NM\":" << QString("%1").arg(p->nm);
            if (ride->areDataPresent()->cad) out << ", \"CAD\":" << QString("%1").arg(p->cad);
            if (ride->areDataPresent()->kph) out << ", \"KPH\":" << QString("%1").arg(p->kph);
            if (ride->areDataPresent()->hr) out << ", \"HR\":"  << QString("%1").arg(p->hr);
            if (ride->areDataPresent()->alt) out << ", \"ALT\":" << QString("%1").arg(p->alt);
            if (ride->areDataPresent()->lat)
                out << ", \"LAT\":" << QString("%1").arg(p->lat, 0, 'g', 11);
            if (ride->areDataPresent()->lon)
                out << ", \"LON\":" << QString("%1").arg(p->lon, 0, 'g', 11);
            if (ride->areDataPresent()->headwind) out << ", \"HEADWIND\":" << QString("%1").arg(p->headwind);
            if (ride->areDataPresent()->slope) out << ", \"SLOPE\":" << QString("%1").arg(p->slope);
            if (ride->areDataPresent()->temp && p->temp != RideFile::NoTemp) out << ", \"TEMP\":" << QString("%1").arg(p->temp);
            if (ride->areDataPresent()->lrbalance) out << ", \"LRBALANCE\":" << QString("%1").arg(p->lrbalance);
            if (ride->areDataPresent()->lte) out << ", \"LTE\":" << QString("%1").arg(p->lte);
            if (ride->areDataPresent()->rte) out << ", \"RTE\":" << QString("%1").arg(p->rte);
            if (ride->areDataPresent()->lps) out << ", \"LPS\":" << QString("%1").arg(p->lps);
            if (ride->areDataPresent()->rps) out << ", \"RPS\":" << QString("%1").arg(p->rps);
            if (ride->areDataPresent()->lpco) out << ", \"LPCO\":" << QString("%1").arg(p->lpco);
            if (ride->areDataPresent()->rpco) out << ", \"RPCO\":" << QString("%1").arg(p->rpco);
            if (ride->areDataPresent()->lppb) out << ", \"LPPB\":" << QString("%1").arg(p->lppb);
            if (ride->areDataPresent()->rppb) out << ", \"RPPB\":" << QString("%1").arg(p->rppb);
            if (ride->areDataPresent()->lppe) out << ", \"LPPE\":" << QString("%1").arg(p->lppe);
            if (ride->areDataPresent()->rppe) out << ", \"RPPE\":" << QString("%1").arg(p->rppe);
            if (ride->areDataPresent()->lpppb) out << ", \"LPPPB\":" << QString("%1").arg(p->lpppb);
            if (ride->areDataPresent()->rpppb) out << ", \"RPPPB\":" << QString("%1").arg(p->rpppb);
            if (ride->areDataPresent()->lpppe) out << ", \"LPPPE\":" << QString("%1").arg(p->lpppe);
            if (ride->areDataPresent()->rpppe) out << ", \"RPPPE\":" << QString("%1").arg(p->rpppe);
            if (ride->areDataPresent()->smo2) out << ", \"SMO2\":" << QString("%1").arg(p->smo2);
            if (ride->areDataPresent()->thb) out << ", \"THB\":" << QString("%1").arg(p->thb);
            if (ride->areDataPresent()->rcad) out << ", \"RCAD\":" << QString("%1").arg(p->rcad);
            if (ride->areDataPresent()->rvert) out << ", \"RVERT\":" << QString("%1").arg(p->rvert);
            if (ride->areDataPresent()->rcontact) out << ", \"RCON\":" << QString("%1").arg(p->rcontact);

            // sample points in here!
            out << " }";
        }
        out <<"\n\t\t]";
    }

    // end of ride and document
    out << "\n\t}\n}\n";

    // close
    file.close();

    return true;
}
