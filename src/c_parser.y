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

%token T_NUMBER_LIT T_CHAR_LIT T_STRING_LIT T_IDENTIFIER T_TYPE_NAME

%token T_AUTO T_BREAK T_CASE T_CHAR T_CONST T_CONTINUE T_DEFAULT T_DO T_DOUBLE T_ELSE T_ENUM T_EXTERN T_FLOAT T_FOR T_GOTO T_IF T_INT T_LONG T_REGISTER T_RETURN T_SHORT T_SIGNED T_SIZEOF T_STATIC T_STRUCT T_SWITCH T_TYPEDEF T_UNION T_UNSIGNED T_VOID T_VOLATILE T_WHILE

%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE T_MODULO T_LSHIFT T_RSHIFT
%token T_LESS_THAN T_GREATER_THAN T_LESS_THAN_EQ T_GREATER_THAN_EQ T_EQ_EQ T_NOT_EQ
%token T_AND T_AND_AND T_OR T_OR_OR T_XOR
%token T_EQ T_PLUS_EQ T_MINUS_EQ T_MULTIPLY_EQ T_DIVIDE_EQ T_MODULO_EQ T_AND_EQ T_OR_EQ T_XOR_EQ T_LSHIFT_EQ T_RSHIFT_EQ

%token T_DOT T_ARROW T_COMMA T_COLON T_SEMICOLON T_QUESTION

%token T_LBRACKET T_RBRACKET T_LSQUARE_BRACKET T_RSQUARE_BRACKET T_LCURLY_BRACE T_RCURLY_BRACE

%token T_NOT T_INVERT T_PLUS_PLUS T_MINUS_MINUS

%type <expr> EXPRESSION ASSIGNEMENT_EXPRESSION UNARY_EXPRESSION POSTFIX_EXPRESSION CAST_EXPRESSION PRIMARY_EXPRESSION
%type <expr> MULTIPLICATIVE_EXPRESSION SHIFT_EXPRESSION ADDITIVE_EXPRESSION RELATIONAL_EXPRESSION EQUALITY_EXPRESSION
%type <expr> AND_EXPRESSION EXCLUSIVE_OR_EXPRESSION INCLUSIVE_OR_EXPRESSION LOGICAL_AND_EXPRESSION LOGICAL_OR_EXPRESSION
%type <expr> CONDITIONAL_EXPRESSION CONSTANT_EXPRESSION DECLARATION INIT_DECLARATOR_LIST INIT_DECLARATOR DECLARATOR INITIALIZER
%type <expr> STORAGE_CLASS_SPECIFIER TYPE_SPECIFIER STRUCT_OR_UNION_SPECIFIER ENUM_SPECIFIER STRUCT_OR_UNION STRUCT_DECLARATION_LIST
%type <expr> DECLARATION_SPECIFIERS STRUCT_DECLARATION SPECIFIER_QUALIFIER_LIST TYPE_QUALIFIER STRUCT_DECLARATOR DECLARATOR
%type <expr> CONSTANT_EXPRESSION ENUM_SPECIFIER ENUMERATOR_LIST ENUMERATOR

%type <token> ASSIGNEMENT_OPERATOR UNARY_OPERATOR

%type <string> T_STRING_LIT T_IDENTIFIER
%type <number> T_NUMBER_LIT T_CHAR_LIT

%start ROOT

%%

ROOT : EXPRESSION {  }
EXPRESSION : ASSIGNEMENT_OPERATOR {  }

PRIMARY_EXPRESSION
	: T_IDENTIFIER
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
	| POSTFIX_EXPRESSION T_DOT T_IDENTIFIER
	| POSTFIX_EXPRESSION T_ARROW T_IDENTIFIER
	| POSTFIX_EXPRESSION T_PLUS_PLUS { $$ = new UnaryPostIncrement($1); }
	| POSTFIX_EXPRESSION T_MINUS_MINUS { $$ = new UnaryPostDecrement($1); }
	;

UNARY_EXPRESSION
	: POSTFIX_EXPRESSION
	| T_PLUS_PLUS UNARY_EXPRESSION { $$ = new UnaryPreIncrement($2); }
	| T_MINUS_MINUS UNARY_EXPRESSION { $$ = new UnaryPreDecrement($2); }
	| UNARY_OPERATOR CAST_EXPRESSION
	{
		switch ($1)
		{
			case T_AND: $$ = new UnaryAddress($2); break;
			case T_MULTIPLY: $$ = new UnaryDereference($2); break;
			case T_PLUS: $$ = new UnaryPlus($2); break;
			case T_MINUS: $$ = new UnaryMinus($2); break;
			case T_INVERT: $$ = new UnaryBitwiseInvert($2); break;
			case T_NOT: $$ = new UnaryNot($2); break;
		}
	}
	| T_SIZEOF UNARY_EXPRESSION
	| T_SIZEOF T_LBRACKET TYPE_NAME T_RBRACKET
	;

