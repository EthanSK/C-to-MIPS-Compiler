%code requires{
  #include "ast.hpp"
  #include <cassert>

  extern StatementPtr g_root;
  extern FILE *yyin;

  int yylex(void);
  void yyerror(const char *);
  
}

%union
{
  StatementPtr expr;
  std::vector<StatementPtr> *exprList;
  DeclPackage *decl;
  double number;
  yytokentype token;
  std::string *string;
}

%token T_INT_LIT T_FLOAT_LIT T_DOUBLE_LIT T_CHAR_LIT T_STRING_LIT T_IDENTIFIER T_TYPE_NAME

%token T_AUTO T_BREAK T_CASE T_CHAR T_CONST T_CONTINUE T_DEFAULT T_DO T_DOUBLE T_ELSE T_ENUM T_EXTERN T_FLOAT T_FOR T_GOTO T_IF T_INT T_LONG T_REGISTER T_RETURN T_SHORT T_SIGNED T_SIZEOF T_STATIC T_STRUCT T_SWITCH T_TYPEDEF T_UNION T_UNSIGNED T_VOID T_VOLATILE T_WHILE

%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE T_MODULO T_LSHIFT T_RSHIFT
%token T_LESS_THAN T_GREATER_THAN T_LESS_THAN_EQ T_GREATER_THAN_EQ T_EQ_EQ T_NOT_EQ
%token T_AND T_AND_AND T_OR T_OR_OR T_XOR
%token T_EQ T_PLUS_EQ T_MINUS_EQ T_MULTIPLY_EQ T_DIVIDE_EQ T_MODULO_EQ T_AND_EQ T_OR_EQ T_XOR_EQ T_LSHIFT_EQ T_RSHIFT_EQ

%token T_DOT T_ARROW T_COMMA T_COLON T_SEMICOLON T_QUESTION T_ELLIPSIS

%token T_LBRACKET T_RBRACKET T_LSQUARE_BRACKET T_RSQUARE_BRACKET T_LCURLY_BRACE T_RCURLY_BRACE

%token T_NOT T_INVERT T_PLUS_PLUS T_MINUS_MINUS

%token T_IDENTIFIER_LIST

%type <expr> EXPRESSION ASSIGNMENT_EXPRESSION UNARY_EXPRESSION POSTFIX_EXPRESSION CAST_EXPRESSION PRIMARY_EXPRESSION
%type <expr> MULTIPLICATIVE_EXPRESSION SHIFT_EXPRESSION ADDITIVE_EXPRESSION RELATIONAL_EXPRESSION EQUALITY_EXPRESSION
%type <expr> AND_EXPRESSION EXCLUSIVE_OR_EXPRESSION INCLUSIVE_OR_EXPRESSION LOGICAL_AND_EXPRESSION LOGICAL_OR_EXPRESSION
%type <expr> CONDITIONAL_EXPRESSION CONSTANT_EXPRESSION DECLARATION INIT_DECLARATOR_LIST DECLARATOR INITIALIZER
%type <expr> STORAGE_CLASS_SPECIFIER TYPE_SPECIFIER STRUCT_OR_UNION_SPECIFIER ENUM_SPECIFIER STRUCT_OR_UNION STRUCT_DECLARATION_LIST
%type <expr> DECLARATION_SPECIFIERS STRUCT_DECLARATION SPECIFIER_QUALIFIER_LIST TYPE_QUALIFIER STRUCT_DECLARATOR
%type <expr> ENUMERATOR_LIST ENUMERATOR DIRECT_DECLARATOR POINTER PARAMETER_TYPE_LIST TYPE_QUALIFIER_LIST
%type <expr> PARAMETER_DECLARATION 


%type <expr> TYPE_NAME ABSTRACT_DECLARATOR DIRECT_ABSTRACT_DECLARATOR INITIALIZER_LIST STATEMENT LABELED_STATEMENT COMPOUND_STATEMENT DECLARATION_LIST
%type <expr> EXPRESSION_STATEMENT SELECTION_STATEMENT ITERATION_STATEMENT JUMP_STATEMENT EXTERNAL_DECLARATION FUNCTION_DEFINITION

%type <exprList> STATEMENT_LIST PARAMETER_LIST TRANSLATION_UNIT

%type <decl> INIT_DECLARATOR

%type <token> ASSIGNEMENT_OPERATOR UNARY_OPERATOR

%type <string> T_STRING_LIT T_IDENTIFIER
%type <number> T_INT_LIT T_CHAR_LIT T_DOUBLE_LIT T_FLOAT_LIT

