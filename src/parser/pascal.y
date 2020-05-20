%{
#define MAX_LITERAL_LEN 256
#define SET_LOCATION(dest) (dest)->set_location(yylloc.first_line, yylloc.first_column)
#include "../ast/ast.h"
#include "../ast/ast_stmt.h"
using namespace AbstractSyntaxTree;

%}

%locations

%union{
    int token_type;
    char* str;
    ASTProgram* ast_program;
    ASTProgramHead* ast_program_head;
    ASTRoutine* ast_routine;
    ASTRoutineHead* ast_routine_head;
    ASTConstExprList* ast_const_expr_list;
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
    ASTRoutineBody* ast_routine_body;
    ASTFunctionDecl* ast_function_decl;
    ASTFunctionHead* ast_function_head;
    ASTProcedureDecl* ast_procedure_decl;
    ASTProcedureHead* ast_procedure_head;
    ASTParaDeclList* ast_para_decl_list;
    ASTParaTypeList* ast_para_type_list;
    ASTStmtList* ast_stmt_list;
    ASTStmt* ast_stmt;
    ASTNonLableStmt* ast_non_label_stmt;
    ASTElseClause* ast_else_clause;
    ASTAssignStmt* ast_assign_stmt;
    ASTProcStmt* ast_proc_stmt;
    ASTIfStmt* ast_if_stmt;
    ASTRepeatStmt* ast_repeat_stmt;
    ASTWhileStmt* ast_while_stmt;
    ASTForStmt* ast_for_stmt;
    ASTCaseStmt* ast_case_stmt;
    ASTCaseExpr* ast_case_expr;
    ASTCaseExprList* ast_case_expr_list;
    ASTGotoStmt* ast_goto_stmt;
    ASTExpressionList* ast_expression_list;
    ASTExpr* ast_expr;
}   

%token TYPE_INT TYPE_INT_8 TYPE_INT_16 TYPE_INT_32 TYPE_INT_64
%token TYPE_UNSIGNED_INT_8 TYPE_UNSIGNED_INT_16 TYPE_UNSIGNED_INT_32 TYPE_UNSIGNED_INT_64 
%token TYPE_BOOLEAN TYPE_FLOAT TYPE_FLOAT_16 TYPE_FLOAT_32 TYPE_CHAR TYPE_STRING
%token LITERAL_INT LITERAL_FLOAT LITERAL_CHAR LITERAL_ESC_CHAR LITERAL_STR LITERAL_TRUE LITERAL_FALSE IDENTIFIER
%token SYM_ADD SYM_SUB SYM_MUL SYM_DIV SYM_EQ SYM_LT SYM_GT SYM_LBRAC SYM_RBRAC SYM_PERIOD SYM_COMMA SYM_COLON
%token SYM_SEMICOLON SYM_AT SYM_CARET SYM_LPAREN SYM_RPAREN SYM_NE SYM_LE SYM_GE SYM_ASSIGN SYM_RANGE COMMENT
%token KWD_AND KWD_ARRAY KWD_ASM KWD_BEGIN KWD_CASE KWD_CONST KWD_CONSTRUCTOR KWD_DESTRUCTOR KWD_DIV
%token KWD_DO KWD_DOWNTO KWD_ELSE KWD_END KWD_FILE KWD_FOR KWD_FUNCTION KWD_GOTO KWD_IF KWD_IMPLEMENTATION KWD_IN 
%token KWD_INHERITED KWD_INLINE KWD_INTERFACE KWD_LABEL KWD_MOD KWD_NIL KWD_NOT KWD_OBJECT KWD_OF KWD_OPERATOR KWD_OR
%token KWD_PACKED KWD_PROCEDURE KWD_PROGRAM KWD_RECORD KWD_REINTRODUCE KWD_REPEAT KWD_SELF KWD_SET KWD_SHL KWD_SHR
%token KWD_THEN KWD_TO KWD_TYPE KWD_UNIT KWD_UNTIL KWD_USES KWD_VAR KWD_WHILE KWD_WITH KWD_XOR
%token SIGN

