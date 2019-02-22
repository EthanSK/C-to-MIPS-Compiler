%code requires{
  #include "ast.hpp"
  #include <cassert>

  extern const Expression *g_root;

  int yylex(void);
  void yyerror(const char *);
}

%union
{
  const Expression *expr;
  double number;
  std::string *string;
}

//Token go here
%%

//Grammar goes here

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root = 0;
  yyparse();
  return g_root;
}