%start ROOT



%%

//Root that turns the aggregate into a sequence and adds the root node
ROOT : TRANSLATION_UNIT { g_root = new RootNode(new SequenceBlock(*$1)); delete $1; }

//Terminals
PRIMARY_EXPRESSION
	: T_IDENTIFIER { $$ = new VariableReference(*$1); delete $1; }
	| T_INT_LIT { $$ = new IntegerLiteral($1); }
	| T_DOUBLE_LIT { $$ = new DoubleLiteral($1); }
	| T_FLOAT_LIT { $$ = new FloatLiteral($1); }
  	| T_CHAR_LIT { $$ = new CharLiteral($1); }
	| T_STRING_LIT { $$ = new StringLiteral(*$1); delete $1; }
	| T_LBRACKET EXPRESSION T_RBRACKET { $$ = $2; }
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

ARGUMENT_EXPRESSION_LIST
	: ASSIGNMENT_EXPRESSION
	| ARGUMENT_EXPRESSION_LIST T_COMMA ASSIGNMENT_EXPRESSION

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
			case T_PLUS: $$ = new UnaryAdd($2); break;
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
	| SHIFT_EXPRESSION T_LSHIFT ADDITIVE_EXPRESSION { $$ = new BinaryLeftShift($1, $3); }
	| SHIFT_EXPRESSION T_RSHIFT ADDITIVE_EXPRESSION { $$ = new BinaryRightShift($1, $3); }
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
	| LOGICAL_AND_EXPRESSION T_AND_AND INCLUSIVE_OR_EXPRESSION { $$ = new BinaryLogicalAnd($1, $3); }
	;

LOGICAL_OR_EXPRESSION
	: LOGICAL_AND_EXPRESSION
	| LOGICAL_OR_EXPRESSION T_OR_OR LOGICAL_AND_EXPRESSION { $$ = new BinaryLogicalOr($1, $3); }
	;

CONDITIONAL_EXPRESSION
	: LOGICAL_OR_EXPRESSION
	| LOGICAL_OR_EXPRESSION T_QUESTION EXPRESSION T_COLON CONDITIONAL_EXPRESSION
	;

