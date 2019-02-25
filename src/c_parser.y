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
%token T_LESS_THAN T_GREATER_THAN T_LESS_THAN_EQ T_GREATER_THAN_EQ T_EQUALS T_NOT_EQUALS

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
