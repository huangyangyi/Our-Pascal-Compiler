/* A Bison parser, made by GNU Bison 3.5.3.  */

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
#define YYBISON_VERSION "3.5.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser/pascal.y"

#define MAX_LITERAL_LEN 256
#define SET_LOCATION(dest) (dest)->set_location(yylloc.first_line, yylloc.first_column)
#include "ast/ast.h"


#line 77 "pascal.y.h"

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
    TYPE_INT = 258,
    TYPE_INT_8 = 259,
    TYPE_INT_16 = 260,
    TYPE_INT_32 = 261,
    TYPE_INT_64 = 262,
    TYPE_UNSIGNED_INT_8 = 263,
    TYPE_UNSIGNED_INT_16 = 264,
    TYPE_UNSIGNED_INT_32 = 265,
    TYPE_UNSIGNED_INT_64 = 266,
    TYPE_BOOLEAN = 267,
    TYPE_FLOAT = 268,
    TYPE_FLOAT_16 = 269,
    TYPE_FLOAT_32 = 270,
    TYPE_CHAR = 271,
    TYPE_STRING = 272,
    LITERAL_INT = 273,
    LITERAL_FLOAT = 274,
    LITERAL_CHAR = 275,
    LITERAL_ESC_CHAR = 276,
    LITERAL_STR = 277,
    LITERAL_TRUE = 278,
    LITERAL_FALSE = 279,
    IDENTIFIER = 280,
    SYM_ADD = 281,
    SYM_SUB = 282,
    SYM_MUL = 283,
    SYM_DIV = 284,
    SYM_EQ = 285,
    SYM_LT = 286,
    SYM_GT = 287,
    SYM_LBRAC = 288,
    SYM_RBRAC = 289,
    SYM_PERIOD = 290,
    SYM_COMMA = 291,
    SYM_COLON = 292,
    SYM_SEMICOLON = 293,
    SYM_AT = 294,
    SYM_CARET = 295,
    SYM_LPAREN = 296,
    SYM_RPAREN = 297,
    SYM_NE = 298,
    SYM_LE = 299,
    SYM_GE = 300,
    SYM_ASSIGN = 301,
    SYM_RANGE = 302,
    COMMENT = 303,
    KWD_AND = 304,
    KWD_ARRAY = 305,
    KWD_ASM = 306,
    KWD_BEGIN = 307,
    KWD_CASE = 308,
    KWD_CONST = 309,
    KWD_CONSTRUCTOR = 310,
    KWD_DESTRUCTOR = 311,
    KWD_DIV = 312,
    KWD_DO = 313,
    KWD_DOWNTO = 314,
    KWD_ELSE = 315,
    KWD_END = 316,
    KWD_FILE = 317,
    KWD_FOR = 318,
    KWD_FUNCTION = 319,
    KWD_GOTO = 320,
    KWD_IF = 321,
    KWD_IMPLEMENTATION = 322,
    KWD_IN = 323,
    KWD_INHERITED = 324,
    KWD_INLINE = 325,
    KWD_INTERFACE = 326,
    KWD_LABEL = 327,
    KWD_MOD = 328,
    KWD_NIL = 329,
    KWD_NOT = 330,
    KWD_OBJECT = 331,
    KWD_OF = 332,
    KWD_OPERATOR = 333,
    KWD_OR = 334,
    KWD_PACKED = 335,
    KWD_PROCEDURE = 336,
    KWD_PROGRAM = 337,
    KWD_RECORD = 338,
    KWD_REINTRODUCE = 339,
    KWD_REPEAT = 340,
    KWD_SELF = 341,
    KWD_SET = 342,
    KWD_SHL = 343,
    KWD_SHR = 344,
    KWD_THEN = 345,
    KWD_TO = 346,
    KWD_TYPE = 347,
    KWD_UNIT = 348,
    KWD_UNTIL = 349,
    KWD_USES = 350,
    KWD_VAR = 351,
    KWD_WHILE = 352,
    KWD_WITH = 353,
    KWD_XOR = 354,
    SIGN = 355
  };
#endif
/* Tokens.  */
#define TYPE_INT 258
#define TYPE_INT_8 259
#define TYPE_INT_16 260
#define TYPE_INT_32 261
#define TYPE_INT_64 262
#define TYPE_UNSIGNED_INT_8 263
#define TYPE_UNSIGNED_INT_16 264
#define TYPE_UNSIGNED_INT_32 265
#define TYPE_UNSIGNED_INT_64 266
#define TYPE_BOOLEAN 267
#define TYPE_FLOAT 268
#define TYPE_FLOAT_16 269
#define TYPE_FLOAT_32 270
#define TYPE_CHAR 271
#define TYPE_STRING 272
#define LITERAL_INT 273
#define LITERAL_FLOAT 274
#define LITERAL_CHAR 275
#define LITERAL_ESC_CHAR 276
#define LITERAL_STR 277
#define LITERAL_TRUE 278
#define LITERAL_FALSE 279
#define IDENTIFIER 280
#define SYM_ADD 281
#define SYM_SUB 282
#define SYM_MUL 283
#define SYM_DIV 284
#define SYM_EQ 285
#define SYM_LT 286
#define SYM_GT 287
#define SYM_LBRAC 288
#define SYM_RBRAC 289
#define SYM_PERIOD 290
#define SYM_COMMA 291
#define SYM_COLON 292
#define SYM_SEMICOLON 293
#define SYM_AT 294
#define SYM_CARET 295
#define SYM_LPAREN 296
#define SYM_RPAREN 297
#define SYM_NE 298
#define SYM_LE 299
#define SYM_GE 300
#define SYM_ASSIGN 301
#define SYM_RANGE 302
#define COMMENT 303
#define KWD_AND 304
#define KWD_ARRAY 305
#define KWD_ASM 306
#define KWD_BEGIN 307
#define KWD_CASE 308
#define KWD_CONST 309
#define KWD_CONSTRUCTOR 310
#define KWD_DESTRUCTOR 311
#define KWD_DIV 312
#define KWD_DO 313
#define KWD_DOWNTO 314
#define KWD_ELSE 315
#define KWD_END 316
#define KWD_FILE 317
#define KWD_FOR 318
#define KWD_FUNCTION 319
#define KWD_GOTO 320
#define KWD_IF 321
#define KWD_IMPLEMENTATION 322
#define KWD_IN 323
#define KWD_INHERITED 324
#define KWD_INLINE 325
#define KWD_INTERFACE 326
#define KWD_LABEL 327
#define KWD_MOD 328
#define KWD_NIL 329
#define KWD_NOT 330
#define KWD_OBJECT 331
#define KWD_OF 332
#define KWD_OPERATOR 333
#define KWD_OR 334
#define KWD_PACKED 335
#define KWD_PROCEDURE 336
#define KWD_PROGRAM 337
#define KWD_RECORD 338
#define KWD_REINTRODUCE 339
#define KWD_REPEAT 340
#define KWD_SELF 341
#define KWD_SET 342
#define KWD_SHL 343
#define KWD_SHR 344
#define KWD_THEN 345
#define KWD_TO 346
#define KWD_TYPE 347
#define KWD_UNIT 348
#define KWD_UNTIL 349
#define KWD_USES 350
#define KWD_VAR 351
#define KWD_WHILE 352
#define KWD_WITH 353
#define KWD_XOR 354
#define SIGN 355

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "parser/pascal.y"

    int token_type;
    char* str;
    ASTProgram* ast_program;
    ASTProgramHead* ast_program_head;
    ASTRoutine* ast_routine;
    ASTRoutineHead* ast_routine_head;
    ASTRoutineBody* ast_routine_body;
    ASTConstPart* ast_const_part;
    ASTConstExprList* ast_const_expr_list;
    ASTConstExpr* ast_const_expr;
    ASTConstValue* ast_const_value;
    ASTTypePart* ast_type_part;
    ASTTypeDeclList* ast_type_decl_list;
    ASTTypeDefinition* ast_type_definition;
    ASTTypeDecl* ast_type_decl;
    ASTType* ast_type;
    ASTSimpleTypeDecl* ast_simple_type_decl;
    ASTArrayTypeDecl* ast_array_type_decl;
    ASTRecordTypeDecl* ast_record_type_decl;    
    ASTNameList* ast_name_list;
    ASTVarParaList* ast_var_para_list;
    ASTValParaList* ast_val_para_list;
    ASTFieldDeclList* ast_field_decl_list;
    ASTFieldDecl* ast_field_decl;
    ASTVarPart* ast_var_part;
    ASTVarDeclList* ast_var_decl_list;
    ASTVarDecl* ast_var_decl;
    ASTRoutinePart* ast_routine_part;
    ASTFunctionDecl* ast_function_decl;
    ASTFunctionHead* ast_function_head;
    ASTProcedureDecl* ast_procedure_decl;
    ASTProcedureHead* ast_procedure_head;
    ASTParaDeclList* ast_para_decl_list;
    ASTParaTypeList* ast_para_type_list;
    ASTStmtList* ast_stmt_list;
    ASTStmt* ast_stmt;
    ASTNonLabelStmt* ast_non_label_stmt;
    ASTElseClause* ast_else_clause;
    ASTAssignStmt* ast_assign_stmt;
    ASTProcStmt* ast_proc_stmt;
    ASTIfStmt* ast_if_stmt;
    ASTRepeatStmt* ast_repeat_stmt;
    ASTWhileStmt* ast_while_stmt;
    ASTForStmt* ast_for_stmt;
    ASTForStmt::ForDir ast_for_stmt_dir;
    ASTCaseStmt* ast_case_stmt;
    ASTCaseExpr* ast_case_expr;
    ASTCaseExprList* ast_case_expr_list;
    ASTGotoStmt* ast_goto_stmt;
    ASTExpressionList* ast_expression_list;
    ASTExpr* ast_expr;