UNARY_OPERATOR
	: T_AND { $$ = T_AND; }
	| T_MULTIPLY { $$ = T_MULTIPLY; }
	| T_PLUS { $$ = T_PLUS; }
	| T_MINUS { $$ = T_MINUS; }
	| T_INVERT { $$ = T_INVERT; }
	| T_NOT { $$ = T_NOT; }
	;

CAST_EXPRESSION
	: UNARY_EXPRESSION
	| T_LBRACKET TYPE_NAME T_RBRACKET CAST_EXPRESSION
	;

MULTIPLICATIVE_EXPRESSION
	: CAST_EXPRESSION
	| MULTIPLICATIVE_EXPRESSION T_MULTIPLY CAST_EXPRESSION { $$ = new BinaryMultiply($1, $3); }
	| MULTIPLICATIVE_EXPRESSION T_DIVIDE CAST_EXPRESSION { $$ = new BinaryDivide($1, $3); }
	| MULTIPLICATIVE_EXPRESSION T_MODULO CAST_EXPRESSION { $$ = new BinaryModulo($1, $3); }
	;

ADDITIVE_EXPRESSION
	: MULTIPLICATIVE_EXPRESSION
	| ADDITIVE_EXPRESSION T_PLUS MULTIPLICATIVE_EXPRESSION { $$ = new BinaryAdd($1, $3); }
	| ADDITIVE_EXPRESSION T_MINUS MULTIPLICATIVE_EXPRESSION { $$ = new BinarySubtract($1, $3); }
	;

SHIFT_EXPRESSION
	: ADDITIVE_EXPRESSION
	| SHIFT_EXPRESSION T_LSHIFT ADDITIVE_EXPRESSION { $$ = new BinaryBitwiseLeftShift($1, $3); }
	| SHIFT_EXPRESSION T_RSHIFT ADDITIVE_EXPRESSION { $$ = new BinaryBitwiseRightShift($1, $3); }
	;

RELATIONAL_EXPRESSION
	: SHIFT_EXPRESSION
	| RELATIONAL_EXPRESSION T_LESS_THAN SHIFT_EXPRESSION { $$ = new BinaryLessThan($1, $3); }
	| RELATIONAL_EXPRESSION T_GREATER_THAN SHIFT_EXPRESSION { $$ = new BinaryGreaterThan($1, $3); }
	| RELATIONAL_EXPRESSION T_LESS_THAN_EQ SHIFT_EXPRESSION { $$ = new BinaryLessThanOrEqualTo($1, $3); }
	| RELATIONAL_EXPRESSION T_GREATER_THAN_EQ SHIFT_EXPRESSION { $$ = new BinaryGreaterThanOrEqualTo($1, $3); }
	;

EQUALITY_EXPRESSION
	: RELATIONAL_EXPRESSION
	| EQUALITY_EXPRESSION T_EQ RELATIONAL_EXPRESSION { $$ = new BinaryIsEqualTo($1, $3); }
	| EQUALITY_EXPRESSION T_NOT_EQ RELATIONAL_EXPRESSION { $$ = new BinaryIsNotEqualTo($1, $3); }
	;

AND_EXPRESSION
	: EQUALITY_EXPRESSION
	| AND_EXPRESSION T_AND EQUALITY_EXPRESSION { $$ = new BinaryBitwiseAnd($1, $3); }
	;

EXCLUSIVE_OR_EXPRESSION
	: AND_EXPRESSION
	| EXCLUSIVE_OR_EXPRESSION T_XOR AND_EXPRESSION { $$ = new BinaryBitwiseXor($1, $3); }
	;

INCLUSIVE_OR_EXPRESSION
	: EXCLUSIVE_OR_EXPRESSION
	| INCLUSIVE_OR_EXPRESSION T_OR EXCLUSIVE_OR_EXPRESSION { $$ = new BinaryBitwiseOr($1, $3); }
	;

LOGICAL_AND_EXPRESSION
	: INCLUSIVE_OR_EXPRESSION
	| LOGICAL_AND_EXPRESSION T_AND_AND INCLUSIVE_OR_EXPRESSION { $$ = new BinaryConditionalAnd($1, $3); }
	;

LOGICAL_OR_EXPRESSION
	: LOGICAL_AND_EXPRESSION
	| LOGICAL_OR_EXPRESSION T_OR_OR LOGICAL_AND_EXPRESSION { $$ = new BinaryConditionalOr($1, $3); }
	;