%type<tok> TYPE_INT TYPE_INT_8 TYPE_INT_16 TYPE_INT_32 TYPE_INT_64
%type<tok> TYPE_UNSIGNED_INT_8 TYPE_UNSIGNED_INT_16 TYPE_UNSIGNED_INT_32 TYPE_UNSIGNED_INT_64 
%type<tok> TYPE_BOOLEAN TYPE_FLOAT TYPE_FLOAT_16 TYPE_FLOAT_32 TYPE_CHAR TYPE_STRING
%type<tok> SYM_ADD SYM_SUB SYM_MUL SYM_DIV SYM_EQ SYM_LT SYM_GT SYM_LBRAC SYM_RBRAC SYM_PERIOD SYM_COMMA SYM_COLON
%type<tok> SYM_SEMICOLON SYM_AT SYM_CARET SYM_LPAREN SYM_RPAREN SYM_NE SYM_LE SYM_GE SYM_ASSIGN SYM_RANGE COMMENT
%type<tok> KWD_AND KWD_ARRAY KWD_ASM KWD_BEGIN KWD_CASE KWD_CONST KWD_CONSTRUCTOR KWD_DESTRUCTOR KWD_DIV
%type<tok> KWD_DO KWD_DOWNTO KWD_ELSE KWD_END KWD_FILE KWD_FOR KWD_FUNCTION KWD_GOTO KWD_IF KWD_IMPLEMENTATION KWD_IN 
%type<tok> KWD_INHERITED KWD_INLINE KWD_INTERFACE KWD_LABEL KWD_MOD KWD_NIL KWD_NOT KWD_OBJECT KWD_OF KWD_OPERATOR KWD_OR
%type<tok> KWD_PACKED KWD_PROCEDURE KWD_PROGRAM KWD_RECORD KWD_REINTRODUCE KWD_REPEAT KWD_SELF KWD_SET KWD_SHL KWD_SHR
%type<tok> KWD_THEN KWD_TO KWD_TYPE KWD_UNIT KWD_UNTIL KWD_USES KWD_VAR KWD_WHILE KWD_WITH KWD_XOR
%type<tok> SIGN

%type<str> LITERAL_INT LITERAL_FLOAT LITERAL_CHAR LITERAL_ESC_CHAR LITERAL_STR LITERAL_TRUE LITERAL_FALSE IDENTIFIER

%type<ast_program> program
%type<ast_program_head> program_head
%type<ast_routine> routine sub_routine
%type<ast_routine_head> routine_head
%type<ast_const_expr_list> const_expr_list const_part
%type<ast_const_value> const_value
%type<ast_type_decl_list> type_part type_decl_list
%type<ast_type_decl> type_definition type_decl
%type<ast_simple_type_decl> simple_type_decl
%type<ast_array_type_decl> array_type_decl 
%type<ast_record_type_decl> record_type_decl
%type<ast_name_list> name_list 
%type<ast_var_para_list> var_para_list
%type<ast_val_para_list> val_para_list
%type<ast_field_decl_list> field_decl_list
%type<ast_field_decl> field_decl 
%type<ast_var_decl_list> var_decl_list 
%type<ast_var_decl> var_decl 
%type<ast_routine_part> routine_part
%type<ast_function_head> function_head
%type<ast_function_decl> function_decl
%type<ast_procedure_decl> procedure_decl 
%type<ast_procedure_head> procedure_head 
%type<ast_para_decl_list> parameters para_decl_list
%type<ast_para_type_list> para_type_list 
%type<ast_stmt_list> routine_body compound_stmt stmt_list
%type<ast_stmt> stmt non_label_stmt 
%type<ast_else_clause> else_clause
%type<ast_assign_stmt> assign_stmt 
%type<ast_proc_stmt> proc_stmt 
%type<ast_if_stmt> if_stmt 
%type<ast_repeat_stmt> repeat_stmt 
%type<ast_while_stmt> while_stmt 
%type<ast_for_stmt> for_stmt
%type<ast_case_stmt> case_stmt 
%type<ast_case_expr_list> case_expr_list 
%type<ast_case_expr> case_expr 
%type<ast_goto_stmt> goto_stmt 
%type<ast_expression_list> expression_list arg_list
%type<ast_expr> expression expr term factor

%%


program: 
    program_head routine SYM_PERIOD {
        $$ = new ASTProgram($1, $2);
        SET_LOCATION($$);
    }
;

