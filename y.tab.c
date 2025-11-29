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
#line 1 "prob2.y"

    #include <stdio.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    int yylex();
    int yyerror(char *);
    extern FILE *yyin;
    char str[100];
    char type[100];
    int size;
    bool stat=false;
    static int labelv=1;
    static int tempv=1;
    struct Stack {
	 int data;
	 struct Stack* next;
    };
    struct s{
	int True;
	int False;
	int next;
	int lexval;
	int val;
	char code[10000];
	struct s* left;
	struct s* right;
	char op[20];
    };
    struct Stack* newNode(int data)
    {
	 struct Stack* Stack = (struct Stack*)
	 malloc(sizeof(struct Stack));
	 Stack->data = data;
	 Stack->next = NULL;
	 return Stack;
    }
  
   int empty(struct Stack* root)
	{
	    return !root;
	}
    
     int top(struct Stack* root)
     {
		    if (empty(root))
			return -1;
		    return root->data;
     }
   void pop(struct Stack** root)
   {
	  if (empty(*root))
		return -1;
	  struct Stack* temp = *root;
	  *root = (*root)->next;
	  int popped = temp->data;
	  free(temp);
	  
	  
   }
  
    void push(struct Stack** root, int data)
    {
	  struct Stack* Stack = newNode(data);
	  Stack->next = *root;
	  *root = Stack;
	  
    }
  

    struct TypeNode{
        char type[20];
        int size;
    };
    struct new_Entry{
        char lexeme [20];
        char type [50];
        int addr;
        
        struct new_Entry* next;
    };
    struct new_Entry* global  = NULL;
    struct new_Entry* head = NULL;
    struct Stack* st = NULL;
    
    struct SymbolTable{
        struct new_Entry* head;
        struct new_Entry* tail;
        struct SymbolTable* prev;
    };
    
    struct SymbolTable* SymbolTemp=NULL;
    struct SymbolTable* SymbolHead=NULL;
   
    int verify(struct SymbolTable* symbol,char lexeme[], char type[]); 
    char* typeofvar(struct SymbolTable* symbol,char lexeme [ ]);
    void add_name(struct SymbolTable* symbol,int addr , char lexeme [ ], char type[]);
    void Construct(struct SymbolTable* symbol,struct SymbolTable* prev);
    char* itoa(int num);
    char* maximized(char* str);
    int minimized(char* str);
    int prec(char* type);
    void Symbol_Table();
    char* mini(char* str,int i);
    char* traversal(struct s* node);

#line 178 "y.tab.c"

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FloatNUM = 258,
    DoubleNUM = 259,
    NUM = 260,
    ID = 261,
    INT = 262,
    LONG = 263,
    FLOAT = 264,
    DOUBLE = 265,
    STRING = 266,
    CHAR = 267,
    LBracket = 268,
    RBracket = 269,
    INC = 270,
    DEC = 271,
    COMP = 272,
    IF = 273,
    ELSE = 274,
    While = 275,
    or = 276,
    and = 277
  };
#endif
/* Tokens.  */
#define FloatNUM 258
#define DoubleNUM 259
#define NUM 260
#define ID 261
#define INT 262
#define LONG 263
#define FLOAT 264
#define DOUBLE 265
#define STRING 266
#define CHAR 267
#define LBracket 268
#define RBracket 269
#define INC 270
#define DEC 271
#define COMP 272
#define IF 273
#define ELSE 274
#define While 275
#define or 276
#define and 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 109 "prob2.y"

    char addr[100];
    struct TypeNode* TypeNode;
    struct SymbolTable* SymbolTable;
    struct s* eval;

#line 281 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   107

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  99

#define YYUNDEFTOK  2
#define YYMAXUTOK   277


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
      23,    24,    29,    27,    31,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
       2,    26,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,    33,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   123,   123,   123,   131,   137,   142,   172,   203,   231,
     234,   237,   241,   241,   265,   288,   314,   329,   344,   351,
     367,   383,   391,   399,   413,   437,   461,   482,   511,   534,
     557,   585,   611,   634,   657,   685,   712,   719,   726,   733,
     741,   748,   758,   758,   763,   763,   784,   813,   857,   857,
     894,   912,   925,   937
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FloatNUM", "DoubleNUM", "NUM", "ID",
  "INT", "LONG", "FLOAT", "DOUBLE", "STRING", "CHAR", "LBracket",
  "RBracket", "INC", "DEC", "COMP", "IF", "ELSE", "While", "or", "and",
  "'('", "')'", "';'", "'='", "'+'", "'-'", "'*'", "'/'", "','", "'['",
  "']'", "$accept", "Start", "$@1", "List", "Comp", "Stmt", "$@2", "Arth",
  "Term", "Fact", "TYPE", "Block", "$@3", "Expr", "$@4", "$@5", "Cond", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    40,    41,    59,    61,    43,    45,    42,
      47,    44,    91,    93
};
# endif

#define YYPACT_NINF (-30)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-49)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -7,   -30,    30,    41,   -30,   -13,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,    -4,    10,    12,    41,    16,    54,   -30,
     -30,   -30,    44,    41,    34,    34,   -30,   -30,   -30,     6,
      48,    19,    60,    58,    61,    52,    53,    74,    50,    56,
     -30,   -30,   -30,   -30,    28,    77,    78,     5,    18,    26,
     -30,   -30,    57,    59,    72,    73,    55,    54,    19,   -30,
     -30,   -30,   -30,   -23,    63,    19,    19,    19,    19,   -30,
     -30,   -30,   -30,    41,    41,   -30,   -30,    18,   -30,    21,
      26,    26,   -30,   -30,    75,    76,    51,    85,    86,    79,
     -30,   -30,   -30,   -30,   -30,    80,    41,    81,   -30
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     2,     0,     0,     1,    12,    37,    38,    39,    40,
      41,    36,    42,     0,     0,     0,     5,     0,     0,     9,
      14,    15,     0,     0,     0,     0,     3,     4,    11,    44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    24,    25,    23,    26,     0,     0,     0,    13,    18,
      21,    43,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    32,    33,     0,     0,     0,     0,     0,     0,    53,
      51,    52,    50,     0,     0,    47,    45,    49,    22,     0,
      16,    17,    19,    20,     0,     0,    27,     0,     0,     6,
       8,    30,    31,    34,    35,     0,     0,     0,     7
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,   -30,   -16,   -30,   -30,   -30,   -29,     3,     4,
      47,   -30,   -30,    39,   -30,   -30,    82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    15,    16,    17,    22,    48,    49,    50,
      18,    19,    23,    30,    38,    39,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      27,    78,    20,    21,    65,    66,     1,    32,    41,    42,
      43,    44,     6,     7,     8,     9,    10,    11,    63,    24,
      45,    46,    41,    42,    43,    44,    26,    86,    47,    77,
       4,   -46,   -48,    25,    45,    46,    87,    88,    37,    33,
      34,    28,    47,    59,    60,    65,    66,     5,     6,     7,
       8,     9,    10,    11,    12,    67,    68,    84,    85,    13,
      29,    14,    69,    70,    71,    72,    91,    92,    80,    81,
      31,    82,    83,    40,    51,    52,    54,    55,    53,    56,
      97,    57,    58,    61,    62,    73,    74,    79,    75,    89,
      90,    93,    94,    96,    64,    98,    76,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,    36
};