CONDITIONAL_EXPRESSION
	: LOGICAL_OR_EXPRESSION
	| LOGICAL_OR_EXPRESSION T_QUESTION EXPRESSION T_COLON CONDITIONAL_EXPRESSION
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

EXPRESSION
	: ASSIGNEMENT_EXPRESSION
	| EXPRESSION T_COMMA ASSIGNEMENT_EXPRESSION
	;

CONSTANT_EXPRESSION
	: CONDITIONAL_EXPRESSION
	;

DECLARATION
	: DECLARATION_SPECIFIERS T_SEMICOLON
	| DECLARATION_SPECIFIERS INIT_DECLARATOR_LIST T_SEMICOLON
	;

DECLARATION_SPECIFIERS
	: STORAGE_CLASS_SPECIFIER
	| STORAGE_CLASS_SPECIFIER DECLARATION_SPECIFIERS
	| TYPE_SPECIFIER
	| TYPE_SPECIFIER DECLARATION_SPECIFIERS
	| TYPE_QUALIFIER
	| TYPE_QUALIFIER DECLARATION_SPECIFIERS
	;

EXPRESSION_STATEMENT
	: T_SEMICOLON
	| EXPRESSION T_SEMICOLON
	;

INIT_DECLARATOR_LIST
	: INIT_DECLARATOR
	| INIT_DECLARATOR_LIST T_COMMA INIT_DECLARATOR
	;

INIT_DECLARATOR
	: DECLARATOR
	| DECLARATOR T_EQ INITIALIZER
	;

STORAGE_CLASS_SPECIFIER
	: T_TYPEDEF
	| T_EXTERN
	| T_STATIC
	| T_AUTO
	| T_REGISTER
	;

TYPE_SPECIFIER
	: T_VOID
	| T_CHAR
	| T_SHORT
	| T_INT
	| T_LONG
	| T_FLOAT
	| T_DOUBLE
	| T_SIGNED
	| T_UNSIGNED
	| STRUCT_OR_UNION_SPECIFIER
	| ENUM_SPECIFIER
	| T_TYPE_NAME
	;

STRUCT_OR_UNION_SPECIFIER
	: STRUCT_OR_UNION IDENTIFIER T_LCURLY_BRACE STRUCT_DECLARATION_LIST T_RCURLY_BRACE
	| STRUCT_OR_UNION T_LCURLY_BRACE STRUCT_DECLARATION_LIST T_RCURLY_BRACE
	| STRUCT_OR_UNION IDENTIFIER
	;

STRUCT_OR_UNION
	: T_STRUCT
	| T_UNION
	;

STRUCT_DECLARATION_LIST
	: STRUCT_DECLARATION
	| STRUCT_DECLARATION_LIST STRUCT_DECLARATION
	;

STRUCT_DECLARATION
	: SPECIFIER_QUALIFIER_LIST STRUCT_DECLARATOR_LIST T_SEMICOLON
	;

SPECIFIER_QUALIFIER_LIST
	: TYPE_SPECIFIER SPECIFIER_QUALIFIER_LIST
	| TYPE_SPECIFIER
	| TYPE_QUALIFIER SPECIFIER_QUALIFIER_LIST
	| TYPE_QUALIFIER
	;

STRUCT_DECLARATOR_LIST
	: STRUCT_DECLARATOR
	| STRUCT_DECLARATOR_LIST T_COMMA STRUCT_DECLARATOR
	;

STRUCT_DECLARATOR
	: DECLARATOR
	| T_COLON CONSTANT_EXPRESSION
	| DECLARATOR T_COLON CONSTANT_EXPRESSION
	;

ENUM_SPECIFIER
	: T_ENUM T_LCURLY_BRACE ENUMERATOR_LIST T_RCURLY_BRACE
	| T_ENUM T_IDENTIFIER T_LCURLY_BRACE ENUMERATOR_LIST T_RCURLY_BRACE
	| T_ENUM T_IDENTIFIER
	;

ENUMERATOR_LIST
	: ENUMERATOR
	| ENUMERATOR_LIST T_COMMA ENUMERATOR
	;

ENUMERATOR
	: T_IDENTIFIER
	| T_IDENTIFIER T_EQ CONSTANT_EXPRESSION
	;

TYPE_QUALIFIER
	: T_CONST
	| T_VOLATILE
	;

%%

StatementPtr g_root; // Definition of variable (to match declaration earlier)

StatementPtr parseAST()
{
  g_root = NULL;
  yyparse();
  return g_root;
}