program_head:
    KWD_PROGRAM  IDENTIFIER  SYM_SEMICOLON {
        $$ = new ASTProgramHead($2);
        SET_LOCATION($$);
    }
;

routine:
    routine_head  routine_body{
        // IMPORTANT !!!
        // function_decl and procedure_decl should 
        // inherit routine
        $$ = new ASTRoutine($1, $2);
        SET_LOCATION($$);
    }
;


routine_head:
    const_part type_part var_part routine_part {
        $$ = new ASTRoutineHead($1, $2, $3, $4);
        SET_LOCATION($$);
    }
;

const_part:
    KWD_CONST const_expr_list{
        $$ = new ASTConstExprList($2);
        SET_LOCATION($$);
    }
    %empty {
        $$ = nullptr;
    }
;

const_expr_list:
    const_expr_list IDENTIFIER SYM_EQ const_value SYM_SEMICOLON {
        ($1)->add_const_expr($2, $4);
        $$ = $1;
        SET_LOCATION($$);
    }
    | IDENTIFIER SYM_EQ const_value SYM_SEMICOLON {
        $$ = new ASTConstExprList($1, $3);
        SET_LOCATION($$);
    }
;

const_value:
    LITERAL_INT {
        $$ = new ASTConstValue($1, ValueType::INT);
        SET_LOCATION($$);
    }
    | LITERAL_FLOAT {
        $$ = new ASTConstValue($1, ValueType::FLOAT);
        SET_LOCATION($$);
    }
    | LITERAL_CHAR {
        $$ = new ASTConstValue($1, ValueType::CHAR);
        SET_LOCATION($$);
    } 
    | LITERAL_STR {
        $$ = new ASTConstValue($1, ValueType::STRING);
        SET_LOCATION($$);
    }
    | LITERAL_FALSE {
        $$ = new ASTConstValue($1, ValueType::BOOL);
        SET_LOCATION($$);
        /* */
    }
    | LITERAL_TRUE {
        $$ = new ASTConstValue($1, ValueType::BOOL);
        SET_LOCATION($$);
    }
;

type_part:
    KWD_TYPE type_decl_list {
        $$ = new ASTTypePart($2);
        SET_LOCATION($$);
    }
    | %empty{
        $$ = nullptr;
        SET_LOCATION($$);
    }
;

type_decl_list:
    type_decl_list type_definition{
        $$ = $1;
        $$->addASTTypeDefinition($2);
        SET_LOCATION($$);
    }
    | type_definition{
        $$ = new ASTTypeDeclList($1);
        SET_LOCATION($$);
    }
;

type_definition:
    IDENTIFIER SYM_EQ type_decl SYM_SEMICOLON{
        $$ = new ASTTypeDefinition($1, $3);
        SET_LOCATION($$);
    }
;

type_decl:
    simple_type_decl{
        $$ = $1;
        SET_LOCATION($$);
    }
    | array_type_decl{
        $$ = $1;
        SET_LOCATION($$);
    }
    | record_type_decl{
        $$ = $1;
        SET_LOCATION($$);
    }
;

TYPE:
    TYPE_BOOLEAN{
        $$ = new ASTType(ASTType::Typename::BOOLEAN);
        SET_LOCATION($$);
    }
    | TYPE_CHAR{
        $$ = new ASTType(ASTType::Typename::CHAR);
        SET_LOCATION($$);
    }
    | TYPE_INTEGER{
        $$ = new ASTType(ASTType::Typename::INTERGER);
        SET_LOCATION($$);
    }
    | TYPE_REAL{
        $$ = new ASTType(ASTType::Typename::REAL);
        SET_LOCATION($$);
    }
;

simple_type_decl:
    TYPE{
        $$ = new ASTSimpleTypeDecl($1);
        SET_LOCATION($$);
    }
    | IDENTIFIER{
        /* need to be completed. */
    }
    | SYM_LPAREN name_list SYM_RPAREN {

    }
    |  const_value  SYM_RANGE  const_value{

    }
    |  SYM_SUB  const_value  SYM_RANGE  const_value{

    }
    |  SYM_SUB  const_value  SYM_RANGE  SYM_SUB  const_value{

    }
    |  IDENTIFIER  SYM_RANGE  IDENTIFIER{

    }
;

