%code requires{
  #include "ast.hpp"
  #include <cassert>

  extern StatementPtr g_root;

  int yylex(void);
  void yyerror(const char *);
}

%union
{
  StatementPtr expr;
  double number;
  yytokentype token;
  std::string *string;
}

%token T_NUMBER_LIT T_CHAR_LIT T_STRING_LIT T_VARIABLE

%token T_AUTO T_BREAK T_CASE T_CHAR T_CONST T_CONTINUE T_DEFAULT T_DO T_DOUBLE T_ELSE T_ENUM T_EXTERN T_FLOAT T_FOR T_GOTO T_IF T_INT T_LONG T_REGISTER T_RETURN T_SHORT T_SIGNED T_SIZEOF T_STATIC T_STRUCT T_SWITCH T_TYPEDEF T_UNION T_UNSIGNED T_VOID T_VOLATILE T_WHILE

%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE T_MODULO T_LSHIFT T_RSHIFT
%token T_LESS_THAN T_GREATER_THAN T_LESS_THAN_EQ T_GREATER_THAN_EQ T_EQ_EQ T_NOT_EQ
%token T_AND T_AND_AND T_OR T_OR_OR T_XOR
%token T_EQ T_PLUS_EQ T_MINUS_EQ T_MULTIPLY_EQ T_DIVIDE_EQ T_MODULO_EQ T_AND_EQ T_OR_EQ T_XOR_EQ T_LSHIFT_EQ T_RSHIFT_EQ

%token T_DOT T_ARROW T_COMMA T_COLON T_SEMICOLON T_QUESTION

%token T_LBRACKET T_RBRACKET T_LSQUARE_BRACKET T_RSQUARE_BRACKET T_LCURLY_BRACE T_RCURLY_BRACE

%token T_NOT T_INVERT T_PLUS_PLUS T_MINUS_MINUS

%type <expr> EXPRESSION ASSIGNEMENT_EXPRESSION UNARY_EXPRESSION POSTFIX_EXPRESSION CAST_EXPRESSION PRIMARY_EXPRESSION
%type <expr> MULTIPLICATIVE_EXPRESSION SHIFT_EXPRESSION ADDITIVE_EXPRESSION

%type <token> ASSIGNEMENT_OPERATOR
%type <token> T_EQ T_MULTIPLY_EQ T_DIVIDE_EQ T_MODULO_EQ T_PLUS_EQ T_MINUS_EQ T_LSHIFT_EQ T_RSHIFT_EQ T_AND_AND T_XOR_EQ T_OR_EQ

%type <string> T_STRING_LIT T_VARIABLE
%type <number> T_NUMBER_LIT T_CHAR_LIT

%start ROOT

%%

ROOT : EXPRESSION {  }
EXPRESSION : ASSIGNEMENT_OPERATOR {  }

PRIMARY_EXPRESSION
	: T_VARIABLE
	| T_NUMBER_LIT
  | T_CHAR_LIT
	| T_STRING_LIT
	| T_LBRACKET EXPRESSION T_RBRACKET { $$ = $2 }
	;

POSTFIX_EXPRESSION
	: PRIMARY_EXPRESSION
	| POSTFIX_EXPRESSION T_LSQUARE_BRACKET EXPRESSION T_RSQUARE_BRACKET
	| POSTFIX_EXPRESSION T_LBRACKET T_RBRACKET
	| POSTFIX_EXPRESSION T_LBRACKET ARGUMENT_EXPRESSION_LIST T_RBRACKET
	| POSTFIX_EXPRESSION T_DOT T_VARIABLE
	| POSTFIX_EXPRESSION T_ARROW T_VARIABLE
	| POSTFIX_EXPRESSION T_PLUS_PLUS { $$ = new UnaryPostIncrement($1); }
	| POSTFIX_EXPRESSION T_MINUS_MINUS { $$ = new UnaryPostDecrement($1); }
	;

