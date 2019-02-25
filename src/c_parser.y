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
  std::string *string;
}

%token AUTO

%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE T_MODULO T_LSHIFT T_RSHIFT
%token T_LESS_THAN T_GREATER_THAN T_LESS_THAN_EQ T_GREATER_THAN_EQ T_EQ_EQ T_NOT_EQ
%token T_AND T_AND_AND T_OR T_OR_OR T_XOR
%token T_EQ T_PLUS_EQ T_MINUS_EQ T_MULTIPLY_EQ T_DIVIDE_EQ T_MODULO_EQ T_AND_EQ T_OR_EQ T_XOR_EQ T_LSHIFT_EQ T_RSHIFT_EQ

%token T_COMMA

%type <expr> EXPR

%start ROOT

%%

ROOT : EXPR {  }
EXPR : AUTO {  }

%%

StatementPtr g_root; // Definition of variable (to match declaration earlier)

StatementPtr parseAST()
{
  g_root = NULL;
  yyparse();
  return g_root;
}