array_type_decl:
    KWD_ARRAY SYM_LBRAC simple_type_decl SYM_RBRAC KWD_OF type_decl{
        $$ = new ASTArrayTypeDecl($3, $6);
        SET_LOCATION($$);
    }
;

record_type_decl:
    KWD_RECORD field_decl_list KWD_END{
        $$ = new ASTRecordTypeDecl($2);
        SET_LOCATION($$);
    }
;

field_decl_list:
    field_decl_list field_decl{
        $$ = $1;
        $$->addASTFieldDecl($2);
        SET_LOCATION($$);
    }
    | field_decl{
        $$ = new addASTFieldDecl($1);
        SET_LOCATION($$);
    }
;

field_decl:
    name_list SYM_COLON type_decl SYM_SEMICOLON{
        $$ = new ASTFieldDecl($1, $3);
        SET_LOCATION($$);
    }
;

name_list:
    name_list SYM_COMMA IDENTIFIER{
        $$ = $1;
        $$->addIDENTIFIER($3);
        SET_LOCATION($$);
    }
    | IDENTIFIER{
        $$ = new ASTNameList($1);
        SET_LOCATION($$);
    }
;

var_part:
    KWD_VAR var_decl_list{
        $$ = new ASTVarPart($2);
        SET_LOCATION($$);
    }
    %empty{
        $$ = nullptr;
    }
;

var_decl_list:
    var_decl_list var_decl{
        $$ = $1;
        $$->addVarDecl($2);
        SET_LOCATION($$);
    }
    | var_decl{
        $$ = new ASTVarDeclList($1);
        SET_LOCATION($$);
    }
;

vec_decl:
    name_list SYM_COLON type_decl SYM_SEMICOLON{
        $$ = new ASTVarDecl($1, $3);
        SET_LOCATION($$);
    }
;

routine_part:
    routine_part function_decl {
        ($1)->add_function_decl($2);
        $$ = $1;
        SET_LOCATION($$);
    }
    | routine_part procedure_decl {
        ($1)->add_procedure_decl($2);
        $$ = $1;
        SET_LOCATION($$);
    }
    | function_decl {
        $$ = new ASTRoutinePart($1);
        SET_LOCATION($$);
    }
    | procedure_decl {
        $$ = new ASTRoutinePart($1);
        SET_LOCATION($$);
    }
    | %empty {
        $$ = nullptr;
    }
;

function_decl:
    function_head SYM_SEMICOLON routine SYM_SEMICOLON {
        // inherit routine !!! 
        // thus routine part can be easily constructed
        $$ = new ASTFunctionDecl($1, $3);
        SET_LOCATION($$);
    }
;

function_head:
    KWD_FUNCTION IDENTIFIER parameters SYM_COLON simple_type_decl {
        $$ = new ASTFunctionHead($2, $3, $5);
        SET_LOCATION($$);
    }
;

procedure_decl:
    procedure_head SYM_SEMICOLON routine SYM_SEMICOLON {
        // inherit routine !!! 
        // thus routine part can be easily constructed
        $$ = new ASTProcedureDecl($1, $3);
        SET_LOCATION($$);
    }
;

procedure_head:
    KWD_PROCEDURE IDENTIFIER parameters {
        $$ = new ASTProcedureHead($2, $3);
        SET_LOCATION($$);
    }
;

parameters:
    SYM_LPAREN para_dec_list SYM_RPAREN {
        $$ = $2;
        SET_LOCATION($$);
    }
    | %empty {
        $$ = nullptr;
    }
;

para_decl_list:
    para_decl_list SYM_SEMICOLON para_type_list {
        ($1)->add_para_type_list($3);
        $$ = $1;
        SET_LOCATION($$);
    }
    | para_type_list {
        $$ = new ASTParaDeclList($1);
        SET_LOCATION($$);
    }
;

para_type_list:
    var_para_list SYM_COLON simple_type_decl {
        $$ = new ASTParaTypeList($1, $3);
        SET_LOCATION($$);
    }
    | val_para_list SYM_COLON simple_type_decl {
        $$ = new ASTParaTypeList($1, $3);
        SET_LOCATION($$);
    }
;

var_para_list:
    KWD_VAR name_list {
        $$ = new ASTVarParaList($2);
        SET_LOCATION($$);
    }
;