UNARY_EXPRESSION
	: POSTFIX_EXPRESSION
	| T_PLUS_PLUS UNARY_EXPRESSION { $$ = new UnaryPreIncrement($2); }
	| T_MINUS_MINUS UNARY_EXPRESSION { $$ = new UnaryPreDecrement($2); }
	| UNARY_OPERATOR CAST_EXPRESSION
	| T_SIZEOF UNARY_EXPRESSION
	| T_SIZEOF T_LBRACKET TYPE_NAME T_RBRACKET
	;

UNARY_OPERATOR
	: T_AND
	| T_MULTIPLY
	| T_PLUS
	| T_MINUS
	| T_INVERT
	| T_NOT
	;

CAST_EXPRESSION
	: UNARY_EXPRESSION
	| T_LBRACKET TYPE_NAME T_RBRACKET CAST_EXPRESSION
	;

ADDITIVE_EXPRESSION
	: MULTIPLICATIVE_EXPRESSION { $$ = $1; }
	| ADDITIVE_EXPRESSION T_PLUS MULTIPLICATIVE_EXPRESSION { $$ = new BinaryAddAssignement($1, $3); }
	| ADDITIVE_EXPRESSION T_MINUS MULTIPLICATIVE_EXPRESSION { $$ = new BinarySubtractAssignement($1, $3); }
	;

SHIFT_EXPRESSION
	: ADDITIVE_EXPRESSION { $$ = $1; }
	| SHIFT_EXPRESSION T_LSHIFT ADDITIVE_EXPRESSION { $$ = new BinaryBitwiseLeftShift($1, $3); }
	| SHIFT_EXPRESSION T_RSHIFT ADDITIVE_EXPRESSION { $$ = new BinaryBitwiseRightShift($1, $3); }
	;

ASSIGNEMENT_EXPRESSION
	: CONDITIONAL_EXPRESSION
	| UNARY_EXPRESSION ASSIGNEMENT_OPERATOR ASSIGNEMENT_EXPRESSION
  {
    switch ($2)
    {
      case T_EQ: $$ = new BinaryAssignement($1, $3); break;
      case T_MULTIPLY_EQ: $$ = new BinaryMultiplyAssignement($1, $3); break;
      case T_DIVIDE_EQ: $$ = new BinaryDivideAssignement($1, $3); break;
      case T_MODULO_EQ: $$ = new BinaryModuloAssignement($1, $3); break;
      case T_PLUS_EQ: $$ = new BinaryAddAssignement($1, $3); break;
      case T_MINUS_EQ: $$ = new BinarySubtractAssignement($1, $3); break;
      case T_LSHIFT_EQ: $$ = new BinaryBitwiseLeftShiftAssignement($1, $3); break;
      case T_RSHIFT_EQ: $$ = new BinaryBitwiseRightShiftAssignement($1, $3); break;
      case T_AND_AND: $$ = new BinaryBitwiseAndAssignment($1, $3); break;
      case T_XOR_EQ: $$ = new BinaryBitwiseXorAssignment($1, $3); break;
      case T_OR_EQ: $$ = new BinaryBitwiseOrAssignment($1, $3); break;
    }
  }
	;

ASSIGNEMENT_OPERATOR
	: T_EQ { $$ = T_EQ; }
	| T_MULTIPLY_EQ { $$ = T_MULTIPLY_EQ; }
	| T_DIVIDE_EQ { $$ = T_DIVIDE_EQ; }
	| T_MODULO_EQ { $$ = T_MODULO_EQ; }
	| T_PLUS_EQ { $$ = T_PLUS_EQ; }
	| T_MINUS_EQ { $$ = T_MINUS_EQ; }
	| T_LSHIFT_EQ { $$ = T_LSHIFT_EQ; }
	| T_RSHIFT_EQ { $$ = T_RSHIFT_EQ; }
	| T_AND_AND { $$ = T_AND_AND; }
	| T_XOR_EQ { $$ = T_XOR_EQ; }
	| T_OR_EQ { $$ = T_OR_EQ; }
	;

EXPRESSION_STATEMENT
	: T_SEMICOLON
	| EXPRESSION T_SEMICOLON
	;

%%

StatementPtr g_root; // Definition of variable (to match declaration earlier)

StatementPtr parseAST()
{
  g_root = NULL;
  yyparse();
  return g_root;
}