#line 380 "pascal.y.h"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   329

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  243

#define YYUNDEFTOK  2
#define YYMAXUTOK   355


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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   143,   143,   151,   158,   169,   177,   185,   189,   195,
     200,   208,   216,   220,   224,   228,   232,   237,   244,   248,
     255,   260,   267,   274,   278,   282,   289,   293,   297,   301,
     308,   312,   315,   318,   321,   324,   327,   333,   340,   347,
     352,   359,   366,   371,   378,   382,   388,   393,   400,   407,
     412,   417,   421,   425,   431,   440,   447,   456,   463,   467,
     473,   478,   485,   489,   496,   503,   510,   517,   525,   531,
     535,   542,   545,   548,   551,   554,   557,   560,   563,   566,
     572,   577,   582,   592,   595,   603,   610,   614,   620,   627,
     634,   641,   644,   650,   657,   662,   670,   674,   681,   689,
     694,   701,   705,   709,   713,   717,   721,   725,   732,   736,
     740,   744,   750,   754,   758,   762,   766,   772,   776,   780,
     784,   788,   792,   796
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE_INT", "TYPE_INT_8", "TYPE_INT_16",
  "TYPE_INT_32", "TYPE_INT_64", "TYPE_UNSIGNED_INT_8",
  "TYPE_UNSIGNED_INT_16", "TYPE_UNSIGNED_INT_32", "TYPE_UNSIGNED_INT_64",
  "TYPE_BOOLEAN", "TYPE_FLOAT", "TYPE_FLOAT_16", "TYPE_FLOAT_32",
  "TYPE_CHAR", "TYPE_STRING", "LITERAL_INT", "LITERAL_FLOAT",
  "LITERAL_CHAR", "LITERAL_ESC_CHAR", "LITERAL_STR", "LITERAL_TRUE",
  "LITERAL_FALSE", "IDENTIFIER", "SYM_ADD", "SYM_SUB", "SYM_MUL",
  "SYM_DIV", "SYM_EQ", "SYM_LT", "SYM_GT", "SYM_LBRAC", "SYM_RBRAC",
  "SYM_PERIOD", "SYM_COMMA", "SYM_COLON", "SYM_SEMICOLON", "SYM_AT",
  "SYM_CARET", "SYM_LPAREN", "SYM_RPAREN", "SYM_NE", "SYM_LE", "SYM_GE",
  "SYM_ASSIGN", "SYM_RANGE", "COMMENT", "KWD_AND", "KWD_ARRAY", "KWD_ASM",
  "KWD_BEGIN", "KWD_CASE", "KWD_CONST", "KWD_CONSTRUCTOR",
  "KWD_DESTRUCTOR", "KWD_DIV", "KWD_DO", "KWD_DOWNTO", "KWD_ELSE",
  "KWD_END", "KWD_FILE", "KWD_FOR", "KWD_FUNCTION", "KWD_GOTO", "KWD_IF",
  "KWD_IMPLEMENTATION", "KWD_IN", "KWD_INHERITED", "KWD_INLINE",
  "KWD_INTERFACE", "KWD_LABEL", "KWD_MOD", "KWD_NIL", "KWD_NOT",
  "KWD_OBJECT", "KWD_OF", "KWD_OPERATOR", "KWD_OR", "KWD_PACKED",
  "KWD_PROCEDURE", "KWD_PROGRAM", "KWD_RECORD", "KWD_REINTRODUCE",
  "KWD_REPEAT", "KWD_SELF", "KWD_SET", "KWD_SHL", "KWD_SHR", "KWD_THEN",
  "KWD_TO", "KWD_TYPE", "KWD_UNIT", "KWD_UNTIL", "KWD_USES", "KWD_VAR",
  "KWD_WHILE", "KWD_WITH", "KWD_XOR", "SIGN", "$accept", "program",
  "program_head", "routine", "routine_head", "routine_body", "const_part",
  "const_expr_list", "const_expr", "const_value", "type_part",
  "type_decl_list", "type_definition", "type_decl", "TYPE",
  "simple_type_decl", "array_type_decl", "record_type_decl",
  "field_decl_list", "field_decl", "name_list", "var_part",
  "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "var_para_list", "val_para_list",
  "compound_stmt", "stmt_list", "stmt", "non_label_stmt", "assign_stmt",
  "proc_stmt", "if_stmt", "else_clause", "repeat_stmt", "while_stmt",
  "for_stmt", "direction", "case_stmt", "case_expr_list", "case_expr",
  "goto_stmt", "expression_list", "expression", "expr", "term", "factor", YY_NULLPTR
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
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355
};
# endif