val_para_list:
    name_list {
        $$ = new ASTValParaList($1);
        SET_LOCATION($$);
    }
;

routine_body:
    compound_stmt{
        $$ = new ASTRoutineBody($1);
        SET_LOCATION($$);
    }
;

compound_stmt:
    KWD_BEGIN stmt_list KWD_END{
        $$ = new ASTStmtList($2);
        SET_LOCATION($$);
    }
;

stmt_list:
    stmt_list stmt SYM_SEMICOLON{
        $$ = $1;
        $$->addStmt($2);
        SET_LOCATION($$);
    }
;

stmt:
    LITERAL_INT SYM_COLON non_label_stmt{
        $$ = new ASTStmt($3, $1);
        SET_LOCATION($$);
    }
    | non_label_stmt{
        $$ = new ASTStmt($1);
        SET_LOCATION($$);
    }
;

non_label_stmt:
    assign_stmt{
        $$ = $1;
    }
    | proc_stmt{
        $$ = $1;
    }
    | compound_stmt{
        $$ = $1;
    }
    | if_stmt{
        $$ = $1;
    }
    | repeat_stmt{
        $$ = $1;
    }
    | while_stmt{
        $$ = $1;
    }
    | for_stmt{
        $$ = $1;
    }
    | case_stmt{
        $$ = $1;
    }
    | goto_stmt{
        $$ = $1;
    }
;

assign_stmt:
    IDENTIFIER SYM_ASSIGN expression{
        $$ = new ASTAssignStmt(0, $1, $3);
        SET_LOCATION($$);
    }
    | IDENTIFIER SYM_LBRAC expression SYM_RBRAC SYM_ASSIGN expression{
        $$ = new ASTAssignStmt(1, $1, $3, $6);
        SET_LOCATION($$);
    }
    | IDENTIFIER SYM_PERIOD IDENTIFIER SYM_ASSIGN expression{
        $$ = new ASTAssignStmt(2, $1, $3, $6);
        SET_LOCATION($$);
    }
;


proc_stmt:
    /* SYS_PROC | SYS_PROC  LP  expression_list  RP |  READ  LP  factor  RP */
    IDENTIFIER{
        $$ = new ASTProcStmt($1);
    }
    | IDENTIFIER SYM_LPAREN arg_list SYM_RPAREN{
        $$ = new ASTProcStmt($1, $2);
        
    }
;


if_stmt:
    KWD_IF expression KWD_THEN stmt else_clause {
        $$ = new ASTIfStmt($2, $4, $5);
        SET_LOCATION($$);
    }
;

else_clause:
    KWD_ELSE stmt {
        $$ = new ASTElseClause($2);
        SET_LOCATION($$);    
    }
    | %empty {
        $$ = nullptr;
    }
;

repeat_stmt:
    KWD_REPEAT stmt_list KWD_UNTIL expression {
        $$ = new ASTRepeatStmt($2, $4);
        SET_LOCATION($$);
    }
;

while_stmt:
    KWD_WHILE expression KWD_DO stmt {
        $$ = new ASTWhileStmt($2, $4);
        SET_LOCATION($$);
    }
;

for_stmt:
    KWD_FOR IDENTIFIER SYM_ASSIGN expression direction expression KWD_DO stmt {
        $$ = new ASTForStmt($2, $4, $5, $6, $8);
        SET_LOCATION($$);
    }
;

direction:
    KWD_TO {
        $$ = ForDir::To;
    }
    | KWD_DOWNTO {
        $$ = ForDir::Downto;
    }
;

case_stmt:
    KWD_CASE expression KWD_OF case_expr_list KWD_END {
        $$ = new ASTCaseStmt($2, $4);
        SET_LOCATION($$);
    }
;

case_expr_list:
    case_expr_list case_expr {
        ($1)->add_case_expr($2);
        $$ = $1;
        SET_LOCATION($$);
    }
    | case_expr {
        $$ = new ASTCaseExprList($2);
        SET_LOCATION($$); 
    }
;

case_expr:
    const_value SYM_COLON stmt SYM_SEMICOLON {
        $$ = new ASTCaseExpr($1, $3);
        SET_LOCATION($$);
    }
    | ID SYM_COLON stmt SYM_SEMICOLON {
        $$ = new ASTCaseExpr($1, $3);
        SET_LOCATION($$);    
    }