static const yytype_int8 yycheck[] =
{
      16,    24,    15,    16,    27,    28,    13,    23,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    47,    23,
      15,    16,     3,     4,     5,     6,    14,     6,    23,    58,
       0,    25,    26,    23,    15,    16,    15,    16,    32,     5,
       6,    25,    23,    15,    16,    27,    28,     6,     7,     8,
       9,    10,    11,    12,    13,    29,    30,    73,    74,    18,
       6,    20,     5,     6,     5,     6,    15,    16,    65,    66,
      26,    67,    68,    25,    14,    17,    24,    24,    17,     5,
      96,    31,    26,     6,     6,    13,    13,    24,    33,    14,
      14,     6,     6,    13,    47,    14,    57,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    35,    36,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    18,    20,    37,    38,    39,    44,    45,
      15,    16,    40,    46,    23,    23,    14,    37,    25,     6,
      47,    26,    37,     5,     6,    50,    50,    32,    48,    49,
      25,     3,     4,     5,     6,    15,    16,    23,    41,    42,
      43,    14,    17,    17,    24,    24,     5,    31,    26,    15,
      16,     6,     6,    41,    44,    27,    28,    29,    30,     5,
       6,     5,     6,    13,    13,    33,    47,    41,    24,    24,
      42,    42,    43,    43,    37,    37,     6,    15,    16,    14,
      14,    15,    16,     6,     6,    19,    13,    37,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    36,    35,    37,    37,    37,    37,    37,    38,
      38,    38,    40,    39,    39,    39,    41,    41,    41,    42,
      42,    42,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    44,    44,    44,    44,
      44,    44,    46,    45,    48,    47,    47,    47,    49,    47,
      50,    50,    50,    50
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     2,     1,     7,    11,     7,     1,
       3,     2,     0,     4,     2,     2,     3,     3,     1,     3,
       3,     1,     3,     1,     1,     1,     1,     4,     2,     2,
       5,     5,     2,     2,     5,     5,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     4,     1,     4,     0,     4,
       3,     3,     3,     3
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
#line 123 "prob2.y"
                 {push(&st,0);SymbolHead=(struct SymbolTable*)malloc(sizeof(struct SymbolTable));Construct(SymbolHead,SymbolTemp);SymbolTemp=SymbolHead;}
#line 1516 "y.tab.c"
    break;

  case 3:
#line 123 "prob2.y"
                                                                                                                                                                        {pop(&st);if(stat==false){printf(" Given program is Accepted\n"); Symbol_Table();}(yyval.eval) = (struct s*)malloc(sizeof(struct s));
                               strcpy((yyval.eval)->code, (yyvsp[-1].eval)->code);
                               if(stat==false){
                                printf("\n-------------TAC of the given code ------------\n%s", (yyvsp[-1].eval)->code);
                                printf("--------------------**------------------------\n");};
                               }
#line 1527 "y.tab.c"
    break;

  case 4:
#line 131 "prob2.y"
                  {
	                        (yyval.eval) = (struct s*)malloc(sizeof(struct s));
                                strcat((yyvsp[-1].eval)->code, (yyvsp[0].eval)->code);
                                strcpy((yyval.eval)->code, (yyvsp[-1].eval)->code);

        }
#line 1538 "y.tab.c"
    break;

  case 5:
#line 137 "prob2.y"
              {
	                        (yyval.eval) = (struct s*)malloc(sizeof(struct s));
                                strcpy((yyval.eval)->code, (yyvsp[0].eval)->code);

        }
#line 1548 "y.tab.c"
    break;

  case 6:
#line 142 "prob2.y"
                                                 {
        					
          					(yyval.eval) = (struct s*)malloc(sizeof(struct s));
          					(yyvsp[-4].eval)->True=labelv;
          					labelv++;
          					(yyvsp[-4].eval)->False=labelv;
          					labelv++;
          				        //printf("%s",$3->left->code);
          				        //printf($3->right->code);
          					(yyval.eval)->next=(yyvsp[-4].eval)->False;
          					(yyvsp[-1].eval)->next=(yyvsp[-4].eval)->False;
          					//char co[20];
          				        //strcpy(co,"1");
          					//printf("%s",co);
          					strcpy((yyval.eval)->code,"if ");
						strcat((yyval.eval)->code,(yyvsp[-4].eval)->code);
						strcat((yyval.eval)->code," goto label");
						strcat((yyval.eval)->code,itoa((yyvsp[-4].eval)->True));
						strcat((yyval.eval)->code,"\n");
						strcat((yyval.eval)->code,"goto label");
						strcat((yyval.eval)->code,itoa((yyvsp[-4].eval)->False));
						strcat((yyval.eval)->code,"\n");
          					strcat((yyval.eval)->code,"label");
          					strcat((yyval.eval)->code,itoa((yyvsp[-4].eval)->True));
          					strcat((yyval.eval)->code,":\n");
          					strcat((yyval.eval)->code,(yyvsp[-1].eval)->code);
          					strcat((yyval.eval)->code,"label");
          					strcat((yyval.eval)->code,itoa((yyvsp[-4].eval)->False));
          					strcat((yyval.eval)->code,":\n");
                                          }
#line 1583 "y.tab.c"
    break;

  case 7:
#line 172 "prob2.y"
                                                                               {
          							        (yyval.eval) = (struct s*)malloc(sizeof(struct s));
				  					(yyvsp[-8].eval)->True=labelv;
				  					labelv++;
				  					(yyvsp[-8].eval)->False=labelv;
				  					labelv++;
				  					(yyval.eval)->next=(yyvsp[-8].eval)->False;
          								(yyvsp[-5].eval)->next=(yyvsp[-8].eval)->False;
          								(yyvsp[-1].eval)->next=(yyvsp[-8].eval)->False;
				  					strcpy((yyval.eval)->code,"if ");
									strcat((yyval.eval)->code,(yyvsp[-8].eval)->code);
									strcat((yyval.eval)->code," goto label");
									strcat((yyval.eval)->code,itoa((yyvsp[-8].eval)->True));
									strcat((yyval.eval)->code,"\n");
									strcat((yyval.eval)->code,"goto label");
									strcat((yyval.eval)->code,itoa((yyvsp[-8].eval)->False));
									strcat((yyval.eval)->code,"\n");
				  					strcat((yyval.eval)->code,"label");
				  					strcat((yyval.eval)->code,itoa((yyvsp[-8].eval)->True));
				  					strcat((yyval.eval)->code,":\n");
				  					strcat((yyval.eval)->code,(yyvsp[-5].eval)->code);
				  					strcat((yyval.eval)->code,"label");
				  					strcat((yyval.eval)->code,itoa((yyvsp[-8].eval)->False));
				  					strcat((yyval.eval)->code,":\n");
				  					strcat((yyval.eval)->code,(yyvsp[-1].eval)->code);
				  					strcat((yyval.eval)->code,"label");
				  					strcat((yyval.eval)->code,itoa(labelv));
				  					strcat((yyval.eval)->code,":\n");
				  					labelv++;	
          							}
#line 1618 "y.tab.c"
    break;

  case 8:
#line 203 "prob2.y"
                                                     {
         					(yyval.eval) = (struct s*)malloc(sizeof(struct s));
         					(yyvsp[-4].eval)->True=labelv;
         					labelv++;
         					(yyvsp[-4].eval)->False=labelv;
         					labelv++;
         					(yyval.eval)->next=(yyvsp[-4].eval)->False;
          					(yyvsp[-1].eval)->next=(yyvsp[-4].eval)->True;
          					strcpy((yyval.eval)->code,"label");
				  		strcat((yyval.eval)->code,itoa((yyvsp[-4].eval)->True));
				  		strcat((yyval.eval)->code,":\n");
         					strcat((yyval.eval)->code,"ifFalse ");
				  		strcat((yyval.eval)->code,(yyvsp[-4].eval)->code);
				  		strcat((yyval.eval)->code," goto label");
				  		strcat((yyval.eval)->code,itoa((yyvsp[-4].eval)->False));
				  		strcat((yyval.eval)->code,"\n");
				  		strcat((yyval.eval)->code,(yyvsp[-1].eval)->code);
				  		strcat((yyval.eval)->code,"goto label");
				  		strcat((yyval.eval)->code,itoa((yyvsp[-4].eval)->True));
				  		strcat((yyval.eval)->code,"\n");
				  		strcat((yyval.eval)->code,"label");
				  		strcat((yyval.eval)->code,itoa((yyvsp[-4].eval)->False));
				  		strcat((yyval.eval)->code,":\n");
         				      }
#line 1647 "y.tab.c"
    break;

  case 9:
#line 231 "prob2.y"
              {             (yyval.eval) = (struct s*)malloc(sizeof(struct s));   
                                strcpy((yyval.eval)->code, (yyvsp[0].eval)->code);
              }
#line 1655 "y.tab.c"
    break;

  case 10:
#line 234 "prob2.y"
                       {   (yyval.eval) = (struct s*)malloc(sizeof(struct s));   
                                strcpy((yyval.eval)->code, (yyvsp[-1].eval)->code);
	}
#line 1663 "y.tab.c"
    break;

  case 11:
#line 237 "prob2.y"
                 {   (yyval.eval) = (struct s*)malloc(sizeof(struct s));   
                                strcpy((yyval.eval)->code, (yyvsp[-1].eval)->code);}
#line 1670 "y.tab.c"
    break;

  case 12:
#line 241 "prob2.y"
           {
	    if(strcmp(typeofvar(SymbolTemp,(yyvsp[0].addr)),"none")==0){
           		 stat=true;
           		 printf("error:not declared %s\n",(yyvsp[0].addr));
            }
            else{
               strcpy(type,typeofvar(SymbolTemp,(yyvsp[0].addr)));
               //printf("%s\n",type);
            }
        }
#line 1685 "y.tab.c"
    break;

  case 13:
#line 250 "prob2.y"
                  {
	                  
	                  (yyval.eval) = (struct s*)malloc(sizeof(struct s));
	                  strcpy((yyval.eval)->code,(yyvsp[0].eval)->code);
	                  
	                  strcat((yyval.eval)->code,(yyvsp[-3].addr));
	                  strcat((yyval.eval)->code, " = ");
	                  strcat((yyval.eval)->code, "t");
                          strcat((yyval.eval)->code, itoa((yyvsp[0].eval)->lexval));
			   strcat((yyval.eval)->code, "\n");
		           (yyval.eval)->lexval = (yyvsp[0].eval)->lexval;
		           //printf("%s",$$->code);
		           
		                  
	}
#line 1705 "y.tab.c"
    break;

  case 14:
#line 265 "prob2.y"
                { if(strcmp(typeofvar(SymbolTemp,(yyvsp[-1].addr)),type)!=0){
           		 stat=true;
           		if( strcmp(typeofvar(SymbolTemp,(yyvsp[-1].addr)),"none")==0){
           		    printf("error:not declared %s\n",(yyvsp[-1].addr));
           		}
           		else{
           		   printf("error:conflicting types in the above expression \n");
           		}
           		
            }
             (yyval.eval) = (struct s*)malloc(sizeof(struct s));
             strcpy((yyval.eval)->code, "t");
             strcat((yyval.eval)->code, itoa(tempv)); 
             strcat((yyval.eval)->code, " = ");
             strcat((yyval.eval)->code, (yyvsp[0].addr));
             strcat((yyval.eval)->code, " + 1\n");
             strcat((yyval.eval)->code, (yyvsp[0].addr));
             strcat((yyval.eval)->code, " = t");
             strcat((yyval.eval)->code, itoa(tempv));
             strcat((yyval.eval)->code, "\n");
             (yyval.eval)->lexval = tempv;
             tempv++;
         }
#line 1733 "y.tab.c"
    break;

  case 15:
#line 288 "prob2.y"
                 { if(strcmp(typeofvar(SymbolTemp,(yyvsp[-1].addr)),type)!=0){
           		 stat=true;
           		if( strcmp(typeofvar(SymbolTemp,(yyvsp[-1].addr)),"none")==0){
           		    printf("error:not declared %s\n",(yyvsp[-1].addr));
           		}
           		else{
           		   printf("error:conflicting types in the above expression \n");
           		}
           		
            }
            (yyval.eval) = (struct s*)malloc(sizeof(struct s));
             strcpy((yyval.eval)->code, "t");
             strcat((yyval.eval)->code, itoa(tempv)); 
             strcat((yyval.eval)->code, " = ");
             strcat((yyval.eval)->code, (yyvsp[0].addr));
             strcat((yyval.eval)->code, " - 1\n");
             strcat((yyval.eval)->code, (yyvsp[0].addr));
             strcat((yyval.eval)->code, " = t");
             strcat((yyval.eval)->code, itoa(tempv));
             strcat((yyval.eval)->code, "\n");
             (yyval.eval)->lexval = tempv;
             tempv++;
         }
#line 1761 "y.tab.c"
    break;

  case 16:
#line 314 "prob2.y"
                       {            (yyval.eval) = (struct s*)malloc(sizeof(struct s));
                                    strcpy((yyval.eval)->code, (yyvsp[-2].eval)->code);
                                    strcat((yyval.eval)->code, (yyvsp[0].eval)->code);
                                    strcat((yyval.eval)->code, "t");
                                    strcat((yyval.eval)->code, itoa(tempv));
                                    strcat((yyval.eval)->code, " = ");
                                    strcat((yyval.eval)->code, "t");
                                    strcat((yyval.eval)->code, itoa((yyvsp[-2].eval)->lexval));
                                    strcat((yyval.eval)->code, " + ");
                                    strcat((yyval.eval)->code, "t");
                                    strcat((yyval.eval)->code, itoa((yyvsp[0].eval)->lexval));
                                    strcat((yyval.eval)->code, "\n");
                                    (yyval.eval)->lexval = tempv;
                                    tempv++;
                       }
#line 1781 "y.tab.c"
    break;

  case 17:
#line 329 "prob2.y"
                       {            (yyval.eval) = (struct s*)malloc(sizeof(struct s));
                                    strcpy((yyval.eval)->code, (yyvsp[-2].eval)->code);
                                    strcat((yyval.eval)->code, (yyvsp[0].eval)->code);
                                    strcat((yyval.eval)->code, "t");
                                    strcat((yyval.eval)->code, itoa(tempv));
                                    strcat((yyval.eval)->code, " = ");
                                    strcat((yyval.eval)->code, "t");
                                    strcat((yyval.eval)->code, itoa((yyvsp[-2].eval)->lexval));
                                    strcat((yyval.eval)->code, " - ");
                                    strcat((yyval.eval)->code, "t");
                                    strcat((yyval.eval)->code, itoa((yyvsp[0].eval)->lexval));
                                    strcat((yyval.eval)->code, "\n");
                                    (yyval.eval)->lexval = tempv;
                                    tempv++;
			}
#line 1801 "y.tab.c"
    break;

  case 18:
#line 344 "prob2.y"
                       { 
			 
			(yyval.eval) = (struct s*)malloc(sizeof(struct s));
                         strcpy((yyval.eval)->code, (yyvsp[0].eval)->code);
                         (yyval.eval)->lexval = (yyvsp[0].eval)->lexval;
                         //printf("%s",$$->code);
	}
#line 1813 "y.tab.c"
    break;

  case 19:
#line 351 "prob2.y"
                       {
		                    (yyval.eval) = (struct s*)malloc(sizeof(struct s));
                                    strcpy((yyval.eval)->code, (yyvsp[-2].eval)->code);
                                    strcat((yyval.eval)->code, (yyvsp[0].eval)->code);
                                    strcat((yyval.eval)->code, "t");
                                    strcat((yyval.eval)->code, itoa(tempv));
                                    strcat((yyval.eval)->code, " = ");
                                    strcat((yyval.eval)->code, "t");
                                    strcat((yyval.eval)->code, itoa((yyvsp[-2].eval)->lexval));
                                    strcat((yyval.eval)->code, " * ");
                                    strcat((yyval.eval)->code, "t");
                                    strcat((yyval.eval)->code, itoa((yyvsp[0].eval)->lexval));
                                    strcat((yyval.eval)->code, "\n");
                                    (yyval.eval)->lexval = tempv;
                                    tempv++;
	}
#line 1834 "y.tab.c"
    break;

  case 20:
#line 367 "prob2.y"
                       {
				     (yyval.eval) = (struct s*)malloc(sizeof(struct s));
                                    strcpy((yyval.eval)->code, (yyvsp[-2].eval)->code);
                                    strcat((yyval.eval)->code, (yyvsp[0].eval)->code);
                                    strcat((yyval.eval)->code, "t");
                                    strcat((yyval.eval)->code, itoa(tempv));
                                    strcat((yyval.eval)->code, " = ");
                                    strcat((yyval.eval)->code, "t");
                                    strcat((yyval.eval)->code, itoa((yyvsp[-2].eval)->lexval));
                                    strcat((yyval.eval)->code, " / ");
                                    strcat((yyval.eval)->code, "t");
                                    strcat((yyval.eval)->code, itoa((yyvsp[0].eval)->lexval));
                                    strcat((yyval.eval)->code, "\n");
                                    (yyval.eval)->lexval = tempv;
                                    tempv++;
                      }
#line 1855 "y.tab.c"
    break;

  case 21:
#line 383 "prob2.y"
               {
	                 
			  (yyval.eval) = (struct s*)malloc(sizeof(struct s));
                         strcpy((yyval.eval)->code, (yyvsp[0].eval)->code);
                         //printf("%s",$$->code);
                         (yyval.eval)->lexval = (yyvsp[0].eval)->lexval;
                         //printf("%d",$$->lexval);
              }
#line 1868 "y.tab.c"
    break;

  case 22:
#line 391 "prob2.y"
                     {
	                 
			  (yyval.eval) = (struct s*)malloc(sizeof(struct s));
                         strcpy((yyval.eval)->code, (yyvsp[-1].eval)->code);
                         //printf("%s",$$->code);
                         (yyval.eval)->lexval = (yyvsp[-1].eval)->lexval;
                         //printf("%d",$$->lexval);
              }
#line 1881 "y.tab.c"
    break;

  case 23:
#line 399 "prob2.y"
                    {
            (yyval.eval) = (struct s*)malloc(sizeof(struct s));
            strcpy((yyval.eval)->code, "t");
            strcat((yyval.eval)->code, itoa(tempv));
            strcat((yyval.eval)->code, " = ");
            strcat((yyval.eval)->code, (yyvsp[0].addr));
            if(prec(type)>prec("integer")){
              strcat((yyval.eval)->code, ".00");
            }
            strcat((yyval.eval)->code, "\n");
            (yyval.eval)->lexval=tempv;
            //printf("%s",$$->code);
            tempv++;
          }
#line 1900 "y.tab.c"
    break;

  case 24:
#line 413 "prob2.y"
                   {
            (yyval.eval) = (struct s*)malloc(sizeof(struct s));
            strcpy((yyval.eval)->code, "t");
            strcat((yyval.eval)->code, itoa(tempv));
            strcat((yyval.eval)->code, " = ");
            //printf("%s\n",type);
            int a=prec(type);
            int b=prec("float");
             //printf("1");
            if(a<b){
                //printf("1");
                int c=itoa(minimized((yyvsp[0].addr)));
            	strcat((yyval.eval)->code, mini((yyvsp[0].addr),c));
            }
            else{
            	//printf("1");
            	strcat((yyval.eval)->code, (yyvsp[0].addr));
            }
            //printf("%s\n",type);
            strcat((yyval.eval)->code, "\n");
            (yyval.eval)->lexval=tempv;
            //printf("%s",$$->code);
            tempv++;
          }
#line 1929 "y.tab.c"
    break;

  case 25:
#line 437 "prob2.y"
                     {
            (yyval.eval) = (struct s*)malloc(sizeof(struct s));
            strcpy((yyval.eval)->code, "t");
            strcat((yyval.eval)->code, itoa(tempv));
            strcat((yyval.eval)->code, " = ");
            //printf("%s\n",type);
            int a=prec(type);
            int b=prec("float");
             //printf("1");
            if(a<b){
                //printf("1");
                int c=itoa(minimized((yyvsp[0].addr)));
            	strcat((yyval.eval)->code, mini((yyvsp[0].addr),c));
            }
            else{
            	//printf("1");
            	strcat((yyval.eval)->code, (yyvsp[0].addr));
            }
            //printf("%s\n",type);
            strcat((yyval.eval)->code, "\n");
            (yyval.eval)->lexval=tempv;
            //printf("%s",$$->code);
            tempv++;
          }
#line 1958 "y.tab.c"
    break;

  case 26:
#line 461 "prob2.y"
              { if(strcmp(typeofvar(SymbolTemp,(yyvsp[0].addr)),type)!=0){
           		 stat=true;
           		if( strcmp(typeofvar(SymbolTemp,(yyvsp[0].addr)),"none")==0){
           		    printf("error:not declared %s\n",(yyvsp[0].addr));
           		}
           		else{
           		   printf("error:conflicting types in the above expression \n");
           		}
           		
            }
            (yyval.eval) = (struct s*)malloc(sizeof(struct s));
            strcpy((yyval.eval)->code, "");
            //strcat($$->code, itoa(tempv));
            //strcat($$->code, " = ");
            //strcat($$->code, $1);
            //strcat($$->code, "\n");
            //$$->lexval=tempv;
            //printf("%s",$$->code);
            //tempv++;
            
         }
#line 1984 "y.tab.c"
    break;

  case 27:
#line 482 "prob2.y"
                          { if(strcmp((yyvsp[-2].TypeNode)->type,type)!=0){
           		    //stat=true;
           		     //printf("%s\n",$2->type);
           		     //printf("%s\n",$2->type);
           		    printf("error:mismatching types %s\n",(yyvsp[0].addr));
           		 }
           		else if( strcmp(typeofvar(SymbolTemp,(yyvsp[0].addr)),"none")==0){
           		    stat=true;
           		    printf("error:not declared %s\n",(yyvsp[0].addr));
           		}
           		
           		   (yyval.eval) = (struct s*)malloc(sizeof(struct s));
			    strcpy((yyval.eval)->code, "t");
			    strcat((yyval.eval)->code, itoa(tempv));
			    strcat((yyval.eval)->code, " = ");
			    strcat((yyval.eval)->code, "(");
			    strcat((yyval.eval)->code, (yyvsp[-2].TypeNode)->type);
			    strcat((yyval.eval)->code, ")");
			    strcat((yyval.eval)->code, (yyvsp[0].addr));
			    strcat((yyval.eval)->code, "\n");
			    (yyval.eval)->lexval=tempv;
			    //printf("%s",$$->code);
			    tempv++;
           		
           	
           		
            
           
         }
#line 2018 "y.tab.c"
    break;

  case 28:
#line 511 "prob2.y"
                 { if(strcmp(typeofvar(SymbolTemp,(yyvsp[-1].addr)),type)!=0){
           		 stat=true;
           		if( strcmp(typeofvar(SymbolTemp,(yyvsp[-1].addr)),"none")==0){
           		    printf("error:not declared %s\n",(yyvsp[-1].addr));
           		}
           		else{
           		   printf("error:conflicting types in the above expression \n");
           		}
           		
            }
             (yyval.eval) = (struct s*)malloc(sizeof(struct s));
             strcpy((yyval.eval)->code, "t");
             strcat((yyval.eval)->code, itoa(tempv)); 
             strcat((yyval.eval)->code, " = ");
             strcat((yyval.eval)->code, (yyvsp[-1].addr));
             strcat((yyval.eval)->code, " + 1\n");
             strcat((yyval.eval)->code, (yyvsp[-1].addr));
             strcat((yyval.eval)->code, " = t");
             strcat((yyval.eval)->code, itoa(tempv));
             strcat((yyval.eval)->code, "\n");
             (yyval.eval)->lexval = tempv-1;
             tempv++;
         }
#line 2046 "y.tab.c"
    break;

  case 29:
#line 534 "prob2.y"
                 { if(strcmp(typeofvar(SymbolTemp,(yyvsp[-1].addr)),type)!=0){
           		 stat=true;
           		if( strcmp(typeofvar(SymbolTemp,(yyvsp[-1].addr)),"none")==0){
           		    printf("error:not declared %s\n",(yyvsp[-1].addr));
           		}
           		else{
           		   printf("error:conflicting types in the above expression \n");
           		}
           		
            }
            (yyval.eval) = (struct s*)malloc(sizeof(struct s));
             strcpy((yyval.eval)->code, "t");
             strcat((yyval.eval)->code, itoa(tempv)); 
             strcat((yyval.eval)->code, " = ");
             strcat((yyval.eval)->code, (yyvsp[-1].addr));
             strcat((yyval.eval)->code, " - 1\n");
             strcat((yyval.eval)->code, (yyvsp[-1].addr));
             strcat((yyval.eval)->code, " = t");
             strcat((yyval.eval)->code, itoa(tempv));
             strcat((yyval.eval)->code, "\n");
             (yyval.eval)->lexval = tempv-1;
             tempv++;
          }
#line 2074 "y.tab.c"
    break;

  case 30:
#line 557 "prob2.y"
                             { if(strcmp((yyvsp[-3].TypeNode)->type,type)!=0){
           		    stat=true;
           		   
           		    printf("error:mismatching types %s\n",(yyvsp[-1].addr));
           		 }
           		else if( strcmp(typeofvar(SymbolTemp,(yyvsp[-1].addr)),"none")==0){
           		    stat=true;
           		    printf("error:not declared %s\n",(yyvsp[-1].addr));
           		}
           		
           		
            
             (yyval.eval) = (struct s*)malloc(sizeof(struct s));
             strcpy((yyval.eval)->code, "t");
             strcat((yyval.eval)->code, itoa(tempv)); 
             strcat((yyval.eval)->code, " = ");
             strcat((yyval.eval)->code, "(");
             strcat((yyval.eval)->code, (yyvsp[-3].TypeNode)->type);
             strcat((yyval.eval)->code, ")");
             strcat((yyval.eval)->code, (yyvsp[-1].addr));
             strcat((yyval.eval)->code, " + 1\n");
             strcat((yyval.eval)->code, (yyvsp[-1].addr));
             strcat((yyval.eval)->code, " = t");
             strcat((yyval.eval)->code, itoa(tempv));
             strcat((yyval.eval)->code, "\n");
             (yyval.eval)->lexval = tempv-1;
             tempv++;
         }
#line 2107 "y.tab.c"
    break;

  case 31:
#line 585 "prob2.y"
                              {  if(strcmp((yyvsp[-3].TypeNode)->type,type)!=0){
           		    stat=true;
           		    printf("error:mismatching types %s\n",(yyvsp[-1].addr));
           		 }
           		else if( strcmp(typeofvar(SymbolTemp,(yyvsp[-1].addr)),"none")==0){
           		    stat=true;
           		    printf("error:not declared %s\n",(yyvsp[-1].addr));
           		}
            
            (yyval.eval) = (struct s*)malloc(sizeof(struct s));
             (yyval.eval) = (struct s*)malloc(sizeof(struct s));
             strcpy((yyval.eval)->code, "t");
             strcat((yyval.eval)->code, itoa(tempv)); 
             strcat((yyval.eval)->code, " = ");
             strcat((yyval.eval)->code, "(");
             strcat((yyval.eval)->code, (yyvsp[-3].TypeNode)->type);
             strcat((yyval.eval)->code, ")");
             strcat((yyval.eval)->code, (yyvsp[-1].addr));
             strcat((yyval.eval)->code, " - 1\n");
             strcat((yyval.eval)->code, (yyvsp[-1].addr));
             strcat((yyval.eval)->code, " = t");
             strcat((yyval.eval)->code, itoa(tempv));
             strcat((yyval.eval)->code, "\n");
             (yyval.eval)->lexval = tempv-1;
             tempv++;
         }
#line 2138 "y.tab.c"
    break;

  case 32:
#line 611 "prob2.y"
                  { if(strcmp(typeofvar(SymbolTemp,(yyvsp[0].addr)),type)!=0){
           		 stat=true;
           		if( strcmp(typeofvar(SymbolTemp,(yyvsp[0].addr)),"none")==0){
           		    printf("error:not declared %s\n",(yyvsp[0].addr));
           		}
           		else{
           		   printf("error:conflicting types in the above expression \n");
           		}
           		
            }
             (yyval.eval) = (struct s*)malloc(sizeof(struct s));
             strcpy((yyval.eval)->code, "t");
             strcat((yyval.eval)->code, itoa(tempv)); 
             strcat((yyval.eval)->code, " = ");
             strcat((yyval.eval)->code, (yyvsp[0].addr));
             strcat((yyval.eval)->code, " + 1\n");
             strcat((yyval.eval)->code, (yyvsp[0].addr));
             strcat((yyval.eval)->code, " = t");
             strcat((yyval.eval)->code, itoa(tempv));
             strcat((yyval.eval)->code, "\n");
             (yyval.eval)->lexval = tempv;
             tempv++;
         }
#line 2166 "y.tab.c"
    break;

  case 33:
#line 634 "prob2.y"
                 { if(strcmp(typeofvar(SymbolTemp,(yyvsp[0].addr)),type)!=0){
           		 stat=true;
           		if( strcmp(typeofvar(SymbolTemp,(yyvsp[0].addr)),"none")==0){
           		    printf("error:not declared %s\n",(yyvsp[0].addr));
           		}
           		else{
           		   printf("error:conflicting types in the above expression \n");
           		}
           		
            }
            (yyval.eval) = (struct s*)malloc(sizeof(struct s));
             strcpy((yyval.eval)->code, "t");
             strcat((yyval.eval)->code, itoa(tempv)); 
             strcat((yyval.eval)->code, " = ");
             strcat((yyval.eval)->code, (yyvsp[0].addr));
             strcat((yyval.eval)->code, " - 1\n");
             strcat((yyval.eval)->code, (yyvsp[0].addr));
             strcat((yyval.eval)->code, " = t");
             strcat((yyval.eval)->code, itoa(tempv));
             strcat((yyval.eval)->code, "\n");
             (yyval.eval)->lexval = tempv;
             tempv++;
          }
#line 2194 "y.tab.c"
    break;

  case 34:
#line 657 "prob2.y"
                             { if(strcmp((yyvsp[-3].TypeNode)->type,type)!=0){
           		    stat=true;
           		   
           		    printf("error:mismatching types %s\n",(yyvsp[0].addr));
           		 }
           		else if( strcmp(typeofvar(SymbolTemp,(yyvsp[0].addr)),"none")==0){
           		    stat=true;
           		    printf("error:not declared %s\n",(yyvsp[0].addr));
           		}
           		
           		
            
             (yyval.eval) = (struct s*)malloc(sizeof(struct s));
             strcpy((yyval.eval)->code, "t");
             strcat((yyval.eval)->code, itoa(tempv)); 
             strcat((yyval.eval)->code, " = ");
             strcat((yyval.eval)->code, "(");
             strcat((yyval.eval)->code, (yyvsp[-3].TypeNode)->type);
             strcat((yyval.eval)->code, ")");
             strcat((yyval.eval)->code, (yyvsp[0].addr));
             strcat((yyval.eval)->code, " + 1\n");
             strcat((yyval.eval)->code, (yyvsp[0].addr));
             strcat((yyval.eval)->code, " = t");
             strcat((yyval.eval)->code, itoa(tempv));
             strcat((yyval.eval)->code, "\n");
             (yyval.eval)->lexval = tempv;
             tempv++;
         }
#line 2227 "y.tab.c"
    break;

  case 35:
#line 685 "prob2.y"
                              {  if(strcmp((yyvsp[-3].TypeNode)->type,type)!=0){
           		    stat=true;
           		    printf("error:mismatching types %s\n",(yyvsp[0].addr));
           		 }
           		else if( strcmp(typeofvar(SymbolTemp,(yyvsp[0].addr)),"none")==0){
           		    stat=true;
           		    printf("error:not declared %s\n",(yyvsp[0].addr));
           		}
            
            (yyval.eval) = (struct s*)malloc(sizeof(struct s));
             (yyval.eval) = (struct s*)malloc(sizeof(struct s));
             strcpy((yyval.eval)->code, "t");
             strcat((yyval.eval)->code, itoa(tempv)); 
             strcat((yyval.eval)->code, " = ");
             strcat((yyval.eval)->code, "(");
             strcat((yyval.eval)->code, (yyvsp[-3].TypeNode)->type);
             strcat((yyval.eval)->code, ")");
             strcat((yyval.eval)->code, (yyvsp[0].addr));
             strcat((yyval.eval)->code, " - 1\n");
             strcat((yyval.eval)->code, (yyvsp[0].addr));
             strcat((yyval.eval)->code, " = t");
             strcat((yyval.eval)->code, itoa(tempv));
             strcat((yyval.eval)->code, "\n");
             (yyval.eval)->lexval = tempv;
             tempv++;
         }
#line 2258 "y.tab.c"
    break;

  case 36:
#line 712 "prob2.y"
             {(yyval.TypeNode)= (struct TypeNode*)malloc(sizeof(struct TypeNode));
            strcpy(type,"char");
            strcpy((yyval.TypeNode)->type,"char");
            size=1;
            (yyval.TypeNode)->size=1;
           
          }
#line 2270 "y.tab.c"
    break;

  case 37:
#line 719 "prob2.y"
             {(yyval.TypeNode)= (struct TypeNode*)malloc(sizeof(struct TypeNode));
            strcpy(type,"integer");
            strcpy((yyval.TypeNode)->type,"integer");
            size=4;
            (yyval.TypeNode)->size=4;
           
            }
#line 2282 "y.tab.c"
    break;

  case 38:
#line 726 "prob2.y"
              {(yyval.TypeNode)= (struct TypeNode*)malloc(sizeof(struct TypeNode));
            strcpy(type,"long");
            strcpy((yyval.TypeNode)->type,"long");
            size=8;
            (yyval.TypeNode)->size=8;
           
            }
#line 2294 "y.tab.c"
    break;

  case 39:
#line 733 "prob2.y"
               {(yyval.TypeNode)= (struct TypeNode*)malloc(sizeof(struct TypeNode));
            strcpy(type,"float");
            strcpy((yyval.TypeNode)->type,"float");
            size=4;
            (yyval.TypeNode)->size=4;
        
            }
#line 2306 "y.tab.c"
    break;

  case 40:
#line 741 "prob2.y"
                 {(yyval.TypeNode)= (struct TypeNode*)malloc(sizeof(struct TypeNode));
            strcpy(type,"double");
            strcpy((yyval.TypeNode)->type,"double");
            size=8;
            (yyval.TypeNode)->size=8;
           
            }
#line 2318 "y.tab.c"
    break;

  case 41:
#line 748 "prob2.y"
                 {(yyval.TypeNode)= (struct TypeNode*)malloc(sizeof(struct TypeNode));
            strcpy(type,"string");
            strcpy((yyval.TypeNode)->type,"string");
            size=50;
            (yyval.TypeNode)->size=50;
           
            }
#line 2330 "y.tab.c"
    break;

  case 42:
#line 758 "prob2.y"
                 {printf("\n");push(&st,0);struct SymbolTable* temp=(struct SymbolTable*)malloc(sizeof(struct SymbolTable));Construct(temp,SymbolTemp);SymbolTemp=temp;}
#line 2336 "y.tab.c"
    break;

  case 43:
#line 758 "prob2.y"
                                                                                                                                                                                                         {  printf("\n");pop(&st);SymbolTemp=SymbolTemp->prev;(yyval.eval) = (struct s*)malloc(sizeof(struct s));
                               strcpy((yyval.eval)->code, (yyvsp[-1].eval)->code);
                              }
#line 2344 "y.tab.c"
    break;

  case 44:
#line 763 "prob2.y"
          {
		
       	 if(verify(SymbolTemp,(yyvsp[0].addr),type)==0){
           		 stat=true;
           		 printf("error:conflicting types for %s\n",(yyvsp[0].addr));
        	 }
        	 else if(verify(SymbolTemp,(yyvsp[0].addr),type)==-1){
            		stat=true;
            		printf("error:redeclaration of %s\n",(yyvsp[0].addr));
        	 }
                 else{
		
			add_name(SymbolTemp,top(st),(yyvsp[0].addr),type);
			int x=top(st);
			pop(&st);
			x = x+size;
			push(&st,x);
		 }
		              
		 

	}
#line 2371 "y.tab.c"
    break;

  case 46:
#line 784 "prob2.y"
                       {
		
       	 if(verify(SymbolTemp,(yyvsp[0].addr),type)==0){
           		 stat=true;           		 
           		 printf("error:conflicting types for %s\n",(yyvsp[0].addr));
        	 }
        	 else if(verify(SymbolTemp,(yyvsp[0].addr),type)==-1){
            		stat=true;
            		printf("error:redeclaration of %s\n",(yyvsp[0].addr));
        	 }
                 else{
		
			add_name(SymbolTemp,top(st),(yyvsp[0].addr),type);
			int x=top(st);
			pop(&st);
			x = x+size;
			push(&st,x);
		 }
		  (yyval.eval) = (struct s*)malloc(sizeof(struct s));
	                   strcpy((yyval.eval)->code, "t");
                          strcat((yyval.eval)->code, itoa(tempv));
		           strcat((yyval.eval)->code, " = ");
			   strcat((yyval.eval)->code,(yyvsp[0].addr));
			   strcat((yyval.eval)->code, "\n");
			   (yyval.eval)->lexval = tempv;
		          tempv++; 
		 
		  
	}
#line 2405 "y.tab.c"
    break;

  case 47:
#line 813 "prob2.y"
                         {
		 if(verify(SymbolTemp,(yyvsp[-3].addr),type)==0){
           		 stat=true;           		 
           		 printf("error:conflicting types for %s\n",(yyvsp[-3].addr));
        	 }
	         else if(verify(SymbolTemp,(yyvsp[-3].addr),type)==-1){
            		stat=true;
            		printf("error:redeclaration of %s\n",(yyvsp[-3].addr));
        	 }
                 else{
		
			strcat(type," ");
   		        strcat (type,"array");
    		        add_name(SymbolTemp,top(st),(yyvsp[-3].addr),type);  
    		        int x=top(st);
                        pop(&st);
		        x = x+size*atoi((yyvsp[-1].addr));
		        push(&st,x); 
		 }
		  (yyval.eval) = (struct s*)malloc(sizeof(struct s));
	                   strcpy((yyval.eval)->code, "t");
                          strcat((yyval.eval)->code, itoa(tempv));
		           strcat((yyval.eval)->code, " = ");
		           //int s=(atoi(NUM))*size;
		           
			   strcat((yyval.eval)->code,(yyvsp[-1].addr));
			   strcat((yyval.eval)->code,"*");
			   strcat((yyval.eval)->code,itoa(size));
			   tempv++; 
			   strcat((yyval.eval)->code, "\n");
			   strcat((yyval.eval)->code, "t");
                          strcat((yyval.eval)->code, itoa(tempv));
		           strcat((yyval.eval)->code, " = ");
		           strcat((yyval.eval)->code, (yyvsp[-3].addr));
		           strcat((yyval.eval)->code, "[");
		           strcat((yyval.eval)->code, "t");
                          strcat((yyval.eval)->code, itoa(tempv-1));
		            strcat((yyval.eval)->code, "]");
			   strcat((yyval.eval)->code, "\n");
			   (yyval.eval)->lexval = tempv;
		          tempv++; 

		 
        }
#line 2454 "y.tab.c"
    break;

  case 48:
#line 857 "prob2.y"
              {
		 
       	 if(verify(SymbolTemp,(yyvsp[0].addr),type)==0){
           		 stat=true;           		 
           		 printf("error:conflicting types for %s\n",(yyvsp[0].addr));
        	 }
        	 else if(verify(SymbolTemp,(yyvsp[0].addr),type)==-1){
            		stat=true;
            		printf("error:redeclaration of %s\n",(yyvsp[0].addr));
        	 }
                 else{
		
			add_name(SymbolTemp,top(st),(yyvsp[0].addr),type);
			int x=top(st);
			pop(&st);
			x = x+size;
			push(&st,x);
		 }
	}
#line 2478 "y.tab.c"
    break;

  case 49:
#line 875 "prob2.y"
                 {
	                  
	                  (yyval.eval) = (struct s*)malloc(sizeof(struct s));
	                  strcpy((yyval.eval)->code,(yyvsp[0].eval)->code);
	                  
	                  strcat((yyval.eval)->code,(yyvsp[-3].addr));
	                  strcat((yyval.eval)->code, " = ");
	                  strcat((yyval.eval)->code, "t");
                          strcat((yyval.eval)->code, itoa((yyvsp[0].eval)->lexval));
			   strcat((yyval.eval)->code, "\n");
		           (yyval.eval)->lexval = (yyvsp[0].eval)->lexval;
		           //printf("%s",$$->code);
		           
		                  
	}
#line 2498 "y.tab.c"
    break;

  case 50:
#line 894 "prob2.y"
                   {
			(yyval.eval) = (struct s*)malloc(sizeof(struct s));
			strcpy((yyval.eval)->code, (yyvsp[-2].addr));
			strcat((yyval.eval)->code, (yyvsp[-1].addr));
			strcat((yyval.eval)->code,(yyvsp[0].addr));
			(yyval.eval)->left=NULL;
			(yyval.eval)->right=NULL;
			//printf("compared \n");
			if(strcmp(typeofvar(SymbolTemp,(yyvsp[-2].addr)),typeofvar(SymbolTemp,(yyvsp[0].addr)))!=0){
           		    printf("error:both %s and %s are of two different data types\n",(yyvsp[-2].addr),(yyvsp[0].addr));
           		    stat=true;
           		}
           		else if( strcmp(typeofvar(SymbolTemp,(yyvsp[-2].addr)),"none")==0||strcmp(typeofvar(SymbolTemp,(yyvsp[0].addr)),"none")==0){
           		    printf("error:not declared \n");
           		    stat=true;
           		}
           		
		      }
#line 2521 "y.tab.c"
    break;

  case 51:
#line 912 "prob2.y"
                       {
			(yyval.eval) = (struct s*)malloc(sizeof(struct s));
			strcpy((yyval.eval)->code, (yyvsp[-2].addr));
			strcat((yyval.eval)->code, (yyvsp[-1].addr));
			strcat((yyval.eval)->code,(yyvsp[0].addr));
			//printf("%s",$$->code);
			(yyval.eval)->left=NULL;
			(yyval.eval)->right=NULL;
			if( strcmp(typeofvar(SymbolTemp,(yyvsp[0].addr)),"none")==0){
           		    printf("error:not declared %s\n",(yyvsp[0].addr));
           		    stat=true;
           		}
			}
#line 2539 "y.tab.c"
    break;

  case 52:
#line 925 "prob2.y"
                       {
			(yyval.eval) = (struct s*)malloc(sizeof(struct s));
			strcpy((yyval.eval)->code, (yyvsp[-2].addr));
			strcat((yyval.eval)->code, (yyvsp[-1].addr));
			strcat((yyval.eval)->code,(yyvsp[0].addr));
			(yyval.eval)->left=NULL;
			(yyval.eval)->right=NULL;
			if( strcmp(typeofvar(SymbolTemp,(yyvsp[-2].addr)),"none")==0){
           		    printf("error:not declared %s\n",(yyvsp[-2].addr));
           		    stat=true;
           		}
			}
#line 2556 "y.tab.c"
    break;

  case 53:
#line 937 "prob2.y"
                        {
			(yyval.eval) = (struct s*)malloc(sizeof(struct s));
			strcpy((yyval.eval)->code, (yyvsp[-2].addr));
			strcat((yyval.eval)->code, (yyvsp[-1].addr));
			strcat((yyval.eval)->code,(yyvsp[0].addr));
			(yyval.eval)->left=NULL;
			(yyval.eval)->right=NULL;
			}
#line 2569 "y.tab.c"
    break;


#line 2573 "y.tab.c"

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
#line 948 "prob2.y"

int yyerror(char * s){

    printf("Not Accepted  %s\n",s);

    return 0;
}



 
void add_name(struct SymbolTable* symbol,int addr , char lexeme [], char type[]){

     if(symbol->head == NULL){
       struct new_Entry* temp=(struct new_Entry*)malloc(sizeof(struct new_Entry));
       if(global==NULL&&head==NULL){
          global= temp;
          head=global;
       }
       else{
          global->next=temp;
          global=temp;
          global->next=NULL;
       }
       
       symbol->head = global;
       symbol->head->addr = addr;
       strcpy(symbol->head->lexeme,lexeme);
       strcpy(symbol->head->type,type);
       symbol->tail=symbol->head;
       symbol->head->next=NULL;
    }
    else{
        struct new_Entry*  Entry = (struct new_Entry*)malloc(sizeof(struct new_Entry));
        Entry->addr = addr;
        strcpy(Entry->lexeme,lexeme);
        strcpy(Entry->type,type);
        global->next=Entry;
        global=Entry;
        global->next=NULL;
        symbol->tail->next = Entry;
        symbol->tail = Entry;
        symbol->tail->next=NULL;
    }
}

void Construct(struct SymbolTable* symbol,struct SymbolTable* prev){
    symbol->prev=prev;
    symbol->head=NULL;
    symbol->tail=NULL;
}

char* itoa(int num){
    int len, i = 0, q = 0, temp = num;
    //printf("%d",num);
    char* str = (char*) malloc(sizeof(char)*10);
    if(num == 0){
        str[0] = '0';
        return str;
    }
    while(temp > 0){
        int rem = temp%10;
        q = 10*q + rem;
        temp /= 10;
    }
    temp = q;
    while(temp > 0){
        int rem = temp%10;
        str[i] = '0' + rem;
        temp /= 10;
        i++;
    }
    return str;
}

int prec(char* type){
   //printf("%s\n",type);
   if(strcmp(type,"double")==0||strcmp(type,"float")==0){
      return 2;
   }
   if(strcmp(type,"integer")==0||strcmp(type,"long")==0){
   //printf("%s\n",type);
      return 1;
   }
   return 0;
}

int minimized(char* str){
   
   for(int i=0;i<strlen(str);i++){
    
    if(str[i]=='.'){
    
       return i;
    }
    
   }
   return -1;
}

char* maximized(char* str){
   strcat(str,".00");
   return str;
}

char* traversal(struct s* node){
        
        char *cod;
        strcpy(cod,"1");
	if(node==NULL){
	     return "";
	}
	if(node->left==NULL && node->right==NULL){
	         strcpy(cod,"if ");
	         strcat(cod,node->code);
	         strcat(cod," goto label");
	         strcat(cod,itoa(node->True));
	         strcat(cod,"\n");
	         strcat(cod,"goto label");
	         strcat(cod,itoa(node->False));
	         strcat(cod,"\n");

	}
	else if(strcmp(node->op,"!")==0){
	         strcpy(cod,"if ");
	         strcat(cod,node->code);
	         strcat(cod," goto label");
	         strcat(cod,itoa(node->False));
	         strcat(cod,"\n");
	         strcat(cod,"goto label");
	         strcat(cod,itoa(node->True));
	         strcat(cod,"\n");
	}
	
	else if(strcmp(node->op,"||")==0){
		 strcpy(cod,"if ");
	         strcat(cod,node->left->code);
	         strcat(cod," goto label");
	         strcat(cod,itoa(node->True));
	         strcat(cod,"\n");
	         strcat(cod,"goto label");
	         strcat(cod,itoa(labelv));
	         strcat(cod,"label");
	         strcat("%d:\n",labelv);
	         strcat(cod,"if ");
	         strcat(cod,node->right->code);
	         strcat(cod," goto label");
	         strcat(cod,itoa(node->True));
	         strcat(cod,"\n");
	         strcat(cod,"goto label");
	         strcat(cod,itoa(node->False));
	         labelv++;
	         strcpy(cod,"\n");
	}
	else if(strcmp(node->op,"&&")==0){
	         strcpy(cod,"if ");
	         strcat(cod,node->left->code);
	         strcat(cod," goto label");
	         strcat(cod,itoa(labelv));
	         strcat(cod,"\n");
	         strcat(cod,"goto label");
	         strcat(cod,itoa(node->False));
	         strcat(cod,"label");
	         strcat("%d:\n",labelv);
	         strcpy(cod,"if ");
	         strcat(cod,node->right->code);
	         strcat(cod," goto label");
	         strcat(cod,itoa(node->True));
	         strcat(cod,"\n");
	         strcat(cod,"goto label");
	         strcat(cod,itoa(node->False));
	         labelv++;
	         strcat(cod,"\n");
	}
	return cod;
}


int verify(struct SymbolTable* symbol,char lexeme [ ], char type[]){
    struct new_Entry* h=symbol->head;
    for(struct new_Entry* i=h;i!=NULL;i=i->next){
        if(strcmp(h->lexeme,lexeme)==0){
            if(strcmp(h->type,type)==0){
                return -1;
            }
            return 0;
        }
    }
    return 1;
 }
char* typeofvar(struct SymbolTable* symbol,char lexeme [ ]){
    struct new_Entry* h=symbol->head;
    for(struct new_Entry* i=h;i!=NULL;i=i->next){
    	//printf("%s\n",i->lexeme);
        if(strcmp(i->lexeme,lexeme)==0){
            return i->type;
        }
    }
    return "none";
 }
 
 
 char* mini(char* str,int i){
    char *token;
    char s[2]=".";
   /* get the first token */
   token = strtok(str, s);
   return token;
 }

void Symbol_Table(){
    struct SymbolTable* symbol=SymbolHead;
    while(symbol!=NULL){
	    struct new_Entry* temp  = symbol->head;
	    while(temp !=NULL){
		printf("%#06x %s %s\n",temp ->addr,temp ->lexeme,temp ->type);
		temp =temp ->next;
	    } 
	    printf("\n");
	    symbol=symbol->prev;
   }
}



int main(int argc , char* argv[]){

    if(argc>1){
        FILE *fp = fopen(argv[1],"r");

        if(fp)yyin = fp;
    }

    yyparse();
    return 0;
}