#define YYPACT_NINF (-153)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -68,    -6,    28,    -7,    20,  -153,    41,    54,    44,    12,
    -153,    77,    41,  -153,  -153,  -153,  -153,  -153,    81,    15,
     173,  -153,    17,    85,    81,  -153,    95,   -41,  -153,  -153,
    -153,  -153,  -153,  -153,   -17,   173,   173,   173,  -153,   227,
     -14,    43,  -153,    87,    13,   173,  -153,   100,   109,   173,
    -153,   173,  -153,    92,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,    14,  -153,  -153,     8,    95,  -153,   110,
     113,   -41,  -153,   106,  -153,   115,   123,   173,  -153,   231,
    -153,   173,   173,   173,  -153,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   122,   173,   131,   173,   173,
     136,   118,  -153,   -23,    76,   208,  -153,  -153,  -153,  -153,
    -153,   125,   298,    95,   143,    95,   135,   140,  -153,  -153,
    -153,  -153,   158,    14,  -153,   148,   148,  -153,  -153,    -7,
      -7,  -153,     7,   252,  -153,   -14,   -14,   -14,   -14,   -14,
     -14,    43,    43,    43,  -153,  -153,  -153,  -153,  -153,   247,
     138,    26,   252,   290,   173,    80,   173,    80,   165,   152,
      48,   209,   -10,  -153,    49,   298,  -153,  -153,   163,   -15,
     166,  -153,   164,   177,   173,  -153,   170,   173,  -153,   180,
     181,   186,  -153,    78,   160,   252,  -153,  -153,   280,  -153,
     189,  -153,  -153,    14,  -153,  -153,    95,   188,    35,  -153,
     193,   198,   209,  -153,  -153,   252,   173,   252,    80,    80,
    -153,  -153,  -153,  -153,   173,    80,  -153,   298,  -153,   149,
     199,   188,   -15,  -153,   209,   209,  -153,   252,   206,   207,
     211,  -153,  -153,    14,  -153,  -153,  -153,  -153,  -153,  -153,
      80,  -153,  -153
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     8,     0,     1,     0,     0,     0,    19,
       3,     0,     7,    10,     2,    68,     4,     6,     0,    45,
       0,     9,     0,     0,    18,    21,     0,    53,    12,    13,
      14,    15,    17,    16,   117,     0,     0,     0,   119,     0,
     107,   111,   116,     0,    83,     0,    66,     0,     0,     0,
      68,     0,    73,     0,    70,    71,    72,    74,    75,    76,
      77,    78,    79,     0,    20,    43,     0,    44,    47,     0,
       0,     5,    51,     0,    52,     0,     0,     0,   122,     0,
     121,     0,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,     0,     0,     0,    67,    28,    26,    29,
      27,    31,     0,     0,     0,     0,     0,     0,    30,    23,
      24,    25,     0,     0,    46,    59,    59,    49,    50,     8,
       8,   123,     0,   100,   120,   105,   104,   102,   106,   103,
     101,   108,   109,   110,   112,   115,   113,   114,    69,     0,
       0,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    40,     0,     0,    22,    42,     0,     0,
       0,    57,     0,     0,     0,   118,     0,     0,    84,     0,
       0,     0,    95,     0,    87,    88,    89,    36,     0,    32,
       0,    38,    39,     0,    33,    48,     0,    65,     0,    61,
       0,     0,     0,    54,    56,    99,     0,    82,     0,     0,
      93,    94,    92,    91,     0,     0,    85,     0,    34,     0,
       0,    64,     0,    58,     0,     0,    55,    81,     0,     0,
       0,    86,    35,     0,    41,    60,    62,    63,    97,    96,
       0,    37,    90
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,  -153,   -12,  -153,  -153,  -153,  -153,   234,   -62,
    -153,  -153,   225,  -121,  -153,  -150,  -153,  -153,  -153,    98,
    -109,  -153,  -153,   197,  -153,   196,  -153,   214,  -153,   142,
    -153,    64,  -153,  -153,   272,   237,  -152,   194,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,   107,  -153,
     195,   -20,   242,    70,    58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,    16,     9,    12,    13,    38,
      19,    24,    25,   117,   118,   119,   120,   121,   162,   163,
      66,    27,    67,    68,    71,    72,    73,    74,    75,   170,
     198,   199,   200,   201,    52,    22,    53,    54,    55,    56,
      57,   216,    58,    59,    60,   214,    61,   181,   182,    62,
     132,   133,    40,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,   116,   168,   184,   160,   186,   164,    81,    82,    83,
      65,   190,    88,    89,     1,    65,    79,   107,    76,     4,
      85,    86,    87,    69,    77,   100,   108,   109,     5,   103,
     110,   105,    28,    29,    30,    43,    31,    32,    33,   111,
      70,   112,    44,   174,   122,   123,    96,     6,    97,   175,
     159,   191,   226,   164,    98,   113,   228,   229,    10,    99,
     197,   116,   174,   231,   114,    90,    11,   155,   178,    15,
      45,    91,   220,   222,   236,   237,   149,   223,    46,   152,
      47,   196,    48,    49,   122,   122,   193,   221,   242,    14,
     189,   180,    92,    78,    43,    80,    15,   115,    43,   116,
      93,    44,    50,   194,    18,    44,    23,    20,    81,    82,
      83,    26,   241,   197,    51,    63,    94,   172,   173,   180,
      65,    85,    86,    87,    95,   101,   218,   102,    15,    45,
     106,   116,    15,    45,   183,   125,   185,   212,   126,    47,
     116,    48,    49,    47,   129,    48,    49,    44,   131,   144,
     145,   146,   147,   130,   205,   232,   150,   207,   141,   142,
     143,    50,   116,   116,   154,    50,    81,    82,    83,   213,
     156,   116,   158,    51,    15,    45,   161,    51,   166,    85,
      86,    87,   165,   167,   177,    47,   227,    48,    49,   169,
     187,    28,    29,    30,   230,    31,    32,    33,    34,   188,
      35,   195,   203,   202,    28,    29,    30,    50,    31,    32,
      33,   179,   107,   153,    36,   204,   206,   208,   209,    51,
     215,   108,   109,   219,   122,   110,   233,    28,    29,    30,
     224,    31,    32,    33,   111,   225,   112,   234,    81,    82,
      83,    81,    82,    83,   238,   239,    21,   210,    37,    64,
     113,    85,    86,    87,    85,    86,    87,    81,    82,    83,
     192,    81,    82,    83,   124,    84,   157,   127,   171,   240,
      85,    86,    87,   134,    85,    86,    87,    81,    82,    83,
      17,   176,    81,    82,    83,   128,   235,   104,   211,   148,
      85,    86,    87,   151,     0,    85,    86,    87,    28,    29,
      30,     0,    31,    32,    33,     0,     0,   217,    28,    29,
      30,     0,    31,    32,    33,   179,    28,    29,    30,     0,
      31,    32,    33,   135,   136,   137,     0,   138,   139,   140
};