;

goto_stmt:
    KWD_GOTO LITERAL_INT {
        // The construction arg is a string !!!
        $$ = new ASTGotoStmt($2);
        SET_LOCATION($$);
    }
;

expression_list:
    expression_list SYM_COMMA expression {
        $$ = $1;
        $$ -> AddExpr($2);
        SET_LOCATION($$);
    }
    | expression {
        $$ = new ASTExpressionList($1);
        SET_LOCATION($$);
    }
;

expression: 
    expression SYM_GE expr {
        $$ = new ASTBinaryExpr(ASTBinaryExpr::Oper::GE, $1, $3);
        SET_LOCATION($$);
    }
    | expression SYM_GT expr {
        $$ = new ASTBinaryExpr(ASTBinaryExpr::Oper::GT, $1, $3);
        SET_LOCATION($$);
    }
    | expression SYM_LE expr {
        $$ = new ASTBinaryExpr(ASTBinaryExpr::Oper::LE, $1, $3);
        SET_LOCATION($$);
    }
    | expression SYM_LT expr {
        $$ = new ASTBinaryExpr(ASTBinaryExpr::Oper::LT, $1, $3);
        SET_LOCATION($$);
    }
    | expression SYM_EQ expr {
        $$ = new ASTBinaryExpr(ASTBinaryExpr::Oper::EQUAL, $1, $3);
        SET_LOCATION($$);
    }
    | expression SYM_NE expr {
        $$ = new ASTBinaryExpr(ASTBinaryExpr::Oper::UNEQUAL, $1, $3);
        SET_LOCATION($$);
    }
    | expr {
        $$ = $1;
        SET_LOCATION($$);
    }
;

expr:
    expr SYM_ADD term {
        $$ = new ASTBinaryExpr(ASTBinaryExpr::Oper::PLUS, $1, $3);
        SET_LOCATION($$);
    }
    | expr SYM_SUB term {
        $$ = new ASTBinaryExpr(ASTBinaryExpr::Oper::MINUS, $1, $3);
        SET_LOCATION($$);
    }
    | expr KWD_OR term {
        $$ = new ASTBinaryExpr(ASTBinaryExpr::Oper::OR, $1, $3);
        SET_LOCATION($$);
    }
    | expr SYM_MUL factor {
        $$ = new ASTBinaryExpr(ASTBinaryExpr::Oper::MUL, $1, $3);
        SET_LOCATION($$);
    }
    | expr KWD_DIV factor {
        $$ = new ASTBinaryExpr(ASTBinaryExpr::Oper::DIV, $1, $3);
        SET_LOCATION($$);
    }
    | expr KWD_MOD factor {
        $$ = new ASTBinaryExpr(ASTBinaryExpr::Oper::MOD, $1, $3);
        SET_LOCATION($$);
    }
    | expr KWD_AND factor {
        $$ = new ASTBinaryExpr(ASTBinaryExpr::Oper::AND, $1, $3);
        SET_LOCATION($$);
    }
    | factor {
        $$ = $1;
        SET_LOCATION($$);   
    }
;
factor:
    IDENTIFIER {
        $$ = new ASTIDExpr($1);
        SET_LOCATION($$);
    }
    | IDENTIFIER SYM_LPAREN exprexpression_list SYM_RPAREN {
        $$ = new ASTFuncCall($1);
        SET_LOCATION($$);   
    }
    | const_value {
        $$ = new ASTConstExpr($1);
        SET_LOCATION($$);
    }
    | SYM_LPAREN expression SYM_RPAREN {
        $$ = $2;
        SET_LOCATION($$);
    }
    | KWD_NOT factor {
        $$ = new ASTUnaryExpr(ASTUnaryExpr::Oper::NOT, $2);
        SET_LOCATION($$);
    }
    | SYM_SUB factor {
        $$ = new ASTUnaryExpr(ASTUnaryExpr::Oper::SUB, $2);
        SET_LOCATION($$);
    }
    | IDENTIFIER SYM_PERIOD IDENTIFIER {
        $$ = new ASTPropExpr($1, $2);
        SET_LOCATION($$);
    }
;
%%

void yyerror(char const char *str) {
    PrintError(str);
    ParseError = 1;
}

int main() {
    return 0;
}