ASSIGNMENT_EXPRESSION 
	: CONDITIONAL_EXPRESSION
	| UNARY_EXPRESSION ASSIGNEMENT_OPERATOR ASSIGNMENT_EXPRESSION
	{
		switch ($2)
		{
		case T_EQ: $$ = new BinaryAssignment($1, $3); break;
		case T_MULTIPLY_EQ: $$ = new BinaryMultiplyAssignment($1, $3); break;
		case T_DIVIDE_EQ: $$ = new BinaryDivideAssignment($1, $3); break;
		case T_MODULO_EQ: $$ = new BinaryModuloAssignment($1, $3); break;
		case T_PLUS_EQ: $$ = new BinaryAddAssignment($1, $3); break;
		case T_MINUS_EQ: $$ = new BinarySubtractAssignment($1, $3); break;
		case T_LSHIFT_EQ: $$ = new BinaryLeftShiftAssignment($1, $3); break;
		case T_RSHIFT_EQ: $$ = new BinaryRightShiftAssignment($1, $3); break;
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
	: ASSIGNMENT_EXPRESSION
	| EXPRESSION T_COMMA ASSIGNMENT_EXPRESSION
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

//Handles declarations both with and without initializers - we will just init with 0
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
	: T_VOID { $$ = new PrimitiveType(PrimitiveType::PrimitiveTypeEnum::_void); }
	| T_CHAR { $$ = new PrimitiveType(PrimitiveType::PrimitiveTypeEnum::_char); }
	| T_SHORT { $$ = new PrimitiveType(PrimitiveType::PrimitiveTypeEnum::_float); }
	| T_INT { $$ = new PrimitiveType(PrimitiveType::PrimitiveTypeEnum::_int); }
	| T_LONG { $$ = new PrimitiveType(PrimitiveType::PrimitiveTypeEnum::_long); }
	| T_FLOAT { $$ = new PrimitiveType(PrimitiveType::PrimitiveTypeEnum::_float); }
	| T_DOUBLE { $$ = new PrimitiveType(PrimitiveType::PrimitiveTypeEnum::_double); }
	| T_SIGNED { $$ = new PrimitiveType(PrimitiveType::PrimitiveTypeEnum::_signed); }
	| T_UNSIGNED { $$ = new PrimitiveType(PrimitiveType::PrimitiveTypeEnum::_unsigned); }
	| STRUCT_OR_UNION_SPECIFIER
	| ENUM_SPECIFIER
	| T_TYPE_NAME
	;

STRUCT_OR_UNION_SPECIFIER
	: STRUCT_OR_UNION T_IDENTIFIER T_LCURLY_BRACE STRUCT_DECLARATION_LIST T_RCURLY_BRACE
	| STRUCT_OR_UNION T_LCURLY_BRACE STRUCT_DECLARATION_LIST T_RCURLY_BRACE
	| STRUCT_OR_UNION T_IDENTIFIER
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

DECLARATOR
	: POINTER DIRECT_DECLARATOR { $$ = new PointerType($2); }
	| DIRECT_DECLARATOR
	;

DIRECT_DECLARATOR
	: T_IDENTIFIER { $$ = new VariableReference(*$1); delete $1; }
	| T_LBRACKET DECLARATOR T_RBRACKET { $$ = $2; }
	| DIRECT_DECLARATOR T_LSQUARE_BRACKET CONSTANT_EXPRESSION T_RSQUARE_BRACKET
	| DIRECT_DECLARATOR T_LSQUARE_BRACKET T_RSQUARE_BRACKET
	| DIRECT_DECLARATOR T_LBRACKET PARAMETER_TYPE_LIST T_RBRACKET
	| DIRECT_DECLARATOR T_LBRACKET T_IDENTIFIER_LIST T_RBRACKET
	| DIRECT_DECLARATOR T_LBRACKET T_RBRACKET
	;

POINTER
	: T_MULTIPLY //dunno what * by itself means
	| T_MULTIPLY TYPE_QUALIFIER_LIST
	| T_MULTIPLY POINTER { $$ = new PointerType($2); }
	| T_MULTIPLY TYPE_QUALIFIER_LIST POINTER
	;

TYPE_QUALIFIER_LIST
	: TYPE_QUALIFIER
	| TYPE_QUALIFIER_LIST TYPE_QUALIFIER
	;

PARAMETER_TYPE_LIST
	: PARAMETER_LIST
	| PARAMETER_LIST T_COMMA T_ELLIPSIS //tf is this
	;

//Aggregate list of params
PARAMETER_LIST
	: PARAMETER_DECLARATION { $$ = new std::vector<StatementPtr>{$1}; }
	| PARAMETER_LIST T_COMMA PARAMETER_DECLARATION { $1->push_back($3); $$ = $1; }
	;

PARAMETER_DECLARATION
	: DECLARATION_SPECIFIERS DECLARATOR
	| DECLARATION_SPECIFIERS ABSTRACT_DECLARATOR
	| DECLARATION_SPECIFIERS
	;

IDENTIFIER_LIST
	: T_IDENTIFIER
	| T_IDENTIFIER_LIST T_COMMA T_IDENTIFIER
	;

TYPE_NAME
	: SPECIFIER_QUALIFIER_LIST
	| SPECIFIER_QUALIFIER_LIST ABSTRACT_DECLARATOR
	;

ABSTRACT_DECLARATOR
	: POINTER
	| DIRECT_ABSTRACT_DECLARATOR
	| POINTER DIRECT_ABSTRACT_DECLARATOR
	;

DIRECT_ABSTRACT_DECLARATOR
	: T_LBRACKET ABSTRACT_DECLARATOR T_RBRACKET
	| T_LSQUARE_BRACKET T_RSQUARE_BRACKET
	| T_LSQUARE_BRACKET CONSTANT_EXPRESSION T_RSQUARE_BRACKET
	| DIRECT_ABSTRACT_DECLARATOR T_LSQUARE_BRACKET T_RSQUARE_BRACKET
	| DIRECT_ABSTRACT_DECLARATOR T_LSQUARE_BRACKET CONSTANT_EXPRESSION T_RSQUARE_BRACKET
	| T_LBRACKET T_RBRACKET
	| T_LBRACKET PARAMETER_TYPE_LIST T_RBRACKET
	| DIRECT_ABSTRACT_DECLARATOR T_LBRACKET T_RBRACKET
	| DIRECT_ABSTRACT_DECLARATOR T_LBRACKET PARAMETER_TYPE_LIST T_RBRACKET
	;

INITIALIZER
	: ASSIGNMENT_EXPRESSION
	| T_LCURLY_BRACE INITIALIZER_LIST T_RCURLY_BRACE
	| T_LCURLY_BRACE INITIALIZER_LIST T_COMMA T_RCURLY_BRACE
	;

INITIALIZER_LIST
	: INITIALIZER
	| INITIALIZER_LIST T_COMMA INITIALIZER
	;

STATEMENT
	: LABELED_STATEMENT //goto garbage
	| COMPOUND_STATEMENT //scope stuff
	| EXPRESSION_STATEMENT //dumb comma thing
	| SELECTION_STATEMENT //if else and switch
	| ITERATION_STATEMENT //loops
	| JUMP_STATEMENT //flow control
	;

//This is goto garbage so ignore it
LABELED_STATEMENT
	: T_IDENTIFIER T_COLON STATEMENT
	| T_CASE CONSTANT_EXPRESSION T_COLON STATEMENT
	| T_DEFAULT T_COLON STATEMENT
	;

//Scope stuff
COMPOUND_STATEMENT
	: T_LCURLY_BRACE T_RCURLY_BRACE { $$ = new ScopeBlock(); }
	| T_LCURLY_BRACE STATEMENT_LIST T_RCURLY_BRACE { $$ = new ScopeBlock(*$2); delete $2; }
	| T_LCURLY_BRACE DECLARATION_LIST T_RCURLY_BRACE { $$ = new ScopeBlock($2); }
	| T_LCURLY_BRACE DECLARATION_LIST STATEMENT_LIST T_RCURLY_BRACE { $$ = new ScopeBlock({$2, new SequenceBlock(*$3)}); delete $3; }
	;

DECLARATION_LIST
	: DECLARATION
	| DECLARATION_LIST DECLARATION
	;

//This should just represent multiple lines in a row, dunno though
STATEMENT_LIST
	: STATEMENT { $$ = new std::vector<StatementPtr>{$1}; }
	| STATEMENT_LIST STATEMENT { $1->push_back($2); $$ = $1; }
	;

//The comma operator nonsense I believe i.e a = (1, 2, func(), 4);
EXPRESSION_STATEMENT
	: T_SEMICOLON
	| EXPRESSION T_SEMICOLON
	;

//If else and switch statements
SELECTION_STATEMENT
	: T_IF T_LBRACKET EXPRESSION T_RBRACKET STATEMENT { $$ = new IfElseStatement($3, $5, new ScopeBlock()); }
	| T_IF T_LBRACKET EXPRESSION T_RBRACKET STATEMENT T_ELSE STATEMENT { $$ = new IfElseStatement($3, $5, $7); }
	| T_SWITCH T_LBRACKET EXPRESSION T_RBRACKET STATEMENT
	;

//Loops - while,do,for
ITERATION_STATEMENT
	: T_WHILE T_LBRACKET EXPRESSION T_RBRACKET STATEMENT { new WhileLoop($3, $5); }
	| T_DO STATEMENT T_WHILE T_LBRACKET EXPRESSION T_RBRACKET T_SEMICOLON { new DoWhileLoop($2, $5); }
	| T_FOR T_LBRACKET EXPRESSION_STATEMENT EXPRESSION_STATEMENT T_RBRACKET STATEMENT
	| T_FOR T_LBRACKET EXPRESSION_STATEMENT EXPRESSION_STATEMENT EXPRESSION T_RBRACKET STATEMENT
	;

//Flow control - break,continue,goto,return
JUMP_STATEMENT
	: T_GOTO T_IDENTIFIER T_SEMICOLON //Goto garbage
	| T_CONTINUE T_SEMICOLON { $$ = new ContinueKeyword(); }
	| T_BREAK T_SEMICOLON { $$ = new BreakKeyword(); }
	| T_RETURN T_SEMICOLON
	| T_RETURN EXPRESSION T_SEMICOLON { $$ = new ReturnKeyword($2); }
	;

//Aggregation of top level global statements
TRANSLATION_UNIT
	: EXTERNAL_DECLARATION { $$ = new std::vector<StatementPtr>{$1}; }
	| TRANSLATION_UNIT EXTERNAL_DECLARATION { $1->push_back($2); $$ = $1; }
	;

//External declaration means something in global scope i think
EXTERNAL_DECLARATION
	: FUNCTION_DEFINITION
	| DECLARATION
	;

FUNCTION_DEFINITION
	: DECLARATION_SPECIFIERS DECLARATOR DECLARATION_LIST COMPOUND_STATEMENT
	| DECLARATION_SPECIFIERS DECLARATOR COMPOUND_STATEMENT
	| DECLARATOR DECLARATION_LIST COMPOUND_STATEMENT
	| DECLARATOR COMPOUND_STATEMENT
	;

%%

StatementPtr g_root; // Definition of variable (to match declaration earlier)

StatementPtr parseAST()
{
  g_root = NULL;
  yyparse();
  return g_root;
}