static const yytype_int16 yycheck[] =
{
      20,    63,   123,   155,   113,   157,   115,    30,    31,    32,
      25,   161,    26,    27,    82,    25,    36,     3,    35,    25,
      43,    44,    45,    64,    41,    45,    12,    13,     0,    49,
      16,    51,    18,    19,    20,    18,    22,    23,    24,    25,
      81,    27,    25,    36,    36,    37,    33,    54,    35,    42,
     112,    61,   202,   162,    41,    41,   208,   209,    38,    46,
     169,   123,    36,   215,    50,    79,    25,    90,    42,    52,
      53,    28,   193,    38,   224,   225,    96,    42,    61,    99,
      63,    96,    65,    66,    36,    36,    37,   196,   240,    35,
      42,   153,    49,    35,    18,    37,    52,    83,    18,   161,
      57,    25,    85,   165,    92,    25,    25,    30,    30,    31,
      32,    96,   233,   222,    97,    30,    73,   129,   130,   181,
      25,    43,    44,    45,    37,    25,   188,    18,    52,    53,
      38,   193,    52,    53,   154,    25,   156,    59,    25,    63,
     202,    65,    66,    63,    38,    65,    66,    25,    25,    91,
      92,    93,    94,    38,   174,   217,    25,   177,    88,    89,
      90,    85,   224,   225,    46,    85,    30,    31,    32,    91,
      94,   233,    47,    97,    52,    53,    33,    97,    38,    43,
      44,    45,    47,    25,    46,    63,   206,    65,    66,    41,
      25,    18,    19,    20,   214,    22,    23,    24,    25,    47,
      27,    38,    38,    37,    18,    19,    20,    85,    22,    23,
      24,    25,     3,    77,    41,    38,    46,    37,    37,    97,
      60,    12,    13,    34,    36,    16,    77,    18,    19,    20,
      37,    22,    23,    24,    25,    37,    27,    38,    30,    31,
      32,    30,    31,    32,    38,    38,    12,    61,    75,    24,
      41,    43,    44,    45,    43,    44,    45,    30,    31,    32,
     162,    30,    31,    32,    67,    38,    58,    71,   126,    58,
      43,    44,    45,    42,    43,    44,    45,    30,    31,    32,
       8,    34,    30,    31,    32,    71,   222,    50,   181,    95,
      43,    44,    45,    98,    -1,    43,    44,    45,    18,    19,
      20,    -1,    22,    23,    24,    -1,    -1,    27,    18,    19,
      20,    -1,    22,    23,    24,    25,    18,    19,    20,    -1,
      22,    23,    24,    81,    82,    83,    -1,    85,    86,    87
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    82,   102,   103,    25,     0,    54,   104,   105,   107,
      38,    25,   108,   109,    35,    52,   106,   135,    92,   111,
      30,   109,   136,    25,   112,   113,    96,   122,    18,    19,
      20,    22,    23,    24,    25,    27,    41,    75,   110,   152,
     153,   154,   155,    18,    25,    53,    61,    63,    65,    66,
      85,    97,   135,   137,   138,   139,   140,   141,   143,   144,
     145,   147,   150,    30,   113,    25,   121,   123,   124,    64,
      81,   125,   126,   127,   128,   129,    35,    41,   155,   152,
     155,    30,    31,    32,    38,    43,    44,    45,    26,    27,
      79,    28,    49,    57,    73,    37,    33,    35,    41,    46,
     152,    25,    18,   152,   136,   152,    38,     3,    12,    13,
      16,    25,    27,    41,    50,    83,   110,   114,   115,   116,
     117,   118,    36,    37,   124,    25,    25,   126,   128,    38,
      38,    25,   151,   152,    42,   153,   153,   153,   153,   153,
     153,   154,   154,   154,   155,   155,   155,   155,   138,   152,
      25,   151,   152,    77,    46,    90,    94,    58,    47,   110,
     121,    33,   119,   120,   121,    47,    38,    25,   114,    41,
     130,   130,   104,   104,    36,    42,    34,    46,    42,    25,
     110,   148,   149,   152,   137,   152,   137,    25,    47,    42,
     116,    61,   120,    37,   110,    38,    96,   121,   131,   132,
     133,   134,    37,    38,    38,   152,    46,   152,    37,    37,
      61,   149,    59,    91,   146,    60,   142,    27,   110,    34,
     114,   121,    38,    42,    37,    37,   116,   152,   137,   137,
     152,   137,   110,    77,    38,   132,   116,   116,    38,    38,
      58,   114,   137
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   103,   104,   105,   106,   107,   107,   108,
     108,   109,   110,   110,   110,   110,   110,   110,   111,   111,
     112,   112,   113,   114,   114,   114,   115,   115,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   117,   118,   119,
     119,   120,   121,   121,   122,   122,   123,   123,   124,   125,
     125,   125,   125,   125,   126,   127,   128,   129,   130,   130,
     131,   131,   132,   132,   133,   134,   135,   136,   136,   137,
     137,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     139,   139,   139,   140,   140,   141,   142,   142,   143,   144,
     145,   146,   146,   147,   148,   148,   149,   149,   150,   151,
     151,   152,   152,   152,   152,   152,   152,   152,   153,   153,
     153,   153,   154,   154,   154,   154,   154,   155,   155,   155,
     155,   155,   155,   155
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     2,     4,     1,     2,     0,     2,
       1,     4,     1,     1,     1,     1,     1,     1,     2,     0,
       2,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     4,     5,     3,     6,     3,     2,
       1,     4,     3,     1,     2,     0,     2,     1,     4,     2,
       2,     1,     1,     0,     4,     5,     4,     3,     3,     0,
       3,     1,     3,     3,     2,     1,     3,     3,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     6,     5,     1,     4,     5,     2,     0,     4,     4,
       8,     1,     1,     5,     2,     1,     4,     4,     2,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     1,     4,     1,
       3,     2,     2,     3
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
#line 143 "parser/pascal.y"
                                    {
        //root of ast, a global variable
        ast_root = new ASTProgram((yyvsp[-2].ast_program_head), (yyvsp[-1].ast_routine)); 
        SET_LOCATION((yyval.ast_program));
    }
#line 1891 "pascal.y.h"
    break;

  case 3:
#line 151 "parser/pascal.y"
                                           {
        (yyval.ast_program_head) = new ASTProgramHead((yyvsp[-1].str));
        SET_LOCATION((yyval.ast_program_head));
    }
#line 1900 "pascal.y.h"
    break;

  case 4:
#line 158 "parser/pascal.y"
                              {
        // IMPORTANT !!!
        // function_decl and procedure_decl should 
        // inherit routine
        (yyval.ast_routine) = new ASTRoutine((yyvsp[-1].ast_routine_head), (yyvsp[0].ast_stmt_list));
        SET_LOCATION((yyval.ast_routine));
    }
#line 1912 "pascal.y.h"
    break;

  case 5:
#line 169 "parser/pascal.y"
                                               {
        (yyval.ast_routine_head) = new ASTRoutineHead((yyvsp[-3].ast_const_part), (yyvsp[-2].ast_type_part), (yyvsp[-1].ast_var_part), (yyvsp[0].ast_routine_part));
        SET_LOCATION((yyval.ast_routine_head));
    }
#line 1921 "pascal.y.h"
    break;

  case 6:
#line 177 "parser/pascal.y"
                 {
        (yyval.ast_stmt_list) = new ASTRoutineBody((yyvsp[0].ast_stmt_list));
        SET_LOCATION((yyval.ast_stmt_list));
    }
#line 1930 "pascal.y.h"
    break;

  case 7:
#line 185 "parser/pascal.y"
                              {
        (yyval.ast_const_part) = new ASTConstPart((yyvsp[0].ast_const_expr_list));
        SET_LOCATION((yyval.ast_const_part));
    }
#line 1939 "pascal.y.h"
    break;

  case 8:
#line 189 "parser/pascal.y"
             {
        (yyval.ast_const_part) = nullptr;
    }
#line 1947 "pascal.y.h"
    break;

  case 9:
#line 195 "parser/pascal.y"
                               {
        ((yyvsp[-1].ast_const_expr_list))->add_const_expr((yyvsp[0].ast_const_expr));
        (yyval.ast_const_expr_list) = (yyvsp[-1].ast_const_expr_list);
        SET_LOCATION((yyval.ast_const_expr_list));
    }
#line 1957 "pascal.y.h"
    break;

  case 10:
#line 200 "parser/pascal.y"
                 {
        (yyval.ast_const_expr_list) = new ASTConstExprList();
        (yyval.ast_const_expr_list)->add_const_expr((yyvsp[0].ast_const_expr));
        SET_LOCATION((yyval.ast_const_expr_list));
    }
#line 1967 "pascal.y.h"
    break;

  case 11:
#line 208 "parser/pascal.y"
                                               {
        (yyval.ast_const_expr) = new ASTConstExpr((yyvsp[-3].str), (yyvsp[-1].ast_expr));
        SET_LOCATION((yyval.ast_const_expr));
    }
#line 1976 "pascal.y.h"
    break;

  case 12:
#line 216 "parser/pascal.y"
                {
        (yyval.ast_const_value) = new ASTConstValue((yyvsp[0].str), ASTConstValue::ValueType::INTEGER);
        SET_LOCATION((yyval.ast_const_value));
    }
#line 1985 "pascal.y.h"
    break;

  case 13:
#line 220 "parser/pascal.y"
                    {
        (yyval.ast_const_value) = new ASTConstValue((yyvsp[0].str), ASTConstValue::ValueType::FLOAT);
        SET_LOCATION((yyval.ast_const_value));
    }
#line 1994 "pascal.y.h"
    break;

  case 14:
#line 224 "parser/pascal.y"
                   {
        (yyval.ast_const_value) = new ASTConstValue((yyvsp[0].str), ASTConstValue::ValueType::CHAR);
        SET_LOCATION((yyval.ast_const_value));
    }
#line 2003 "pascal.y.h"
    break;

  case 15:
#line 228 "parser/pascal.y"
                  {
        (yyval.ast_const_value) = new ASTConstValue((yyvsp[0].str), ASTConstValue::ValueType::STRING);
        SET_LOCATION((yyval.ast_const_value));
    }
#line 2012 "pascal.y.h"
    break;

  case 16:
#line 232 "parser/pascal.y"
                    {
        (yyval.ast_const_value) = new ASTConstValue((yyvsp[0].str), ASTConstValue::ValueType::BOOL);
        SET_LOCATION((yyval.ast_const_value));
        /* */
    }
#line 2022 "pascal.y.h"
    break;

  case 17:
#line 237 "parser/pascal.y"
                   {
        (yyval.ast_const_value) = new ASTConstValue((yyvsp[0].str), ASTConstValue::ValueType::BOOL);
        SET_LOCATION((yyval.ast_const_value));
    }
#line 2031 "pascal.y.h"
    break;

  case 18:
#line 244 "parser/pascal.y"
                            {
        (yyval.ast_type_part) = new ASTTypePart((yyvsp[0].ast_type_decl_list));
        SET_LOCATION((yyval.ast_type_part));
    }
#line 2040 "pascal.y.h"
    break;

  case 19:
#line 248 "parser/pascal.y"
            {
        (yyval.ast_type_part) = nullptr;
        SET_LOCATION((yyval.ast_type_part));
    }
#line 2049 "pascal.y.h"
    break;

  case 20:
#line 255 "parser/pascal.y"
                                  {
        (yyval.ast_type_decl_list) = (yyvsp[-1].ast_type_decl_list);
        (yyval.ast_type_decl_list)->addASTTypeDefinition((yyvsp[0].ast_type_definition));
        SET_LOCATION((yyval.ast_type_decl_list));
    }
#line 2059 "pascal.y.h"
    break;

  case 21:
#line 260 "parser/pascal.y"
                     {
        (yyval.ast_type_decl_list) = new ASTTypeDeclList((yyvsp[0].ast_type_definition));
        SET_LOCATION((yyval.ast_type_decl_list));
    }
#line 2068 "pascal.y.h"
    break;

  case 22:
#line 267 "parser/pascal.y"
                                             {
        (yyval.ast_type_definition) = new ASTTypeDefinition((yyvsp[-3].str), (yyvsp[-1].ast_type_decl));
        SET_LOCATION((yyval.ast_type_definition));
    }
#line 2077 "pascal.y.h"
    break;

  case 23:
#line 274 "parser/pascal.y"
                    {
        (yyval.ast_type_decl) = (yyvsp[0].ast_simple_type_decl);
        SET_LOCATION((yyval.ast_type_decl));
    }
#line 2086 "pascal.y.h"
    break;

  case 24:
#line 278 "parser/pascal.y"
                     {
        (yyval.ast_type_decl) = (yyvsp[0].ast_array_type_decl);
        SET_LOCATION((yyval.ast_type_decl));
    }
#line 2095 "pascal.y.h"
    break;

  case 25:
#line 282 "parser/pascal.y"
                      {
        (yyval.ast_type_decl) = (yyvsp[0].ast_record_type_decl);
        SET_LOCATION((yyval.ast_type_decl));
    }
#line 2104 "pascal.y.h"
    break;

  case 26:
#line 289 "parser/pascal.y"
                {
        (yyval.ast_type) = new ASTType(ASTType::Typename::BOOLEAN);
        SET_LOCATION((yyval.ast_type));
    }
#line 2113 "pascal.y.h"
    break;

  case 27:
#line 293 "parser/pascal.y"
               {
        (yyval.ast_type) = new ASTType(ASTType::Typename::CHAR);
        SET_LOCATION((yyval.ast_type));
    }
#line 2122 "pascal.y.h"
    break;

  case 28:
#line 297 "parser/pascal.y"
              {
        (yyval.ast_type) = new ASTType(ASTType::Typename::INTERGER);
        SET_LOCATION((yyval.ast_type));
    }
#line 2131 "pascal.y.h"
    break;

  case 29:
#line 301 "parser/pascal.y"
                {
        (yyval.ast_type) = new ASTType(ASTType::Typename::REAL);
        SET_LOCATION((yyval.ast_type));
    }
#line 2140 "pascal.y.h"
    break;

  case 30:
#line 308 "parser/pascal.y"
        {
        (yyval.ast_simple_type_decl) = new ASTSimpleTypeDecl((yyvsp[0].ast_type));
        SET_LOCATION((yyval.ast_simple_type_decl));
    }
#line 2149 "pascal.y.h"
    break;

  case 31:
#line 312 "parser/pascal.y"
                {
        /* TODO: need to be completed. */
    }
#line 2157 "pascal.y.h"
    break;

  case 32:
#line 315 "parser/pascal.y"
                                      {

    }
#line 2165 "pascal.y.h"
    break;

  case 33:
#line 318 "parser/pascal.y"
                                          {

    }
#line 2173 "pascal.y.h"
    break;

  case 34:
#line 321 "parser/pascal.y"
                                                   {

    }
#line 2181 "pascal.y.h"
    break;

  case 35:
#line 324 "parser/pascal.y"
                                                            {

    }
#line 2189 "pascal.y.h"
    break;

  case 36:
#line 327 "parser/pascal.y"
                                        {

    }
#line 2197 "pascal.y.h"
    break;

  case 37:
#line 333 "parser/pascal.y"
                                                                   {
        (yyval.ast_array_type_decl) = new ASTArrayTypeDecl((yyvsp[-3].ast_simple_type_decl), (yyvsp[0].ast_type_decl));
        SET_LOCATION((yyval.ast_array_type_decl));
    }
#line 2206 "pascal.y.h"
    break;

  case 38:
#line 340 "parser/pascal.y"
                                      {
        (yyval.ast_record_type_decl) = new ASTRecordTypeDecl((yyvsp[-1].ast_field_decl_list));
        SET_LOCATION((yyval.ast_record_type_decl));
    }
#line 2215 "pascal.y.h"
    break;

  case 39:
#line 347 "parser/pascal.y"
                              {
        (yyval.ast_field_decl_list) = (yyvsp[-1].ast_field_decl_list);
        (yyval.ast_field_decl_list)->addASTFieldDecl((yyvsp[0].ast_field_decl));
        SET_LOCATION((yyval.ast_field_decl_list));
    }
#line 2225 "pascal.y.h"
    break;

  case 40:
#line 352 "parser/pascal.y"
                {
        (yyval.ast_field_decl_list) = new addASTFieldDecl((yyvsp[0].ast_field_decl));
        SET_LOCATION((yyval.ast_field_decl_list));
    }
#line 2234 "pascal.y.h"
    break;

  case 41:
#line 359 "parser/pascal.y"
                                               {
        (yyval.ast_field_decl) = new ASTFieldDecl((yyvsp[-3].ast_name_list), (yyvsp[-1].ast_type_decl));
        SET_LOCATION((yyval.ast_field_decl));
    }
#line 2243 "pascal.y.h"
    break;

  case 42:
#line 366 "parser/pascal.y"
                                  {
        (yyval.ast_name_list) = (yyvsp[-2].ast_name_list);
        (yyval.ast_name_list)->addIDENTIFIER((yyvsp[0].str));
        SET_LOCATION((yyval.ast_name_list));
    }
#line 2253 "pascal.y.h"
    break;

  case 43:
#line 371 "parser/pascal.y"
                {
        (yyval.ast_name_list) = new ASTNameList((yyvsp[0].str));
        SET_LOCATION((yyval.ast_name_list));
    }
#line 2262 "pascal.y.h"
    break;

  case 44:
#line 378 "parser/pascal.y"
                         {
        (yyval.ast_var_part) = new ASTVarPart((yyvsp[0].ast_var_decl_list));
        SET_LOCATION((yyval.ast_var_part));
    }
#line 2271 "pascal.y.h"
    break;

  case 45:
#line 382 "parser/pascal.y"
            {
        (yyval.ast_var_part) = nullptr;
    }
#line 2279 "pascal.y.h"
    break;

  case 46:
#line 388 "parser/pascal.y"
                          {
        (yyval.ast_var_decl_list) = (yyvsp[-1].ast_var_decl_list);
        (yyval.ast_var_decl_list)->addVarDecl((yyvsp[0].ast_var_decl));
        SET_LOCATION((yyval.ast_var_decl_list));
    }
#line 2289 "pascal.y.h"
    break;

  case 47:
#line 393 "parser/pascal.y"
              {
        (yyval.ast_var_decl_list) = new ASTVarDeclList((yyvsp[0].ast_var_decl));
        SET_LOCATION((yyval.ast_var_decl_list));
    }
#line 2298 "pascal.y.h"
    break;

  case 48:
#line 400 "parser/pascal.y"
                                               {
        (yyval.ast_var_decl) = new ASTVarDecl((yyvsp[-3].ast_name_list), (yyvsp[-1].ast_type_decl));
        SET_LOCATION((yyval.ast_var_decl));
    }
#line 2307 "pascal.y.h"
    break;

  case 49:
#line 407 "parser/pascal.y"
                               {
        ((yyvsp[-1].ast_routine_part))->add_function_decl((yyvsp[0].ast_function_decl));
        (yyval.ast_routine_part) = (yyvsp[-1].ast_routine_part);
        SET_LOCATION((yyval.ast_routine_part));
    }
#line 2317 "pascal.y.h"
    break;

  case 50:
#line 412 "parser/pascal.y"
                                  {
        ((yyvsp[-1].ast_routine_part))->add_procedure_decl((yyvsp[0].ast_procedure_decl));
        (yyval.ast_routine_part) = (yyvsp[-1].ast_routine_part);
        SET_LOCATION((yyval.ast_routine_part));
    }
#line 2327 "pascal.y.h"
    break;

  case 51:
#line 417 "parser/pascal.y"
                    {
        (yyval.ast_routine_part) = new ASTRoutinePart((yyvsp[0].ast_function_decl));
        SET_LOCATION((yyval.ast_routine_part));
    }
#line 2336 "pascal.y.h"
    break;

  case 52:
#line 421 "parser/pascal.y"
                     {
        (yyval.ast_routine_part) = new ASTRoutinePart((yyvsp[0].ast_procedure_decl));
        SET_LOCATION((yyval.ast_routine_part));
    }
#line 2345 "pascal.y.h"
    break;

  case 53:
#line 425 "parser/pascal.y"
             {
        (yyval.ast_routine_part) = nullptr;
    }
#line 2353 "pascal.y.h"
    break;

  case 54:
#line 431 "parser/pascal.y"
                                                      {
        // inherit routine !!! 
        // thus routine part can be easily constructed
        (yyval.ast_function_decl) = new ASTFunctionDecl((yyvsp[-3].ast_function_head), (yyvsp[-1].ast_routine));
        SET_LOCATION((yyval.ast_function_decl));
    }
#line 2364 "pascal.y.h"
    break;

  case 55:
#line 440 "parser/pascal.y"
                                                                  {
        (yyval.ast_function_head) = new ASTFunctionHead((yyvsp[-3].str), (yyvsp[-2].ast_para_decl_list), (yyvsp[0].ast_simple_type_decl));
        SET_LOCATION((yyval.ast_function_head));
    }
#line 2373 "pascal.y.h"
    break;

  case 56:
#line 447 "parser/pascal.y"
                                                       {
        // inherit routine !!! 
        // thus routine part can be easily constructed
        (yyval.ast_procedure_decl) = new ASTProcedureDecl((yyvsp[-3].ast_procedure_head), (yyvsp[-1].ast_routine));
        SET_LOCATION((yyval.ast_procedure_decl));
    }
#line 2384 "pascal.y.h"
    break;

  case 57:
#line 456 "parser/pascal.y"
                                        {
        (yyval.ast_procedure_head) = new ASTProcedureHead((yyvsp[-1].str), (yyvsp[0].ast_para_decl_list));
        SET_LOCATION((yyval.ast_procedure_head));
    }
#line 2393 "pascal.y.h"
    break;

  case 58:
#line 463 "parser/pascal.y"
                                         {
        (yyval.ast_para_decl_list) = (yyvsp[-1].ast_para_decl_list);
        SET_LOCATION((yyval.ast_para_decl_list));
    }
#line 2402 "pascal.y.h"
    break;

  case 59:
#line 467 "parser/pascal.y"
             {
        (yyval.ast_para_decl_list) = nullptr;
    }
#line 2410 "pascal.y.h"
    break;

  case 60:
#line 473 "parser/pascal.y"
                                                {
        ((yyvsp[-2].ast_para_decl_list))->add_para_type_list((yyvsp[0].ast_para_type_list));
        (yyval.ast_para_decl_list) = (yyvsp[-2].ast_para_decl_list);
        SET_LOCATION((yyval.ast_para_decl_list));
    }
#line 2420 "pascal.y.h"
    break;

  case 61:
#line 478 "parser/pascal.y"
                     {
        (yyval.ast_para_decl_list) = new ASTParaDeclList((yyvsp[0].ast_para_type_list));
        SET_LOCATION((yyval.ast_para_decl_list));
    }
#line 2429 "pascal.y.h"
    break;

  case 62:
#line 485 "parser/pascal.y"
                                             {
        (yyval.ast_para_type_list) = new ASTParaTypeList((yyvsp[-2].ast_var_para_list), (yyvsp[0].ast_simple_type_decl));
        SET_LOCATION((yyval.ast_para_type_list));
    }
#line 2438 "pascal.y.h"
    break;

  case 63:
#line 489 "parser/pascal.y"
                                               {
        (yyval.ast_para_type_list) = new ASTParaTypeList((yyvsp[-2].ast_val_para_list), (yyvsp[0].ast_simple_type_decl));
        SET_LOCATION((yyval.ast_para_type_list));
    }
#line 2447 "pascal.y.h"
    break;

  case 64:
#line 496 "parser/pascal.y"
                      {
        (yyval.ast_var_para_list) = new ASTVarParaList((yyvsp[0].ast_name_list));
        SET_LOCATION((yyval.ast_var_para_list));
    }
#line 2456 "pascal.y.h"
    break;

  case 65:
#line 503 "parser/pascal.y"
              {
        (yyval.ast_val_para_list) = new ASTValParaList((yyvsp[0].ast_name_list));
        SET_LOCATION((yyval.ast_val_para_list));
    }
#line 2465 "pascal.y.h"
    break;

  case 66:
#line 510 "parser/pascal.y"
                               {
        (yyval.ast_stmt_list) = new ASTStmtList((yyvsp[-1].ast_stmt_list));
        SET_LOCATION((yyval.ast_stmt_list));
    }
#line 2474 "pascal.y.h"
    break;

  case 67:
#line 517 "parser/pascal.y"
                                {
        (yyval.ast_stmt_list) = (yyvsp[-2].ast_stmt_list);
        if ((yyval.ast_stmt_list) == nullptr)
            (yyval.ast_stmt_list) = new ASTStmtList((yyvsp[-1].ast_stmt));
        else
            (yyval.ast_stmt_list)->addStmt((yyvsp[-1].ast_stmt));
        SET_LOCATION((yyval.ast_stmt_list));
    }
#line 2487 "pascal.y.h"
    break;

  case 68:
#line 525 "parser/pascal.y"
            {
        (yyval.ast_stmt_list) = nullptr;
    }
#line 2495 "pascal.y.h"
    break;

  case 69:
#line 531 "parser/pascal.y"
                                        {
        (yyval.ast_stmt) = new ASTStmt((yyvsp[0].ast_stmt), (yyvsp[-2].str));
        SET_LOCATION((yyval.ast_stmt));
    }
#line 2504 "pascal.y.h"
    break;

  case 70:
#line 535 "parser/pascal.y"
                    {
        (yyval.ast_stmt) = new ASTStmt((yyvsp[0].ast_stmt));
        SET_LOCATION((yyval.ast_stmt));
    }
#line 2513 "pascal.y.h"
    break;

  case 71:
#line 542 "parser/pascal.y"
               {
        (yyval.ast_stmt) = (yyvsp[0].ast_assign_stmt);
    }
#line 2521 "pascal.y.h"
    break;

  case 72:
#line 545 "parser/pascal.y"
               {
        (yyval.ast_stmt) = (yyvsp[0].ast_proc_stmt);
    }
#line 2529 "pascal.y.h"
    break;

  case 73:
#line 548 "parser/pascal.y"
                   {
        (yyval.ast_stmt) = (yyvsp[0].ast_stmt_list);
    }
#line 2537 "pascal.y.h"
    break;

  case 74:
#line 551 "parser/pascal.y"
             {
        (yyval.ast_stmt) = (yyvsp[0].ast_if_stmt);
    }
#line 2545 "pascal.y.h"
    break;

  case 75:
#line 554 "parser/pascal.y"
                 {
        (yyval.ast_stmt) = (yyvsp[0].ast_repeat_stmt);
    }
#line 2553 "pascal.y.h"
    break;

  case 76:
#line 557 "parser/pascal.y"
                {
        (yyval.ast_stmt) = (yyvsp[0].ast_while_stmt);
    }
#line 2561 "pascal.y.h"
    break;

  case 77:
#line 560 "parser/pascal.y"
              {
        (yyval.ast_stmt) = (yyvsp[0].ast_for_stmt);
    }
#line 2569 "pascal.y.h"
    break;

  case 78:
#line 563 "parser/pascal.y"
               {
        (yyval.ast_stmt) = (yyvsp[0].ast_case_stmt);
    }
#line 2577 "pascal.y.h"
    break;

  case 79:
#line 566 "parser/pascal.y"
               {
        (yyval.ast_stmt) = (yyvsp[0].ast_goto_stmt);
    }
#line 2585 "pascal.y.h"
    break;

  case 80:
#line 572 "parser/pascal.y"
                                    {
        ASTIDExpr *expr = new ASTIDExpr((yyvsp[-2].str));
        (yyval.ast_assign_stmt) = new ASTAssignStmt(expr, (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_assign_stmt));
    }
#line 2595 "pascal.y.h"
    break;

  case 81:
#line 577 "parser/pascal.y"
                                                                     {
        ASTArrayExpr *expr = new ASTArrayExpr((yyvsp[-5].str), (yyvsp[-3].ast_expr));
        (yyval.ast_assign_stmt) = new ASTAssignStmt(expr, (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_assign_stmt));
    }
#line 2605 "pascal.y.h"
    break;

  case 82:
#line 582 "parser/pascal.y"
                                                            {
        ASTArrayExpr *expr = new ASTPropExpr((yyvsp[-4].str), (yyvsp[-2].str));
        (yyval.ast_assign_stmt) = new ASTAssignStmt(expr, (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_assign_stmt));
    }
#line 2615 "pascal.y.h"
    break;

  case 83:
#line 592 "parser/pascal.y"
              {
        (yyval.ast_proc_stmt) = new ASTProcStmt((yyvsp[0].str));
    }
#line 2623 "pascal.y.h"
    break;

  case 84:
#line 595 "parser/pascal.y"
                                                      {
        (yyval.ast_proc_stmt) = new ASTProcStmt((yyvsp[-3].str), (yyvsp[-2].tok));
        
    }
#line 2632 "pascal.y.h"
    break;

  case 85:
#line 603 "parser/pascal.y"
                                                {
        (yyval.ast_if_stmt) = new ASTIfStmt((yyvsp[-3].ast_expr), (yyvsp[-1].ast_stmt), (yyvsp[0].ast_else_clause));
        SET_LOCATION((yyval.ast_if_stmt));
    }
#line 2641 "pascal.y.h"
    break;

  case 86:
#line 610 "parser/pascal.y"
                  {
        (yyval.ast_else_clause) = new ASTElseClause((yyvsp[0].ast_stmt));
        SET_LOCATION((yyval.ast_else_clause));    
    }
#line 2650 "pascal.y.h"
    break;

  case 87:
#line 614 "parser/pascal.y"
             {
        (yyval.ast_else_clause) = nullptr;
    }
#line 2658 "pascal.y.h"
    break;

  case 88:
#line 620 "parser/pascal.y"
                                              {
        (yyval.ast_repeat_stmt) = new ASTRepeatStmt((yyvsp[-2].ast_stmt_list), (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_repeat_stmt));
    }
#line 2667 "pascal.y.h"
    break;

  case 89:
#line 627 "parser/pascal.y"
                                     {
        (yyval.ast_while_stmt) = new ASTWhileStmt((yyvsp[-2].ast_expr), (yyvsp[0].ast_stmt));
        SET_LOCATION((yyval.ast_while_stmt));
    }
#line 2676 "pascal.y.h"
    break;

  case 90:
#line 634 "parser/pascal.y"
                                                                              {
        (yyval.ast_for_stmt) = new ASTForStmt((yyvsp[-6].str), (yyvsp[-4].ast_expr), (yyvsp[-3].ast_for_stmt_dir), (yyvsp[-2].ast_expr), (yyvsp[0].ast_stmt));
        SET_LOCATION((yyval.ast_for_stmt));
    }
#line 2685 "pascal.y.h"
    break;

  case 91:
#line 641 "parser/pascal.y"
           {
        (yyval.ast_for_stmt_dir) = ASTForStmt::ForDir::TO;
    }
#line 2693 "pascal.y.h"
    break;

  case 92:
#line 644 "parser/pascal.y"
                 {
        (yyval.ast_for_stmt_dir) = ASTForStmt::ForDir::DOWNTO;
    }
#line 2701 "pascal.y.h"
    break;

  case 93:
#line 650 "parser/pascal.y"
                                                      {
        (yyval.ast_case_stmt) = new ASTCaseStmt((yyvsp[-3].ast_expr), (yyvsp[-1].ast_case_expr_list));
        SET_LOCATION((yyval.ast_case_stmt));
    }
#line 2710 "pascal.y.h"
    break;

  case 94:
#line 657 "parser/pascal.y"
                             {
        ((yyvsp[-1].ast_case_expr_list))->add_case_expr((yyvsp[0].ast_case_expr));
        (yyval.ast_case_expr_list) = (yyvsp[-1].ast_case_expr_list);
        SET_LOCATION((yyval.ast_case_expr_list));
    }
#line 2720 "pascal.y.h"
    break;

  case 95:
#line 662 "parser/pascal.y"
                {
        (yyval.ast_case_expr_list) = new ASTCaseExprList();
        (yyval.ast_case_expr_list)->add_case_expr((yyvsp[0].ast_case_expr));
        SET_LOCATION((yyval.ast_case_expr_list)); 
    }
#line 2730 "pascal.y.h"
    break;

  case 96:
#line 670 "parser/pascal.y"
                                             {
        (yyval.ast_case_expr) = new ASTCaseExpr((yyvsp[-3].ast_const_value), (yyvsp[-1].ast_stmt));
        SET_LOCATION((yyval.ast_case_expr));
    }
#line 2739 "pascal.y.h"
    break;

  case 97:
#line 674 "parser/pascal.y"
                                              {
        (yyval.ast_case_expr) = new ASTCaseExpr((yyvsp[-3].str), (yyvsp[-1].ast_stmt));
        SET_LOCATION((yyval.ast_case_expr));    
    }
#line 2748 "pascal.y.h"
    break;

  case 98:
#line 681 "parser/pascal.y"
                         {
        // The construction arg is a string !!!
        (yyval.ast_goto_stmt) = new ASTGotoStmt((yyvsp[0].str));
        SET_LOCATION((yyval.ast_goto_stmt));
    }
#line 2758 "pascal.y.h"
    break;

  case 99:
#line 689 "parser/pascal.y"
                                         {
        (yyval.ast_expression_list) = (yyvsp[-2].ast_expression_list);
        (yyval.ast_expression_list) -> AddExpr((yyvsp[-1].tok));
        SET_LOCATION((yyval.ast_expression_list));
    }
#line 2768 "pascal.y.h"
    break;

  case 100:
#line 694 "parser/pascal.y"
                 {
        (yyval.ast_expression_list) = new ASTExpressionList((yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_expression_list));
    }
#line 2777 "pascal.y.h"
    break;

  case 101:
#line 701 "parser/pascal.y"
                           {
        (yyval.ast_expr) = new ASTBinaryExpr(ASTBinaryExpr::Oper::GE, (yyvsp[-2].ast_expr), (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2786 "pascal.y.h"
    break;

  case 102:
#line 705 "parser/pascal.y"
                             {
        (yyval.ast_expr) = new ASTBinaryExpr(ASTBinaryExpr::Oper::GT, (yyvsp[-2].ast_expr), (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2795 "pascal.y.h"
    break;

  case 103:
#line 709 "parser/pascal.y"
                             {
        (yyval.ast_expr) = new ASTBinaryExpr(ASTBinaryExpr::Oper::LE, (yyvsp[-2].ast_expr), (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2804 "pascal.y.h"
    break;

  case 104:
#line 713 "parser/pascal.y"
                             {
        (yyval.ast_expr) = new ASTBinaryExpr(ASTBinaryExpr::Oper::LT, (yyvsp[-2].ast_expr), (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2813 "pascal.y.h"
    break;

  case 105:
#line 717 "parser/pascal.y"
                             {
        (yyval.ast_expr) = new ASTBinaryExpr(ASTBinaryExpr::Oper::EQUAL, (yyvsp[-2].ast_expr), (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2822 "pascal.y.h"
    break;

  case 106:
#line 721 "parser/pascal.y"
                             {
        (yyval.ast_expr) = new ASTBinaryExpr(ASTBinaryExpr::Oper::UNEQUAL, (yyvsp[-2].ast_expr), (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2831 "pascal.y.h"
    break;

  case 107:
#line 725 "parser/pascal.y"
           {
        (yyval.ast_expr) = (yyvsp[0].ast_expr);
        SET_LOCATION((yyval.ast_expr));
    }
#line 2840 "pascal.y.h"
    break;

  case 108:
#line 732 "parser/pascal.y"
                      {
        (yyval.ast_expr) = new ASTBinaryExpr(ASTBinaryExpr::Oper::PLUS, (yyvsp[-2].ast_expr), (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2849 "pascal.y.h"
    break;

  case 109:
#line 736 "parser/pascal.y"
                        {
        (yyval.ast_expr) = new ASTBinaryExpr(ASTBinaryExpr::Oper::MINUS, (yyvsp[-2].ast_expr), (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2858 "pascal.y.h"
    break;

  case 110:
#line 740 "parser/pascal.y"
                       {
        (yyval.ast_expr) = new ASTBinaryExpr(ASTBinaryExpr::Oper::OR, (yyvsp[-2].ast_expr), (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2867 "pascal.y.h"
    break;

  case 111:
#line 744 "parser/pascal.y"
           {
        (yyval.ast_expr) = (yyvsp[0].ast_expr);
        SET_LOCATION((yyval.ast_expr));
    }
#line 2876 "pascal.y.h"
    break;

  case 112:
#line 750 "parser/pascal.y"
                        {
        (yyval.ast_expr) = new ASTBinaryExpr(ASTBinaryExpr::Oper::MUL, (yyvsp[-2].ast_expr), (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2885 "pascal.y.h"
    break;

  case 113:
#line 754 "parser/pascal.y"
                          {
        (yyval.ast_expr) = new ASTBinaryExpr(ASTBinaryExpr::Oper::DIV, (yyvsp[-2].ast_expr), (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2894 "pascal.y.h"
    break;

  case 114:
#line 758 "parser/pascal.y"
                          {
        (yyval.ast_expr) = new ASTBinaryExpr(ASTBinaryExpr::Oper::MOD, (yyvsp[-2].ast_expr), (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2903 "pascal.y.h"
    break;

  case 115:
#line 762 "parser/pascal.y"
                          {
        (yyval.ast_expr) = new ASTBinaryExpr(ASTBinaryExpr::Oper::AND, (yyvsp[-2].ast_expr), (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2912 "pascal.y.h"
    break;

  case 116:
#line 766 "parser/pascal.y"
             {
        (yyval.ast_expr) = (yyvsp[0].ast_expr);
        SET_LOCATION((yyval.ast_expr));   
    }
#line 2921 "pascal.y.h"
    break;

  case 117:
#line 772 "parser/pascal.y"
               {
        (yyval.ast_expr) = new ASTIDExpr((yyvsp[0].str));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2930 "pascal.y.h"
    break;

  case 118:
#line 776 "parser/pascal.y"
                                                       {
        (yyval.ast_expr) = new ASTFuncCall((yyvsp[-3].str), (yyvsp[-1].ast_expression_list));
        SET_LOCATION((yyval.ast_expr));   
    }
#line 2939 "pascal.y.h"
    break;

  case 119:
#line 780 "parser/pascal.y"
                  {
        (yyval.ast_expr) = new ASTConstValueExpr((yyvsp[0].ast_const_value));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2948 "pascal.y.h"
    break;

  case 120:
#line 784 "parser/pascal.y"
                                       {
        (yyval.ast_expr) = (yyvsp[-1].ast_expr);
        SET_LOCATION((yyval.ast_expr));
    }
#line 2957 "pascal.y.h"
    break;

  case 121:
#line 788 "parser/pascal.y"
                     {
        (yyval.ast_expr) = new ASTUnaryExpr(ASTUnaryExpr::Oper::NOT, (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2966 "pascal.y.h"
    break;

  case 122:
#line 792 "parser/pascal.y"
                     {
        (yyval.ast_expr) = new ASTUnaryExpr(ASTUnaryExpr::Oper::SUB, (yyvsp[0].ast_expr));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2975 "pascal.y.h"
    break;

  case 123:
#line 796 "parser/pascal.y"
                                       {
        (yyval.ast_expr) = new ASTPropExpr((yyvsp[-2].str), (yyvsp[-1].tok));
        SET_LOCATION((yyval.ast_expr));
    }
#line 2984 "pascal.y.h"
    break;


#line 2988 "pascal.y.h"

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
#line 801 "parser/pascal.y"


void yyerror(char const char *str) {
    PrintError(str);
    ParseError = 1;
}

int main() {
    return 0;
}
